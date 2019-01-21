/*libC++RWD Library for C++ Rendering of White_dune Data (in Development)*/

/* Copyright (c) Stefan Wolf, 2010. */
/* Copyright (c) J. "MUFTI" Scheurich, 2015-2018. */

/*
Redistribution and use in source and binary forms, with or without modification, are permitted provided that the following conditions are met:
1. Redistributions of source code must retain the above copyright notice, this list of conditions and the following disclaimer.
2. Redistributions in binary form must reproduce the above copyright notice, this list of conditions and the following disclaimer in the documentation and/or other materials provided with the distribution.
3. The name of the author may not be used to endorse or promote products derived from this software without specific prior written permission.

THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF
MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,
INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS
OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR
TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
*/

#define __USE_XOPEN 1 /* for M_PI */
#include <math.h>
#include <sys/time.h>
#include <string.h>
#include <setjmp.h>
#include <jpeglib.h>
#include <png.h>

namespace CPPRWD
{

    void error(const char *errormsg);

    void IndexedFaceSetRender(X3dNode *data, void*);

    void TextRender(X3dNode *data, void* extraData);

    void ImageTextureRender(X3dNode *data, void*);

    void PixelTextureRender(X3dNode *data, void*);

    void PointLightRender(X3dNode *data, void*);

    void DirectionalLightRender(X3dNode *data, void*);

    void SpotLightRender(X3dNode *data, void*);

    void MaterialRender(X3dNode *data, void*);

    void TransformTreeRender(X3dNode *data, void *dataptr);

    void GroupTreeRender(X3dNode *data, void *dataptr);

    void ViewpointRender(X3dNode *data, void*);

    void SwitchTreeRender(X3dNode *data, void *dataptr);

    void HAnimHumanoidTreeRender(X3dNode *data, void *dataptr);

    void HAnimJointTreeRender(X3dNode *data, void *dataptr);

    bool TimeSensorSendEvents(X3dNode *data, const char *event, 
                              void* extraData);

    float interpolate(float t, float key, float oldKey,
                               float value, float oldValue);

    void accountInterpolator(float *target, float fraction,
                             float *keys, float *keyValues, int numKeys,
                             int stride, int rotation);

    bool PositionInterpolatorSendEvents(X3dNode *data, const char *event,
                                        void* extraData);

    bool OrientationInterpolatorSendEvents(X3dNode *data, const char *event,
                                           void* extraData);

    bool ColorInterpolatorSendEvents(X3dNode *data, const char *event,
                                     void* extraData);

    bool ScalarInterpolatorSendEvents(X3dNode *data, const char *event,
                                      void* extraData);

    bool CoordinateInterpolatorSendEvents(X3dNode *data, const char *event,
                                          void* extraData);

    bool NormalInterpolatorSendEvents(X3dNode *data, const char *event,
                                      void* extraData);

    bool PositionInterpolator2DSendEvents(X3dNode *data, const char *event,
                                          void* extraData);

    void draw(float *matrix);

    void processEvents();

    void init();

    void finalize();

    int allocLight();
}

#define Z_NEAR 0.05f
#define Z_FAR 7000.0f

#define EPSILON 1E-9

static bool viewpointRendered = false;
static bool viewPointExists = false;

static short lightExists = 0;
static int numLights = 0;

static GLfloat viewpoint1Position[] = { 0, 0, 10 };

static float projectionMatrix[16];

static bool preRender = false;
static bool initRender = false;

static X3dSceneGraph scenegraph;

void CPPRWD::error(const char *errormsg)
{
    #ifdef WIN32
    MessageBox(NULL, errormsg, NULL, MB_OK);
    #else
    fprintf(stderr, "%s\n", errormsg);
    #endif
}

int CPPRWD::allocLight()
{
    GLint maxLights;
    glGetIntegerv(GL_MAX_LIGHTS, &maxLights);
    
    if (numLights >= maxLights) {
        error("too many lights!\n");
        return GL_LIGHT0;
    }
    
    return (GL_LIGHT0 + numLights++);
}

void CPPRWD::IndexedFaceSetRender(X3dNode *data, void* extraData)
{
    if(preRender)
    {
    }
    else if(initRender)
    {
    }
    else
    {
        X3dIndexedFaceSet *Xindexedfaceset = (X3dIndexedFaceSet*)data;
        X3dCoordinate *Xcoordinate = (X3dCoordinate*)Xindexedfaceset->coord;
        X3dNormal *Xnormal = (X3dNormal*)Xindexedfaceset->normal;
        X3dColor *Xcolor = (X3dColor*)Xindexedfaceset->color;
        X3dTextureCoordinate *Xtexturecoordinate = (X3dTextureCoordinate*)Xindexedfaceset->texCoord;
        GLint *faces = NULL;
        GLfloat *vertex = NULL;
        GLint *normalindex = NULL;
        GLfloat *normal = NULL;
        GLfloat *colors = NULL;
        GLint *colorindex = NULL;
        GLint *texturecoordinateindex = NULL;
        int faces_len, vertex_len, normalindex_len, normal_len, color_len, colorindex_len, texturecoordinateindex_len;
        bool normalpervertex, colorpervertex;
        if(Xcolor != NULL)
        {
            glEnable(GL_COLOR_MATERIAL); //Maybe needfull
            glColorMaterial(GL_FRONT_AND_BACK, GL_DIFFUSE);
            colors = Xcolor->color;
            color_len = Xcolor->color_length;
            colorpervertex = Xindexedfaceset->colorPerVertex;
        }
        if(Xindexedfaceset->colorIndex != NULL)
        {
            colorindex = Xindexedfaceset->colorIndex;
            colorindex_len = Xindexedfaceset->colorIndex_length;
        }
        if(Xindexedfaceset->texCoordIndex != NULL)
        {
            texturecoordinateindex = Xindexedfaceset->texCoordIndex;
            texturecoordinateindex_len = Xindexedfaceset->texCoordIndex_length;
        }
        vertex = Xcoordinate->point;
        faces = Xindexedfaceset->coordIndex;
        normalindex = Xindexedfaceset->normalIndex;
        if(Xnormal!=NULL)normal = Xnormal->vector;
        vertex_len = Xcoordinate->point_length;
        faces_len = Xindexedfaceset->coordIndex_length;
        if(Xnormal != NULL)normal_len = Xnormal->vector_length;
        normalindex_len = Xindexedfaceset->normalIndex_length;
        normalpervertex = Xindexedfaceset->normalPerVertex;
        int buffer, normalbuffer, texturebuffer = 0;
        int facecounter = 0;
        if (Xindexedfaceset->ccw != 0)
        {
           glFrontFace(GL_CCW);
        }
        else
        {
           glFrontFace(GL_CW);
        }
        if (Xindexedfaceset->solid == 0) 
        {
           glDisable(GL_CULL_FACE);
           glLightModeli(GL_LIGHT_MODEL_TWO_SIDE, GL_TRUE);
        } 
        else 
        {
           glEnable(GL_CULL_FACE);
           glLightModeli(GL_LIGHT_MODEL_TWO_SIDE, GL_FALSE);
        }

        glBegin(GL_POLYGON);
        if(colors && !colorpervertex)
            glColor3f(colors[3 * facecounter], colors[3 * facecounter + 1], colors[3 * facecounter + 2]);

        for(int i = 0; i != faces_len; i++)
        {
            buffer = faces[i];
            if (buffer < 0) {
                glEnd();
                if (i != faces_len - 1)
                    glBegin(GL_POLYGON);
            }

            if(normalindex != NULL)
                normalbuffer = normalindex[i];
            else 
                normalbuffer = buffer;
            if(texturecoordinateindex != NULL)
                texturebuffer = texturecoordinateindex[i];
            else
                texturebuffer = buffer;
            if(buffer == -1 && (normalbuffer == -1 || normalindex != NULL))
            {
                facecounter++;
                glEnd();
                glBegin(GL_POLYGON);
                if(colors && !colorpervertex)
                    glColor3f(colors[3 * facecounter], colors[3 * facecounter + 1], colors[3 * facecounter + 2]);
            }
            else if(((buffer == -1 && normalbuffer != -1) || (buffer != -1 && normalbuffer == -1)) && normalindex != NULL)
                error("Error in normalIndex");
            else
            {
                if(normalpervertex && normal != NULL)glNormal3f(normal[normalbuffer*3], normal[normalbuffer*3+1], normal[normalbuffer*3+2]);
                if(colors && color_len > 0 && colorpervertex)
                    glColor3f(colors[buffer*3], colors[buffer*3+1], colors[buffer*3+2]);
                if(Xtexturecoordinate)
                    if((Xtexturecoordinate->point) && (texturecoordinateindex))
                        glTexCoord2f(Xtexturecoordinate->point[texturebuffer*2], Xtexturecoordinate->point[texturebuffer*2+1]);
                glVertex3f(vertex[buffer*3], vertex[buffer*3+1], vertex[buffer*3+2]);
            }
        }
        glEnd();
    }
    glDisable(GL_COLOR_MATERIAL);
}


void CPPRWD::TextRender(X3dNode *data, void* extraData)
{
    if(preRender)
    {
    }
    else if(initRender)
    {
    }
    else
    {
        X3dText *text = (X3dText*)data;
        glPushAttrib(GL_ENABLE_BIT);
    
        glDisable(GL_LIGHTING);
        glDisable(GL_BLEND);
        
        glEnable(GL_LINE_SMOOTH);
    
        float fsize = 1;
        X3dFontStyle *fontStyle = (X3dFontStyle *)text->fontStyle;
        if (fontStyle != NULL)
           fsize = fontStyle->size;
    
        for (int j = 0; j < text->string_length;j++) 
        {
            float fsize = 1;
            const char *str = text->string[j];
            glPushMatrix();
            glTranslatef(0, -j * fsize, 0);
            const float GLUT_STROKE_ROMAN_SIZE = 119.05;
            float scale = 1/GLUT_STROKE_ROMAN_SIZE;
            glScalef(scale * fsize, scale * fsize, 1.0);
            for (int i = 0; i < strlen(str); i++)
                glutStrokeCharacter(GLUT_STROKE_ROMAN, str[i]);
            glPopMatrix();
        }
        glPopAttrib();
    }
}

static bool not2PowN(int number)
{
    bool ret = true;
    for (int i = 0; i < 32; i++)
        if (number == (1 << i))
        {
            ret = false;
            break;
        }
    return ret;
}

static void textureTransformBind(X3dNode *data)
{
    int i;
    X3dTextureTransform *texTransform = (X3dTextureTransform *)data;
    if(preRender)
    {
    }
    else if(initRender)
    {
    }
    else {
        const float *fcenter = texTransform->center;
        const float *fscale = texTransform->scale;
        const float *ftranslation = texTransform->translation;

        glPushMatrix();
        glMatrixMode(GL_TEXTURE);
        glLoadIdentity();
        glTranslatef(-fcenter[0], -fcenter[1], 0.0f);
        glScalef(fscale[0], fscale[1], 1.0f);
        glRotatef(texTransform->rotation * 180.0f / M_PI, 0.0f, 0.0f, 1.0f);
        glTranslatef(fcenter[0], fcenter[1], 0.0f);
        glTranslatef(ftranslation[0], ftranslation[1], 0.0f);
        glMatrixMode(GL_MODELVIEW);
    }
}

static void textureTransformUnBind(void)
{
    glPopMatrix();
}

static void renderIntTexture(GLuint *textureName, int height, int width, 
                             int format, GLuint *data, 
                             bool repeatS, bool repeatT)
{
    if (*textureName == 0) {
        glGenTextures(1, textureName);
        glBindTexture(GL_TEXTURE_2D, *textureName);
        glPixelStorei(GL_UNPACK_ALIGNMENT, 1);
        glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
        glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
        glTexImage2D(GL_TEXTURE_2D, 0, format, width, height, 0, format, 
                     GL_UNSIGNED_BYTE, data);
    } else {
        glBindTexture(GL_TEXTURE_2D, *textureName);
    }
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, 
                    repeatS ? GL_REPEAT : GL_CLAMP);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, 
                    repeatT ? GL_REPEAT : GL_CLAMP);
    glEnable(GL_TEXTURE_2D);
}

static void renderByteTexture(GLuint *textureName, int height, int width, 
                              int format, GLbyte *data,
                              int repeatS, int repeatT)
{
    if (*textureName == 0) {
        glGenTextures(1, textureName);
        glBindTexture(GL_TEXTURE_2D, *textureName);
        glPixelStorei(GL_UNPACK_ALIGNMENT, 1);
        glPixelStorei(GL_PACK_ALIGNMENT, 1);
        glTexImage2D(GL_TEXTURE_2D, 0, format, width, height, 0, format, 
                     GL_UNSIGNED_BYTE, data);
        glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
        glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    } else {
        glBindTexture(GL_TEXTURE_2D, *textureName);
    }
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, 
                    repeatS ? GL_REPEAT : GL_CLAMP);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, 
                    repeatT ? GL_REPEAT : GL_CLAMP);
    glEnable(GL_TEXTURE_2D);
}

static int errorFlag = 0;
static jmp_buf jpegEnv;

struct ImageTextureExtraDataStruct {
    unsigned int height;
    unsigned int width;
    unsigned int colorMode;
    unsigned char *pixels;
    GLuint *textureName;
};

static void CRWDJpgErrorExit(j_common_ptr cinfo)
{
    longjmp(jpegEnv,1);
    errorFlag = 1;
}

static int CRWDJpgLoad(struct jpeg_decompress_struct *cinfo, FILE *file, 
                       unsigned int *width, unsigned int *height, 
                       unsigned int* components)
{
    static struct jpeg_error_mgr jpgError;

    errorFlag=0;
    if (setjmp(jpegEnv)!=0)
    {
        errorFlag = 1;
        return 1;
    }
    cinfo->err = jpeg_std_error(&jpgError);
    cinfo->err->error_exit = CRWDJpgErrorExit;
    jpeg_create_decompress(cinfo);

    jpeg_stdio_src(cinfo, file);
    jpeg_read_header(cinfo, 1);
    jpeg_start_decompress(cinfo);

    *width = cinfo->output_width;
    *height = cinfo->output_height;
    *components = cinfo->output_components;

    return errorFlag;
}

static int CRWDJpgRead(struct jpeg_decompress_struct *cinfo, 
                       unsigned char *pixels)
{
    JSAMPARRAY buffer;
    int rowStride;
    unsigned char *ptr;
    int buffer_height = 1;

    rowStride = cinfo->output_width * cinfo->output_components;
    buffer = (JSAMPARRAY)malloc(sizeof(JSAMPROW) * buffer_height);
    buffer[0] = (JSAMPROW)malloc(sizeof(JSAMPLE) * rowStride);
    
    ptr = pixels + rowStride * (cinfo->output_height - 1);
    while (cinfo->output_scanline < cinfo->output_height) 
    {
        jpeg_read_scanlines(cinfo, buffer, 1);
        memcpy(ptr, buffer[0], rowStride);
        ptr -= rowStride;
    }

    jpeg_finish_decompress(cinfo);
    jpeg_destroy_decompress(cinfo);
    free(buffer[0]);
    free(buffer);
    return errorFlag;
}

static double getGammaExp()
{
    static double defaultExponent = 2.2;
    static int set = 0;

    if (!set)
    {
#if defined(NeXT)
        defaultExponent = 1.0;
#elif defined(__sgi)
        defaultExponent = 1.7;
#elif defined(MACOSX)
        defaultExponent = 1.5;
#endif
        set = 1;
    }
    return defaultExponent;
}
#ifndef png_jmpbuf 
#define png_jmpbuf(png_ptr) ((png_ptr)->jmpbuf) 
#endif 

#define PNG_SIGNATURE_SIZE 8

static int CRWDPngLoad(FILE *f, png_structp *pngPtr, png_infop *infoPtr,
                       unsigned int *width, unsigned int *height, 
                       unsigned int *components)
{
    unsigned char signature[PNG_SIGNATURE_SIZE];
    
    int bitDepth;
    int colorType;
    int interlaceType;
    int grayPalette;

    fread(signature, 1, PNG_SIGNATURE_SIZE, f);
    if (!png_check_sig(signature, PNG_SIGNATURE_SIZE))
    {
        errorFlag = 1;
        fclose(f);
        return 1;
    }
    *pngPtr = png_create_read_struct(PNG_LIBPNG_VER_STRING, 0, 0, 0);    
    if (*pngPtr == NULL)
    {
        errorFlag = 1;
        fclose(f);
        return 1;
    }
    *infoPtr = png_create_info_struct(*pngPtr);
    if (*infoPtr == NULL)
    {
        errorFlag = 1;
        png_destroy_read_struct(pngPtr, NULL, NULL);
        fclose(f);
        return 1;
    }
    if (setjmp(png_jmpbuf(*pngPtr)))
    {
        png_destroy_read_struct(pngPtr, infoPtr, NULL);
        errorFlag = 1;
        fclose(f);
        return 1;
    }
#ifndef PNG_NO_STDIO
    png_init_io(*pngPtr, f);
#endif
    png_set_sig_bytes(*pngPtr, PNG_SIGNATURE_SIZE);
    png_read_info(*pngPtr, *infoPtr);
    png_get_IHDR(*pngPtr, *infoPtr, width, height, &bitDepth, &colorType,
                 &interlaceType, NULL, NULL);
    png_set_strip_16(*pngPtr);
    png_set_packing(*pngPtr);
    *components = png_get_channels(*pngPtr, *infoPtr);

    if (colorType == PNG_COLOR_TYPE_PALETTE)
    {
        png_set_expand(*pngPtr);
        *components = 3;
    }

    if ((colorType == PNG_COLOR_TYPE_GRAY) && (bitDepth < 8))
        png_set_expand(*pngPtr);

    if (png_get_valid(*pngPtr, *infoPtr, PNG_INFO_tRNS))
    {
      png_set_expand(*pngPtr);
      *components = *components + 1;
    }
    
    grayPalette = 0;
    if (colorType == PNG_COLOR_TYPE_PALETTE)
    {
        int n;
        int numPalette;
        png_colorp palette;

        if (png_get_PLTE(*pngPtr, *infoPtr, &palette, &numPalette))
        {
          grayPalette = 1;
          for (n = 0; n < numPalette; ++n)
            if ((palette[n].red != palette[n].green) ||
                (palette[n].red != palette[n].blue))
            {
                grayPalette = 0;
                break;
            }
        }
    }
    
    {
        double gamma;
        double exponent = getGammaExp();
        if (png_get_gAMA(*pngPtr, *infoPtr, &gamma))
            png_set_gamma(*pngPtr, exponent, gamma);
        else
            png_set_gamma(*pngPtr, exponent, 0.45455);
    }

    png_read_update_info(*pngPtr, *infoPtr);
    png_get_IHDR(*pngPtr, *infoPtr, width, height, &bitDepth, &colorType,
                 &interlaceType, NULL, NULL);
    return 0;
}

static int CRWDPngRead(png_structp *pngPtr, png_infop *infoPtr,
                       struct ImageTextureExtraDataStruct *data, 
                       unsigned int *components)
{
    int rowStride = *components * data->width;
    png_bytep *rowPtrs;
    int row;
    unsigned char *ptr;
    int i;

    rowPtrs = (png_bytep *) malloc(sizeof(png_bytep) * data->height);

    for (row = 0; row < data->height; row++)
    {
        rowPtrs[row] = (png_bytep)png_malloc(*pngPtr, 
                            png_get_rowbytes(*pngPtr, *infoPtr));
    }

    png_read_image(*pngPtr, rowPtrs);

    ptr = data->pixels + rowStride * (data->height - 1);
    for (i = 0; i < data->height; i++)
    {
        memcpy(ptr, rowPtrs[i], rowStride);
        ptr -= rowStride;
    }
    png_destroy_read_struct(pngPtr, infoPtr, NULL);
    free(rowPtrs);
}

void CPPRWD::ImageTextureRender(X3dNode *data, void *)
{
    int i;
    struct ImageTextureExtraDataStruct *extraVar;

    struct X3dImageTexture *imageTexture = (struct X3dImageTexture*) data;
    extraVar = (struct ImageTextureExtraDataStruct *)imageTexture->extra_data;
    if(preRender)
    {
    }
    else if(initRender)
    {
        int i;
        const char *filename;
        unsigned int components;
        struct jpeg_decompress_struct cinfo;
        png_structp pngPtr;
        png_infop infoPtr;
        FILE *file;

        imageTexture->extra_data = malloc(sizeof(struct 
                                                 ImageTextureExtraDataStruct));
        extraVar = (struct ImageTextureExtraDataStruct *)
                   imageTexture->extra_data;

        extraVar->textureName = new GLuint[1];
        *(extraVar->textureName) = 0;

        filename = *(imageTexture->url);

        if (!filename)
            return;
        else if (strlen(filename) == 0)
            return;
        else if (!(file = fopen(filename, "rb")))
            return;

        /* try to handle file as jpeg file */
        CRWDJpgLoad(&cinfo, file, &(extraVar->width), &(extraVar->height), 
                    &components);
        if (!errorFlag)
        {
            extraVar->pixels = (unsigned char *)malloc(components *
                                   extraVar->width * extraVar->height);
            if (extraVar->pixels == NULL)
                return;        

            CRWDJpgRead(&cinfo, extraVar->pixels);
            extraVar->colorMode = GL_RGB;
        }
        fclose(file);
        if (errorFlag) 
        { 
            /* try to handle file as PNG file) */
            file = fopen(filename, "rb");
            if (!CRWDPngLoad(file, &pngPtr, &infoPtr, 
                             &(extraVar->width), &(extraVar->height),
                             &components))
            {
                extraVar->pixels = (unsigned char *)malloc(components *
                                       extraVar->width * extraVar->height);
                if (extraVar->pixels == NULL)
                     return;
                 CRWDPngRead(&pngPtr, &infoPtr, extraVar, &components);
            }
            fclose(file);
        }

        extraVar->colorMode = GL_RGBA;
        switch (components)
        {
          case 1:
            extraVar->colorMode = GL_LUMINANCE;
            break;
          case 2:
            extraVar->colorMode = GL_LUMINANCE_ALPHA;
            break;
          case 3:
            extraVar->colorMode = GL_RGB;
            break;          
        }
        if (not2PowN(extraVar->width))
            error("warning: texture width is not 2 pow N");            
        if (not2PowN(extraVar->height))
            error("warning: texture height is not 2 pow N");            
        if (extraVar->width != extraVar->height)
            error("warning: texture width and height is not equal\n");
    } 
    else 
    {
        X3dNode *textureTransform;
        textureTransform = ((struct X3dAppearance *)imageTexture->m_parent)->
                           textureTransform;

        if (textureTransform)
            textureTransformBind(textureTransform);
        glMatrixMode(GL_TEXTURE);
        renderByteTexture(extraVar->textureName,
                          extraVar->width, extraVar->height, 
                          extraVar->colorMode, (GLbyte *)(extraVar->pixels), 
                          imageTexture->repeatS, imageTexture->repeatT); 
        glMatrixMode(GL_MODELVIEW);
        if (textureTransform)
            textureTransformUnBind();
    }
}

void CPPRWD::PixelTextureRender(X3dNode *data, void*)
{
    X3dPixelTexture *pixelTexture = (X3dPixelTexture*) data;
    GLuint *textureName = (GLuint *) pixelTexture->extra_data;
    if(preRender)
    {
    }
    else if(initRender)
    {
        int bigEndian = 1;
        bigEndian = (*(unsigned char *)&bigEndian) == 0;

        pixelTexture->extra_data = malloc(sizeof(GLuint));
        textureName = (GLuint *) pixelTexture->extra_data;
        *textureName = 0;

        if (not2PowN(pixelTexture->image[0]))
            error("warning: texture width is not 2 pow N");            
        if (not2PowN(pixelTexture->image[1]))
            error("warning: texture height is not 2 pow N");            
        if (pixelTexture->image[0] != pixelTexture->image[1])
            error("warning: texture width and height is not equal\n");
        // store modified colors back to pixelTexture.image
        for (int i = 3; i < pixelTexture->image_length; i++) {
            int a = 0xff;
            int r,g,b;
            switch (pixelTexture->image[2])
            {
              case 4:
                r = (pixelTexture->image[i]&0xFF000000) >> 24;
                g = (pixelTexture->image[i]&0x00FF0000) >> 16;
                b = (pixelTexture->image[i]&0x0000FF00) >> 8;
                a = (pixelTexture->image[i]&0x000000FF);
                break;
              case 3:
                r = (pixelTexture->image[i]&0x00FF0000) >> 16;
                g = (pixelTexture->image[i]&0x0000FF00) >> 8;
                b = (pixelTexture->image[i]&0x000000FF);
                break;
              case 2:
                r = g = b = (pixelTexture->image[i]&0x0000FF00) >> 8;
                a = (pixelTexture->image[i]&0x000000FF);
                break;
              case 1:
                r = g = b = (pixelTexture->image[i]&0xFF);
                break;
            }
            if (bigEndian)
            {
                pixelTexture->image[i] = a | 
                                         (b << 8) | (g << 16) | (r << 24);
            }
            else
            {
                pixelTexture->image[i] = r | (g << 8) | (b << 16) | 
                                         (a << 24);
            }
        }
    }
    else {
        X3dNode *textureTransform;
        textureTransform = ((X3dAppearance *)pixelTexture->m_parent)->
                           textureTransform;
                
        if (textureTransform)
            textureTransformBind(textureTransform);
        renderIntTexture(textureName, 
                         pixelTexture->image[0], pixelTexture->image[1], 
                         GL_RGBA, (GLuint *)&pixelTexture->image[3], 
                         pixelTexture->repeatS, pixelTexture->repeatT); 
        if (textureTransform)
            textureTransformUnBind();
    }
}

void CPPRWD::PointLightRender(X3dNode *data, void* extraData)
{
    int lightNum = -1;
    X3dPointLight *lightNode = (X3dPointLight*)data;
    if(preRender && lightNode->on)
    {
        lightNum = *(int *)(lightNode->extra_data);
        glEnable(lightNum);
        X3dPointLight *light = (X3dPointLight *)data;
        GLfloat light_color[4] = {light->color[0]*light->intensity, light->color[1]*light->intensity, light->color[2]*light->intensity, 1};
        GLfloat light_ambient_color[4] = {light->color[0]*light->ambientIntensity, light->color[1]*light->ambientIntensity, light->color[2]*light->ambientIntensity, 1};
        GLfloat light_position[4] = {light->location[0], light->location[1], light->location[2], 
                                     extraData != NULL ? *((float *)extraData) : 0.0f};
        GLfloat light_attenuation[3] = {light->attenuation[0], light->attenuation[1], light->attenuation[2]};
        glLightfv(lightNum, GL_DIFFUSE, light_color);
        glLightfv(lightNum, GL_AMBIENT, light_ambient_color);
        glLightfv(lightNum, GL_POSITION, light_position);
        glLightf(lightNum, GL_CONSTANT_ATTENUATION, light_attenuation[0]);
        glLightf(lightNum, GL_LINEAR_ATTENUATION, light_attenuation[1]);
        glLightf(lightNum, GL_QUADRATIC_ATTENUATION, light_attenuation[2]);
        glLightf(lightNum, GL_SPOT_CUTOFF, 180.0f);
        glLightf(lightNum, GL_SPOT_EXPONENT, 0.0f);
    }
    else if(initRender)
    {
        lightExists = true;
        lightNode->extra_data = malloc(sizeof(int));
        *(int *)(lightNode->extra_data) = allocLight();
    }
    else
    {
    }
}

void CPPRWD::DirectionalLightRender(X3dNode *data, void* extraData)
{
    X3dDirectionalLight *lightNode = (X3dDirectionalLight*)data;
    int lightNum = -1;
    if(preRender && lightNode->on)
    {
        int i;
        GLfloat color[4];
        GLfloat ambient_color[4];
        GLfloat position[4];

        for (i = 0; i < 3; i++) 
            color[i] = lightNode->color[i] * lightNode->intensity;
        color[3] = 1;

        for (i = 0; i < 3; i++) 
            ambient_color[i] = lightNode->color[i] * lightNode->ambientIntensity;
        ambient_color[3] = 1;

        for (i = 0; i < 3; i++)
            position[i] = -lightNode->direction[i];
        position[3] = 0.0f;

        lightNum = *(int *)(lightNode->extra_data);
        glLightfv(lightNum, GL_AMBIENT, ambient_color);
        glLightfv(lightNum, GL_DIFFUSE, color);
        glLightfv(lightNum, GL_POSITION, position);
        glLightfv(lightNum, GL_SPECULAR, color);
        glLightf(lightNum, GL_SPOT_CUTOFF, 180.0f);
        glLightf(lightNum, GL_SPOT_EXPONENT, 0.0f);
        glLightf(lightNum, GL_CONSTANT_ATTENUATION, 1);
        glLightf(lightNum, GL_LINEAR_ATTENUATION, 0);
        glLightf(lightNum, GL_QUADRATIC_ATTENUATION, 0);
        glEnable(lightNum);
    }
    else if(initRender)
    {
        lightExists = -1;
        lightNode->extra_data = malloc(sizeof(int));
        *(int *)(lightNode->extra_data) = allocLight();
    }
}

void CPPRWD::SpotLightRender(X3dNode *data, void* extraData)
{
    X3dSpotLight *lightNode = (X3dSpotLight*)data;
    int lightNum = -1;
    if(preRender && lightNode->on)
    {
        int i;
        GLfloat color[4];
        GLfloat ambient_color[4];
        GLfloat position[4];
        GLfloat ambientIntensity[4];

        for (i = 0; i < 3; i++) 
            color[i] = lightNode->color[i] * lightNode->intensity;
        color[3] = 1;

        for (i = 0; i < 3; i++) 
            ambient_color[i] = lightNode->color[i] * lightNode->ambientIntensity;
        ambient_color[3] = 1;

        for (i = 0; i < 3; i++)
            position[i] = lightNode->direction[i];
        position[3] = 1.0f;

        lightNum = *(int *)(lightNode->extra_data);
        glLightfv(lightNum, GL_AMBIENT, ambient_color);
        glLightfv(lightNum, GL_DIFFUSE, color);
        glLightfv(lightNum, GL_POSITION, position);
        glLightfv(lightNum, GL_SPECULAR, color);
        glLightfv(lightNum, GL_SPOT_DIRECTION, lightNode->direction);
        glLightf(lightNum, GL_SPOT_CUTOFF, lightNode->cutOffAngle * 180.0f / M_PI);
        glLightf(lightNum, GL_SPOT_EXPONENT, lightNode->beamWidth < lightNode->cutOffAngle ? 1.0f : 0.0f);
        glLightf(lightNum, GL_CONSTANT_ATTENUATION, lightNode->attenuation[0]);
        glLightf(lightNum, GL_LINEAR_ATTENUATION, lightNode->attenuation[1]);
        glLightf(lightNum, GL_QUADRATIC_ATTENUATION, lightNode->attenuation[2]);
        glEnable(lightNum);
    }
    else if(initRender)
    {
        lightExists = -1;
        lightNode->extra_data = malloc(sizeof(int));
        *(int *)(lightNode->extra_data) = allocLight();
    }
}


void CPPRWD::MaterialRender(X3dNode *data, void*)
{
    if(preRender)
    {
    }
    else if(initRender)
    {
    }
    else
    {
        X3dMaterial *material = (X3dMaterial*)data;
        GLfloat diffuse_color[4] = {material->diffuseColor[0], material->diffuseColor[1], material->diffuseColor[2], 1.0f};
        GLfloat ambient = material->ambientIntensity;
        GLfloat ambient_color[4] = {ambient * material->diffuseColor[0], ambient * material->diffuseColor[1], ambient * material->diffuseColor[2], 1};
        GLfloat emissive_color[4] = {material->emissiveColor[0], material->emissiveColor[1], material->emissiveColor[2], 1.0f};
        GLfloat specuar_color[4] = {material->specularColor[0], material->specularColor[1], material->specularColor[2], 1.0f};
        GLfloat shininess = material->shininess*128.0f;
        glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, diffuse_color);
        glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, ambient_color);
        glMaterialfv(GL_FRONT_AND_BACK, GL_EMISSION, emissive_color);
        glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, specuar_color);
        glMaterialf(GL_FRONT_AND_BACK, GL_SHININESS, shininess);
    }
}

void CPPRWD::GroupTreeRender(X3dNode *data, void *dataptr)
{
    X3dGroup *group = (X3dGroup*)data;
    glPushMatrix();
    if (group->children)
        for (int i = 0; i < group->children_length; i++)
            if (group->children[i]) 
            {
                if(!(preRender || initRender))
                    glDisable(GL_TEXTURE_2D);
                group->children[i]->treeRender(dataptr);
            }
    glPopMatrix();
}

void CPPRWD::TransformTreeRender(X3dNode *data, void *dataptr)
{
    X3dTransform *transform = (X3dTransform*)data;
    if(preRender || initRender)
    {
        if (transform->children)
            for (int i = 0; i < transform->children_length; i++)
                if (transform->children[i])
                    transform->children[i]->treeRender(dataptr);
    }
    else
    {
        glPushMatrix();
        glTranslatef(transform->translation[0], transform->translation[1], transform->translation[2]);
        glTranslatef(transform->center[0], transform->center[1], transform->center[2]);
        glRotatef( ((transform->rotation[3] / M_PI) * 180.0f), transform->rotation[0], transform->rotation[1], transform->rotation[2]);
        glRotatef( ((transform->scaleOrientation[3] / M_PI) * 180.0f), transform->scaleOrientation[0], transform->scaleOrientation[1], transform->scaleOrientation[2]);
        glScalef(transform->scale[0], transform->scale[1], transform->scale[2]);
        glRotatef( ((transform->scaleOrientation[3] / M_PI) * 180.0f) * -1.0f, transform->scaleOrientation[0], transform->scaleOrientation[1], transform->scaleOrientation[2]);
        glTranslatef(transform->center[0] * -1.0f, transform->center[1] * -1.0f, transform->center[2] * -1.0f);
        if (transform->children)
            for (int i = 0; i < transform->children_length; i++)
                if (transform->children[i]) 
                {
                    glDisable(GL_TEXTURE_2D);
                    transform->children[i]->treeRender(dataptr);
                }
        glPopMatrix();
    }
}

void CPPRWD::ViewpointRender(X3dNode *data, void*)
{
    X3dViewpoint *viewpoint = (X3dViewpoint*)data;
    if(preRender || initRender)
    {
        viewPointExists = true;

        if(!viewpointRendered)
        {
            viewpointRendered = true;
            for (int i = 0; i < 3; i++)
                viewpoint1Position[i] = viewpoint->position[i];

            glMatrixMode(GL_PROJECTION);
            float fieldOfViewdegree = ((viewpoint->fieldOfView / M_PI) * 180.0f);

            if(initRender) {
                gluPerspective(fieldOfViewdegree, 1.0, Z_NEAR, Z_FAR);  /* fieldOfView in degree, aspect radio, Z nearest, Z farest */
                glGetFloatv(GL_PROJECTION_MATRIX, projectionMatrix);
            } else if(preRender)
                glLoadMatrixf(projectionMatrix);

            glRotatef( ( -(viewpoint->orientation[3] / (2*M_PI) ) * 360), viewpoint->orientation[0], viewpoint->orientation[1], viewpoint->orientation[2]);
            glTranslatef(-viewpoint->position[0], -viewpoint->position[1], -viewpoint->position[2]);
            glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        }
    }
    else
    {
    }
}

void CPPRWD::SwitchTreeRender(X3dNode *data, void *dataptr)
{
    struct X3dSwitch *nodeSwitch = (struct X3dSwitch *)data;
    glPushMatrix();
    if (nodeSwitch->children)
       if (nodeSwitch->whichChoice < nodeSwitch->children_length)
           if (nodeSwitch->children[nodeSwitch->whichChoice])
           {
               if(!(preRender || initRender))
                   glDisable(GL_TEXTURE_2D);
               nodeSwitch->children[nodeSwitch->whichChoice]->
                     treeRender(dataptr);
           }
    glPopMatrix();
}

struct HAnimJointExtraDataStruct {
    float jointMatrix[16];
    float thisMatrix[16];
};

void multMatrixVec(float *ret, float mat[16], float x, float y, float z)
{
    float s = mat[4*0+3]*x + mat[4*1+3]*y + mat[4*2+3]*z + mat[4*3+3];
    if (s == 0)
        s = 1;

    ret[0] = (mat[4*0+0]*x + mat[4*1+0]*y + mat[4*2+0]*z + mat[4*3+0])/s;
    ret[1] = (mat[4*0+1]*x + mat[4*1+1]*y + mat[4*2+1]*z + mat[4*3+1])/s;
    ret[2] = (mat[4*0+2]*x + mat[4*1+2]*y + mat[4*2+2]*z + mat[4*3+2])/s;
}

struct HAnimHumanoidExtraDataStruct {
     float *origVertices;
     int origVertices_length;
     float thisMatrix[16];
};

void applyJoint(X3dNode *data, X3dNode *x3dcoord, float *origVertices, 
                X3dNode *parent)
{
     struct X3dHAnimJoint *joint = (struct X3dHAnimJoint*)data;
     struct X3dCoordinate *coord = (X3dCoordinate *)x3dcoord;
     int i;
     struct HAnimJointExtraDataStruct *extraVar;
     struct X3dHAnimJoint *mayJoint = (struct X3dHAnimJoint*)parent;
     struct X3dHAnimHumanoid *mayHuman = (struct X3dHAnimHumanoid*)parent;
     float *mayMatrix;

     extraVar = (struct HAnimJointExtraDataStruct *)(joint->extra_data);
     if (extraVar == NULL)
         return;
     if (mayJoint->getType() == X3dHAnimJointType) 
     {
         struct HAnimJointExtraDataStruct *jointData =
             (struct HAnimJointExtraDataStruct *)(mayJoint->extra_data);
         mayMatrix = jointData->jointMatrix;
     } else {
         struct HAnimHumanoidExtraDataStruct *humanData =
             (struct HAnimHumanoidExtraDataStruct *)(mayHuman->extra_data);
         mayMatrix = humanData->thisMatrix;
     }
     glMatrixMode(GL_MODELVIEW);
     glPushMatrix();
     glLoadIdentity();
     glMultMatrixf(mayMatrix);
     glMultMatrixf(extraVar->thisMatrix);
     glGetFloatv(GL_MODELVIEW_MATRIX, extraVar->jointMatrix);
     glPopMatrix();

     if (coord && coord->point)
     {
         int *mskinCoordIndex = joint->skinCoordIndex;
         float *mskinCoordWeight = joint->skinCoordWeight;
         for (i = 0; i < joint->skinCoordIndex_length; i++)
             if (mskinCoordIndex[i] > -1) {
                 int index = mskinCoordIndex[i];
                 float *point = origVertices + index * 3;
                 float wpoint[3];
                 float newpoint[3];
                 int sCwI = joint->skinCoordWeight_length - 1;
                 float weight = mskinCoordWeight[i < sCwI ? i : sCwI];
                 newpoint[0] = coord->point[index * 3];
                 newpoint[1] = coord->point[index * 3 + 1];
                 newpoint[2] = coord->point[index * 3 + 2];
                 multMatrixVec(wpoint, extraVar->jointMatrix, 
                               point[0], point[1], point[2]);
                 wpoint[0] = wpoint[0] * weight; 
                 wpoint[1] = wpoint[1] * weight; 
                 wpoint[2] = wpoint[2] * weight; 
                 newpoint[0] += wpoint[0];
                 newpoint[1] += wpoint[1];
                 newpoint[2] += wpoint[2];
                 coord->point[index * 3 + 0] = newpoint[0];
                 coord->point[index * 3 + 1] = newpoint[1];
                 coord->point[index * 3 + 2] = newpoint[2];
             }
    }
    if (joint->children)
        for (i = 0; i < joint->children_length; i++)
            if (joint->children[i])
            {
                if (joint->children[i]->getType() == X3dHAnimJointType)
                    if (coord && coord->point)
                        applyJoint(joint->children[i], x3dcoord, 
                                   origVertices, data);
            }
}

void CPPRWD::HAnimHumanoidTreeRender(X3dNode *data, void *dataptr)
{
    struct X3dHAnimHumanoid *humanoid = (struct X3dHAnimHumanoid*)data;
    int i;
    struct HAnimHumanoidExtraDataStruct *extraVar;
    struct X3dCoordinate *coord = (X3dCoordinate *)humanoid->skinCoord;

    if(initRender)
    {
        humanoid->extra_data = malloc(sizeof(struct 
                                             HAnimHumanoidExtraDataStruct));
    }
    extraVar = (struct HAnimHumanoidExtraDataStruct *)humanoid->extra_data;
    if (extraVar == NULL)
        return;
    if(initRender) {
        glMatrixMode(GL_MODELVIEW);
        glPushMatrix();
        glLoadIdentity();
        glGetFloatv(GL_MODELVIEW_MATRIX, extraVar->thisMatrix);
        glPopMatrix();

        if (coord && coord->point) 
        {
            extraVar->origVertices = (float *)malloc(coord->point_length * 
                                                     sizeof(float));
            for (i = 0; i < coord->point_length; i++)
                extraVar->origVertices[i] = coord->point[i];
            extraVar->origVertices_length = coord->point_length;
        }
    }
    if(initRender)
    {
        if (humanoid->skeleton)
            for (i = 0; i < humanoid->skeleton_length; i++)
                if (humanoid->skeleton[i]) 
                {
                    humanoid->skeleton[i]->treeRender(dataptr);;
                }       
        if (humanoid->skin)
            for (i = 0; i < humanoid->skin_length; i++)
                if (humanoid->skin[i])
                    humanoid->skin[i]->treeRender(dataptr);
    }
    else
    {
        struct X3dCoordinate *coord = (X3dCoordinate *)humanoid->skinCoord;

        if (preRender)
        {
            glPushMatrix();
            glMatrixMode(GL_MODELVIEW);
            glLoadIdentity();
            glTranslatef(humanoid->translation[0], humanoid->translation[1], humanoid->translation[2]);
            glTranslatef(humanoid->center[0], humanoid->center[1], humanoid->center[2]);
            glRotatef( ( (humanoid->rotation[3] / (2*M_PI) ) * 360), humanoid->rotation[0], humanoid->rotation[1], humanoid->rotation[2]);
            glRotatef( ( (humanoid->scaleOrientation[3] / (2*M_PI) ) * 360), humanoid->scaleOrientation[0], humanoid->scaleOrientation[1], humanoid->scaleOrientation[2]);
            glScalef(humanoid->scale[0], humanoid->scale[1], humanoid->scale[2]);
            glRotatef( ( (humanoid->scaleOrientation[3] / (2*M_PI) ) * 360) * -1, humanoid->scaleOrientation[0], humanoid->scaleOrientation[1], humanoid->scaleOrientation[2]);
            glTranslatef(humanoid->center[0] * -1, humanoid->center[1] * -1, humanoid->center[2] * -1);
            glGetFloatv(GL_MODELVIEW_MATRIX, extraVar->thisMatrix);
            glPopMatrix();
            for (i = 0; i < coord->point_length; i++)
                coord->point[i] = 0;
        }
        glPushMatrix();
        glMultMatrixf(extraVar->thisMatrix);
        if (humanoid->skin)
            for (i = 0; i < humanoid->skin_length; i++)
                if (humanoid->skin[i]) {
                    glDisable(GL_TEXTURE_2D);
                    humanoid->skin[i]->treeRender(dataptr);
                }
        if (humanoid->skeleton)
            for (i = 0; i < humanoid->skeleton_length; i++)
                if (humanoid->skeleton[i])
                {
                    if (preRender) 
                    {
                        if (humanoid->skeleton[i]->getType() == 
                            X3dHAnimJointType)
                            if (coord && coord->point)
                                applyJoint(humanoid->skeleton[i], coord, 
                                           extraVar->origVertices, data);
                    }
                    glDisable(GL_TEXTURE_2D);
                    humanoid->skeleton[i]->treeRender(dataptr);
                }
        glPopMatrix();
    }
}

void CPPRWD::HAnimJointTreeRender(X3dNode *data, void *dataptr)
{
    struct X3dHAnimJoint *joint = (struct X3dHAnimJoint*)data;
    struct HAnimJointExtraDataStruct *extraVar;
    int i;

    if(initRender)
    {
        joint->extra_data = malloc(sizeof(struct 
                                          HAnimJointExtraDataStruct));
    }
    extraVar = (struct HAnimJointExtraDataStruct *)joint->extra_data;
    if (extraVar == NULL)
        return;
    if(initRender)
    {
        glMatrixMode(GL_MODELVIEW);
        glPushMatrix();
        glLoadIdentity();
        glGetFloatv(GL_MODELVIEW_MATRIX, extraVar->jointMatrix);
        glGetFloatv(GL_MODELVIEW_MATRIX, extraVar->thisMatrix);
        glPopMatrix();
        if (joint->children)
            for (i = 0; i < joint->children_length; i++)
                if (joint->children[i])
                {
                    glDisable(GL_TEXTURE_2D);
                    joint->children[i]->treeRender(dataptr);
                }
    }
    else
    {
        if (preRender)
        {
            glMatrixMode(GL_MODELVIEW);
            glPushMatrix();
            glLoadIdentity();
            glTranslatef(joint->translation[0], joint->translation[1], joint->translation[2]);
            glTranslatef(joint->center[0], joint->center[1], joint->center[2]);
            glRotatef( ( (joint->rotation[3] / (2*M_PI) ) * 360), joint->rotation[0], joint->rotation[1], joint->rotation[2]);
            glRotatef( ( (joint->scaleOrientation[3] / (2*M_PI) ) * 360), joint->scaleOrientation[0], joint->scaleOrientation[1], joint->scaleOrientation[2]);
            glScalef(joint->scale[0], joint->scale[1], joint->scale[2]);
            glRotatef( ( (joint->scaleOrientation[3] / (2*M_PI) ) * 360) * -1, joint->scaleOrientation[0], joint->scaleOrientation[1], joint->scaleOrientation[2]);
            glTranslatef(joint->center[0] * -1, joint->center[1] * -1, joint->center[2] * -1);
            glGetFloatv(GL_MODELVIEW_MATRIX, extraVar->thisMatrix);
            glPopMatrix();
        }
        glMultMatrixf(extraVar->thisMatrix);
        if (joint->children)
            for (i = 0; i < joint->children_length; i++)
                if (joint->children[i])
                {
                    glDisable(GL_TEXTURE_2D);
                    joint->children[i]->treeRender(dataptr);
                }
    }
}


static double getTimerTime(void)
{
#ifdef WIN32
    struct _timeb t;
    _ftime(&t);
    return (double) t.time + t.millitm / 1000.0;
#else
    struct timeval t;
    gettimeofday(&t, NULL);
    return (double) t.tv_sec + (double) t.tv_usec / 1000000.0;
#endif
}

class CPPRWDTimeSensorData {
public:
    double startTime;
    double stopTime;
};

bool CPPRWD::TimeSensorSendEvents(X3dNode *data, const char *event, 
                                  void* extraData)
{
    X3dTimeSensor *timeSensor = (struct X3dTimeSensor *)data;
    double currentTime = 0;
    CPPRWDTimeSensorData *dataPtr;
    double callTime;
    if (timeSensor->m_data == NULL) {
        timeSensor->m_data = (CPPRWDTimeSensorData *)
                             new CPPRWDTimeSensorData();
        timeSensor->isActive = 0;     
        dataPtr = (CPPRWDTimeSensorData *)timeSensor->m_data;
        dataPtr->startTime = timeSensor->startTime;
        dataPtr->stopTime = timeSensor->stopTime;       
    }

    dataPtr = (CPPRWDTimeSensorData *)timeSensor->m_data;

    if (!timeSensor->enabled)
        return false;

    currentTime = getTimerTime();

    if (timeSensor->isActive) {
        timeSensor->time = currentTime;
    } else {
        if (timeSensor->startTime > dataPtr->stopTime)
            dataPtr->startTime = timeSensor->startTime;
    }
    if (!timeSensor->loop) { 
        if (dataPtr->stopTime > dataPtr->startTime) {
            if (timeSensor->isActive) {
                dataPtr->stopTime = currentTime;
                timeSensor->isActive = 1;
                return true;  
            }
            return false;
        }
        if (currentTime > (dataPtr->startTime + 
                           timeSensor->cycleInterval)) {
            timeSensor->fraction_changed = 1.0f;
            if (timeSensor->isActive) {
                dataPtr->stopTime = currentTime;
                timeSensor->isActive = 0;
                return true;
            }
            return false;
        }
        if (currentTime < timeSensor->startTime)
            return false;
    }

    timeSensor->isActive = 1;
                
    callTime = currentTime - dataPtr->startTime;
    timeSensor->fraction_changed = (float)(fmod(callTime, 
                                                timeSensor->cycleInterval) / 
                                           timeSensor->cycleInterval);
    return true;
}

float CPPRWD::interpolate(float t, float key, float oldKey, 
                                  float value, float oldValue)
{
    float delta = (key == oldKey) ? 0 : (t - oldKey) / (key - oldKey);
    return oldValue + delta * (value - oldValue);
}

void CPPRWD::accountInterpolator(float *target, float fraction,
                                 float *keys, float *keyValues, int numKeys,
                                 int stride, int rotation)
{
    int i;
    int j;
    if (!rotation) {
        if (numKeys > 0) {
            for (j = 0; j < stride; j++)
                target[j]=keyValues[j];
            int oldi = 0;
            for (i = 0; i < numKeys; i++) {
                if ((fraction >= keys[oldi]) && (fraction < keys[i])) {
                    for (j = 0; j < stride; j++)
                        target[j] = interpolate(fraction, keys[i], keys[oldi], 
                                                keyValues[i * stride + j], 
                                                keyValues[oldi * stride + j]); 
                    break;
                }
                oldi = i;
            }
            if (i == numKeys)
                for (j = 0; j < stride; j++)
                    target[j] = keyValues[(numKeys - 1) * stride + j];
        }
    } else {
        float k1 = 0.0;
        float k2 = 1.0;
        int pos1 = 0;
        int pos2 = 0;
        int pos;
        float s;
        float q[4];
        float q1[4];
        float q2[4];
        int flip;
        float alpha;
        float beta;
        float theta;
        float sin_t;
        float cos_t;
        float len;

        if (numKeys == 0) {
            target[0] = 0;
            target[1] = 0;
            target[2] = 1;
            target[3] = 0;
            return;
        }

        for (pos = 0; pos < numKeys; pos++)
            if (keys[pos] > fraction) 
                break;

        if (pos == 0) {
            k1 = 0.0f;
            pos1 = 0;
        } else {
            k1 = keys[pos - 1];
            pos1 = pos - 1;
        }

        if (pos == numKeys) {
            k2 = 1.0f;
            pos2 = numKeys - 1;
        } else {
           k2 = keys[pos];
           pos2 = pos;
        }

        if ((k1 == k2) || (pos1==pos2))
            alpha = 0.0f;
        else
            alpha = (fraction - k1) / (k2 - k1);

        s = sin(keyValues[pos1 * 4 + 3] * 0.5f);
        for (i = 0; i < 3; i++)
             q1[i] = keyValues[pos1 * 4 + i] * s;
        q1[3] = cos(keyValues[pos1 * 4 + 3] * 0.5f);

        s = sin(keyValues[pos2 * 4 + 3] * 0.5f);
        for (i = 0; i < 3; i++)
             q2[i] = keyValues[pos2 * 4 + i] * s;
        q2[3] = cos(keyValues[pos2 * 4 + 3] * 0.5f);
        
        cos_t = q1[0]*q2[0] + q1[1]*q2[1] + q1[2]*q2[2] + q1[3]*q2[3];

        len = (float) sqrt(cos_t);
        if (len > 0)
            len = 1 / len;
        else
            len = 1;

        if (cos_t < 0.0) {
            cos_t = -cos_t;
            flip = 1;
        } else
            flip = 0;
        if (1.0 - cos_t < EPSILON)
            beta = 1.0f - alpha;
        else {
            theta = (float) acos(cos_t);
            sin_t = (float) sin(theta);
            beta = (float) sin(theta - alpha * theta) / sin_t;
            alpha = (float) sin(alpha * theta) / sin_t;
        }
        if (flip)
            alpha = -alpha;
        for (i = 0; i < 4; i++)
            q[i] = (q1[i] * beta + q2[i] * alpha);
        for (i = 0; i < 3; i++)
            target[i] = q[i] * len;
        target[3] = 2.0f * (float) acos(q[3]);
    }
}

bool CPPRWD::PositionInterpolatorSendEvents(X3dNode *data, const char *event,
                                            void* extraData)
{
    static int warned = 0;
    X3dPositionInterpolator *interpolator = (X3dPositionInterpolator *)data;
    if (interpolator->key_length * 3 != interpolator->keyValue_length) { 
        if (!warned)
            error("invalid PositionInterpolator: number keys do not match number values\n");
        warned = 1;
        return false;
    }
    accountInterpolator(interpolator->value_changed, interpolator->set_fraction,
                        interpolator->key, interpolator->keyValue, 
                        interpolator->key_length, 3, 0); 
    return true;
}

bool CPPRWD::OrientationInterpolatorSendEvents(X3dNode *data, const char *event,
                                               void* extraData)
{
    static int warned = 0;
    X3dOrientationInterpolator *interpolator = (X3dOrientationInterpolator *)
                                               data;
    if (interpolator->key_length * 4 != interpolator->keyValue_length) { 
        if (!warned)
            error("invalid OrientationInterpolator: number keys do not match number values\n");
        warned = 1;
        return false;
    }
    accountInterpolator(interpolator->value_changed, interpolator->set_fraction,
                        interpolator->key, interpolator->keyValue, 
                        interpolator->key_length, 4, 1); 
    return true;
}

bool CPPRWD::ColorInterpolatorSendEvents(X3dNode *data, const char *event,
                                         void* extraData)
{
    static int warned = 0;
    X3dColorInterpolator *interpolator = (X3dColorInterpolator *)data;
    if (interpolator->key_length * 3 != interpolator->keyValue_length) { 
        if (!warned)
            error("invalid ColorInterpolator: number keys do not match number values\n");
        warned = 1;
        return false;
    }
    accountInterpolator(interpolator->value_changed, interpolator->set_fraction,
                        interpolator->key, interpolator->keyValue, 
                        interpolator->key_length, 3, 0); 
    return true;
}

bool CPPRWD::ScalarInterpolatorSendEvents(X3dNode *data, const char *event,
                                          void* extraData)
{
    static int warned = 0;
    X3dScalarInterpolator *interpolator = (X3dScalarInterpolator *)data;
    if (interpolator->key_length * 1 != interpolator->keyValue_length) { 
        if (!warned)
            error("invalid ScalarInterpolator: number keys do not match number values\n");
        warned = 1;
        return false;
    }
    accountInterpolator(&interpolator->value_changed, interpolator->set_fraction,
                        interpolator->key, interpolator->keyValue, 
                        interpolator->key_length, 1, 0); 
    return true;
}

bool CPPRWD::CoordinateInterpolatorSendEvents(X3dNode *data, const char *event,
                                              void* extraData)
{
    X3dCoordinateInterpolator *interpolator = (X3dCoordinateInterpolator *)data;
    int targetSize = interpolator->keyValue_length / interpolator->key_length;
    if (interpolator->value_changed == NULL) {
        if (interpolator->key_length * targetSize != 
            interpolator->keyValue_length){
            error("invalid CoodinateInterpolator: number keys do not match number values\n");
            return false;
        }
        interpolator->value_changed_length = targetSize;
        interpolator->value_changed = new float[targetSize == 0 ? 1 :
                                                targetSize * sizeof(float)];
    }
        
    accountInterpolator(interpolator->value_changed, interpolator->set_fraction,
                        interpolator->key, interpolator->keyValue, 
                        interpolator->key_length, 
                        interpolator->value_changed_length, 0);
    return true;
}

bool CPPRWD::NormalInterpolatorSendEvents(X3dNode *data, const char *event,
                                          void* extraData)
{
    int i,j;
    X3dNormalInterpolator *interpolator = (X3dNormalInterpolator *)data;
    int targetSize = interpolator->keyValue_length / interpolator->key_length;
    if (interpolator->value_changed == NULL) {
        if (interpolator->key_length * targetSize != 
            interpolator->keyValue_length){
            error("invalid CoodinateInterpolator: number keys do not match number values\n");
            return false;
        }
        interpolator->value_changed_length = targetSize;
        interpolator->value_changed = new float[targetSize == 0 ? 1 :
                                                targetSize * sizeof(float)];
    }
        
    accountInterpolator(interpolator->value_changed, interpolator->set_fraction,
                        interpolator->key, interpolator->keyValue, 
                        interpolator->key_length, 
                        interpolator->value_changed_length, 0);

    /* normalize results */
    for (i = 0; i < targetSize; i += 3) {
        float *vec = interpolator->keyValue + 3 * i;
        float len = sqrt(vec[0] * vec[0] + vec[1] * vec[1] + vec[2] * vec[2]);
        if (len != 0)
            for (j = 0; j < 3 ; j++)
                vec[j] /= len;
    }   
    return true;
}

bool CPPRWD::PositionInterpolator2DSendEvents(X3dNode *data, const char *event,
                                              void* extraData)
{
    static int warned = 0;
    X3dPositionInterpolator2D *interpolator = (X3dPositionInterpolator2D *)data;
    if (interpolator->key_length * 2 != interpolator->keyValue_length) { 
        if (!warned)
            error("invalid PositionInterpolator: number keys do not match number values\n");
        warned = 1;
        return false;
    }
    accountInterpolator(interpolator->value_changed, interpolator->set_fraction,
                        interpolator->key, interpolator->keyValue, 
                        interpolator->key_length, 2, 0); 
    return true;
}
        
X3dNode *rootNode = &scenegraph.root;
//X3dNode *rootNode = &scenegraph.DEFNAME;

void CPPRWD::processEvents() {
    X3dProcessEvents(&scenegraph, NULL);
}

void CPPRWD::draw(float *matrix)
{
    glClearColor(0, 0, 0, 1);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

//    glMatrixMode(GL_MODELVIEW);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glLoadMatrixf(matrix);
    glMatrixMode(GL_MODELVIEW);

    viewpointRendered = false;
    
    preRender = true;

    rootNode->treeRender(NULL);

    if(!lightExists)
    {
        static int light = -1;
        if (light == -1)
            light = allocLight();
        glEnable(light);
    }

    glMatrixMode(GL_MODELVIEW);
    preRender = false;
    rootNode->treeRender(NULL);
}

void CPPRWD::init()
{
    X3dTransform::treeRenderCallback = TransformTreeRender;
    X3dGroup::treeRenderCallback = GroupTreeRender;
    X3dIndexedFaceSet::renderCallback = IndexedFaceSetRender;
    X3dText::renderCallback = TextRender;
    X3dPointLight::renderCallback = PointLightRender;
    X3dDirectionalLight::renderCallback = DirectionalLightRender;
    X3dSpotLight::renderCallback = SpotLightRender;
    X3dMaterial::renderCallback = MaterialRender;
    X3dViewpoint::renderCallback = ViewpointRender;
    X3dPixelTexture::renderCallback = PixelTextureRender;
    X3dImageTexture::renderCallback = ImageTextureRender;
    X3dSwitch::treeRenderCallback = SwitchTreeRender;
    X3dHAnimHumanoid::treeRenderCallback = HAnimHumanoidTreeRender;
    X3dHAnimJoint::treeRenderCallback = HAnimJointTreeRender;
    X3dTimeSensor::processEventCallback = TimeSensorSendEvents;
    X3dPositionInterpolator::processEventCallback = PositionInterpolatorSendEvents;
    X3dOrientationInterpolator::processEventCallback = OrientationInterpolatorSendEvents;
    X3dColorInterpolator::processEventCallback = ColorInterpolatorSendEvents;
    X3dScalarInterpolator::processEventCallback = ScalarInterpolatorSendEvents;
    X3dCoordinateInterpolator::processEventCallback = CoordinateInterpolatorSendEvents;

    glColorMaterial(GL_FRONT_AND_BACK, GL_AMBIENT);
    glColorMaterial(GL_FRONT_AND_BACK, GL_DIFFUSE);
    glColorMaterial(GL_FRONT_AND_BACK, GL_EMISSION);
    glColorMaterial(GL_FRONT_AND_BACK, GL_SPECULAR);
    glColorMaterial(GL_FRONT_AND_BACK, GL_SHININESS);

    /*Enable light*/
    glEnable(GL_LIGHTING);

    GLint one[4] = {1, 1, 1, 0};
    glLightModeliv(GL_LIGHT_MODEL_AMBIENT, one);

    /* Use depth buffering for hidden surface elimination. */
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_NORMALIZE);

    glDepthMask(GL_TRUE);
    glDepthFunc(GL_LEQUAL);

    glEnable(GL_ALPHA_TEST);
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    glAlphaFunc(GL_NOTEQUAL, 0);

    glShadeModel(GL_SMOOTH);

    preRender = false;
    initRender = true;

    rootNode->treeRender(NULL);

    if(!viewPointExists)
    {
        X3dViewpoint viewpoint;
        viewpoint.fieldOfView = 0.785398;
        viewpoint.position = (float *)malloc(3 * sizeof(float));
        viewpoint.position[0] = 0;
        viewpoint.position[1] = 0;
        viewpoint.position[2] = 10;
        viewpoint.orientation = (float *)malloc(4 * sizeof(float));
        viewpoint.orientation[0] = 0;
        viewpoint.orientation[1] = 0;
        viewpoint.orientation[2] = 1;
        viewpoint.orientation[3] = 0;
        ViewpointRender(&viewpoint, NULL);
        free(viewpoint.position);
        viewpoint.position = NULL;
        free(viewpoint.orientation);
        viewpoint.orientation = NULL;
    }

    initRender = false;

}

void CPPRWD::finalize()
{
}