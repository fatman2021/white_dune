// VRML97/X3D file "" converted to C++ with white_dune

#include <stddef.h> // for NULL

class X3dSceneGraph;

class X3dNode {
public:
    X3dNode() {
        m_parent = NULL;
        m_protoRoot = NULL;
        m_data = NULL;
    }
    virtual void treeRender(void *dataptr) {
        if (m_protoRoot != NULL)
            m_protoRoot->treeRender(dataptr);
    }
    virtual void treeDoWithData(void *dataptr) {
        if (m_protoRoot != NULL)
            m_protoRoot->treeDoWithData(dataptr);
    }
    X3dNode *m_parent;
    X3dNode *m_protoRoot;
    void *m_data;
    virtual int getType() const = 0;
};

typedef void (*X3dCallback)(X3dNode *node, void *dataptr);
typedef bool (*X3dProcessEventCallback)(X3dNode *node, const char *event, void *dataptr);


class X3dColorRGBA : public X3dNode {
public:
    X3dNode* metadata;
    float* color;
    int color_length;
    void* extra_data;

    int getType() const { return 40; }

    static X3dCallback renderCallback;
    static X3dCallback treeRenderCallback;
    static X3dCallback doWithDataCallback;
    static X3dCallback treeDoWithDataCallback;
    static X3dProcessEventCallback processEventCallback;

    X3dColorRGBA() {
        metadata = NULL;
        color = NULL;
        color_length = 0;
        extra_data = NULL;
    }
    virtual void treeRender(void *dataptr) {
        int i;
        if (treeRenderCallback) {
            treeRenderCallback(this, dataptr);
            return;
        }
        if (m_protoRoot != NULL)
            m_protoRoot->treeRender(dataptr);
        else {
            if (metadata)
                metadata->treeRender(dataptr);
            render(dataptr);
        }
    }
    virtual void render(void *dataptr) {
        if (renderCallback)
            renderCallback(this, dataptr);
    }
    virtual void treeDoWithData(void *dataptr) {
        int i;
        if (treeDoWithDataCallback) {
            treeDoWithDataCallback(this, dataptr);
            return;
        }
        if (m_protoRoot != NULL)
            m_protoRoot->treeDoWithData(dataptr);
        else {
            if (metadata)
                metadata->treeDoWithData(dataptr);
            doWithData(dataptr);
        }
    }
    virtual void doWithData(void *dataptr) {
        if (doWithDataCallback)
            doWithDataCallback(this, dataptr);
    }
};

X3dCallback X3dColorRGBA::renderCallback = NULL;
X3dCallback X3dColorRGBA::treeRenderCallback = NULL;
X3dCallback X3dColorRGBA::doWithDataCallback = NULL;
X3dCallback X3dColorRGBA::treeDoWithDataCallback = NULL;
X3dProcessEventCallback X3dColorRGBA::processEventCallback = NULL;

int X3dColorRGBAType = 40;



class X3dVolumeEmitter : public X3dNode {
public:
    X3dNode* metadata;
    float speed;
    float variation;
    float mass;
    float surfaceArea;
    X3dNode* coord;
    float* direction;
    int direction_length;
    int* coordIndex;
    int coordIndex_length;
    bool internal;
    void* extra_data;

    int getType() const { return 323; }

    static X3dCallback renderCallback;
    static X3dCallback treeRenderCallback;
    static X3dCallback doWithDataCallback;
    static X3dCallback treeDoWithDataCallback;
    static X3dProcessEventCallback processEventCallback;

    X3dVolumeEmitter() {
        metadata = NULL;
        speed = 0.0f;
        variation = 0.0f;
        mass = 0.0f;
        surfaceArea = 0.0f;
        coord = NULL;
        direction = NULL;
        direction_length = 0;
        coordIndex = NULL;
        coordIndex_length = 0;
        internal = false;
        extra_data = NULL;
    }
    virtual void treeRender(void *dataptr) {
        int i;
        if (treeRenderCallback) {
            treeRenderCallback(this, dataptr);
            return;
        }
        if (m_protoRoot != NULL)
            m_protoRoot->treeRender(dataptr);
        else {
            if (metadata)
                metadata->treeRender(dataptr);
            if (coord)
                coord->treeRender(dataptr);
            render(dataptr);
        }
    }
    virtual void render(void *dataptr) {
        if (renderCallback)
            renderCallback(this, dataptr);
    }
    virtual void treeDoWithData(void *dataptr) {
        int i;
        if (treeDoWithDataCallback) {
            treeDoWithDataCallback(this, dataptr);
            return;
        }
        if (m_protoRoot != NULL)
            m_protoRoot->treeDoWithData(dataptr);
        else {
            if (metadata)
                metadata->treeDoWithData(dataptr);
            if (coord)
                coord->treeDoWithData(dataptr);
            doWithData(dataptr);
        }
    }
    virtual void doWithData(void *dataptr) {
        if (doWithDataCallback)
            doWithDataCallback(this, dataptr);
    }
};

X3dCallback X3dVolumeEmitter::renderCallback = NULL;
X3dCallback X3dVolumeEmitter::treeRenderCallback = NULL;
X3dCallback X3dVolumeEmitter::doWithDataCallback = NULL;
X3dCallback X3dVolumeEmitter::treeDoWithDataCallback = NULL;
X3dProcessEventCallback X3dVolumeEmitter::processEventCallback = NULL;

int X3dVolumeEmitterType = 323;



class X3dHAnimJoint : public X3dNode {
public:
    X3dNode** addChildren;
    int addChildren_length;
    X3dNode** removeChildren;
    int removeChildren_length;
    X3dNode* metadata;
    float* rotation;
    int rotation_length;
    float* translation;
    int translation_length;
    float* bboxCenter;
    int bboxCenter_length;
    float* bboxSize;
    int bboxSize_length;
    float* center;
    int center_length;
    float* scale;
    int scale_length;
    float* scaleOrientation;
    int scaleOrientation_length;
    X3dNode** children;
    int children_length;
    X3dNode** displacers;
    int displacers_length;
    float* limitOrientation;
    int limitOrientation_length;
    float* llimit;
    int llimit_length;
    const char* name;
    int* skinCoordIndex;
    int skinCoordIndex_length;
    float* skinCoordWeight;
    int skinCoordWeight_length;
    float* stiffness;
    int stiffness_length;
    float* ulimit;
    int ulimit_length;
    void* extra_data;

    int getType() const { return 107; }

    static X3dCallback renderCallback;
    static X3dCallback treeRenderCallback;
    static X3dCallback doWithDataCallback;
    static X3dCallback treeDoWithDataCallback;
    static X3dProcessEventCallback processEventCallback;

    X3dHAnimJoint() {
        metadata = NULL;
        rotation = NULL;
        rotation_length = 0;
        translation = NULL;
        translation_length = 0;
        bboxCenter = NULL;
        bboxCenter_length = 0;
        bboxSize = NULL;
        bboxSize_length = 0;
        center = NULL;
        center_length = 0;
        scale = NULL;
        scale_length = 0;
        scaleOrientation = NULL;
        scaleOrientation_length = 0;
        children = NULL;
        children_length = 0;
        displacers = NULL;
        displacers_length = 0;
        limitOrientation = NULL;
        limitOrientation_length = 0;
        llimit = NULL;
        llimit_length = 0;
        name = NULL;
        skinCoordIndex = NULL;
        skinCoordIndex_length = 0;
        skinCoordWeight = NULL;
        skinCoordWeight_length = 0;
        stiffness = NULL;
        stiffness_length = 0;
        ulimit = NULL;
        ulimit_length = 0;
        extra_data = NULL;
    }
    virtual void treeRender(void *dataptr) {
        int i;
        if (treeRenderCallback) {
            treeRenderCallback(this, dataptr);
            return;
        }
        if (m_protoRoot != NULL)
            m_protoRoot->treeRender(dataptr);
        else {
            if (metadata)
                metadata->treeRender(dataptr);
            if (children)
                for (i = 0; i < children_length; i++)
                    if (children[i])
                        children[i]->treeRender(dataptr);
            if (displacers)
                for (i = 0; i < displacers_length; i++)
                    if (displacers[i])
                        displacers[i]->treeRender(dataptr);
            render(dataptr);
        }
    }
    virtual void render(void *dataptr) {
        if (renderCallback)
            renderCallback(this, dataptr);
    }
    virtual void treeDoWithData(void *dataptr) {
        int i;
        if (treeDoWithDataCallback) {
            treeDoWithDataCallback(this, dataptr);
            return;
        }
        if (m_protoRoot != NULL)
            m_protoRoot->treeDoWithData(dataptr);
        else {
            if (metadata)
                metadata->treeDoWithData(dataptr);
            if (children)
                for (i = 0; i < children_length; i++)
                    if (children[i])
                        children[i]->treeDoWithData(dataptr);
            if (displacers)
                for (i = 0; i < displacers_length; i++)
                    if (displacers[i])
                        displacers[i]->treeDoWithData(dataptr);
            doWithData(dataptr);
        }
    }
    virtual void doWithData(void *dataptr) {
        if (doWithDataCallback)
            doWithDataCallback(this, dataptr);
    }
};

X3dCallback X3dHAnimJoint::renderCallback = NULL;
X3dCallback X3dHAnimJoint::treeRenderCallback = NULL;
X3dCallback X3dHAnimJoint::doWithDataCallback = NULL;
X3dCallback X3dHAnimJoint::treeDoWithDataCallback = NULL;
X3dProcessEventCallback X3dHAnimJoint::processEventCallback = NULL;

int X3dHAnimJointType = 107;



class X3dWindPhysicsModel : public X3dNode {
public:
    X3dNode* metadata;
    float* direction;
    int direction_length;
    bool enabled;
    float gustiness;
    float speed;
    float turbulence;
    void* extra_data;

    int getType() const { return 328; }

    static X3dCallback renderCallback;
    static X3dCallback treeRenderCallback;
    static X3dCallback doWithDataCallback;
    static X3dCallback treeDoWithDataCallback;
    static X3dProcessEventCallback processEventCallback;

    X3dWindPhysicsModel() {
        metadata = NULL;
        direction = NULL;
        direction_length = 0;
        enabled = false;
        gustiness = 0.0f;
        speed = 0.0f;
        turbulence = 0.0f;
        extra_data = NULL;
    }
    virtual void treeRender(void *dataptr) {
        int i;
        if (treeRenderCallback) {
            treeRenderCallback(this, dataptr);
            return;
        }
        if (m_protoRoot != NULL)
            m_protoRoot->treeRender(dataptr);
        else {
            if (metadata)
                metadata->treeRender(dataptr);
            render(dataptr);
        }
    }
    virtual void render(void *dataptr) {
        if (renderCallback)
            renderCallback(this, dataptr);
    }
    virtual void treeDoWithData(void *dataptr) {
        int i;
        if (treeDoWithDataCallback) {
            treeDoWithDataCallback(this, dataptr);
            return;
        }
        if (m_protoRoot != NULL)
            m_protoRoot->treeDoWithData(dataptr);
        else {
            if (metadata)
                metadata->treeDoWithData(dataptr);
            doWithData(dataptr);
        }
    }
    virtual void doWithData(void *dataptr) {
        if (doWithDataCallback)
            doWithDataCallback(this, dataptr);
    }
};

X3dCallback X3dWindPhysicsModel::renderCallback = NULL;
X3dCallback X3dWindPhysicsModel::treeRenderCallback = NULL;
X3dCallback X3dWindPhysicsModel::doWithDataCallback = NULL;
X3dCallback X3dWindPhysicsModel::treeDoWithDataCallback = NULL;
X3dProcessEventCallback X3dWindPhysicsModel::processEventCallback = NULL;

int X3dWindPhysicsModelType = 328;



class X3dTransform : public X3dNode {
public:
    X3dNode** addChildren;
    int addChildren_length;
    X3dNode** removeChildren;
    int removeChildren_length;
    X3dNode* metadata;
    float* rotation;
    int rotation_length;
    float* translation;
    int translation_length;
    float* bboxCenter;
    int bboxCenter_length;
    float* bboxSize;
    int bboxSize_length;
    float* center;
    int center_length;
    float* scale;
    int scale_length;
    float* scaleOrientation;
    int scaleOrientation_length;
    X3dNode** children;
    int children_length;
    void* extra_data;
    int num_route_source;
    X3dNode **route_sources;

    int getType() const { return 289; }

    static X3dCallback renderCallback;
    static X3dCallback treeRenderCallback;
    static X3dCallback doWithDataCallback;
    static X3dCallback treeDoWithDataCallback;
    static X3dProcessEventCallback processEventCallback;

    X3dTransform() {
        metadata = NULL;
        rotation = NULL;
        rotation_length = 0;
        translation = NULL;
        translation_length = 0;
        bboxCenter = NULL;
        bboxCenter_length = 0;
        bboxSize = NULL;
        bboxSize_length = 0;
        center = NULL;
        center_length = 0;
        scale = NULL;
        scale_length = 0;
        scaleOrientation = NULL;
        scaleOrientation_length = 0;
        children = NULL;
        children_length = 0;
        extra_data = NULL;
    }
    virtual void treeRender(void *dataptr) {
        int i;
        if (treeRenderCallback) {
            treeRenderCallback(this, dataptr);
            return;
        }
        if (m_protoRoot != NULL)
            m_protoRoot->treeRender(dataptr);
        else {
            if (metadata)
                metadata->treeRender(dataptr);
            if (children)
                for (i = 0; i < children_length; i++)
                    if (children[i])
                        children[i]->treeRender(dataptr);
            render(dataptr);
        }
    }
    virtual void render(void *dataptr) {
        if (renderCallback)
            renderCallback(this, dataptr);
    }
    virtual void treeDoWithData(void *dataptr) {
        int i;
        if (treeDoWithDataCallback) {
            treeDoWithDataCallback(this, dataptr);
            return;
        }
        if (m_protoRoot != NULL)
            m_protoRoot->treeDoWithData(dataptr);
        else {
            if (metadata)
                metadata->treeDoWithData(dataptr);
            if (children)
                for (i = 0; i < children_length; i++)
                    if (children[i])
                        children[i]->treeDoWithData(dataptr);
            doWithData(dataptr);
        }
    }
    virtual void doWithData(void *dataptr) {
        if (doWithDataCallback)
            doWithDataCallback(this, dataptr);
    }
};

X3dCallback X3dTransform::renderCallback = NULL;
X3dCallback X3dTransform::treeRenderCallback = NULL;
X3dCallback X3dTransform::doWithDataCallback = NULL;
X3dCallback X3dTransform::treeDoWithDataCallback = NULL;
X3dProcessEventCallback X3dTransform::processEventCallback = NULL;

int X3dTransformType = 289;



class X3dCylinderSensor : public X3dNode {
public:
    bool isActive;
    bool isOver;
    float* rotation_changed;
    int rotation_changed_length;
    float* trackPoint_changed;
    int trackPoint_changed_length;
    X3dNode* metadata;
    bool autoOffset;
    float* axisRotation;
    int axisRotation_length;
    const char* description;
    float diskAngle;
    bool enabled;
    float maxAngle;
    float minAngle;
    float offset;
    void* extra_data;

    int getType() const { return 65; }

    static X3dCallback renderCallback;
    static X3dCallback treeRenderCallback;
    static X3dCallback doWithDataCallback;
    static X3dCallback treeDoWithDataCallback;
    static X3dProcessEventCallback processEventCallback;

    X3dCylinderSensor() {
        metadata = NULL;
        autoOffset = false;
        axisRotation = NULL;
        axisRotation_length = 0;
        description = NULL;
        diskAngle = 0.0f;
        enabled = false;
        maxAngle = 0.0f;
        minAngle = 0.0f;
        offset = 0.0f;
        extra_data = NULL;
    }
    virtual void treeRender(void *dataptr) {
        int i;
        if (treeRenderCallback) {
            treeRenderCallback(this, dataptr);
            return;
        }
        if (m_protoRoot != NULL)
            m_protoRoot->treeRender(dataptr);
        else {
            if (metadata)
                metadata->treeRender(dataptr);
            render(dataptr);
        }
    }
    virtual void render(void *dataptr) {
        if (renderCallback)
            renderCallback(this, dataptr);
    }
    virtual void treeDoWithData(void *dataptr) {
        int i;
        if (treeDoWithDataCallback) {
            treeDoWithDataCallback(this, dataptr);
            return;
        }
        if (m_protoRoot != NULL)
            m_protoRoot->treeDoWithData(dataptr);
        else {
            if (metadata)
                metadata->treeDoWithData(dataptr);
            doWithData(dataptr);
        }
    }
    virtual void doWithData(void *dataptr) {
        if (doWithDataCallback)
            doWithDataCallback(this, dataptr);
    }
};

X3dCallback X3dCylinderSensor::renderCallback = NULL;
X3dCallback X3dCylinderSensor::treeRenderCallback = NULL;
X3dCallback X3dCylinderSensor::doWithDataCallback = NULL;
X3dCallback X3dCylinderSensor::treeDoWithDataCallback = NULL;
X3dProcessEventCallback X3dCylinderSensor::processEventCallback = NULL;

int X3dCylinderSensorType = 65;



class X3dCommonSurfaceShader : public X3dNode {
public:
    X3dNode** addChildren;
    int addChildren_length;
    X3dNode** removeChildren;
    int removeChildren_length;
    X3dNode* metadata;
    X3dNode** children;
    int children_length;
    float* bboxCenter;
    int bboxCenter_length;
    float* bboxSize;
    int bboxSize_length;
    void* extra_data;

    int getType() const { return 42; }

    static X3dCallback renderCallback;
    static X3dCallback treeRenderCallback;
    static X3dCallback doWithDataCallback;
    static X3dCallback treeDoWithDataCallback;
    static X3dProcessEventCallback processEventCallback;

    X3dCommonSurfaceShader() {
        metadata = NULL;
        children = NULL;
        children_length = 0;
        bboxCenter = NULL;
        bboxCenter_length = 0;
        bboxSize = NULL;
        bboxSize_length = 0;
        extra_data = NULL;
    }
    virtual void treeRender(void *dataptr) {
        int i;
        if (treeRenderCallback) {
            treeRenderCallback(this, dataptr);
            return;
        }
        if (m_protoRoot != NULL)
            m_protoRoot->treeRender(dataptr);
        else {
            if (metadata)
                metadata->treeRender(dataptr);
            if (children)
                for (i = 0; i < children_length; i++)
                    if (children[i])
                        children[i]->treeRender(dataptr);
            render(dataptr);
        }
    }
    virtual void render(void *dataptr) {
        if (renderCallback)
            renderCallback(this, dataptr);
    }
    virtual void treeDoWithData(void *dataptr) {
        int i;
        if (treeDoWithDataCallback) {
            treeDoWithDataCallback(this, dataptr);
            return;
        }
        if (m_protoRoot != NULL)
            m_protoRoot->treeDoWithData(dataptr);
        else {
            if (metadata)
                metadata->treeDoWithData(dataptr);
            if (children)
                for (i = 0; i < children_length; i++)
                    if (children[i])
                        children[i]->treeDoWithData(dataptr);
            doWithData(dataptr);
        }
    }
    virtual void doWithData(void *dataptr) {
        if (doWithDataCallback)
            doWithDataCallback(this, dataptr);
    }
};

X3dCallback X3dCommonSurfaceShader::renderCallback = NULL;
X3dCallback X3dCommonSurfaceShader::treeRenderCallback = NULL;
X3dCallback X3dCommonSurfaceShader::doWithDataCallback = NULL;
X3dCallback X3dCommonSurfaceShader::treeDoWithDataCallback = NULL;
X3dProcessEventCallback X3dCommonSurfaceShader::processEventCallback = NULL;

int X3dCommonSurfaceShaderType = 42;



class X3dPlaneSensor : public X3dNode {
public:
    bool isOver;
    bool isActive;
    float* trackPoint_changed;
    int trackPoint_changed_length;
    float* translation_changed;
    int translation_changed_length;
    X3dNode* metadata;
    bool autoOffset;
    float* axisRotation;
    int axisRotation_length;
    const char* description;
    bool enabled;
    float* maxPosition;
    int maxPosition_length;
    float* minPosition;
    int minPosition_length;
    float* offset;
    int offset_length;
    void* extra_data;

    int getType() const { return 196; }

    static X3dCallback renderCallback;
    static X3dCallback treeRenderCallback;
    static X3dCallback doWithDataCallback;
    static X3dCallback treeDoWithDataCallback;
    static X3dProcessEventCallback processEventCallback;

    X3dPlaneSensor() {
        metadata = NULL;
        autoOffset = false;
        axisRotation = NULL;
        axisRotation_length = 0;
        description = NULL;
        enabled = false;
        maxPosition = NULL;
        maxPosition_length = 0;
        minPosition = NULL;
        minPosition_length = 0;
        offset = NULL;
        offset_length = 0;
        extra_data = NULL;
    }
    virtual void treeRender(void *dataptr) {
        int i;
        if (treeRenderCallback) {
            treeRenderCallback(this, dataptr);
            return;
        }
        if (m_protoRoot != NULL)
            m_protoRoot->treeRender(dataptr);
        else {
            if (metadata)
                metadata->treeRender(dataptr);
            render(dataptr);
        }
    }
    virtual void render(void *dataptr) {
        if (renderCallback)
            renderCallback(this, dataptr);
    }
    virtual void treeDoWithData(void *dataptr) {
        int i;
        if (treeDoWithDataCallback) {
            treeDoWithDataCallback(this, dataptr);
            return;
        }
        if (m_protoRoot != NULL)
            m_protoRoot->treeDoWithData(dataptr);
        else {
            if (metadata)
                metadata->treeDoWithData(dataptr);
            doWithData(dataptr);
        }
    }
    virtual void doWithData(void *dataptr) {
        if (doWithDataCallback)
            doWithDataCallback(this, dataptr);
    }
};

X3dCallback X3dPlaneSensor::renderCallback = NULL;
X3dCallback X3dPlaneSensor::treeRenderCallback = NULL;
X3dCallback X3dPlaneSensor::doWithDataCallback = NULL;
X3dCallback X3dPlaneSensor::treeDoWithDataCallback = NULL;
X3dProcessEventCallback X3dPlaneSensor::processEventCallback = NULL;

int X3dPlaneSensorType = 196;



class X3dPositionInterpolator2D : public X3dNode {
public:
    float set_fraction;
    float* value_changed;
    int value_changed_length;
    X3dNode* metadata;
    float* key;
    int key_length;
    float* keyValue;
    int keyValue_length;
    void* extra_data;

    int getType() const { return 211; }

    static X3dCallback renderCallback;
    static X3dCallback treeRenderCallback;
    static X3dCallback doWithDataCallback;
    static X3dCallback treeDoWithDataCallback;
    static X3dProcessEventCallback processEventCallback;

    X3dPositionInterpolator2D() {
        metadata = NULL;
        key = NULL;
        key_length = 0;
        keyValue = NULL;
        keyValue_length = 0;
        extra_data = NULL;
    }
    virtual void treeRender(void *dataptr) {
        int i;
        if (treeRenderCallback) {
            treeRenderCallback(this, dataptr);
            return;
        }
        if (m_protoRoot != NULL)
            m_protoRoot->treeRender(dataptr);
        else {
            if (metadata)
                metadata->treeRender(dataptr);
            render(dataptr);
        }
    }
    virtual void render(void *dataptr) {
        if (renderCallback)
            renderCallback(this, dataptr);
    }
    virtual void treeDoWithData(void *dataptr) {
        int i;
        if (treeDoWithDataCallback) {
            treeDoWithDataCallback(this, dataptr);
            return;
        }
        if (m_protoRoot != NULL)
            m_protoRoot->treeDoWithData(dataptr);
        else {
            if (metadata)
                metadata->treeDoWithData(dataptr);
            doWithData(dataptr);
        }
    }
    virtual void doWithData(void *dataptr) {
        if (doWithDataCallback)
            doWithDataCallback(this, dataptr);
    }
};

X3dCallback X3dPositionInterpolator2D::renderCallback = NULL;
X3dCallback X3dPositionInterpolator2D::treeRenderCallback = NULL;
X3dCallback X3dPositionInterpolator2D::doWithDataCallback = NULL;
X3dCallback X3dPositionInterpolator2D::treeDoWithDataCallback = NULL;
X3dProcessEventCallback X3dPositionInterpolator2D::processEventCallback = NULL;

int X3dPositionInterpolator2DType = 211;



class X3dHAnimSite : public X3dNode {
public:
    X3dNode** addChildren;
    int addChildren_length;
    X3dNode** removeChildren;
    int removeChildren_length;
    X3dNode* metadata;
    float* rotation;
    int rotation_length;
    float* translation;
    int translation_length;
    float* bboxCenter;
    int bboxCenter_length;
    float* bboxSize;
    int bboxSize_length;
    float* center;
    int center_length;
    float* scale;
    int scale_length;
    float* scaleOrientation;
    int scaleOrientation_length;
    X3dNode** children;
    int children_length;
    const char* name;
    void* extra_data;

    int getType() const { return 109; }

    static X3dCallback renderCallback;
    static X3dCallback treeRenderCallback;
    static X3dCallback doWithDataCallback;
    static X3dCallback treeDoWithDataCallback;
    static X3dProcessEventCallback processEventCallback;

    X3dHAnimSite() {
        metadata = NULL;
        rotation = NULL;
        rotation_length = 0;
        translation = NULL;
        translation_length = 0;
        bboxCenter = NULL;
        bboxCenter_length = 0;
        bboxSize = NULL;
        bboxSize_length = 0;
        center = NULL;
        center_length = 0;
        scale = NULL;
        scale_length = 0;
        scaleOrientation = NULL;
        scaleOrientation_length = 0;
        children = NULL;
        children_length = 0;
        name = NULL;
        extra_data = NULL;
    }
    virtual void treeRender(void *dataptr) {
        int i;
        if (treeRenderCallback) {
            treeRenderCallback(this, dataptr);
            return;
        }
        if (m_protoRoot != NULL)
            m_protoRoot->treeRender(dataptr);
        else {
            if (metadata)
                metadata->treeRender(dataptr);
            if (children)
                for (i = 0; i < children_length; i++)
                    if (children[i])
                        children[i]->treeRender(dataptr);
            render(dataptr);
        }
    }
    virtual void render(void *dataptr) {
        if (renderCallback)
            renderCallback(this, dataptr);
    }
    virtual void treeDoWithData(void *dataptr) {
        int i;
        if (treeDoWithDataCallback) {
            treeDoWithDataCallback(this, dataptr);
            return;
        }
        if (m_protoRoot != NULL)
            m_protoRoot->treeDoWithData(dataptr);
        else {
            if (metadata)
                metadata->treeDoWithData(dataptr);
            if (children)
                for (i = 0; i < children_length; i++)
                    if (children[i])
                        children[i]->treeDoWithData(dataptr);
            doWithData(dataptr);
        }
    }
    virtual void doWithData(void *dataptr) {
        if (doWithDataCallback)
            doWithDataCallback(this, dataptr);
    }
};

X3dCallback X3dHAnimSite::renderCallback = NULL;
X3dCallback X3dHAnimSite::treeRenderCallback = NULL;
X3dCallback X3dHAnimSite::doWithDataCallback = NULL;
X3dCallback X3dHAnimSite::treeDoWithDataCallback = NULL;
X3dProcessEventCallback X3dHAnimSite::processEventCallback = NULL;

int X3dHAnimSiteType = 109;



class X3dImageTexture : public X3dNode {
public:
    X3dNode* metadata;
    const char** url;
    int url_length;
    bool repeatS;
    bool repeatT;
    X3dNode* textureProperties;
    X3dNode** effects;
    int effects_length;
    const char* alphaChannel;
    void* extra_data;

    int getType() const { return 112; }

    static X3dCallback renderCallback;
    static X3dCallback treeRenderCallback;
    static X3dCallback doWithDataCallback;
    static X3dCallback treeDoWithDataCallback;
    static X3dProcessEventCallback processEventCallback;

    X3dImageTexture() {
        metadata = NULL;
        url = NULL;
        url_length = 0;
        repeatS = false;
        repeatT = false;
        textureProperties = NULL;
        effects = NULL;
        effects_length = 0;
        alphaChannel = NULL;
        extra_data = NULL;
    }
    virtual void treeRender(void *dataptr) {
        int i;
        if (treeRenderCallback) {
            treeRenderCallback(this, dataptr);
            return;
        }
        if (m_protoRoot != NULL)
            m_protoRoot->treeRender(dataptr);
        else {
            if (metadata)
                metadata->treeRender(dataptr);
            if (textureProperties)
                textureProperties->treeRender(dataptr);
            if (effects)
                for (i = 0; i < effects_length; i++)
                    if (effects[i])
                        effects[i]->treeRender(dataptr);
            render(dataptr);
        }
    }
    virtual void render(void *dataptr) {
        if (renderCallback)
            renderCallback(this, dataptr);
    }
    virtual void treeDoWithData(void *dataptr) {
        int i;
        if (treeDoWithDataCallback) {
            treeDoWithDataCallback(this, dataptr);
            return;
        }
        if (m_protoRoot != NULL)
            m_protoRoot->treeDoWithData(dataptr);
        else {
            if (metadata)
                metadata->treeDoWithData(dataptr);
            if (textureProperties)
                textureProperties->treeDoWithData(dataptr);
            if (effects)
                for (i = 0; i < effects_length; i++)
                    if (effects[i])
                        effects[i]->treeDoWithData(dataptr);
            doWithData(dataptr);
        }
    }
    virtual void doWithData(void *dataptr) {
        if (doWithDataCallback)
            doWithDataCallback(this, dataptr);
    }
};

X3dCallback X3dImageTexture::renderCallback = NULL;
X3dCallback X3dImageTexture::treeRenderCallback = NULL;
X3dCallback X3dImageTexture::doWithDataCallback = NULL;
X3dCallback X3dImageTexture::treeDoWithDataCallback = NULL;
X3dProcessEventCallback X3dImageTexture::processEventCallback = NULL;

int X3dImageTextureType = 112;



class X3dScreenFontStyle : public X3dNode {
public:
    X3dNode* metadata;
    const char** family;
    int family_length;
    bool horizontal;
    const char** justify;
    int justify_length;
    const char* language;
    bool leftToRight;
    float spacing;
    const char* style;
    bool topToBottom;
    float pointSize;
    void* extra_data;

    int getType() const { return 232; }

    static X3dCallback renderCallback;
    static X3dCallback treeRenderCallback;
    static X3dCallback doWithDataCallback;
    static X3dCallback treeDoWithDataCallback;
    static X3dProcessEventCallback processEventCallback;

    X3dScreenFontStyle() {
        metadata = NULL;
        family = NULL;
        family_length = 0;
        horizontal = false;
        justify = NULL;
        justify_length = 0;
        language = NULL;
        leftToRight = false;
        spacing = 0.0f;
        style = NULL;
        topToBottom = false;
        pointSize = 0.0f;
        extra_data = NULL;
    }
    virtual void treeRender(void *dataptr) {
        int i;
        if (treeRenderCallback) {
            treeRenderCallback(this, dataptr);
            return;
        }
        if (m_protoRoot != NULL)
            m_protoRoot->treeRender(dataptr);
        else {
            if (metadata)
                metadata->treeRender(dataptr);
            render(dataptr);
        }
    }
    virtual void render(void *dataptr) {
        if (renderCallback)
            renderCallback(this, dataptr);
    }
    virtual void treeDoWithData(void *dataptr) {
        int i;
        if (treeDoWithDataCallback) {
            treeDoWithDataCallback(this, dataptr);
            return;
        }
        if (m_protoRoot != NULL)
            m_protoRoot->treeDoWithData(dataptr);
        else {
            if (metadata)
                metadata->treeDoWithData(dataptr);
            doWithData(dataptr);
        }
    }
    virtual void doWithData(void *dataptr) {
        if (doWithDataCallback)
            doWithDataCallback(this, dataptr);
    }
};

X3dCallback X3dScreenFontStyle::renderCallback = NULL;
X3dCallback X3dScreenFontStyle::treeRenderCallback = NULL;
X3dCallback X3dScreenFontStyle::doWithDataCallback = NULL;
X3dCallback X3dScreenFontStyle::treeDoWithDataCallback = NULL;
X3dProcessEventCallback X3dScreenFontStyle::processEventCallback = NULL;

int X3dScreenFontStyleType = 232;



class X3dNavigationInfo : public X3dNode {
public:
    bool set_bind;
    double bindTime;
    bool isBound;
    bool transitionComplete;
    X3dNode* metadata;
    float* avatarSize;
    int avatarSize_length;
    bool headlight;
    float speed;
    double transitionTime;
    const char** transitionType;
    int transitionType_length;
    const char** type;
    int type_length;
    float visibilityLimit;
    const char* blendingSort;
    void* extra_data;

    int getType() const { return 166; }

    static X3dCallback renderCallback;
    static X3dCallback treeRenderCallback;
    static X3dCallback doWithDataCallback;
    static X3dCallback treeDoWithDataCallback;
    static X3dProcessEventCallback processEventCallback;

    X3dNavigationInfo() {
        metadata = NULL;
        avatarSize = NULL;
        avatarSize_length = 0;
        headlight = false;
        speed = 0.0f;
        transitionTime = 0;
        transitionType = NULL;
        transitionType_length = 0;
        type = NULL;
        type_length = 0;
        visibilityLimit = 0.0f;
        blendingSort = NULL;
        extra_data = NULL;
    }
    virtual void treeRender(void *dataptr) {
        int i;
        if (treeRenderCallback) {
            treeRenderCallback(this, dataptr);
            return;
        }
        if (m_protoRoot != NULL)
            m_protoRoot->treeRender(dataptr);
        else {
            if (metadata)
                metadata->treeRender(dataptr);
            render(dataptr);
        }
    }
    virtual void render(void *dataptr) {
        if (renderCallback)
            renderCallback(this, dataptr);
    }
    virtual void treeDoWithData(void *dataptr) {
        int i;
        if (treeDoWithDataCallback) {
            treeDoWithDataCallback(this, dataptr);
            return;
        }
        if (m_protoRoot != NULL)
            m_protoRoot->treeDoWithData(dataptr);
        else {
            if (metadata)
                metadata->treeDoWithData(dataptr);
            doWithData(dataptr);
        }
    }
    virtual void doWithData(void *dataptr) {
        if (doWithDataCallback)
            doWithDataCallback(this, dataptr);
    }
};

X3dCallback X3dNavigationInfo::renderCallback = NULL;
X3dCallback X3dNavigationInfo::treeRenderCallback = NULL;
X3dCallback X3dNavigationInfo::doWithDataCallback = NULL;
X3dCallback X3dNavigationInfo::treeDoWithDataCallback = NULL;
X3dProcessEventCallback X3dNavigationInfo::processEventCallback = NULL;

int X3dNavigationInfoType = 166;



class X3dRemoteSelectionGroup : public X3dNode {
public:
    X3dNode** addChildren;
    int addChildren_length;
    X3dNode** removeChildren;
    int removeChildren_length;
    X3dNode* metadata;
    X3dNode** children;
    int children_length;
    float* bboxCenter;
    int bboxCenter_length;
    float* bboxSize;
    int bboxSize_length;
    void* extra_data;

    int getType() const { return 224; }

    static X3dCallback renderCallback;
    static X3dCallback treeRenderCallback;
    static X3dCallback doWithDataCallback;
    static X3dCallback treeDoWithDataCallback;
    static X3dProcessEventCallback processEventCallback;

    X3dRemoteSelectionGroup() {
        metadata = NULL;
        children = NULL;
        children_length = 0;
        bboxCenter = NULL;
        bboxCenter_length = 0;
        bboxSize = NULL;
        bboxSize_length = 0;
        extra_data = NULL;
    }
    virtual void treeRender(void *dataptr) {
        int i;
        if (treeRenderCallback) {
            treeRenderCallback(this, dataptr);
            return;
        }
        if (m_protoRoot != NULL)
            m_protoRoot->treeRender(dataptr);
        else {
            if (metadata)
                metadata->treeRender(dataptr);
            if (children)
                for (i = 0; i < children_length; i++)
                    if (children[i])
                        children[i]->treeRender(dataptr);
            render(dataptr);
        }
    }
    virtual void render(void *dataptr) {
        if (renderCallback)
            renderCallback(this, dataptr);
    }
    virtual void treeDoWithData(void *dataptr) {
        int i;
        if (treeDoWithDataCallback) {
            treeDoWithDataCallback(this, dataptr);
            return;
        }
        if (m_protoRoot != NULL)
            m_protoRoot->treeDoWithData(dataptr);
        else {
            if (metadata)
                metadata->treeDoWithData(dataptr);
            if (children)
                for (i = 0; i < children_length; i++)
                    if (children[i])
                        children[i]->treeDoWithData(dataptr);
            doWithData(dataptr);
        }
    }
    virtual void doWithData(void *dataptr) {
        if (doWithDataCallback)
            doWithDataCallback(this, dataptr);
    }
};

X3dCallback X3dRemoteSelectionGroup::renderCallback = NULL;
X3dCallback X3dRemoteSelectionGroup::treeRenderCallback = NULL;
X3dCallback X3dRemoteSelectionGroup::doWithDataCallback = NULL;
X3dCallback X3dRemoteSelectionGroup::treeDoWithDataCallback = NULL;
X3dProcessEventCallback X3dRemoteSelectionGroup::processEventCallback = NULL;

int X3dRemoteSelectionGroupType = 224;



class X3dCoordinateInterpolator : public X3dNode {
public:
    float set_fraction;
    float* value_changed;
    int value_changed_length;
    X3dNode* metadata;
    float* key;
    int key_length;
    float* keyValue;
    int keyValue_length;
    void* extra_data;

    int getType() const { return 57; }

    static X3dCallback renderCallback;
    static X3dCallback treeRenderCallback;
    static X3dCallback doWithDataCallback;
    static X3dCallback treeDoWithDataCallback;
    static X3dProcessEventCallback processEventCallback;

    X3dCoordinateInterpolator() {
        metadata = NULL;
        key = NULL;
        key_length = 0;
        keyValue = NULL;
        keyValue_length = 0;
        extra_data = NULL;
    }
    virtual void treeRender(void *dataptr) {
        int i;
        if (treeRenderCallback) {
            treeRenderCallback(this, dataptr);
            return;
        }
        if (m_protoRoot != NULL)
            m_protoRoot->treeRender(dataptr);
        else {
            if (metadata)
                metadata->treeRender(dataptr);
            render(dataptr);
        }
    }
    virtual void render(void *dataptr) {
        if (renderCallback)
            renderCallback(this, dataptr);
    }
    virtual void treeDoWithData(void *dataptr) {
        int i;
        if (treeDoWithDataCallback) {
            treeDoWithDataCallback(this, dataptr);
            return;
        }
        if (m_protoRoot != NULL)
            m_protoRoot->treeDoWithData(dataptr);
        else {
            if (metadata)
                metadata->treeDoWithData(dataptr);
            doWithData(dataptr);
        }
    }
    virtual void doWithData(void *dataptr) {
        if (doWithDataCallback)
            doWithDataCallback(this, dataptr);
    }
};

X3dCallback X3dCoordinateInterpolator::renderCallback = NULL;
X3dCallback X3dCoordinateInterpolator::treeRenderCallback = NULL;
X3dCallback X3dCoordinateInterpolator::doWithDataCallback = NULL;
X3dCallback X3dCoordinateInterpolator::treeDoWithDataCallback = NULL;
X3dProcessEventCallback X3dCoordinateInterpolator::processEventCallback = NULL;

int X3dCoordinateInterpolatorType = 57;



class X3dDirectionalLight : public X3dNode {
public:
    X3dNode* metadata;
    float ambientIntensity;
    float* color;
    int color_length;
    float* direction;
    int direction_length;
    bool global;
    float intensity;
    bool on;
    float* projectionRectangle;
    int projectionRectangle_length;
    float* projectionLocation;
    int projectionLocation_length;
    bool shadows;
    bool kambiShadows;
    bool kambiShadowsMain;
    float projectionNear;
    float projectionFar;
    float* up;
    int up_length;
    X3dNode* defaultShadowMap;
    X3dNode** effects;
    int effects_length;
    bool shadowVolumes;
    bool shadowVolumesMain;
    void* extra_data;

    int getType() const { return 67; }

    static X3dCallback renderCallback;
    static X3dCallback treeRenderCallback;
    static X3dCallback doWithDataCallback;
    static X3dCallback treeDoWithDataCallback;
    static X3dProcessEventCallback processEventCallback;

    X3dDirectionalLight() {
        metadata = NULL;
        ambientIntensity = 0.0f;
        color = NULL;
        color_length = 0;
        direction = NULL;
        direction_length = 0;
        global = false;
        intensity = 0.0f;
        on = false;
        projectionRectangle = NULL;
        projectionRectangle_length = 0;
        projectionLocation = NULL;
        projectionLocation_length = 0;
        shadows = false;
        kambiShadows = false;
        kambiShadowsMain = false;
        projectionNear = 0.0f;
        projectionFar = 0.0f;
        up = NULL;
        up_length = 0;
        defaultShadowMap = NULL;
        effects = NULL;
        effects_length = 0;
        shadowVolumes = false;
        shadowVolumesMain = false;
        extra_data = NULL;
    }
    virtual void treeRender(void *dataptr) {
        int i;
        if (treeRenderCallback) {
            treeRenderCallback(this, dataptr);
            return;
        }
        if (m_protoRoot != NULL)
            m_protoRoot->treeRender(dataptr);
        else {
            if (metadata)
                metadata->treeRender(dataptr);
            if (defaultShadowMap)
                defaultShadowMap->treeRender(dataptr);
            if (effects)
                for (i = 0; i < effects_length; i++)
                    if (effects[i])
                        effects[i]->treeRender(dataptr);
            render(dataptr);
        }
    }
    virtual void render(void *dataptr) {
        if (renderCallback)
            renderCallback(this, dataptr);
    }
    virtual void treeDoWithData(void *dataptr) {
        int i;
        if (treeDoWithDataCallback) {
            treeDoWithDataCallback(this, dataptr);
            return;
        }
        if (m_protoRoot != NULL)
            m_protoRoot->treeDoWithData(dataptr);
        else {
            if (metadata)
                metadata->treeDoWithData(dataptr);
            if (defaultShadowMap)
                defaultShadowMap->treeDoWithData(dataptr);
            if (effects)
                for (i = 0; i < effects_length; i++)
                    if (effects[i])
                        effects[i]->treeDoWithData(dataptr);
            doWithData(dataptr);
        }
    }
    virtual void doWithData(void *dataptr) {
        if (doWithDataCallback)
            doWithDataCallback(this, dataptr);
    }
};

X3dCallback X3dDirectionalLight::renderCallback = NULL;
X3dCallback X3dDirectionalLight::treeRenderCallback = NULL;
X3dCallback X3dDirectionalLight::doWithDataCallback = NULL;
X3dCallback X3dDirectionalLight::treeDoWithDataCallback = NULL;
X3dProcessEventCallback X3dDirectionalLight::processEventCallback = NULL;

int X3dDirectionalLightType = 67;



class X3dCollision : public X3dNode {
public:
    X3dNode** addChildren;
    int addChildren_length;
    X3dNode** removeChildren;
    int removeChildren_length;
    double collideTime;
    bool isActive;
    X3dNode* metadata;
    X3dNode** children;
    int children_length;
    bool enabled;
    float* bboxCenter;
    int bboxCenter_length;
    float* bboxSize;
    int bboxSize_length;
    X3dNode* proxy;
    void* extra_data;

    int getType() const { return 31; }

    static X3dCallback renderCallback;
    static X3dCallback treeRenderCallback;
    static X3dCallback doWithDataCallback;
    static X3dCallback treeDoWithDataCallback;
    static X3dProcessEventCallback processEventCallback;

    X3dCollision() {
        metadata = NULL;
        children = NULL;
        children_length = 0;
        enabled = false;
        bboxCenter = NULL;
        bboxCenter_length = 0;
        bboxSize = NULL;
        bboxSize_length = 0;
        proxy = NULL;
        extra_data = NULL;
    }
    virtual void treeRender(void *dataptr) {
        int i;
        if (treeRenderCallback) {
            treeRenderCallback(this, dataptr);
            return;
        }
        if (m_protoRoot != NULL)
            m_protoRoot->treeRender(dataptr);
        else {
            if (metadata)
                metadata->treeRender(dataptr);
            if (children)
                for (i = 0; i < children_length; i++)
                    if (children[i])
                        children[i]->treeRender(dataptr);
            if (proxy)
                proxy->treeRender(dataptr);
            render(dataptr);
        }
    }
    virtual void render(void *dataptr) {
        if (renderCallback)
            renderCallback(this, dataptr);
    }
    virtual void treeDoWithData(void *dataptr) {
        int i;
        if (treeDoWithDataCallback) {
            treeDoWithDataCallback(this, dataptr);
            return;
        }
        if (m_protoRoot != NULL)
            m_protoRoot->treeDoWithData(dataptr);
        else {
            if (metadata)
                metadata->treeDoWithData(dataptr);
            if (children)
                for (i = 0; i < children_length; i++)
                    if (children[i])
                        children[i]->treeDoWithData(dataptr);
            if (proxy)
                proxy->treeDoWithData(dataptr);
            doWithData(dataptr);
        }
    }
    virtual void doWithData(void *dataptr) {
        if (doWithDataCallback)
            doWithDataCallback(this, dataptr);
    }
};

X3dCallback X3dCollision::renderCallback = NULL;
X3dCallback X3dCollision::treeRenderCallback = NULL;
X3dCallback X3dCollision::doWithDataCallback = NULL;
X3dCallback X3dCollision::treeDoWithDataCallback = NULL;
X3dProcessEventCallback X3dCollision::processEventCallback = NULL;

int X3dCollisionType = 31;



class X3dNurbsGroup : public X3dNode {
public:
    X3dNode** addChildren;
    int addChildren_length;
    X3dNode** removeChildren;
    int removeChildren_length;
    X3dNode* metadata;
    X3dNode** children;
    int children_length;
    float* bboxCenter;
    int bboxCenter_length;
    float* bboxSize;
    int bboxSize_length;
    float tessellationScale;
    void* extra_data;

    int getType() const { return 172; }

    static X3dCallback renderCallback;
    static X3dCallback treeRenderCallback;
    static X3dCallback doWithDataCallback;
    static X3dCallback treeDoWithDataCallback;
    static X3dProcessEventCallback processEventCallback;

    X3dNurbsGroup() {
        metadata = NULL;
        children = NULL;
        children_length = 0;
        bboxCenter = NULL;
        bboxCenter_length = 0;
        bboxSize = NULL;
        bboxSize_length = 0;
        tessellationScale = 0.0f;
        extra_data = NULL;
    }
    virtual void treeRender(void *dataptr) {
        int i;
        if (treeRenderCallback) {
            treeRenderCallback(this, dataptr);
            return;
        }
        if (m_protoRoot != NULL)
            m_protoRoot->treeRender(dataptr);
        else {
            if (metadata)
                metadata->treeRender(dataptr);
            if (children)
                for (i = 0; i < children_length; i++)
                    if (children[i])
                        children[i]->treeRender(dataptr);
            render(dataptr);
        }
    }
    virtual void render(void *dataptr) {
        if (renderCallback)
            renderCallback(this, dataptr);
    }
    virtual void treeDoWithData(void *dataptr) {
        int i;
        if (treeDoWithDataCallback) {
            treeDoWithDataCallback(this, dataptr);
            return;
        }
        if (m_protoRoot != NULL)
            m_protoRoot->treeDoWithData(dataptr);
        else {
            if (metadata)
                metadata->treeDoWithData(dataptr);
            if (children)
                for (i = 0; i < children_length; i++)
                    if (children[i])
                        children[i]->treeDoWithData(dataptr);
            doWithData(dataptr);
        }
    }
    virtual void doWithData(void *dataptr) {
        if (doWithDataCallback)
            doWithDataCallback(this, dataptr);
    }
};

X3dCallback X3dNurbsGroup::renderCallback = NULL;
X3dCallback X3dNurbsGroup::treeRenderCallback = NULL;
X3dCallback X3dNurbsGroup::doWithDataCallback = NULL;
X3dCallback X3dNurbsGroup::treeDoWithDataCallback = NULL;
X3dProcessEventCallback X3dNurbsGroup::processEventCallback = NULL;

int X3dNurbsGroupType = 172;



class X3dPointEmitter : public X3dNode {
public:
    X3dNode* metadata;
    float speed;
    float variation;
    float mass;
    float surfaceArea;
    float* direction;
    int direction_length;
    float* position;
    int position_length;
    void* extra_data;

    int getType() const { return 197; }

    static X3dCallback renderCallback;
    static X3dCallback treeRenderCallback;
    static X3dCallback doWithDataCallback;
    static X3dCallback treeDoWithDataCallback;
    static X3dProcessEventCallback processEventCallback;

    X3dPointEmitter() {
        metadata = NULL;
        speed = 0.0f;
        variation = 0.0f;
        mass = 0.0f;
        surfaceArea = 0.0f;
        direction = NULL;
        direction_length = 0;
        position = NULL;
        position_length = 0;
        extra_data = NULL;
    }
    virtual void treeRender(void *dataptr) {
        int i;
        if (treeRenderCallback) {
            treeRenderCallback(this, dataptr);
            return;
        }
        if (m_protoRoot != NULL)
            m_protoRoot->treeRender(dataptr);
        else {
            if (metadata)
                metadata->treeRender(dataptr);
            render(dataptr);
        }
    }
    virtual void render(void *dataptr) {
        if (renderCallback)
            renderCallback(this, dataptr);
    }
    virtual void treeDoWithData(void *dataptr) {
        int i;
        if (treeDoWithDataCallback) {
            treeDoWithDataCallback(this, dataptr);
            return;
        }
        if (m_protoRoot != NULL)
            m_protoRoot->treeDoWithData(dataptr);
        else {
            if (metadata)
                metadata->treeDoWithData(dataptr);
            doWithData(dataptr);
        }
    }
    virtual void doWithData(void *dataptr) {
        if (doWithDataCallback)
            doWithDataCallback(this, dataptr);
    }
};

X3dCallback X3dPointEmitter::renderCallback = NULL;
X3dCallback X3dPointEmitter::treeRenderCallback = NULL;
X3dCallback X3dPointEmitter::doWithDataCallback = NULL;
X3dCallback X3dPointEmitter::treeDoWithDataCallback = NULL;
X3dProcessEventCallback X3dPointEmitter::processEventCallback = NULL;

int X3dPointEmitterType = 197;



class X3dProximitySensor : public X3dNode {
public:
    double enterTime;
    double exitTime;
    float* centerOfRotation_changed;
    int centerOfRotation_changed_length;
    bool isActive;
    float* position_changed;
    int position_changed_length;
    float* orientation_changed;
    int orientation_changed_length;
    X3dNode* metadata;
    float* center;
    int center_length;
    bool enabled;
    float* size;
    int size_length;
    void* extra_data;

    int getType() const { return 216; }

    static X3dCallback renderCallback;
    static X3dCallback treeRenderCallback;
    static X3dCallback doWithDataCallback;
    static X3dCallback treeDoWithDataCallback;
    static X3dProcessEventCallback processEventCallback;

    X3dProximitySensor() {
        metadata = NULL;
        center = NULL;
        center_length = 0;
        enabled = false;
        size = NULL;
        size_length = 0;
        extra_data = NULL;
    }
    virtual void treeRender(void *dataptr) {
        int i;
        if (treeRenderCallback) {
            treeRenderCallback(this, dataptr);
            return;
        }
        if (m_protoRoot != NULL)
            m_protoRoot->treeRender(dataptr);
        else {
            if (metadata)
                metadata->treeRender(dataptr);
            render(dataptr);
        }
    }
    virtual void render(void *dataptr) {
        if (renderCallback)
            renderCallback(this, dataptr);
    }
    virtual void treeDoWithData(void *dataptr) {
        int i;
        if (treeDoWithDataCallback) {
            treeDoWithDataCallback(this, dataptr);
            return;
        }
        if (m_protoRoot != NULL)
            m_protoRoot->treeDoWithData(dataptr);
        else {
            if (metadata)
                metadata->treeDoWithData(dataptr);
            doWithData(dataptr);
        }
    }
    virtual void doWithData(void *dataptr) {
        if (doWithDataCallback)
            doWithDataCallback(this, dataptr);
    }
};

X3dCallback X3dProximitySensor::renderCallback = NULL;
X3dCallback X3dProximitySensor::treeRenderCallback = NULL;
X3dCallback X3dProximitySensor::doWithDataCallback = NULL;
X3dCallback X3dProximitySensor::treeDoWithDataCallback = NULL;
X3dProcessEventCallback X3dProximitySensor::processEventCallback = NULL;

int X3dProximitySensorType = 216;



class X3dHAnimHumanoid : public X3dNode {
public:
    X3dNode* metadata;
    float* rotation;
    int rotation_length;
    float* translation;
    int translation_length;
    float* bboxCenter;
    int bboxCenter_length;
    float* bboxSize;
    int bboxSize_length;
    float* center;
    int center_length;
    float* scale;
    int scale_length;
    float* scaleOrientation;
    int scaleOrientation_length;
    const char** info;
    int info_length;
    X3dNode** joints;
    int joints_length;
    const char* name;
    X3dNode** segments;
    int segments_length;
    X3dNode** sites;
    int sites_length;
    X3dNode** skeleton;
    int skeleton_length;
    X3dNode** skin;
    int skin_length;
    X3dNode* skinCoord;
    X3dNode* skinNormal;
    const char* version;
    X3dNode** viewpoints;
    int viewpoints_length;
    void* extra_data;

    int getType() const { return 106; }

    static X3dCallback renderCallback;
    static X3dCallback treeRenderCallback;
    static X3dCallback doWithDataCallback;
    static X3dCallback treeDoWithDataCallback;
    static X3dProcessEventCallback processEventCallback;

    X3dHAnimHumanoid() {
        metadata = NULL;
        rotation = NULL;
        rotation_length = 0;
        translation = NULL;
        translation_length = 0;
        bboxCenter = NULL;
        bboxCenter_length = 0;
        bboxSize = NULL;
        bboxSize_length = 0;
        center = NULL;
        center_length = 0;
        scale = NULL;
        scale_length = 0;
        scaleOrientation = NULL;
        scaleOrientation_length = 0;
        info = NULL;
        info_length = 0;
        joints = NULL;
        joints_length = 0;
        name = NULL;
        segments = NULL;
        segments_length = 0;
        sites = NULL;
        sites_length = 0;
        skeleton = NULL;
        skeleton_length = 0;
        skin = NULL;
        skin_length = 0;
        skinCoord = NULL;
        skinNormal = NULL;
        version = NULL;
        viewpoints = NULL;
        viewpoints_length = 0;
        extra_data = NULL;
    }
    virtual void treeRender(void *dataptr) {
        int i;
        if (treeRenderCallback) {
            treeRenderCallback(this, dataptr);
            return;
        }
        if (m_protoRoot != NULL)
            m_protoRoot->treeRender(dataptr);
        else {
            if (metadata)
                metadata->treeRender(dataptr);
            if (joints)
                for (i = 0; i < joints_length; i++)
                    if (joints[i])
                        joints[i]->treeRender(dataptr);
            if (segments)
                for (i = 0; i < segments_length; i++)
                    if (segments[i])
                        segments[i]->treeRender(dataptr);
            if (sites)
                for (i = 0; i < sites_length; i++)
                    if (sites[i])
                        sites[i]->treeRender(dataptr);
            if (skeleton)
                for (i = 0; i < skeleton_length; i++)
                    if (skeleton[i])
                        skeleton[i]->treeRender(dataptr);
            if (skin)
                for (i = 0; i < skin_length; i++)
                    if (skin[i])
                        skin[i]->treeRender(dataptr);
            if (skinCoord)
                skinCoord->treeRender(dataptr);
            if (skinNormal)
                skinNormal->treeRender(dataptr);
            if (viewpoints)
                for (i = 0; i < viewpoints_length; i++)
                    if (viewpoints[i])
                        viewpoints[i]->treeRender(dataptr);
            render(dataptr);
        }
    }
    virtual void render(void *dataptr) {
        if (renderCallback)
            renderCallback(this, dataptr);
    }
    virtual void treeDoWithData(void *dataptr) {
        int i;
        if (treeDoWithDataCallback) {
            treeDoWithDataCallback(this, dataptr);
            return;
        }
        if (m_protoRoot != NULL)
            m_protoRoot->treeDoWithData(dataptr);
        else {
            if (metadata)
                metadata->treeDoWithData(dataptr);
            if (joints)
                for (i = 0; i < joints_length; i++)
                    if (joints[i])
                        joints[i]->treeDoWithData(dataptr);
            if (segments)
                for (i = 0; i < segments_length; i++)
                    if (segments[i])
                        segments[i]->treeDoWithData(dataptr);
            if (sites)
                for (i = 0; i < sites_length; i++)
                    if (sites[i])
                        sites[i]->treeDoWithData(dataptr);
            if (skeleton)
                for (i = 0; i < skeleton_length; i++)
                    if (skeleton[i])
                        skeleton[i]->treeDoWithData(dataptr);
            if (skin)
                for (i = 0; i < skin_length; i++)
                    if (skin[i])
                        skin[i]->treeDoWithData(dataptr);
            if (skinCoord)
                skinCoord->treeDoWithData(dataptr);
            if (skinNormal)
                skinNormal->treeDoWithData(dataptr);
            if (viewpoints)
                for (i = 0; i < viewpoints_length; i++)
                    if (viewpoints[i])
                        viewpoints[i]->treeDoWithData(dataptr);
            doWithData(dataptr);
        }
    }
    virtual void doWithData(void *dataptr) {
        if (doWithDataCallback)
            doWithDataCallback(this, dataptr);
    }
};

X3dCallback X3dHAnimHumanoid::renderCallback = NULL;
X3dCallback X3dHAnimHumanoid::treeRenderCallback = NULL;
X3dCallback X3dHAnimHumanoid::doWithDataCallback = NULL;
X3dCallback X3dHAnimHumanoid::treeDoWithDataCallback = NULL;
X3dProcessEventCallback X3dHAnimHumanoid::processEventCallback = NULL;

int X3dHAnimHumanoidType = 106;



class X3dIndexedFaceSet : public X3dNode {
public:
    int* set_colorIndex;
    int set_colorIndex_length;
    int* set_coordIndex;
    int set_coordIndex_length;
    int* set_normalIndex;
    int set_normalIndex_length;
    int* set_texCoordIndex;
    int set_texCoordIndex_length;
    X3dNode* metadata;
    X3dNode* color;
    X3dNode* coord;
    X3dNode* normal;
    X3dNode* texCoord;
    bool ccw;
    int* colorIndex;
    int colorIndex_length;
    bool colorPerVertex;
    bool convex;
    int* coordIndex;
    int coordIndex_length;
    float creaseAngle;
    int* normalIndex;
    int normalIndex_length;
    bool normalPerVertex;
    bool solid;
    int* texCoordIndex;
    int texCoordIndex_length;
    float* radianceTransfer;
    int radianceTransfer_length;
    X3dNode** attrib;
    int attrib_length;
    X3dNode* fogCoord;
    void* extra_data;
    int glName_number;

    int getType() const { return 115; }

    void setGlName(int number){ glName_number = number; }

    static X3dCallback renderCallback;
    static X3dCallback treeRenderCallback;
    static X3dCallback createNormalsCallback;
    static X3dCallback doWithDataCallback;
    static X3dCallback treeDoWithDataCallback;
    static X3dProcessEventCallback processEventCallback;

    X3dIndexedFaceSet() {
        metadata = NULL;
        color = NULL;
        coord = NULL;
        normal = NULL;
        texCoord = NULL;
        ccw = false;
        colorIndex = NULL;
        colorIndex_length = 0;
        colorPerVertex = false;
        convex = false;
        coordIndex = NULL;
        coordIndex_length = 0;
        creaseAngle = 0.0f;
        normalIndex = NULL;
        normalIndex_length = 0;
        normalPerVertex = false;
        solid = false;
        texCoordIndex = NULL;
        texCoordIndex_length = 0;
        radianceTransfer = NULL;
        radianceTransfer_length = 0;
        attrib = NULL;
        attrib_length = 0;
        fogCoord = NULL;
        extra_data = NULL;
    }
    virtual void treeRender(void *dataptr) {
        int i;
        if (treeRenderCallback) {
            treeRenderCallback(this, dataptr);
            return;
        }
        if (m_protoRoot != NULL)
            m_protoRoot->treeRender(dataptr);
        else {
            if (metadata)
                metadata->treeRender(dataptr);
            if (color)
                color->treeRender(dataptr);
            if (coord)
                coord->treeRender(dataptr);
            if (normal)
                normal->treeRender(dataptr);
            if (texCoord)
                texCoord->treeRender(dataptr);
            if (attrib)
                for (i = 0; i < attrib_length; i++)
                    if (attrib[i])
                        attrib[i]->treeRender(dataptr);
            if (fogCoord)
                fogCoord->treeRender(dataptr);
            render(dataptr);
        }
    }
    virtual void render(void *dataptr) {
        if (renderCallback)
            renderCallback(this, dataptr);
    }
    virtual void createNormals(void *dataptr) {
        if (createNormalsCallback)
            createNormalsCallback(this, dataptr);
    }
    virtual void treeDoWithData(void *dataptr) {
        int i;
        if (treeDoWithDataCallback) {
            treeDoWithDataCallback(this, dataptr);
            return;
        }
        if (m_protoRoot != NULL)
            m_protoRoot->treeDoWithData(dataptr);
        else {
            if (metadata)
                metadata->treeDoWithData(dataptr);
            if (color)
                color->treeDoWithData(dataptr);
            if (coord)
                coord->treeDoWithData(dataptr);
            if (normal)
                normal->treeDoWithData(dataptr);
            if (texCoord)
                texCoord->treeDoWithData(dataptr);
            if (attrib)
                for (i = 0; i < attrib_length; i++)
                    if (attrib[i])
                        attrib[i]->treeDoWithData(dataptr);
            if (fogCoord)
                fogCoord->treeDoWithData(dataptr);
            doWithData(dataptr);
        }
    }
    virtual void doWithData(void *dataptr) {
        if (doWithDataCallback)
            doWithDataCallback(this, dataptr);
    }
};

X3dCallback X3dIndexedFaceSet::renderCallback = NULL;
X3dCallback X3dIndexedFaceSet::treeRenderCallback = NULL;
X3dCallback X3dIndexedFaceSet::createNormalsCallback = NULL;
X3dCallback X3dIndexedFaceSet::doWithDataCallback = NULL;
X3dCallback X3dIndexedFaceSet::treeDoWithDataCallback = NULL;
X3dProcessEventCallback X3dIndexedFaceSet::processEventCallback = NULL;

int X3dIndexedFaceSetType = 115;



class X3dTriangleSet : public X3dNode {
public:
    X3dNode* metadata;
    X3dNode* color;
    X3dNode* coord;
    X3dNode* normal;
    X3dNode* texCoord;
    bool ccw;
    bool colorPerVertex;
    bool normalPerVertex;
    bool solid;
    float* radianceTransfer;
    int radianceTransfer_length;
    X3dNode** attrib;
    int attrib_length;
    X3dNode* fogCoord;
    void* extra_data;

    int getType() const { return 293; }

    static X3dCallback renderCallback;
    static X3dCallback treeRenderCallback;
    static X3dCallback doWithDataCallback;
    static X3dCallback treeDoWithDataCallback;
    static X3dProcessEventCallback processEventCallback;

    X3dTriangleSet() {
        metadata = NULL;
        color = NULL;
        coord = NULL;
        normal = NULL;
        texCoord = NULL;
        ccw = false;
        colorPerVertex = false;
        normalPerVertex = false;
        solid = false;
        radianceTransfer = NULL;
        radianceTransfer_length = 0;
        attrib = NULL;
        attrib_length = 0;
        fogCoord = NULL;
        extra_data = NULL;
    }
    virtual void treeRender(void *dataptr) {
        int i;
        if (treeRenderCallback) {
            treeRenderCallback(this, dataptr);
            return;
        }
        if (m_protoRoot != NULL)
            m_protoRoot->treeRender(dataptr);
        else {
            if (metadata)
                metadata->treeRender(dataptr);
            if (color)
                color->treeRender(dataptr);
            if (coord)
                coord->treeRender(dataptr);
            if (normal)
                normal->treeRender(dataptr);
            if (texCoord)
                texCoord->treeRender(dataptr);
            if (attrib)
                for (i = 0; i < attrib_length; i++)
                    if (attrib[i])
                        attrib[i]->treeRender(dataptr);
            if (fogCoord)
                fogCoord->treeRender(dataptr);
            render(dataptr);
        }
    }
    virtual void render(void *dataptr) {
        if (renderCallback)
            renderCallback(this, dataptr);
    }
    virtual void treeDoWithData(void *dataptr) {
        int i;
        if (treeDoWithDataCallback) {
            treeDoWithDataCallback(this, dataptr);
            return;
        }
        if (m_protoRoot != NULL)
            m_protoRoot->treeDoWithData(dataptr);
        else {
            if (metadata)
                metadata->treeDoWithData(dataptr);
            if (color)
                color->treeDoWithData(dataptr);
            if (coord)
                coord->treeDoWithData(dataptr);
            if (normal)
                normal->treeDoWithData(dataptr);
            if (texCoord)
                texCoord->treeDoWithData(dataptr);
            if (attrib)
                for (i = 0; i < attrib_length; i++)
                    if (attrib[i])
                        attrib[i]->treeDoWithData(dataptr);
            if (fogCoord)
                fogCoord->treeDoWithData(dataptr);
            doWithData(dataptr);
        }
    }
    virtual void doWithData(void *dataptr) {
        if (doWithDataCallback)
            doWithDataCallback(this, dataptr);
    }
};

X3dCallback X3dTriangleSet::renderCallback = NULL;
X3dCallback X3dTriangleSet::treeRenderCallback = NULL;
X3dCallback X3dTriangleSet::doWithDataCallback = NULL;
X3dCallback X3dTriangleSet::treeDoWithDataCallback = NULL;
X3dProcessEventCallback X3dTriangleSet::processEventCallback = NULL;

int X3dTriangleSetType = 293;



class X3dFontStyle : public X3dNode {
public:
    X3dNode* metadata;
    const char** family;
    int family_length;
    bool horizontal;
    const char** justify;
    int justify_length;
    const char* language;
    bool leftToRight;
    float spacing;
    const char* style;
    bool topToBottom;
    float size;
    void* extra_data;

    int getType() const { return 89; }

    static X3dCallback renderCallback;
    static X3dCallback treeRenderCallback;
    static X3dCallback doWithDataCallback;
    static X3dCallback treeDoWithDataCallback;
    static X3dProcessEventCallback processEventCallback;

    X3dFontStyle() {
        metadata = NULL;
        family = NULL;
        family_length = 0;
        horizontal = false;
        justify = NULL;
        justify_length = 0;
        language = NULL;
        leftToRight = false;
        spacing = 0.0f;
        style = NULL;
        topToBottom = false;
        size = 0.0f;
        extra_data = NULL;
    }
    virtual void treeRender(void *dataptr) {
        int i;
        if (treeRenderCallback) {
            treeRenderCallback(this, dataptr);
            return;
        }
        if (m_protoRoot != NULL)
            m_protoRoot->treeRender(dataptr);
        else {
            if (metadata)
                metadata->treeRender(dataptr);
            render(dataptr);
        }
    }
    virtual void render(void *dataptr) {
        if (renderCallback)
            renderCallback(this, dataptr);
    }
    virtual void treeDoWithData(void *dataptr) {
        int i;
        if (treeDoWithDataCallback) {
            treeDoWithDataCallback(this, dataptr);
            return;
        }
        if (m_protoRoot != NULL)
            m_protoRoot->treeDoWithData(dataptr);
        else {
            if (metadata)
                metadata->treeDoWithData(dataptr);
            doWithData(dataptr);
        }
    }
    virtual void doWithData(void *dataptr) {
        if (doWithDataCallback)
            doWithDataCallback(this, dataptr);
    }
};

X3dCallback X3dFontStyle::renderCallback = NULL;
X3dCallback X3dFontStyle::treeRenderCallback = NULL;
X3dCallback X3dFontStyle::doWithDataCallback = NULL;
X3dCallback X3dFontStyle::treeDoWithDataCallback = NULL;
X3dProcessEventCallback X3dFontStyle::processEventCallback = NULL;

int X3dFontStyleType = 89;



class X3dMaterial : public X3dNode {
public:
    X3dNode* metadata;
    float ambientIntensity;
    float* diffuseColor;
    int diffuseColor_length;
    float* emissiveColor;
    int emissiveColor_length;
    float shininess;
    float* specularColor;
    int specularColor_length;
    float transparency;
    float mirror;
    float* reflSpecular;
    int reflSpecular_length;
    float* reflDiffuse;
    int reflDiffuse_length;
    float* transSpecular;
    int transSpecular_length;
    float* transDiffuse;
    int transDiffuse_length;
    float reflSpecularExp;
    float transSpecularExp;
    void* extra_data;

    int getType() const { return 147; }

    static X3dCallback renderCallback;
    static X3dCallback treeRenderCallback;
    static X3dCallback doWithDataCallback;
    static X3dCallback treeDoWithDataCallback;
    static X3dProcessEventCallback processEventCallback;

    X3dMaterial() {
        metadata = NULL;
        ambientIntensity = 0.0f;
        diffuseColor = NULL;
        diffuseColor_length = 0;
        emissiveColor = NULL;
        emissiveColor_length = 0;
        shininess = 0.0f;
        specularColor = NULL;
        specularColor_length = 0;
        transparency = 0.0f;
        mirror = 0.0f;
        reflSpecular = NULL;
        reflSpecular_length = 0;
        reflDiffuse = NULL;
        reflDiffuse_length = 0;
        transSpecular = NULL;
        transSpecular_length = 0;
        transDiffuse = NULL;
        transDiffuse_length = 0;
        reflSpecularExp = 0.0f;
        transSpecularExp = 0.0f;
        extra_data = NULL;
    }
    virtual void treeRender(void *dataptr) {
        int i;
        if (treeRenderCallback) {
            treeRenderCallback(this, dataptr);
            return;
        }
        if (m_protoRoot != NULL)
            m_protoRoot->treeRender(dataptr);
        else {
            if (metadata)
                metadata->treeRender(dataptr);
            render(dataptr);
        }
    }
    virtual void render(void *dataptr) {
        if (renderCallback)
            renderCallback(this, dataptr);
    }
    virtual void treeDoWithData(void *dataptr) {
        int i;
        if (treeDoWithDataCallback) {
            treeDoWithDataCallback(this, dataptr);
            return;
        }
        if (m_protoRoot != NULL)
            m_protoRoot->treeDoWithData(dataptr);
        else {
            if (metadata)
                metadata->treeDoWithData(dataptr);
            doWithData(dataptr);
        }
    }
    virtual void doWithData(void *dataptr) {
        if (doWithDataCallback)
            doWithDataCallback(this, dataptr);
    }
};

X3dCallback X3dMaterial::renderCallback = NULL;
X3dCallback X3dMaterial::treeRenderCallback = NULL;
X3dCallback X3dMaterial::doWithDataCallback = NULL;
X3dCallback X3dMaterial::treeDoWithDataCallback = NULL;
X3dProcessEventCallback X3dMaterial::processEventCallback = NULL;

int X3dMaterialType = 147;



class X3dConeEmitter : public X3dNode {
public:
    X3dNode* metadata;
    float speed;
    float variation;
    float mass;
    float surfaceArea;
    float angle;
    float* direction;
    int direction_length;
    float* position;
    int position_length;
    void* extra_data;

    int getType() const { return 48; }

    static X3dCallback renderCallback;
    static X3dCallback treeRenderCallback;
    static X3dCallback doWithDataCallback;
    static X3dCallback treeDoWithDataCallback;
    static X3dProcessEventCallback processEventCallback;

    X3dConeEmitter() {
        metadata = NULL;
        speed = 0.0f;
        variation = 0.0f;
        mass = 0.0f;
        surfaceArea = 0.0f;
        angle = 0.0f;
        direction = NULL;
        direction_length = 0;
        position = NULL;
        position_length = 0;
        extra_data = NULL;
    }
    virtual void treeRender(void *dataptr) {
        int i;
        if (treeRenderCallback) {
            treeRenderCallback(this, dataptr);
            return;
        }
        if (m_protoRoot != NULL)
            m_protoRoot->treeRender(dataptr);
        else {
            if (metadata)
                metadata->treeRender(dataptr);
            render(dataptr);
        }
    }
    virtual void render(void *dataptr) {
        if (renderCallback)
            renderCallback(this, dataptr);
    }
    virtual void treeDoWithData(void *dataptr) {
        int i;
        if (treeDoWithDataCallback) {
            treeDoWithDataCallback(this, dataptr);
            return;
        }
        if (m_protoRoot != NULL)
            m_protoRoot->treeDoWithData(dataptr);
        else {
            if (metadata)
                metadata->treeDoWithData(dataptr);
            doWithData(dataptr);
        }
    }
    virtual void doWithData(void *dataptr) {
        if (doWithDataCallback)
            doWithDataCallback(this, dataptr);
    }
};

X3dCallback X3dConeEmitter::renderCallback = NULL;
X3dCallback X3dConeEmitter::treeRenderCallback = NULL;
X3dCallback X3dConeEmitter::doWithDataCallback = NULL;
X3dCallback X3dConeEmitter::treeDoWithDataCallback = NULL;
X3dProcessEventCallback X3dConeEmitter::processEventCallback = NULL;

int X3dConeEmitterType = 48;



class X3dOrientationInterpolator : public X3dNode {
public:
    float set_fraction;
    float* value_changed;
    int value_changed_length;
    X3dNode* metadata;
    float* key;
    int key_length;
    float* keyValue;
    int keyValue_length;
    void* extra_data;

    int getType() const { return 186; }

    static X3dCallback renderCallback;
    static X3dCallback treeRenderCallback;
    static X3dCallback doWithDataCallback;
    static X3dCallback treeDoWithDataCallback;
    static X3dProcessEventCallback processEventCallback;

    X3dOrientationInterpolator() {
        metadata = NULL;
        key = NULL;
        key_length = 0;
        keyValue = NULL;
        keyValue_length = 0;
        extra_data = NULL;
    }
    virtual void treeRender(void *dataptr) {
        int i;
        if (treeRenderCallback) {
            treeRenderCallback(this, dataptr);
            return;
        }
        if (m_protoRoot != NULL)
            m_protoRoot->treeRender(dataptr);
        else {
            if (metadata)
                metadata->treeRender(dataptr);
            render(dataptr);
        }
    }
    virtual void render(void *dataptr) {
        if (renderCallback)
            renderCallback(this, dataptr);
    }
    virtual void treeDoWithData(void *dataptr) {
        int i;
        if (treeDoWithDataCallback) {
            treeDoWithDataCallback(this, dataptr);
            return;
        }
        if (m_protoRoot != NULL)
            m_protoRoot->treeDoWithData(dataptr);
        else {
            if (metadata)
                metadata->treeDoWithData(dataptr);
            doWithData(dataptr);
        }
    }
    virtual void doWithData(void *dataptr) {
        if (doWithDataCallback)
            doWithDataCallback(this, dataptr);
    }
};

X3dCallback X3dOrientationInterpolator::renderCallback = NULL;
X3dCallback X3dOrientationInterpolator::treeRenderCallback = NULL;
X3dCallback X3dOrientationInterpolator::doWithDataCallback = NULL;
X3dCallback X3dOrientationInterpolator::treeDoWithDataCallback = NULL;
X3dProcessEventCallback X3dOrientationInterpolator::processEventCallback = NULL;

int X3dOrientationInterpolatorType = 186;



class X3dTimeSensor : public X3dNode {
public:
    double cycleTime;
    double elapsedTime;
    float fraction_changed;
    bool isActive;
    bool isPaused;
    double time;
    X3dNode* metadata;
    double cycleInterval;
    bool enabled;
    bool loop;
    double pauseTime;
    double resumeTime;
    double startTime;
    double stopTime;
    void* extra_data;

    int getType() const { return 284; }

    static X3dCallback renderCallback;
    static X3dCallback treeRenderCallback;
    static X3dCallback doWithDataCallback;
    static X3dCallback treeDoWithDataCallback;
    static X3dProcessEventCallback processEventCallback;

    X3dTimeSensor() {
        metadata = NULL;
        cycleInterval = 0;
        enabled = false;
        loop = false;
        pauseTime = 0;
        resumeTime = 0;
        startTime = 0;
        stopTime = 0;
        extra_data = NULL;
    }
    virtual void treeRender(void *dataptr) {
        int i;
        if (treeRenderCallback) {
            treeRenderCallback(this, dataptr);
            return;
        }
        if (m_protoRoot != NULL)
            m_protoRoot->treeRender(dataptr);
        else {
            if (metadata)
                metadata->treeRender(dataptr);
            render(dataptr);
        }
    }
    virtual void render(void *dataptr) {
        if (renderCallback)
            renderCallback(this, dataptr);
    }
    virtual void treeDoWithData(void *dataptr) {
        int i;
        if (treeDoWithDataCallback) {
            treeDoWithDataCallback(this, dataptr);
            return;
        }
        if (m_protoRoot != NULL)
            m_protoRoot->treeDoWithData(dataptr);
        else {
            if (metadata)
                metadata->treeDoWithData(dataptr);
            doWithData(dataptr);
        }
    }
    virtual void doWithData(void *dataptr) {
        if (doWithDataCallback)
            doWithDataCallback(this, dataptr);
    }
};

X3dCallback X3dTimeSensor::renderCallback = NULL;
X3dCallback X3dTimeSensor::treeRenderCallback = NULL;
X3dCallback X3dTimeSensor::doWithDataCallback = NULL;
X3dCallback X3dTimeSensor::treeDoWithDataCallback = NULL;
X3dProcessEventCallback X3dTimeSensor::processEventCallback = NULL;

int X3dTimeSensorType = 284;



class X3dIndexedLineSet : public X3dNode {
public:
    int* set_colorIndex;
    int set_colorIndex_length;
    int* set_coordIndex;
    int set_coordIndex_length;
    X3dNode* metadata;
    X3dNode** attrib;
    int attrib_length;
    X3dNode* color;
    X3dNode* coord;
    int* colorIndex;
    int colorIndex_length;
    bool colorPerVertex;
    int* coordIndex;
    int coordIndex_length;
    X3dNode* fogCoord;
    void* extra_data;
    int glName_number;

    int getType() const { return 116; }

    void setGlName(int number){ glName_number = number; }

    static X3dCallback renderCallback;
    static X3dCallback treeRenderCallback;
    static X3dCallback doWithDataCallback;
    static X3dCallback treeDoWithDataCallback;
    static X3dProcessEventCallback processEventCallback;

    X3dIndexedLineSet() {
        metadata = NULL;
        attrib = NULL;
        attrib_length = 0;
        color = NULL;
        coord = NULL;
        colorIndex = NULL;
        colorIndex_length = 0;
        colorPerVertex = false;
        coordIndex = NULL;
        coordIndex_length = 0;
        fogCoord = NULL;
        extra_data = NULL;
    }
    virtual void treeRender(void *dataptr) {
        int i;
        if (treeRenderCallback) {
            treeRenderCallback(this, dataptr);
            return;
        }
        if (m_protoRoot != NULL)
            m_protoRoot->treeRender(dataptr);
        else {
            if (metadata)
                metadata->treeRender(dataptr);
            if (attrib)
                for (i = 0; i < attrib_length; i++)
                    if (attrib[i])
                        attrib[i]->treeRender(dataptr);
            if (color)
                color->treeRender(dataptr);
            if (coord)
                coord->treeRender(dataptr);
            if (fogCoord)
                fogCoord->treeRender(dataptr);
            render(dataptr);
        }
    }
    virtual void render(void *dataptr) {
        if (renderCallback)
            renderCallback(this, dataptr);
    }
    virtual void treeDoWithData(void *dataptr) {
        int i;
        if (treeDoWithDataCallback) {
            treeDoWithDataCallback(this, dataptr);
            return;
        }
        if (m_protoRoot != NULL)
            m_protoRoot->treeDoWithData(dataptr);
        else {
            if (metadata)
                metadata->treeDoWithData(dataptr);
            if (attrib)
                for (i = 0; i < attrib_length; i++)
                    if (attrib[i])
                        attrib[i]->treeDoWithData(dataptr);
            if (color)
                color->treeDoWithData(dataptr);
            if (coord)
                coord->treeDoWithData(dataptr);
            if (fogCoord)
                fogCoord->treeDoWithData(dataptr);
            doWithData(dataptr);
        }
    }
    virtual void doWithData(void *dataptr) {
        if (doWithDataCallback)
            doWithDataCallback(this, dataptr);
    }
};

X3dCallback X3dIndexedLineSet::renderCallback = NULL;
X3dCallback X3dIndexedLineSet::treeRenderCallback = NULL;
X3dCallback X3dIndexedLineSet::doWithDataCallback = NULL;
X3dCallback X3dIndexedLineSet::treeDoWithDataCallback = NULL;
X3dProcessEventCallback X3dIndexedLineSet::processEventCallback = NULL;

int X3dIndexedLineSetType = 116;



class X3dMultiPart : public X3dNode {
public:
    X3dNode** addChildren;
    int addChildren_length;
    X3dNode** removeChildren;
    int removeChildren_length;
    X3dNode* metadata;
    X3dNode** children;
    int children_length;
    float* bboxCenter;
    int bboxCenter_length;
    float* bboxSize;
    int bboxSize_length;
    void* extra_data;

    int getType() const { return 162; }

    static X3dCallback renderCallback;
    static X3dCallback treeRenderCallback;
    static X3dCallback doWithDataCallback;
    static X3dCallback treeDoWithDataCallback;
    static X3dProcessEventCallback processEventCallback;

    X3dMultiPart() {
        metadata = NULL;
        children = NULL;
        children_length = 0;
        bboxCenter = NULL;
        bboxCenter_length = 0;
        bboxSize = NULL;
        bboxSize_length = 0;
        extra_data = NULL;
    }
    virtual void treeRender(void *dataptr) {
        int i;
        if (treeRenderCallback) {
            treeRenderCallback(this, dataptr);
            return;
        }
        if (m_protoRoot != NULL)
            m_protoRoot->treeRender(dataptr);
        else {
            if (metadata)
                metadata->treeRender(dataptr);
            if (children)
                for (i = 0; i < children_length; i++)
                    if (children[i])
                        children[i]->treeRender(dataptr);
            render(dataptr);
        }
    }
    virtual void render(void *dataptr) {
        if (renderCallback)
            renderCallback(this, dataptr);
    }
    virtual void treeDoWithData(void *dataptr) {
        int i;
        if (treeDoWithDataCallback) {
            treeDoWithDataCallback(this, dataptr);
            return;
        }
        if (m_protoRoot != NULL)
            m_protoRoot->treeDoWithData(dataptr);
        else {
            if (metadata)
                metadata->treeDoWithData(dataptr);
            if (children)
                for (i = 0; i < children_length; i++)
                    if (children[i])
                        children[i]->treeDoWithData(dataptr);
            doWithData(dataptr);
        }
    }
    virtual void doWithData(void *dataptr) {
        if (doWithDataCallback)
            doWithDataCallback(this, dataptr);
    }
};

X3dCallback X3dMultiPart::renderCallback = NULL;
X3dCallback X3dMultiPart::treeRenderCallback = NULL;
X3dCallback X3dMultiPart::doWithDataCallback = NULL;
X3dCallback X3dMultiPart::treeDoWithDataCallback = NULL;
X3dProcessEventCallback X3dMultiPart::processEventCallback = NULL;

int X3dMultiPartType = 162;



class X3dViewport : public X3dNode {
public:
    X3dNode** addChildren;
    int addChildren_length;
    X3dNode** removeChildren;
    int removeChildren_length;
    X3dNode* metadata;
    X3dNode** children;
    int children_length;
    float* bboxCenter;
    int bboxCenter_length;
    float* bboxSize;
    int bboxSize_length;
    float* clipBoundary;
    int clipBoundary_length;
    void* extra_data;

    int getType() const { return 318; }

    static X3dCallback renderCallback;
    static X3dCallback treeRenderCallback;
    static X3dCallback doWithDataCallback;
    static X3dCallback treeDoWithDataCallback;
    static X3dProcessEventCallback processEventCallback;

    X3dViewport() {
        metadata = NULL;
        children = NULL;
        children_length = 0;
        bboxCenter = NULL;
        bboxCenter_length = 0;
        bboxSize = NULL;
        bboxSize_length = 0;
        clipBoundary = NULL;
        clipBoundary_length = 0;
        extra_data = NULL;
    }
    virtual void treeRender(void *dataptr) {
        int i;
        if (treeRenderCallback) {
            treeRenderCallback(this, dataptr);
            return;
        }
        if (m_protoRoot != NULL)
            m_protoRoot->treeRender(dataptr);
        else {
            if (metadata)
                metadata->treeRender(dataptr);
            if (children)
                for (i = 0; i < children_length; i++)
                    if (children[i])
                        children[i]->treeRender(dataptr);
            render(dataptr);
        }
    }
    virtual void render(void *dataptr) {
        if (renderCallback)
            renderCallback(this, dataptr);
    }
    virtual void treeDoWithData(void *dataptr) {
        int i;
        if (treeDoWithDataCallback) {
            treeDoWithDataCallback(this, dataptr);
            return;
        }
        if (m_protoRoot != NULL)
            m_protoRoot->treeDoWithData(dataptr);
        else {
            if (metadata)
                metadata->treeDoWithData(dataptr);
            if (children)
                for (i = 0; i < children_length; i++)
                    if (children[i])
                        children[i]->treeDoWithData(dataptr);
            doWithData(dataptr);
        }
    }
    virtual void doWithData(void *dataptr) {
        if (doWithDataCallback)
            doWithDataCallback(this, dataptr);
    }
};

X3dCallback X3dViewport::renderCallback = NULL;
X3dCallback X3dViewport::treeRenderCallback = NULL;
X3dCallback X3dViewport::doWithDataCallback = NULL;
X3dCallback X3dViewport::treeDoWithDataCallback = NULL;
X3dProcessEventCallback X3dViewport::processEventCallback = NULL;

int X3dViewportType = 318;



class X3dAnchor : public X3dNode {
public:
    X3dNode** addChildren;
    int addChildren_length;
    X3dNode** removeChildren;
    int removeChildren_length;
    X3dNode* metadata;
    X3dNode** children;
    int children_length;
    float* bboxCenter;
    int bboxCenter_length;
    float* bboxSize;
    int bboxSize_length;
    const char* description;
    const char** parameter;
    int parameter_length;
    const char** url;
    int url_length;
    void* extra_data;

    int getType() const { return 0; }

    static X3dCallback renderCallback;
    static X3dCallback treeRenderCallback;
    static X3dCallback doWithDataCallback;
    static X3dCallback treeDoWithDataCallback;
    static X3dProcessEventCallback processEventCallback;

    X3dAnchor() {
        metadata = NULL;
        children = NULL;
        children_length = 0;
        bboxCenter = NULL;
        bboxCenter_length = 0;
        bboxSize = NULL;
        bboxSize_length = 0;
        description = NULL;
        parameter = NULL;
        parameter_length = 0;
        url = NULL;
        url_length = 0;
        extra_data = NULL;
    }
    virtual void treeRender(void *dataptr) {
        int i;
        if (treeRenderCallback) {
            treeRenderCallback(this, dataptr);
            return;
        }
        if (m_protoRoot != NULL)
            m_protoRoot->treeRender(dataptr);
        else {
            if (metadata)
                metadata->treeRender(dataptr);
            if (children)
                for (i = 0; i < children_length; i++)
                    if (children[i])
                        children[i]->treeRender(dataptr);
            render(dataptr);
        }
    }
    virtual void render(void *dataptr) {
        if (renderCallback)
            renderCallback(this, dataptr);
    }
    virtual void treeDoWithData(void *dataptr) {
        int i;
        if (treeDoWithDataCallback) {
            treeDoWithDataCallback(this, dataptr);
            return;
        }
        if (m_protoRoot != NULL)
            m_protoRoot->treeDoWithData(dataptr);
        else {
            if (metadata)
                metadata->treeDoWithData(dataptr);
            if (children)
                for (i = 0; i < children_length; i++)
                    if (children[i])
                        children[i]->treeDoWithData(dataptr);
            doWithData(dataptr);
        }
    }
    virtual void doWithData(void *dataptr) {
        if (doWithDataCallback)
            doWithDataCallback(this, dataptr);
    }
};

X3dCallback X3dAnchor::renderCallback = NULL;
X3dCallback X3dAnchor::treeRenderCallback = NULL;
X3dCallback X3dAnchor::doWithDataCallback = NULL;
X3dCallback X3dAnchor::treeDoWithDataCallback = NULL;
X3dProcessEventCallback X3dAnchor::processEventCallback = NULL;

int X3dAnchorType = 0;



class X3dColor : public X3dNode {
public:
    X3dNode* metadata;
    float* color;
    int color_length;
    void* extra_data;

    int getType() const { return 35; }

    static X3dCallback renderCallback;
    static X3dCallback treeRenderCallback;
    static X3dCallback doWithDataCallback;
    static X3dCallback treeDoWithDataCallback;
    static X3dProcessEventCallback processEventCallback;

    X3dColor() {
        metadata = NULL;
        color = NULL;
        color_length = 0;
        extra_data = NULL;
    }
    virtual void treeRender(void *dataptr) {
        int i;
        if (treeRenderCallback) {
            treeRenderCallback(this, dataptr);
            return;
        }
        if (m_protoRoot != NULL)
            m_protoRoot->treeRender(dataptr);
        else {
            if (metadata)
                metadata->treeRender(dataptr);
            render(dataptr);
        }
    }
    virtual void render(void *dataptr) {
        if (renderCallback)
            renderCallback(this, dataptr);
    }
    virtual void treeDoWithData(void *dataptr) {
        int i;
        if (treeDoWithDataCallback) {
            treeDoWithDataCallback(this, dataptr);
            return;
        }
        if (m_protoRoot != NULL)
            m_protoRoot->treeDoWithData(dataptr);
        else {
            if (metadata)
                metadata->treeDoWithData(dataptr);
            doWithData(dataptr);
        }
    }
    virtual void doWithData(void *dataptr) {
        if (doWithDataCallback)
            doWithDataCallback(this, dataptr);
    }
};

X3dCallback X3dColor::renderCallback = NULL;
X3dCallback X3dColor::treeRenderCallback = NULL;
X3dCallback X3dColor::doWithDataCallback = NULL;
X3dCallback X3dColor::treeDoWithDataCallback = NULL;
X3dProcessEventCallback X3dColor::processEventCallback = NULL;

int X3dColorType = 35;



class X3dShape : public X3dNode {
public:
    X3dNode* metadata;
    X3dNode* appearance;
    X3dNode* geometry;
    float* bboxCenter;
    int bboxCenter_length;
    float* bboxSize;
    int bboxSize_length;
    X3dNode* octreeTriangles;
    const char* shading;
    void* extra_data;

    int getType() const { return 240; }

    static X3dCallback renderCallback;
    static X3dCallback treeRenderCallback;
    static X3dCallback doWithDataCallback;
    static X3dCallback treeDoWithDataCallback;
    static X3dProcessEventCallback processEventCallback;

    X3dShape() {
        metadata = NULL;
        appearance = NULL;
        geometry = NULL;
        bboxCenter = NULL;
        bboxCenter_length = 0;
        bboxSize = NULL;
        bboxSize_length = 0;
        octreeTriangles = NULL;
        shading = NULL;
        extra_data = NULL;
    }
    virtual void treeRender(void *dataptr) {
        int i;
        if (treeRenderCallback) {
            treeRenderCallback(this, dataptr);
            return;
        }
        if (m_protoRoot != NULL)
            m_protoRoot->treeRender(dataptr);
        else {
            if (metadata)
                metadata->treeRender(dataptr);
            if (appearance)
                appearance->treeRender(dataptr);
            if (geometry)
                geometry->treeRender(dataptr);
            if (octreeTriangles)
                octreeTriangles->treeRender(dataptr);
            render(dataptr);
        }
    }
    virtual void render(void *dataptr) {
        if (renderCallback)
            renderCallback(this, dataptr);
    }
    virtual void treeDoWithData(void *dataptr) {
        int i;
        if (treeDoWithDataCallback) {
            treeDoWithDataCallback(this, dataptr);
            return;
        }
        if (m_protoRoot != NULL)
            m_protoRoot->treeDoWithData(dataptr);
        else {
            if (metadata)
                metadata->treeDoWithData(dataptr);
            if (appearance)
                appearance->treeDoWithData(dataptr);
            if (geometry)
                geometry->treeDoWithData(dataptr);
            if (octreeTriangles)
                octreeTriangles->treeDoWithData(dataptr);
            doWithData(dataptr);
        }
    }
    virtual void doWithData(void *dataptr) {
        if (doWithDataCallback)
            doWithDataCallback(this, dataptr);
    }
};

X3dCallback X3dShape::renderCallback = NULL;
X3dCallback X3dShape::treeRenderCallback = NULL;
X3dCallback X3dShape::doWithDataCallback = NULL;
X3dCallback X3dShape::treeDoWithDataCallback = NULL;
X3dProcessEventCallback X3dShape::processEventCallback = NULL;

int X3dShapeType = 240;



class X3dNormalInterpolator : public X3dNode {
public:
    float set_fraction;
    float* value_changed;
    int value_changed_length;
    X3dNode* metadata;
    float* key;
    int key_length;
    float* keyValue;
    int keyValue_length;
    void* extra_data;

    int getType() const { return 168; }

    static X3dCallback renderCallback;
    static X3dCallback treeRenderCallback;
    static X3dCallback doWithDataCallback;
    static X3dCallback treeDoWithDataCallback;
    static X3dProcessEventCallback processEventCallback;

    X3dNormalInterpolator() {
        metadata = NULL;
        key = NULL;
        key_length = 0;
        keyValue = NULL;
        keyValue_length = 0;
        extra_data = NULL;
    }
    virtual void treeRender(void *dataptr) {
        int i;
        if (treeRenderCallback) {
            treeRenderCallback(this, dataptr);
            return;
        }
        if (m_protoRoot != NULL)
            m_protoRoot->treeRender(dataptr);
        else {
            if (metadata)
                metadata->treeRender(dataptr);
            render(dataptr);
        }
    }
    virtual void render(void *dataptr) {
        if (renderCallback)
            renderCallback(this, dataptr);
    }
    virtual void treeDoWithData(void *dataptr) {
        int i;
        if (treeDoWithDataCallback) {
            treeDoWithDataCallback(this, dataptr);
            return;
        }
        if (m_protoRoot != NULL)
            m_protoRoot->treeDoWithData(dataptr);
        else {
            if (metadata)
                metadata->treeDoWithData(dataptr);
            doWithData(dataptr);
        }
    }
    virtual void doWithData(void *dataptr) {
        if (doWithDataCallback)
            doWithDataCallback(this, dataptr);
    }
};

X3dCallback X3dNormalInterpolator::renderCallback = NULL;
X3dCallback X3dNormalInterpolator::treeRenderCallback = NULL;
X3dCallback X3dNormalInterpolator::doWithDataCallback = NULL;
X3dCallback X3dNormalInterpolator::treeDoWithDataCallback = NULL;
X3dProcessEventCallback X3dNormalInterpolator::processEventCallback = NULL;

int X3dNormalInterpolatorType = 168;



class X3dScalarInterpolator : public X3dNode {
public:
    float set_fraction;
    float value_changed;
    X3dNode* metadata;
    float* key;
    int key_length;
    float* keyValue;
    int keyValue_length;
    void* extra_data;

    int getType() const { return 230; }

    static X3dCallback renderCallback;
    static X3dCallback treeRenderCallback;
    static X3dCallback doWithDataCallback;
    static X3dCallback treeDoWithDataCallback;
    static X3dProcessEventCallback processEventCallback;

    X3dScalarInterpolator() {
        metadata = NULL;
        key = NULL;
        key_length = 0;
        keyValue = NULL;
        keyValue_length = 0;
        extra_data = NULL;
    }
    virtual void treeRender(void *dataptr) {
        int i;
        if (treeRenderCallback) {
            treeRenderCallback(this, dataptr);
            return;
        }
        if (m_protoRoot != NULL)
            m_protoRoot->treeRender(dataptr);
        else {
            if (metadata)
                metadata->treeRender(dataptr);
            render(dataptr);
        }
    }
    virtual void render(void *dataptr) {
        if (renderCallback)
            renderCallback(this, dataptr);
    }
    virtual void treeDoWithData(void *dataptr) {
        int i;
        if (treeDoWithDataCallback) {
            treeDoWithDataCallback(this, dataptr);
            return;
        }
        if (m_protoRoot != NULL)
            m_protoRoot->treeDoWithData(dataptr);
        else {
            if (metadata)
                metadata->treeDoWithData(dataptr);
            doWithData(dataptr);
        }
    }
    virtual void doWithData(void *dataptr) {
        if (doWithDataCallback)
            doWithDataCallback(this, dataptr);
    }
};

X3dCallback X3dScalarInterpolator::renderCallback = NULL;
X3dCallback X3dScalarInterpolator::treeRenderCallback = NULL;
X3dCallback X3dScalarInterpolator::doWithDataCallback = NULL;
X3dCallback X3dScalarInterpolator::treeDoWithDataCallback = NULL;
X3dProcessEventCallback X3dScalarInterpolator::processEventCallback = NULL;

int X3dScalarInterpolatorType = 230;



class X3dHAnimSegment : public X3dNode {
public:
    X3dNode** addChildren;
    int addChildren_length;
    X3dNode** removeChildren;
    int removeChildren_length;
    X3dNode* metadata;
    X3dNode** children;
    int children_length;
    float* bboxCenter;
    int bboxCenter_length;
    float* bboxSize;
    int bboxSize_length;
    float* centerOfMass;
    int centerOfMass_length;
    X3dNode* coord;
    X3dNode** displacers;
    int displacers_length;
    float mass;
    float* momentsOfInertia;
    int momentsOfInertia_length;
    const char* name;
    void* extra_data;

    int getType() const { return 108; }

    static X3dCallback renderCallback;
    static X3dCallback treeRenderCallback;
    static X3dCallback doWithDataCallback;
    static X3dCallback treeDoWithDataCallback;
    static X3dProcessEventCallback processEventCallback;

    X3dHAnimSegment() {
        metadata = NULL;
        children = NULL;
        children_length = 0;
        bboxCenter = NULL;
        bboxCenter_length = 0;
        bboxSize = NULL;
        bboxSize_length = 0;
        centerOfMass = NULL;
        centerOfMass_length = 0;
        coord = NULL;
        displacers = NULL;
        displacers_length = 0;
        mass = 0.0f;
        momentsOfInertia = NULL;
        momentsOfInertia_length = 0;
        name = NULL;
        extra_data = NULL;
    }
    virtual void treeRender(void *dataptr) {
        int i;
        if (treeRenderCallback) {
            treeRenderCallback(this, dataptr);
            return;
        }
        if (m_protoRoot != NULL)
            m_protoRoot->treeRender(dataptr);
        else {
            if (metadata)
                metadata->treeRender(dataptr);
            if (children)
                for (i = 0; i < children_length; i++)
                    if (children[i])
                        children[i]->treeRender(dataptr);
            if (coord)
                coord->treeRender(dataptr);
            if (displacers)
                for (i = 0; i < displacers_length; i++)
                    if (displacers[i])
                        displacers[i]->treeRender(dataptr);
            render(dataptr);
        }
    }
    virtual void render(void *dataptr) {
        if (renderCallback)
            renderCallback(this, dataptr);
    }
    virtual void treeDoWithData(void *dataptr) {
        int i;
        if (treeDoWithDataCallback) {
            treeDoWithDataCallback(this, dataptr);
            return;
        }
        if (m_protoRoot != NULL)
            m_protoRoot->treeDoWithData(dataptr);
        else {
            if (metadata)
                metadata->treeDoWithData(dataptr);
            if (children)
                for (i = 0; i < children_length; i++)
                    if (children[i])
                        children[i]->treeDoWithData(dataptr);
            if (coord)
                coord->treeDoWithData(dataptr);
            if (displacers)
                for (i = 0; i < displacers_length; i++)
                    if (displacers[i])
                        displacers[i]->treeDoWithData(dataptr);
            doWithData(dataptr);
        }
    }
    virtual void doWithData(void *dataptr) {
        if (doWithDataCallback)
            doWithDataCallback(this, dataptr);
    }
};

X3dCallback X3dHAnimSegment::renderCallback = NULL;
X3dCallback X3dHAnimSegment::treeRenderCallback = NULL;
X3dCallback X3dHAnimSegment::doWithDataCallback = NULL;
X3dCallback X3dHAnimSegment::treeDoWithDataCallback = NULL;
X3dProcessEventCallback X3dHAnimSegment::processEventCallback = NULL;

int X3dHAnimSegmentType = 108;



class X3dKambiAppearance : public X3dNode {
public:
    X3dNode* metadata;
    X3dNode* material;
    X3dNode* texture;
    X3dNode* textureTransform;
    X3dNode* fillProperties;
    X3dNode* lineProperties;
    X3dNode** shaders;
    int shaders_length;
    X3dNode** receiveShadows;
    int receiveShadows_length;
    bool shadowCaster;
    X3dNode* normalMap;
    X3dNode* heightMap;
    float heightMapScale;
    X3dNode** effects;
    int effects_length;
    void* extra_data;

    int getType() const { return 127; }

    static X3dCallback renderCallback;
    static X3dCallback treeRenderCallback;
    static X3dCallback doWithDataCallback;
    static X3dCallback treeDoWithDataCallback;
    static X3dProcessEventCallback processEventCallback;

    X3dKambiAppearance() {
        metadata = NULL;
        material = NULL;
        texture = NULL;
        textureTransform = NULL;
        fillProperties = NULL;
        lineProperties = NULL;
        shaders = NULL;
        shaders_length = 0;
        receiveShadows = NULL;
        receiveShadows_length = 0;
        shadowCaster = false;
        normalMap = NULL;
        heightMap = NULL;
        heightMapScale = 0.0f;
        effects = NULL;
        effects_length = 0;
        extra_data = NULL;
    }
    virtual void treeRender(void *dataptr) {
        int i;
        if (treeRenderCallback) {
            treeRenderCallback(this, dataptr);
            return;
        }
        if (m_protoRoot != NULL)
            m_protoRoot->treeRender(dataptr);
        else {
            if (metadata)
                metadata->treeRender(dataptr);
            if (material)
                material->treeRender(dataptr);
            if (texture)
                texture->treeRender(dataptr);
            if (textureTransform)
                textureTransform->treeRender(dataptr);
            if (fillProperties)
                fillProperties->treeRender(dataptr);
            if (lineProperties)
                lineProperties->treeRender(dataptr);
            if (shaders)
                for (i = 0; i < shaders_length; i++)
                    if (shaders[i])
                        shaders[i]->treeRender(dataptr);
            if (receiveShadows)
                for (i = 0; i < receiveShadows_length; i++)
                    if (receiveShadows[i])
                        receiveShadows[i]->treeRender(dataptr);
            if (normalMap)
                normalMap->treeRender(dataptr);
            if (heightMap)
                heightMap->treeRender(dataptr);
            if (effects)
                for (i = 0; i < effects_length; i++)
                    if (effects[i])
                        effects[i]->treeRender(dataptr);
            render(dataptr);
        }
    }
    virtual void render(void *dataptr) {
        if (renderCallback)
            renderCallback(this, dataptr);
    }
    virtual void treeDoWithData(void *dataptr) {
        int i;
        if (treeDoWithDataCallback) {
            treeDoWithDataCallback(this, dataptr);
            return;
        }
        if (m_protoRoot != NULL)
            m_protoRoot->treeDoWithData(dataptr);
        else {
            if (metadata)
                metadata->treeDoWithData(dataptr);
            if (material)
                material->treeDoWithData(dataptr);
            if (texture)
                texture->treeDoWithData(dataptr);
            if (textureTransform)
                textureTransform->treeDoWithData(dataptr);
            if (fillProperties)
                fillProperties->treeDoWithData(dataptr);
            if (lineProperties)
                lineProperties->treeDoWithData(dataptr);
            if (shaders)
                for (i = 0; i < shaders_length; i++)
                    if (shaders[i])
                        shaders[i]->treeDoWithData(dataptr);
            if (receiveShadows)
                for (i = 0; i < receiveShadows_length; i++)
                    if (receiveShadows[i])
                        receiveShadows[i]->treeDoWithData(dataptr);
            if (normalMap)
                normalMap->treeDoWithData(dataptr);
            if (heightMap)
                heightMap->treeDoWithData(dataptr);
            if (effects)
                for (i = 0; i < effects_length; i++)
                    if (effects[i])
                        effects[i]->treeDoWithData(dataptr);
            doWithData(dataptr);
        }
    }
    virtual void doWithData(void *dataptr) {
        if (doWithDataCallback)
            doWithDataCallback(this, dataptr);
    }
};

X3dCallback X3dKambiAppearance::renderCallback = NULL;
X3dCallback X3dKambiAppearance::treeRenderCallback = NULL;
X3dCallback X3dKambiAppearance::doWithDataCallback = NULL;
X3dCallback X3dKambiAppearance::treeDoWithDataCallback = NULL;
X3dProcessEventCallback X3dKambiAppearance::processEventCallback = NULL;

int X3dKambiAppearanceType = 127;



class X3dTextureCoordinate : public X3dNode {
public:
    X3dNode* metadata;
    float* point;
    int point_length;
    void* extra_data;

    int getType() const { return 276; }

    static X3dCallback renderCallback;
    static X3dCallback treeRenderCallback;
    static X3dCallback doWithDataCallback;
    static X3dCallback treeDoWithDataCallback;
    static X3dProcessEventCallback processEventCallback;

    X3dTextureCoordinate() {
        metadata = NULL;
        point = NULL;
        point_length = 0;
        extra_data = NULL;
    }
    virtual void treeRender(void *dataptr) {
        int i;
        if (treeRenderCallback) {
            treeRenderCallback(this, dataptr);
            return;
        }
        if (m_protoRoot != NULL)
            m_protoRoot->treeRender(dataptr);
        else {
            if (metadata)
                metadata->treeRender(dataptr);
            render(dataptr);
        }
    }
    virtual void render(void *dataptr) {
        if (renderCallback)
            renderCallback(this, dataptr);
    }
    virtual void treeDoWithData(void *dataptr) {
        int i;
        if (treeDoWithDataCallback) {
            treeDoWithDataCallback(this, dataptr);
            return;
        }
        if (m_protoRoot != NULL)
            m_protoRoot->treeDoWithData(dataptr);
        else {
            if (metadata)
                metadata->treeDoWithData(dataptr);
            doWithData(dataptr);
        }
    }
    virtual void doWithData(void *dataptr) {
        if (doWithDataCallback)
            doWithDataCallback(this, dataptr);
    }
};

X3dCallback X3dTextureCoordinate::renderCallback = NULL;
X3dCallback X3dTextureCoordinate::treeRenderCallback = NULL;
X3dCallback X3dTextureCoordinate::doWithDataCallback = NULL;
X3dCallback X3dTextureCoordinate::treeDoWithDataCallback = NULL;
X3dProcessEventCallback X3dTextureCoordinate::processEventCallback = NULL;

int X3dTextureCoordinateType = 276;



class X3dNormal : public X3dNode {
public:
    X3dNode* metadata;
    float* vector;
    int vector_length;
    void* extra_data;

    int getType() const { return 167; }

    static X3dCallback renderCallback;
    static X3dCallback treeRenderCallback;
    static X3dCallback doWithDataCallback;
    static X3dCallback treeDoWithDataCallback;
    static X3dProcessEventCallback processEventCallback;

    X3dNormal() {
        metadata = NULL;
        vector = NULL;
        vector_length = 0;
        extra_data = NULL;
    }
    virtual void treeRender(void *dataptr) {
        int i;
        if (treeRenderCallback) {
            treeRenderCallback(this, dataptr);
            return;
        }
        if (m_protoRoot != NULL)
            m_protoRoot->treeRender(dataptr);
        else {
            if (metadata)
                metadata->treeRender(dataptr);
            render(dataptr);
        }
    }
    virtual void render(void *dataptr) {
        if (renderCallback)
            renderCallback(this, dataptr);
    }
    virtual void treeDoWithData(void *dataptr) {
        int i;
        if (treeDoWithDataCallback) {
            treeDoWithDataCallback(this, dataptr);
            return;
        }
        if (m_protoRoot != NULL)
            m_protoRoot->treeDoWithData(dataptr);
        else {
            if (metadata)
                metadata->treeDoWithData(dataptr);
            doWithData(dataptr);
        }
    }
    virtual void doWithData(void *dataptr) {
        if (doWithDataCallback)
            doWithDataCallback(this, dataptr);
    }
};

X3dCallback X3dNormal::renderCallback = NULL;
X3dCallback X3dNormal::treeRenderCallback = NULL;
X3dCallback X3dNormal::doWithDataCallback = NULL;
X3dCallback X3dNormal::treeDoWithDataCallback = NULL;
X3dProcessEventCallback X3dNormal::processEventCallback = NULL;

int X3dNormalType = 167;



class X3dKambiNavigationInfo : public X3dNode {
public:
    bool set_bind;
    double bindTime;
    bool isBound;
    bool transitionComplete;
    X3dNode* metadata;
    float* avatarSize;
    int avatarSize_length;
    bool headlight;
    float speed;
    double transitionTime;
    const char** transitionType;
    int transitionType_length;
    const char** type;
    int type_length;
    float visibilityLimit;
    const char* blendingSort;
    bool timeOriginAtLoad;
    X3dNode* octreeRendering;
    X3dNode* octreeDynamicCollisions;
    X3dNode* octreeVisibleTriangles;
    X3dNode* octreeCollidableTriangles;
    float headBobbing;
    float headBobbingDistance;
    float headBobbingTime;
    X3dNode* headlightNode;
    void* extra_data;

    int getType() const { return 130; }

    static X3dCallback renderCallback;
    static X3dCallback treeRenderCallback;
    static X3dCallback doWithDataCallback;
    static X3dCallback treeDoWithDataCallback;
    static X3dProcessEventCallback processEventCallback;

    X3dKambiNavigationInfo() {
        metadata = NULL;
        avatarSize = NULL;
        avatarSize_length = 0;
        headlight = false;
        speed = 0.0f;
        transitionTime = 0;
        transitionType = NULL;
        transitionType_length = 0;
        type = NULL;
        type_length = 0;
        visibilityLimit = 0.0f;
        blendingSort = NULL;
        timeOriginAtLoad = false;
        octreeRendering = NULL;
        octreeDynamicCollisions = NULL;
        octreeVisibleTriangles = NULL;
        octreeCollidableTriangles = NULL;
        headBobbing = 0.0f;
        headBobbingDistance = 0.0f;
        headBobbingTime = 0.0f;
        headlightNode = NULL;
        extra_data = NULL;
    }
    virtual void treeRender(void *dataptr) {
        int i;
        if (treeRenderCallback) {
            treeRenderCallback(this, dataptr);
            return;
        }
        if (m_protoRoot != NULL)
            m_protoRoot->treeRender(dataptr);
        else {
            if (metadata)
                metadata->treeRender(dataptr);
            if (octreeRendering)
                octreeRendering->treeRender(dataptr);
            if (octreeDynamicCollisions)
                octreeDynamicCollisions->treeRender(dataptr);
            if (octreeVisibleTriangles)
                octreeVisibleTriangles->treeRender(dataptr);
            if (octreeCollidableTriangles)
                octreeCollidableTriangles->treeRender(dataptr);
            if (headlightNode)
                headlightNode->treeRender(dataptr);
            render(dataptr);
        }
    }
    virtual void render(void *dataptr) {
        if (renderCallback)
            renderCallback(this, dataptr);
    }
    virtual void treeDoWithData(void *dataptr) {
        int i;
        if (treeDoWithDataCallback) {
            treeDoWithDataCallback(this, dataptr);
            return;
        }
        if (m_protoRoot != NULL)
            m_protoRoot->treeDoWithData(dataptr);
        else {
            if (metadata)
                metadata->treeDoWithData(dataptr);
            if (octreeRendering)
                octreeRendering->treeDoWithData(dataptr);
            if (octreeDynamicCollisions)
                octreeDynamicCollisions->treeDoWithData(dataptr);
            if (octreeVisibleTriangles)
                octreeVisibleTriangles->treeDoWithData(dataptr);
            if (octreeCollidableTriangles)
                octreeCollidableTriangles->treeDoWithData(dataptr);
            if (headlightNode)
                headlightNode->treeDoWithData(dataptr);
            doWithData(dataptr);
        }
    }
    virtual void doWithData(void *dataptr) {
        if (doWithDataCallback)
            doWithDataCallback(this, dataptr);
    }
};

X3dCallback X3dKambiNavigationInfo::renderCallback = NULL;
X3dCallback X3dKambiNavigationInfo::treeRenderCallback = NULL;
X3dCallback X3dKambiNavigationInfo::doWithDataCallback = NULL;
X3dCallback X3dKambiNavigationInfo::treeDoWithDataCallback = NULL;
X3dProcessEventCallback X3dKambiNavigationInfo::processEventCallback = NULL;

int X3dKambiNavigationInfoType = 130;



class X3dSpotLight : public X3dNode {
public:
    X3dNode* metadata;
    float ambientIntensity;
    float* attenuation;
    int attenuation_length;
    float beamWidth;
    float* color;
    int color_length;
    float cutOffAngle;
    float* direction;
    int direction_length;
    bool global;
    float intensity;
    float* location;
    int location_length;
    bool on;
    float radius;
    float projectionAngle;
    bool shadows;
    bool kambiShadows;
    bool kambiShadowsMain;
    float projectionNear;
    float projectionFar;
    float* up;
    int up_length;
    X3dNode* defaultShadowMap;
    X3dNode** effects;
    int effects_length;
    bool shadowVolumes;
    bool shadowVolumesMain;
    void* extra_data;

    int getType() const { return 257; }

    static X3dCallback renderCallback;
    static X3dCallback treeRenderCallback;
    static X3dCallback doWithDataCallback;
    static X3dCallback treeDoWithDataCallback;
    static X3dProcessEventCallback processEventCallback;

    X3dSpotLight() {
        metadata = NULL;
        ambientIntensity = 0.0f;
        attenuation = NULL;
        attenuation_length = 0;
        beamWidth = 0.0f;
        color = NULL;
        color_length = 0;
        cutOffAngle = 0.0f;
        direction = NULL;
        direction_length = 0;
        global = false;
        intensity = 0.0f;
        location = NULL;
        location_length = 0;
        on = false;
        radius = 0.0f;
        projectionAngle = 0.0f;
        shadows = false;
        kambiShadows = false;
        kambiShadowsMain = false;
        projectionNear = 0.0f;
        projectionFar = 0.0f;
        up = NULL;
        up_length = 0;
        defaultShadowMap = NULL;
        effects = NULL;
        effects_length = 0;
        shadowVolumes = false;
        shadowVolumesMain = false;
        extra_data = NULL;
    }
    virtual void treeRender(void *dataptr) {
        int i;
        if (treeRenderCallback) {
            treeRenderCallback(this, dataptr);
            return;
        }
        if (m_protoRoot != NULL)
            m_protoRoot->treeRender(dataptr);
        else {
            if (metadata)
                metadata->treeRender(dataptr);
            if (defaultShadowMap)
                defaultShadowMap->treeRender(dataptr);
            if (effects)
                for (i = 0; i < effects_length; i++)
                    if (effects[i])
                        effects[i]->treeRender(dataptr);
            render(dataptr);
        }
    }
    virtual void render(void *dataptr) {
        if (renderCallback)
            renderCallback(this, dataptr);
    }
    virtual void treeDoWithData(void *dataptr) {
        int i;
        if (treeDoWithDataCallback) {
            treeDoWithDataCallback(this, dataptr);
            return;
        }
        if (m_protoRoot != NULL)
            m_protoRoot->treeDoWithData(dataptr);
        else {
            if (metadata)
                metadata->treeDoWithData(dataptr);
            if (defaultShadowMap)
                defaultShadowMap->treeDoWithData(dataptr);
            if (effects)
                for (i = 0; i < effects_length; i++)
                    if (effects[i])
                        effects[i]->treeDoWithData(dataptr);
            doWithData(dataptr);
        }
    }
    virtual void doWithData(void *dataptr) {
        if (doWithDataCallback)
            doWithDataCallback(this, dataptr);
    }
};

X3dCallback X3dSpotLight::renderCallback = NULL;
X3dCallback X3dSpotLight::treeRenderCallback = NULL;
X3dCallback X3dSpotLight::doWithDataCallback = NULL;
X3dCallback X3dSpotLight::treeDoWithDataCallback = NULL;
X3dProcessEventCallback X3dSpotLight::processEventCallback = NULL;

int X3dSpotLightType = 257;



class X3dColorInterpolator : public X3dNode {
public:
    float set_fraction;
    float* value_changed;
    int value_changed_length;
    X3dNode* metadata;
    float* key;
    int key_length;
    float* keyValue;
    int keyValue_length;
    void* extra_data;

    int getType() const { return 38; }

    static X3dCallback renderCallback;
    static X3dCallback treeRenderCallback;
    static X3dCallback doWithDataCallback;
    static X3dCallback treeDoWithDataCallback;
    static X3dProcessEventCallback processEventCallback;

    X3dColorInterpolator() {
        metadata = NULL;
        key = NULL;
        key_length = 0;
        keyValue = NULL;
        keyValue_length = 0;
        extra_data = NULL;
    }
    virtual void treeRender(void *dataptr) {
        int i;
        if (treeRenderCallback) {
            treeRenderCallback(this, dataptr);
            return;
        }
        if (m_protoRoot != NULL)
            m_protoRoot->treeRender(dataptr);
        else {
            if (metadata)
                metadata->treeRender(dataptr);
            render(dataptr);
        }
    }
    virtual void render(void *dataptr) {
        if (renderCallback)
            renderCallback(this, dataptr);
    }
    virtual void treeDoWithData(void *dataptr) {
        int i;
        if (treeDoWithDataCallback) {
            treeDoWithDataCallback(this, dataptr);
            return;
        }
        if (m_protoRoot != NULL)
            m_protoRoot->treeDoWithData(dataptr);
        else {
            if (metadata)
                metadata->treeDoWithData(dataptr);
            doWithData(dataptr);
        }
    }
    virtual void doWithData(void *dataptr) {
        if (doWithDataCallback)
            doWithDataCallback(this, dataptr);
    }
};

X3dCallback X3dColorInterpolator::renderCallback = NULL;
X3dCallback X3dColorInterpolator::treeRenderCallback = NULL;
X3dCallback X3dColorInterpolator::doWithDataCallback = NULL;
X3dCallback X3dColorInterpolator::treeDoWithDataCallback = NULL;
X3dProcessEventCallback X3dColorInterpolator::processEventCallback = NULL;

int X3dColorInterpolatorType = 38;



class X3dExplosionEmitter : public X3dNode {
public:
    X3dNode* metadata;
    float speed;
    float variation;
    float mass;
    float surfaceArea;
    float* position;
    int position_length;
    void* extra_data;

    int getType() const { return 81; }

    static X3dCallback renderCallback;
    static X3dCallback treeRenderCallback;
    static X3dCallback doWithDataCallback;
    static X3dCallback treeDoWithDataCallback;
    static X3dProcessEventCallback processEventCallback;

    X3dExplosionEmitter() {
        metadata = NULL;
        speed = 0.0f;
        variation = 0.0f;
        mass = 0.0f;
        surfaceArea = 0.0f;
        position = NULL;
        position_length = 0;
        extra_data = NULL;
    }
    virtual void treeRender(void *dataptr) {
        int i;
        if (treeRenderCallback) {
            treeRenderCallback(this, dataptr);
            return;
        }
        if (m_protoRoot != NULL)
            m_protoRoot->treeRender(dataptr);
        else {
            if (metadata)
                metadata->treeRender(dataptr);
            render(dataptr);
        }
    }
    virtual void render(void *dataptr) {
        if (renderCallback)
            renderCallback(this, dataptr);
    }
    virtual void treeDoWithData(void *dataptr) {
        int i;
        if (treeDoWithDataCallback) {
            treeDoWithDataCallback(this, dataptr);
            return;
        }
        if (m_protoRoot != NULL)
            m_protoRoot->treeDoWithData(dataptr);
        else {
            if (metadata)
                metadata->treeDoWithData(dataptr);
            doWithData(dataptr);
        }
    }
    virtual void doWithData(void *dataptr) {
        if (doWithDataCallback)
            doWithDataCallback(this, dataptr);
    }
};

X3dCallback X3dExplosionEmitter::renderCallback = NULL;
X3dCallback X3dExplosionEmitter::treeRenderCallback = NULL;
X3dCallback X3dExplosionEmitter::doWithDataCallback = NULL;
X3dCallback X3dExplosionEmitter::treeDoWithDataCallback = NULL;
X3dProcessEventCallback X3dExplosionEmitter::processEventCallback = NULL;

int X3dExplosionEmitterType = 81;



class X3dLineSet : public X3dNode {
public:
    X3dNode* metadata;
    X3dNode** attrib;
    int attrib_length;
    X3dNode* color;
    X3dNode* coord;
    X3dNode* fogCoord;
    int* vertexCount;
    int vertexCount_length;
    void* extra_data;
    int glName_number;

    int getType() const { return 143; }

    void setGlName(int number){ glName_number = number; }

    static X3dCallback renderCallback;
    static X3dCallback treeRenderCallback;
    static X3dCallback doWithDataCallback;
    static X3dCallback treeDoWithDataCallback;
    static X3dProcessEventCallback processEventCallback;

    X3dLineSet() {
        metadata = NULL;
        attrib = NULL;
        attrib_length = 0;
        color = NULL;
        coord = NULL;
        fogCoord = NULL;
        vertexCount = NULL;
        vertexCount_length = 0;
        extra_data = NULL;
    }
    virtual void treeRender(void *dataptr) {
        int i;
        if (treeRenderCallback) {
            treeRenderCallback(this, dataptr);
            return;
        }
        if (m_protoRoot != NULL)
            m_protoRoot->treeRender(dataptr);
        else {
            if (metadata)
                metadata->treeRender(dataptr);
            if (attrib)
                for (i = 0; i < attrib_length; i++)
                    if (attrib[i])
                        attrib[i]->treeRender(dataptr);
            if (color)
                color->treeRender(dataptr);
            if (coord)
                coord->treeRender(dataptr);
            if (fogCoord)
                fogCoord->treeRender(dataptr);
            render(dataptr);
        }
    }
    virtual void render(void *dataptr) {
        if (renderCallback)
            renderCallback(this, dataptr);
    }
    virtual void treeDoWithData(void *dataptr) {
        int i;
        if (treeDoWithDataCallback) {
            treeDoWithDataCallback(this, dataptr);
            return;
        }
        if (m_protoRoot != NULL)
            m_protoRoot->treeDoWithData(dataptr);
        else {
            if (metadata)
                metadata->treeDoWithData(dataptr);
            if (attrib)
                for (i = 0; i < attrib_length; i++)
                    if (attrib[i])
                        attrib[i]->treeDoWithData(dataptr);
            if (color)
                color->treeDoWithData(dataptr);
            if (coord)
                coord->treeDoWithData(dataptr);
            if (fogCoord)
                fogCoord->treeDoWithData(dataptr);
            doWithData(dataptr);
        }
    }
    virtual void doWithData(void *dataptr) {
        if (doWithDataCallback)
            doWithDataCallback(this, dataptr);
    }
};

X3dCallback X3dLineSet::renderCallback = NULL;
X3dCallback X3dLineSet::treeRenderCallback = NULL;
X3dCallback X3dLineSet::doWithDataCallback = NULL;
X3dCallback X3dLineSet::treeDoWithDataCallback = NULL;
X3dProcessEventCallback X3dLineSet::processEventCallback = NULL;

int X3dLineSetType = 143;



class X3dPixelTexture : public X3dNode {
public:
    X3dNode* metadata;
    int* image;
    int image_length;
    bool repeatS;
    bool repeatT;
    X3dNode* textureProperties;
    X3dNode** effects;
    int effects_length;
    const char* alphaChannel;
    void* extra_data;

    int getType() const { return 193; }

    static X3dCallback renderCallback;
    static X3dCallback treeRenderCallback;
    static X3dCallback doWithDataCallback;
    static X3dCallback treeDoWithDataCallback;
    static X3dProcessEventCallback processEventCallback;

    X3dPixelTexture() {
        metadata = NULL;
        image = NULL;
        image_length = 0;
        repeatS = false;
        repeatT = false;
        textureProperties = NULL;
        effects = NULL;
        effects_length = 0;
        alphaChannel = NULL;
        extra_data = NULL;
    }
    virtual void treeRender(void *dataptr) {
        int i;
        if (treeRenderCallback) {
            treeRenderCallback(this, dataptr);
            return;
        }
        if (m_protoRoot != NULL)
            m_protoRoot->treeRender(dataptr);
        else {
            if (metadata)
                metadata->treeRender(dataptr);
            if (textureProperties)
                textureProperties->treeRender(dataptr);
            if (effects)
                for (i = 0; i < effects_length; i++)
                    if (effects[i])
                        effects[i]->treeRender(dataptr);
            render(dataptr);
        }
    }
    virtual void render(void *dataptr) {
        if (renderCallback)
            renderCallback(this, dataptr);
    }
    virtual void treeDoWithData(void *dataptr) {
        int i;
        if (treeDoWithDataCallback) {
            treeDoWithDataCallback(this, dataptr);
            return;
        }
        if (m_protoRoot != NULL)
            m_protoRoot->treeDoWithData(dataptr);
        else {
            if (metadata)
                metadata->treeDoWithData(dataptr);
            if (textureProperties)
                textureProperties->treeDoWithData(dataptr);
            if (effects)
                for (i = 0; i < effects_length; i++)
                    if (effects[i])
                        effects[i]->treeDoWithData(dataptr);
            doWithData(dataptr);
        }
    }
    virtual void doWithData(void *dataptr) {
        if (doWithDataCallback)
            doWithDataCallback(this, dataptr);
    }
};

X3dCallback X3dPixelTexture::renderCallback = NULL;
X3dCallback X3dPixelTexture::treeRenderCallback = NULL;
X3dCallback X3dPixelTexture::doWithDataCallback = NULL;
X3dCallback X3dPixelTexture::treeDoWithDataCallback = NULL;
X3dProcessEventCallback X3dPixelTexture::processEventCallback = NULL;

int X3dPixelTextureType = 193;



class X3dSwitch : public X3dNode {
public:
    X3dNode** addChildren;
    int addChildren_length;
    X3dNode** removeChildren;
    int removeChildren_length;
    X3dNode* metadata;
    float* bboxCenter;
    int bboxCenter_length;
    float* bboxSize;
    int bboxSize_length;
    X3dNode** children;
    int children_length;
    int whichChoice;
    void* extra_data;

    int getType() const { return 269; }

    static X3dCallback renderCallback;
    static X3dCallback treeRenderCallback;
    static X3dCallback doWithDataCallback;
    static X3dCallback treeDoWithDataCallback;
    static X3dProcessEventCallback processEventCallback;

    X3dSwitch() {
        metadata = NULL;
        bboxCenter = NULL;
        bboxCenter_length = 0;
        bboxSize = NULL;
        bboxSize_length = 0;
        children = NULL;
        children_length = 0;
        whichChoice = 0;
        extra_data = NULL;
    }
    virtual void treeRender(void *dataptr) {
        int i;
        if (treeRenderCallback) {
            treeRenderCallback(this, dataptr);
            return;
        }
        if (m_protoRoot != NULL)
            m_protoRoot->treeRender(dataptr);
        else {
            if (metadata)
                metadata->treeRender(dataptr);
            if (children)
                for (i = 0; i < children_length; i++)
                    if (children[i])
                        children[i]->treeRender(dataptr);
            render(dataptr);
        }
    }
    virtual void render(void *dataptr) {
        if (renderCallback)
            renderCallback(this, dataptr);
    }
    virtual void treeDoWithData(void *dataptr) {
        int i;
        if (treeDoWithDataCallback) {
            treeDoWithDataCallback(this, dataptr);
            return;
        }
        if (m_protoRoot != NULL)
            m_protoRoot->treeDoWithData(dataptr);
        else {
            if (metadata)
                metadata->treeDoWithData(dataptr);
            if (children)
                for (i = 0; i < children_length; i++)
                    if (children[i])
                        children[i]->treeDoWithData(dataptr);
            doWithData(dataptr);
        }
    }
    virtual void doWithData(void *dataptr) {
        if (doWithDataCallback)
            doWithDataCallback(this, dataptr);
    }
};

X3dCallback X3dSwitch::renderCallback = NULL;
X3dCallback X3dSwitch::treeRenderCallback = NULL;
X3dCallback X3dSwitch::doWithDataCallback = NULL;
X3dCallback X3dSwitch::treeDoWithDataCallback = NULL;
X3dProcessEventCallback X3dSwitch::processEventCallback = NULL;

int X3dSwitchType = 269;



class X3dBlock : public X3dNode {
public:
    X3dNode** addChildren;
    int addChildren_length;
    X3dNode** removeChildren;
    int removeChildren_length;
    X3dNode* metadata;
    X3dNode** children;
    int children_length;
    float* bboxCenter;
    int bboxCenter_length;
    float* bboxSize;
    int bboxSize_length;
    void* extra_data;

    int getType() const { return 10; }

    static X3dCallback renderCallback;
    static X3dCallback treeRenderCallback;
    static X3dCallback doWithDataCallback;
    static X3dCallback treeDoWithDataCallback;
    static X3dProcessEventCallback processEventCallback;

    X3dBlock() {
        metadata = NULL;
        children = NULL;
        children_length = 0;
        bboxCenter = NULL;
        bboxCenter_length = 0;
        bboxSize = NULL;
        bboxSize_length = 0;
        extra_data = NULL;
    }
    virtual void treeRender(void *dataptr) {
        int i;
        if (treeRenderCallback) {
            treeRenderCallback(this, dataptr);
            return;
        }
        if (m_protoRoot != NULL)
            m_protoRoot->treeRender(dataptr);
        else {
            if (metadata)
                metadata->treeRender(dataptr);
            if (children)
                for (i = 0; i < children_length; i++)
                    if (children[i])
                        children[i]->treeRender(dataptr);
            render(dataptr);
        }
    }
    virtual void render(void *dataptr) {
        if (renderCallback)
            renderCallback(this, dataptr);
    }
    virtual void treeDoWithData(void *dataptr) {
        int i;
        if (treeDoWithDataCallback) {
            treeDoWithDataCallback(this, dataptr);
            return;
        }
        if (m_protoRoot != NULL)
            m_protoRoot->treeDoWithData(dataptr);
        else {
            if (metadata)
                metadata->treeDoWithData(dataptr);
            if (children)
                for (i = 0; i < children_length; i++)
                    if (children[i])
                        children[i]->treeDoWithData(dataptr);
            doWithData(dataptr);
        }
    }
    virtual void doWithData(void *dataptr) {
        if (doWithDataCallback)
            doWithDataCallback(this, dataptr);
    }
};

X3dCallback X3dBlock::renderCallback = NULL;
X3dCallback X3dBlock::treeRenderCallback = NULL;
X3dCallback X3dBlock::doWithDataCallback = NULL;
X3dCallback X3dBlock::treeDoWithDataCallback = NULL;
X3dProcessEventCallback X3dBlock::processEventCallback = NULL;

int X3dBlockType = 10;



class X3dViewpoint : public X3dNode {
public:
    bool set_bind;
    double bindTime;
    bool isBound;
    float* cameraMatrix;
    int cameraMatrix_length;
    float* cameraInverseMatrix;
    int cameraInverseMatrix_length;
    float* cameraRotationMatrix;
    int cameraRotationMatrix_length;
    float* cameraRotationInverseMatrix;
    int cameraRotationInverseMatrix_length;
    X3dNode* metadata;
    float* centerOfRotation;
    int centerOfRotation_length;
    const char* description;
    float fieldOfView;
    bool jump;
    float* orientation;
    int orientation_length;
    bool retainUserOffsets;
    float* position;
    int position_length;
    float* direction;
    int direction_length;
    float* up;
    int up_length;
    float* gravityUp;
    int gravityUp_length;
    bool cameraMatrixSendAlsoOnOffscreenRendering;
    void* extra_data;

    int getType() const { return 316; }

    static X3dCallback renderCallback;
    static X3dCallback treeRenderCallback;
    static X3dCallback doWithDataCallback;
    static X3dCallback treeDoWithDataCallback;
    static X3dProcessEventCallback processEventCallback;

    X3dViewpoint() {
        metadata = NULL;
        centerOfRotation = NULL;
        centerOfRotation_length = 0;
        description = NULL;
        fieldOfView = 0.0f;
        jump = false;
        orientation = NULL;
        orientation_length = 0;
        retainUserOffsets = false;
        position = NULL;
        position_length = 0;
        direction = NULL;
        direction_length = 0;
        up = NULL;
        up_length = 0;
        gravityUp = NULL;
        gravityUp_length = 0;
        cameraMatrixSendAlsoOnOffscreenRendering = false;
        extra_data = NULL;
    }
    virtual void treeRender(void *dataptr) {
        int i;
        if (treeRenderCallback) {
            treeRenderCallback(this, dataptr);
            return;
        }
        if (m_protoRoot != NULL)
            m_protoRoot->treeRender(dataptr);
        else {
            if (metadata)
                metadata->treeRender(dataptr);
            render(dataptr);
        }
    }
    virtual void render(void *dataptr) {
        if (renderCallback)
            renderCallback(this, dataptr);
    }
    virtual void treeDoWithData(void *dataptr) {
        int i;
        if (treeDoWithDataCallback) {
            treeDoWithDataCallback(this, dataptr);
            return;
        }
        if (m_protoRoot != NULL)
            m_protoRoot->treeDoWithData(dataptr);
        else {
            if (metadata)
                metadata->treeDoWithData(dataptr);
            doWithData(dataptr);
        }
    }
    virtual void doWithData(void *dataptr) {
        if (doWithDataCallback)
            doWithDataCallback(this, dataptr);
    }
};

X3dCallback X3dViewpoint::renderCallback = NULL;
X3dCallback X3dViewpoint::treeRenderCallback = NULL;
X3dCallback X3dViewpoint::doWithDataCallback = NULL;
X3dCallback X3dViewpoint::treeDoWithDataCallback = NULL;
X3dProcessEventCallback X3dViewpoint::processEventCallback = NULL;

int X3dViewpointType = 316;



class X3dPointSet : public X3dNode {
public:
    X3dNode* metadata;
    X3dNode** attrib;
    int attrib_length;
    X3dNode* color;
    X3dNode* coord;
    X3dNode* fogCoord;
    void* extra_data;
    int glName_number;

    int getType() const { return 200; }

    void setGlName(int number){ glName_number = number; }

    static X3dCallback renderCallback;
    static X3dCallback treeRenderCallback;
    static X3dCallback doWithDataCallback;
    static X3dCallback treeDoWithDataCallback;
    static X3dProcessEventCallback processEventCallback;

    X3dPointSet() {
        metadata = NULL;
        attrib = NULL;
        attrib_length = 0;
        color = NULL;
        coord = NULL;
        fogCoord = NULL;
        extra_data = NULL;
    }
    virtual void treeRender(void *dataptr) {
        int i;
        if (treeRenderCallback) {
            treeRenderCallback(this, dataptr);
            return;
        }
        if (m_protoRoot != NULL)
            m_protoRoot->treeRender(dataptr);
        else {
            if (metadata)
                metadata->treeRender(dataptr);
            if (attrib)
                for (i = 0; i < attrib_length; i++)
                    if (attrib[i])
                        attrib[i]->treeRender(dataptr);
            if (color)
                color->treeRender(dataptr);
            if (coord)
                coord->treeRender(dataptr);
            if (fogCoord)
                fogCoord->treeRender(dataptr);
            render(dataptr);
        }
    }
    virtual void render(void *dataptr) {
        if (renderCallback)
            renderCallback(this, dataptr);
    }
    virtual void treeDoWithData(void *dataptr) {
        int i;
        if (treeDoWithDataCallback) {
            treeDoWithDataCallback(this, dataptr);
            return;
        }
        if (m_protoRoot != NULL)
            m_protoRoot->treeDoWithData(dataptr);
        else {
            if (metadata)
                metadata->treeDoWithData(dataptr);
            if (attrib)
                for (i = 0; i < attrib_length; i++)
                    if (attrib[i])
                        attrib[i]->treeDoWithData(dataptr);
            if (color)
                color->treeDoWithData(dataptr);
            if (coord)
                coord->treeDoWithData(dataptr);
            if (fogCoord)
                fogCoord->treeDoWithData(dataptr);
            doWithData(dataptr);
        }
    }
    virtual void doWithData(void *dataptr) {
        if (doWithDataCallback)
            doWithDataCallback(this, dataptr);
    }
};

X3dCallback X3dPointSet::renderCallback = NULL;
X3dCallback X3dPointSet::treeRenderCallback = NULL;
X3dCallback X3dPointSet::doWithDataCallback = NULL;
X3dCallback X3dPointSet::treeDoWithDataCallback = NULL;
X3dProcessEventCallback X3dPointSet::processEventCallback = NULL;

int X3dPointSetType = 200;



class X3dBoundedPhysicsModel : public X3dNode {
public:
    X3dNode* metadata;
    bool enabled;
    X3dNode* geometry;
    void* extra_data;

    int getType() const { return 18; }

    static X3dCallback renderCallback;
    static X3dCallback treeRenderCallback;
    static X3dCallback doWithDataCallback;
    static X3dCallback treeDoWithDataCallback;
    static X3dProcessEventCallback processEventCallback;

    X3dBoundedPhysicsModel() {
        metadata = NULL;
        enabled = false;
        geometry = NULL;
        extra_data = NULL;
    }
    virtual void treeRender(void *dataptr) {
        int i;
        if (treeRenderCallback) {
            treeRenderCallback(this, dataptr);
            return;
        }
        if (m_protoRoot != NULL)
            m_protoRoot->treeRender(dataptr);
        else {
            if (metadata)
                metadata->treeRender(dataptr);
            if (geometry)
                geometry->treeRender(dataptr);
            render(dataptr);
        }
    }
    virtual void render(void *dataptr) {
        if (renderCallback)
            renderCallback(this, dataptr);
    }
    virtual void treeDoWithData(void *dataptr) {
        int i;
        if (treeDoWithDataCallback) {
            treeDoWithDataCallback(this, dataptr);
            return;
        }
        if (m_protoRoot != NULL)
            m_protoRoot->treeDoWithData(dataptr);
        else {
            if (metadata)
                metadata->treeDoWithData(dataptr);
            if (geometry)
                geometry->treeDoWithData(dataptr);
            doWithData(dataptr);
        }
    }
    virtual void doWithData(void *dataptr) {
        if (doWithDataCallback)
            doWithDataCallback(this, dataptr);
    }
};

X3dCallback X3dBoundedPhysicsModel::renderCallback = NULL;
X3dCallback X3dBoundedPhysicsModel::treeRenderCallback = NULL;
X3dCallback X3dBoundedPhysicsModel::doWithDataCallback = NULL;
X3dCallback X3dBoundedPhysicsModel::treeDoWithDataCallback = NULL;
X3dProcessEventCallback X3dBoundedPhysicsModel::processEventCallback = NULL;

int X3dBoundedPhysicsModelType = 18;



class X3dGroup : public X3dNode {
public:
    X3dNode** addChildren;
    int addChildren_length;
    X3dNode** removeChildren;
    int removeChildren_length;
    X3dNode* metadata;
    X3dNode** children;
    int children_length;
    float* bboxCenter;
    int bboxCenter_length;
    float* bboxSize;
    int bboxSize_length;
    void* extra_data;

    int getType() const { return 104; }

    static X3dCallback renderCallback;
    static X3dCallback treeRenderCallback;
    static X3dCallback doWithDataCallback;
    static X3dCallback treeDoWithDataCallback;
    static X3dProcessEventCallback processEventCallback;

    X3dGroup() {
        metadata = NULL;
        children = NULL;
        children_length = 0;
        bboxCenter = NULL;
        bboxCenter_length = 0;
        bboxSize = NULL;
        bboxSize_length = 0;
        extra_data = NULL;
    }
    virtual void treeRender(void *dataptr) {
        int i;
        if (treeRenderCallback) {
            treeRenderCallback(this, dataptr);
            return;
        }
        if (m_protoRoot != NULL)
            m_protoRoot->treeRender(dataptr);
        else {
            if (metadata)
                metadata->treeRender(dataptr);
            if (children)
                for (i = 0; i < children_length; i++)
                    if (children[i])
                        children[i]->treeRender(dataptr);
            render(dataptr);
        }
    }
    virtual void render(void *dataptr) {
        if (renderCallback)
            renderCallback(this, dataptr);
    }
    virtual void treeDoWithData(void *dataptr) {
        int i;
        if (treeDoWithDataCallback) {
            treeDoWithDataCallback(this, dataptr);
            return;
        }
        if (m_protoRoot != NULL)
            m_protoRoot->treeDoWithData(dataptr);
        else {
            if (metadata)
                metadata->treeDoWithData(dataptr);
            if (children)
                for (i = 0; i < children_length; i++)
                    if (children[i])
                        children[i]->treeDoWithData(dataptr);
            doWithData(dataptr);
        }
    }
    virtual void doWithData(void *dataptr) {
        if (doWithDataCallback)
            doWithDataCallback(this, dataptr);
    }
};

X3dCallback X3dGroup::renderCallback = NULL;
X3dCallback X3dGroup::treeRenderCallback = NULL;
X3dCallback X3dGroup::doWithDataCallback = NULL;
X3dCallback X3dGroup::treeDoWithDataCallback = NULL;
X3dProcessEventCallback X3dGroup::processEventCallback = NULL;

int X3dGroupType = 104;



class X3dPolylineEmitter : public X3dNode {
public:
    X3dNode* metadata;
    float speed;
    float variation;
    float mass;
    float surfaceArea;
    X3dNode* coord;
    float* direction;
    int direction_length;
    int* coordIndex;
    int coordIndex_length;
    void* extra_data;

    int getType() const { return 202; }

    static X3dCallback renderCallback;
    static X3dCallback treeRenderCallback;
    static X3dCallback doWithDataCallback;
    static X3dCallback treeDoWithDataCallback;
    static X3dProcessEventCallback processEventCallback;

    X3dPolylineEmitter() {
        metadata = NULL;
        speed = 0.0f;
        variation = 0.0f;
        mass = 0.0f;
        surfaceArea = 0.0f;
        coord = NULL;
        direction = NULL;
        direction_length = 0;
        coordIndex = NULL;
        coordIndex_length = 0;
        extra_data = NULL;
    }
    virtual void treeRender(void *dataptr) {
        int i;
        if (treeRenderCallback) {
            treeRenderCallback(this, dataptr);
            return;
        }
        if (m_protoRoot != NULL)
            m_protoRoot->treeRender(dataptr);
        else {
            if (metadata)
                metadata->treeRender(dataptr);
            if (coord)
                coord->treeRender(dataptr);
            render(dataptr);
        }
    }
    virtual void render(void *dataptr) {
        if (renderCallback)
            renderCallback(this, dataptr);
    }
    virtual void treeDoWithData(void *dataptr) {
        int i;
        if (treeDoWithDataCallback) {
            treeDoWithDataCallback(this, dataptr);
            return;
        }
        if (m_protoRoot != NULL)
            m_protoRoot->treeDoWithData(dataptr);
        else {
            if (metadata)
                metadata->treeDoWithData(dataptr);
            if (coord)
                coord->treeDoWithData(dataptr);
            doWithData(dataptr);
        }
    }
    virtual void doWithData(void *dataptr) {
        if (doWithDataCallback)
            doWithDataCallback(this, dataptr);
    }
};

X3dCallback X3dPolylineEmitter::renderCallback = NULL;
X3dCallback X3dPolylineEmitter::treeRenderCallback = NULL;
X3dCallback X3dPolylineEmitter::doWithDataCallback = NULL;
X3dCallback X3dPolylineEmitter::treeDoWithDataCallback = NULL;
X3dProcessEventCallback X3dPolylineEmitter::processEventCallback = NULL;

int X3dPolylineEmitterType = 202;



class X3dPositionInterpolator : public X3dNode {
public:
    float set_fraction;
    float* value_changed;
    int value_changed_length;
    X3dNode* metadata;
    float* key;
    int key_length;
    float* keyValue;
    int keyValue_length;
    void* extra_data;

    int getType() const { return 210; }

    static X3dCallback renderCallback;
    static X3dCallback treeRenderCallback;
    static X3dCallback doWithDataCallback;
    static X3dCallback treeDoWithDataCallback;
    static X3dProcessEventCallback processEventCallback;

    X3dPositionInterpolator() {
        metadata = NULL;
        key = NULL;
        key_length = 0;
        keyValue = NULL;
        keyValue_length = 0;
        extra_data = NULL;
    }
    virtual void treeRender(void *dataptr) {
        int i;
        if (treeRenderCallback) {
            treeRenderCallback(this, dataptr);
            return;
        }
        if (m_protoRoot != NULL)
            m_protoRoot->treeRender(dataptr);
        else {
            if (metadata)
                metadata->treeRender(dataptr);
            render(dataptr);
        }
    }
    virtual void render(void *dataptr) {
        if (renderCallback)
            renderCallback(this, dataptr);
    }
    virtual void treeDoWithData(void *dataptr) {
        int i;
        if (treeDoWithDataCallback) {
            treeDoWithDataCallback(this, dataptr);
            return;
        }
        if (m_protoRoot != NULL)
            m_protoRoot->treeDoWithData(dataptr);
        else {
            if (metadata)
                metadata->treeDoWithData(dataptr);
            doWithData(dataptr);
        }
    }
    virtual void doWithData(void *dataptr) {
        if (doWithDataCallback)
            doWithDataCallback(this, dataptr);
    }
};

X3dCallback X3dPositionInterpolator::renderCallback = NULL;
X3dCallback X3dPositionInterpolator::treeRenderCallback = NULL;
X3dCallback X3dPositionInterpolator::doWithDataCallback = NULL;
X3dCallback X3dPositionInterpolator::treeDoWithDataCallback = NULL;
X3dProcessEventCallback X3dPositionInterpolator::processEventCallback = NULL;

int X3dPositionInterpolatorType = 210;



class X3dCoordinate : public X3dNode {
public:
    X3dNode* metadata;
    float* point;
    int point_length;
    void* extra_data;

    int getType() const { return 52; }

    static X3dCallback renderCallback;
    static X3dCallback treeRenderCallback;
    static X3dCallback doWithDataCallback;
    static X3dCallback treeDoWithDataCallback;
    static X3dProcessEventCallback processEventCallback;

    X3dCoordinate() {
        metadata = NULL;
        point = NULL;
        point_length = 0;
        extra_data = NULL;
    }
    virtual void treeRender(void *dataptr) {
        int i;
        if (treeRenderCallback) {
            treeRenderCallback(this, dataptr);
            return;
        }
        if (m_protoRoot != NULL)
            m_protoRoot->treeRender(dataptr);
        else {
            if (metadata)
                metadata->treeRender(dataptr);
            render(dataptr);
        }
    }
    virtual void render(void *dataptr) {
        if (renderCallback)
            renderCallback(this, dataptr);
    }
    virtual void treeDoWithData(void *dataptr) {
        int i;
        if (treeDoWithDataCallback) {
            treeDoWithDataCallback(this, dataptr);
            return;
        }
        if (m_protoRoot != NULL)
            m_protoRoot->treeDoWithData(dataptr);
        else {
            if (metadata)
                metadata->treeDoWithData(dataptr);
            doWithData(dataptr);
        }
    }
    virtual void doWithData(void *dataptr) {
        if (doWithDataCallback)
            doWithDataCallback(this, dataptr);
    }
};

X3dCallback X3dCoordinate::renderCallback = NULL;
X3dCallback X3dCoordinate::treeRenderCallback = NULL;
X3dCallback X3dCoordinate::doWithDataCallback = NULL;
X3dCallback X3dCoordinate::treeDoWithDataCallback = NULL;
X3dProcessEventCallback X3dCoordinate::processEventCallback = NULL;

int X3dCoordinateType = 52;



class X3dForcePhysicsModel : public X3dNode {
public:
    X3dNode* metadata;
    bool enabled;
    float* force;
    int force_length;
    void* extra_data;

    int getType() const { return 90; }

    static X3dCallback renderCallback;
    static X3dCallback treeRenderCallback;
    static X3dCallback doWithDataCallback;
    static X3dCallback treeDoWithDataCallback;
    static X3dProcessEventCallback processEventCallback;

    X3dForcePhysicsModel() {
        metadata = NULL;
        enabled = false;
        force = NULL;
        force_length = 0;
        extra_data = NULL;
    }
    virtual void treeRender(void *dataptr) {
        int i;
        if (treeRenderCallback) {
            treeRenderCallback(this, dataptr);
            return;
        }
        if (m_protoRoot != NULL)
            m_protoRoot->treeRender(dataptr);
        else {
            if (metadata)
                metadata->treeRender(dataptr);
            render(dataptr);
        }
    }
    virtual void render(void *dataptr) {
        if (renderCallback)
            renderCallback(this, dataptr);
    }
    virtual void treeDoWithData(void *dataptr) {
        int i;
        if (treeDoWithDataCallback) {
            treeDoWithDataCallback(this, dataptr);
            return;
        }
        if (m_protoRoot != NULL)
            m_protoRoot->treeDoWithData(dataptr);
        else {
            if (metadata)
                metadata->treeDoWithData(dataptr);
            doWithData(dataptr);
        }
    }
    virtual void doWithData(void *dataptr) {
        if (doWithDataCallback)
            doWithDataCallback(this, dataptr);
    }
};

X3dCallback X3dForcePhysicsModel::renderCallback = NULL;
X3dCallback X3dForcePhysicsModel::treeRenderCallback = NULL;
X3dCallback X3dForcePhysicsModel::doWithDataCallback = NULL;
X3dCallback X3dForcePhysicsModel::treeDoWithDataCallback = NULL;
X3dProcessEventCallback X3dForcePhysicsModel::processEventCallback = NULL;

int X3dForcePhysicsModelType = 90;



class X3dSphereSensor : public X3dNode {
public:
    bool isActive;
    bool isOver;
    float* rotation_changed;
    int rotation_changed_length;
    float* trackPoint_changed;
    int trackPoint_changed_length;
    X3dNode* metadata;
    bool autoOffset;
    const char* description;
    bool enabled;
    float* offset;
    int offset_length;
    void* extra_data;

    int getType() const { return 253; }

    static X3dCallback renderCallback;
    static X3dCallback treeRenderCallback;
    static X3dCallback doWithDataCallback;
    static X3dCallback treeDoWithDataCallback;
    static X3dProcessEventCallback processEventCallback;

    X3dSphereSensor() {
        metadata = NULL;
        autoOffset = false;
        description = NULL;
        enabled = false;
        offset = NULL;
        offset_length = 0;
        extra_data = NULL;
    }
    virtual void treeRender(void *dataptr) {
        int i;
        if (treeRenderCallback) {
            treeRenderCallback(this, dataptr);
            return;
        }
        if (m_protoRoot != NULL)
            m_protoRoot->treeRender(dataptr);
        else {
            if (metadata)
                metadata->treeRender(dataptr);
            render(dataptr);
        }
    }
    virtual void render(void *dataptr) {
        if (renderCallback)
            renderCallback(this, dataptr);
    }
    virtual void treeDoWithData(void *dataptr) {
        int i;
        if (treeDoWithDataCallback) {
            treeDoWithDataCallback(this, dataptr);
            return;
        }
        if (m_protoRoot != NULL)
            m_protoRoot->treeDoWithData(dataptr);
        else {
            if (metadata)
                metadata->treeDoWithData(dataptr);
            doWithData(dataptr);
        }
    }
    virtual void doWithData(void *dataptr) {
        if (doWithDataCallback)
            doWithDataCallback(this, dataptr);
    }
};

X3dCallback X3dSphereSensor::renderCallback = NULL;
X3dCallback X3dSphereSensor::treeRenderCallback = NULL;
X3dCallback X3dSphereSensor::doWithDataCallback = NULL;
X3dCallback X3dSphereSensor::treeDoWithDataCallback = NULL;
X3dProcessEventCallback X3dSphereSensor::processEventCallback = NULL;

int X3dSphereSensorType = 253;



class X3dSurfaceEmitter : public X3dNode {
public:
    X3dNode* metadata;
    float speed;
    float variation;
    float mass;
    float surfaceArea;
    int* coordIndex;
    int coordIndex_length;
    X3dNode* surface;
    void* extra_data;

    int getType() const { return 267; }

    static X3dCallback renderCallback;
    static X3dCallback treeRenderCallback;
    static X3dCallback doWithDataCallback;
    static X3dCallback treeDoWithDataCallback;
    static X3dProcessEventCallback processEventCallback;

    X3dSurfaceEmitter() {
        metadata = NULL;
        speed = 0.0f;
        variation = 0.0f;
        mass = 0.0f;
        surfaceArea = 0.0f;
        coordIndex = NULL;
        coordIndex_length = 0;
        surface = NULL;
        extra_data = NULL;
    }
    virtual void treeRender(void *dataptr) {
        int i;
        if (treeRenderCallback) {
            treeRenderCallback(this, dataptr);
            return;
        }
        if (m_protoRoot != NULL)
            m_protoRoot->treeRender(dataptr);
        else {
            if (metadata)
                metadata->treeRender(dataptr);
            if (surface)
                surface->treeRender(dataptr);
            render(dataptr);
        }
    }
    virtual void render(void *dataptr) {
        if (renderCallback)
            renderCallback(this, dataptr);
    }
    virtual void treeDoWithData(void *dataptr) {
        int i;
        if (treeDoWithDataCallback) {
            treeDoWithDataCallback(this, dataptr);
            return;
        }
        if (m_protoRoot != NULL)
            m_protoRoot->treeDoWithData(dataptr);
        else {
            if (metadata)
                metadata->treeDoWithData(dataptr);
            if (surface)
                surface->treeDoWithData(dataptr);
            doWithData(dataptr);
        }
    }
    virtual void doWithData(void *dataptr) {
        if (doWithDataCallback)
            doWithDataCallback(this, dataptr);
    }
};

X3dCallback X3dSurfaceEmitter::renderCallback = NULL;
X3dCallback X3dSurfaceEmitter::treeRenderCallback = NULL;
X3dCallback X3dSurfaceEmitter::doWithDataCallback = NULL;
X3dCallback X3dSurfaceEmitter::treeDoWithDataCallback = NULL;
X3dProcessEventCallback X3dSurfaceEmitter::processEventCallback = NULL;

int X3dSurfaceEmitterType = 267;



class X3dTouchSensor : public X3dNode {
public:
    float* hitNormal_changed;
    int hitNormal_changed_length;
    float* hitPoint_changed;
    int hitPoint_changed_length;
    float* hitTexCoord_changed;
    int hitTexCoord_changed_length;
    bool isActive;
    bool isOver;
    double touchTime;
    X3dNode* metadata;
    const char* description;
    bool enabled;
    void* extra_data;

    int getType() const { return 288; }

    static X3dCallback renderCallback;
    static X3dCallback treeRenderCallback;
    static X3dCallback doWithDataCallback;
    static X3dCallback treeDoWithDataCallback;
    static X3dProcessEventCallback processEventCallback;

    X3dTouchSensor() {
        metadata = NULL;
        description = NULL;
        enabled = false;
        extra_data = NULL;
    }
    virtual void treeRender(void *dataptr) {
        int i;
        if (treeRenderCallback) {
            treeRenderCallback(this, dataptr);
            return;
        }
        if (m_protoRoot != NULL)
            m_protoRoot->treeRender(dataptr);
        else {
            if (metadata)
                metadata->treeRender(dataptr);
            render(dataptr);
        }
    }
    virtual void render(void *dataptr) {
        if (renderCallback)
            renderCallback(this, dataptr);
    }
    virtual void treeDoWithData(void *dataptr) {
        int i;
        if (treeDoWithDataCallback) {
            treeDoWithDataCallback(this, dataptr);
            return;
        }
        if (m_protoRoot != NULL)
            m_protoRoot->treeDoWithData(dataptr);
        else {
            if (metadata)
                metadata->treeDoWithData(dataptr);
            doWithData(dataptr);
        }
    }
    virtual void doWithData(void *dataptr) {
        if (doWithDataCallback)
            doWithDataCallback(this, dataptr);
    }
};

X3dCallback X3dTouchSensor::renderCallback = NULL;
X3dCallback X3dTouchSensor::treeRenderCallback = NULL;
X3dCallback X3dTouchSensor::doWithDataCallback = NULL;
X3dCallback X3dTouchSensor::treeDoWithDataCallback = NULL;
X3dProcessEventCallback X3dTouchSensor::processEventCallback = NULL;

int X3dTouchSensorType = 288;



class X3dPointLight : public X3dNode {
public:
    X3dNode* metadata;
    float ambientIntensity;
    float* attenuation;
    int attenuation_length;
    float* color;
    int color_length;
    bool global;
    float intensity;
    float* location;
    int location_length;
    bool on;
    float radius;
    bool shadows;
    bool kambiShadows;
    bool kambiShadowsMain;
    float projectionNear;
    float projectionFar;
    float* up;
    int up_length;
    X3dNode* defaultShadowMap;
    X3dNode** effects;
    int effects_length;
    bool shadowVolumes;
    bool shadowVolumesMain;
    void* extra_data;

    int getType() const { return 198; }

    static X3dCallback renderCallback;
    static X3dCallback treeRenderCallback;
    static X3dCallback doWithDataCallback;
    static X3dCallback treeDoWithDataCallback;
    static X3dProcessEventCallback processEventCallback;

    X3dPointLight() {
        metadata = NULL;
        ambientIntensity = 0.0f;
        attenuation = NULL;
        attenuation_length = 0;
        color = NULL;
        color_length = 0;
        global = false;
        intensity = 0.0f;
        location = NULL;
        location_length = 0;
        on = false;
        radius = 0.0f;
        shadows = false;
        kambiShadows = false;
        kambiShadowsMain = false;
        projectionNear = 0.0f;
        projectionFar = 0.0f;
        up = NULL;
        up_length = 0;
        defaultShadowMap = NULL;
        effects = NULL;
        effects_length = 0;
        shadowVolumes = false;
        shadowVolumesMain = false;
        extra_data = NULL;
    }
    virtual void treeRender(void *dataptr) {
        int i;
        if (treeRenderCallback) {
            treeRenderCallback(this, dataptr);
            return;
        }
        if (m_protoRoot != NULL)
            m_protoRoot->treeRender(dataptr);
        else {
            if (metadata)
                metadata->treeRender(dataptr);
            if (defaultShadowMap)
                defaultShadowMap->treeRender(dataptr);
            if (effects)
                for (i = 0; i < effects_length; i++)
                    if (effects[i])
                        effects[i]->treeRender(dataptr);
            render(dataptr);
        }
    }
    virtual void render(void *dataptr) {
        if (renderCallback)
            renderCallback(this, dataptr);
    }
    virtual void treeDoWithData(void *dataptr) {
        int i;
        if (treeDoWithDataCallback) {
            treeDoWithDataCallback(this, dataptr);
            return;
        }
        if (m_protoRoot != NULL)
            m_protoRoot->treeDoWithData(dataptr);
        else {
            if (metadata)
                metadata->treeDoWithData(dataptr);
            if (defaultShadowMap)
                defaultShadowMap->treeDoWithData(dataptr);
            if (effects)
                for (i = 0; i < effects_length; i++)
                    if (effects[i])
                        effects[i]->treeDoWithData(dataptr);
            doWithData(dataptr);
        }
    }
    virtual void doWithData(void *dataptr) {
        if (doWithDataCallback)
            doWithDataCallback(this, dataptr);
    }
};

X3dCallback X3dPointLight::renderCallback = NULL;
X3dCallback X3dPointLight::treeRenderCallback = NULL;
X3dCallback X3dPointLight::doWithDataCallback = NULL;
X3dCallback X3dPointLight::treeDoWithDataCallback = NULL;
X3dProcessEventCallback X3dPointLight::processEventCallback = NULL;

int X3dPointLightType = 198;



class X3dText : public X3dNode {
public:
    float* lineBounds;
    int lineBounds_length;
    float* origin;
    int origin_length;
    float* textBounds;
    int textBounds_length;
    X3dNode* metadata;
    X3dNode* fontStyle;
    float* length;
    int length_length;
    float maxExtent;
    const char** string;
    int string_length;
    bool solid;
    X3dNode* texCoord;
    void* extra_data;

    int getType() const { return 273; }

    static X3dCallback renderCallback;
    static X3dCallback treeRenderCallback;
    static X3dCallback doWithDataCallback;
    static X3dCallback treeDoWithDataCallback;
    static X3dProcessEventCallback processEventCallback;

    X3dText() {
        metadata = NULL;
        fontStyle = NULL;
        length = NULL;
        length_length = 0;
        maxExtent = 0.0f;
        string = NULL;
        string_length = 0;
        solid = false;
        texCoord = NULL;
        extra_data = NULL;
    }
    virtual void treeRender(void *dataptr) {
        int i;
        if (treeRenderCallback) {
            treeRenderCallback(this, dataptr);
            return;
        }
        if (m_protoRoot != NULL)
            m_protoRoot->treeRender(dataptr);
        else {
            if (metadata)
                metadata->treeRender(dataptr);
            if (fontStyle)
                fontStyle->treeRender(dataptr);
            if (texCoord)
                texCoord->treeRender(dataptr);
            render(dataptr);
        }
    }
    virtual void render(void *dataptr) {
        if (renderCallback)
            renderCallback(this, dataptr);
    }
    virtual void treeDoWithData(void *dataptr) {
        int i;
        if (treeDoWithDataCallback) {
            treeDoWithDataCallback(this, dataptr);
            return;
        }
        if (m_protoRoot != NULL)
            m_protoRoot->treeDoWithData(dataptr);
        else {
            if (metadata)
                metadata->treeDoWithData(dataptr);
            if (fontStyle)
                fontStyle->treeDoWithData(dataptr);
            if (texCoord)
                texCoord->treeDoWithData(dataptr);
            doWithData(dataptr);
        }
    }
    virtual void doWithData(void *dataptr) {
        if (doWithDataCallback)
            doWithDataCallback(this, dataptr);
    }
};

X3dCallback X3dText::renderCallback = NULL;
X3dCallback X3dText::treeRenderCallback = NULL;
X3dCallback X3dText::doWithDataCallback = NULL;
X3dCallback X3dText::treeDoWithDataCallback = NULL;
X3dProcessEventCallback X3dText::processEventCallback = NULL;

int X3dTextType = 273;



class X3dAppearance : public X3dNode {
public:
    X3dNode* metadata;
    X3dNode* material;
    X3dNode* texture;
    X3dNode* textureTransform;
    X3dNode* fillProperties;
    X3dNode* lineProperties;
    X3dNode** shaders;
    int shaders_length;
    X3dNode** receiveShadows;
    int receiveShadows_length;
    bool shadowCaster;
    X3dNode* normalMap;
    X3dNode* heightMap;
    float heightMapScale;
    X3dNode** effects;
    int effects_length;
    void* extra_data;

    int getType() const { return 1; }

    static X3dCallback renderCallback;
    static X3dCallback treeRenderCallback;
    static X3dCallback doWithDataCallback;
    static X3dCallback treeDoWithDataCallback;
    static X3dProcessEventCallback processEventCallback;

    X3dAppearance() {
        metadata = NULL;
        material = NULL;
        texture = NULL;
        textureTransform = NULL;
        fillProperties = NULL;
        lineProperties = NULL;
        shaders = NULL;
        shaders_length = 0;
        receiveShadows = NULL;
        receiveShadows_length = 0;
        shadowCaster = false;
        normalMap = NULL;
        heightMap = NULL;
        heightMapScale = 0.0f;
        effects = NULL;
        effects_length = 0;
        extra_data = NULL;
    }
    virtual void treeRender(void *dataptr) {
        int i;
        if (treeRenderCallback) {
            treeRenderCallback(this, dataptr);
            return;
        }
        if (m_protoRoot != NULL)
            m_protoRoot->treeRender(dataptr);
        else {
            if (metadata)
                metadata->treeRender(dataptr);
            if (material)
                material->treeRender(dataptr);
            if (texture)
                texture->treeRender(dataptr);
            if (textureTransform)
                textureTransform->treeRender(dataptr);
            if (fillProperties)
                fillProperties->treeRender(dataptr);
            if (lineProperties)
                lineProperties->treeRender(dataptr);
            if (shaders)
                for (i = 0; i < shaders_length; i++)
                    if (shaders[i])
                        shaders[i]->treeRender(dataptr);
            if (receiveShadows)
                for (i = 0; i < receiveShadows_length; i++)
                    if (receiveShadows[i])
                        receiveShadows[i]->treeRender(dataptr);
            if (normalMap)
                normalMap->treeRender(dataptr);
            if (heightMap)
                heightMap->treeRender(dataptr);
            if (effects)
                for (i = 0; i < effects_length; i++)
                    if (effects[i])
                        effects[i]->treeRender(dataptr);
            render(dataptr);
        }
    }
    virtual void render(void *dataptr) {
        if (renderCallback)
            renderCallback(this, dataptr);
    }
    virtual void treeDoWithData(void *dataptr) {
        int i;
        if (treeDoWithDataCallback) {
            treeDoWithDataCallback(this, dataptr);
            return;
        }
        if (m_protoRoot != NULL)
            m_protoRoot->treeDoWithData(dataptr);
        else {
            if (metadata)
                metadata->treeDoWithData(dataptr);
            if (material)
                material->treeDoWithData(dataptr);
            if (texture)
                texture->treeDoWithData(dataptr);
            if (textureTransform)
                textureTransform->treeDoWithData(dataptr);
            if (fillProperties)
                fillProperties->treeDoWithData(dataptr);
            if (lineProperties)
                lineProperties->treeDoWithData(dataptr);
            if (shaders)
                for (i = 0; i < shaders_length; i++)
                    if (shaders[i])
                        shaders[i]->treeDoWithData(dataptr);
            if (receiveShadows)
                for (i = 0; i < receiveShadows_length; i++)
                    if (receiveShadows[i])
                        receiveShadows[i]->treeDoWithData(dataptr);
            if (normalMap)
                normalMap->treeDoWithData(dataptr);
            if (heightMap)
                heightMap->treeDoWithData(dataptr);
            if (effects)
                for (i = 0; i < effects_length; i++)
                    if (effects[i])
                        effects[i]->treeDoWithData(dataptr);
            doWithData(dataptr);
        }
    }
    virtual void doWithData(void *dataptr) {
        if (doWithDataCallback)
            doWithDataCallback(this, dataptr);
    }
};

X3dCallback X3dAppearance::renderCallback = NULL;
X3dCallback X3dAppearance::treeRenderCallback = NULL;
X3dCallback X3dAppearance::doWithDataCallback = NULL;
X3dCallback X3dAppearance::treeDoWithDataCallback = NULL;
X3dProcessEventCallback X3dAppearance::processEventCallback = NULL;

int X3dAppearanceType = 1;



class X3dParticleSystem : public X3dNode {
public:
    X3dNode* metadata;
    X3dNode* appearance;
    bool createParticles;
    X3dNode* geometry;
    bool enabled;
    float lifetimeVariation;
    int maxParticles;
    float particleLifetime;
    float* particleSize;
    int particleSize_length;
    float* bboxCenter;
    int bboxCenter_length;
    float* bboxSize;
    int bboxSize_length;
    X3dNode* colorRamp;
    float* colorKey;
    int colorKey_length;
    X3dNode* emitter;
    const char* geometryType;
    X3dNode** physics;
    int physics_length;
    X3dNode* texCoordRamp;
    float* texCoordKey;
    int texCoordKey_length;
    void* extra_data;

    int getType() const { return 191; }

    static X3dCallback renderCallback;
    static X3dCallback treeRenderCallback;
    static X3dCallback doWithDataCallback;
    static X3dCallback treeDoWithDataCallback;
    static X3dProcessEventCallback processEventCallback;

    X3dParticleSystem() {
        metadata = NULL;
        appearance = NULL;
        createParticles = false;
        geometry = NULL;
        enabled = false;
        lifetimeVariation = 0.0f;
        maxParticles = 0;
        particleLifetime = 0.0f;
        particleSize = NULL;
        particleSize_length = 0;
        bboxCenter = NULL;
        bboxCenter_length = 0;
        bboxSize = NULL;
        bboxSize_length = 0;
        colorRamp = NULL;
        colorKey = NULL;
        colorKey_length = 0;
        emitter = NULL;
        geometryType = NULL;
        physics = NULL;
        physics_length = 0;
        texCoordRamp = NULL;
        texCoordKey = NULL;
        texCoordKey_length = 0;
        extra_data = NULL;
    }
    virtual void treeRender(void *dataptr) {
        int i;
        if (treeRenderCallback) {
            treeRenderCallback(this, dataptr);
            return;
        }
        if (m_protoRoot != NULL)
            m_protoRoot->treeRender(dataptr);
        else {
            if (metadata)
                metadata->treeRender(dataptr);
            if (appearance)
                appearance->treeRender(dataptr);
            if (geometry)
                geometry->treeRender(dataptr);
            if (colorRamp)
                colorRamp->treeRender(dataptr);
            if (emitter)
                emitter->treeRender(dataptr);
            if (physics)
                for (i = 0; i < physics_length; i++)
                    if (physics[i])
                        physics[i]->treeRender(dataptr);
            if (texCoordRamp)
                texCoordRamp->treeRender(dataptr);
            render(dataptr);
        }
    }
    virtual void render(void *dataptr) {
        if (renderCallback)
            renderCallback(this, dataptr);
    }
    virtual void treeDoWithData(void *dataptr) {
        int i;
        if (treeDoWithDataCallback) {
            treeDoWithDataCallback(this, dataptr);
            return;
        }
        if (m_protoRoot != NULL)
            m_protoRoot->treeDoWithData(dataptr);
        else {
            if (metadata)
                metadata->treeDoWithData(dataptr);
            if (appearance)
                appearance->treeDoWithData(dataptr);
            if (geometry)
                geometry->treeDoWithData(dataptr);
            if (colorRamp)
                colorRamp->treeDoWithData(dataptr);
            if (emitter)
                emitter->treeDoWithData(dataptr);
            if (physics)
                for (i = 0; i < physics_length; i++)
                    if (physics[i])
                        physics[i]->treeDoWithData(dataptr);
            if (texCoordRamp)
                texCoordRamp->treeDoWithData(dataptr);
            doWithData(dataptr);
        }
    }
    virtual void doWithData(void *dataptr) {
        if (doWithDataCallback)
            doWithDataCallback(this, dataptr);
    }
};

X3dCallback X3dParticleSystem::renderCallback = NULL;
X3dCallback X3dParticleSystem::treeRenderCallback = NULL;
X3dCallback X3dParticleSystem::doWithDataCallback = NULL;
X3dCallback X3dParticleSystem::treeDoWithDataCallback = NULL;
X3dProcessEventCallback X3dParticleSystem::processEventCallback = NULL;

int X3dParticleSystemType = 191;



class X3dTextureTransform : public X3dNode {
public:
    X3dNode* metadata;
    float* center;
    int center_length;
    float rotation;
    float* scale;
    int scale_length;
    float* translation;
    int translation_length;
    void* extra_data;

    int getType() const { return 281; }

    static X3dCallback renderCallback;
    static X3dCallback treeRenderCallback;
    static X3dCallback doWithDataCallback;
    static X3dCallback treeDoWithDataCallback;
    static X3dProcessEventCallback processEventCallback;

    X3dTextureTransform() {
        metadata = NULL;
        center = NULL;
        center_length = 0;
        rotation = 0.0f;
        scale = NULL;
        scale_length = 0;
        translation = NULL;
        translation_length = 0;
        extra_data = NULL;
    }
    virtual void treeRender(void *dataptr) {
        int i;
        if (treeRenderCallback) {
            treeRenderCallback(this, dataptr);
            return;
        }
        if (m_protoRoot != NULL)
            m_protoRoot->treeRender(dataptr);
        else {
            if (metadata)
                metadata->treeRender(dataptr);
            render(dataptr);
        }
    }
    virtual void render(void *dataptr) {
        if (renderCallback)
            renderCallback(this, dataptr);
    }
    virtual void treeDoWithData(void *dataptr) {
        int i;
        if (treeDoWithDataCallback) {
            treeDoWithDataCallback(this, dataptr);
            return;
        }
        if (m_protoRoot != NULL)
            m_protoRoot->treeDoWithData(dataptr);
        else {
            if (metadata)
                metadata->treeDoWithData(dataptr);
            doWithData(dataptr);
        }
    }
    virtual void doWithData(void *dataptr) {
        if (doWithDataCallback)
            doWithDataCallback(this, dataptr);
    }
};

X3dCallback X3dTextureTransform::renderCallback = NULL;
X3dCallback X3dTextureTransform::treeRenderCallback = NULL;
X3dCallback X3dTextureTransform::doWithDataCallback = NULL;
X3dCallback X3dTextureTransform::treeDoWithDataCallback = NULL;
X3dProcessEventCallback X3dTextureTransform::processEventCallback = NULL;

int X3dTextureTransformType = 281;




class X3dSceneGraph {
public:
    X3dGroup root;
    X3dTransform Transform1;
    X3dShape Shape_14;
    X3dAppearance Appearance_15;
    X3dMaterial Material1;
    X3dCoordinateInterpolator CoordinateInterpolator_16;
    X3dNormalInterpolator NormalInterpolator_17;
    X3dIndexedFaceSet NurbsSurface1;
    X3dCoordinate Coordinate1;
    X3dNormal Normal1;
    X3dTextureCoordinate TextureCoordinate1;
    X3dCoordinate Coordinate_12;
    X3dNormal Normal3;
    X3dTextureCoordinate TextureCoordinate_24;
    X3dTimeSensor TimeSensor1;
    X3dCoordinateInterpolator CoordinateInterpolator1;
    X3dColorInterpolator ColorInterpolator1;
    X3dPositionInterpolator PositionInterpolator1;
    X3dTransform Transform_18;
    X3dShape Shape_19;
    X3dAppearance Appearance_20;
    X3dMaterial Material_21;
    X3dIndexedFaceSet Text_13;
    X3dCoordinate Coordinate2;
    X3dNormal Normal2;
    X3dTextureCoordinate TextureCoordinate2;
    X3dCoordinate Coordinate_25;
    X3dNormal Normal_26;
    X3dTextureCoordinate TextureCoordinate_27;
    X3dFontStyle FontStyle_22;
    X3dNavigationInfo NavigationInfo_23;
public:
    X3dSceneGraph();
    void render(void *data) { root.treeRender(data); }
    void doWithData(void *data) { root.treeDoWithData(data); }
    X3dNode *getNodeFromGlName(int glName);
};

X3dSceneGraph::X3dSceneGraph() {
    root.m_parent = (X3dNode *)NULL;
    Transform1.route_sources =  NULL;
    Transform1.num_route_source = 0;
    Transform1.m_parent = (X3dNode *)&root;
    Shape_14.m_parent = (X3dNode *)&Transform1;
    Appearance_15.m_parent = (X3dNode *)&Shape_14;
    Material1.m_parent = (X3dNode *)&Appearance_15;
    Material1.ambientIntensity = 0.200000;
    {
    static float m_diffuseColor[] = { 0.137255, 0.113725, 1 };
    Material1.diffuseColor = m_diffuseColor;
    Material1.diffuseColor_length = sizeof(m_diffuseColor) / sizeof(float);
    }
    {
    static float m_emissiveColor[] = { 0, 0, 0 };
    Material1.emissiveColor = m_emissiveColor;
    Material1.emissiveColor_length = sizeof(m_emissiveColor) / sizeof(float);
    }
    Material1.shininess = 0.200000;
    {
    static float m_specularColor[] = { 0.968627, 0.976471, 1 };
    Material1.specularColor = m_specularColor;
    Material1.specularColor_length = sizeof(m_specularColor) / sizeof(float);
    }
    Material1.transparency = 0;
    Material1.mirror = 0;
    {
    static float m_reflSpecular[1];
    Material1.reflSpecular = NULL;
    Material1.reflSpecular_length = 0;
    }
    {
    static float m_reflDiffuse[1];
    Material1.reflDiffuse = NULL;
    Material1.reflDiffuse_length = 0;
    }
    {
    static float m_transSpecular[1];
    Material1.transSpecular = NULL;
    Material1.transSpecular_length = 0;
    }
    {
    static float m_transDiffuse[1];
    Material1.transDiffuse = NULL;
    Material1.transDiffuse_length = 0;
    }
    Material1.reflSpecularExp = 10e5;
    Material1.transSpecularExp = 10e5;
    Appearance_15.material = &Material1;
    Appearance_15.texture = NULL;
    Appearance_15.textureTransform = NULL;
    {
    static X3dNode* m_receiveShadows[1];
    Appearance_15.receiveShadows = NULL;
    Appearance_15.receiveShadows_length = 0;
    }
    Appearance_15.shadowCaster = true;
    Appearance_15.normalMap = NULL;
    Appearance_15.heightMap = NULL;
    Appearance_15.heightMapScale = 10.000000e-3;
    {
    static X3dNode* m_effects[1];
    Appearance_15.effects = NULL;
    Appearance_15.effects_length = 0;
    }
    CoordinateInterpolator_16.m_parent = (X3dNode *)&Shape_14;
    {
    static float m_key[] = { 0, 1 };
    CoordinateInterpolator_16.key = m_key;
    CoordinateInterpolator_16.key_length = sizeof(m_key) / sizeof(float);
    }
    {
    static float m_keyValue[] = { 0, -1, 0, 0, -1, 0, 0, -1, 0, 0, -1, 0, 0, -1, 0, 0, -1, 0, 0, -1, 0, 0, -1, 0, 0, -1, 0, 0, -1, 0, 0, -1, 0, 0, -1, 0, 0, -1, 0, 0, -1, 0, 0, -1, 0, 0, -1, 0, 0, -1, 0, 0, -1, 0, 0, -1, 0, 0, -1, 0, 0, -1, 0, 0, -1, 0, 0, -1, 0, 0, -1, 0, 0, -1, 0, 0, -1, 0, 0, -1, 0, 0, -1, 0, 0, -1, 0, 0, -1, 0, 0, -1, 0, 0, -1, 0, 0, -0.995685, -0.092796, -0.017442, -0.995685, -0.091142, -0.035262, -0.995685, -0.085836, -0.052311, -0.995685, -0.076647, -0.067347, -0.995685, -0.063840, -0.079303, -0.995685, -0.048189, -0.087525, -0.995685, -0.030831, -0.091880, -0.995685, -0.013006, -0.092698, -0.995685, 0.004271, -0.090174, -0.995685, 0.021902, -0.083901, -0.995685, 0.039645, -0.073762, -0.995685, 0.056305, -0.060154, -0.995685, 0.070658, -0.043961, -0.995685, 0.081723, -0.026371, -0.995685, 0.088970, -0.008611, -0.995685, 0.092396, 0.008611, -0.995685, 0.092396, 0.026371, -0.995685, 0.088970, 0.043961, -0.995685, 0.081723, 0.060154, -0.995685, 0.070658, 0.073762, -0.995685, 0.056305, 0.083901, -0.995685, 0.039645, 0.090174, -0.995685, 0.021903, 0.092698, -0.995685, 0.004272, 0.091880, -0.995685, -0.013006, 0.087525, -0.995685, -0.030831, 0.079303, -0.995685, -0.048189, 0.067347, -0.995685, -0.063840, 0.052311, -0.995685, -0.076647, 0.035262, -0.995685, -0.085835, 0.017442, -0.995685, -0.091142, 0, -0.995685, -0.092796, 0, -0.982177, -0.187956, -0.035328, -0.982177, -0.184607, -0.071422, -0.982177, -0.173858, -0.105954, -0.982177, -0.155246, -0.136409, -0.982177, -0.129307, -0.160626, -0.982177, -0.097607, -0.177279, -0.982177, -0.062447, -0.186101, -0.982177, -0.026343, -0.187757, -0.982177, 0.008652, -0.182646, -0.982177, 0.044363, -0.169940, -0.982177, 0.080300, -0.149404, -0.982177, 0.114045, -0.121841, -0.982177, 0.143117, -0.089042, -0.982177, 0.165527, -0.053415, -0.982177, 0.180207, -0.017442, -0.982177, 0.187145, 0.017442, -0.982177, 0.187145, 0.053415, -0.982177, 0.180207, 0.089042, -0.982177, 0.165527, 0.121841, -0.982177, 0.143117, 0.149404, -0.982177, 0.114045, 0.169940, -0.982177, 0.080301, 0.182646, -0.982177, 0.044363, 0.187757, -0.982177, 0.008652, 0.186101, -0.982177, -0.026343, 0.177280, -0.982177, -0.062447, 0.160626, -0.982177, -0.097606, 0.136409, -0.982177, -0.129306, 0.105954, -0.982177, -0.155246, 0.071422, -0.982177, -0.173858, 0.035328, -0.982177, -0.184606, 0.000001, -0.982177, -0.187956, 0, -0.958769, -0.284186, -0.053415, -0.958769, -0.279121, -0.107989, -0.958769, -0.262869, -0.160200, -0.958769, -0.234729, -0.206247, -0.958769, -0.195509, -0.242862, -0.958769, -0.147579, -0.268043, -0.958769, -0.094419, -0.281381, -0.958769, -0.039831, -0.283885, -0.958769, 0.013081, -0.276157, -0.958769, 0.067076, -0.256945, -0.958769, 0.121412, -0.225895, -0.958769, 0.172433, -0.184221, -0.958769, 0.216390, -0.134630, -0.958769, 0.250273, -0.080762, -0.958769, 0.272469, -0.026371, -0.958769, 0.282960, 0.026371, -0.958769, 0.282960, 0.080762, -0.958769, 0.272469, 0.134629, -0.958769, 0.250273, 0.184221, -0.958769, 0.216390, 0.225895, -0.958769, 0.172433, 0.256945, -0.958769, 0.121413, 0.276157, -0.958769, 0.067076, 0.283885, -0.958769, 0.013082, 0.281381, -0.958769, -0.039830, 0.268043, -0.958769, -0.094418, 0.242863, -0.958769, -0.147579, 0.206248, -0.958769, -0.195509, 0.160201, -0.958769, -0.234729, 0.107989, -0.958769, -0.262869, 0.053415, -0.958769, -0.279121, 0.000001, -0.958769, -0.284186, 0, -0.924990, -0.379992, -0.071422, -0.924990, -0.373220, -0.144394, -0.924990, -0.351489, -0.214207, -0.924990, -0.313862, -0.275778, -0.924990, -0.261420, -0.324737, -0.924990, -0.197332, -0.358407, -0.924990, -0.126249, -0.376242, -0.924990, -0.053258, -0.379590, -0.924990, 0.017491, -0.369256, -0.924990, 0.089688, -0.343568, -0.924990, 0.162344, -0.302050, -0.924990, 0.230564, -0.246326, -0.924990, 0.289340, -0.180017, -0.924990, 0.334646, -0.107989, -0.924990, 0.364325, -0.035262, -0.924990, 0.378353, 0.035262, -0.924990, 0.378353, 0.107988, -0.924990, 0.364325, 0.180016, -0.924990, 0.334646, 0.246326, -0.924990, 0.289340, 0.302050, -0.924990, 0.230565, 0.343568, -0.924990, 0.162344, 0.369256, -0.924990, 0.089689, 0.379590, -0.924990, 0.017492, 0.376242, -0.924990, -0.053258, 0.358407, -0.924990, -0.126249, 0.324738, -0.924990, -0.197331, 0.275779, -0.924990, -0.261419, 0.214208, -0.924990, -0.313862, 0.144395, -0.924990, -0.351489, 0.071423, -0.924990, -0.373220, 0.000001, -0.924990, -0.379992, 0, -0.880666, -0.473738, -0.089042, -0.880666, -0.465294, -0.180017, -0.880666, -0.438202, -0.267053, -0.880666, -0.391293, -0.343814, -0.880666, -0.325913, -0.404851, -0.880666, -0.246014, -0.446827, -0.880666, -0.157395, -0.469061, -0.880666, -0.066397, -0.473235, -0.880666, 0.021806, -0.460353, -0.880666, 0.111815, -0.428327, -0.880666, 0.202394, -0.376567, -0.880666, 0.287445, -0.307096, -0.880666, 0.360721, -0.224427, -0.880666, 0.417205, -0.134630, -0.880666, 0.454205, -0.043961, -0.880666, 0.471693, 0.043961, -0.880666, 0.471693, 0.134629, -0.880666, 0.454205, 0.224427, -0.880666, 0.417205, 0.307095, -0.880666, 0.360721, 0.376566, -0.880666, 0.287446, 0.428327, -0.880666, 0.202395, 0.460353, -0.880666, 0.111815, 0.473235, -0.880666, 0.021807, 0.469061, -0.880666, -0.066397, 0.446827, -0.880666, -0.157395, 0.404852, -0.880666, -0.246013, 0.343814, -0.880666, -0.325912, 0.267054, -0.880666, -0.391292, 0.180018, -0.880666, -0.438202, 0.089043, -0.880666, -0.465294, 0.000001, -0.880666, -0.473738, 0, -0.825969, -0.563715, -0.105954, -0.825969, -0.553668, -0.214207, -0.825969, -0.521430, -0.317775, -0.825969, -0.465611, -0.409115, -0.825969, -0.387814, -0.481745, -0.825969, -0.292740, -0.531693, -0.825969, -0.187290, -0.558151, -0.825969, -0.079008, -0.563117, -0.825969, 0.025948, -0.547788, -0.825969, 0.133052, -0.509679, -0.825969, 0.240835, -0.448088, -0.825969, 0.342040, -0.365423, -0.825969, 0.429233, -0.267053, -0.825969, 0.496445, -0.160200, -0.825969, 0.540472, -0.052311, -0.825969, 0.561283, 0.052311, -0.825969, 0.561283, 0.160200, -0.825969, 0.540473, 0.267053, -0.825969, 0.496445, 0.365422, -0.825969, 0.429233, 0.448088, -0.825969, 0.342041, 0.509679, -0.825969, 0.240836, 0.547788, -0.825969, 0.133053, 0.563117, -0.825969, 0.025949, 0.558151, -0.825970, -0.079007, 0.531693, -0.825969, -0.187289, 0.481746, -0.825969, -0.292738, 0.409116, -0.825969, -0.387813, 0.317776, -0.825969, -0.465610, 0.214209, -0.825969, -0.521430, 0.105955, -0.825969, -0.553668, 0.000002, -0.825969, -0.563715, 0, -0.761436, -0.648240, -0.121841, -0.761436, -0.636687, -0.246326, -0.761436, -0.599615, -0.365423, -0.761436, -0.535426, -0.470458, -0.761436, -0.445964, -0.553979, -0.761436, -0.336634, -0.611416, -0.761436, -0.215373, -0.641841, -0.761436, -0.090855, -0.647553, -0.761436, 0.029839, -0.629925, -0.761436, 0.153002, -0.586102, -0.761436, 0.276947, -0.515276, -0.761436, 0.393327, -0.420215, -0.761436, 0.493593, -0.307096, -0.761436, 0.570883, -0.184221, -0.761436, 0.621513, -0.060154, -0.761436, 0.645443, 0.060154, -0.761436, 0.645443, 0.184221, -0.761436, 0.621513, 0.307095, -0.761436, 0.570883, 0.420215, -0.761436, 0.493594, 0.515276, -0.761436, 0.393327, 0.586102, -0.761436, 0.276947, 0.629925, -0.761436, 0.153003, 0.647553, -0.761436, 0.029840, 0.641842, -0.761436, -0.090854, 0.611417, -0.761436, -0.215371, 0.553980, -0.761436, -0.336633, 0.470459, -0.761436, -0.445963, 0.365424, -0.761436, -0.535425, 0.246328, -0.761436, -0.599615, 0.121843, -0.761436, -0.636686, 0.000002, -0.761436, -0.648240, 0, -0.687961, -0.725747, -0.136409, -0.687961, -0.712813, -0.275778, -0.687961, -0.671309, -0.409115, -0.687961, -0.599445, -0.526709, -0.687961, -0.499286, -0.620216, -0.687961, -0.376884, -0.684521, -0.687961, -0.241124, -0.718584, -0.687961, -0.101718, -0.724978, -0.687961, 0.033406, -0.705243, -0.687961, 0.171296, -0.656180, -0.687961, 0.310060, -0.576885, -0.687961, 0.440355, -0.470459, -0.687961, 0.552610, -0.343814, -0.687961, 0.639141, -0.206247, -0.687961, 0.695824, -0.067347, -0.687961, 0.722616, 0.067347, -0.687961, 0.722616, 0.206247, -0.687961, 0.695824, 0.343813, -0.687961, 0.639141, 0.470458, -0.687961, 0.552611, 0.576885, -0.687961, 0.440355, 0.656179, -0.687961, 0.310061, 0.705242, -0.687961, 0.171297, 0.724978, -0.687961, 0.033407, 0.718584, -0.687961, -0.101717, 0.684521, -0.687961, -0.241122, 0.620217, -0.687961, -0.376882, 0.526710, -0.687961, -0.499285, 0.409116, -0.687961, -0.599444, 0.275780, -0.687961, -0.671308, 0.136411, -0.687961, -0.712812, 0.000002, -0.687961, -0.725747, 0, -0.606761, -0.794885, -0.149404, -0.606761, -0.780717, -0.302050, -0.606761, -0.735260, -0.448088, -0.606761, -0.656550, -0.576885, -0.606761, -0.546850, -0.679300, -0.606761, -0.412787, -0.749730, -0.606761, -0.264094, -0.787038, -0.606761, -0.111408, -0.794042, -0.606761, 0.036589, -0.772426, -0.606761, 0.187614, -0.718690, -0.606761, 0.339597, -0.631841, -0.606761, 0.482305, -0.515276, -0.606761, 0.605254, -0.376567, -0.606761, 0.700028, -0.225895, -0.606761, 0.762111, -0.073762, -0.606761, 0.791455, 0.073762, -0.606761, 0.791455, 0.225895, -0.606761, 0.762111, 0.376566, -0.606761, 0.700028, 0.515275, -0.606761, 0.605254, 0.631841, -0.606761, 0.482305, 0.718689, -0.606761, 0.339598, 0.772426, -0.606761, 0.187615, 0.794042, -0.606761, 0.036590, 0.787039, -0.606761, -0.111407, 0.749731, -0.606761, -0.264093, 0.679301, -0.606761, -0.412785, 0.576887, -0.606761, -0.546848, 0.448090, -0.606761, -0.656549, 0.302052, -0.606761, -0.735259, 0.149406, -0.606761, -0.780717, 0.000002, -0.606761, -0.794885, 0, -0.519304, -0.854590, -0.160626, -0.519304, -0.839358, -0.324737, -0.519304, -0.790487, -0.481745, -0.519304, -0.705865, -0.620216, -0.519304, -0.587925, -0.730323, -0.519304, -0.443792, -0.806044, -0.519304, -0.283931, -0.846154, -0.519304, -0.119776, -0.853684, -0.519304, 0.039337, -0.830444, -0.519304, 0.201706, -0.772672, -0.519304, 0.365105, -0.679300, -0.519304, 0.518531, -0.553979, -0.519304, 0.650715, -0.404851, -0.519304, 0.752608, -0.242863, -0.519304, 0.819354, -0.079303, -0.519304, 0.850902, 0.079303, -0.519304, 0.850902, 0.242862, -0.519304, 0.819354, 0.404851, -0.519304, 0.752608, 0.553979, -0.519304, 0.650716, 0.679299, -0.519304, 0.518532, 0.772671, -0.519304, 0.365106, 0.830444, -0.519304, 0.201707, 0.853684, -0.519304, 0.039338, 0.846154, -0.519304, -0.119775, 0.806044, -0.519304, -0.283929, 0.730324, -0.519304, -0.443790, 0.620217, -0.519304, -0.587923, 0.481747, -0.519304, -0.705864, 0.324740, -0.519304, -0.790486, 0.160628, -0.519304, -0.839358, 0.000002, -0.519304, -0.854589, 0, -0.427229, -0.904144, -0.169940, -0.427229, -0.888029, -0.343568, -0.427229, -0.836323, -0.509679, -0.427229, -0.746795, -0.656180, -0.427229, -0.622016, -0.772672, -0.427229, -0.469526, -0.852783, -0.427229, -0.300394, -0.895219, -0.427229, -0.126722, -0.903185, -0.427229, 0.041618, -0.878599, -0.427229, 0.213402, -0.817476, -0.427229, 0.386276, -0.718690, -0.427229, 0.548599, -0.586102, -0.427229, 0.688448, -0.428327, -0.427229, 0.796249, -0.256945, -0.427229, 0.866865, -0.083901, -0.427229, 0.900242, 0.083901, -0.427229, 0.900242, 0.256945, -0.427229, 0.866865, 0.428326, -0.427229, 0.796249, 0.586102, -0.427229, 0.688448, 0.718689, -0.427229, 0.548600, 0.817475, -0.427229, 0.386277, 0.878598, -0.427229, 0.213403, 0.903185, -0.427229, 0.041619, 0.895219, -0.427229, -0.126720, 0.852784, -0.427229, -0.300393, 0.772673, -0.427229, -0.469524, 0.656181, -0.427229, -0.622014, 0.509681, -0.427229, -0.746794, 0.343570, -0.427229, -0.836323, 0.169942, -0.427229, -0.888029, 0.000002, -0.427229, -0.904144, 0, -0.332242, -0.943194, -0.177279, -0.332242, -0.926384, -0.358407, -0.332242, -0.872445, -0.531693, -0.332242, -0.779050, -0.684521, -0.332242, -0.648881, -0.806044, -0.332242, -0.489805, -0.889615, -0.332242, -0.313369, -0.933884, -0.332242, -0.132195, -0.942194, -0.332242, 0.043416, -0.916546, -0.332242, 0.222619, -0.852783, -0.332242, 0.402959, -0.749730, -0.332242, 0.572293, -0.611416, -0.332242, 0.718182, -0.446827, -0.332242, 0.830639, -0.268043, -0.332242, 0.904305, -0.087525, -0.332242, 0.939124, 0.087525, -0.332242, 0.939124, 0.268042, -0.332242, 0.904306, 0.446826, -0.332242, 0.830639, 0.611416, -0.332242, 0.718183, 0.749730, -0.332242, 0.572294, 0.852783, -0.332242, 0.402961, 0.916545, -0.332242, 0.222620, 0.942194, -0.332242, 0.043417, 0.933884, -0.332242, -0.132193, 0.889616, -0.332242, -0.313367, 0.806045, -0.332242, -0.489803, 0.684522, -0.332242, -0.648880, 0.531695, -0.332242, -0.779048, 0.358409, -0.332242, -0.872444, 0.177282, -0.332242, -0.926383, 0.000003, -0.332242, -0.943194, 0, -0.236027, -0.971747, -0.182646, -0.236027, -0.954427, -0.369256, -0.236027, -0.898855, -0.547788, -0.236027, -0.802633, -0.705242, -0.236027, -0.668524, -0.830444, -0.236027, -0.504632, -0.916546, -0.236027, -0.322855, -0.962155, -0.236027, -0.136197, -0.970716, -0.236027, 0.044730, -0.944291, -0.236027, 0.229358, -0.878599, -0.236027, 0.415158, -0.772426, -0.236027, 0.589618, -0.629925, -0.236027, 0.739923, -0.460353, -0.236027, 0.855784, -0.276157, -0.236027, 0.931681, -0.090175, -0.236027, 0.967554, 0.090174, -0.236027, 0.967554, 0.276157, -0.236027, 0.931681, 0.460352, -0.236027, 0.855784, 0.629924, -0.236027, 0.739923, 0.772426, -0.236027, 0.589618, 0.878598, -0.236027, 0.415159, 0.944291, -0.236027, 0.229359, 0.970716, -0.236027, 0.044731, 0.962155, -0.236027, -0.136195, 0.916546, -0.236027, -0.322853, 0.830445, -0.236027, -0.504630, 0.705244, -0.236027, -0.668522, 0.547790, -0.236027, -0.802632, 0.369259, -0.236027, -0.898854, 0.182649, -0.236027, -0.954427, 0.000003, -0.236027, -0.971747, 0, -0.140157, -0.990129, -0.186101, -0.140157, -0.972483, -0.376242, -0.140157, -0.915859, -0.558151, -0.140157, -0.817816, -0.718584, -0.140157, -0.681171, -0.846154, -0.140157, -0.514178, -0.933884, -0.140157, -0.328963, -0.980356, -0.140157, -0.138773, -0.989080, -0.140157, 0.045576, -0.962155, -0.140157, 0.233697, -0.895219, -0.140157, 0.423012, -0.787039, -0.140157, 0.600772, -0.641842, -0.140157, 0.753920, -0.469061, -0.140157, 0.871973, -0.281381, -0.140157, 0.949305, -0.091880, -0.140157, 0.985857, 0.091880, -0.140157, 0.985857, 0.281381, -0.140157, 0.949306, 0.469061, -0.140157, 0.871974, 0.641841, -0.140157, 0.753921, 0.787038, -0.140157, 0.600772, 0.895219, -0.140157, 0.423013, 0.962155, -0.140157, 0.233698, 0.989080, -0.140157, 0.045577, 0.980356, -0.140157, -0.138772, 0.933885, -0.140157, -0.328961, 0.846155, -0.140157, -0.514176, 0.718585, -0.140157, -0.681169, 0.558153, -0.140157, -0.817815, 0.376244, -0.140157, -0.915858, 0.186104, -0.140157, -0.972482, 0.000003, -0.140157, -0.990129, 0, -0.046031, -0.998940, -0.187757, -0.046031, -0.981136, -0.379590, -0.046031, -0.924009, -0.563117, -0.046031, -0.825094, -0.724978, -0.046031, -0.687232, -0.853684, -0.046031, -0.518754, -0.942194, -0.046031, -0.331890, -0.989080, -0.046031, -0.140008, -0.997881, -0.046031, 0.045982, -0.970717, -0.046031, 0.235777, -0.903185, -0.046031, 0.426776, -0.794042, -0.046031, 0.606118, -0.647553, -0.046031, 0.760629, -0.473235, -0.046031, 0.879733, -0.283885, -0.046031, 0.957753, -0.092698, -0.046031, 0.994630, 0.092698, -0.046031, 0.994630, 0.283885, -0.046031, 0.957753, 0.473235, -0.046031, 0.879733, 0.647552, -0.046031, 0.760629, 0.794041, -0.046031, 0.606118, 0.903185, -0.046031, 0.426777, 0.970716, -0.046031, 0.235778, 0.997881, -0.046031, 0.045983, 0.989080, -0.046031, -0.140007, 0.942195, -0.046031, -0.331888, 0.853685, -0.046031, -0.518752, 0.724980, -0.046031, -0.687230, 0.563120, -0.046031, -0.825093, 0.379592, -0.046031, -0.924008, 0.187760, -0.046031, -0.981136, 0.000003, -0.046031, -0.998940, 0, 0.046030, -0.998940, -0.187757, 0.046030, -0.981136, -0.379590, 0.046030, -0.924009, -0.563117, 0.046030, -0.825094, -0.724978, 0.046030, -0.687232, -0.853684, 0.046030, -0.518754, -0.942194, 0.046030, -0.331890, -0.989080, 0.046030, -0.140008, -0.997856, 0.046030, 0.045982, -0.970599, 0.046030, 0.235777, -0.902997, 0.046030, 0.426776, -0.793814, 0.046030, 0.606118, -0.647321, 0.046030, 0.760629, -0.473035, 0.046030, 0.879733, -0.283747, 0.046030, 0.957753, -0.092648, 0.046030, 0.994630, 0.092698, 0.046030, 0.994630, 0.283885, 0.046030, 0.957753, 0.473235, 0.046030, 0.879733, 0.647552, 0.046030, 0.760629, 0.794041, 0.046030, 0.606118, 0.903185, 0.046030, 0.426777, 0.970716, 0.046030, 0.235778, 0.997881, 0.046030, 0.045983, 0.989080, 0.045418, -0.140007, 0.942195, 0.044737, -0.331888, 0.853685, 0.044274, -0.518752, 0.724980, 0.044087, -0.687230, 0.563120, 0.044200, -0.825092, 0.379592, 0.044598, -0.924008, 0.187760, 0.045231, -0.981136, 0.000003, 0.046030, -0.998940, 0, 0.140157, -0.990129, -0.186101, 0.140156, -0.972483, -0.376242, 0.140156, -0.915859, -0.558151, 0.140156, -0.817817, -0.718584, 0.140156, -0.681171, -0.846154, 0.140156, -0.514178, -0.933884, 0.140157, -0.328963, -0.980356, 0.140157, -0.138773, -0.989006, 0.140157, 0.045576, -0.961814, 0.140156, 0.233697, -0.894675, 0.140156, 0.423012, -0.786379, 0.140156, 0.600772, -0.641169, 0.140156, 0.753920, -0.468479, 0.140156, 0.871973, -0.280982, 0.140156, 0.949305, -0.091735, 0.140157, 0.985857, 0.091880, 0.140157, 0.985857, 0.281381, 0.140156, 0.949305, 0.469061, 0.140156, 0.871974, 0.641841, 0.140156, 0.753921, 0.787038, 0.140156, 0.600772, 0.895219, 0.140156, 0.423013, 0.962155, 0.140156, 0.233698, 0.989080, 0.140156, 0.045577, 0.980356, 0.138383, -0.138772, 0.933885, 0.136408, -0.328961, 0.846155, 0.135068, -0.514176, 0.718585, 0.134526, -0.681169, 0.558153, 0.134853, -0.817815, 0.376244, 0.136006, -0.915858, 0.186104, 0.137841, -0.972482, 0.000003, 0.140156, -0.990129, 0, 0.236027, -0.971747, -0.182646, 0.236027, -0.954427, -0.369256, 0.236027, -0.898856, -0.547788, 0.236027, -0.802633, -0.705242, 0.236027, -0.668524, -0.830444, 0.236027, -0.504632, -0.916546, 0.236027, -0.322855, -0.962155, 0.236027, -0.136197, -0.970599, 0.236027, 0.044730, -0.943747, 0.236027, 0.229358, -0.877731, 0.236027, 0.415158, -0.771374, 0.236027, 0.589618, -0.628852, 0.236027, 0.739923, -0.459425, 0.236027, 0.855784, -0.275521, 0.236027, 0.931681, -0.089943, 0.236027, 0.967554, 0.090174, 0.236027, 0.967554, 0.276157, 0.236027, 0.931681, 0.460352, 0.236027, 0.855785, 0.629924, 0.236027, 0.739923, 0.772426, 0.236027, 0.589618, 0.878598, 0.236027, 0.415159, 0.944291, 0.236027, 0.229359, 0.970717, 0.236027, 0.044731, 0.962155, 0.233199, -0.136195, 0.916546, 0.230049, -0.322853, 0.830446, 0.227912, -0.504630, 0.705244, 0.227048, -0.668523, 0.547790, 0.227569, -0.802632, 0.369259, 0.229407, -0.898855, 0.182649, 0.232334, -0.954427, 0.000003, 0.236027, -0.971747, 0, 0.332242, -0.943194, -0.177279, 0.332242, -0.926384, -0.358407, 0.332242, -0.872445, -0.531693, 0.332242, -0.779050, -0.684521, 0.332242, -0.648881, -0.806044, 0.332242, -0.489805, -0.889615, 0.332242, -0.313369, -0.933884, 0.332242, -0.132195, -0.942038, 0.332242, 0.043416, -0.915824, 0.332242, 0.222619, -0.851633, 0.332242, 0.402960, -0.748336, 0.332242, 0.572293, -0.609994, 0.332242, 0.718182, -0.445596, 0.332242, 0.830639, -0.267199, 0.332242, 0.904306, -0.087218, 0.332242, 0.939124, 0.087525, 0.332242, 0.939124, 0.268043, 0.332242, 0.904306, 0.446826, 0.332242, 0.830639, 0.611416, 0.332242, 0.718183, 0.749730, 0.332242, 0.572294, 0.852783, 0.332242, 0.402961, 0.916546, 0.332242, 0.222620, 0.942195, 0.332242, 0.043417, 0.933885, 0.328493, -0.132193, 0.889616, 0.324317, -0.313367, 0.806045, 0.321484, -0.489803, 0.684522, 0.320339, -0.648880, 0.531695, 0.321030, -0.779048, 0.358409, 0.323467, -0.872444, 0.177282, 0.327347, -0.926384, 0.000003, 0.332242, -0.943194, 0, 0.427228, -0.904144, -0.169940, 0.427228, -0.888030, -0.343568, 0.427228, -0.836324, -0.509679, 0.427228, -0.746795, -0.656180, 0.427228, -0.622016, -0.772672, 0.427228, -0.469526, -0.852783, 0.427228, -0.300395, -0.895219, 0.427228, -0.126722, -0.902998, 0.427228, 0.041618, -0.877731, 0.427228, 0.213402, -0.816092, 0.427228, 0.386276, -0.717012, 0.427228, 0.548599, -0.584391, 0.427228, 0.688448, -0.426847, 0.427228, 0.796249, -0.255930, 0.427228, 0.866865, -0.083532, 0.427228, 0.900243, 0.083901, 0.427228, 0.900243, 0.256945, 0.427228, 0.866865, 0.428326, 0.427228, 0.796249, 0.586102, 0.427228, 0.688448, 0.718689, 0.427228, 0.548600, 0.817475, 0.427228, 0.386277, 0.878598, 0.427228, 0.213403, 0.903185, 0.427228, 0.041619, 0.895220, 0.422719, -0.126720, 0.852784, 0.417694, -0.300393, 0.772673, 0.414286, -0.469524, 0.656181, 0.412908, -0.622015, 0.509681, 0.413740, -0.746794, 0.343570, 0.416672, -0.836323, 0.169942, 0.421339, -0.888029, 0.000002, 0.427228, -0.904144, 0, 0.519304, -0.854590, -0.160626, 0.519304, -0.839359, -0.324738, 0.519304, -0.790487, -0.481745, 0.519304, -0.705865, -0.620216, 0.519304, -0.587925, -0.730324, 0.519304, -0.443792, -0.806044, 0.519304, -0.283931, -0.846155, 0.519304, -0.119776, -0.853472, 0.519304, 0.039337, -0.829465, 0.519304, 0.201706, -0.771110, 0.519304, 0.365105, -0.677407, 0.519304, 0.518532, -0.552048, 0.519304, 0.650715, -0.403181, 0.519304, 0.752608, -0.241718, 0.519304, 0.819354, -0.078886, 0.519304, 0.850902, 0.079303, 0.519304, 0.850902, 0.242862, 0.519304, 0.819354, 0.404851, 0.519304, 0.752608, 0.553979, 0.519304, 0.650716, 0.679300, 0.519304, 0.518532, 0.772672, 0.519304, 0.365106, 0.830444, 0.519304, 0.201707, 0.853684, 0.519304, 0.039338, 0.846155, 0.514215, -0.119775, 0.806045, 0.508547, -0.283929, 0.730324, 0.504701, -0.443790, 0.620218, 0.503146, -0.587923, 0.481747, 0.504084, -0.705864, 0.324740, 0.507392, -0.790486, 0.160628, 0.512659, -0.839358, 0.000002, 0.519304, -0.854590, 0, 0.606760, -0.794885, -0.149404, 0.606760, -0.780718, -0.302050, 0.606760, -0.735260, -0.448089, 0.606760, -0.656551, -0.576886, 0.606760, -0.546850, -0.679300, 0.606760, -0.412787, -0.749731, 0.606760, -0.264094, -0.787039, 0.606760, -0.111408, -0.793815, 0.606760, 0.036589, -0.771375, 0.606760, 0.187614, -0.717012, 0.606760, 0.339598, -0.629808, 0.606760, 0.482305, -0.513202, 0.606760, 0.605254, -0.374772, 0.606760, 0.700028, -0.224665, 0.606760, 0.762111, -0.073314, 0.606760, 0.791455, 0.073762, 0.606760, 0.791455, 0.225895, 0.606760, 0.762111, 0.376566, 0.606760, 0.700028, 0.515276, 0.606760, 0.605255, 0.631841, 0.606760, 0.482306, 0.718690, 0.606760, 0.339598, 0.772426, 0.606760, 0.187615, 0.794042, 0.606760, 0.036590, 0.787039, 0.601294, -0.111407, 0.749731, 0.595205, -0.264093, 0.679301, 0.591074, -0.412786, 0.576887, 0.589403, -0.546849, 0.448090, 0.590411, -0.656550, 0.302052, 0.593965, -0.735260, 0.149406, 0.599622, -0.780717, 0.000002, 0.606760, -0.794885, 0, 0.687961, -0.725748, -0.136409, 0.687961, -0.712813, -0.275779, 0.687961, -0.671309, -0.409115, 0.687961, -0.599446, -0.526709, 0.687961, -0.499286, -0.620216, 0.687961, -0.376884, -0.684521, 0.687961, -0.241124, -0.718584, 0.687961, -0.101718, -0.724744, 0.687961, 0.033407, -0.704159, 0.687961, 0.171296, -0.654452, 0.687961, 0.310060, -0.574791, 0.687961, 0.440355, -0.468322, 0.687961, 0.552611, -0.341966, 0.687961, 0.639141, -0.204980, 0.687961, 0.695825, -0.066885, 0.687961, 0.722616, 0.067347, 0.687961, 0.722616, 0.206247, 0.687961, 0.695825, 0.343814, 0.687961, 0.639142, 0.470458, 0.687961, 0.552611, 0.576885, 0.687961, 0.440356, 0.656180, 0.687961, 0.310061, 0.705243, 0.687961, 0.171297, 0.724978, 0.687961, 0.033408, 0.718584, 0.682331, -0.101717, 0.684522, 0.676058, -0.241123, 0.620217, 0.671803, -0.376883, 0.526711, 0.670083, -0.499285, 0.409116, 0.671121, -0.599444, 0.275780, 0.674781, -0.671308, 0.136411, 0.680609, -0.712813, 0.000002, 0.687961, -0.725748, 0, 0.761436, -0.648241, -0.121841, 0.761436, -0.636687, -0.246326, 0.761436, -0.599616, -0.365423, 0.761436, -0.535427, -0.470459, 0.761436, -0.445965, -0.553980, 0.761436, -0.336634, -0.611417, 0.761436, -0.215373, -0.641842, 0.761436, -0.090855, -0.647321, 0.761436, 0.029839, -0.628853, 0.761436, 0.153002, -0.584391, 0.761436, 0.276947, -0.513202, 0.761436, 0.393327, -0.418100, 0.761436, 0.493594, -0.305266, 0.761436, 0.570884, -0.182966, 0.761436, 0.621513, -0.059697, 0.761436, 0.645444, 0.060154, 0.761436, 0.645444, 0.184221, 0.761436, 0.621513, 0.307096, 0.761436, 0.570884, 0.420215, 0.761436, 0.493594, 0.515276, 0.761436, 0.393327, 0.586102, 0.761436, 0.276948, 0.629925, 0.761436, 0.153003, 0.647554, 0.761436, 0.029840, 0.641842, 0.755860, -0.090854, 0.611417, 0.749649, -0.215372, 0.553980, 0.745435, -0.336633, 0.470460, 0.743732, -0.445963, 0.365424, 0.744760, -0.535426, 0.246328, 0.748384, -0.599615, 0.121843, 0.754155, -0.636687, 0.000002, 0.761435, -0.648241, 0, 0.825969, -0.563716, -0.105954, 0.825969, -0.553669, -0.214208, 0.825969, -0.521431, -0.317775, 0.825969, -0.465612, -0.409115, 0.825969, -0.387815, -0.481746, 0.825969, -0.292740, -0.531693, 0.825969, -0.187290, -0.558151, 0.825969, -0.079008, -0.562897, 0.825969, 0.025948, -0.546768, 0.825969, 0.133052, -0.508052, 0.825969, 0.240835, -0.446116, 0.825969, 0.342041, -0.363411, 0.825969, 0.429233, -0.265312, 0.825969, 0.496445, -0.159007, 0.825969, 0.540473, -0.051876, 0.825969, 0.561283, 0.052311, 0.825969, 0.561283, 0.160200, 0.825969, 0.540473, 0.267053, 0.825969, 0.496445, 0.365423, 0.825969, 0.429234, 0.448089, 0.825969, 0.342041, 0.509680, 0.825969, 0.240836, 0.547789, 0.825969, 0.133053, 0.563118, 0.825969, 0.025949, 0.558152, 0.820666, -0.079008, 0.531694, 0.814757, -0.187289, 0.481746, 0.810750, -0.292739, 0.409116, 0.809129, -0.387814, 0.317776, 0.810107, -0.465611, 0.214209, 0.813555, -0.521431, 0.105955, 0.819044, -0.553669, 0.000002, 0.825969, -0.563716, 0, 0.880666, -0.473738, -0.089042, 0.880666, -0.465295, -0.180017, 0.880666, -0.438203, -0.267053, 0.880666, -0.391293, -0.343814, 0.880666, -0.325914, -0.404852, 0.880666, -0.246014, -0.446827, 0.880666, -0.157396, -0.469062, 0.880666, -0.066398, -0.473035, 0.880666, 0.021806, -0.459425, 0.880666, 0.111815, -0.426847, 0.880666, 0.202395, -0.374773, 0.880666, 0.287446, -0.305266, 0.880666, 0.360722, -0.222844, 0.880666, 0.417205, -0.133545, 0.880666, 0.454206, -0.043566, 0.880666, 0.471694, 0.043961, 0.880666, 0.471694, 0.134630, 0.880666, 0.454206, 0.224427, 0.880666, 0.417206, 0.307096, 0.880666, 0.360722, 0.376567, 0.880666, 0.287446, 0.428327, 0.880666, 0.202395, 0.460354, 0.880666, 0.111816, 0.473236, 0.880666, 0.021807, 0.469063, 0.875843, -0.066397, 0.446828, 0.870469, -0.157395, 0.404852, 0.866824, -0.246013, 0.343815, 0.865350, -0.325913, 0.267054, 0.866240, -0.391293, 0.180018, 0.869375, -0.438203, 0.089043, 0.874367, -0.465295, 0.000001, 0.880666, -0.473738, 0, 0.924989, -0.379993, -0.071422, 0.924989, -0.373221, -0.144395, 0.924989, -0.351490, -0.214208, 0.924989, -0.313863, -0.275779, 0.924989, -0.261421, -0.324738, 0.924989, -0.197332, -0.358408, 0.924989, -0.126250, -0.376243, 0.924989, -0.053259, -0.379418, 0.924989, 0.017491, -0.368459, 0.924989, 0.089689, -0.342295, 0.924989, 0.162344, -0.300507, 0.924989, 0.230565, -0.244752, 0.924989, 0.289341, -0.178655, 0.924989, 0.334647, -0.107055, 0.924989, 0.364326, -0.034922, 0.924989, 0.378354, 0.035262, 0.924989, 0.378354, 0.107989, 0.924989, 0.364326, 0.180017, 0.924989, 0.334647, 0.246327, 0.924989, 0.289341, 0.302051, 0.924989, 0.230565, 0.343568, 0.924989, 0.162344, 0.369257, 0.924989, 0.089689, 0.379591, 0.924989, 0.017492, 0.376243, 0.920839, -0.053258, 0.358408, 0.916215, -0.126249, 0.324739, 0.913078, -0.197331, 0.275780, 0.911810, -0.261420, 0.214209, 0.912575, -0.313862, 0.144396, 0.915273, -0.351490, 0.071423, 0.919569, -0.373221, 0.000001, 0.924989, -0.379993, 0, 0.958769, -0.284187, -0.053415, 0.958769, -0.279122, -0.107989, 0.958769, -0.262870, -0.160201, 0.958769, -0.234730, -0.206248, 0.958769, -0.195510, -0.242863, 0.958769, -0.147580, -0.268044, 0.958769, -0.094419, -0.281382, 0.958769, -0.039831, -0.283748, 0.958769, 0.013081, -0.275522, 0.958769, 0.067076, -0.255931, 0.958769, 0.121413, -0.224666, 0.958769, 0.172434, -0.182967, 0.958769, 0.216390, -0.133545, 0.958769, 0.250274, -0.080018, 0.958769, 0.272470, -0.026101, 0.958769, 0.282961, 0.026371, 0.958769, 0.282961, 0.080762, 0.958769, 0.272470, 0.134630, 0.958769, 0.250274, 0.184221, 0.958769, 0.216391, 0.225896, 0.958769, 0.172434, 0.256946, 0.958769, 0.121413, 0.276158, 0.958769, 0.067076, 0.283886, 0.958769, 0.013082, 0.281382, 0.955462, -0.039830, 0.268044, 0.951779, -0.094418, 0.242864, 0.949280, -0.147579, 0.206249, 0.948270, -0.195509, 0.160201, 0.948879, -0.234730, 0.107990, 0.951029, -0.262870, 0.053416, 0.954451, -0.279122, 0.000001, 0.958769, -0.284187, 0, 0.982177, -0.187958, -0.035328, 0.982177, -0.184608, -0.071422, 0.982177, -0.173859, -0.105955, 0.982177, -0.155247, -0.136410, 0.982177, -0.129308, -0.160627, 0.982177, -0.097607, -0.177281, 0.982177, -0.062447, -0.186102, 0.982177, -0.026344, -0.187662, 0.982177, 0.008652, -0.182202, 0.982177, 0.044363, -0.169230, 0.982177, 0.080301, -0.148543, 0.982177, 0.114045, -0.120963, 0.982177, 0.143118, -0.088283, 0.982177, 0.165528, -0.052894, 0.982177, 0.180208, -0.017252, 0.982177, 0.187147, 0.017442, 0.982177, 0.187147, 0.053415, 0.982177, 0.180208, 0.089042, 0.982177, 0.165528, 0.121842, 0.982177, 0.143118, 0.149405, 0.982177, 0.114045, 0.169941, 0.982177, 0.080301, 0.182647, 0.982177, 0.044363, 0.187758, 0.982177, 0.008652, 0.186102, 0.979862, -0.026343, 0.177281, 0.977282, -0.062447, 0.160627, 0.975532, -0.097607, 0.136410, 0.974825, -0.129307, 0.105955, 0.975252, -0.155247, 0.071423, 0.976757, -0.173859, 0.035328, 0.979154, -0.184608, 0.000001, 0.982177, -0.187958, 0, 0.995685, -0.092798, -0.017442, 0.995685, -0.091144, -0.035262, 0.995685, -0.085837, -0.052311, 0.995685, -0.076648, -0.067348, 0.995685, -0.063841, -0.079304, 0.995685, -0.048190, -0.087526, 0.995685, -0.030831, -0.091882, 0.995685, -0.013006, -0.092649, 0.995685, 0.004272, -0.089944, 0.995685, 0.021903, -0.083533, 0.995685, 0.039646, -0.073315, 0.995685, 0.056306, -0.059698, 0.995685, 0.070659, -0.043566, 0.995685, 0.081724, -0.026101, 0.995685, 0.088971, -0.008513, 0.995685, 0.092397, 0.008611, 0.995685, 0.092397, 0.026372, 0.995685, 0.088971, 0.043962, 0.995685, 0.081724, 0.060155, 0.995685, 0.070659, 0.073763, 0.995685, 0.056306, 0.083902, 0.995685, 0.039646, 0.090176, 0.995685, 0.021903, 0.092699, 0.995685, 0.004272, 0.091882, 0.994481, -0.013006, 0.087526, 0.993139, -0.030831, 0.079304, 0.992229, -0.048190, 0.067348, 0.991861, -0.063841, 0.052312, 0.992083, -0.076648, 0.035263, 0.992866, -0.085837, 0.017442, 0.994113, -0.091144, 0, 0.995685, -0.092798, 0, 1, -0.000001, -0, 1, -0.000001, -0.000001, 1, -0.000001, -0.000001, 1, -0.000001, -0.000001, 1, -0.000001, -0.000001, 1, -0.000001, -0.000001, 1, -0, -0.000001, 1, -0, -0.000001, 1, 0, -0.000001, 1, 0, -0.000001, 1, 0.000001, -0.000001, 1, 0.000001, -0.000001, 1, 0.000001, -0.000001, 1, 0.000001, -0, 1, 0.000001, -0, 1, 0.000001, 0, 1, 0.000001, 0, 1, 0.000001, 0.000001, 1, 0.000001, 0.000001, 1, 0.000001, 0.000001, 1, 0.000001, 0.000001, 1, 0.000001, 0.000001, 1, 0, 0.000001, 1, 0, 0.000001, 1, -0, 0.000001, 1, -0, 0.000001, 1.000000, -0.000001, 0.000001, 1.000000, -0.000001, 0.000001, 1.000000, -0.000001, 0.000001, 1.000000, -0.000001, 0, 1.000000, -0.000001, 0, 1, -0.000001, -0.013192, -0.988931, -0.139125, -0.039863, -0.988931, -0.133861, -0.066237, -0.988931, -0.122897, -0.090505, -0.988931, -0.106260, -0.110921, -0.988931, -0.084736, -0.126183, -0.988931, -0.059768, -0.135696, -0.988931, -0.033157, -0.139609, -0.988931, -0.006607, -0.138319, -0.988931, 0.019797, -0.131665, -0.988931, 0.046553, -0.119252, -0.988931, 0.072574, -0.101290, -0.988931, 0.096031, -0.078750, -0.988931, 0.115256, -0.053197, -0.988931, 0.129107, -0.026460, -0.988931, 0.137180, -0, -0.988931, 0.139771, 0.026460, -0.988931, 0.137180, 0.053197, -0.988931, 0.129107, 0.078749, -0.988931, 0.115256, 0.101290, -0.988931, 0.096031, 0.119252, -0.988931, 0.072574, 0.131665, -0.988931, 0.046553, 0.138319, -0.988931, 0.019797, 0.139609, -0.988931, -0.006606, 0.135697, -0.988931, -0.033157, 0.126183, -0.988931, -0.059768, 0.110921, -0.988931, -0.084735, 0.090505, -0.988931, -0.106260, 0.066237, -0.988931, -0.122896, 0.039864, -0.988931, -0.133860, 0.013193, -0.988931, -0.139125, -0.022186, -0.970473, -0.233968, -0.067038, -0.970473, -0.225114, -0.111391, -0.970473, -0.206676, -0.152202, -0.970473, -0.178698, -0.186536, -0.970473, -0.142500, -0.212203, -0.970473, -0.100513, -0.228201, -0.970473, -0.055760, -0.234781, -0.970473, -0.011110, -0.232611, -0.970473, 0.033293, -0.221422, -0.970473, 0.078288, -0.200546, -0.970473, 0.122048, -0.170340, -0.970473, 0.161496, -0.132433, -0.970473, 0.193827, -0.089462, -0.970473, 0.217119, -0.044497, -0.970473, 0.230695, -0, -0.970473, 0.235053, 0.044497, -0.970473, 0.230695, 0.089462, -0.970473, 0.217119, 0.132433, -0.970473, 0.193827, 0.170340, -0.970473, 0.161496, 0.200546, -0.970473, 0.122048, 0.221422, -0.970473, 0.078288, 0.232611, -0.970473, 0.033293, 0.234781, -0.970473, -0.011110, 0.228201, -0.970473, -0.055759, 0.212203, -0.970473, -0.100512, 0.186536, -0.970473, -0.142500, 0.152203, -0.970473, -0.178697, 0.111392, -0.970473, -0.206675, 0.067039, -0.970473, -0.225114, 0.022186, -0.970473, -0.233968, -0.031209, -0.941879, -0.329130, -0.094305, -0.941879, -0.316675, -0.156698, -0.941879, -0.290737, -0.214108, -0.941879, -0.251380, -0.262406, -0.941879, -0.200460, -0.298512, -0.941879, -0.141395, -0.321018, -0.941879, -0.078439, -0.330274, -0.941879, -0.015629, -0.327222, -0.941879, 0.046834, -0.311481, -0.941879, 0.110130, -0.282114, -0.941879, 0.171688, -0.239623, -0.941879, 0.227182, -0.186298, -0.941879, 0.272662, -0.125849, -0.941879, 0.305428, -0.062596, -0.941879, 0.324527, -0, -0.941879, 0.330656, 0.062596, -0.941879, 0.324527, 0.125849, -0.941879, 0.305428, 0.186298, -0.941879, 0.272662, 0.239623, -0.941879, 0.227182, 0.282114, -0.941879, 0.171689, 0.311481, -0.941879, 0.110130, 0.327222, -0.941879, 0.046835, 0.330274, -0.941879, -0.015629, 0.321018, -0.941879, -0.078439, 0.298513, -0.941879, -0.141394, 0.262407, -0.941879, -0.200459, 0.214109, -0.941879, -0.251380, 0.156698, -0.941879, -0.290737, 0.094306, -0.941879, -0.316675, 0.031210, -0.941879, -0.329130, -0.040116, -0.902828, -0.423061, -0.121219, -0.902828, -0.407051, -0.201418, -0.902828, -0.373711, -0.275213, -0.902828, -0.323122, -0.337295, -0.902828, -0.257670, -0.383705, -0.902828, -0.181748, -0.412634, -0.902828, -0.100825, -0.424532, -0.902828, -0.020090, -0.420609, -0.902828, 0.060200, -0.400376, -0.902828, 0.141560, -0.362628, -0.902828, 0.220687, -0.308010, -0.902828, 0.292018, -0.239466, -0.902828, 0.350478, -0.161766, -0.902828, 0.392595, -0.080460, -0.902828, 0.417144, -0, -0.902828, 0.425023, 0.080460, -0.902828, 0.417144, 0.161765, -0.902828, 0.392595, 0.239466, -0.902828, 0.350478, 0.308009, -0.902828, 0.292018, 0.362628, -0.902828, 0.220687, 0.400376, -0.902828, 0.141561, 0.420608, -0.902828, 0.060201, 0.424532, -0.902828, -0.020089, 0.412634, -0.902828, -0.100824, 0.383706, -0.902828, -0.181747, 0.337296, -0.902828, -0.257669, 0.275214, -0.902828, -0.323121, 0.201419, -0.902828, -0.373711, 0.121220, -0.902828, -0.407051, 0.040117, -0.902828, -0.423061, -0.048749, -0.853318, -0.514104, -0.147305, -0.853318, -0.494649, -0.244763, -0.853318, -0.454134, -0.334439, -0.853318, -0.392658, -0.409881, -0.853318, -0.313120, -0.466279, -0.853318, -0.220860, -0.501433, -0.853318, -0.122523, -0.515891, -0.853318, -0.024413, -0.511123, -0.853318, 0.073155, -0.486537, -0.853318, 0.172024, -0.440665, -0.853318, 0.268179, -0.374293, -0.853318, 0.354860, -0.291000, -0.853318, 0.425901, -0.196577, -0.853318, 0.477082, -0.097775, -0.853318, 0.506913, -0, -0.853318, 0.516488, 0.097775, -0.853318, 0.506913, 0.196577, -0.853318, 0.477082, 0.290999, -0.853318, 0.425901, 0.374293, -0.853318, 0.354860, 0.440665, -0.853318, 0.268179, 0.486537, -0.853318, 0.172025, 0.511123, -0.853318, 0.073156, 0.515891, -0.853318, -0.024412, 0.501433, -0.853318, -0.122522, 0.466279, -0.853318, -0.220859, 0.409882, -0.853318, -0.313119, 0.334440, -0.853318, -0.392657, 0.244764, -0.853318, -0.454134, 0.147306, -0.853318, -0.494648, 0.048750, -0.853318, -0.514104, -0.056949, -0.793703, -0.600577, -0.172082, -0.793703, -0.577850, -0.285933, -0.793703, -0.530521, -0.390693, -0.793703, -0.458704, -0.478824, -0.793703, -0.365788, -0.544708, -0.793703, -0.258009, -0.585775, -0.793703, -0.143131, -0.602666, -0.793703, -0.028519, -0.597096, -0.793703, 0.085460, -0.568374, -0.793703, 0.200959, -0.514786, -0.793703, 0.313287, -0.437250, -0.793703, 0.414548, -0.339947, -0.793703, 0.497538, -0.229642, -0.793703, 0.557328, -0.114221, -0.793703, 0.592178, -0, -0.793703, 0.603363, 0.114221, -0.793703, 0.592178, 0.229642, -0.793703, 0.557328, 0.339946, -0.793703, 0.497539, 0.437250, -0.793703, 0.414549, 0.514786, -0.793703, 0.313288, 0.568373, -0.793703, 0.200960, 0.597096, -0.793703, 0.085461, 0.602666, -0.793703, -0.028518, 0.585776, -0.793703, -0.143130, 0.544709, -0.793703, -0.258008, 0.478825, -0.793703, -0.365787, 0.390694, -0.793703, -0.458703, 0.285934, -0.793703, -0.530520, 0.172084, -0.793703, -0.577850, 0.056950, -0.793703, -0.600577, -0.064562, -0.724699, -0.680872, -0.195089, -0.724699, -0.655106, -0.324160, -0.724699, -0.601449, -0.442926, -0.724699, -0.520030, -0.542841, -0.724699, -0.414692, -0.617533, -0.724699, -0.292503, -0.664090, -0.724699, -0.162267, -0.683239, -0.724699, -0.032332, -0.676925, -0.724699, 0.096886, -0.644362, -0.724699, 0.227826, -0.583611, -0.724699, 0.355172, -0.495709, -0.724699, 0.469971, -0.385396, -0.724699, 0.564057, -0.260344, -0.724699, 0.631840, -0.129492, -0.724699, 0.671349, -0, -0.724699, 0.684029, 0.129492, -0.724699, 0.671349, 0.260344, -0.724699, 0.631840, 0.385395, -0.724699, 0.564057, 0.495708, -0.724699, 0.469972, 0.583610, -0.724699, 0.355173, 0.644362, -0.724699, 0.227827, 0.676924, -0.724699, 0.096887, 0.683239, -0.724699, -0.032331, 0.664091, -0.724699, -0.162266, 0.617534, -0.724699, -0.292502, 0.542842, -0.724699, -0.414691, 0.442927, -0.724699, -0.520029, 0.324162, -0.724699, -0.601448, 0.195090, -0.724699, -0.655105, 0.064564, -0.724699, -0.680871, -0.071453, -0.647361, -0.753540, -0.215910, -0.647361, -0.725025, -0.358758, -0.647361, -0.665641, -0.490199, -0.647361, -0.575533, -0.600778, -0.647361, -0.458952, -0.683442, -0.647361, -0.323722, -0.734968, -0.647361, -0.179586, -0.756160, -0.647361, -0.035783, -0.749172, -0.647361, 0.107226, -0.713135, -0.647361, 0.252142, -0.645899, -0.647361, 0.393079, -0.548615, -0.647361, 0.520131, -0.426529, -0.647361, 0.624258, -0.288131, -0.647361, 0.699276, -0.143313, -0.647361, 0.743001, -0, -0.647361, 0.757035, 0.143313, -0.647361, 0.743001, 0.288130, -0.647361, 0.699276, 0.426528, -0.647361, 0.624258, 0.548615, -0.647361, 0.520131, 0.645899, -0.647361, 0.393080, 0.713134, -0.647361, 0.252143, 0.749172, -0.647361, 0.107227, 0.756161, -0.647361, -0.035782, 0.734969, -0.647361, -0.179585, 0.683442, -0.647361, -0.323721, 0.600779, -0.647361, -0.458950, 0.490201, -0.647361, -0.575532, 0.358760, -0.647361, -0.665640, 0.215912, -0.647361, -0.725024, 0.071455, -0.647361, -0.753540, -0.077507, -0.563033, -0.817387, -0.234204, -0.563033, -0.786456, -0.389155, -0.563033, -0.722040, -0.531734, -0.563033, -0.624297, -0.651681, -0.563032, -0.497838, -0.741349, -0.563033, -0.351151, -0.797242, -0.563033, -0.194802, -0.820230, -0.563033, -0.038815, -0.812649, -0.563033, 0.116312, -0.773558, -0.563033, 0.273506, -0.700626, -0.563033, 0.426385, -0.595099, -0.563033, 0.564201, -0.462668, -0.563033, 0.677151, -0.312544, -0.563033, 0.758525, -0.155456, -0.563033, 0.805955, -0, -0.563033, 0.821178, 0.155456, -0.563033, 0.805955, 0.312544, -0.563033, 0.758525, 0.462668, -0.563033, 0.677151, 0.595099, -0.563033, 0.564202, 0.700625, -0.563033, 0.426385, 0.773558, -0.563033, 0.273507, 0.812649, -0.563033, 0.116313, 0.820230, -0.563033, -0.038813, 0.797242, -0.563033, -0.194801, 0.741350, -0.563033, -0.351149, 0.651682, -0.563033, -0.497837, 0.531735, -0.563033, -0.624296, 0.389157, -0.563033, -0.722039, 0.234206, -0.563033, -0.786455, 0.077510, -0.563033, -0.817387, -0.082641, -0.473266, -0.871530, -0.249718, -0.473266, -0.838549, -0.414932, -0.473266, -0.769867, -0.566955, -0.473266, -0.665650, -0.694848, -0.473266, -0.530815, -0.790455, -0.473266, -0.374411, -0.850050, -0.473266, -0.207706, -0.874561, -0.473266, -0.041386, -0.866478, -0.473266, 0.124016, -0.824798, -0.473266, 0.291622, -0.747034, -0.473266, 0.454628, -0.634518, -0.473266, 0.601573, -0.493315, -0.473266, 0.722005, -0.333246, -0.473266, 0.808769, -0.165753, -0.473266, 0.859341, -0, -0.473266, 0.875572, 0.165753, -0.473266, 0.859341, 0.333246, -0.473266, 0.808769, 0.493314, -0.473266, 0.722005, 0.634517, -0.473266, 0.601574, 0.747034, -0.473266, 0.454629, 0.824797, -0.473266, 0.291623, 0.866478, -0.473266, 0.124017, 0.874561, -0.473266, -0.041384, 0.850050, -0.473266, -0.207704, 0.790456, -0.473266, -0.374409, 0.694849, -0.473266, -0.530813, 0.566957, -0.473266, -0.665649, 0.414934, -0.473266, -0.769866, 0.249720, -0.473266, -0.838549, 0.082644, -0.473266, -0.871530, -0.086805, -0.379735, -0.915438, -0.262298, -0.379735, -0.880795, -0.435837, -0.379735, -0.808653, -0.595518, -0.379735, -0.699185, -0.729854, -0.379735, -0.557557, -0.830278, -0.379735, -0.393273, -0.892875, -0.379735, -0.218170, -0.918621, -0.379735, -0.043471, -0.910131, -0.379735, 0.130264, -0.866351, -0.379735, 0.306314, -0.784670, -0.379735, 0.477532, -0.666485, -0.379735, 0.631880, -0.518168, -0.379735, 0.758379, -0.350035, -0.379735, 0.849515, -0.174104, -0.379735, 0.902634, -0, -0.379735, 0.919683, 0.174103, -0.379735, 0.902634, 0.350035, -0.379735, 0.849515, 0.518167, -0.379735, 0.758380, 0.666484, -0.379735, 0.631881, 0.784669, -0.379735, 0.477533, 0.866350, -0.379735, 0.306315, 0.910131, -0.379735, 0.130265, 0.918621, -0.379735, -0.043469, 0.892876, -0.379735, -0.218168, 0.830279, -0.379735, -0.393272, 0.729855, -0.379735, -0.557555, 0.595520, -0.379735, -0.699184, 0.435839, -0.379735, -0.808652, 0.262301, -0.379735, -0.880795, 0.086807, -0.379735, -0.915438, -0.089981, -0.284134, -0.948938, -0.271897, -0.284134, -0.913028, -0.451786, -0.284134, -0.838246, -0.617311, -0.284134, -0.724772, -0.756563, -0.284134, -0.577960, -0.860662, -0.284134, -0.407665, -0.925550, -0.284134, -0.226154, -0.952237, -0.284134, -0.045062, -0.943437, -0.284134, 0.135031, -0.898055, -0.284134, 0.317524, -0.813385, -0.284134, 0.495007, -0.690875, -0.284134, 0.655004, -0.537130, -0.284134, 0.786132, -0.362845, -0.284134, 0.880602, -0.180475, -0.284134, 0.935666, -0, -0.284134, 0.953339, 0.180475, -0.284134, 0.935666, 0.362844, -0.284134, 0.880602, 0.537130, -0.284134, 0.786132, 0.690874, -0.284134, 0.655005, 0.813384, -0.284134, 0.495008, 0.898054, -0.284134, 0.317525, 0.943437, -0.284134, 0.135032, 0.952238, -0.284134, -0.045060, 0.925550, -0.284134, -0.226152, 0.860663, -0.284134, -0.407663, 0.756564, -0.284134, -0.577959, 0.617313, -0.284134, -0.724770, 0.451788, -0.284134, -0.838245, 0.271900, -0.284134, -0.913027, 0.089984, -0.284134, -0.948938, -0.092187, -0.188092, -0.972196, -0.278561, -0.188092, -0.935406, -0.462859, -0.188092, -0.858791, -0.632441, -0.188092, -0.742536, -0.775106, -0.188092, -0.592126, -0.881757, -0.188092, -0.417657, -0.948235, -0.188092, -0.231697, -0.975577, -0.188092, -0.046166, -0.966561, -0.188092, 0.138340, -0.920066, -0.188092, 0.325306, -0.833321, -0.188092, 0.507140, -0.707808, -0.188092, 0.671058, -0.550295, -0.188092, 0.805400, -0.371738, -0.188092, 0.902186, -0.184898, -0.188092, 0.958599, -0, -0.188092, 0.976705, 0.184898, -0.188092, 0.958599, 0.371738, -0.188092, 0.902186, 0.550295, -0.188092, 0.805400, 0.707807, -0.188092, 0.671059, 0.833320, -0.188092, 0.507141, 0.920066, -0.188092, 0.325307, 0.966560, -0.188092, 0.138342, 0.975577, -0.188092, -0.046165, 0.948236, -0.188092, -0.231695, 0.881758, -0.188092, -0.417655, 0.775108, -0.188092, -0.592125, 0.632443, -0.188092, -0.742535, 0.462861, -0.188092, -0.858790, 0.278564, -0.188092, -0.935406, 0.092189, -0.188092, -0.972196, -0.093465, -0.093094, -0.985672, -0.282422, -0.093094, -0.948372, -0.469275, -0.093094, -0.870695, -0.641207, -0.093094, -0.752828, -0.785850, -0.093094, -0.600334, -0.893979, -0.093094, -0.423446, -0.961379, -0.093094, -0.234908, -0.989099, -0.093094, -0.046806, -0.979958, -0.093094, 0.140258, -0.932819, -0.093094, 0.329815, -0.844871, -0.093094, 0.514169, -0.717619, -0.093094, 0.680360, -0.557923, -0.093094, 0.816564, -0.376891, -0.093094, 0.914691, -0.187461, -0.093094, 0.971886, -0, -0.093094, 0.990243, 0.187461, -0.093094, 0.971886, 0.376890, -0.093094, 0.914691, 0.557922, -0.093094, 0.816564, 0.717618, -0.093094, 0.680360, 0.844871, -0.093094, 0.514170, 0.932819, -0.093094, 0.329816, 0.979958, -0.093094, 0.140259, 0.989099, -0.093094, -0.046804, 0.961379, -0.093094, -0.234907, 0.893980, -0.093094, -0.423444, 0.785851, -0.093094, -0.600332, 0.641209, -0.093094, -0.752827, 0.469277, -0.093094, -0.870694, 0.282425, -0.093094, -0.948371, 0.093467, -0.093094, -0.985672, -0.093879, -0, -0.990038, -0.283673, -0, -0.952573, -0.471354, -0, -0.874552, -0.644048, -0, -0.756163, -0.789331, -0, -0.602993, -0.897939, -0, -0.425322, -0.965637, -0, -0.235949, -0.993474, -0, -0.047013, -0.984263, -0, 0.140879, -0.936875, -0, 0.331276, -0.848510, -0, 0.516447, -0.720683, -0, 0.683373, -0.560286, -0, 0.820181, -0.378476, -0, 0.918743, -0.188245, -0, 0.976191, 0.000012, -0, 0.994630, 0.188291, -0, 0.976191, 0.378560, -0, 0.918743, 0.560394, -0, 0.820181, 0.720797, -0, 0.683374, 0.848613, -0, 0.516448, 0.936951, -0, 0.331277, 0.984299, -0, 0.140880, 0.993481, -0.000153, -0.047012, 0.965638, -0.000477, -0.235947, 0.897940, -0.000763, -0.425320, 0.789332, -0.000925, -0.602991, 0.644050, -0.000944, -0.756161, 0.471356, -0.000816, -0.874550, 0.283676, -0.000558, -0.952572, 0.093881, -0.000200, -0.990038, -0.093465, 0.093093, -0.985672, -0.282422, 0.093093, -0.948372, -0.469275, 0.093093, -0.870695, -0.641207, 0.093093, -0.752828, -0.785850, 0.093093, -0.600334, -0.893979, 0.093093, -0.423446, -0.961379, 0.093093, -0.234908, -0.989074, 0.093093, -0.046806, -0.979818, 0.093093, 0.140258, -0.932521, 0.093093, 0.329815, -0.844466, 0.093093, 0.514169, -0.717171, 0.093093, 0.680360, -0.557501, 0.093093, 0.816564, -0.376561, 0.093093, 0.914691, -0.187278, 0.093093, 0.971886, 0.000049, 0.093093, 0.990243, 0.187461, 0.093093, 0.971886, 0.376890, 0.093093, 0.914691, 0.557922, 0.093093, 0.816564, 0.717618, 0.093093, 0.680360, 0.844871, 0.093093, 0.514170, 0.932819, 0.093093, 0.329816, 0.979958, 0.093093, 0.140259, 0.989099, 0.092497, -0.046804, 0.961379, 0.091237, -0.234907, 0.893980, 0.090122, -0.423444, 0.785851, 0.089489, -0.600332, 0.641209, 0.089417, -0.752827, 0.469277, 0.089914, -0.870694, 0.282425, 0.090919, -0.948371, 0.093467, 0.092315, -0.985672, -0.092187, 0.188092, -0.972197, -0.278561, 0.188092, -0.935406, -0.462859, 0.188092, -0.858791, -0.632441, 0.188092, -0.742536, -0.775106, 0.188092, -0.592126, -0.881757, 0.188092, -0.417657, -0.948235, 0.188092, -0.231697, -0.975529, 0.188092, -0.046166, -0.966291, 0.188092, 0.138340, -0.919492, 0.188092, 0.325306, -0.832540, 0.188092, 0.507140, -0.706944, 0.188092, 0.671058, -0.549481, 0.188092, 0.805400, -0.371102, 0.188092, 0.902186, -0.184545, 0.188092, 0.958599, 0.000094, 0.188092, 0.976705, 0.184898, 0.188092, 0.958599, 0.371738, 0.188092, 0.902186, 0.550295, 0.188092, 0.805400, 0.707807, 0.188092, 0.671059, 0.833320, 0.188092, 0.507141, 0.920066, 0.188092, 0.325307, 0.966560, 0.188092, 0.138342, 0.975577, 0.186941, -0.046165, 0.948236, 0.184510, -0.231695, 0.881758, 0.182359, -0.417655, 0.775108, 0.181139, -0.592125, 0.632443, 0.180999, -0.742535, 0.462861, 0.181959, -0.858790, 0.278564, 0.183897, -0.935406, 0.092189, 0.186590, -0.972196, -0.089981, 0.284134, -0.948938, -0.271897, 0.284134, -0.913028, -0.451786, 0.284134, -0.838246, -0.617311, 0.284134, -0.724772, -0.756563, 0.284134, -0.577961, -0.860662, 0.284134, -0.407665, -0.925550, 0.284134, -0.226154, -0.952169, 0.284134, -0.045062, -0.943052, 0.284134, 0.135031, -0.897234, 0.284134, 0.317524, -0.812268, 0.284134, 0.495007, -0.689639, 0.284134, 0.655004, -0.535967, 0.284134, 0.786132, -0.361935, 0.284134, 0.880602, -0.179970, 0.284134, 0.935666, 0.000135, 0.284134, 0.953339, 0.180475, 0.284134, 0.935666, 0.362844, 0.284134, 0.880603, 0.537130, 0.284134, 0.786132, 0.690874, 0.284134, 0.655005, 0.813384, 0.284134, 0.495008, 0.898054, 0.284134, 0.317525, 0.943437, 0.284134, 0.135032, 0.952238, 0.282490, -0.045060, 0.925550, 0.279015, -0.226152, 0.860663, 0.275941, -0.407663, 0.756564, 0.274196, -0.577959, 0.617313, 0.273996, -0.724770, 0.451788, 0.275368, -0.838245, 0.271900, 0.278139, -0.913027, 0.089984, 0.281987, -0.948938, -0.086805, 0.379735, -0.915438, -0.262298, 0.379735, -0.880796, -0.435837, 0.379735, -0.808653, -0.595518, 0.379735, -0.699185, -0.729854, 0.379735, -0.557557, -0.830279, 0.379735, -0.393273, -0.892876, 0.379735, -0.218170, -0.918535, 0.379735, -0.043471, -0.909648, 0.379735, 0.130264, -0.865320, 0.379735, 0.306314, -0.783268, 0.379735, 0.477532, -0.664933, 0.379735, 0.631881, -0.516707, 0.379735, 0.758379, -0.348893, 0.379735, 0.849515, -0.173470, 0.379735, 0.902634, 0.000169, 0.379735, 0.919684, 0.174103, 0.379735, 0.902634, 0.350035, 0.379735, 0.849515, 0.518167, 0.379735, 0.758380, 0.666484, 0.379735, 0.631881, 0.784669, 0.379735, 0.477533, 0.866350, 0.379735, 0.306315, 0.910131, 0.379735, 0.130265, 0.918621, 0.377670, -0.043469, 0.892876, 0.373306, -0.218168, 0.830279, 0.369446, -0.393272, 0.729855, 0.367254, -0.557555, 0.595520, 0.367004, -0.699184, 0.435839, 0.368727, -0.808652, 0.262301, 0.372206, -0.880795, 0.086807, 0.377039, -0.915438, -0.082641, 0.473266, -0.871531, -0.249718, 0.473266, -0.838550, -0.414932, 0.473266, -0.769868, -0.566955, 0.473266, -0.665650, -0.694848, 0.473266, -0.530815, -0.790456, 0.473266, -0.374411, -0.850050, 0.473266, -0.207706, -0.874461, 0.473266, -0.041386, -0.865916, 0.473266, 0.124016, -0.823599, 0.473266, 0.291622, -0.745405, 0.473266, 0.454628, -0.632715, 0.473266, 0.601573, -0.491617, 0.473266, 0.722005, -0.331919, 0.473266, 0.808769, -0.165016, 0.473266, 0.859341, 0.000197, 0.473266, 0.875572, 0.165753, 0.473266, 0.859341, 0.333246, 0.473266, 0.808769, 0.493314, 0.473266, 0.722005, 0.634517, 0.473266, 0.601574, 0.747034, 0.473266, 0.454629, 0.824797, 0.473266, 0.291623, 0.866478, 0.473266, 0.124017, 0.874561, 0.470867, -0.041384, 0.850051, 0.465794, -0.207704, 0.790456, 0.461307, -0.374409, 0.694849, 0.458760, -0.530813, 0.566957, 0.458470, -0.665649, 0.414934, 0.460472, -0.769867, 0.249720, 0.464516, -0.838549, 0.082644, 0.470132, -0.871530, -0.077507, 0.563032, -0.817388, -0.234204, 0.563032, -0.786456, -0.389155, 0.563032, -0.722041, -0.531734, 0.563032, -0.624298, -0.651681, 0.563032, -0.497838, -0.741350, 0.563032, -0.351151, -0.797242, 0.563032, -0.194802, -0.820120, 0.563032, -0.038815, -0.812032, 0.563032, 0.116312, -0.772241, 0.563032, 0.273506, -0.698834, 0.563032, 0.426385, -0.593116, 0.563032, 0.564201, -0.460801, 0.563032, 0.677151, -0.311084, 0.563032, 0.758525, -0.154646, 0.563032, 0.805956, 0.000216, 0.563032, 0.821179, 0.155456, 0.563032, 0.805956, 0.312544, 0.563032, 0.758526, 0.462668, 0.563032, 0.677152, 0.595099, 0.563032, 0.564202, 0.700626, 0.563032, 0.426386, 0.773558, 0.563032, 0.273507, 0.812649, 0.563032, 0.116313, 0.820230, 0.560393, -0.038813, 0.797242, 0.554815, -0.194801, 0.741350, 0.549882, -0.351149, 0.651682, 0.547081, -0.497837, 0.531735, 0.546761, -0.624296, 0.389157, 0.548963, -0.722040, 0.234206, 0.553410, -0.786455, 0.077510, 0.559586, -0.817388, -0.071453, 0.647361, -0.753541, -0.215910, 0.647361, -0.725025, -0.358758, 0.647361, -0.665641, -0.490200, 0.647361, -0.575533, -0.600778, 0.647361, -0.458952, -0.683442, 0.647361, -0.323722, -0.734969, 0.647361, -0.179586, -0.756046, 0.647361, -0.035783, -0.748523, 0.647361, 0.107226, -0.711750, 0.647361, 0.252142, -0.644016, 0.647361, 0.393080, -0.546531, 0.647361, 0.520131, -0.424566, 0.647361, 0.624259, -0.286596, 0.647361, 0.699276, -0.142461, 0.647361, 0.743002, 0.000227, 0.647361, 0.757036, 0.143313, 0.647361, 0.743002, 0.288131, 0.647361, 0.699277, 0.426529, 0.647361, 0.624259, 0.548615, 0.647361, 0.520132, 0.645899, 0.647361, 0.393080, 0.713135, 0.647361, 0.252143, 0.749172, 0.647361, 0.107227, 0.756161, 0.644587, -0.035782, 0.734969, 0.638722, -0.179585, 0.683443, 0.633535, -0.323721, 0.600779, 0.630591, -0.458951, 0.490201, 0.630255, -0.575532, 0.358760, 0.632570, -0.665640, 0.215912, 0.637244, -0.725025, 0.071455, 0.643738, -0.753541, -0.064562, 0.724698, -0.680872, -0.195089, 0.724698, -0.655106, -0.324161, 0.724698, -0.601449, -0.442927, 0.724698, -0.520031, -0.542841, 0.724698, -0.414692, -0.617534, 0.724698, -0.292504, -0.664091, 0.724698, -0.162268, -0.683123, 0.724698, -0.032332, -0.676269, 0.724698, 0.096886, -0.642964, 0.724698, 0.227826, -0.581709, 0.724698, 0.355172, -0.493604, 0.724698, 0.469972, -0.383413, 0.724698, 0.564057, -0.258795, 0.724698, 0.631841, -0.128632, 0.724698, 0.671349, 0.000230, 0.724698, 0.684030, 0.129492, 0.724698, 0.671349, 0.260344, 0.724698, 0.631841, 0.385396, 0.724698, 0.564058, 0.495709, 0.724698, 0.469972, 0.583611, 0.724698, 0.355173, 0.644363, 0.724698, 0.227827, 0.676925, 0.724698, 0.096887, 0.683240, 0.721897, -0.032331, 0.664091, 0.715974, -0.162266, 0.617534, 0.710736, -0.292502, 0.542842, 0.707763, -0.414691, 0.442928, 0.707424, -0.520030, 0.324162, 0.709762, -0.601449, 0.195091, 0.714482, -0.655106, 0.064564, 0.721040, -0.680872, -0.056949, 0.793702, -0.600578, -0.172082, 0.793702, -0.577851, -0.285933, 0.793702, -0.530521, -0.390693, 0.793702, -0.458705, -0.478825, 0.793702, -0.365788, -0.544709, 0.793702, -0.258009, -0.585776, 0.793702, -0.143132, -0.602553, 0.793702, -0.028519, -0.596460, 0.793702, 0.085460, -0.567016, 0.793702, 0.200959, -0.512940, 0.793702, 0.313287, -0.435207, 0.793702, 0.414549, -0.338022, 0.793702, 0.497539, -0.228138, 0.793702, 0.557329, -0.113387, 0.793702, 0.592178, 0.000223, 0.793702, 0.603364, 0.114221, 0.793702, 0.592178, 0.229642, 0.793702, 0.557329, 0.339947, 0.793702, 0.497539, 0.437251, 0.793702, 0.414549, 0.514787, 0.793702, 0.313288, 0.568374, 0.793702, 0.200960, 0.597096, 0.793702, 0.085461, 0.602666, 0.790983, -0.028518, 0.585776, 0.785233, -0.143131, 0.544709, 0.780148, -0.258008, 0.478826, 0.777261, -0.365787, 0.390694, 0.776932, -0.458704, 0.285934, 0.779201, -0.530521, 0.172084, 0.783784, -0.577850, 0.056950, 0.790151, -0.600578, -0.048749, 0.853317, -0.514105, -0.147305, 0.853317, -0.494650, -0.244763, 0.853317, -0.454135, -0.334439, 0.853317, -0.392658, -0.409882, 0.853317, -0.313121, -0.466280, 0.853317, -0.220860, -0.501434, 0.853317, -0.122523, -0.515787, 0.853317, -0.024413, -0.510532, 0.853317, 0.073155, -0.485273, 0.853317, 0.172024, -0.438947, 0.853317, 0.268179, -0.372391, 0.853317, 0.354860, -0.289208, 0.853317, 0.425901, -0.195177, 0.853317, 0.477082, -0.096998, 0.853317, 0.506914, 0.000207, 0.853317, 0.516489, 0.097775, 0.853317, 0.506914, 0.196578, 0.853317, 0.477083, 0.291000, 0.853317, 0.425902, 0.374294, 0.853317, 0.354861, 0.440666, 0.853317, 0.268180, 0.486537, 0.853317, 0.172025, 0.511124, 0.853317, 0.073156, 0.515892, 0.850786, -0.024412, 0.501434, 0.845434, -0.122522, 0.466280, 0.840700, -0.220859, 0.409882, 0.838013, -0.313120, 0.334440, 0.837706, -0.392658, 0.244764, 0.839819, -0.454134, 0.147307, 0.844085, -0.494649, 0.048750, 0.850011, -0.514104, -0.040116, 0.902827, -0.423062, -0.121219, 0.902827, -0.407052, -0.201418, 0.902827, -0.373712, -0.275214, 0.902827, -0.323123, -0.337296, 0.902827, -0.257670, -0.383706, 0.902827, -0.181748, -0.412635, 0.902827, -0.100825, -0.424440, 0.902827, -0.020090, -0.420084, 0.902827, 0.060200, -0.399256, 0.902827, 0.141561, -0.361105, 0.902827, 0.220687, -0.306324, 0.902827, 0.292018, -0.237879, 0.902827, 0.350479, -0.160525, 0.902827, 0.392596, -0.079772, 0.902827, 0.417145, 0.000184, 0.902827, 0.425024, 0.080460, 0.902827, 0.417145, 0.161766, 0.902827, 0.392596, 0.239467, 0.902827, 0.350479, 0.308010, 0.902827, 0.292019, 0.362628, 0.902827, 0.220688, 0.400377, 0.902827, 0.141561, 0.420609, 0.902827, 0.060201, 0.424533, 0.900584, -0.020089, 0.412635, 0.895841, -0.100825, 0.383707, 0.891646, -0.181747, 0.337297, 0.889266, -0.257670, 0.275215, 0.888994, -0.323122, 0.201419, 0.890866, -0.373712, 0.121220, 0.894646, -0.407052, 0.040117, 0.899898, -0.423062, -0.031209, 0.941879, -0.329131, -0.094305, 0.941879, -0.316676, -0.156698, 0.941879, -0.290738, -0.214109, 0.941879, -0.251381, -0.262407, 0.941879, -0.200461, -0.298513, 0.941879, -0.141395, -0.321019, 0.941879, -0.078440, -0.330198, 0.941879, -0.015629, -0.326787, 0.941879, 0.046834, -0.310552, 0.941879, 0.110130, -0.280850, 0.941879, 0.171689, -0.238223, 0.941879, 0.227182, -0.184980, 0.941879, 0.272663, -0.124818, 0.941879, 0.305429, -0.062024, 0.941879, 0.324528, 0.000153, 0.941879, 0.330657, 0.062596, 0.941879, 0.324528, 0.125849, 0.941879, 0.305429, 0.186299, 0.941879, 0.272663, 0.239624, 0.941879, 0.227183, 0.282115, 0.941879, 0.171689, 0.311482, 0.941879, 0.110131, 0.327223, 0.941879, 0.046835, 0.330275, 0.940015, -0.015629, 0.321019, 0.936074, -0.078439, 0.298514, 0.932588, -0.141395, 0.262408, 0.930609, -0.200460, 0.214110, 0.930383, -0.251380, 0.156699, 0.931939, -0.290738, 0.094306, 0.935081, -0.316676, 0.031210, 0.939444, -0.329131, -0.022186, 0.970473, -0.233969, -0.067039, 0.970473, -0.225115, -0.111392, 0.970473, -0.206677, -0.152203, 0.970473, -0.178699, -0.186537, 0.970473, -0.142501, -0.212204, 0.970473, -0.100513, -0.228202, 0.970473, -0.055760, -0.234724, 0.970473, -0.011110, -0.232283, 0.970473, 0.033293, -0.220721, 0.970473, 0.078288, -0.199593, 0.970473, 0.122048, -0.169285, 0.970473, 0.161497, -0.131439, 0.970473, 0.193828, -0.088685, 0.970473, 0.217120, -0.044066, 0.970473, 0.230696, 0.000115, 0.970473, 0.235054, 0.044498, 0.970473, 0.230696, 0.089462, 0.970473, 0.217120, 0.132434, 0.970473, 0.193828, 0.170341, 0.970473, 0.161497, 0.200547, 0.970473, 0.122048, 0.221423, 0.970473, 0.078288, 0.232612, 0.970473, 0.033293, 0.234782, 0.969068, -0.011110, 0.228202, 0.966096, -0.055760, 0.212204, 0.963468, -0.100513, 0.186537, 0.961977, -0.142501, 0.152204, 0.961806, -0.178698, 0.111392, 0.962979, -0.206676, 0.067039, 0.965348, -0.225115, 0.022186, 0.968638, -0.233969, -0.013192, 0.988931, -0.139127, -0.039864, 0.988931, -0.133862, -0.066238, 0.988931, -0.122898, -0.090506, 0.988931, -0.106261, -0.110922, 0.988931, -0.084737, -0.126184, 0.988931, -0.059769, -0.135698, 0.988931, -0.033157, -0.139574, 0.988931, -0.006607, -0.138114, 0.988931, 0.019797, -0.131227, 0.988931, 0.046553, -0.118655, 0.988931, 0.072574, -0.100630, 0.988931, 0.096032, -0.078128, 0.988931, 0.115257, -0.052711, 0.988931, 0.129108, -0.026190, 0.988931, 0.137181, 0.000072, 0.988931, 0.139772, 0.026460, 0.988931, 0.137181, 0.053198, 0.988931, 0.129108, 0.078750, 0.988931, 0.115257, 0.101291, 0.988931, 0.096032, 0.119253, 0.988931, 0.072575, 0.131666, 0.988931, 0.046553, 0.138320, 0.988931, 0.019797, 0.139610, 0.988051, -0.006606, 0.135698, 0.986191, -0.033157, 0.126184, 0.984546, -0.059769, 0.110922, 0.983612, -0.084736, 0.090506, 0.983505, -0.106261, 0.066238, 0.984240, -0.122898, 0.039864, 0.985722, -0.133862, 0.013193, 0.987782, -0.139127, 0, -1.641960, -0.106933, 0, -1.641960, -0.106933, 0, -1.641960, -0.106933, 0, -1.641960, -0.106933, 0, -1.641960, -0.106933, 0, -1.641960, -0.106933, 0, -1.641960, -0.106933, 0, -1.641960, -0.106933, 0, -1.641960, -0.106933, 0, -1.641960, -0.106933, 0, -1.641960, -0.106933, 0, -1.641960, -0.106933, 0, -1.641960, -0.106933, 0, -1.641960, -0.106933, 0, -1.641960, -0.106933, 0, -1.641960, -0.106933, 0, -1.641960, -0.106933, 0, -1.641960, -0.106933, 0, -1.641960, -0.106933, 0, -1.641960, -0.106933, 0, -1.641960, -0.106933, 0, -1.641960, -0.106933, 0, -1.641960, -0.106933, 0, -1.641960, -0.106933, 0, -1.641960, -0.106933, 0, -1.641960, -0.106933, 0, -1.641960, -0.106933, 0, -1.641960, -0.106933, 0, -1.641960, -0.106933, 0, -1.641960, -0.106933, 0, -1.641960, -0.106933, 0, -1.641960, -0.106933, 0, -1.653076, -0.193730, -0.009561, -1.635986, -0.191469, -0.019330, -1.618526, -0.185543, -0.028676, -1.601821, -0.175761, -0.036919, -1.587088, -0.162432, -0.043473, -1.575374, -0.146365, -0.047981, -1.567317, -0.128721, -0.050368, -1.563050, -0.110745, -0.050817, -1.562185, -0.093438, -0.049433, -1.563014, -0.075877, -0.045994, -1.565077, -0.058309, -0.040436, -1.568410, -0.041931, -0.032976, -1.572885, -0.027956, -0.024099, -1.578209, -0.017342, -0.014457, -1.583992, -0.010583, -0.004721, -1.589831, -0.007651, 0.004721, -1.589831, -0.007651, 0.014457, -1.583992, -0.010583, 0.024099, -1.578209, -0.017342, 0.032976, -1.572885, -0.027955, 0.040436, -1.568410, -0.041931, 0.045994, -1.565077, -0.058309, 0.049433, -1.563015, -0.075877, 0.050817, -1.562185, -0.093438, 0.050368, -1.563050, -0.110744, 0.047981, -1.567317, -0.128721, 0.043473, -1.575374, -0.146365, 0.036919, -1.587088, -0.162432, 0.028677, -1.601821, -0.175761, 0.019330, -1.618526, -0.185543, 0.009562, -1.635986, -0.191469, 0, -1.653076, -0.193730, 0, -1.647693, -0.282335, -0.020175, -1.614833, -0.277819, -0.040789, -1.581259, -0.265879, -0.060509, -1.549139, -0.246127, -0.077902, -1.520811, -0.219182, -0.091732, -1.498286, -0.186683, -0.101243, -1.482795, -0.150973, -0.106281, -1.474589, -0.114579, -0.107227, -1.472926, -0.079527, -0.104308, -1.474521, -0.043951, -0.097051, -1.478487, -0.008349, -0.085323, -1.484896, 0.024853, -0.069582, -1.493500, 0.053198, -0.050851, -1.503736, 0.074743, -0.030505, -1.514857, 0.088483, -0.009961, -1.526084, 0.094472, 0.009961, -1.526084, 0.094472, 0.030505, -1.514857, 0.088483, 0.050851, -1.503736, 0.074743, 0.069582, -1.493500, 0.053198, 0.085323, -1.484896, 0.024854, 0.097051, -1.478487, -0.008349, 0.104308, -1.474521, -0.043951, 0.107227, -1.472926, -0.079527, 0.106281, -1.474589, -0.114578, 0.101243, -1.482795, -0.150973, 0.091732, -1.498285, -0.186682, 0.077902, -1.520811, -0.219182, 0.060510, -1.549139, -0.246127, 0.040789, -1.581259, -0.265878, 0.020176, -1.614832, -0.277819, 0, -1.647693, -0.282335, 0, -1.624238, -0.371504, -0.031777, -1.577312, -0.364774, -0.064243, -1.529368, -0.346820, -0.095304, -1.483500, -0.317052, -0.122698, -1.443047, -0.276396, -0.144481, -1.410879, -0.227325, -0.159461, -1.388758, -0.173379, -0.167396, -1.377041, -0.118375, -0.168886, -1.374665, -0.065384, -0.164288, -1.376943, -0.011582, -0.152859, -1.382607, 0.042276, -0.134387, -1.391760, 0.092523, -0.109595, -1.404045, 0.135441, -0.080092, -1.418664, 0.168089, -0.048046, -1.434543, 0.188942, -0.015689, -1.450577, 0.198078, 0.015689, -1.450577, 0.198078, 0.048046, -1.434544, 0.188942, 0.080092, -1.418664, 0.168089, 0.109594, -1.404045, 0.135441, 0.134387, -1.391760, 0.092523, 0.152859, -1.382607, 0.042277, 0.164288, -1.376943, -0.011581, 0.168886, -1.374665, -0.065383, 0.167396, -1.377041, -0.118375, 0.159461, -1.388758, -0.173379, 0.144481, -1.410879, -0.227324, 0.122699, -1.443046, -0.276396, 0.095305, -1.483499, -0.317052, 0.064244, -1.529367, -0.346820, 0.031777, -1.577312, -0.364773, 0, -1.624237, -0.371504, 0, -1.581532, -0.459816, -0.044260, -1.522627, -0.450953, -0.089481, -1.462443, -0.427086, -0.132744, -1.404864, -0.387415, -0.170899, -1.354083, -0.333171, -0.201239, -1.313704, -0.267650, -0.222104, -1.285935, -0.195582, -0.233156, -1.271225, -0.122069, -0.235231, -1.268244, -0.051219, -0.228827, -1.271103, 0.020736, -0.212908, -1.278213, 0.092791, -0.187180, -1.289703, 0.160040, -0.152648, -1.305124, 0.217512, -0.111556, -1.323475, 0.261267, -0.066920, -1.343409, 0.289260, -0.021852, -1.363536, 0.301587, 0.021852, -1.363536, 0.301587, 0.066920, -1.343409, 0.289261, 0.111556, -1.323475, 0.261267, 0.152648, -1.305124, 0.217512, 0.187180, -1.289703, 0.160040, 0.212908, -1.278213, 0.092791, 0.228827, -1.271103, 0.020737, 0.235231, -1.268244, -0.051218, 0.233156, -1.271225, -0.122068, 0.222104, -1.285935, -0.195581, 0.201239, -1.313703, -0.267649, 0.170900, -1.354082, -0.333171, 0.132744, -1.404863, -0.387415, 0.089481, -1.462442, -0.427085, 0.044261, -1.522626, -0.450953, 0.000001, -1.581532, -0.459816, 0, -1.518921, -0.545728, -0.057478, -1.450470, -0.534855, -0.116205, -1.380534, -0.505281, -0.172388, -1.313624, -0.455997, -0.221939, -1.254614, -0.388523, -0.261340, -1.207692, -0.306959, -0.288436, -1.175423, -0.217195, -0.302789, -1.158330, -0.125591, -0.305484, -1.154865, -0.037270, -0.297168, -1.158188, 0.052457, -0.276494, -1.166449, 0.142338, -0.243082, -1.179801, 0.226261, -0.198237, -1.197722, 0.298021, -0.144873, -1.219046, 0.352702, -0.086906, -1.242211, 0.387744, -0.028378, -1.265599, 0.403256, 0.028378, -1.265599, 0.403256, 0.086906, -1.242210, 0.387744, 0.144872, -1.219047, 0.352702, 0.198237, -1.197722, 0.298022, 0.243082, -1.179801, 0.226261, 0.276494, -1.166449, 0.142339, 0.297167, -1.158188, 0.052458, 0.305484, -1.154865, -0.037269, 0.302789, -1.158330, -0.125590, 0.288436, -1.175423, -0.217194, 0.261340, -1.207691, -0.306958, 0.221940, -1.254614, -0.388522, 0.172389, -1.313623, -0.455996, 0.116205, -1.380533, -0.505281, 0.057479, -1.450469, -0.534855, 0.000001, -1.518920, -0.545728, 0, -1.436369, -0.627648, -0.071248, -1.361103, -0.614930, -0.144043, -1.284205, -0.579964, -0.213686, -1.210635, -0.521533, -0.275107, -1.145750, -0.441433, -0.323947, -1.094157, -0.344528, -0.357535, -1.058676, -0.237819, -0.375326, -1.039881, -0.128870, -0.378666, -1.036070, -0.023786, -0.368358, -1.039725, 0.083009, -0.342732, -1.048808, 0.190025, -0.301315, -1.063490, 0.289988, -0.245727, -1.083194, 0.375515, -0.179579, -1.106642, 0.440745, -0.107726, -1.132112, 0.482620, -0.035176, -1.157829, 0.501256, 0.035176, -1.157829, 0.501256, 0.107726, -1.132112, 0.482620, 0.179578, -1.106642, 0.440745, 0.245727, -1.083194, 0.375516, 0.301315, -1.063490, 0.289989, 0.342732, -1.048808, 0.190025, 0.368358, -1.039725, 0.083010, 0.378666, -1.036071, -0.023785, 0.375326, -1.039881, -0.128870, 0.357535, -1.058675, -0.237818, 0.323948, -1.094156, -0.344527, 0.275108, -1.145750, -0.441432, 0.213687, -1.210634, -0.521532, 0.144044, -1.284204, -0.579963, 0.071249, -1.361102, -0.614930, 0.000001, -1.436368, -0.627648, 0, -1.334520, -0.704021, -0.085355, -1.255394, -0.689660, -0.172562, -1.174549, -0.649719, -0.255994, -1.097205, -0.582786, -0.329576, -1.028992, -0.490902, -0.388086, -0.974752, -0.379647, -0.428323, -0.937450, -0.257062, -0.449638, -0.917691, -0.131843, -0.453639, -0.913686, -0.011015, -0.441289, -0.917527, 0.111824, -0.410590, -0.927077, 0.234961, -0.360973, -0.942511, 0.350036, -0.294379, -0.963227, 0.448552, -0.215134, -0.987878, 0.523758, -0.129055, -1.014654, 0.572124, -0.042141, -1.041690, 0.593768, 0.042141, -1.041690, 0.593769, 0.129054, -1.014654, 0.572124, 0.215133, -0.987877, 0.523758, 0.294378, -0.963227, 0.448552, 0.360973, -0.942511, 0.350037, 0.410589, -0.927077, 0.234962, 0.441289, -0.917527, 0.111825, 0.453639, -0.913686, -0.011014, 0.449638, -0.917691, -0.131842, 0.428324, -0.937450, -0.257061, 0.388087, -0.974751, -0.379646, 0.329577, -1.028992, -0.490901, 0.255995, -1.097204, -0.582784, 0.172563, -1.174549, -0.649719, 0.085356, -1.255392, -0.689659, 0.000001, -1.334519, -0.704021, 0, -1.214707, -0.773419, -0.099564, -1.134802, -0.757649, -0.201288, -1.053162, -0.713248, -0.298609, -0.975056, -0.638612, -0.384440, -0.906172, -0.536008, -0.452690, -0.851397, -0.411662, -0.499625, -0.813729, -0.274565, -0.524488, -0.793775, -0.134452, -0.529155, -0.789730, 0.000809, -0.514750, -0.793609, 0.138371, -0.478940, -0.803253, 0.276320, -0.421063, -0.818840, 0.405297, -0.343383, -0.839759, 0.515784, -0.250947, -0.864652, 0.600210, -0.150538, -0.891692, 0.654607, -0.049156, -0.918995, 0.679091, 0.049156, -0.918995, 0.679091, 0.150538, -0.891692, 0.654607, 0.250946, -0.864652, 0.600210, 0.343383, -0.839759, 0.515784, 0.421063, -0.818840, 0.405298, 0.478940, -0.803253, 0.276320, 0.514750, -0.793610, 0.138372, 0.529155, -0.789730, 0.000810, 0.524488, -0.793775, -0.134450, 0.499626, -0.813729, -0.274564, 0.452691, -0.851397, -0.411660, 0.384441, -0.906171, -0.536007, 0.298610, -0.975055, -0.638611, 0.201289, -1.053161, -0.713247, 0.099565, -1.134801, -0.757648, 0.000001, -1.214706, -0.773419, 0, -1.078898, -0.834629, -0.113633, -1.001322, -0.817708, -0.229732, -0.922063, -0.769438, -0.340805, -0.846235, -0.688037, -0.438765, -0.779359, -0.575963, -0.516659, -0.726181, -0.440013, -0.570227, -0.689611, -0.290022, -0.598602, -0.670240, -0.136649, -0.603929, -0.666313, 0.011480, -0.587489, -0.670079, 0.162187, -0.546618, -0.679441, 0.313379, -0.480563, -0.694573, 0.454807, -0.391906, -0.714883, 0.576039, -0.286407, -0.739050, 0.668770, -0.171810, -0.765302, 0.728634, -0.056102, -0.791808, 0.755737, 0.056102, -0.791808, 0.755737, 0.171810, -0.765302, 0.728634, 0.286407, -0.739050, 0.668770, 0.391906, -0.714883, 0.576039, 0.480563, -0.694573, 0.454808, 0.546618, -0.679441, 0.313380, 0.587488, -0.670079, 0.162188, 0.603929, -0.666313, 0.011481, 0.598602, -0.670240, -0.136648, 0.570227, -0.689611, -0.290021, 0.516660, -0.726181, -0.440012, 0.438766, -0.779358, -0.575962, 0.340806, -0.846234, -0.688036, 0.229733, -0.922062, -0.769437, 0.113634, -1.001321, -0.817708, 0.000002, -1.078897, -0.834629, 0, -0.929589, -0.886719, -0.127326, -0.857373, -0.868925, -0.257416, -0.783590, -0.817434, -0.381874, -0.713002, -0.730307, -0.491639, -0.650746, -0.610158, -0.578920, -0.601243, -0.464268, -0.638943, -0.567200, -0.303198, -0.670738, -0.549167, -0.138404, -0.676707, -0.545511, 0.020832, -0.658285, -0.549017, 0.182905, -0.612489, -0.557733, 0.345567, -0.538474, -0.571819, 0.497803, -0.439134, -0.590725, 0.628388, -0.320921, -0.613223, 0.728379, -0.192515, -0.637661, 0.793059, -0.062863, -0.662335, 0.822521, 0.062862, -0.662335, 0.822521, 0.192514, -0.637661, 0.793059, 0.320921, -0.613223, 0.728379, 0.439133, -0.590725, 0.628389, 0.538474, -0.571819, 0.497803, 0.612489, -0.557733, 0.345568, 0.658285, -0.549017, 0.182906, 0.676706, -0.545511, 0.020833, 0.670738, -0.549167, -0.138403, 0.638943, -0.567200, -0.303197, 0.578921, -0.601243, -0.464266, 0.491640, -0.650746, -0.610156, 0.381876, -0.713001, -0.730306, 0.257418, -0.783589, -0.817433, 0.127328, -0.857372, -0.868924, 0.000002, -0.929588, -0.886719, 0, -0.769657, -0.929088, -0.140427, -0.705655, -0.910703, -0.283902, -0.640263, -0.856676, -0.421167, -0.577702, -0.764927, -0.542225, -0.522527, -0.638190, -0.638487, -0.478654, -0.484142, -0.704686, -0.448482, -0.313940, -0.739752, -0.432500, -0.139701, -0.746335, -0.429259, 0.028748, -0.726018, -0.432367, 0.200270, -0.675510, -0.440091, 0.372491, -0.593880, -0.452576, 0.533758, -0.484318, -0.469331, 0.672190, -0.353942, -0.489271, 0.778306, -0.212323, -0.510929, 0.847091, -0.069331, -0.532798, 0.878620, 0.069331, -0.532798, 0.878620, 0.212323, -0.510929, 0.847091, 0.353942, -0.489271, 0.778306, 0.484317, -0.469332, 0.672191, 0.593879, -0.452576, 0.533759, 0.675510, -0.440091, 0.372492, 0.726018, -0.432367, 0.200271, 0.746335, -0.429259, 0.028750, 0.739752, -0.432499, -0.139699, 0.704686, -0.448482, -0.313939, 0.638488, -0.478653, -0.484141, 0.542226, -0.522526, -0.638188, 0.421168, -0.577701, -0.764926, 0.283904, -0.640262, -0.856675, 0.140429, -0.705654, -0.910702, 0.000002, -0.769656, -0.929088, 0, -0.602187, -0.961483, -0.152749, -0.548988, -0.942784, -0.308813, -0.494634, -0.886916, -0.458121, -0.442634, -0.791675, -0.589802, -0.396772, -0.659879, -0.694510, -0.360305, -0.499509, -0.766517, -0.335226, -0.322183, -0.804660, -0.321942, -0.140537, -0.811821, -0.319248, 0.035164, -0.789721, -0.321831, 0.214149, -0.734781, -0.328252, 0.393947, -0.645988, -0.338629, 0.562403, -0.526813, -0.352556, 0.707115, -0.384998, -0.369130, 0.818171, -0.230953, -0.387132, 0.890315, -0.075414, -0.405309, 0.923597, 0.075414, -0.405309, 0.923597, 0.230953, -0.387132, 0.890315, 0.384998, -0.369130, 0.818171, 0.526813, -0.352556, 0.707115, 0.645988, -0.338629, 0.562404, 0.734781, -0.328252, 0.393948, 0.789721, -0.321831, 0.214150, 0.811821, -0.319248, 0.035165, 0.804661, -0.321942, -0.140536, 0.766518, -0.335226, -0.322181, 0.694511, -0.360304, -0.499507, 0.589803, -0.396772, -0.659878, 0.458123, -0.442633, -0.791674, 0.308815, -0.494634, -0.886915, 0.152751, -0.548987, -0.942784, 0.000002, -0.602186, -0.961482, 0, -0.430287, -0.983981, -0.164142, -0.390156, -0.965238, -0.331846, -0.349155, -0.908211, -0.492290, -0.309929, -0.810596, -0.633792, -0.275334, -0.675260, -0.746309, -0.247825, -0.510391, -0.823687, -0.228907, -0.327943, -0.864676, -0.218886, -0.140929, -0.872370, -0.216854, 0.040066, -0.848622, -0.218802, 0.224530, -0.789585, -0.223646, 0.409920, -0.694169, -0.231474, 0.583718, -0.566105, -0.241980, 0.733135, -0.413713, -0.254482, 0.847940, -0.248179, -0.268062, 0.922688, -0.081039, -0.281774, 0.957402, 0.081039, -0.281774, 0.957402, 0.248178, -0.268062, 0.922688, 0.413713, -0.254482, 0.847940, 0.566105, -0.241980, 0.733136, 0.694169, -0.231474, 0.583719, 0.789584, -0.223646, 0.409921, 0.848622, -0.218802, 0.224531, 0.872370, -0.216854, 0.040068, 0.864676, -0.218886, -0.140927, 0.823688, -0.228907, -0.327941, 0.746310, -0.247824, -0.510389, 0.633793, -0.275333, -0.675258, 0.492292, -0.309928, -0.810595, 0.331848, -0.349155, -0.908210, 0.164144, -0.390156, -0.965237, 0.000002, -0.430286, -0.983981, 0, -0.256932, -0.996962, -0.174498, -0.231768, -0.978423, -0.352783, -0.206058, -0.920887, -0.523350, -0.181461, -0.821971, -0.673780, -0.159768, -0.684555, -0.793397, -0.142518, -0.516951, -0.875657, -0.130655, -0.331314, -0.919231, -0.124371, -0.140902, -0.927411, -0.123098, 0.043491, -0.902165, -0.124319, 0.231508, -0.839402, -0.127356, 0.420566, -0.737967, -0.132265, 0.597911, -0.601823, -0.138853, 0.750503, -0.439816, -0.146692, 0.867893, -0.263837, -0.155208, 0.944506, -0.086152, -0.163806, 0.980330, 0.086152, -0.163806, 0.980330, 0.263837, -0.155208, 0.944506, 0.439815, -0.146692, 0.867894, 0.601822, -0.138853, 0.750503, 0.737966, -0.132265, 0.597912, 0.839402, -0.127356, 0.420567, 0.902164, -0.124319, 0.231510, 0.927411, -0.123098, 0.043492, 0.919231, -0.124371, -0.140900, 0.875657, -0.130655, -0.331312, 0.793398, -0.142518, -0.516949, 0.673782, -0.159767, -0.684554, 0.523352, -0.181460, -0.821970, 0.352785, -0.206058, -0.920886, 0.174500, -0.231768, -0.978422, 0.000003, -0.256932, -0.996962, 0, -0.084831, -1.001047, -0.183752, -0.076145, -0.982936, -0.371492, -0.067271, -0.925493, -0.551105, -0.058781, -0.826277, -0.709513, -0.051293, -0.688150, -0.835473, -0.045339, -0.519460, -0.922096, -0.041244, -0.332450, -0.967981, -0.039075, -0.140492, -0.976595, -0.038636, 0.045513, -0.950010, -0.039057, 0.235272, -0.883919, -0.040106, 0.426183, -0.777104, -0.041800, 0.605381, -0.633740, -0.044074, 0.759700, -0.463141, -0.046780, 0.878575, -0.277829, -0.049719, 0.956347, -0.090721, -0.052687, 0.992973, 0.090720, -0.052687, 0.992973, 0.277829, -0.049719, 0.956347, 0.463140, -0.046780, 0.878576, 0.633739, -0.044074, 0.759701, 0.777103, -0.041800, 0.605382, 0.883919, -0.040106, 0.426184, 0.950010, -0.039057, 0.235273, 0.976595, -0.038636, 0.045514, 0.967982, -0.039075, -0.140490, 0.922097, -0.041244, -0.332449, 0.835474, -0.045339, -0.519458, 0.709515, -0.051293, -0.688148, 0.551107, -0.058781, -0.826276, 0.371495, -0.067271, -0.925492, 0.183755, -0.076145, -0.982935, 0.000003, -0.084831, -1.001048, 0, 0.046030, -0.998940, -0.201401, 0.057787, -0.981136, -0.407173, 0.069798, -0.924009, -0.604037, 0.081289, -0.825094, -0.777660, 0.091424, -0.687232, -0.915718, 0.099483, -0.518754, -1.010661, 0.105025, -0.331890, -1.060953, 0.107960, -0.140008, -1.070394, 0.108511, 0.045982, -1.041255, 0.106810, 0.235777, -0.968817, 0.102582, 0.426776, -0.851743, 0.095748, 0.606118, -0.694609, 0.086576, 0.760629, -0.507624, 0.075661, 0.879733, -0.304514, 0.063806, 0.957753, -0.099434, 0.051835, 0.994630, 0.099434, 0.051835, 0.994630, 0.304514, 0.063805, 0.957753, 0.507623, 0.075661, 0.879733, 0.694608, 0.086576, 0.760629, 0.851742, 0.095748, 0.606118, 0.968816, 0.102582, 0.426777, 1.041255, 0.106810, 0.235778, 1.070394, 0.108511, 0.045983, 1.060953, 0.107960, -0.140007, 1.010661, 0.105025, -0.331888, 0.915719, 0.099483, -0.518752, 0.777662, 0.091424, -0.687230, 0.604040, 0.081289, -0.825092, 0.407176, 0.069798, -0.924008, 0.201404, 0.057787, -0.981136, 0.000003, 0.046031, -0.998940, 0, 0.140157, -0.990129, -0.225629, 0.174216, -0.972483, -0.456155, 0.209014, -0.915859, -0.676701, 0.242306, -0.817817, -0.871210, 0.271667, -0.681171, -1.025877, 0.295015, -0.514178, -1.132241, 0.311071, -0.328963, -1.188583, 0.319575, -0.138773, -1.199160, 0.321172, 0.045576, -1.166516, 0.316244, 0.233697, -1.085363, 0.303994, 0.423012, -0.954205, 0.284196, 0.600772, -0.778168, 0.257623, 0.753920, -0.568690, 0.226001, 0.871973, -0.341146, 0.191653, 0.949305, -0.111396, 0.156972, 0.985857, 0.111396, 0.156972, 0.985857, 0.341146, 0.191653, 0.949305, 0.568689, 0.226001, 0.871974, 0.778167, 0.257622, 0.753921, 0.954204, 0.284196, 0.600772, 1.085363, 0.303994, 0.423013, 1.166515, 0.316244, 0.233698, 1.199160, 0.321172, 0.045577, 1.188583, 0.319576, -0.138772, 1.132241, 0.311071, -0.328961, 1.025878, 0.295015, -0.514176, 0.871212, 0.271668, -0.681169, 0.676704, 0.242306, -0.817815, 0.456158, 0.209014, -0.915858, 0.225632, 0.174216, -0.972482, 0.000003, 0.140157, -0.990129, 0, 0.236027, -0.971747, -0.245683, 0.290342, -0.954427, -0.496698, 0.345837, -0.898856, -0.736847, 0.398929, -0.802633, -0.948644, 0.445754, -0.668524, -1.117057, 0.482986, -0.504632, -1.232874, 0.508591, -0.322855, -1.294225, 0.522155, -0.136197, -1.305741, 0.524701, 0.044730, -1.270196, 0.516842, 0.229358, -1.181830, 0.497307, 0.415158, -1.039015, 0.465733, 0.589618, -0.847332, 0.423355, 0.739923, -0.619235, 0.372928, 0.855784, -0.371467, 0.318151, 0.931681, -0.121297, 0.262843, 0.967554, 0.121296, 0.262843, 0.967554, 0.371467, 0.318151, 0.931681, 0.619234, 0.372927, 0.855785, 0.847331, 0.423355, 0.739923, 1.039014, 0.465733, 0.589618, 1.181830, 0.497306, 0.415159, 1.270196, 0.516842, 0.229359, 1.305741, 0.524701, 0.044731, 1.294225, 0.522155, -0.136195, 1.232875, 0.508592, -0.322853, 1.117058, 0.482987, -0.504630, 0.948646, 0.445754, -0.668523, 0.736850, 0.398930, -0.802632, 0.496701, 0.345838, -0.898855, 0.245686, 0.290343, -0.954427, 0.000004, 0.236027, -0.971747, 0, 0.332242, -0.943194, -0.260845, 0.404246, -0.926384, -0.527351, 0.477813, -0.872445, -0.782320, 0.548195, -0.779050, -1.007187, 0.610268, -0.648881, -1.185993, 0.659626, -0.489805, -1.308959, 0.693569, -0.313369, -1.374095, 0.711550, -0.132195, -1.386322, 0.714925, 0.043416, -1.348583, 0.704507, 0.222619, -1.254764, 0.678609, 0.402960, -1.103135, 0.636753, 0.572293, -0.899623, 0.580576, 0.718182, -0.657450, 0.513726, 0.830639, -0.394392, 0.441110, 0.904306, -0.128782, 0.367791, 0.939124, 0.128782, 0.367791, 0.939124, 0.394391, 0.441110, 0.904306, 0.657449, 0.513725, 0.830639, 0.899622, 0.580575, 0.718183, 1.103135, 0.636753, 0.572294, 1.254764, 0.678609, 0.402961, 1.348583, 0.704507, 0.222620, 1.386322, 0.714925, 0.043417, 1.374095, 0.711550, -0.132193, 1.308959, 0.693569, -0.313367, 1.185995, 0.659626, -0.489803, 1.007189, 0.610268, -0.648880, 0.782323, 0.548196, -0.779048, 0.527354, 0.477814, -0.872444, 0.260848, 0.404247, -0.926384, 0.000004, 0.332243, -0.943194, 0, 0.427228, -0.904144, -0.270475, 0.513855, -0.888030, -0.546821, 0.602362, -0.836324, -0.811204, 0.687038, -0.746795, -1.044374, 0.761716, -0.622016, -1.229782, 0.821098, -0.469526, -1.357288, 0.861935, -0.300395, -1.424829, 0.883567, -0.126722, -1.437508, 0.887627, 0.041618, -1.398375, 0.875094, 0.213402, -1.301092, 0.843937, 0.386276, -1.143865, 0.793581, 0.548599, -0.932839, 0.725994, 0.688448, -0.681724, 0.645568, 0.796249, -0.408953, 0.558206, 0.866865, -0.133537, 0.469997, 0.900243, 0.133537, 0.469997, 0.900243, 0.408953, 0.558206, 0.866865, 0.681723, 0.645568, 0.796249, 0.932838, 0.725994, 0.688448, 1.143864, 0.793581, 0.548600, 1.301092, 0.843937, 0.386277, 1.398375, 0.875094, 0.213403, 1.437507, 0.887627, 0.041619, 1.424829, 0.883567, -0.126720, 1.357288, 0.861935, -0.300393, 1.229784, 0.821099, -0.469524, 1.044376, 0.761717, -0.622015, 0.811207, 0.687039, -0.746794, 0.546825, 0.602363, -0.836323, 0.270479, 0.513856, -0.888029, 0.000004, 0.427230, -0.904144, 0, 0.519304, -0.854590, -0.274062, 0.617046, -0.839359, -0.554073, 0.716911, -0.790487, -0.821961, 0.812452, -0.705865, -1.058223, 0.896713, -0.587925, -1.246090, 0.963715, -0.443792, -1.375286, 1.009791, -0.283931, -1.443723, 1.034199, -0.119776, -1.456570, 1.038781, 0.039337, -1.416919, 1.024639, 0.201706, -1.318346, 0.989484, 0.365105, -1.159033, 0.932666, 0.518532, -0.945209, 0.856407, 0.650715, -0.690764, 0.765661, 0.752608, -0.414376, 0.667089, 0.819354, -0.135308, 0.567560, 0.850902, 0.135308, 0.567560, 0.850902, 0.414376, 0.667089, 0.819354, 0.690763, 0.765661, 0.752608, 0.945208, 0.856407, 0.650716, 1.159032, 0.932666, 0.518532, 1.318345, 0.989484, 0.365106, 1.416918, 1.024639, 0.201707, 1.456570, 1.038781, 0.039338, 1.443723, 1.034199, -0.119775, 1.375287, 1.009792, -0.283929, 1.246092, 0.963715, -0.443790, 1.058226, 0.896714, -0.587923, 0.821964, 0.812453, -0.705864, 0.554076, 0.716912, -0.790486, 0.274066, 0.617048, -0.839358, 0.000004, 0.519305, -0.854590, 0, 0.606760, -0.794885, -0.271260, 0.711758, -0.780718, -0.548407, 0.819034, -0.735260, -0.813557, 0.921667, -0.656551, -1.047403, 1.012182, -0.546850, -1.233349, 1.084157, -0.412787, -1.361224, 1.133654, -0.264094, -1.428961, 1.159873, -0.111408, -1.441677, 1.164795, 0.036589, -1.402431, 1.149604, 0.187614, -1.304866, 1.111839, 0.339598, -1.147182, 1.050804, 0.482305, -0.935544, 0.968885, 0.605254, -0.683701, 0.871403, 0.700028, -0.410139, 0.765514, 0.762111, -0.133924, 0.658599, 0.791455, 0.133924, 0.658599, 0.791455, 0.410139, 0.765514, 0.762111, 0.683700, 0.871403, 0.700028, 0.935543, 0.968884, 0.605255, 1.147181, 1.050804, 0.482306, 1.304865, 1.111839, 0.339598, 1.402430, 1.149604, 0.187615, 1.441677, 1.164795, 0.036590, 1.428961, 1.159873, -0.111407, 1.361225, 1.133654, -0.264093, 1.233350, 1.084158, -0.412786, 1.047405, 1.012183, -0.546849, 0.813560, 0.921668, -0.656550, 0.548411, 0.819036, -0.735260, 0.271264, 0.711759, -0.780717, 0.000004, 0.606762, -0.794885, 0, 0.687961, -0.725748, -0.261925, 0.796112, -0.712813, -0.529535, 0.906610, -0.671309, -0.785560, 1.012326, -0.599446, -1.011359, 1.105560, -0.499286, -1.190906, 1.179696, -0.376884, -1.314380, 1.230680, -0.241124, -1.379787, 1.257686, -0.101718, -1.392065, 1.262756, 0.033407, -1.354169, 1.247109, 0.171296, -1.259962, 1.208210, 0.310060, -1.107705, 1.145342, 0.440355, -0.903349, 1.060962, 0.552611, -0.660173, 0.960552, 0.639141, -0.396025, 0.851483, 0.695825, -0.129316, 0.741356, 0.722616, 0.129315, 0.741356, 0.722616, 0.396025, 0.851483, 0.695825, 0.660172, 0.960552, 0.639142, 0.903349, 1.060961, 0.552611, 1.107704, 1.145341, 0.440356, 1.259961, 1.208210, 0.310061, 1.354169, 1.247109, 0.171297, 1.392065, 1.262756, 0.033408, 1.379787, 1.257687, -0.101717, 1.314381, 1.230680, -0.241123, 1.190907, 1.179697, -0.376883, 1.011361, 1.105561, -0.499285, 0.785563, 1.012327, -0.599444, 0.529539, 0.906612, -0.671308, 0.261929, 0.796114, -0.712813, 0.000004, 0.687962, -0.725748, 0, 0.761436, -0.648241, -0.246134, 0.868533, -0.636687, -0.497610, 0.977954, -0.599616, -0.738199, 1.082639, -0.535427, -0.950384, 1.174964, -0.445965, -1.119107, 1.248378, -0.336634, -1.235137, 1.298865, -0.215373, -1.296600, 1.325608, -0.090855, -1.308137, 1.330628, 0.029839, -1.272527, 1.315134, 0.153002, -1.183999, 1.276614, 0.276947, -1.040921, 1.214358, 0.393327, -0.848887, 1.130801, 0.493594, -0.620371, 1.031370, 0.570884, -0.372149, 0.923364, 0.621513, -0.121519, 0.814311, 0.645444, 0.121519, 0.814311, 0.645444, 0.372149, 0.923364, 0.621513, 0.620371, 1.031370, 0.570884, 0.848886, 1.130800, 0.493594, 1.040921, 1.214358, 0.393327, 1.183998, 1.276613, 0.276948, 1.272526, 1.315133, 0.153003, 1.308137, 1.330628, 0.029840, 1.296600, 1.325608, -0.090854, 1.235138, 1.298865, -0.215372, 1.119108, 1.248379, -0.336633, 0.950386, 1.174965, -0.445963, 0.738202, 1.082640, -0.535426, 0.497613, 0.977955, -0.599615, 0.246137, 0.868534, -0.636687, 0.000004, 0.761437, -0.648241, 0, 0.825969, -0.563716, -0.224181, 0.927840, -0.553669, -0.453229, 1.031922, -0.521431, -0.672360, 1.131498, -0.465612, -0.865621, 1.219318, -0.387815, -1.019295, 1.289149, -0.292740, -1.124977, 1.337172, -0.187290, -1.180958, 1.362610, -0.079008, -1.191467, 1.367386, 0.025948, -1.159032, 1.352647, 0.133052, -1.078400, 1.316007, 0.240835, -0.948083, 1.256790, 0.342041, -0.773176, 1.177310, 0.429233, -0.565041, 1.082731, 0.496445, -0.338958, 0.979995, 0.540473, -0.110681, 0.876264, 0.561283, 0.110681, 0.876264, 0.561283, 0.338957, 0.979995, 0.540473, 0.565041, 1.082731, 0.496445, 0.773175, 1.177309, 0.429234, 0.948082, 1.256790, 0.342041, 1.078399, 1.316007, 0.240836, 1.159032, 1.352647, 0.133053, 1.191467, 1.367386, 0.025949, 1.180958, 1.362611, -0.079008, 1.124977, 1.337172, -0.187289, 1.019297, 1.289150, -0.292739, 0.865623, 1.219319, -0.387814, 0.672363, 1.131499, -0.465611, 0.453231, 1.031923, -0.521431, 0.224185, 0.927841, -0.553669, 0.000003, 0.825970, -0.563716, 0, 0.880666, -0.473738, -0.196566, 0.973313, -0.465295, -0.397398, 1.067972, -0.438203, -0.589536, 1.158533, -0.391293, -0.758990, 1.238402, -0.325914, -0.893734, 1.301911, -0.246014, -0.986397, 1.345587, -0.157396, -1.035482, 1.368722, -0.066398, -1.044697, 1.373065, 0.021806, -1.016257, 1.359661, 0.111815, -0.945558, 1.326338, 0.202395, -0.831294, 1.272481, 0.287446, -0.677933, 1.200197, 0.360722, -0.495437, 1.114181, 0.417205, -0.297203, 1.020747, 0.454206, -0.097047, 0.926407, 0.471694, 0.097047, 0.926407, 0.471694, 0.297203, 1.020747, 0.454206, 0.495436, 1.114181, 0.417206, 0.677932, 1.200197, 0.360722, 0.831293, 1.272481, 0.287446, 0.945557, 1.326338, 0.202395, 1.016257, 1.359660, 0.111816, 1.044696, 1.373065, 0.021807, 1.035483, 1.368722, -0.066397, 0.986398, 1.345587, -0.157395, 0.893735, 1.301912, -0.246013, 0.758992, 1.238403, -0.325913, 0.589538, 1.158534, -0.391293, 0.397400, 1.067973, -0.438203, 0.196568, 0.973315, -0.465295, 0.000003, 0.880667, -0.473738, 0, 0.924989, -0.379993, -0.163952, 1.004717, -0.373221, -0.331462, 1.086176, -0.351490, -0.491720, 1.164108, -0.313863, -0.633059, 1.232840, -0.261421, -0.745446, 1.287493, -0.197332, -0.822735, 1.325077, -0.126250, -0.863676, 1.344986, -0.053259, -0.871361, 1.348724, 0.017491, -0.847641, 1.337189, 0.089689, -0.788671, 1.308512, 0.162344, -0.693366, 1.262167, 0.230565, -0.565450, 1.199962, 0.289341, -0.413234, 1.125941, 0.334647, -0.247892, 1.045537, 0.364326, -0.080945, 0.964352, 0.378354, 0.080945, 0.964352, 0.378354, 0.247891, 1.045536, 0.364326, 0.413234, 1.125941, 0.334647, 0.565450, 1.199962, 0.289341, 0.693366, 1.262166, 0.230565, 0.788671, 1.308512, 0.162344, 0.847640, 1.337188, 0.089689, 0.871361, 1.348724, 0.017492, 0.863676, 1.344986, -0.053258, 0.822735, 1.325077, -0.126249, 0.745447, 1.287493, -0.197331, 0.633060, 1.232840, -0.261420, 0.491722, 1.164109, -0.313862, 0.331464, 1.086177, -0.351490, 0.163954, 1.004718, -0.373221, 0.000002, 0.924990, -0.379993, 0, 0.958769, -0.284187, -0.127126, 1.022282, -0.279122, -0.257011, 1.087174, -0.262870, -0.381273, 1.149256, -0.234730, -0.490865, 1.204009, -0.195510, -0.578009, 1.247547, -0.147580, -0.637937, 1.277488, -0.094419, -0.669682, 1.293348, -0.039831, -0.675642, 1.296325, 0.013081, -0.657249, 1.287136, 0.067076, -0.611525, 1.264292, 0.121413, -0.537627, 1.227372, 0.172434, -0.438443, 1.177819, 0.216390, -0.320416, 1.118852, 0.250274, -0.192212, 1.054800, 0.272470, -0.062764, 0.990126, 0.282961, 0.062763, 0.990126, 0.282961, 0.192211, 1.054799, 0.272470, 0.320416, 1.118852, 0.250274, 0.438442, 1.177819, 0.216391, 0.537626, 1.227372, 0.172434, 0.611525, 1.264292, 0.121413, 0.657249, 1.287136, 0.067076, 0.675642, 1.296325, 0.013082, 0.669682, 1.293348, -0.039830, 0.637938, 1.277488, -0.094418, 0.578009, 1.247547, -0.147579, 0.490866, 1.204010, -0.195509, 0.381275, 1.149257, -0.234730, 0.257013, 1.087175, -0.262870, 0.127128, 1.022283, -0.279122, 0.000002, 0.958770, -0.284187, 0, 0.982177, -0.187958, -0.086945, 1.026654, -0.184608, -0.175778, 1.072095, -0.173859, -0.260765, 1.115570, -0.155247, -0.335718, 1.153912, -0.129308, -0.395319, 1.184400, -0.097607, -0.436306, 1.205366, -0.062447, -0.458017, 1.216473, -0.026344, -0.462093, 1.218558, 0.008652, -0.449514, 1.212123, 0.044363, -0.418242, 1.196126, 0.080301, -0.367700, 1.170272, 0.114045, -0.299865, 1.135571, 0.143118, -0.219143, 1.094278, 0.165528, -0.131460, 1.049425, 0.180208, -0.042926, 1.004136, 0.187147, 0.042926, 1.004136, 0.187147, 0.131460, 1.049424, 0.180208, 0.219143, 1.094278, 0.165528, 0.299865, 1.135571, 0.143118, 0.367700, 1.170272, 0.114045, 0.418241, 1.196126, 0.080301, 0.449514, 1.212123, 0.044363, 0.462093, 1.218558, 0.008652, 0.458017, 1.216473, -0.026343, 0.436306, 1.205367, -0.062447, 0.395319, 1.184400, -0.097607, 0.335719, 1.153912, -0.129307, 0.260766, 1.115570, -0.155247, 0.175779, 1.072096, -0.173859, 0.086947, 1.026654, -0.184608, 0.000001, 0.982178, -0.187958, 0, 0.995685, -0.092798, -0.044287, 1.018816, -0.091144, -0.089535, 1.042449, -0.085837, -0.132824, 1.065059, -0.076648, -0.171003, 1.085000, -0.063841, -0.201361, 1.100856, -0.048190, -0.222238, 1.111760, -0.030831, -0.233297, 1.117536, -0.013006, -0.235373, 1.118620, 0.004272, -0.228966, 1.115274, 0.021903, -0.213037, 1.106954, 0.039646, -0.187293, 1.093508, 0.056306, -0.152740, 1.075461, 0.070659, -0.111623, 1.053986, 0.081724, -0.066961, 1.030659, 0.088971, -0.021865, 1.007105, 0.092397, 0.021865, 1.007105, 0.092397, 0.066961, 1.030658, 0.088971, 0.111623, 1.053986, 0.081724, 0.152740, 1.075461, 0.070659, 0.187293, 1.093508, 0.056306, 0.213037, 1.106954, 0.039646, 0.228966, 1.115274, 0.021903, 0.235373, 1.118620, 0.004272, 0.233297, 1.117536, -0.013006, 0.222238, 1.111760, -0.030831, 0.201361, 1.100856, -0.048190, 0.171003, 1.085000, -0.063841, 0.132825, 1.065059, -0.076648, 0.089535, 1.042449, -0.085837, 0.044287, 1.018816, -0.091144, 0.000001, 0.995685, -0.092798, 0, 1, -0.000001, -0.000001, 1, -0.000001, -0.000001, 1.000001, -0.000001, -0.000002, 1.000001, -0.000001, -0.000003, 1.000001, -0.000001, -0.000003, 1.000002, -0.000001, -0.000003, 1.000002, -0, -0.000003, 1.000002, -0, -0.000004, 1.000002, 0, -0.000003, 1.000002, 0, -0.000003, 1.000002, 0.000001, -0.000003, 1.000001, 0.000001, -0.000002, 1.000001, 0.000001, -0.000002, 1.000001, 0.000001, -0.000001, 1, 0.000001, -0, 1, 0.000001, 0, 1, 0.000001, 0.000001, 1, 0.000001, 0.000002, 1.000001, 0.000001, 0.000002, 1.000001, 0.000001, 0.000003, 1.000001, 0.000001, 0.000003, 1.000002, 0.000001, 0.000003, 1.000002, 0, 0.000004, 1.000002, 0, 0.000003, 1.000002, -0, 0.000003, 1.000002, -0, 0.000003, 1.000002, -0.000001, 0.000003, 1.000001, -0.000001, 0.000002, 1.000001, -0.000001, 0.000001, 1.000001, -0.000001, 0.000001, 1, -0.000001, 0, 1, -0.000001, -0.007434, -1.637897, -0.236338, -0.022464, -1.612651, -0.230178, -0.037326, -1.587686, -0.218328, -0.051002, -1.564715, -0.200876, -0.062507, -1.545390, -0.178666, -0.071107, -1.530943, -0.153186, -0.076468, -1.521938, -0.126254, -0.078673, -1.518187, -0.099572, -0.077946, -1.518161, -0.073198, -0.074197, -1.520275, -0.046622, -0.067201, -1.524217, -0.020934, -0.057080, -1.529923, 0.002041, -0.044377, -1.537082, 0.020661, -0.029978, -1.545198, 0.033825, -0.014911, -1.553691, 0.041180, -0, -1.557958, 0.043411, 0.014911, -1.553691, 0.041180, 0.029978, -1.545198, 0.033825, 0.044377, -1.537082, 0.020661, 0.057080, -1.529923, 0.002042, 0.067201, -1.524218, -0.020934, 0.074197, -1.520275, -0.046621, 0.077946, -1.518161, -0.073198, 0.078673, -1.518187, -0.099572, 0.076468, -1.521938, -0.126254, 0.071107, -1.530943, -0.153185, 0.062507, -1.545389, -0.178665, 0.051002, -1.564715, -0.200875, 0.037326, -1.587686, -0.218327, 0.022464, -1.612651, -0.230177, 0.007434, -1.637897, -0.236338, -0.012988, -1.616019, -0.324108, -0.039246, -1.575693, -0.313823, -0.065211, -1.535817, -0.293969, -0.089104, -1.499124, -0.264689, -0.109203, -1.468256, -0.227396, -0.124229, -1.445180, -0.184590, -0.133595, -1.430796, -0.139327, -0.137447, -1.424805, -0.094466, -0.136177, -1.424764, -0.050111, -0.129627, -1.428139, -0.005401, -0.117405, -1.434437, 0.037826, -0.099722, -1.443550, 0.076504, -0.077530, -1.454986, 0.107868, -0.052374, -1.467950, 0.130064, -0.026050, -1.481515, 0.142494, -0, -1.488331, 0.146275, 0.026050, -1.481515, 0.142494, 0.052373, -1.467950, 0.130064, 0.077530, -1.454986, 0.107868, 0.099722, -1.443550, 0.076504, 0.117405, -1.434437, 0.037826, 0.129626, -1.428139, -0.005401, 0.136177, -1.424764, -0.050111, 0.137447, -1.424805, -0.094466, 0.133595, -1.430796, -0.139326, 0.124229, -1.445179, -0.184590, 0.109204, -1.468255, -0.227396, 0.089104, -1.499124, -0.264689, 0.065212, -1.535816, -0.293969, 0.039246, -1.575693, -0.313823, 0.012988, -1.616019, -0.324108, -0.019009, -1.576427, -0.411761, -0.057440, -1.522938, -0.397408, -0.095443, -1.470044, -0.369593, -0.130411, -1.421373, -0.328509, -0.159829, -1.380428, -0.276135, -0.181821, -1.349819, -0.215984, -0.195529, -1.330740, -0.152351, -0.201167, -1.322794, -0.089262, -0.199308, -1.322739, -0.026862, -0.189721, -1.327216, 0.036055, -0.171833, -1.335570, 0.096908, -0.145952, -1.347658, 0.151379, -0.113473, -1.362827, 0.195577, -0.076654, -1.380023, 0.226890, -0.038127, -1.398016, 0.244467, -0, -1.407057, 0.249832, 0.038127, -1.398016, 0.244467, 0.076653, -1.380023, 0.226890, 0.113473, -1.362827, 0.195577, 0.145952, -1.347658, 0.151379, 0.171833, -1.335570, 0.096908, 0.189720, -1.327216, 0.036056, 0.199308, -1.322739, -0.026862, 0.201167, -1.322794, -0.089261, 0.195529, -1.330740, -0.152351, 0.181821, -1.349819, -0.215983, 0.159830, -1.380428, -0.276135, 0.130412, -1.421373, -0.328508, 0.095443, -1.470043, -0.369593, 0.057441, -1.522937, -0.397408, 0.019010, -1.576427, -0.411761, -0.025435, -1.518388, -0.497838, -0.076856, -1.454018, -0.479544, -0.127704, -1.390366, -0.443945, -0.174493, -1.331796, -0.391277, -0.213854, -1.282523, -0.324076, -0.243280, -1.245688, -0.246846, -0.261621, -1.222728, -0.165109, -0.269165, -1.213166, -0.084037, -0.266677, -1.213100, -0.003824, -0.253849, -1.218488, 0.077081, -0.229916, -1.228541, 0.155358, -0.195287, -1.243087, 0.225459, -0.151828, -1.261342, 0.282376, -0.102564, -1.282035, 0.322744, -0.051014, -1.303689, 0.345462, -0, -1.314568, 0.352421, 0.051014, -1.303689, 0.345462, 0.102564, -1.282035, 0.322744, 0.151828, -1.261342, 0.282376, 0.195286, -1.243088, 0.225459, 0.229916, -1.228541, 0.155358, 0.253849, -1.218488, 0.077081, 0.266677, -1.213100, -0.003823, 0.269165, -1.213166, -0.084037, 0.261621, -1.222728, -0.165108, 0.243280, -1.245688, -0.246846, 0.213855, -1.282523, -0.324075, 0.174493, -1.331796, -0.391276, 0.127705, -1.390365, -0.443944, 0.076857, -1.454017, -0.479544, 0.025435, -1.518387, -0.497838, -0.032182, -1.441716, -0.580791, -0.097244, -1.369078, -0.558758, -0.161580, -1.297249, -0.515694, -0.220780, -1.231156, -0.451872, -0.270583, -1.175553, -0.370361, -0.307814, -1.133987, -0.276625, -0.331021, -1.108077, -0.177369, -0.340566, -1.097286, -0.078879, -0.337419, -1.097212, 0.018603, -0.321188, -1.103293, 0.116957, -0.290906, -1.114637, 0.212153, -0.247090, -1.131052, 0.297447, -0.192104, -1.151651, 0.366746, -0.129771, -1.175003, 0.415953, -0.064547, -1.199437, 0.443719, -0, -1.211714, 0.452256, 0.064546, -1.199438, 0.443719, 0.129771, -1.175003, 0.415953, 0.192104, -1.151651, 0.366746, 0.247090, -1.131052, 0.297447, 0.290905, -1.114637, 0.212154, 0.321188, -1.103293, 0.116958, 0.337419, -1.097212, 0.018603, 0.340566, -1.097286, -0.078878, 0.331022, -1.108077, -0.177368, 0.307815, -1.133986, -0.276624, 0.270584, -1.175553, -0.370360, 0.220781, -1.231155, -0.451871, 0.161581, -1.297248, -0.515693, 0.097244, -1.369077, -0.558757, 0.032183, -1.441715, -0.580790, -0.039151, -1.346847, -0.659065, -0.118302, -1.268813, -0.633568, -0.196571, -1.191648, -0.583500, -0.268591, -1.120646, -0.509164, -0.329179, -1.060913, -0.414128, -0.374473, -1.016259, -0.304764, -0.402705, -0.988425, -0.188899, -0.414317, -0.976832, -0.073878, -0.410488, -0.976752, 0.040008, -0.390742, -0.983284, 0.154955, -0.353902, -0.995472, 0.266253, -0.300598, -1.013106, 0.366023, -0.233704, -1.035235, 0.447143, -0.157873, -1.060321, 0.504811, -0.078524, -1.086571, 0.537442, -0, -1.099760, 0.547512, 0.078524, -1.086571, 0.537442, 0.157873, -1.060321, 0.504812, 0.233704, -1.035235, 0.447143, 0.300598, -1.013105, 0.366023, 0.353902, -0.995472, 0.266253, 0.390742, -0.983284, 0.154955, 0.410488, -0.976752, 0.040009, 0.414317, -0.976832, -0.073878, 0.402705, -0.988424, -0.188898, 0.374473, -1.016258, -0.304763, 0.329180, -1.060912, -0.414126, 0.268592, -1.120645, -0.509163, 0.196572, -1.191648, -0.583500, 0.118303, -1.268812, -0.633568, 0.039152, -1.346845, -0.659065, -0.046230, -1.234856, -0.731187, -0.139692, -1.154477, -0.702569, -0.232113, -1.074993, -0.646091, -0.317155, -1.001856, -0.562077, -0.388698, -0.940328, -0.454555, -0.442181, -0.894332, -0.330734, -0.475518, -0.865661, -0.199480, -0.489230, -0.853721, -0.069125, -0.484708, -0.853638, 0.059997, -0.461392, -0.860367, 0.190369, -0.417891, -0.872920, 0.316654, -0.354950, -0.891084, 0.429917, -0.275961, -0.913879, 0.522076, -0.186418, -0.939719, 0.587675, -0.092722, -0.966758, 0.624898, -0, -0.980343, 0.636430, 0.092722, -0.966758, 0.624898, 0.186418, -0.939719, 0.587675, 0.275960, -0.913879, 0.522076, 0.354949, -0.891084, 0.429918, 0.417891, -0.872920, 0.316654, 0.461392, -0.860367, 0.190370, 0.484708, -0.853638, 0.059998, 0.489230, -0.853721, -0.069124, 0.475519, -0.865661, -0.199479, 0.442182, -0.894332, -0.330733, 0.388699, -0.940328, -0.454554, 0.317156, -1.001856, -0.562076, 0.232114, -1.074992, -0.646090, 0.139693, -1.154476, -0.702568, 0.046231, -1.234854, -0.731187, -0.053299, -1.107432, -0.795851, -0.161054, -1.027837, -0.764511, -0.267609, -0.949129, -0.702334, -0.365655, -0.876705, -0.609655, -0.448139, -0.815777, -0.490912, -0.509800, -0.770230, -0.354066, -0.548236, -0.741839, -0.208922, -0.564043, -0.730014, -0.064703, -0.558831, -0.729933, 0.078212, -0.531949, -0.736596, 0.222564, -0.481796, -0.749027, 0.362451, -0.409229, -0.767014, 0.487982, -0.318161, -0.789586, 0.590201, -0.214926, -0.815174, 0.663055, -0.106902, -0.841949, 0.704517, -0, -0.855401, 0.717414, 0.106901, -0.841949, 0.704517, 0.214925, -0.815174, 0.663056, 0.318161, -0.789586, 0.590201, 0.409229, -0.767014, 0.487982, 0.481796, -0.749027, 0.362451, 0.531949, -0.736596, 0.222565, 0.558831, -0.729933, 0.078213, 0.564044, -0.730015, -0.064702, 0.548236, -0.741839, -0.208921, 0.509801, -0.770229, -0.354064, 0.448139, -0.815777, -0.490910, 0.365656, -0.876705, -0.609654, 0.267610, -0.949128, -0.702333, 0.161056, -1.027836, -0.764510, 0.053301, -1.107431, -0.795851, -0.060240, -0.966795, -0.851995, -0.182027, -0.891087, -0.818376, -0.302457, -0.816222, -0.751304, -0.413271, -0.747335, -0.651116, -0.506496, -0.689382, -0.522600, -0.576187, -0.646059, -0.374375, -0.619627, -0.619055, -0.217069, -0.637494, -0.607808, -0.060685, -0.631602, -0.607730, 0.094351, -0.601220, -0.614068, 0.251009, -0.544536, -0.625892, 0.402889, -0.462519, -0.643000, 0.539259, -0.359592, -0.664470, 0.650394, -0.242913, -0.688809, 0.729711, -0.120822, -0.714276, 0.774988, -0, -0.727072, 0.789129, 0.120822, -0.714276, 0.774988, 0.242913, -0.688809, 0.729711, 0.359592, -0.664470, 0.650394, 0.462519, -0.643000, 0.539260, 0.544536, -0.625892, 0.402890, 0.601220, -0.614068, 0.251010, 0.631602, -0.607730, 0.094352, 0.637494, -0.607808, -0.060684, 0.619628, -0.619054, -0.217067, 0.576188, -0.646059, -0.374374, 0.506497, -0.689382, -0.522599, 0.413272, -0.747335, -0.651115, 0.302458, -0.816221, -0.751303, 0.182028, -0.891086, -0.818376, 0.060241, -0.966794, -0.851995, -0.066938, -0.815568, -0.898859, -0.202268, -0.746720, -0.863434, -0.336090, -0.678639, -0.792336, -0.459226, -0.615994, -0.685895, -0.562818, -0.563293, -0.549189, -0.640259, -0.523895, -0.391387, -0.688530, -0.499337, -0.223811, -0.708383, -0.489109, -0.057131, -0.701836, -0.489039, 0.108189, -0.668076, -0.494802, 0.275308, -0.605088, -0.505555, 0.437405, -0.513951, -0.521113, 0.583035, -0.399579, -0.540637, 0.701816, -0.269925, -0.562771, 0.786709, -0.134258, -0.585931, 0.835323, -0, -0.597567, 0.850570, 0.134258, -0.585931, 0.835323, 0.269925, -0.562771, 0.786709, 0.399578, -0.540638, 0.701816, 0.513951, -0.521113, 0.583035, 0.605088, -0.505555, 0.437405, 0.668075, -0.494802, 0.275309, 0.701836, -0.489039, 0.108190, 0.708383, -0.489109, -0.057130, 0.688530, -0.499337, -0.223809, 0.640259, -0.523894, -0.391386, 0.562819, -0.563292, -0.549188, 0.459228, -0.615993, -0.685894, 0.336092, -0.678638, -0.792335, 0.202270, -0.746719, -0.863434, 0.066940, -0.815568, -0.898858, -0.073294, -0.656622, -0.936014, -0.221473, -0.597385, -0.899270, -0.368001, -0.538808, -0.825049, -0.502829, -0.484909, -0.713668, -0.616256, -0.439564, -0.570430, -0.701050, -0.405667, -0.404944, -0.753904, -0.384537, -0.229090, -0.775642, -0.375737, -0.054081, -0.768474, -0.375677, 0.119583, -0.731508, -0.380635, 0.295214, -0.662540, -0.389887, 0.465650, -0.562750, -0.403273, 0.618867, -0.437518, -0.420072, 0.743945, -0.295554, -0.439115, 0.833471, -0.147005, -0.459042, 0.884906, -0, -0.469054, 0.901109, 0.147005, -0.459042, 0.884906, 0.295554, -0.439115, 0.833471, 0.437517, -0.420072, 0.743946, 0.562749, -0.403273, 0.618867, 0.662539, -0.389887, 0.465650, 0.731507, -0.380635, 0.295215, 0.768474, -0.375677, 0.119584, 0.775642, -0.375737, -0.054080, 0.753904, -0.384537, -0.229089, 0.701051, -0.405666, -0.404942, 0.616257, -0.439564, -0.570428, 0.502830, -0.484908, -0.713666, 0.368003, -0.538807, -0.825047, 0.221475, -0.597384, -0.899269, 0.073296, -0.656621, -0.936014, -0.079223, -0.492904, -0.963372, -0.239387, -0.445733, -0.925787, -0.397767, -0.399088, -0.849350, -0.543501, -0.356167, -0.734353, -0.666103, -0.320059, -0.586260, -0.757756, -0.293066, -0.415006, -0.814885, -0.276240, -0.232898, -0.838382, -0.269233, -0.051559, -0.830633, -0.269184, 0.128477, -0.790677, -0.273133, 0.310636, -0.716131, -0.280500, 0.487497, -0.608269, -0.291160, 0.646593, -0.472907, -0.304537, 0.776590, -0.319461, -0.319701, 0.869778, -0.158896, -0.335569, 0.923500, -0, -0.343542, 0.940500, 0.158896, -0.335569, 0.923501, 0.319460, -0.319701, 0.869778, 0.472907, -0.304537, 0.776590, 0.608268, -0.291160, 0.646593, 0.716130, -0.280500, 0.487498, 0.790677, -0.273133, 0.310637, 0.830633, -0.269184, 0.128478, 0.838382, -0.269232, -0.051558, 0.814885, -0.276240, -0.232896, 0.757757, -0.293065, -0.415005, 0.666104, -0.320058, -0.586258, 0.543503, -0.356167, -0.734351, 0.397769, -0.399087, -0.849348, 0.239389, -0.445733, -0.925787, 0.079225, -0.492904, -0.963371, -0.084660, -0.327286, -0.981151, -0.255817, -0.294284, -0.943190, -0.425067, -0.261651, -0.865416, -0.580803, -0.231623, -0.748095, -0.711820, -0.206361, -0.596789, -0.809762, -0.187476, -0.421650, -0.870813, -0.175705, -0.235272, -0.895922, -0.170802, -0.049568, -0.887642, -0.170768, 0.134899, -0.844943, -0.173531, 0.321631, -0.765281, -0.178685, 0.503029, -0.650016, -0.186143, 0.666317, -0.505364, -0.195502, 0.799868, -0.341386, -0.206111, 0.895757, -0.169802, -0.217212, 0.951231, -0, -0.222790, 0.968866, 0.169801, -0.217212, 0.951231, 0.341386, -0.206111, 0.895757, 0.505364, -0.195502, 0.799868, 0.650015, -0.186143, 0.666317, 0.765280, -0.178685, 0.503030, 0.844943, -0.173531, 0.321632, 0.887642, -0.170768, 0.134900, 0.895922, -0.170802, -0.049567, 0.870813, -0.175705, -0.235270, 0.809763, -0.187476, -0.421648, 0.711821, -0.206361, -0.596787, 0.580805, -0.231622, -0.748094, 0.425069, -0.261650, -0.865415, 0.255819, -0.294284, -0.943189, 0.084662, -0.327285, -0.981151, -0.089562, -0.162419, -0.989842, -0.270631, -0.145311, -0.951935, -0.449683, -0.128393, -0.873657, -0.614437, -0.112825, -0.755238, -0.753041, -0.099729, -0.602279, -0.856656, -0.089939, -0.425044, -0.921241, -0.083837, -0.236289, -0.947805, -0.081295, -0.048097, -0.939045, -0.081277, 0.138946, -0.893874, -0.082710, 0.328382, -0.809598, -0.085382, 0.512510, -0.687658, -0.089248, 0.678374, -0.534630, -0.094100, 0.814168, -0.361156, -0.099600, 0.911830, -0.179635, -0.105355, 0.968539, -0, -0.108246, 0.986652, 0.179634, -0.105355, 0.968539, 0.361155, -0.099600, 0.911830, 0.534629, -0.094100, 0.814168, 0.687658, -0.089248, 0.678375, 0.809598, -0.085382, 0.512511, 0.893874, -0.082710, 0.328383, 0.939045, -0.081277, 0.138947, 0.947805, -0.081295, -0.048096, 0.921242, -0.083837, -0.236288, 0.856656, -0.089939, -0.425042, 0.753042, -0.099729, -0.602277, 0.614439, -0.112825, -0.755237, 0.449685, -0.128392, -0.873656, 0.270634, -0.145310, -0.951934, 0.089565, -0.162419, -0.989842, -0.096288, -0.014290, -0.991015, -0.290955, -0.003958, -0.953394, -0.483452, 0.006259, -0.875218, -0.660579, 0.015660, -0.756688, -0.809591, 0.023569, -0.603399, -0.920987, 0.029481, -0.425638, -0.990423, 0.033166, -0.236210, -1.018981, 0.034690, -0.047251, -1.009564, 0.034407, 0.140636, -0.961000, 0.032557, 0.331002, -0.870396, 0.029106, 0.516114, -0.739299, 0.024113, 0.682957, -0.574778, 0.017846, 0.819659, -0.388277, 0.010742, 0.918102, -0.193125, 0.003309, 0.975426, -0, -0.000426, 0.993801, 0.193124, 0.003309, 0.975426, 0.388277, 0.010742, 0.918102, 0.574778, 0.017846, 0.819660, 0.739298, 0.024113, 0.682958, 0.870395, 0.029106, 0.516115, 0.961000, 0.032557, 0.331003, 1.009563, 0.034407, 0.140637, 1.018981, 0.034690, -0.047250, 0.990423, 0.033166, -0.236208, 0.920988, 0.029481, -0.425637, 0.809593, 0.023569, -0.603397, 0.660581, 0.015660, -0.756687, 0.483454, 0.006259, -0.875217, 0.290957, -0.003958, -0.953393, 0.096291, -0.014290, -0.991015, -0.106757, 0.104547, -0.985672, -0.322590, 0.127704, -0.948372, -0.536017, 0.150602, -0.870695, -0.732402, 0.171672, -0.752828, -0.897616, 0.189397, -0.600334, -1.021124, 0.202648, -0.423446, -1.098109, 0.210908, -0.234908, -1.129772, 0.214305, -0.046806, -1.119331, 0.213185, 0.140258, -1.065488, 0.207408, 0.329815, -0.965032, 0.196630, 0.514169, -0.819681, 0.181036, 0.680360, -0.637273, 0.161465, 0.816564, -0.430494, 0.139280, 0.914691, -0.214123, 0.116066, 0.971886, -0, 0.104403, 0.990243, 0.214122, 0.116066, 0.971886, 0.430493, 0.139280, 0.914691, 0.637272, 0.161465, 0.816564, 0.819680, 0.181036, 0.680360, 0.965031, 0.196630, 0.514170, 1.065487, 0.207408, 0.329816, 1.119331, 0.213184, 0.140259, 1.129773, 0.214305, -0.046804, 1.098110, 0.210908, -0.234907, 1.021125, 0.202648, -0.423444, 0.897618, 0.189397, -0.600332, 0.732404, 0.171672, -0.752827, 0.536019, 0.150602, -0.870694, 0.322592, 0.127704, -0.948371, 0.106761, 0.104548, -0.985672, -0.117828, 0.210185, -0.972197, -0.356041, 0.254852, -0.935406, -0.591600, 0.299022, -0.858791, -0.808351, 0.339664, -0.742536, -0.990697, 0.373856, -0.592126, -1.127012, 0.399416, -0.417657, -1.211981, 0.415348, -0.231697, -1.246927, 0.421901, -0.046166, -1.235403, 0.419740, 0.138340, -1.175976, 0.408597, 0.325306, -1.065103, 0.387807, 0.507140, -0.904680, 0.357727, 0.671058, -0.703356, 0.319977, 0.805400, -0.475135, 0.277183, 0.902186, -0.236327, 0.232405, 0.958599, -0, 0.209907, 0.976705, 0.236326, 0.232405, 0.958599, 0.475134, 0.277183, 0.902186, 0.703355, 0.319977, 0.805400, 0.904679, 0.357726, 0.671059, 1.065103, 0.387807, 0.507141, 1.175976, 0.408597, 0.325307, 1.235403, 0.419740, 0.138342, 1.246927, 0.421901, -0.046165, 1.211981, 0.415348, -0.231695, 1.127013, 0.399416, -0.417655, 0.990699, 0.373856, -0.592125, 0.808353, 0.339664, -0.742535, 0.591603, 0.299022, -0.858790, 0.356044, 0.254853, -0.935406, 0.117831, 0.210186, -0.972196, -0.126632, 0.315714, -0.948938, -0.382644, 0.379560, -0.913028, -0.635804, 0.442693, -0.838246, -0.868749, 0.500786, -0.724772, -1.064720, 0.549658, -0.577961, -1.211221, 0.586193, -0.407665, -1.302538, 0.608966, -0.226154, -1.340096, 0.618332, -0.045062, -1.327711, 0.615244, 0.135031, -1.263843, 0.599316, 0.317524, -1.144686, 0.569601, 0.495007, -0.972276, 0.526604, 0.655004, -0.755910, 0.472646, 0.786132, -0.510636, 0.411479, 0.880602, -0.253984, 0.347474, 0.935666, -0, 0.315317, 0.953339, 0.253984, 0.347474, 0.935666, 0.510635, 0.411478, 0.880603, 0.755909, 0.472646, 0.786132, 0.972275, 0.526604, 0.655005, 1.144686, 0.569600, 0.495008, 1.263843, 0.599316, 0.317525, 1.327711, 0.615244, 0.135032, 1.340096, 0.618332, -0.045060, 1.302539, 0.608966, -0.226152, 1.211222, 0.586193, -0.407663, 1.064722, 0.549659, -0.577959, 0.868752, 0.500787, -0.724770, 0.635807, 0.442694, -0.838245, 0.382648, 0.379560, -0.913027, 0.126635, 0.315715, -0.948938, -0.132830, 0.419393, -0.915438, -0.401373, 0.499569, -0.880796, -0.666924, 0.578852, -0.808653, -0.911271, 0.651804, -0.699185, -1.116834, 0.713177, -0.557557, -1.270505, 0.759057, -0.393273, -1.366292, 0.787655, -0.218170, -1.405688, 0.799417, -0.043471, -1.392697, 0.795538, 0.130264, -1.325704, 0.775537, 0.306314, -1.200714, 0.738220, 0.477532, -1.019865, 0.684226, 0.631881, -0.792909, 0.616466, 0.758379, -0.535630, 0.539653, 0.849515, -0.266416, 0.459276, 0.902634, -0, 0.418894, 0.919684, 0.266416, 0.459276, 0.902634, 0.535629, 0.539652, 0.849515, 0.792908, 0.616466, 0.758380, 1.019865, 0.684226, 0.631881, 1.200714, 0.738220, 0.477533, 1.325703, 0.775537, 0.306315, 1.392697, 0.795538, 0.130265, 1.405689, 0.799417, -0.043469, 1.366293, 0.787655, -0.218168, 1.270507, 0.759057, -0.393272, 1.116836, 0.713178, -0.557555, 0.911274, 0.651805, -0.699184, 0.666927, 0.578853, -0.808652, 0.401377, 0.499570, -0.880795, 0.132834, 0.419394, -0.915438, -0.136134, 0.519358, -0.871531, -0.411358, 0.612544, -0.838550, -0.683515, 0.704690, -0.769868, -0.933941, 0.789480, -0.665650, -1.144617, 0.860811, -0.530815, -1.302112, 0.914135, -0.374411, -1.400281, 0.947373, -0.207706, -1.440657, 0.961043, -0.041386, -1.427343, 0.956536, 0.124016, -1.358683, 0.933289, 0.291622, -1.230584, 0.889917, 0.454628, -1.045236, 0.827162, 0.601573, -0.812634, 0.748408, 0.722005, -0.548954, 0.659131, 0.808769, -0.273044, 0.565713, 0.859341, -0, 0.518779, 0.875572, 0.273043, 0.565713, 0.859341, 0.548954, 0.659131, 0.808769, 0.812633, 0.748407, 0.722005, 1.045236, 0.827162, 0.601574, 1.230583, 0.889917, 0.454629, 1.358682, 0.933289, 0.291623, 1.427343, 0.956535, 0.124017, 1.440657, 0.961043, -0.041384, 1.400282, 0.947373, -0.207704, 1.302113, 0.914135, -0.374409, 1.144619, 0.860811, -0.530813, 0.933943, 0.789481, -0.665649, 0.683518, 0.704692, -0.769867, 0.411362, 0.612545, -0.838549, 0.136138, 0.519360, -0.871530, -0.136330, 0.613717, -0.817388, -0.411950, 0.716187, -0.786456, -0.684500, 0.817516, -0.722041, -0.935286, 0.910753, -0.624298, -1.146266, 0.989192, -0.497838, -1.303987, 1.047829, -0.351151, -1.402298, 1.084379, -0.194802, -1.442733, 1.099412, -0.038815, -1.429399, 1.094455, 0.116312, -1.360640, 1.068892, 0.273506, -1.232357, 1.021199, 0.426385, -1.046742, 0.952191, 0.564201, -0.813804, 0.865589, 0.677151, -0.549745, 0.767417, 0.758525, -0.273437, 0.664691, 0.805956, -0, 0.613080, 0.821179, 0.273437, 0.664691, 0.805956, 0.549744, 0.767417, 0.758526, 0.813804, 0.865589, 0.677152, 1.046741, 0.952190, 0.564202, 1.232356, 1.021198, 0.426386, 1.360640, 1.068892, 0.273507, 1.429399, 1.094455, 0.116313, 1.442733, 1.099412, -0.038813, 1.402299, 1.084380, -0.194801, 1.303988, 1.047830, -0.351149, 1.146268, 0.989192, -0.497837, 0.935289, 0.910754, -0.624296, 0.684503, 0.817517, -0.722040, 0.411954, 0.716189, -0.786455, 0.136334, 0.613719, -0.817388, -0.133296, 0.700648, -0.753541, -0.402782, 0.808379, -0.725025, -0.669265, 0.914909, -0.665641, -0.914470, 1.012934, -0.575533, -1.120754, 1.095399, -0.458952, -1.274965, 1.157047, -0.323722, -1.371088, 1.195473, -0.179586, -1.410622, 1.211278, -0.035783, -1.397585, 1.206066, 0.107226, -1.330357, 1.179191, 0.252142, -1.204929, 1.129049, 0.393080, -1.023445, 1.056498, 0.520131, -0.795692, 0.965450, 0.624259, -0.537510, 0.862238, 0.699276, -0.267351, 0.754238, 0.743002, -0, 0.699978, 0.757036, 0.267351, 0.754238, 0.743002, 0.537509, 0.862238, 0.699277, 0.795691, 0.965450, 0.624259, 1.023444, 1.056498, 0.520132, 1.204928, 1.129048, 0.393080, 1.330356, 1.179190, 0.252143, 1.397585, 1.206066, 0.107227, 1.410622, 1.211278, -0.035782, 1.371089, 1.195473, -0.179585, 1.274966, 1.157047, -0.323721, 1.120756, 1.095400, -0.458951, 0.914472, 1.012935, -0.575532, 0.669268, 0.914911, -0.665640, 0.402785, 0.808380, -0.725025, 0.133300, 0.700649, -0.753541, -0.127015, 0.778510, -0.680872, -0.383801, 0.887302, -0.655106, -0.637726, 0.994882, -0.601449, -0.871376, 1.093872, -0.520031, -1.067939, 1.177150, -0.414692, -1.214882, 1.239405, -0.292504, -1.306476, 1.278210, -0.162268, -1.344147, 1.294170, -0.032332, -1.331725, 1.288907, 0.096886, -1.267664, 1.261766, 0.227826, -1.148147, 1.211131, 0.355172, -0.975216, 1.137866, 0.469972, -0.758195, 1.045921, 0.564057, -0.512180, 0.941692, 0.631841, -0.254752, 0.832629, 0.671349, -0, 0.777833, 0.684030, 0.254752, 0.832628, 0.671349, 0.512179, 0.941692, 0.631841, 0.758194, 1.045921, 0.564058, 0.975215, 1.137865, 0.469972, 1.148146, 1.211131, 0.355173, 1.267664, 1.261766, 0.227827, 1.331724, 1.288907, 0.096887, 1.344147, 1.294170, -0.032331, 1.306476, 1.278210, -0.162266, 1.214884, 1.239405, -0.292502, 1.067941, 1.177150, -0.414691, 0.871378, 1.093873, -0.520030, 0.637729, 0.994883, -0.601449, 0.383804, 0.887304, -0.655106, 0.127018, 0.778512, -0.680872, -0.117579, 0.845944, -0.600578, -0.355288, 0.951562, -0.577851, -0.590349, 1.056003, -0.530521, -0.806641, 1.152105, -0.458705, -0.988602, 1.232952, -0.365788, -1.124629, 1.293391, -0.258009, -1.209418, 1.331064, -0.143132, -1.244290, 1.346558, -0.028519, -1.232791, 1.341449, 0.085460, -1.173489, 1.315100, 0.200959, -1.062851, 1.265942, 0.313287, -0.902767, 1.194815, 0.414549, -0.701869, 1.105553, 0.497539, -0.474130, 1.004365, 0.557329, -0.235827, 0.898484, 0.592178, -0, 0.845287, 0.603364, 0.235826, 0.898483, 0.592178, 0.474129, 1.004365, 0.557329, 0.701868, 1.105552, 0.497539, 0.902766, 1.194814, 0.414549, 1.062850, 1.265942, 0.313288, 1.173489, 1.315100, 0.200960, 1.232790, 1.341449, 0.085461, 1.244291, 1.346558, -0.028518, 1.209418, 1.331064, -0.143131, 1.124630, 1.293391, -0.258008, 0.988603, 1.232953, -0.365787, 0.806643, 1.152106, -0.458704, 0.590352, 1.056004, -0.530521, 0.355291, 0.951563, -0.577850, 0.117582, 0.845946, -0.600578, -0.105187, 0.901947, -0.514105, -0.317843, 1.000262, -0.494650, -0.528131, 1.097481, -0.454135, -0.721627, 1.186938, -0.392658, -0.884410, 1.262195, -0.313121, -1.006101, 1.318455, -0.220860, -1.081954, 1.353523, -0.122523, -1.113151, 1.367946, -0.024413, -1.102863, 1.363190, 0.073155, -1.049812, 1.338663, 0.172024, -0.950834, 1.292904, 0.268179, -0.807621, 1.226694, 0.354860, -0.627897, 1.143605, 0.425901, -0.424160, 1.049414, 0.477082, -0.210972, 0.950853, 0.506914, -0, 0.901335, 0.516489, 0.210972, 0.950853, 0.506914, 0.424159, 1.049414, 0.477083, 0.627896, 1.143605, 0.425902, 0.807621, 1.226694, 0.354861, 0.950833, 1.292904, 0.268180, 1.049811, 1.338663, 0.172025, 1.102863, 1.363189, 0.073156, 1.113151, 1.367946, -0.024412, 1.081954, 1.353523, -0.122522, 1.006102, 1.318455, -0.220859, 0.884412, 1.262196, -0.313120, 0.721629, 1.186939, -0.392658, 0.528133, 1.097482, -0.454134, 0.317846, 1.000263, -0.494649, 0.105190, 0.901948, -0.514104, -0.090129, 0.945921, -0.423062, -0.272344, 1.033045, -0.407052, -0.452529, 1.119197, -0.373712, -0.618326, 1.198471, -0.323123, -0.757807, 1.265162, -0.257670, -0.862078, 1.315017, -0.181748, -0.927072, 1.346093, -0.100825, -0.953804, 1.358874, -0.020090, -0.944989, 1.354659, 0.060200, -0.899532, 1.332925, 0.141561, -0.814722, 1.292375, 0.220687, -0.692011, 1.233702, 0.292018, -0.538014, 1.160071, 0.350479, -0.363442, 1.076602, 0.392596, -0.180772, 0.989261, 0.417145, -0, 0.945379, 0.425024, 0.180771, 0.989260, 0.417145, 0.363441, 1.076601, 0.392596, 0.538013, 1.160070, 0.350479, 0.692010, 1.233702, 0.292019, 0.814722, 1.292374, 0.220688, 0.899531, 1.332925, 0.141561, 0.944989, 1.354659, 0.060201, 0.953804, 1.358874, -0.020089, 0.927073, 1.346093, -0.100825, 0.862079, 1.315017, -0.181747, 0.757808, 1.265162, -0.257670, 0.618328, 1.198472, -0.323122, 0.452531, 1.119198, -0.373712, 0.272347, 1.033046, -0.407052, 0.090132, 0.945923, -0.423062, -0.072769, 0.977689, -0.329131, -0.219888, 1.050087, -0.316676, -0.365367, 1.121679, -0.290738, -0.499229, 1.187553, -0.251381, -0.611845, 1.242972, -0.200461, -0.696032, 1.284401, -0.141395, -0.748507, 1.310225, -0.078440, -0.770090, 1.320846, -0.015629, -0.762973, 1.317343, 0.046834, -0.726272, 1.299282, 0.110130, -0.657797, 1.265586, 0.171689, -0.558721, 1.216830, 0.227182, -0.434386, 1.155643, 0.272663, -0.293438, 1.086282, 0.305429, -0.145953, 1.013704, 0.324528, -0, 0.977239, 0.330657, 0.145953, 1.013703, 0.324528, 0.293438, 1.086282, 0.305429, 0.434385, 1.155643, 0.272663, 0.558721, 1.216830, 0.227183, 0.657797, 1.265586, 0.171689, 0.726271, 1.299282, 0.110131, 0.762973, 1.317343, 0.046835, 0.770090, 1.320846, -0.015629, 0.748508, 1.310225, -0.078439, 0.696032, 1.284401, -0.141395, 0.611846, 1.242973, -0.200460, 0.499231, 1.187554, -0.251380, 0.365368, 1.121680, -0.290738, 0.219890, 1.050088, -0.316676, 0.072771, 0.977690, -0.329131, -0.053518, 0.997470, -0.233969, -0.161715, 1.052051, -0.225115, -0.268707, 1.106024, -0.206677, -0.367155, 1.155687, -0.178699, -0.449978, 1.197467, -0.142501, -0.511893, 1.228700, -0.100513, -0.550486, 1.248169, -0.055760, -0.566359, 1.256176, -0.011110, -0.561124, 1.253536, 0.033293, -0.534132, 1.239919, 0.078288, -0.483773, 1.214515, 0.122048, -0.410909, 1.177758, 0.161497, -0.319467, 1.131630, 0.193828, -0.215808, 1.079339, 0.217120, -0.107340, 1.024621, 0.230696, -0, 0.997131, 0.235054, 0.107340, 1.024621, 0.230696, 0.215807, 1.079338, 0.217120, 0.319466, 1.131630, 0.193828, 0.410908, 1.177758, 0.161497, 0.483773, 1.214515, 0.122048, 0.534132, 1.239919, 0.078288, 0.561124, 1.253535, 0.033293, 0.566359, 1.256176, -0.011110, 0.550486, 1.248169, -0.055760, 0.511893, 1.228701, -0.100513, 0.449979, 1.197467, -0.142501, 0.367157, 1.155687, -0.178698, 0.268708, 1.106025, -0.206676, 0.161717, 1.052052, -0.225115, 0.053519, 0.997471, -0.233969, -0.032808, 1.005833, -0.139127, -0.099136, 1.040004, -0.133862, -0.164726, 1.073793, -0.122898, -0.225078, 1.104885, -0.106261, -0.275850, 1.131042, -0.084737, -0.313806, 1.150595, -0.059769, -0.337465, 1.162784, -0.033157, -0.347195, 1.167797, -0.006607, -0.343986, 1.166144, 0.019797, -0.327440, 1.157619, 0.046553, -0.296568, 1.141715, 0.072574, -0.251900, 1.118703, 0.096032, -0.195843, 1.089824, 0.115257, -0.132297, 1.057087, 0.129108, -0.065803, 1.022831, 0.137181, -0, 1.005620, 0.139772, 0.065803, 1.022831, 0.137181, 0.132297, 1.057087, 0.129108, 0.195843, 1.089824, 0.115257, 0.251899, 1.118703, 0.096032, 0.296568, 1.141715, 0.072575, 0.327439, 1.157619, 0.046553, 0.343986, 1.166144, 0.019797, 0.347195, 1.167797, -0.006606, 0.337465, 1.162784, -0.033157, 0.313806, 1.150596, -0.059769, 0.275851, 1.131042, -0.084736, 0.225078, 1.104885, -0.106261, 0.164726, 1.073794, -0.122898, 0.099137, 1.040004, -0.133862, 0.032809, 1.005833, -0.139127 };
    CoordinateInterpolator_16.keyValue = m_keyValue;
    CoordinateInterpolator_16.keyValue_length = sizeof(m_keyValue) / sizeof(float);
    }
    CoordinateInterpolator_16.set_fraction = 0;
    {
    static float m_value_changed[1];
    CoordinateInterpolator_16.value_changed = NULL;
    CoordinateInterpolator_16.value_changed_length = 0;
    }
    NormalInterpolator_17.m_parent = (X3dNode *)&Shape_14;
    {
    static float m_key[] = { 0, 1 };
    NormalInterpolator_17.key = m_key;
    NormalInterpolator_17.key_length = sizeof(m_key) / sizeof(float);
    }
    {
    static float m_keyValue[] = { -0.004411, -0.998911, -0.046447, -0.013321, -0.998910, -0.044742, -0.022161, -0.998909, -0.041111, -0.030290, -0.998908, -0.035563, -0.037118, -0.998908, -0.028359, -0.042205, -0.998909, -0.019988, -0.045341, -0.998910, -0.011086, -0.046599, -0.998911, -0.002202, -0.046193, -0.998911, 0.006611, -0.044018, -0.998910, 0.015563, -0.039899, -0.998909, 0.024281, -0.033900, -0.998908, 0.032140, -0.026349, -0.998908, 0.038569, -0.017795, -0.998909, 0.043170, -0.008839, -0.998910, 0.045825, 0, -0.998911, 0.046649, 0.008839, -0.998910, 0.045825, 0.017795, -0.998909, 0.043170, 0.026349, -0.998908, 0.038569, 0.033900, -0.998908, 0.032140, 0.039899, -0.998909, 0.024281, 0.044018, -0.998909, 0.015564, 0.046193, -0.998911, 0.006611, 0.046599, -0.998911, -0.002205, 0.045342, -0.998910, -0.011082, 0.042205, -0.998909, -0.019988, 0.037118, -0.998908, -0.028359, 0.030292, -0.998908, -0.035560, 0.022158, -0.998909, -0.041112, 0.013321, -0.998910, -0.044742, 0.004411, -0.998911, -0.046447, 0.004411, -0.998911, -0.046447, 0, -0.995685, -0.092796, -0.017442, -0.995685, -0.091142, -0.035262, -0.995685, -0.085836, -0.052311, -0.995685, -0.076647, -0.067347, -0.995685, -0.063840, -0.079303, -0.995685, -0.048190, -0.087525, -0.995685, -0.030831, -0.091880, -0.995685, -0.013006, -0.092698, -0.995685, 0.004271, -0.090174, -0.995685, 0.021902, -0.083901, -0.995685, 0.039645, -0.073762, -0.995685, 0.056305, -0.060154, -0.995685, 0.070658, -0.043961, -0.995685, 0.081723, -0.026371, -0.995685, 0.088970, -0.008611, -0.995685, 0.092396, 0.008611, -0.995685, 0.092396, 0.026371, -0.995685, 0.088970, 0.043961, -0.995685, 0.081722, 0.060154, -0.995685, 0.070658, 0.073762, -0.995685, 0.056305, 0.083901, -0.995685, 0.039645, 0.090174, -0.995685, 0.021903, 0.092698, -0.995685, 0.004272, 0.091880, -0.995685, -0.013006, 0.087525, -0.995685, -0.030831, 0.079303, -0.995685, -0.048189, 0.067347, -0.995685, -0.063840, 0.052311, -0.995685, -0.076647, 0.035262, -0.995685, -0.085836, 0.017442, -0.995685, -0.091142, -0, -0.995685, -0.092796, 0, -0.982177, -0.187956, -0.035328, -0.982177, -0.184607, -0.071422, -0.982177, -0.173858, -0.105954, -0.982177, -0.155246, -0.136409, -0.982177, -0.129307, -0.160626, -0.982177, -0.097607, -0.177279, -0.982177, -0.062447, -0.186101, -0.982177, -0.026343, -0.187757, -0.982177, 0.008652, -0.182646, -0.982177, 0.044363, -0.169940, -0.982177, 0.080300, -0.149404, -0.982177, 0.114045, -0.121841, -0.982177, 0.143117, -0.089042, -0.982177, 0.165527, -0.053415, -0.982177, 0.180207, -0.017442, -0.982177, 0.187145, 0.017442, -0.982177, 0.187145, 0.053415, -0.982177, 0.180207, 0.089042, -0.982177, 0.165527, 0.121841, -0.982177, 0.143117, 0.149404, -0.982177, 0.114045, 0.169940, -0.982177, 0.080301, 0.182646, -0.982177, 0.044363, 0.187757, -0.982177, 0.008652, 0.186101, -0.982177, -0.026343, 0.177279, -0.982177, -0.062447, 0.160626, -0.982177, -0.097606, 0.136409, -0.982177, -0.129306, 0.105954, -0.982177, -0.155246, 0.071423, -0.982177, -0.173857, 0.035328, -0.982177, -0.184606, 0.000001, -0.982177, -0.187956, -0, -0.958769, -0.284186, -0.053415, -0.958769, -0.279121, -0.107989, -0.958769, -0.262869, -0.160200, -0.958769, -0.234729, -0.206247, -0.958769, -0.195509, -0.242862, -0.958769, -0.147579, -0.268043, -0.958769, -0.094419, -0.281381, -0.958769, -0.039831, -0.283885, -0.958769, 0.013081, -0.276157, -0.958769, 0.067076, -0.256945, -0.958769, 0.121412, -0.225895, -0.958769, 0.172433, -0.184221, -0.958769, 0.216390, -0.134630, -0.958769, 0.250273, -0.080762, -0.958769, 0.272469, -0.026372, -0.958769, 0.282960, 0.026371, -0.958769, 0.282960, 0.080762, -0.958769, 0.272469, 0.134630, -0.958769, 0.250273, 0.184221, -0.958769, 0.216390, 0.225895, -0.958769, 0.172433, 0.256945, -0.958769, 0.121413, 0.276157, -0.958769, 0.067076, 0.283885, -0.958769, 0.013082, 0.281381, -0.958769, -0.039830, 0.268043, -0.958769, -0.094418, 0.242863, -0.958769, -0.147579, 0.206248, -0.958769, -0.195509, 0.160201, -0.958769, -0.234729, 0.107989, -0.958769, -0.262869, 0.053415, -0.958769, -0.279121, 0.000001, -0.958769, -0.284186, -0, -0.924990, -0.379992, -0.071422, -0.924990, -0.373220, -0.144394, -0.924990, -0.351489, -0.214207, -0.924990, -0.313862, -0.275778, -0.924990, -0.261420, -0.324737, -0.924990, -0.197332, -0.358407, -0.924990, -0.126250, -0.376242, -0.924990, -0.053259, -0.379589, -0.924990, 0.017491, -0.369256, -0.924990, 0.089688, -0.343568, -0.924990, 0.162344, -0.302050, -0.924990, 0.230564, -0.246326, -0.924990, 0.289340, -0.180017, -0.924990, 0.334646, -0.107989, -0.924990, 0.364325, -0.035262, -0.924990, 0.378353, 0.035262, -0.924990, 0.378353, 0.107989, -0.924990, 0.364325, 0.180017, -0.924990, 0.334646, 0.246326, -0.924990, 0.289340, 0.302050, -0.924990, 0.230565, 0.343567, -0.924990, 0.162344, 0.369256, -0.924990, 0.089689, 0.379589, -0.924990, 0.017492, 0.376242, -0.924990, -0.053258, 0.358407, -0.924990, -0.126249, 0.324738, -0.924990, -0.197331, 0.275779, -0.924990, -0.261419, 0.214208, -0.924990, -0.313861, 0.144395, -0.924990, -0.351489, 0.071423, -0.924990, -0.373220, 0.000001, -0.924990, -0.379992, -0, -0.880666, -0.473737, -0.089042, -0.880666, -0.465294, -0.180017, -0.880666, -0.438202, -0.267053, -0.880666, -0.391293, -0.343814, -0.880666, -0.325913, -0.404851, -0.880666, -0.246014, -0.446826, -0.880666, -0.157396, -0.469061, -0.880666, -0.066398, -0.473235, -0.880666, 0.021806, -0.460353, -0.880666, 0.111815, -0.428327, -0.880666, 0.202394, -0.376567, -0.880666, 0.287445, -0.307096, -0.880666, 0.360721, -0.224427, -0.880666, 0.417204, -0.134630, -0.880666, 0.454205, -0.043961, -0.880666, 0.471693, 0.043961, -0.880666, 0.471693, 0.134630, -0.880666, 0.454205, 0.224427, -0.880666, 0.417205, 0.307095, -0.880666, 0.360721, 0.376566, -0.880666, 0.287446, 0.428326, -0.880666, 0.202395, 0.460353, -0.880666, 0.111815, 0.473235, -0.880666, 0.021807, 0.469061, -0.880666, -0.066397, 0.446827, -0.880666, -0.157395, 0.404852, -0.880666, -0.246013, 0.343814, -0.880666, -0.325912, 0.267054, -0.880666, -0.391292, 0.180018, -0.880666, -0.438202, 0.089043, -0.880666, -0.465294, 0.000001, -0.880666, -0.473737, -0, -0.825969, -0.563715, -0.105954, -0.825969, -0.553668, -0.214207, -0.825969, -0.521430, -0.317775, -0.825969, -0.465611, -0.409115, -0.825969, -0.387814, -0.481745, -0.825969, -0.292740, -0.531693, -0.825969, -0.187290, -0.558151, -0.825969, -0.079009, -0.563117, -0.825969, 0.025948, -0.547788, -0.825969, 0.133052, -0.509679, -0.825969, 0.240835, -0.448088, -0.825969, 0.342040, -0.365423, -0.825969, 0.429233, -0.267053, -0.825969, 0.496445, -0.160200, -0.825969, 0.540472, -0.052311, -0.825969, 0.561283, 0.052311, -0.825969, 0.561282, 0.160200, -0.825969, 0.540472, 0.267053, -0.825969, 0.496445, 0.365422, -0.825970, 0.429233, 0.448088, -0.825969, 0.342041, 0.509679, -0.825969, 0.240836, 0.547788, -0.825969, 0.133053, 0.563117, -0.825969, 0.025949, 0.558151, -0.825969, -0.079008, 0.531693, -0.825969, -0.187289, 0.481745, -0.825969, -0.292739, 0.409115, -0.825969, -0.387813, 0.317776, -0.825969, -0.465610, 0.214209, -0.825969, -0.521430, 0.105956, -0.825969, -0.553668, 0.000002, -0.825969, -0.563715, -0, -0.761436, -0.648240, -0.121841, -0.761436, -0.636687, -0.246326, -0.761436, -0.599615, -0.365423, -0.761436, -0.535426, -0.470458, -0.761436, -0.445964, -0.553979, -0.761436, -0.336634, -0.611416, -0.761436, -0.215373, -0.641841, -0.761436, -0.090855, -0.647553, -0.761436, 0.029839, -0.629925, -0.761436, 0.153002, -0.586102, -0.761436, 0.276947, -0.515276, -0.761436, 0.393327, -0.420215, -0.761436, 0.493593, -0.307096, -0.761436, 0.570883, -0.184221, -0.761436, 0.621512, -0.060154, -0.761436, 0.645443, 0.060154, -0.761436, 0.645443, 0.184221, -0.761436, 0.621512, 0.307095, -0.761436, 0.570883, 0.420215, -0.761436, 0.493594, 0.515276, -0.761436, 0.393327, 0.586102, -0.761436, 0.276947, 0.629925, -0.761436, 0.153003, 0.647553, -0.761436, 0.029840, 0.641842, -0.761436, -0.090854, 0.611417, -0.761436, -0.215372, 0.553980, -0.761436, -0.336633, 0.470459, -0.761436, -0.445963, 0.365424, -0.761436, -0.535425, 0.246328, -0.761436, -0.599615, 0.121843, -0.761436, -0.636686, 0.000002, -0.761436, -0.648240, -0, -0.687961, -0.725747, -0.136409, -0.687961, -0.712813, -0.275779, -0.687961, -0.671309, -0.409115, -0.687961, -0.599445, -0.526709, -0.687961, -0.499286, -0.620216, -0.687961, -0.376884, -0.684521, -0.687961, -0.241124, -0.718584, -0.687961, -0.101718, -0.724978, -0.687961, 0.033407, -0.705242, -0.687961, 0.171296, -0.656180, -0.687961, 0.310060, -0.576885, -0.687961, 0.440355, -0.470458, -0.687961, 0.552610, -0.343814, -0.687961, 0.639141, -0.206248, -0.687961, 0.695824, -0.067347, -0.687961, 0.722616, 0.067347, -0.687961, 0.722616, 0.206247, -0.687961, 0.695824, 0.343813, -0.687961, 0.639141, 0.470458, -0.687961, 0.552610, 0.576885, -0.687961, 0.440355, 0.656179, -0.687961, 0.310061, 0.705242, -0.687961, 0.171297, 0.724978, -0.687961, 0.033408, 0.718584, -0.687961, -0.101717, 0.684521, -0.687961, -0.241123, 0.620217, -0.687961, -0.376882, 0.526710, -0.687961, -0.499285, 0.409116, -0.687961, -0.599444, 0.275780, -0.687961, -0.671308, 0.136411, -0.687961, -0.712812, 0.000002, -0.687961, -0.725747, -0, -0.606761, -0.794885, -0.149404, -0.606761, -0.780717, -0.302050, -0.606761, -0.735260, -0.448088, -0.606761, -0.656550, -0.576885, -0.606761, -0.546850, -0.679300, -0.606761, -0.412787, -0.749730, -0.606761, -0.264094, -0.787038, -0.606761, -0.111408, -0.794042, -0.606761, 0.036589, -0.772426, -0.606761, 0.187614, -0.718690, -0.606761, 0.339597, -0.631841, -0.606761, 0.482305, -0.515276, -0.606761, 0.605254, -0.376567, -0.606761, 0.700028, -0.225895, -0.606761, 0.762111, -0.073763, -0.606761, 0.791455, 0.073762, -0.606761, 0.791455, 0.225895, -0.606761, 0.762111, 0.376566, -0.606761, 0.700028, 0.515275, -0.606761, 0.605254, 0.631841, -0.606761, 0.482305, 0.718689, -0.606761, 0.339598, 0.772426, -0.606761, 0.187615, 0.794042, -0.606761, 0.036590, 0.787039, -0.606761, -0.111407, 0.749731, -0.606761, -0.264093, 0.679301, -0.606761, -0.412785, 0.576886, -0.606761, -0.546848, 0.448090, -0.606761, -0.656549, 0.302052, -0.606761, -0.735259, 0.149406, -0.606761, -0.780717, 0.000002, -0.606761, -0.794884, -0, -0.519304, -0.854590, -0.160626, -0.519304, -0.839358, -0.324737, -0.519304, -0.790486, -0.481745, -0.519304, -0.705865, -0.620216, -0.519304, -0.587925, -0.730323, -0.519304, -0.443792, -0.806044, -0.519304, -0.283931, -0.846154, -0.519304, -0.119776, -0.853684, -0.519304, 0.039337, -0.830444, -0.519304, 0.201706, -0.772672, -0.519304, 0.365105, -0.679300, -0.519304, 0.518531, -0.553979, -0.519304, 0.650715, -0.404851, -0.519304, 0.752608, -0.242863, -0.519304, 0.819354, -0.079303, -0.519304, 0.850902, 0.079303, -0.519304, 0.850902, 0.242862, -0.519304, 0.819354, 0.404851, -0.519304, 0.752608, 0.553979, -0.519304, 0.650716, 0.679299, -0.519304, 0.518532, 0.772671, -0.519304, 0.365106, 0.830444, -0.519304, 0.201707, 0.853684, -0.519304, 0.039338, 0.846154, -0.519304, -0.119775, 0.806044, -0.519304, -0.283929, 0.730324, -0.519304, -0.443790, 0.620217, -0.519304, -0.587923, 0.481747, -0.519304, -0.705863, 0.324740, -0.519304, -0.790486, 0.160628, -0.519304, -0.839358, 0.000002, -0.519304, -0.854589, -0, -0.427229, -0.904144, -0.169940, -0.427229, -0.888029, -0.343568, -0.427229, -0.836323, -0.509679, -0.427229, -0.746795, -0.656180, -0.427229, -0.622016, -0.772672, -0.427229, -0.469526, -0.852783, -0.427229, -0.300395, -0.895219, -0.427229, -0.126722, -0.903185, -0.427229, 0.041618, -0.878598, -0.427229, 0.213402, -0.817476, -0.427229, 0.386276, -0.718690, -0.427229, 0.548599, -0.586102, -0.427229, 0.688447, -0.428327, -0.427229, 0.796249, -0.256945, -0.427229, 0.866865, -0.083901, -0.427229, 0.900242, 0.083901, -0.427229, 0.900242, 0.256945, -0.427229, 0.866865, 0.428326, -0.427229, 0.796249, 0.586102, -0.427229, 0.688448, 0.718689, -0.427229, 0.548600, 0.817475, -0.427229, 0.386277, 0.878598, -0.427229, 0.213403, 0.903185, -0.427229, 0.041619, 0.895219, -0.427229, -0.126720, 0.852784, -0.427229, -0.300393, 0.772673, -0.427229, -0.469524, 0.656181, -0.427229, -0.622014, 0.509681, -0.427229, -0.746794, 0.343570, -0.427229, -0.836322, 0.169942, -0.427229, -0.888029, 0.000003, -0.427229, -0.904144, -0, -0.332242, -0.943194, -0.177279, -0.332242, -0.926384, -0.358407, -0.332242, -0.872445, -0.531693, -0.332242, -0.779050, -0.684521, -0.332242, -0.648881, -0.806044, -0.332242, -0.489805, -0.889615, -0.332242, -0.313369, -0.933884, -0.332242, -0.132195, -0.942194, -0.332242, 0.043416, -0.916546, -0.332242, 0.222619, -0.852783, -0.332242, 0.402959, -0.749730, -0.332242, 0.572293, -0.611416, -0.332242, 0.718182, -0.446826, -0.332242, 0.830639, -0.268043, -0.332242, 0.904305, -0.087525, -0.332242, 0.939124, 0.087525, -0.332242, 0.939124, 0.268043, -0.332242, 0.904306, 0.446826, -0.332242, 0.830639, 0.611416, -0.332242, 0.718183, 0.749730, -0.332242, 0.572294, 0.852783, -0.332242, 0.402961, 0.916545, -0.332242, 0.222620, 0.942194, -0.332242, 0.043417, 0.933885, -0.332242, -0.132193, 0.889616, -0.332242, -0.313367, 0.806045, -0.332242, -0.489803, 0.684522, -0.332242, -0.648880, 0.531695, -0.332242, -0.779048, 0.358409, -0.332242, -0.872444, 0.177282, -0.332242, -0.926383, 0.000003, -0.332242, -0.943194, -0, -0.236027, -0.971747, -0.182646, -0.236027, -0.954427, -0.369256, -0.236027, -0.898855, -0.547788, -0.236027, -0.802633, -0.705242, -0.236027, -0.668524, -0.830444, -0.236027, -0.504632, -0.916546, -0.236027, -0.322855, -0.962155, -0.236027, -0.136197, -0.970717, -0.236027, 0.044730, -0.944291, -0.236027, 0.229358, -0.878598, -0.236027, 0.415158, -0.772426, -0.236027, 0.589618, -0.629925, -0.236027, 0.739923, -0.460353, -0.236027, 0.855784, -0.276157, -0.236027, 0.931681, -0.090174, -0.236027, 0.967554, 0.090174, -0.236027, 0.967554, 0.276157, -0.236027, 0.931681, 0.460352, -0.236027, 0.855784, 0.629924, -0.236027, 0.739923, 0.772426, -0.236027, 0.589618, 0.878598, -0.236027, 0.415159, 0.944291, -0.236027, 0.229359, 0.970716, -0.236027, 0.044731, 0.962155, -0.236027, -0.136195, 0.916546, -0.236027, -0.322853, 0.830445, -0.236027, -0.504630, 0.705244, -0.236027, -0.668522, 0.547790, -0.236027, -0.802632, 0.369259, -0.236027, -0.898854, 0.182649, -0.236027, -0.954427, 0.000003, -0.236027, -0.971747, -0, -0.140157, -0.990129, -0.186101, -0.140157, -0.972483, -0.376242, -0.140157, -0.915859, -0.558151, -0.140157, -0.817817, -0.718584, -0.140157, -0.681171, -0.846154, -0.140157, -0.514178, -0.933884, -0.140157, -0.328962, -0.980356, -0.140157, -0.138773, -0.989080, -0.140157, 0.045576, -0.962155, -0.140157, 0.233697, -0.895219, -0.140157, 0.423012, -0.787039, -0.140157, 0.600772, -0.641841, -0.140157, 0.753920, -0.469061, -0.140157, 0.871973, -0.281381, -0.140157, 0.949305, -0.091880, -0.140157, 0.985857, 0.091880, -0.140157, 0.985857, 0.281381, -0.140157, 0.949305, 0.469061, -0.140157, 0.871974, 0.641841, -0.140157, 0.753921, 0.787038, -0.140157, 0.600772, 0.895219, -0.140157, 0.423013, 0.962155, -0.140157, 0.233698, 0.989080, -0.140157, 0.045578, 0.980356, -0.140157, -0.138772, 0.933885, -0.140157, -0.328961, 0.846155, -0.140157, -0.514176, 0.718585, -0.140157, -0.681169, 0.558153, -0.140157, -0.817815, 0.376244, -0.140157, -0.915858, 0.186104, -0.140157, -0.972482, 0.000003, -0.140157, -0.990129, -0, -0.046031, -0.998940, -0.187757, -0.046031, -0.981136, -0.379589, -0.046031, -0.924009, -0.563117, -0.046031, -0.825094, -0.724978, -0.046031, -0.687232, -0.853684, -0.046031, -0.518754, -0.942194, -0.046031, -0.331890, -0.989080, -0.046031, -0.140008, -0.997881, -0.046031, 0.045982, -0.970717, -0.046031, 0.235777, -0.903185, -0.046031, 0.426776, -0.794042, -0.046031, 0.606118, -0.647553, -0.046031, 0.760629, -0.473235, -0.046031, 0.879733, -0.283885, -0.046031, 0.957753, -0.092698, -0.046031, 0.994630, 0.092698, -0.046031, 0.994630, 0.283885, -0.046031, 0.957753, 0.473235, -0.046031, 0.879733, 0.647552, -0.046031, 0.760629, 0.794041, -0.046031, 0.606118, 0.903185, -0.046031, 0.426777, 0.970716, -0.046031, 0.235778, 0.997881, -0.046031, 0.045983, 0.989080, -0.046030, -0.140006, 0.942195, -0.046031, -0.331888, 0.853685, -0.046031, -0.518752, 0.724980, -0.046031, -0.687230, 0.563119, -0.046031, -0.825092, 0.379592, -0.046031, -0.924008, 0.187760, -0.046031, -0.981136, 0.000003, -0.046031, -0.998940, -0, 0.046030, -0.998940, -0.187757, 0.046030, -0.981136, -0.379589, 0.046030, -0.924009, -0.563117, 0.046031, -0.825094, -0.724978, 0.046031, -0.687232, -0.853684, 0.046031, -0.518754, -0.942194, 0.046031, -0.331890, -0.989080, 0.046031, -0.140008, -0.997831, 0.046569, 0.046520, -0.970510, 0.048450, 0.236143, -0.902925, 0.049621, 0.426923, -0.793845, 0.049856, 0.606073, -0.647486, 0.049214, 0.760486, -0.473287, 0.048043, 0.879597, -0.283978, 0.046858, 0.957685, -0.092745, 0.046129, 0.994621, 0.092698, 0.046030, 0.994630, 0.283885, 0.046031, 0.957753, 0.473235, 0.046031, 0.879733, 0.647552, 0.046031, 0.760629, 0.794041, 0.046031, 0.606118, 0.903185, 0.046031, 0.426777, 0.970716, 0.046030, 0.235778, 0.997881, 0.046030, 0.045983, 0.989026, 0.046635, -0.140187, 0.942093, 0.047327, -0.331996, 0.853574, 0.047808, -0.518773, 0.724906, 0.048005, -0.687173, 0.563119, 0.047886, -0.824987, 0.379679, 0.047470, -0.923900, 0.187925, 0.046823, -0.981067, 0.000219, 0.046030, -0.998940, -0, 0.140156, -0.990129, -0.186101, 0.140157, -0.972483, -0.376242, 0.140156, -0.915859, -0.558151, 0.140157, -0.817817, -0.718584, 0.140157, -0.681171, -0.846154, 0.140157, -0.514178, -0.933884, 0.140157, -0.328962, -0.980356, 0.140157, -0.138773, -0.988940, 0.140628, 0.047135, -0.961583, 0.142276, 0.234766, -0.894510, 0.143300, 0.423459, -0.786508, 0.143507, 0.600675, -0.641675, 0.142945, 0.753539, -0.469221, 0.141920, 0.871602, -0.281654, 0.140882, 0.949117, -0.092016, 0.140243, 0.985832, 0.091880, 0.140156, 0.985857, 0.281381, 0.140157, 0.949306, 0.469061, 0.140156, 0.871974, 0.641841, 0.140157, 0.753921, 0.787038, 0.140157, 0.600772, 0.895219, 0.140156, 0.423013, 0.962155, 0.140157, 0.233698, 0.989080, 0.140156, 0.045577, 0.979894, 0.141780, -0.140379, 0.933013, 0.143633, -0.329933, 0.845222, 0.144918, -0.514391, 0.717980, 0.145444, -0.680699, 0.558181, 0.145126, -0.816929, 0.377031, 0.144017, -0.914935, 0.187572, 0.142284, -0.971891, 0.001929, 0.140156, -0.990128, -0, 0.236026, -0.971747, -0.182646, 0.236027, -0.954428, -0.369256, 0.236027, -0.898856, -0.547788, 0.236027, -0.802633, -0.705242, 0.236027, -0.668524, -0.830444, 0.236026, -0.504632, -0.916546, 0.236027, -0.322855, -0.962155, 0.236026, -0.136197, -0.970503, 0.236419, 0.047215, -0.943430, 0.237792, 0.231074, -0.877537, 0.238646, 0.415904, -0.771646, 0.238819, 0.589515, -0.629703, 0.238351, 0.739366, -0.460628, 0.237498, 0.855229, -0.276597, 0.236632, 0.931396, -0.090392, 0.236099, 0.967516, 0.090174, 0.236027, 0.967554, 0.276157, 0.236027, 0.931681, 0.460352, 0.236027, 0.855785, 0.629924, 0.236027, 0.739923, 0.772426, 0.236027, 0.589618, 0.878598, 0.236026, 0.415159, 0.944291, 0.236026, 0.229359, 0.970717, 0.236026, 0.044731, 0.960951, 0.238342, -0.140594, 0.914301, 0.240979, -0.325549, 0.828072, 0.242800, -0.505316, 0.703755, 0.243544, -0.667394, 0.547983, 0.243094, -0.800388, 0.371463, 0.241523, -0.896483, 0.186672, 0.239061, -0.952892, 0.005274, 0.236023, -0.971733, -0, 0.332242, -0.943194, -0.177279, 0.332242, -0.926384, -0.358407, 0.332242, -0.872445, -0.531693, 0.332242, -0.779050, -0.684521, 0.332242, -0.648881, -0.806044, 0.332242, -0.489805, -0.889615, 0.332242, -0.313369, -0.933884, 0.332241, -0.132195, -0.941929, 0.332547, 0.046711, -0.915484, 0.333622, 0.224913, -0.851489, 0.334290, 0.404001, -0.748802, 0.334425, 0.572237, -0.611194, 0.334060, 0.717528, -0.447224, 0.333393, 0.829964, -0.268635, 0.332716, 0.903956, -0.087814, 0.332298, 0.939078, 0.087525, 0.332242, 0.939125, 0.268043, 0.332242, 0.904306, 0.446826, 0.332242, 0.830639, 0.611416, 0.332242, 0.718183, 0.749730, 0.332242, 0.572294, 0.852783, 0.332242, 0.402960, 0.916546, 0.332242, 0.222620, 0.942194, 0.332242, 0.043417, 0.931713, 0.334854, -0.140655, 0.885630, 0.337830, -0.318638, 0.801906, 0.339878, -0.491355, 0.682055, 0.340713, -0.647082, 0.532337, 0.340208, -0.775162, 0.362768, 0.338442, -0.868249, 0.185034, 0.335666, -0.923629, 0.010137, 0.332225, -0.943146, -0, 0.427228, -0.904144, -0.169940, 0.427228, -0.888030, -0.343568, 0.427228, -0.836324, -0.509679, 0.427228, -0.746795, -0.656180, 0.427228, -0.622016, -0.772672, 0.427228, -0.469526, -0.852783, 0.427228, -0.300395, -0.895219, 0.427228, -0.126722, -0.902891, 0.427445, 0.045584, -0.877435, 0.428217, 0.216189, -0.816077, 0.428697, 0.387604, -0.717722, 0.428794, 0.548645, -0.585935, 0.428533, 0.687779, -0.428852, 0.428054, 0.795522, -0.257669, 0.427568, 0.866482, -0.084249, 0.427269, 0.900191, 0.083901, 0.427228, 0.900243, 0.256945, 0.427228, 0.866865, 0.428326, 0.427228, 0.796249, 0.586102, 0.427228, 0.688448, 0.718689, 0.427228, 0.548600, 0.817475, 0.427228, 0.386277, 0.878598, 0.427228, 0.213403, 0.903185, 0.427228, 0.041620, 0.891989, 0.429706, -0.140385, 0.846972, 0.432565, -0.309073, 0.766784, 0.434525, -0.472472, 0.652940, 0.435323, -0.619809, 0.511231, 0.434841, -0.741320, 0.350840, 0.433152, -0.830236, 0.182489, 0.430488, -0.883956, 0.016356, 0.427171, -0.904023, -0, 0.519304, -0.854590, -0.160626, 0.519304, -0.839359, -0.324738, 0.519304, -0.790487, -0.481745, 0.519304, -0.705865, -0.620216, 0.519304, -0.587925, -0.730323, 0.519304, -0.443792, -0.806044, 0.519304, -0.283931, -0.846154, 0.519304, -0.119776, -0.853385, 0.519437, 0.043813, -0.829278, 0.519923, 0.204886, -0.771296, 0.520225, 0.366699, -0.678397, 0.520287, 0.518728, -0.553919, 0.520123, 0.650112, -0.405503, 0.519823, 0.751899, -0.243695, 0.519517, 0.818972, -0.079697, 0.519329, 0.850850, 0.079303, 0.519304, 0.850902, 0.242862, 0.519304, 0.819354, 0.404851, 0.519304, 0.752608, 0.553979, 0.519304, 0.650716, 0.679300, 0.519304, 0.518532, 0.772672, 0.519304, 0.365106, 0.830444, 0.519304, 0.201707, 0.853684, 0.519304, 0.039338, 0.841918, 0.521228, -0.139624, 0.798618, 0.523558, -0.296812, 0.723053, 0.525151, -0.448788, 0.616703, 0.525799, -0.585843, 0.484827, 0.525408, -0.699206, 0.335675, 0.524035, -0.782758, 0.178899, 0.521865, -0.834057, 0.023728, 0.519157, -0.854349, -0, 0.606760, -0.794885, -0.149404, 0.606760, -0.780718, -0.302050, 0.606760, -0.735260, -0.448088, 0.606760, -0.656551, -0.576886, 0.606760, -0.546850, -0.679300, 0.606760, -0.412787, -0.749731, 0.606760, -0.264094, -0.787039, 0.606760, -0.111409, -0.793760, 0.606820, 0.041399, -0.771344, 0.607058, 0.191071, -0.717448, 0.607207, 0.341421, -0.631093, 0.607238, 0.482684, -0.515362, 0.607158, 0.604782, -0.377337, 0.607012, 0.699395, -0.226807, 0.606864, 0.761758, -0.074186, 0.606773, 0.791406, 0.073762, 0.606760, 0.791455, 0.225895, 0.606760, 0.762111, 0.376566, 0.606760, 0.700028, 0.515276, 0.606760, 0.605254, 0.631841, 0.606760, 0.482306, 0.718690, 0.606760, 0.339598, 0.772426, 0.606760, 0.187615, 0.794042, 0.606760, 0.036590, 0.781989, 0.607771, -0.138230, 0.741168, 0.609261, -0.281906, 0.671321, 0.610283, -0.420574, 0.573855, 0.610699, -0.545653, 0.453450, 0.610448, -0.649413, 0.317380, 0.609567, -0.726428, 0.174165, 0.608178, -0.774459, 0.032011, 0.606449, -0.794477, -0, 0.687961, -0.725748, -0.136409, 0.687961, -0.712813, -0.275779, 0.687961, -0.671309, -0.409115, 0.687961, -0.599445, -0.526709, 0.687961, -0.499286, -0.620216, 0.687961, -0.376884, -0.684521, 0.687961, -0.241124, -0.718584, 0.687961, -0.101718, -0.724731, 0.687964, 0.038363, -0.704313, 0.688007, 0.174902, -0.655155, 0.688034, 0.312059, -0.576352, 0.688041, 0.440928, -0.470709, 0.688027, 0.552314, -0.344683, 0.688003, 0.638628, -0.207206, 0.687978, 0.695523, -0.067785, 0.687963, 0.722573, 0.067347, 0.687961, 0.722616, 0.206247, 0.687961, 0.695825, 0.343814, 0.687961, 0.639142, 0.470458, 0.687961, 0.552611, 0.576885, 0.687961, 0.440356, 0.656180, 0.687961, 0.310061, 0.705243, 0.687961, 0.171297, 0.724979, 0.687961, 0.033408, 0.713029, 0.687801, -0.136089, 0.675502, 0.688288, -0.264493, 0.612421, 0.688633, -0.388233, 0.525082, 0.688776, -0.499877, 0.417564, 0.688689, -0.592745, 0.296159, 0.688390, -0.662125, 0.168232, 0.687932, -0.706008, 0.040932, 0.687384, -0.725140, -0, 0.761436, -0.648241, -0.121841, 0.761436, -0.636687, -0.246327, 0.761435, -0.599616, -0.365423, 0.761436, -0.535427, -0.470459, 0.761436, -0.445965, -0.553980, 0.761435, -0.336634, -0.611417, 0.761436, -0.215373, -0.641842, 0.761435, -0.090855, -0.647351, 0.761399, 0.034749, -0.629189, 0.761309, 0.156618, -0.585342, 0.761254, 0.279047, -0.514987, 0.761244, 0.394077, -0.420626, 0.761276, 0.493490, -0.308031, 0.761334, 0.570515, -0.185189, 0.761393, 0.621277, -0.060589, 0.761431, 0.645409, 0.060154, 0.761436, 0.645443, 0.184221, 0.761436, 0.621513, 0.307096, 0.761436, 0.570884, 0.420215, 0.761436, 0.493594, 0.515276, 0.761436, 0.393328, 0.586102, 0.761436, 0.276948, 0.629925, 0.761436, 0.153003, 0.647553, 0.761436, 0.029840, 0.636164, 0.759983, -0.133119, 0.602728, 0.759473, -0.244787, 0.547357, 0.759148, -0.352270, 0.471205, 0.759022, -0.449279, 0.377746, 0.759098, -0.530168, 0.272299, 0.759373, -0.590936, 0.161093, 0.759839, -0.629836, 0.050204, 0.760475, -0.647423, -0, 0.825969, -0.563716, -0.105954, 0.825969, -0.553669, -0.214208, 0.825969, -0.521431, -0.317775, 0.825969, -0.465612, -0.409115, 0.825969, -0.387815, -0.481745, 0.825969, -0.292740, -0.531693, 0.825969, -0.187290, -0.558151, 0.825969, -0.079009, -0.562966, 0.825913, 0.030621, -0.547259, 0.825752, 0.136534, -0.509191, 0.825652, 0.242945, -0.448034, 0.825633, 0.342922, -0.365963, 0.825689, 0.429311, -0.268013, 0.825791, 0.496223, -0.161139, 0.825895, 0.540306, -0.052725, 0.825960, 0.561258, 0.052311, 0.825969, 0.561283, 0.160200, 0.825969, 0.540473, 0.267053, 0.825969, 0.496445, 0.365423, 0.825969, 0.429234, 0.448089, 0.825969, 0.342041, 0.509680, 0.825969, 0.240836, 0.547789, 0.825969, 0.133053, 0.563118, 0.825969, 0.025949, 0.552757, 0.823254, -0.129275, 0.524118, 0.821914, -0.223064, 0.477247, 0.821036, -0.313265, 0.413132, 0.820688, -0.394706, 0.334646, 0.820897, -0.462752, 0.246156, 0.821648, -0.514103, 0.152782, 0.822881, -0.547289, 0.059537, 0.824504, -0.562716, -0, 0.880666, -0.473738, -0.089042, 0.880666, -0.465295, -0.180017, 0.880666, -0.438203, -0.267053, 0.880666, -0.391293, -0.343814, 0.880666, -0.325914, -0.404852, 0.880666, -0.246014, -0.446827, 0.880666, -0.157396, -0.469062, 0.880666, -0.066398, -0.473132, 0.880606, 0.026058, -0.460017, 0.880429, 0.115018, -0.428083, 0.880319, 0.204409, -0.376705, 0.880297, 0.288392, -0.307715, 0.880359, 0.360942, -0.225360, 0.880471, 0.417113, -0.135499, 0.880585, 0.454103, -0.044339, 0.880656, 0.471677, 0.043961, 0.880666, 0.471694, 0.134630, 0.880666, 0.454206, 0.224428, 0.880666, 0.417205, 0.307096, 0.880666, 0.360722, 0.376567, 0.880666, 0.287446, 0.428327, 0.880666, 0.202395, 0.460353, 0.880666, 0.111816, 0.473236, 0.880666, 0.021807, 0.464332, 0.876860, -0.124549, 0.441044, 0.874997, -0.199648, 0.403270, 0.873771, -0.271841, 0.351815, 0.873284, -0.337049, 0.288954, 0.873577, -0.391623, 0.218130, 0.874626, -0.432952, 0.143378, 0.876342, -0.459856, 0.068657, 0.878588, -0.472620, -0, 0.924989, -0.379993, -0.071422, 0.924989, -0.373221, -0.144395, 0.924989, -0.351490, -0.214208, 0.924989, -0.313863, -0.275779, 0.924989, -0.261421, -0.324738, 0.924989, -0.197332, -0.358407, 0.924989, -0.126250, -0.376242, 0.924989, -0.053259, -0.379528, 0.924938, 0.021151, -0.369081, 0.924785, 0.092473, -0.343514, 0.924690, 0.164152, -0.302315, 0.924672, 0.231491, -0.246959, 0.924725, 0.289647, -0.180866, 0.924821, 0.334653, -0.108748, 0.924920, 0.364276, -0.035588, 0.924981, 0.378343, 0.035262, 0.924989, 0.378354, 0.107989, 0.924989, 0.364326, 0.180017, 0.924989, 0.334647, 0.246327, 0.924989, 0.289341, 0.302051, 0.924989, 0.230565, 0.343569, 0.924989, 0.162344, 0.369257, 0.924989, 0.089689, 0.379591, 0.924989, 0.017492, 0.372484, 0.920382, -0.118965, 0.354909, 0.918397, -0.174890, 0.326612, 0.917088, -0.228635, 0.288208, 0.916567, -0.277202, 0.241377, 0.916881, -0.317910, 0.188650, 0.918001, -0.348834, 0.132990, 0.919831, -0.369087, 0.077317, 0.922220, -0.378856, -0, 0.958769, -0.284187, -0.053415, 0.958769, -0.279122, -0.107989, 0.958769, -0.262870, -0.160201, 0.958769, -0.234730, -0.206248, 0.958769, -0.195510, -0.242864, 0.958769, -0.147580, -0.268044, 0.958769, -0.094419, -0.281382, 0.958769, -0.039831, -0.283854, 0.958734, 0.015998, -0.276095, 0.958628, 0.069313, -0.257009, 0.958562, 0.122904, -0.226207, 0.958549, 0.173248, -0.184793, 0.958586, 0.216714, -0.135338, 0.958653, 0.250337, -0.081375, 0.958721, 0.272456, -0.026631, 0.958763, 0.282956, 0.026372, 0.958769, 0.282961, 0.080762, 0.958769, 0.272470, 0.134630, 0.958769, 0.250274, 0.184221, 0.958769, 0.216391, 0.225896, 0.958769, 0.172434, 0.256946, 0.958769, 0.121413, 0.276158, 0.958769, 0.067076, 0.283886, 0.958769, 0.013082, 0.278799, 0.953728, -0.112578, 0.267088, 0.952059, -0.149153, 0.248431, 0.950959, -0.184280, 0.223242, 0.950521, -0.216038, 0.192609, 0.950785, -0.242714, 0.158148, 0.951726, -0.263070, 0.121754, 0.953264, -0.276519, 0.085308, 0.955274, -0.283151, -0, 0.982177, -0.187958, -0.035328, 0.982177, -0.184608, -0.071422, 0.982177, -0.173859, -0.105955, 0.982177, -0.155247, -0.136410, 0.982177, -0.129308, -0.160627, 0.982177, -0.097607, -0.177280, 0.982177, -0.062447, -0.186102, 0.982177, -0.026344, -0.187747, 0.982159, 0.010695, -0.182648, 0.982104, 0.045941, -0.170046, 0.982071, 0.081374, -0.149680, 0.982064, 0.114659, -0.122281, 0.982083, 0.143390, -0.089557, 0.982117, 0.165606, -0.053849, 0.982152, 0.180213, -0.017624, 0.982174, 0.187145, 0.017442, 0.982177, 0.187147, 0.053415, 0.982177, 0.180208, 0.089043, 0.982177, 0.165528, 0.121841, 0.982177, 0.143118, 0.149404, 0.982177, 0.114046, 0.169941, 0.982177, 0.080301, 0.182647, 0.982177, 0.044363, 0.187758, 0.982177, 0.008652, 0.184782, 0.977104, -0.105465, 0.178883, 0.976177, -0.122798, 0.169815, 0.975570, -0.139380, 0.157797, 0.975329, -0.154382, 0.143310, 0.975474, -0.167072, 0.127047, 0.975993, -0.176909, 0.109823, 0.976846, -0.183606, 0.092468, 0.977969, -0.187152, -0, 0.995685, -0.092798, -0.017443, 0.995685, -0.091144, -0.035262, 0.995685, -0.085837, -0.052311, 0.995685, -0.076648, -0.067347, 0.995685, -0.063841, -0.079304, 0.995685, -0.048190, -0.087526, 0.995685, -0.030831, -0.091882, 0.995685, -0.013006, -0.092697, 0.995680, 0.005334, -0.090194, 0.995665, 0.022728, -0.083982, 0.995655, 0.040215, -0.073929, 0.995654, 0.056643, -0.060399, 0.995659, 0.070820, -0.044236, 0.995668, 0.081778, -0.026600, 0.995678, 0.088980, -0.008706, 0.995684, 0.092397, 0.008611, 0.995685, 0.092397, 0.026371, 0.995685, 0.088972, 0.043961, 0.995685, 0.081724, 0.060155, 0.995685, 0.070660, 0.073763, 0.995685, 0.056306, 0.083902, 0.995685, 0.039645, 0.090176, 0.995685, 0.021903, 0.092699, 0.995685, 0.004272, 0.091797, 0.990971, -0.097723, 0.091479, 0.991153, -0.096168, 0.091765, 0.991287, -0.094498, 0.092681, 0.991344, -0.092996, 0.094095, 0.991309, -0.091937, 0.095751, 0.991192, -0.091490, 0.097358, 0.991019, -0.091668, 0.098685, 0.990825, -0.092345, -0.004408, 0.998911, -0.046449, -0.013321, 0.998910, -0.044744, -0.022161, 0.998909, -0.041112, -0.030288, 0.998908, -0.035565, -0.037119, 0.998908, -0.028360, -0.042206, 0.998909, -0.019988, -0.045344, 0.998910, -0.011080, -0.046619, 0.998911, -0.002074, -0.046196, 0.998907, 0.007088, -0.044045, 0.998903, 0.015919, -0.039966, 0.998900, 0.024514, -0.034012, 0.998900, 0.032267, -0.026494, 0.998903, 0.038618, -0.017919, 0.998906, 0.043190, -0.008929, 0.998909, 0.045827, -0, 0.998911, 0.046650, 0.008842, 0.998910, 0.045826, 0.017786, 0.998909, 0.043175, 0.026349, 0.998909, 0.038569, 0.033902, 0.998908, 0.032138, 0.039901, 0.998909, 0.024279, 0.044018, 0.998909, 0.015567, 0.046194, 0.998911, 0.006608, 0.049679, 0.996182, -0.071781, 0.047532, 0.995117, -0.086501, 0.051132, 0.995763, -0.076426, 0.056942, 0.996132, -0.066921, 0.064725, 0.996174, -0.058717, 0.073959, 0.995884, -0.052385, 0.083974, 0.995301, -0.048222, 0.094038, 0.994494, -0.046244, 0.094038, 0.994494, -0.046244, -0.013209, -0.990162, -0.139299, -0.039913, -0.990173, -0.134029, -0.066321, -0.990182, -0.123052, -0.090620, -0.990186, -0.106395, -0.111062, -0.990185, -0.084843, -0.126342, -0.990180, -0.059844, -0.135866, -0.990171, -0.033198, -0.139783, -0.990160, -0.006615, -0.138491, -0.990165, 0.019822, -0.131831, -0.990176, 0.046611, -0.119403, -0.990183, 0.072666, -0.101419, -0.990186, 0.096153, -0.078849, -0.990184, 0.115402, -0.053264, -0.990178, 0.129269, -0.026493, -0.990168, 0.137351, -0, -0.990159, 0.139944, 0.026493, -0.990168, 0.137351, 0.053264, -0.990178, 0.129269, 0.078849, -0.990184, 0.115402, 0.101419, -0.990186, 0.096153, 0.119403, -0.990183, 0.072666, 0.131831, -0.990176, 0.046611, 0.138491, -0.990165, 0.019822, 0.139783, -0.990160, -0.006615, 0.135867, -0.990171, -0.033198, 0.126343, -0.990180, -0.059844, 0.111062, -0.990185, -0.084843, 0.090620, -0.990186, -0.106395, 0.066321, -0.990182, -0.123052, 0.039914, -0.990173, -0.134029, 0.013209, -0.990162, -0.139299, -0.022218, -0.971907, -0.234313, -0.067139, -0.971938, -0.225453, -0.111562, -0.971961, -0.206992, -0.152438, -0.971973, -0.178974, -0.186824, -0.971971, -0.142720, -0.212527, -0.971956, -0.100666, -0.228544, -0.971931, -0.055844, -0.235126, -0.971901, -0.011126, -0.232957, -0.971915, 0.033342, -0.221758, -0.971945, 0.078406, -0.200854, -0.971965, 0.122235, -0.170603, -0.971974, 0.161746, -0.132637, -0.971968, 0.194125, -0.089598, -0.971951, 0.217449, -0.044564, -0.971923, 0.231040, -0, -0.971899, 0.235398, 0.044564, -0.971923, 0.231040, 0.089598, -0.971951, 0.217449, 0.132637, -0.971969, 0.194125, 0.170603, -0.971974, 0.161746, 0.200854, -0.971965, 0.122235, 0.221757, -0.971944, 0.078407, 0.232957, -0.971915, 0.033343, 0.235126, -0.971901, -0.011126, 0.228544, -0.971931, -0.055843, 0.212527, -0.971956, -0.100666, 0.186824, -0.971971, -0.142720, 0.152438, -0.971973, -0.178974, 0.111562, -0.971961, -0.206992, 0.067140, -0.971938, -0.225453, 0.022219, -0.971907, -0.234313, -0.031265, -0.943562, -0.329718, -0.094479, -0.943621, -0.317260, -0.156995, -0.943665, -0.291288, -0.214519, -0.943688, -0.251863, -0.262909, -0.943684, -0.200844, -0.299075, -0.943656, -0.141661, -0.321607, -0.943607, -0.078583, -0.330860, -0.943550, -0.015657, -0.327812, -0.943577, 0.046919, -0.312061, -0.943633, 0.110335, -0.282652, -0.943673, 0.172015, -0.240084, -0.943689, 0.227618, -0.186654, -0.943680, 0.273183, -0.126085, -0.943645, 0.306001, -0.062710, -0.943592, 0.325117, -0, -0.943546, 0.331241, 0.062710, -0.943592, 0.325117, 0.126085, -0.943645, 0.306001, 0.186654, -0.943680, 0.273183, 0.240083, -0.943689, 0.227619, 0.282651, -0.943673, 0.172016, 0.312061, -0.943633, 0.110336, 0.327812, -0.943577, 0.046919, 0.330860, -0.943550, -0.015656, 0.321607, -0.943607, -0.078583, 0.299076, -0.943656, -0.141661, 0.262910, -0.943684, -0.200844, 0.214520, -0.943688, -0.251862, 0.156995, -0.943665, -0.291288, 0.094480, -0.943621, -0.317260, 0.031266, -0.943562, -0.329718, -0.040203, -0.904781, -0.423976, -0.121494, -0.904874, -0.407974, -0.201890, -0.904944, -0.374588, -0.275869, -0.904981, -0.323892, -0.338097, -0.904975, -0.258283, -0.384599, -0.904930, -0.182171, -0.413559, -0.904852, -0.101051, -0.425441, -0.904762, -0.020133, -0.421530, -0.904805, 0.060332, -0.401292, -0.904894, 0.141884, -0.363483, -0.904957, 0.221207, -0.308745, -0.904983, 0.292715, -0.240034, -0.904967, 0.351308, -0.162139, -0.904913, 0.393502, -0.080639, -0.904829, 0.418069, -0, -0.904756, 0.425931, 0.080639, -0.904829, 0.418069, 0.162139, -0.904913, 0.393502, 0.240034, -0.904967, 0.351309, 0.308745, -0.904983, 0.292715, 0.363483, -0.904957, 0.221208, 0.401292, -0.904894, 0.141885, 0.421530, -0.904805, 0.060333, 0.425441, -0.904762, -0.020132, 0.413559, -0.904852, -0.101051, 0.384599, -0.904930, -0.182170, 0.338098, -0.904975, -0.258282, 0.275870, -0.904981, -0.323892, 0.201891, -0.904944, -0.374587, 0.121495, -0.904874, -0.407973, 0.040204, -0.904781, -0.423976, -0.048876, -0.855532, -0.515438, -0.147710, -0.855662, -0.496008, -0.245464, -0.855761, -0.455435, -0.335416, -0.855811, -0.393805, -0.411075, -0.855804, -0.314033, -0.467602, -0.855740, -0.221487, -0.502793, -0.855632, -0.122855, -0.517214, -0.855506, -0.024475, -0.512470, -0.855567, 0.073348, -0.487890, -0.855691, 0.172502, -0.441936, -0.855779, 0.268952, -0.375389, -0.855815, 0.355898, -0.291844, -0.855793, 0.427136, -0.197130, -0.855717, 0.478423, -0.098037, -0.855600, 0.508269, 0, -0.855497, 0.517807, 0.098037, -0.855600, 0.508269, 0.197130, -0.855717, 0.478423, 0.291844, -0.855793, 0.427136, 0.375388, -0.855815, 0.355899, 0.441936, -0.855779, 0.268953, 0.487889, -0.855691, 0.172503, 0.512470, -0.855567, 0.073349, 0.517214, -0.855506, -0.024475, 0.502793, -0.855632, -0.122854, 0.467603, -0.855740, -0.221486, 0.411076, -0.855804, -0.314032, 0.335417, -0.855812, -0.393804, 0.245465, -0.855761, -0.455434, 0.147711, -0.855662, -0.496007, 0.048877, -0.855532, -0.515438, -0.057123, -0.796135, -0.602417, -0.172645, -0.796300, -0.579741, -0.286914, -0.796426, -0.532341, -0.392064, -0.796490, -0.460315, -0.480500, -0.796480, -0.367068, -0.546559, -0.796399, -0.258886, -0.587664, -0.796262, -0.143593, -0.604487, -0.796101, -0.028605, -0.598958, -0.796178, 0.085727, -0.570259, -0.796336, 0.201626, -0.516567, -0.796448, 0.314371, -0.438788, -0.796494, 0.416006, -0.341130, -0.796466, 0.499271, -0.230414, -0.796369, 0.559200, -0.114584, -0.796221, 0.594056, -0, -0.796090, 0.605178, 0.114584, -0.796221, 0.594056, 0.230414, -0.796369, 0.559201, 0.341130, -0.796466, 0.499271, 0.438788, -0.796495, 0.416007, 0.516567, -0.796448, 0.314371, 0.570259, -0.796336, 0.201626, 0.598958, -0.796178, 0.085728, 0.604487, -0.796101, -0.028604, 0.587664, -0.796262, -0.143592, 0.546559, -0.796399, -0.258884, 0.480501, -0.796480, -0.367067, 0.392066, -0.796490, -0.460314, 0.286915, -0.796426, -0.532340, 0.172647, -0.796300, -0.579741, 0.057125, -0.796135, -0.602417, -0.064792, -0.727270, -0.683287, -0.195833, -0.727464, -0.657606, -0.325464, -0.727612, -0.603866, -0.444753, -0.727687, -0.522175, -0.545071, -0.727676, -0.416396, -0.619989, -0.727581, -0.293667, -0.666583, -0.727419, -0.162877, -0.685626, -0.727231, -0.032445, -0.679374, -0.727321, 0.097236, -0.646859, -0.727507, 0.228709, -0.585978, -0.727638, 0.356613, -0.497757, -0.727693, 0.471913, -0.386970, -0.727660, 0.566361, -0.261367, -0.727546, 0.634322, -0.129970, -0.727371, 0.673824, -0, -0.727218, 0.686407, 0.129970, -0.727371, 0.673824, 0.261367, -0.727546, 0.634322, 0.386970, -0.727660, 0.566362, 0.497756, -0.727693, 0.471913, 0.585977, -0.727638, 0.356613, 0.646859, -0.727507, 0.228710, 0.679374, -0.727321, 0.097237, 0.685626, -0.727231, -0.032444, 0.666583, -0.727419, -0.162875, 0.619989, -0.727581, -0.293665, 0.545072, -0.727676, -0.416394, 0.444754, -0.727687, -0.522174, 0.325465, -0.727612, -0.603866, 0.195835, -0.727464, -0.657605, 0.064793, -0.727270, -0.683287, -0.071741, -0.649965, -0.756571, -0.216850, -0.650178, -0.728179, -0.360408, -0.650339, -0.668703, -0.492517, -0.650422, -0.578254, -0.603607, -0.650410, -0.461113, -0.686550, -0.650306, -0.325195, -0.738110, -0.650128, -0.180354, -0.759152, -0.649922, -0.035924, -0.752250, -0.650021, 0.107667, -0.716289, -0.650224, 0.253257, -0.648900, -0.650368, 0.394905, -0.551215, -0.650428, 0.522595, -0.428526, -0.650392, 0.627181, -0.289424, -0.650267, 0.702415, -0.143914, -0.650076, 0.746117, -0, -0.649908, 0.760013, 0.143914, -0.650076, 0.746117, 0.289424, -0.650267, 0.702415, 0.428525, -0.650392, 0.627181, 0.551214, -0.650428, 0.522596, 0.648899, -0.650368, 0.394906, 0.716288, -0.650224, 0.253258, 0.752250, -0.650021, 0.107668, 0.759152, -0.649922, -0.035923, 0.738110, -0.650128, -0.180353, 0.686551, -0.650306, -0.325193, 0.603608, -0.650410, -0.461112, 0.492519, -0.650422, -0.578253, 0.360410, -0.650340, -0.668702, 0.216852, -0.650178, -0.728179, 0.071743, -0.649965, -0.756571, -0.077853, -0.565545, -0.821035, -0.235340, -0.565763, -0.790270, -0.391157, -0.565929, -0.725755, -0.534549, -0.566014, -0.627603, -0.655117, -0.566001, -0.500463, -0.745117, -0.565894, -0.352936, -0.801036, -0.565712, -0.195730, -0.823826, -0.565501, -0.038985, -0.816359, -0.565603, 0.116843, -0.777375, -0.565811, 0.274855, -0.704267, -0.565959, 0.428601, -0.598257, -0.566020, 0.567195, -0.465093, -0.565983, 0.680700, -0.314111, -0.565855, 0.762327, -0.156181, -0.565659, 0.809715, -0, -0.565486, 0.824758, 0.156181, -0.565659, 0.809715, 0.314110, -0.565855, 0.762327, 0.465092, -0.565983, 0.680700, 0.598256, -0.566020, 0.567195, 0.704267, -0.565959, 0.428601, 0.777375, -0.565811, 0.274856, 0.816359, -0.565603, 0.116844, 0.823826, -0.565501, -0.038984, 0.801037, -0.565712, -0.195728, 0.745118, -0.565894, -0.352934, 0.655119, -0.566001, -0.500462, 0.534551, -0.566014, -0.627602, 0.391159, -0.565929, -0.725754, 0.235342, -0.565763, -0.790269, 0.077855, -0.565545, -0.821034, -0.083042, -0.475560, -0.875755, -0.251038, -0.475770, -0.842985, -0.417266, -0.475928, -0.774197, -0.570241, -0.476009, -0.669508, -0.698857, -0.475997, -0.533877, -0.794845, -0.475895, -0.376490, -0.854459, -0.475721, -0.208783, -0.878722, -0.475518, -0.041583, -0.870779, -0.475616, 0.124632, -0.829239, -0.475815, 0.293193, -0.751281, -0.475957, 0.457212, -0.638203, -0.476015, 0.605067, -0.496143, -0.475980, 0.726144, -0.335071, -0.475857, 0.813196, -0.166595, -0.475669, 0.863704, -0, -0.475505, 0.879713, 0.166594, -0.475669, 0.863704, 0.335070, -0.475857, 0.813196, 0.496143, -0.475980, 0.726145, 0.638203, -0.476015, 0.605068, 0.751280, -0.475957, 0.457213, 0.829239, -0.475815, 0.293194, 0.870779, -0.475616, 0.124633, 0.878722, -0.475519, -0.041581, 0.854459, -0.475721, -0.208782, 0.794846, -0.475895, -0.376488, 0.698858, -0.475997, -0.533876, 0.570242, -0.476009, -0.669506, 0.417268, -0.475928, -0.774196, 0.251041, -0.475770, -0.842984, 0.083044, -0.475560, -0.875755, -0.087253, -0.381695, -0.920161, -0.263780, -0.381880, -0.885770, -0.438459, -0.382020, -0.813519, -0.599214, -0.382092, -0.703525, -0.734364, -0.382082, -0.561002, -0.835210, -0.381991, -0.395609, -0.897816, -0.381837, -0.219377, -0.923271, -0.381657, -0.043691, -0.914944, -0.381744, 0.130953, -0.871336, -0.381920, 0.308077, -0.789444, -0.382046, 0.480437, -0.670631, -0.382098, 0.635811, -0.521348, -0.382066, 0.763034, -0.352084, -0.381957, 0.854486, -0.175046, -0.381791, 0.907521, -0, -0.381645, 0.924309, 0.175046, -0.381791, 0.907521, 0.352083, -0.381957, 0.854486, 0.521348, -0.382066, 0.763035, 0.670630, -0.382098, 0.635812, 0.789443, -0.382046, 0.480438, 0.871335, -0.381920, 0.308078, 0.914944, -0.381744, 0.130954, 0.923271, -0.381657, -0.043689, 0.897817, -0.381837, -0.219376, 0.835211, -0.381991, -0.395608, 0.734365, -0.382082, -0.561000, 0.599216, -0.382092, -0.703524, 0.438461, -0.382020, -0.813518, 0.263782, -0.381880, -0.885769, 0.087255, -0.381695, -0.920161, -0.090466, -0.285665, -0.954050, -0.273504, -0.285814, -0.918426, -0.454637, -0.285927, -0.843535, -0.621332, -0.285985, -0.729493, -0.761468, -0.285977, -0.581708, -0.866021, -0.285904, -0.410203, -0.930909, -0.285779, -0.227463, -0.957267, -0.285635, -0.045300, -0.948650, -0.285704, 0.135777, -0.903466, -0.285847, 0.319437, -0.818575, -0.285948, 0.498166, -0.695385, -0.285989, 0.659280, -0.540589, -0.285964, 0.791194, -0.365070, -0.285877, 0.886002, -0.181496, -0.285743, 0.940962, -0, -0.285625, 0.958341, 0.181496, -0.285743, 0.940962, 0.365069, -0.285877, 0.886002, 0.540588, -0.285964, 0.791194, 0.695384, -0.285989, 0.659281, 0.818574, -0.285948, 0.498167, 0.903466, -0.285847, 0.319438, 0.948650, -0.285704, 0.135778, 0.957267, -0.285635, -0.045298, 0.930909, -0.285779, -0.227462, 0.866022, -0.285904, -0.410201, 0.761469, -0.285977, -0.581706, 0.621333, -0.285985, -0.729491, 0.454639, -0.285927, -0.843534, 0.273507, -0.285814, -0.918425, 0.090469, -0.285665, -0.954050, -0.092696, -0.189131, -0.977567, -0.280253, -0.189234, -0.941089, -0.465865, -0.189313, -0.864367, -0.636683, -0.189353, -0.747516, -0.780280, -0.189347, -0.596079, -0.887405, -0.189297, -0.420332, -0.953874, -0.189210, -0.233075, -0.980858, -0.189110, -0.046416, -0.972041, -0.189158, 0.139125, -0.925766, -0.189257, 0.327321, -0.838794, -0.189327, 0.510471, -0.712566, -0.189356, 0.675569, -0.553943, -0.189339, 0.810739, -0.374082, -0.189278, 0.907875, -0.185973, -0.189185, 0.964170, -0, -0.189103, 0.981957, 0.185972, -0.189185, 0.964170, 0.374082, -0.189278, 0.907875, 0.553943, -0.189339, 0.810740, 0.712565, -0.189356, 0.675570, 0.838793, -0.189327, 0.510471, 0.925765, -0.189257, 0.327323, 0.972041, -0.189158, 0.139126, 0.980858, -0.189110, -0.046414, 0.953874, -0.189210, -0.233073, 0.887406, -0.189297, -0.420330, 0.780282, -0.189347, -0.596077, 0.636685, -0.189353, -0.747514, 0.465867, -0.189313, -0.864366, 0.280256, -0.189234, -0.941088, 0.092699, -0.189131, -0.977567, -0.093985, -0.093612, -0.991163, -0.284156, -0.093665, -0.954192, -0.472356, -0.093705, -0.876412, -0.645559, -0.093725, -0.757937, -0.791158, -0.093722, -0.604389, -0.899769, -0.093697, -0.426189, -0.967152, -0.093653, -0.236319, -0.994497, -0.093602, -0.047061, -0.985564, -0.093626, 0.141060, -0.938659, -0.093676, 0.331880, -0.850484, -0.093712, 0.517585, -0.722500, -0.093727, 0.684988, -0.561665, -0.093718, 0.822040, -0.379293, -0.093687, 0.920521, -0.188561, -0.093640, 0.977587, -0, -0.093598, 0.995610, 0.188560, -0.093640, 0.977587, 0.379293, -0.093687, 0.920521, 0.561664, -0.093718, 0.822040, 0.722500, -0.093727, 0.684988, 0.850484, -0.093712, 0.517586, 0.938658, -0.093676, 0.331881, 0.985564, -0.093626, 0.141061, 0.994497, -0.093602, -0.047060, 0.967152, -0.093653, -0.236317, 0.899770, -0.093697, -0.426187, 0.791159, -0.093722, -0.604387, 0.645561, -0.093725, -0.757936, 0.472359, -0.093705, -0.876411, 0.284158, -0.093665, -0.954191, 0.093988, -0.093612, -0.991162, -0.094400, -0, -0.995534, -0.285410, -0, -0.958405, -0.474444, -0, -0.880286, -0.648413, -0, -0.761289, -0.794656, -0, -0.607061, -0.903745, -0, -0.428072, -0.971421, -0, -0.237362, -0.998889, 0.000135, -0.047135, -0.989879, 0.000744, 0.141914, -0.942750, 0.001512, 0.333497, -0.854200, 0.001866, 0.519942, -0.725686, 0.001764, 0.688024, -0.564177, 0.001308, 0.825653, -0.381018, 0.000715, 0.924568, -0.189430, 0.000233, 0.981894, -0.000012, 0.000025, 1, 0.189393, -0, 0.981901, 0.380968, -0, 0.924588, 0.564147, -0, 0.825674, 0.725694, -0, 0.688017, 0.854243, -0, 0.519874, 0.942804, -0, 0.333347, 0.989912, -0, 0.141684, 0.998880, 0.000152, -0.047313, 0.971403, 0.000478, -0.237438, 0.903723, 0.000773, -0.428117, 0.794644, 0.000944, -0.607075, 0.648424, 0.000964, -0.761278, 0.474485, 0.000829, -0.880263, 0.285483, 0.000561, -0.958384, 0.094499, 0.000199, -0.995525, -0.093985, 0.093612, -0.991163, -0.284156, 0.093665, -0.954192, -0.472356, 0.093705, -0.876413, -0.645559, 0.093725, -0.757937, -0.791158, 0.093722, -0.604389, -0.899769, 0.093696, -0.426188, -0.967152, 0.093653, -0.236319, -0.994497, 0.093860, -0.046537, -0.985303, 0.095020, 0.141946, -0.938194, 0.096510, 0.332382, -0.850032, 0.097210, 0.517684, -0.722239, 0.097034, 0.684803, -0.561650, 0.096170, 0.821767, -0.379436, 0.095028, 0.920325, -0.188700, 0.094077, 0.977518, -0.000046, 0.093645, 0.995606, 0.188560, 0.093640, 0.977587, 0.379293, 0.093687, 0.920521, 0.561664, 0.093718, 0.822040, 0.722500, 0.093727, 0.684989, 0.850484, 0.093712, 0.517586, 0.938658, 0.093676, 0.331881, 0.985564, 0.093626, 0.141061, 0.994422, 0.094167, -0.047512, 0.966802, 0.095416, -0.237045, 0.899303, 0.096547, -0.426537, 0.790770, 0.097201, -0.604347, 0.645434, 0.097277, -0.757597, 0.472608, 0.096761, -0.875944, 0.284798, 0.095735, -0.953795, 0.094938, 0.094347, -0.991002, -0.092696, 0.189131, -0.977567, -0.280254, 0.189234, -0.941089, -0.465865, 0.189313, -0.864367, -0.636683, 0.189353, -0.747516, -0.780280, 0.189347, -0.596079, -0.887405, 0.189296, -0.420332, -0.953874, 0.189210, -0.233075, -0.980860, 0.189345, -0.045404, -0.971562, 0.190346, 0.140837, -0.924919, 0.191675, 0.328308, -0.837977, 0.192314, 0.510696, -0.712108, 0.192181, 0.675254, -0.553940, 0.191434, 0.810249, -0.374369, 0.190425, 0.907517, -0.186243, 0.189561, 0.964044, -0.000089, 0.189144, 0.981949, 0.185972, 0.189185, 0.964170, 0.374082, 0.189278, 0.907875, 0.553943, 0.189338, 0.810740, 0.712566, 0.189356, 0.675570, 0.838793, 0.189327, 0.510471, 0.925766, 0.189257, 0.327323, 0.972041, 0.189158, 0.139126, 0.980588, 0.190129, -0.047931, 0.952656, 0.192317, -0.235502, 0.885777, 0.194317, -0.421473, 0.778911, 0.195470, -0.595893, 0.636204, 0.195603, -0.746314, 0.466668, 0.194693, -0.862737, 0.282385, 0.192883, -0.939710, 0.095887, 0.190423, -0.977008, -0.090466, 0.285665, -0.954050, -0.273504, 0.285814, -0.918426, -0.454637, 0.285927, -0.843535, -0.621332, 0.285985, -0.729493, -0.761468, 0.285976, -0.581708, -0.866021, 0.285903, -0.410203, -0.930909, 0.285779, -0.227463, -0.957271, 0.285847, -0.043852, -0.948008, 0.286659, 0.138232, -0.902337, 0.287795, 0.320876, -0.817500, 0.288355, 0.498543, -0.694805, 0.288268, 0.658899, -0.540628, 0.287656, 0.790554, -0.365496, 0.286805, 0.885526, -0.181886, 0.286050, 0.940794, -0.000127, 0.285660, 0.958331, 0.181496, 0.285742, 0.940962, 0.365069, 0.285876, 0.886002, 0.540588, 0.285964, 0.791195, 0.695384, 0.285989, 0.659281, 0.818574, 0.285947, 0.498167, 0.903466, 0.285846, 0.319438, 0.948650, 0.285704, 0.135778, 0.956711, 0.286961, -0.048545, 0.928421, 0.289646, -0.232680, 0.862731, 0.292151, -0.412728, 0.758749, 0.293592, -0.581467, 0.620476, 0.293757, -0.727128, 0.456453, 0.292622, -0.840252, 0.278096, 0.290355, -0.915618, 0.097295, 0.287265, -0.952897, -0.087253, 0.381694, -0.920161, -0.263780, 0.381880, -0.885770, -0.438459, 0.382020, -0.813520, -0.599214, 0.382092, -0.703525, -0.734364, 0.382081, -0.561002, -0.835210, 0.381990, -0.395609, -0.897817, 0.381836, -0.219377, -0.923276, 0.381849, -0.041873, -0.914200, 0.382452, 0.134048, -0.870040, 0.383374, 0.309929, -0.788231, 0.383844, 0.480995, -0.670013, 0.383802, 0.635436, -0.521463, 0.383334, 0.762320, -0.352644, 0.382656, 0.853942, -0.175540, 0.382026, 0.907327, -0.000160, 0.381674, 0.924297, 0.175046, 0.381791, 0.907521, 0.352083, 0.381957, 0.854486, 0.521348, 0.382066, 0.763035, 0.670630, 0.382097, 0.635812, 0.789443, 0.382045, 0.480438, 0.871335, 0.381920, 0.308078, 0.914944, 0.381743, 0.130954, 0.922379, 0.383130, -0.049274, 0.893859, 0.385803, -0.228410, 0.830059, 0.388416, -0.400168, 0.730239, 0.389915, -0.560997, 0.598192, 0.390087, -0.699999, 0.441845, 0.388906, -0.808409, 0.271764, 0.386544, -0.881322, 0.099001, 0.383311, -0.918298, -0.083042, 0.475560, -0.875755, -0.251038, 0.475769, -0.842985, -0.417266, 0.475928, -0.774198, -0.570241, 0.476009, -0.669508, -0.698857, 0.475997, -0.533878, -0.794846, 0.475894, -0.376490, -0.854459, 0.475720, -0.208783, -0.878727, 0.475689, -0.039469, -0.869999, 0.476082, 0.128245, -0.827896, 0.476785, 0.295405, -0.750053, 0.477161, 0.457971, -0.637633, 0.477158, 0.604768, -0.496362, 0.476832, 0.725435, -0.335755, 0.476330, 0.812637, -0.167175, 0.475833, 0.863502, -0.000186, 0.475528, 0.879701, 0.166594, 0.475669, 0.863704, 0.335070, 0.475857, 0.813196, 0.496143, 0.475979, 0.726145, 0.638203, 0.476015, 0.605068, 0.751280, 0.475956, 0.457213, 0.829239, 0.475815, 0.293194, 0.870779, 0.475615, 0.124633, 0.877492, 0.476974, -0.050036, 0.849059, 0.479126, -0.222570, 0.787971, 0.481464, -0.383790, 0.693609, 0.482802, -0.534610, 0.569507, 0.482956, -0.665144, 0.422875, 0.481902, -0.767429, 0.263295, 0.479789, -0.836946, 0.100837, 0.476890, -0.873160, -0.077853, 0.565544, -0.821035, -0.235340, 0.565763, -0.790270, -0.391157, 0.565929, -0.725755, -0.534549, 0.566013, -0.627603, -0.655118, 0.566001, -0.500464, -0.745118, 0.565894, -0.352936, -0.801037, 0.565712, -0.195730, -0.823829, 0.565651, -0.036660, -0.815605, 0.565851, 0.120835, -0.776097, 0.566344, 0.277361, -0.703139, 0.566625, 0.429571, -0.597809, 0.566656, 0.567032, -0.465439, 0.566460, 0.680066, -0.314904, 0.566124, 0.761800, -0.156827, 0.565758, 0.809520, -0.000205, 0.565504, 0.824745, 0.156181, 0.565658, 0.809715, 0.314110, 0.565854, 0.762328, 0.465092, 0.565982, 0.680700, 0.598257, 0.566020, 0.567196, 0.704267, 0.565958, 0.428602, 0.777375, 0.565810, 0.274856, 0.816359, 0.565602, 0.116844, 0.822297, 0.566791, -0.050752, 0.794444, 0.567972, -0.215096, 0.736975, 0.569719, -0.363715, 0.649346, 0.570719, -0.502624, 0.534780, 0.570833, -0.623025, 0.399713, 0.570046, -0.717828, 0.252666, 0.568467, -0.782946, 0.102634, 0.566300, -0.817784, -0.071741, 0.649964, -0.756571, -0.216850, 0.650177, -0.728180, -0.360409, 0.650339, -0.668704, -0.492517, 0.650422, -0.578255, -0.603607, 0.650409, -0.461113, -0.686551, 0.650305, -0.325195, -0.738110, 0.650127, -0.180354, -0.759152, 0.650051, -0.033479, -0.751575, 0.650090, 0.111886, -0.715166, 0.650396, 0.255973, -0.647962, 0.650591, 0.396076, -0.550944, 0.650645, 0.522610, -0.429007, 0.650559, 0.626678, -0.290304, 0.650367, 0.701959, -0.144603, 0.650121, 0.745944, -0.000216, 0.649921, 0.760002, 0.143914, 0.650075, 0.746117, 0.289424, 0.650266, 0.702415, 0.428526, 0.650391, 0.627182, 0.551214, 0.650428, 0.522596, 0.648900, 0.650368, 0.394906, 0.716289, 0.650224, 0.253258, 0.752251, 0.650020, 0.107668, 0.757406, 0.650922, -0.051344, 0.730764, 0.650811, -0.205980, 0.677853, 0.651760, -0.340181, 0.598154, 0.652307, -0.465518, 0.494547, 0.652370, -0.574314, 0.372662, 0.651939, -0.660378, 0.239929, 0.651080, -0.720090, 0.104224, 0.649911, -0.752830, -0.064792, 0.727269, -0.683288, -0.195833, 0.727464, -0.657606, -0.325464, 0.727611, -0.603867, -0.444753, 0.727687, -0.522175, -0.545071, 0.727676, -0.416396, -0.619989, 0.727580, -0.293667, -0.666584, 0.727418, -0.162877, -0.685624, 0.727339, -0.029975, -0.678813, 0.727260, 0.101520, -0.645955, 0.727416, 0.231537, -0.585287, 0.727537, 0.357952, -0.497690, 0.727603, 0.472121, -0.387578, 0.727599, 0.566023, -0.262303, 0.727521, 0.633964, -0.130675, 0.727376, 0.673682, -0.000219, 0.727226, 0.686398, 0.129970, 0.727370, 0.673825, 0.261367, 0.727545, 0.634323, 0.386970, 0.727659, 0.566362, 0.497757, 0.727692, 0.471914, 0.585978, 0.727638, 0.356614, 0.646859, 0.727506, 0.228710, 0.679375, 0.727321, 0.097237, 0.683776, 0.727855, -0.051743, 0.659051, 0.726306, -0.195272, 0.611608, 0.726387, -0.313525, 0.540914, 0.726443, -0.423902, 0.449480, 0.726450, -0.519845, 0.342127, 0.726404, -0.596058, 0.225203, 0.726326, -0.649410, 0.105456, 0.726251, -0.679293, -0.057123, 0.796134, -0.602418, -0.172645, 0.796300, -0.579742, -0.286914, 0.796425, -0.532342, -0.392065, 0.796489, -0.460315, -0.480500, 0.796480, -0.367068, -0.546559, 0.796399, -0.258886, -0.587664, 0.796261, -0.143593, -0.604482, 0.796188, -0.026206, -0.598530, 0.796039, 0.089907, -0.569601, 0.796086, 0.204452, -0.516141, 0.796150, 0.315821, -0.438923, 0.796219, 0.416393, -0.341837, 0.796267, 0.499105, -0.231367, 0.796268, 0.558951, -0.115277, 0.796200, 0.593950, -0.000213, 0.796096, 0.605170, 0.114584, 0.796220, 0.594057, 0.230414, 0.796369, 0.559201, 0.341130, 0.796466, 0.499272, 0.438789, 0.796494, 0.416007, 0.516567, 0.796448, 0.314372, 0.570260, 0.796336, 0.201627, 0.598959, 0.796178, 0.085728, 0.602660, 0.796309, -0.051889, 0.580561, 0.793369, -0.183072, 0.539402, 0.792654, -0.284157, 0.478619, 0.792264, -0.378474, 0.400341, 0.792220, -0.460560, 0.308596, 0.792525, -0.525997, 0.208668, 0.793162, -0.572147, 0.106194, 0.794092, -0.598449, -0.048876, 0.855532, -0.515439, -0.147710, 0.855662, -0.496009, -0.245464, 0.855761, -0.455435, -0.335417, 0.855811, -0.393806, -0.411076, 0.855804, -0.314033, -0.467603, 0.855740, -0.221487, -0.502794, 0.855631, -0.122855, -0.517208, 0.855571, -0.022241, -0.512175, 0.855399, 0.077259, -0.487472, 0.855379, 0.175206, -0.441757, 0.855404, 0.270435, -0.375689, 0.855466, 0.356421, -0.292605, 0.855538, 0.427126, -0.198058, 0.855584, 0.478277, -0.098690, 0.855567, 0.508198, -0.000199, 0.855500, 0.517802, 0.098037, 0.855599, 0.508270, 0.197130, 0.855716, 0.478424, 0.291844, 0.855793, 0.427137, 0.375389, 0.855815, 0.355899, 0.441937, 0.855778, 0.268953, 0.487890, 0.855690, 0.172503, 0.512471, 0.855566, 0.073349, 0.515540, 0.855302, -0.051736, 0.496700, 0.851206, -0.169522, 0.462491, 0.849898, -0.252539, 0.412327, 0.849174, -0.329984, 0.347948, 0.849092, -0.397460, 0.272604, 0.849659, -0.451405, 0.190549, 0.850829, -0.489675, 0.106330, 0.852511, -0.511780, -0.040203, 0.904780, -0.423977, -0.121494, 0.904873, -0.407975, -0.201891, 0.904944, -0.374588, -0.275870, 0.904980, -0.323893, -0.338098, 0.904975, -0.258283, -0.384600, 0.904929, -0.182171, -0.413560, 0.904852, -0.101052, -0.425435, 0.904807, -0.018152, -0.421352, 0.904649, 0.063813, -0.401080, 0.904600, 0.144339, -0.363501, 0.904601, 0.222629, -0.309154, 0.904651, 0.293311, -0.240792, 0.904724, 0.351416, -0.162994, 0.904785, 0.393443, -0.081224, 0.904796, 0.418028, -0.000176, 0.904757, 0.425928, 0.080639, 0.904829, 0.418070, 0.162139, 0.904912, 0.393503, 0.240034, 0.904967, 0.351309, 0.308745, 0.904983, 0.292716, 0.363484, 0.904957, 0.221208, 0.401293, 0.904894, 0.141885, 0.421531, 0.904805, 0.060333, 0.424038, 0.904193, -0.051250, 0.408952, 0.899330, -0.154801, 0.382168, 0.897729, -0.219160, 0.343112, 0.896840, -0.279199, 0.293132, 0.896739, -0.331561, 0.234713, 0.897436, -0.373522, 0.171105, 0.898869, -0.403432, 0.105783, 0.900923, -0.420889, -0.031265, 0.943561, -0.329719, -0.094480, 0.943620, -0.317261, -0.156995, 0.943665, -0.291289, -0.214520, 0.943687, -0.251864, -0.262910, 0.943684, -0.200845, -0.299076, 0.943655, -0.141662, -0.321608, 0.943606, -0.078583, -0.330855, 0.943578, -0.014011, -0.327726, 0.943458, 0.049823, -0.312001, 0.943408, 0.112418, -0.282795, 0.943399, 0.173276, -0.240528, 0.943433, 0.228210, -0.187346, 0.943492, 0.273358, -0.126819, 0.943546, 0.306004, -0.063201, 0.943565, 0.325100, -0.000147, 0.943546, 0.331240, 0.062710, 0.943592, 0.325118, 0.126085, 0.943645, 0.306002, 0.186655, 0.943679, 0.273184, 0.240084, 0.943689, 0.227619, 0.282652, 0.943673, 0.172016, 0.312062, 0.943633, 0.110336, 0.327813, 0.943577, 0.046919, 0.329820, 0.942697, -0.050415, 0.318801, 0.937558, -0.139107, 0.299706, 0.936019, -0.184514, 0.272025, 0.935164, -0.226874, 0.236708, 0.935067, -0.263855, 0.195486, 0.935737, -0.293568, 0.150612, 0.937115, -0.314851, 0.104502, 0.939087, -0.327405, -0.022219, 0.971907, -0.234314, -0.067140, 0.971938, -0.225455, -0.111562, 0.971961, -0.206993, -0.152438, 0.971973, -0.178975, -0.186825, 0.971971, -0.142721, -0.212528, 0.971956, -0.100667, -0.228545, 0.971930, -0.055844, -0.235124, 0.971915, -0.009885, -0.232931, 0.971844, 0.035539, -0.221784, 0.971808, 0.080004, -0.201043, 0.971800, 0.123235, -0.171004, 0.971819, 0.162253, -0.133197, 0.971855, 0.194311, -0.090167, 0.971890, 0.217484, -0.044937, 0.971906, 0.231038, -0.000111, 0.971899, 0.235398, 0.044564, 0.971923, 0.231041, 0.089599, 0.971950, 0.217450, 0.132638, 0.971968, 0.194126, 0.170604, 0.971973, 0.161747, 0.200855, 0.971965, 0.122236, 0.221759, 0.971944, 0.078407, 0.232958, 0.971915, 0.033343, 0.234512, 0.970866, -0.049225, 0.227674, 0.965982, -0.122653, 0.216319, 0.964873, -0.149086, 0.200063, 0.964258, -0.173730, 0.179456, 0.964188, -0.195287, 0.155468, 0.964670, -0.212701, 0.129354, 0.965662, -0.225307, 0.102471, 0.967085, -0.232907, -0.013209, 0.990162, -0.139300, -0.039914, 0.990173, -0.134030, -0.066321, 0.990181, -0.123053, -0.090621, 0.990186, -0.106396, -0.111063, 0.990185, -0.084844, -0.126344, 0.990180, -0.059844, -0.135868, 0.990171, -0.033199, -0.139782, 0.990165, -0.005838, -0.138494, 0.990136, 0.021201, -0.131883, 0.990120, 0.047625, -0.119561, 0.990116, 0.073316, -0.101702, 0.990123, 0.096501, -0.079219, 0.990138, 0.115545, -0.053628, 0.990153, 0.129307, -0.026728, 0.990161, 0.137356, -0.000069, 0.990159, 0.139945, 0.026493, 0.990168, 0.137352, 0.053265, 0.990178, 0.129271, 0.078850, 0.990184, 0.115403, 0.101419, 0.990186, 0.096154, 0.119404, 0.990183, 0.072666, 0.131832, 0.990176, 0.046612, 0.138493, 0.990165, 0.019822, 0.139622, 0.989056, -0.047690, 0.136886, 0.984936, -0.105655, 0.133128, 0.984598, -0.113332, 0.128149, 0.984415, -0.120441, 0.122098, 0.984394, -0.126730, 0.115173, 0.984537, -0.131992, 0.107612, 0.984838, -0.136067, 0.099697, 0.985282, -0.138850, -0.867367, -0.493636, 0.063221, -0.861922, -0.503245, 0.061927, -0.856470, -0.512964, 0.057689, -0.851481, -0.521962, 0.050364, -0.847417, -0.529396, 0.040310, -0.844602, -0.534643, 0.028348, -0.843160, -0.537436, 0.015599, -0.843021, -0.537857, 0.005054, -0.839603, -0.541684, 0.040553, -0.826077, -0.555231, 0.096515, -0.801718, -0.577371, 0.154566, -0.764328, -0.608583, 0.213141, -0.711741, -0.648481, 0.269992, -0.642629, -0.695282, 0.321886, -0.557240, -0.745786, 0.365084, -0, -0.885378, 0.464872, 0.557247, -0.745782, 0.365082, 0.642625, -0.695284, 0.321890, 0.711746, -0.648478, 0.269990, 0.764320, -0.608590, 0.213151, 0.801720, -0.577370, 0.154559, 0.826075, -0.555233, 0.096522, 0.839604, -0.541684, 0.040548, 0.843022, -0.537856, 0.005050, 0.843161, -0.537435, 0.015599, 0.844603, -0.534642, 0.028352, 0.847416, -0.529397, 0.040308, 0.851481, -0.521961, 0.050364, 0.856471, -0.512962, 0.057691, 0.861918, -0.503253, 0.061926, 0.867370, -0.493632, 0.063222, 0.867370, -0.493631, 0.063221, -0.872299, -0.488658, 0.017543, -0.869857, -0.492628, 0.025813, -0.865839, -0.499258, 0.032623, -0.860584, -0.508017, 0.036246, -0.854874, -0.517629, 0.035373, -0.849728, -0.526383, 0.029720, -0.846044, -0.532729, 0.020245, -0.844290, -0.535816, 0.008755, -0.843355, -0.537194, 0.013184, -0.835061, -0.545932, 0.068053, -0.817630, -0.561747, 0.126182, -0.788640, -0.585737, 0.186974, -0.745175, -0.618614, 0.249059, -0.684268, -0.660121, 0.309867, -0.603900, -0.708357, 0.365425, -0.504497, -0.759456, 0.410741, 0.504498, -0.759456, 0.410741, 0.603901, -0.708356, 0.365425, 0.684268, -0.660121, 0.309867, 0.745174, -0.618615, 0.249060, 0.788639, -0.585738, 0.186975, 0.817629, -0.561747, 0.126183, 0.835061, -0.545932, 0.068054, 0.843355, -0.537194, 0.013183, 0.844290, -0.535816, 0.008754, 0.846044, -0.532729, 0.020245, 0.849728, -0.526383, 0.029721, 0.854874, -0.517629, 0.035373, 0.860584, -0.508017, 0.036247, 0.865839, -0.499258, 0.032624, 0.869857, -0.492628, 0.025813, 0.872299, -0.488659, 0.017543, -0.850584, -0.519300, -0.082668, -0.857153, -0.511324, -0.061946, -0.860020, -0.508641, -0.040630, -0.859364, -0.510903, -0.021738, -0.856200, -0.516587, -0.007776, -0.852071, -0.523426, 0.000154, -0.848488, -0.529209, 0.002675, -0.846415, -0.532522, 0.001683, -0.845130, -0.534363, 0.014573, -0.836620, -0.542569, 0.075401, -0.818534, -0.557016, 0.140486, -0.787876, -0.579018, 0.209734, -0.740719, -0.609720, 0.282093, -0.672677, -0.649329, 0.354792, -0.580310, -0.696084, 0.422739, -0.463503, -0.745584, 0.478822, 0.463503, -0.745584, 0.478821, 0.580310, -0.696084, 0.422739, 0.672677, -0.649329, 0.354792, 0.740719, -0.609720, 0.282094, 0.787876, -0.579019, 0.209735, 0.818534, -0.557016, 0.140487, 0.836620, -0.542569, 0.075402, 0.845130, -0.534363, 0.014574, 0.846414, -0.532522, 0.001683, 0.848488, -0.529209, 0.002675, 0.852071, -0.523426, 0.000154, 0.856199, -0.516587, -0.007776, 0.859364, -0.510903, -0.021738, 0.860020, -0.508641, -0.040629, 0.857153, -0.511324, -0.061946, 0.850585, -0.519300, -0.082668, -0.814352, -0.544312, -0.201382, -0.835643, -0.524831, -0.162031, -0.849171, -0.513987, -0.121348, -0.855394, -0.511149, -0.083834, -0.856052, -0.514164, -0.053008, -0.853624, -0.520001, -0.030415, -0.850500, -0.525751, -0.015362, -0.848294, -0.529496, -0.005565, -0.846728, -0.531786, 0.016006, -0.837951, -0.539403, 0.082962, -0.819066, -0.552325, 0.155137, -0.786506, -0.571992, 0.232882, -0.735347, -0.599830, 0.315387, -0.659865, -0.636351, 0.399544, -0.555417, -0.679814, 0.478921, -0.421847, -0.725320, 0.544018, 0.421847, -0.725320, 0.544018, 0.555416, -0.679814, 0.478921, 0.659865, -0.636351, 0.399544, 0.735347, -0.599830, 0.315387, 0.786506, -0.571992, 0.232882, 0.819066, -0.552326, 0.155138, 0.837951, -0.539403, 0.082962, 0.846728, -0.531786, 0.016007, 0.848294, -0.529496, -0.005565, 0.850500, -0.525751, -0.015362, 0.853624, -0.520001, -0.030415, 0.856052, -0.514165, -0.053008, 0.855394, -0.511149, -0.083833, 0.849171, -0.513987, -0.121348, 0.835643, -0.524831, -0.162030, 0.814353, -0.544312, -0.201382, -0.758687, -0.558132, -0.335980, -0.802766, -0.530158, -0.272945, -0.832109, -0.513794, -0.208830, -0.848213, -0.508021, -0.149830, -0.854309, -0.509985, -0.100352, -0.854398, -0.515898, -0.062081, -0.852131, -0.522226, -0.033944, -0.849981, -0.526653, -0.013022, -0.848196, -0.529395, 0.017488, -0.839110, -0.536336, 0.090765, -0.819301, -0.547522, 0.170191, -0.784621, -0.564428, 0.256498, -0.729169, -0.588650, 0.349004, -0.645992, -0.620881, 0.444073, -0.529572, -0.659362, 0.533663, -0.380346, -0.698896, 0.605707, 0.380345, -0.698897, 0.605707, 0.529571, -0.659362, 0.533663, 0.645992, -0.620881, 0.444073, 0.729169, -0.588650, 0.349005, 0.784621, -0.564428, 0.256498, 0.819301, -0.547522, 0.170191, 0.839110, -0.536337, 0.090765, 0.848196, -0.529394, 0.017489, 0.849981, -0.526653, -0.013021, 0.852131, -0.522226, -0.033944, 0.854398, -0.515898, -0.062080, 0.854309, -0.509985, -0.100352, 0.848213, -0.508021, -0.149829, 0.832109, -0.513794, -0.208829, 0.802767, -0.530158, -0.272944, 0.758688, -0.558132, -0.335979, -0.680732, -0.554629, -0.478530, -0.756624, -0.524171, -0.390852, -0.807808, -0.506513, -0.301481, -0.837375, -0.500745, -0.219219, -0.850834, -0.503645, -0.149744, -0.854388, -0.510895, -0.094909, -0.853417, -0.518514, -0.053134, -0.851513, -0.523925, -0.020715, -0.849570, -0.527133, 0.019024, -0.840142, -0.533285, 0.098837, -0.819302, -0.542457, 0.185699, -0.782301, -0.556094, 0.280650, -0.722285, -0.575869, 0.382988, -0.631223, -0.602594, 0.488302, -0.503142, -0.634562, 0.586668, -0.339768, -0.666637, 0.663440, 0.339768, -0.666637, 0.663440, 0.503142, -0.634562, 0.586668, 0.631222, -0.602594, 0.488302, 0.722284, -0.575869, 0.382988, 0.782301, -0.556094, 0.280650, 0.819302, -0.542457, 0.185700, 0.840142, -0.533285, 0.098837, 0.849570, -0.527132, 0.019025, 0.851512, -0.523925, -0.020714, 0.853416, -0.518514, -0.053133, 0.854388, -0.510895, -0.094908, 0.850834, -0.503645, -0.149743, 0.837375, -0.500745, -0.219217, 0.807809, -0.506512, -0.301479, 0.756625, -0.524171, -0.390851, 0.680733, -0.554628, -0.478529, -0.582726, -0.529752, -0.616274, -0.697043, -0.504491, -0.509529, -0.775710, -0.490802, -0.396720, -0.822519, -0.488568, -0.291142, -0.845487, -0.494719, -0.201008, -0.853577, -0.504760, -0.128930, -0.854380, -0.514497, -0.072989, -0.852920, -0.521253, -0.028670, -0.850882, -0.524953, 0.020619, -0.841088, -0.530168, 0.107205, -0.819124, -0.536980, 0.201712, -0.779620, -0.546741, 0.305396, -0.714791, -0.561149, 0.417355, -0.615730, -0.581141, 0.532121, -0.476511, -0.605255, 0.637655, -0.300809, -0.628899, 0.716938, 0.300809, -0.628899, 0.716938, 0.476510, -0.605255, 0.637655, 0.615729, -0.581141, 0.532121, 0.714791, -0.561149, 0.417356, 0.779620, -0.546741, 0.305396, 0.819124, -0.536980, 0.201713, 0.841088, -0.530168, 0.107205, 0.850882, -0.524953, 0.020619, 0.852920, -0.521253, -0.028670, 0.854380, -0.514497, -0.072988, 0.853578, -0.504760, -0.128929, 0.845488, -0.494719, -0.201007, 0.822520, -0.488568, -0.291140, 0.775711, -0.490802, -0.396719, 0.697044, -0.504491, -0.509528, 0.582728, -0.529752, -0.616272, -0.473135, -0.484256, -0.735962, -0.626403, -0.470522, -0.621472, -0.736038, -0.465856, -0.491148, -0.803457, -0.470833, -0.364381, -0.838151, -0.482768, -0.253846, -0.851944, -0.497241, -0.164141, -0.855040, -0.510052, -0.093556, -0.854230, -0.518584, -0.036916, -0.852157, -0.522812, 0.022277, -0.841985, -0.526906, 0.115897, -0.818821, -0.530931, 0.218278, -0.776648, -0.536097, 0.330785, -0.706786, -0.544112, 0.452101, -0.599696, -0.556139, 0.575390, -0.450063, -0.571279, 0.686355, -0.264064, -0.586027, 0.766056, 0.264064, -0.586027, 0.766056, 0.450062, -0.571279, 0.686356, 0.599696, -0.556139, 0.575391, 0.706786, -0.544112, 0.452102, 0.776647, -0.536097, 0.330786, 0.818821, -0.530931, 0.218278, 0.841985, -0.526906, 0.115897, 0.852157, -0.522812, 0.022278, 0.854230, -0.518584, -0.036915, 0.855040, -0.510052, -0.093556, 0.851944, -0.497242, -0.164141, 0.838152, -0.482768, -0.253845, 0.803457, -0.470833, -0.364380, 0.736039, -0.465856, -0.491146, 0.626405, -0.470522, -0.621470, 0.473137, -0.484256, -0.735960, -0.363724, -0.423765, -0.829535, -0.549502, -0.423940, -0.719946, -0.689997, -0.431672, -0.581002, -0.780258, -0.447076, -0.437402, -0.828748, -0.467357, -0.307821, -0.849466, -0.488065, -0.200499, -0.855412, -0.505049, -0.114877, -0.855462, -0.515865, -0.045476, -0.853419, -0.520672, 0.024005, -0.842869, -0.523414, 0.124941, -0.818448, -0.524128, 0.235443, -0.773457, -0.523848, 0.356858, -0.698369, -0.524332, 0.487193, -0.583315, -0.527167, 0.617931, -0.424183, -0.532455, 0.732503, -0.230032, -0.538307, 0.810747, 0.230032, -0.538307, 0.810747, 0.424182, -0.532455, 0.732503, 0.583315, -0.527167, 0.617931, 0.698369, -0.524332, 0.487193, 0.773456, -0.523849, 0.356859, 0.818448, -0.524128, 0.235443, 0.842869, -0.523414, 0.124942, 0.853419, -0.520672, 0.024006, 0.855462, -0.515865, -0.045476, 0.855412, -0.505049, -0.114876, 0.849466, -0.488066, -0.200498, 0.828749, -0.467357, -0.307820, 0.780259, -0.447076, -0.437400, 0.689999, -0.431672, -0.581000, 0.549504, -0.423940, -0.719945, 0.363727, -0.423765, -0.829534, -0.264645, -0.355842, -0.896292, -0.472274, -0.368202, -0.800865, -0.639723, -0.389138, -0.662816, -0.753324, -0.417103, -0.508456, -0.817267, -0.448075, -0.362358, -0.846129, -0.476931, -0.237914, -0.855508, -0.499341, -0.136983, -0.856638, -0.513045, -0.054377, -0.854694, -0.518491, 0.025809, -0.843778, -0.519599, 0.134368, -0.818065, -0.516363, 0.253255, -0.770124, -0.509631, 0.383646, -0.689646, -0.501313, 0.522565, -0.566789, -0.493751, 0.659514, -0.399246, -0.488576, 0.775820, -0.199118, -0.485942, 0.851007, 0.199117, -0.485942, 0.851007, 0.399246, -0.488576, 0.775820, 0.566789, -0.493751, 0.659515, 0.689645, -0.501313, 0.522566, 0.770124, -0.509631, 0.383647, 0.818065, -0.516363, 0.253256, 0.843778, -0.519599, 0.134368, 0.854694, -0.518491, 0.025810, 0.856638, -0.513045, -0.054376, 0.855508, -0.499341, -0.136983, 0.846129, -0.476931, -0.237913, 0.817268, -0.448075, -0.362356, 0.753325, -0.417104, -0.508454, 0.639725, -0.389138, -0.662814, 0.472277, -0.368202, -0.800863, 0.264648, -0.355842, -0.896291, -0.181608, -0.286819, -0.940613, -0.400134, -0.307354, -0.863381, -0.587947, -0.339866, -0.734036, -0.723410, -0.381040, -0.575748, -0.803790, -0.424555, -0.416742, -0.841933, -0.463508, -0.276242, -0.855347, -0.492762, -0.159899, -0.857777, -0.510067, -0.063645, -0.856003, -0.516228, 0.027694, -0.844757, -0.515353, 0.144209, -0.817741, -0.507388, 0.271765, -0.766735, -0.493009, 0.411169, -0.680724, -0.474477, 0.558110, -0.550329, -0.455359, 0.699847, -0.375616, -0.439399, 0.815991, -0.171651, -0.429040, 0.886826, 0.171651, -0.429040, 0.886826, 0.375616, -0.439399, 0.815991, 0.550329, -0.455359, 0.699848, 0.680724, -0.474476, 0.558111, 0.766734, -0.493009, 0.411170, 0.817741, -0.507388, 0.271766, 0.844757, -0.515353, 0.144210, 0.856003, -0.516228, 0.027695, 0.857776, -0.510068, -0.063644, 0.855347, -0.492763, -0.159898, 0.841933, -0.463508, -0.276241, 0.803791, -0.424556, -0.416741, 0.723411, -0.381041, -0.575746, 0.587949, -0.339867, -0.734034, 0.400136, -0.307354, -0.863380, 0.181612, -0.286819, -0.940613, -0.116174, -0.220526, -0.968438, -0.336873, -0.244914, -0.909139, -0.537509, -0.285834, -0.793337, -0.691592, -0.339327, -0.637618, -0.788514, -0.396499, -0.470142, -0.836902, -0.447430, -0.315279, -0.854949, -0.485118, -0.183634, -0.858899, -0.506871, -0.073305, -0.857376, -0.513836, 0.029668, -0.845857, -0.510545, 0.154500, -0.817557, -0.496898, 0.291022, -0.763380, -0.473448, 0.439428, -0.671715, -0.443138, 0.593657, -0.534147, -0.411388, 0.738544, -0.353643, -0.384644, 0.852635, -0.147904, -0.367618, 0.918140, 0.147904, -0.367618, 0.918140, 0.353642, -0.384644, 0.852635, 0.534146, -0.411388, 0.738544, 0.671715, -0.443137, 0.593657, 0.763380, -0.473448, 0.439429, 0.817557, -0.496897, 0.291023, 0.845857, -0.510545, 0.154501, 0.857375, -0.513836, 0.029669, 0.858899, -0.506871, -0.073304, 0.854949, -0.485119, -0.183633, 0.836902, -0.447430, -0.315278, 0.788515, -0.396499, -0.470141, 0.691594, -0.339328, -0.637616, 0.537511, -0.285835, -0.793335, 0.336876, -0.244915, -0.909138, 0.116178, -0.220526, -0.968437, -0.067419, -0.158620, -0.985035, -0.284474, -0.183328, -0.940992, -0.490913, -0.228992, -0.840576, -0.659175, -0.292661, -0.692704, -0.771769, -0.363690, -0.521634, -0.831094, -0.428295, -0.354749, -0.854350, -0.476177, -0.208188, -0.860030, -0.503383, -0.083386, -0.858840, -0.511259, 0.031739, -0.847139, -0.505013, 0.165279, -0.817609, -0.484507, 0.311078, -0.760161, -0.450290, 0.468396, -0.662724, -0.406479, 0.628945, -0.518454, -0.361169, 0.775089, -0.333658, -0.324004, 0.885265, -0.128108, -0.301623, 0.944781, 0.128108, -0.301623, 0.944781, 0.333657, -0.324004, 0.885265, 0.518453, -0.361169, 0.775089, 0.662724, -0.406479, 0.628945, 0.760160, -0.450289, 0.468397, 0.817608, -0.484506, 0.311079, 0.847139, -0.505013, 0.165280, 0.858840, -0.511259, 0.031740, 0.860030, -0.503383, -0.083385, 0.854350, -0.476177, -0.208187, 0.831094, -0.428295, -0.354747, 0.771770, -0.363691, -0.521632, 0.659176, -0.292661, -0.692702, 0.490915, -0.228993, -0.840574, 0.284477, -0.183328, -0.940991, 0.067423, -0.158620, -0.985035, -0.033419, -0.101404, -0.994284, -0.243493, -0.123968, -0.961948, -0.450061, -0.170975, -0.876477, -0.627564, -0.241889, -0.740036, -0.754023, -0.326010, -0.570234, -0.824609, -0.405653, -0.394291, -0.853596, -0.465654, -0.233537, -0.861200, -0.499515, -0.093916, -0.860435, -0.508431, 0.033914, -0.848683, -0.498551, 0.176591, -0.818015, -0.469721, 0.331984, -0.757178, -0.422699, 0.498002, -0.653841, -0.363527, 0.663581, -0.503449, -0.303970, 0.808790, -0.315974, -0.257167, 0.913250, -0.112470, -0.230967, 0.966439, 0.112470, -0.230967, 0.966439, 0.315974, -0.257167, 0.913250, 0.503449, -0.303970, 0.808790, 0.653840, -0.363527, 0.663582, 0.757178, -0.422699, 0.498003, 0.818015, -0.469721, 0.331985, 0.848683, -0.498551, 0.176592, 0.860435, -0.508431, 0.033915, 0.861200, -0.499515, -0.093915, 0.853597, -0.465654, -0.233536, 0.824610, -0.405654, -0.394289, 0.754024, -0.326011, -0.570232, 0.627566, -0.241890, -0.740034, 0.450063, -0.170976, -0.876476, 0.243496, -0.123968, -0.961947, 0.033422, -0.101405, -0.994284, -0.012109, -0.048522, -0.998749, -0.213614, -0.067401, -0.974590, -0.416198, -0.112977, -0.902228, -0.598136, -0.187901, -0.779055, -0.735876, -0.283429, -0.614943, -0.817606, -0.379004, -0.433448, -0.852762, -0.453198, -0.259633, -0.862445, -0.495156, -0.104922, -0.862205, -0.505265, 0.036203, -0.850591, -0.490887, 0.188484, -0.818920, -0.451893, 0.353784, -0.754529, -0.389615, 0.528097, -0.645118, -0.313130, 0.696974, -0.489307, -0.239033, 0.838714, -0.300882, -0.183870, 0.935768, -0.101178, -0.155581, 0.982628, 0.101178, -0.155581, 0.982628, 0.300881, -0.183870, 0.935768, 0.489307, -0.239032, 0.838715, 0.645117, -0.313130, 0.696974, 0.754528, -0.389614, 0.528098, 0.818920, -0.451892, 0.353785, 0.850590, -0.490887, 0.188484, 0.862205, -0.505265, 0.036204, 0.862445, -0.495156, -0.104921, 0.852762, -0.453198, -0.259631, 0.817606, -0.379005, -0.433446, 0.735877, -0.283431, -0.614941, 0.598138, -0.187902, -0.779053, 0.416200, -0.112978, -0.902227, 0.213617, -0.067401, -0.974590, 0.012112, -0.048522, -0.998749, -0.001648, 0.000625, -0.999998, -0.194094, -0.013696, -0.980887, -0.389992, -0.055762, -0.919128, -0.572127, -0.131529, -0.809550, -0.718040, -0.236005, -0.654768, -0.810308, -0.347781, -0.471645, -0.851951, -0.438359, -0.286391, -0.863819, -0.490163, -0.116432, -0.864210, -0.501647, 0.038616, -0.852997, -0.481654, 0.201012, -0.820496, -0.430146, 0.376511, -0.752276, -0.349667, 0.558403, -0.636539, -0.253951, 0.728235, -0.476161, -0.165641, 0.863617, -0.288636, -0.103978, 0.951776, -0.094398, -0.075494, 0.992668, 0.094398, -0.075494, 0.992668, 0.288635, -0.103978, 0.951776, 0.476161, -0.165640, 0.863617, 0.636539, -0.253951, 0.728236, 0.752275, -0.349667, 0.558404, 0.820496, -0.430146, 0.376512, 0.852997, -0.481654, 0.201013, 0.864210, -0.501647, 0.038617, 0.863820, -0.490163, -0.116430, 0.851952, -0.438360, -0.286389, 0.810309, -0.347782, -0.471643, 0.718041, -0.236006, -0.654766, 0.572129, -0.131530, -0.809548, 0.389995, -0.055763, -0.919127, 0.194097, -0.013696, -0.980887, 0.001651, 0.000625, -0.999998, 0.002687, 0.046030, -0.998936, -0.175847, -0.003855, -0.984410, -0.361069, -0.110009, -0.926028, -0.531218, -0.238200, -0.813061, -0.665502, -0.356953, -0.655509, -0.756896, -0.447450, -0.476337, -0.810823, -0.505382, -0.295222, -0.836399, -0.534310, -0.122263, -0.840973, -0.539596, 0.040011, -0.826626, -0.523134, 0.207413, -0.787968, -0.480359, 0.385177, -0.716410, -0.406281, 0.567179, -0.603663, -0.300314, 0.738514, -0.449553, -0.173503, 0.876241, -0.268805, -0.052005, 0.961790, -0.084768, 0.030223, 0.995942, 0.084768, 0.030224, 0.995942, 0.268804, -0.052005, 0.961790, 0.449553, -0.173503, 0.876241, 0.603662, -0.300314, 0.738514, 0.716410, -0.406281, 0.567180, 0.787968, -0.480359, 0.385178, 0.826626, -0.523133, 0.207414, 0.840973, -0.539596, 0.040012, 0.836400, -0.534311, -0.122262, 0.810823, -0.505382, -0.295220, 0.756897, -0.447450, -0.476335, 0.665503, -0.356954, -0.655507, 0.531220, -0.238201, -0.813060, 0.361071, -0.110011, -0.926027, 0.175849, -0.003857, -0.984410, -0.002684, 0.046030, -0.998936, 0.021152, 0.140125, -0.989908, -0.142866, 0.084687, -0.986112, -0.323561, -0.020019, -0.945996, -0.502128, -0.150980, -0.851512, -0.653903, -0.279643, -0.703001, -0.763562, -0.382907, -0.519957, -0.830795, -0.451322, -0.325712, -0.863318, -0.486110, -0.135569, -0.869175, -0.492508, 0.044405, -0.850844, -0.472623, 0.229547, -0.802074, -0.421559, 0.423042, -0.714320, -0.335370, 0.614226, -0.582691, -0.217324, 0.783097, -0.414694, -0.083968, 0.906079, -0.232012, 0.037248, 0.972000, -0.058116, 0.119716, 0.991106, 0.058116, 0.119716, 0.991106, 0.232011, 0.037248, 0.972000, 0.414694, -0.083967, 0.906079, 0.582691, -0.217324, 0.783098, 0.714320, -0.335370, 0.614227, 0.802074, -0.421559, 0.423043, 0.850844, -0.472623, 0.229548, 0.869175, -0.492508, 0.044406, 0.863318, -0.486110, -0.135568, 0.830795, -0.451322, -0.325710, 0.763563, -0.382908, -0.519956, 0.653905, -0.279644, -0.702999, 0.502129, -0.150982, -0.851511, 0.323564, -0.020020, -0.945995, 0.142868, 0.084686, -0.986112, -0.021150, 0.140125, -0.989908, 0.052110, 0.235706, -0.970426, -0.099527, 0.179610, -0.978690, -0.274766, 0.080721, -0.958117, -0.460345, -0.047860, -0.886449, -0.631421, -0.182975, -0.753543, -0.764623, -0.298876, -0.570985, -0.850826, -0.379533, -0.363386, -0.893821, -0.421717, -0.152439, -0.901653, -0.429559, 0.050001, -0.877231, -0.405271, 0.257334, -0.813563, -0.344065, 0.468757, -0.703718, -0.244657, 0.667027, -0.549396, -0.116313, 0.827427, -0.367646, 0.018905, 0.929774, -0.184684, 0.134929, 0.973492, -0.020475, 0.213491, 0.976730, 0.020475, 0.213491, 0.976730, 0.184684, 0.134930, 0.973492, 0.367646, 0.018905, 0.929774, 0.549396, -0.116312, 0.827427, 0.703717, -0.244656, 0.667028, 0.813563, -0.344065, 0.468758, 0.877231, -0.405271, 0.257335, 0.901653, -0.429559, 0.050002, 0.893822, -0.421718, -0.152437, 0.850827, -0.379534, -0.363384, 0.764624, -0.298877, -0.570983, 0.631423, -0.182977, -0.753541, 0.460347, -0.047862, -0.886448, 0.274768, 0.080720, -0.958116, 0.099529, 0.179609, -0.978690, -0.052108, 0.235705, -0.970427, 0.091329, 0.330853, -0.939252, -0.047888, 0.278478, -0.959248, -0.214907, 0.190336, -0.957908, -0.403406, 0.071456, -0.912227, -0.592914, -0.062756, -0.802816, -0.754792, -0.187717, -0.628532, -0.867916, -0.280915, -0.409646, -0.927141, -0.331851, -0.174025, -0.938143, -0.341489, 0.057215, -0.904056, -0.311809, 0.292332, -0.818130, -0.239266, 0.522892, -0.678982, -0.128012, 0.722909, -0.499803, 0.004848, 0.866126, -0.307417, 0.134061, 0.942084, -0.128011, 0.238750, 0.962607, 0.025135, 0.309196, 0.950666, -0.025135, 0.309196, 0.950666, 0.128011, 0.238750, 0.962607, 0.307416, 0.134061, 0.942084, 0.499802, 0.004848, 0.866126, 0.678981, -0.128011, 0.722910, 0.818129, -0.239266, 0.522893, 0.904055, -0.311809, 0.292334, 0.938143, -0.341489, 0.057217, 0.927141, -0.331851, -0.174023, 0.867916, -0.280915, -0.409644, 0.754793, -0.187718, -0.628530, 0.592916, -0.062758, -0.802815, 0.403408, 0.071455, -0.912226, 0.214909, 0.190334, -0.957908, 0.047890, 0.278477, -0.959248, -0.091327, 0.330853, -0.939253, 0.135568, 0.423284, -0.895797, 0.009816, 0.378165, -0.925686, -0.145124, 0.305330, -0.941123, -0.329664, 0.204656, -0.921649, -0.531873, 0.083322, -0.842715, -0.724449, -0.040400, -0.688143, -0.874111, -0.141522, -0.464653, -0.958720, -0.200614, -0.201521, -0.974975, -0.212130, 0.066522, -0.925173, -0.177015, 0.335739, -0.806460, -0.095280, 0.583562, -0.631511, 0.020227, 0.775103, -0.429943, 0.145693, 0.891023, -0.234072, 0.258262, 0.937289, -0.063773, 0.345324, 0.936314, 0.076028, 0.404046, 0.911574, -0.076028, 0.404046, 0.911573, 0.063773, 0.345324, 0.936314, 0.234071, 0.258262, 0.937289, 0.429942, 0.145693, 0.891024, 0.631510, 0.020228, 0.775104, 0.806459, -0.095279, 0.583563, 0.925173, -0.177015, 0.335740, 0.974975, -0.212130, 0.066524, 0.958720, -0.200614, -0.201519, 0.874112, -0.141523, -0.464650, 0.724451, -0.040401, -0.688141, 0.531875, 0.083320, -0.842714, 0.329666, 0.204654, -0.921649, 0.145126, 0.305329, -0.941123, -0.009815, 0.378164, -0.925687, -0.135566, 0.423284, -0.895797, 0.182110, 0.510620, -0.840300, 0.071064, 0.475080, -0.877068, -0.067808, 0.420633, -0.904693, -0.239652, 0.345597, -0.907265, -0.442359, 0.251863, -0.860746, -0.658442, 0.148932, -0.737749, -0.850395, 0.056157, -0.523140, -0.972106, -0.003048, -0.234522, -0.996843, -0.015107, 0.077950, -0.922498, 0.021110, 0.385424, -0.760404, 0.099763, 0.641743, -0.550628, 0.200554, 0.810300, -0.337781, 0.300700, 0.891899, -0.149483, 0.385698, 0.910435, 0.005518, 0.450368, 0.892826, 0.129630, 0.495055, 0.859137, -0.129630, 0.495055, 0.859137, -0.005518, 0.450369, 0.892826, 0.149482, 0.385698, 0.910435, 0.337781, 0.300701, 0.891899, 0.550627, 0.200555, 0.810301, 0.760402, 0.099763, 0.641744, 0.922497, 0.021110, 0.385425, 0.996843, -0.015107, 0.077952, 0.972107, -0.003049, -0.234520, 0.850396, 0.056156, -0.523138, 0.658444, 0.148931, -0.737747, 0.442362, 0.251861, -0.860745, 0.239654, 0.345596, -0.907265, 0.067809, 0.420632, -0.904694, -0.071062, 0.475080, -0.877069, -0.182108, 0.510620, -0.840300, 0.228640, 0.590688, -0.773829, 0.133158, 0.565622, -0.813843, 0.013448, 0.530275, -0.847719, -0.137292, 0.484382, -0.864017, -0.323543, 0.429624, -0.843056, -0.540665, 0.371071, -0.754975, -0.760919, 0.318254, -0.565435, -0.921523, 0.283784, -0.265070, -0.956845, 0.276631, 0.089010, -0.853602, 0.297964, 0.427295, -0.653525, 0.343181, 0.674635, -0.429224, 0.400335, 0.809629, -0.225930, 0.457891, 0.859820, -0.057658, 0.508603, 0.859068, 0.076767, 0.549281, 0.832104, 0.183499, 0.579380, 0.794133, -0.183499, 0.579380, 0.794133, -0.076768, 0.549281, 0.832104, 0.057658, 0.508603, 0.859068, 0.225930, 0.457891, 0.859820, 0.429223, 0.400335, 0.809629, 0.653523, 0.343181, 0.674636, 0.853601, 0.297964, 0.427297, 0.956845, 0.276631, 0.089013, 0.921524, 0.283783, -0.265067, 0.760921, 0.318254, -0.565432, 0.540667, 0.371070, -0.754974, 0.323545, 0.429624, -0.843055, 0.137294, 0.484381, -0.864017, -0.013446, 0.530275, -0.847719, -0.133156, 0.565621, -0.813844, -0.228638, 0.590688, -0.773830, 0.273254, 0.661778, -0.698127, 0.193496, 0.646696, -0.737796, 0.094395, 0.628605, -0.771975, -0.029754, 0.609740, -0.792043, -0.184380, 0.594673, -0.782539, -0.370823, 0.590214, -0.717034, -0.573676, 0.601466, -0.555998, -0.736028, 0.620890, -0.269738, -0.773979, 0.626584, 0.091372, -0.665489, 0.611426, 0.428117, -0.472490, 0.593890, 0.651190, -0.273943, 0.590664, 0.758993, -0.102995, 0.601343, 0.792325, 0.035820, 0.619046, 0.784538, 0.146708, 0.637933, 0.755988, 0.235460, 0.654683, 0.718295, -0.235460, 0.654683, 0.718295, -0.146709, 0.637933, 0.755988, -0.035820, 0.619046, 0.784538, 0.102995, 0.601342, 0.792325, 0.273943, 0.590664, 0.758994, 0.472489, 0.593890, 0.651190, 0.665487, 0.611425, 0.428119, 0.773979, 0.626584, 0.091375, 0.736029, 0.620890, -0.269735, 0.573678, 0.601467, -0.555996, 0.370825, 0.590214, -0.717033, 0.184382, 0.594673, -0.782539, 0.029755, 0.609740, -0.792043, -0.094394, 0.628605, -0.771975, -0.193494, 0.646696, -0.737797, -0.273253, 0.661778, -0.698128, 0.314502, 0.722798, -0.615347, 0.249869, 0.716140, -0.651697, 0.171000, 0.711523, -0.681538, 0.074602, 0.712877, -0.697310, -0.041963, 0.726600, -0.685778, -0.177988, 0.760369, -0.624627, -0.321120, 0.815747, -0.481082, -0.432408, 0.871304, -0.232061, -0.458026, 0.885466, 0.078500, -0.384396, 0.846105, 0.369250, -0.250316, 0.785936, 0.565373, -0.107881, 0.740578, 0.663254, 0.018931, 0.717703, 0.696093, 0.125189, 0.711113, 0.691843, 0.212421, 0.713385, 0.667802, 0.283762, 0.719376, 0.634017, -0.283762, 0.719375, 0.634017, -0.212421, 0.713385, 0.667802, -0.125189, 0.711113, 0.691843, -0.018931, 0.717702, 0.696093, 0.107881, 0.740578, 0.663255, 0.250315, 0.785936, 0.565373, 0.384395, 0.846105, 0.369252, 0.458025, 0.885466, 0.078502, 0.432408, 0.871305, -0.232058, 0.321121, 0.815747, -0.481080, 0.177989, 0.760370, -0.624626, 0.041965, 0.726600, -0.685778, -0.074601, 0.712877, -0.697310, -0.170999, 0.711523, -0.681538, -0.249868, 0.716140, -0.651697, -0.314501, 0.722798, -0.615347, 0.351395, 0.773295, -0.527766, 0.300674, 0.772893, -0.558776, 0.240208, 0.777146, -0.581673, 0.168995, 0.790128, -0.589185, 0.087425, 0.817299, -0.569544, -0.000747, 0.863017, -0.505174, -0.084587, 0.922909, -0.375611, -0.143090, 0.974039, -0.175421, -0.155717, 0.986046, 0.058866, -0.118578, 0.951705, 0.283189, -0.044301, 0.892132, 0.449598, 0.043706, 0.837774, 0.544265, 0.129383, 0.801584, 0.583715, 0.205969, 0.782225, 0.587963, 0.271740, 0.774224, 0.571607, 0.327165, 0.772702, 0.543963, -0.327165, 0.772702, 0.543963, -0.271740, 0.774224, 0.571607, -0.205969, 0.782225, 0.587963, -0.129383, 0.801584, 0.583715, -0.043707, 0.837774, 0.544265, 0.044301, 0.892132, 0.449599, 0.118578, 0.951705, 0.283190, 0.155716, 0.986046, 0.058868, 0.143090, 0.974040, -0.175419, 0.084588, 0.922910, -0.375610, 0.000747, 0.863017, -0.505174, -0.087424, 0.817299, -0.569543, -0.168994, 0.790128, -0.589185, -0.240207, 0.777146, -0.581674, -0.300673, 0.772894, -0.558777, -0.351394, 0.773295, -0.527767, 0.383372, 0.813378, -0.437542, 0.344973, 0.816919, -0.462208, 0.300300, 0.825682, -0.477567, 0.249790, 0.842745, -0.476850, 0.195380, 0.871183, -0.450408, 0.141425, 0.911373, -0.386520, 0.095378, 0.956316, -0.276337, 0.066481, 0.989924, -0.125026, 0.060600, 0.997293, 0.041650, 0.078259, 0.975708, 0.204622, 0.116835, 0.934091, 0.337378, 0.167954, 0.890015, 0.423868, 0.222869, 0.855406, 0.467557, 0.275698, 0.832964, 0.479752, 0.323419, 0.820471, 0.471410, 0.364947, 0.814658, 0.450717, -0.364947, 0.814658, 0.450717, -0.323419, 0.820471, 0.471410, -0.275698, 0.832964, 0.479752, -0.222869, 0.855406, 0.467557, -0.167954, 0.890015, 0.423868, -0.116835, 0.934090, 0.337379, -0.078259, 0.975707, 0.204623, -0.060600, 0.997293, 0.041651, -0.066481, 0.989924, -0.125025, -0.095377, 0.956317, -0.276336, -0.141424, 0.911374, -0.386519, -0.195380, 0.871183, -0.450407, -0.249789, 0.842745, -0.476850, -0.300299, 0.825682, -0.477567, -0.344973, 0.816920, -0.462208, -0.383371, 0.813378, -0.437542, 0.410223, 0.843576, -0.346548, 0.382430, 0.848949, -0.364738, 0.350780, 0.858772, -0.373450, 0.316292, 0.874797, -0.367000, 0.281114, 0.897987, -0.338519, 0.248660, 0.926705, -0.281754, 0.223159, 0.955059, -0.195097, 0.208281, 0.974257, -0.086268, 0.205364, 0.978268, 0.028596, 0.214237, 0.966323, 0.142554, 0.234776, 0.941460, 0.241936, 0.264290, 0.911916, 0.313943, 0.298604, 0.885512, 0.355954, 0.333786, 0.865913, 0.372533, 0.367046, 0.853191, 0.370597, 0.396837, 0.845815, 0.356534, -0.396837, 0.845815, 0.356534, -0.367046, 0.853191, 0.370597, -0.333786, 0.865913, 0.372533, -0.298604, 0.885512, 0.355954, -0.264290, 0.911916, 0.313943, -0.234776, 0.941460, 0.241937, -0.214237, 0.966323, 0.142555, -0.205364, 0.978268, 0.028597, -0.208281, 0.974257, -0.086267, -0.223158, 0.955059, -0.195096, -0.248660, 0.926706, -0.281754, -0.281113, 0.897987, -0.338518, -0.316291, 0.874798, -0.367000, -0.350780, 0.858772, -0.373450, -0.382429, 0.848949, -0.364738, -0.410223, 0.843576, -0.346549, 0.432005, 0.864686, -0.256300, 0.413157, 0.870175, -0.268510, 0.392028, 0.878738, -0.272277, 0.369635, 0.891052, -0.263432, 0.347692, 0.906941, -0.237843, 0.328427, 0.924585, -0.193075, 0.314051, 0.940382, -0.130591, 0.306004, 0.950331, -0.056863, 0.304457, 0.952341, 0.018789, 0.309194, 0.946286, 0.094559, 0.320512, 0.932983, 0.163756, 0.337578, 0.915734, 0.217880, 0.358475, 0.898617, 0.252948, 0.380898, 0.884407, 0.269705, 0.402830, 0.874019, 0.271697, 0.422904, 0.867101, 0.263225, -0.422904, 0.867101, 0.263225, -0.402830, 0.874019, 0.271697, -0.380898, 0.884407, 0.269705, -0.358475, 0.898617, 0.252948, -0.337578, 0.915734, 0.217880, -0.320512, 0.932982, 0.163756, -0.309194, 0.946286, 0.094560, -0.304457, 0.952341, 0.018790, -0.306004, 0.950331, -0.056863, -0.314051, 0.940382, -0.130590, -0.328427, 0.924585, -0.193075, -0.347691, 0.906941, -0.237842, -0.369635, 0.891052, -0.263432, -0.392027, 0.878738, -0.272277, -0.413157, 0.870175, -0.268510, -0.432005, 0.864686, -0.256301, 0.448948, 0.877632, -0.167951, 0.437562, 0.881984, -0.175051, 0.424902, 0.888000, -0.175825, 0.411706, 0.895751, -0.167716, 0.399082, 0.904773, -0.148724, 0.388307, 0.913889, -0.118425, 0.380481, 0.921427, -0.078776, 0.376189, 0.925921, -0.033951, 0.375371, 0.926807, 0.011195, 0.377882, 0.924116, 0.056693, 0.383974, 0.917962, 0.099549, 0.393386, 0.909419, 0.134926, 0.405243, 0.900160, 0.159656, 0.418309, 0.891671, 0.173031, 0.431355, 0.884771, 0.176391, 0.443445, 0.879618, 0.172133, -0.443445, 0.879618, 0.172133, -0.431355, 0.884771, 0.176391, -0.418309, 0.891671, 0.173031, -0.405243, 0.900160, 0.159656, -0.393386, 0.909419, 0.134926, -0.383974, 0.917962, 0.099549, -0.377882, 0.924116, 0.056694, -0.375371, 0.926807, 0.011196, -0.376189, 0.925921, -0.033951, -0.380481, 0.921427, -0.078775, -0.388307, 0.913889, -0.118425, -0.399082, 0.904774, -0.148724, -0.411706, 0.895751, -0.167716, -0.424902, 0.888000, -0.175825, -0.437562, 0.881984, -0.175051, -0.448947, 0.877632, -0.167951, 0.461385, 0.883372, -0.082330, 0.456205, 0.885772, -0.085355, 0.450446, 0.888751, -0.084973, 0.444477, 0.892205, -0.080064, 0.438826, 0.895844, -0.069975, 0.434061, 0.899208, -0.054919, 0.430640, 0.901801, -0.036106, 0.428779, 0.903277, -0.015454, 0.428426, 0.903562, 0.005089, 0.429512, 0.902690, 0.025877, 0.432162, 0.900628, 0.045873, 0.436299, 0.897592, 0.063015, 0.441575, 0.894027, 0.075677, 0.447458, 0.890432, 0.083142, 0.453379, 0.887192, 0.085666, 0.458883, 0.884499, 0.084191, -0.458883, 0.884499, 0.084191, -0.453379, 0.887191, 0.085666, -0.447458, 0.890432, 0.083142, -0.441575, 0.894027, 0.075678, -0.436299, 0.897592, 0.063015, -0.432162, 0.900628, 0.045872, -0.429512, 0.902690, 0.025877, -0.428426, 0.903562, 0.005089, -0.428779, 0.903277, -0.015455, -0.430640, 0.901801, -0.036106, -0.434061, 0.899208, -0.054919, -0.438825, 0.895844, -0.069975, -0.444477, 0.892205, -0.080064, -0.450446, 0.888751, -0.084974, -0.456205, 0.885772, -0.085355, -0.461385, 0.883372, -0.082330, 0.461354, 0.886259, -0.041211, 0.458922, 0.887586, -0.039756, 0.456534, 0.888954, -0.036588, 0.454350, 0.890259, -0.031695, 0.452527, 0.891392, -0.025305, 0.451177, 0.892256, -0.017857, 0.450347, 0.892799, -0.009904, 0.450015, 0.893019, -0.001961, 0.450122, 0.892948, 0.005897, 0.450698, 0.892568, 0.013912, 0.451788, 0.891862, 0.021676, 0.453385, 0.890854, 0.028662, 0.455405, 0.889622, 0.034346, 0.457714, 0.888270, 0.038393, 0.460144, 0.886912, 0.040689, 0, 0.997056, -0.076670, -0.460142, 0.886912, 0.040689, -0.457714, 0.888270, 0.038393, -0.455407, 0.889621, 0.034349, -0.453384, 0.890855, 0.028658, -0.451789, 0.891861, 0.021681, -0.450697, 0.892569, 0.013906, -0.450122, 0.892948, 0.005908, -0.450015, 0.893019, -0.001975, -0.450346, 0.892799, -0.009892, -0.451177, 0.892256, -0.017858, -0.452527, 0.891391, -0.025306, -0.454349, 0.890260, -0.031693, -0.456534, 0.888953, -0.036588, -0.458923, 0.887586, -0.039756, -0.461354, 0.886259, -0.041211, -0.461354, 0.886259, -0.041211, -0.863559, -0.503611, -0.025346, -0.863979, -0.503407, -0.011044, -0.861947, -0.506996, 0.001626, -0.858049, -0.513460, 0.010530, -0.853374, -0.521101, 0.014370, -0.849154, -0.527981, 0.013200, -0.846335, -0.532585, 0.008340, -0.844810, -0.534982, 0.009549, -0.840412, -0.540253, 0.042822, -0.827425, -0.552126, 0.102588, -0.803777, -0.571311, 0.165970, -0.766413, -0.598906, 0.232211, -0.711777, -0.635399, 0.299402, -0.636616, -0.679890, 0.363965, -0.539541, -0.729382, 0.420592, 0, -0.860871, 0.508823, 0.539541, -0.729382, 0.420592, 0.636616, -0.679890, 0.363965, 0.711777, -0.635399, 0.299402, 0.766413, -0.598906, 0.232211, 0.803777, -0.571311, 0.165970, 0.827425, -0.552126, 0.102589, 0.840412, -0.540253, 0.042822, 0.844810, -0.534982, 0.009549, 0.846335, -0.532585, 0.008340, 0.849154, -0.527981, 0.013200, 0.853374, -0.521101, 0.014370, 0.858049, -0.513460, 0.010530, 0.861947, -0.506996, 0.001627, 0.863979, -0.503407, -0.011044, 0.863559, -0.503610, -0.025346, -0.840972, -0.525905, -0.127240, -0.851533, -0.515323, -0.096606, -0.856637, -0.511558, -0.066938, -0.857126, -0.513424, -0.041607, -0.854677, -0.518660, -0.022766, -0.851252, -0.524647, -0.010738, -0.848449, -0.529260, -0.004142, -0.846678, -0.532064, 0.006675, -0.842056, -0.537316, 0.047261, -0.828601, -0.548198, 0.113573, -0.803724, -0.565600, 0.184727, -0.763584, -0.590892, 0.260356, -0.703431, -0.624944, 0.338570, -0.618642, -0.667092, 0.415055, -0.506972, -0.714098, 0.482746, 0, -0.821009, 0.570915, 0.506971, -0.714098, 0.482746, 0.618641, -0.667092, 0.415055, 0.703431, -0.624944, 0.338570, 0.763584, -0.590892, 0.260356, 0.803724, -0.565600, 0.184728, 0.828601, -0.548198, 0.113574, 0.842055, -0.537316, 0.047261, 0.846678, -0.532064, 0.006675, 0.848449, -0.529260, -0.004142, 0.851252, -0.524647, -0.010738, 0.854677, -0.518660, -0.022766, 0.857126, -0.513425, -0.041607, 0.856637, -0.511558, -0.066938, 0.851534, -0.515323, -0.096606, 0.840973, -0.525904, -0.127239, -0.805045, -0.540825, -0.243745, -0.831385, -0.521611, -0.191626, -0.847139, -0.512292, -0.141113, -0.854023, -0.511147, -0.096816, -0.854874, -0.515180, -0.061484, -0.852791, -0.521047, -0.035456, -0.850277, -0.526062, -0.016974, -0.848377, -0.529380, 0.003727, -0.843533, -0.534570, 0.051838, -0.829524, -0.544334, 0.124864, -0.803240, -0.559671, 0.203897, -0.760064, -0.582108, 0.288881, -0.694101, -0.612759, 0.377823, -0.599532, -0.651079, 0.465464, -0.473674, -0.693598, 0.542729, -0, -0.778102, 0.628138, 0.473673, -0.693598, 0.542729, 0.599532, -0.651080, 0.465464, 0.694101, -0.612759, 0.377823, 0.760064, -0.582108, 0.288881, 0.803240, -0.559671, 0.203897, 0.829524, -0.544334, 0.124864, 0.843533, -0.534570, 0.051839, 0.848377, -0.529380, 0.003728, 0.850277, -0.526062, -0.016974, 0.852791, -0.521047, -0.035455, 0.854874, -0.515180, -0.061484, 0.854023, -0.511148, -0.096816, 0.847139, -0.512292, -0.141113, 0.831386, -0.521611, -0.191625, 0.805045, -0.540824, -0.243744, -0.752659, -0.543909, -0.371034, -0.801879, -0.519990, -0.294280, -0.832694, -0.508072, -0.220188, -0.848466, -0.506066, -0.154929, -0.853911, -0.510362, -0.101822, -0.853799, -0.517013, -0.061032, -0.851863, -0.522893, -0.030207, -0.849951, -0.526861, 0.000694, -0.844891, -0.531938, 0.056571, -0.830253, -0.540414, 0.136502, -0.802405, -0.553331, 0.223544, -0.755948, -0.572285, 0.317854, -0.683916, -0.598529, 0.417159, -0.579538, -0.631591, 0.515003, -0.440210, -0.667904, 0.600100, -0, -0.732485, 0.680783, 0.440210, -0.667904, 0.600100, 0.579538, -0.631591, 0.515004, 0.683916, -0.598529, 0.417159, 0.755948, -0.572285, 0.317855, 0.802404, -0.553331, 0.223545, 0.830253, -0.540414, 0.136503, 0.844891, -0.531938, 0.056571, 0.849951, -0.526861, 0.000694, 0.851863, -0.522893, -0.030207, 0.853799, -0.517014, -0.061032, 0.853911, -0.510362, -0.101822, 0.848466, -0.506066, -0.154928, 0.832694, -0.508072, -0.220187, 0.801879, -0.519989, -0.294279, 0.752660, -0.543909, -0.371033, -0.682952, -0.531115, -0.501491, -0.762051, -0.508332, -0.401095, -0.812708, -0.497793, -0.302831, -0.840195, -0.497595, -0.215571, -0.851722, -0.503889, -0.143757, -0.854289, -0.512376, -0.087526, -0.853244, -0.519661, -0.043887, -0.851438, -0.524449, -0.002436, -0.846171, -0.529354, 0.061475, -0.830842, -0.536322, 0.148529, -0.801286, -0.546386, 0.243729, -0.751324, -0.561139, 0.347325, -0.673006, -0.581917, 0.456548, -0.558922, -0.608360, 0.563475, -0.407128, -0.637079, 0.654505, -0, -0.684343, 0.729160, 0.407128, -0.637079, 0.654505, 0.558922, -0.608360, 0.563476, 0.673006, -0.581917, 0.456548, 0.751324, -0.561139, 0.347325, 0.801286, -0.546386, 0.243729, 0.830842, -0.536321, 0.148530, 0.846171, -0.529354, 0.061476, 0.851438, -0.524450, -0.002436, 0.853244, -0.519661, -0.043886, 0.854289, -0.512376, -0.087526, 0.851722, -0.503889, -0.143757, 0.840195, -0.497595, -0.215570, 0.812709, -0.497793, -0.302830, 0.762052, -0.508331, -0.401094, 0.682953, -0.531115, -0.501490, -0.598887, -0.500650, -0.625047, -0.712245, -0.485266, -0.507172, -0.786927, -0.480539, -0.387076, -0.829011, -0.485162, -0.278133, -0.848240, -0.495427, -0.187191, -0.854270, -0.506955, -0.114976, -0.854449, -0.516282, -0.058054, -0.852867, -0.522097, -0.005675, -0.847406, -0.526756, 0.066568, -0.831339, -0.531940, 0.160983, -0.799949, -0.538627, 0.264504, -0.746276, -0.548358, 0.377327, -0.661504, -0.562552, 0.495931, -0.537957, -0.581107, 0.610669, -0.374944, -0.601204, 0.705670, -0, -0.633727, 0.773556, 0.374944, -0.601204, 0.705670, 0.537956, -0.581107, 0.610670, 0.661504, -0.562551, 0.495932, 0.746276, -0.548358, 0.377327, 0.799949, -0.538627, 0.264505, 0.831339, -0.531940, 0.160983, 0.847406, -0.526756, 0.066569, 0.852867, -0.522097, -0.005674, 0.854449, -0.516282, -0.058053, 0.854270, -0.506955, -0.114975, 0.848240, -0.495427, -0.187190, 0.829011, -0.485162, -0.278132, 0.786928, -0.480539, -0.387074, 0.712247, -0.485266, -0.507170, 0.598889, -0.500649, -0.625045, -0.507164, -0.454178, -0.732466, -0.654452, -0.450729, -0.607072, -0.755608, -0.455771, -0.470457, -0.814820, -0.468253, -0.341771, -0.843411, -0.484624, -0.231944, -0.853744, -0.500558, -0.143399, -0.855501, -0.512666, -0.072746, -0.854267, -0.519757, -0.009032, -0.848630, -0.524082, 0.071867, -0.831792, -0.527144, 0.173903, -0.798459, -0.529823, 0.285920, -0.740889, -0.533591, 0.407876, -0.649550, -0.540023, 0.535220, -0.516923, -0.549533, 0.656357, -0.344128, -0.560343, 0.753387, -0, -0.580570, 0.814210, 0.344127, -0.560343, 0.753387, 0.516922, -0.549533, 0.656357, 0.649549, -0.540023, 0.535221, 0.740889, -0.533591, 0.407877, 0.798459, -0.529823, 0.285920, 0.831792, -0.527144, 0.173904, 0.848630, -0.524082, 0.071867, 0.854267, -0.519757, -0.009032, 0.855501, -0.512666, -0.072745, 0.853744, -0.500558, -0.143398, 0.843411, -0.484624, -0.231943, 0.814820, -0.468253, -0.341770, 0.755609, -0.455771, -0.470455, 0.654454, -0.450729, -0.607070, 0.507166, -0.454178, -0.732465, -0.416008, -0.396244, -0.818491, -0.592064, -0.406112, -0.696084, -0.719605, -0.423471, -0.550309, -0.797685, -0.446462, -0.405425, -0.837201, -0.471119, -0.277745, -0.852714, -0.492974, -0.172788, -0.856422, -0.508721, -0.087997, -0.855661, -0.517385, -0.012519, -0.849875, -0.521271, 0.077389, -0.832250, -0.521792, 0.187330, -0.796886, -0.519707, 0.308021, -0.735254, -0.516435, 0.438972, -0.637289, -0.513865, 0.574287, -0.496105, -0.513304, 0.700285, -0.315105, -0.514521, 0.797481, -0, -0.524704, 0.851285, 0.315105, -0.514522, 0.797481, 0.496105, -0.513304, 0.700285, 0.637288, -0.513865, 0.574287, 0.735254, -0.516435, 0.438972, 0.796886, -0.519707, 0.308021, 0.832250, -0.521792, 0.187331, 0.849875, -0.521271, 0.077389, 0.855661, -0.517386, -0.012518, 0.856422, -0.508721, -0.087996, 0.852714, -0.492974, -0.172787, 0.837201, -0.471119, -0.277743, 0.797686, -0.446462, -0.405424, 0.719606, -0.423472, -0.550307, 0.592067, -0.406112, -0.696082, 0.416011, -0.396244, -0.818489, -0.332434, -0.332322, -0.882638, -0.529112, -0.353877, -0.771240, -0.680332, -0.384176, -0.624146, -0.777866, -0.419537, -0.467882, -0.829616, -0.454547, -0.324227, -0.851190, -0.483966, -0.203108, -0.857236, -0.504345, -0.103837, -0.857076, -0.514937, -0.016145, -0.851177, -0.518251, 0.083154, -0.832772, -0.515720, 0.201307, -0.795306, -0.507964, 0.330849, -0.729465, -0.496416, 0.470587, -0.624874, -0.483548, 0.612954, -0.475792, -0.472046, 0.742155, -0.288256, -0.463712, 0.837782, -0, -0.465879, 0.884848, 0.288256, -0.463712, 0.837783, 0.475791, -0.472046, 0.742156, 0.624874, -0.483548, 0.612955, 0.729464, -0.496416, 0.470588, 0.795305, -0.507964, 0.330850, 0.832771, -0.515720, 0.201307, 0.851177, -0.518251, 0.083154, 0.857076, -0.514937, -0.016144, 0.857236, -0.504345, -0.103836, 0.851190, -0.483966, -0.203107, 0.829617, -0.454548, -0.324226, 0.777867, -0.419537, -0.467880, 0.680333, -0.384176, -0.624144, 0.529115, -0.353878, -0.771238, 0.332437, -0.332322, -0.882637, -0.260763, -0.267018, -0.927741, -0.469361, -0.296861, -0.831609, -0.639578, -0.338882, -0.690000, -0.755831, -0.387408, -0.527859, -0.820718, -0.434551, -0.370927, -0.849191, -0.473268, -0.234290, -0.857969, -0.499418, -0.120293, -0.858538, -0.512362, -0.019921, -0.852574, -0.514942, 0.089183, -0.833420, -0.508731, 0.215877, -0.793805, -0.494212, 0.354441, -0.723623, -0.472968, 0.502664, -0.612464, -0.448459, 0.650978, -0.456266, -0.425338, 0.781606, -0.263920, -0.407828, 0.874084, -0, -0.403788, 0.914852, 0.263920, -0.407828, 0.874084, 0.456266, -0.425338, 0.781607, 0.612463, -0.448459, 0.650978, 0.723622, -0.472968, 0.502665, 0.793805, -0.494212, 0.354441, 0.833420, -0.508731, 0.215878, 0.852573, -0.514942, 0.089183, 0.858538, -0.512362, -0.019920, 0.857969, -0.499419, -0.120292, 0.849191, -0.473268, -0.234289, 0.820719, -0.434551, -0.370926, 0.755832, -0.387408, -0.527857, 0.639579, -0.338882, -0.689998, 0.469364, -0.296861, -0.831607, 0.260766, -0.267019, -0.927740, -0.202715, -0.203332, -0.957895, -0.415707, -0.237633, -0.877905, -0.599263, -0.288856, -0.746623, -0.732250, -0.350190, -0.584104, -0.810634, -0.410785, -0.417286, -0.846754, -0.460577, -0.266227, -0.858652, -0.493804, -0.137384, -0.860079, -0.509603, -0.023857, -0.854112, -0.511246, 0.095499, -0.834276, -0.500582, 0.231089, -0.792483, -0.477978, 0.378823, -0.717833, -0.445410, 0.535094, -0.600214, -0.407891, 0.688018, -0.437807, -0.372712, 0.818175, -0.242405, -0.346728, 0.906101, -0, -0.338089, 0.941114, 0.242405, -0.346728, 0.906101, 0.437807, -0.372712, 0.818175, 0.600213, -0.407891, 0.688018, 0.717833, -0.445410, 0.535095, 0.792483, -0.477978, 0.378824, 0.834276, -0.500582, 0.231090, 0.854112, -0.511246, 0.095500, 0.860079, -0.509603, -0.023856, 0.858652, -0.493805, -0.137383, 0.846754, -0.460577, -0.266225, 0.810635, -0.410785, -0.417284, 0.732251, -0.350191, -0.584102, 0.599265, -0.288857, -0.746621, 0.415710, -0.237634, -0.877904, 0.202719, -0.203332, -0.957894, -0.158247, -0.142774, -0.977023, -0.369993, -0.178144, -0.911795, -0.561202, -0.235422, -0.793491, -0.707955, -0.308162, -0.635481, -0.799574, -0.382923, -0.462657, -0.843939, -0.445543, -0.298763, -0.859326, -0.487335, -0.155124, -0.861733, -0.506591, -0.027965, -0.855849, -0.507042, 0.102128, -0.835435, -0.490960, 0.246994, -0.791456, -0.458668, 0.404006, -0.712198, -0.412907, 0.567698, -0.588272, -0.361030, 0.723597, -0.420681, -0.313663, 0.851259, -0.223992, -0.280240, 0.933431, -0, -0.268437, 0.963297, 0.223991, -0.280240, 0.933431, 0.420681, -0.313663, 0.851260, 0.588272, -0.361030, 0.723598, 0.712198, -0.412907, 0.567699, 0.791456, -0.458667, 0.404007, 0.835435, -0.490960, 0.246995, 0.855849, -0.507042, 0.102129, 0.861733, -0.506591, -0.027964, 0.859326, -0.487335, -0.155122, 0.843939, -0.445543, -0.298761, 0.799574, -0.382924, -0.462655, 0.707957, -0.308162, -0.635479, 0.561204, -0.235423, -0.793490, 0.369996, -0.178144, -0.911794, 0.158250, -0.142774, -0.977022, -0.126409, -0.085833, -0.988258, -0.333137, -0.119655, -0.935255, -0.526937, -0.179782, -0.830672, -0.683886, -0.261715, -0.681032, -0.787832, -0.350662, -0.506316, -0.840838, -0.427757, -0.331685, -0.860048, -0.479802, -0.173516, -0.863544, -0.503241, -0.032254, -0.857856, -0.502175, 0.109100, -0.837022, -0.479464, 0.263646, -0.790853, -0.435515, 0.429974, -0.706809, -0.374437, 0.600181, -0.576764, -0.306956, 0.757048, -0.405136, -0.247681, 0.880068, -0.208935, -0.208201, 0.955509, -0, -0.194535, 0.980895, 0.208935, -0.208201, 0.955510, 0.405136, -0.247681, 0.880068, 0.576763, -0.306956, 0.757049, 0.706809, -0.374437, 0.600182, 0.790853, -0.435515, 0.429975, 0.837021, -0.479464, 0.263647, 0.857856, -0.502175, 0.109101, 0.863544, -0.503241, -0.032253, 0.860048, -0.479802, -0.173514, 0.840839, -0.427758, -0.331683, 0.787833, -0.350663, -0.506314, 0.683887, -0.261716, -0.681031, 0.526939, -0.179783, -0.830670, 0.333140, -0.119655, -0.935254, 0.126412, -0.085834, -0.988257, -0.105930, -0.032421, -0.993845, -0.305385, -0.062852, -0.950152, -0.497664, -0.122919, -0.858616, -0.661022, -0.211307, -0.720000, -0.775797, -0.313714, -0.547469, -0.837587, -0.406737, -0.364708, -0.860894, -0.470942, -0.192549, -0.865568, -0.499442, -0.036735, -0.860227, -0.496437, 0.116448, -0.839191, -0.465554, 0.281100, -0.790814, -0.407525, 0.456658, -0.701718, -0.328747, 0.632073, -0.565767, -0.244662, 0.787432, -0.391388, -0.174307, 0.903567, -0.197467, -0.130520, 0.971582, -0, -0.116190, 0.993227, 0.197466, -0.130519, 0.971582, 0.391387, -0.174307, 0.903567, 0.565766, -0.244662, 0.787432, 0.701718, -0.328747, 0.632074, 0.790814, -0.407525, 0.456659, 0.839191, -0.465553, 0.281101, 0.860227, -0.496436, 0.116449, 0.865568, -0.499442, -0.036734, 0.860894, -0.470942, -0.192547, 0.837588, -0.406738, -0.364707, 0.775798, -0.313715, -0.547467, 0.661023, -0.211308, -0.719998, 0.497666, -0.122920, -0.858615, 0.305388, -0.062853, -0.950152, 0.105933, -0.032421, -0.993845, -0.092655, 0.007310, -0.995672, -0.281931, -0.046106, -0.958326, -0.467252, -0.134929, -0.873768, -0.627370, -0.242858, -0.739883, -0.743903, -0.349972, -0.569322, -0.812681, -0.437535, -0.384855, -0.844544, -0.494275, -0.206003, -0.854304, -0.518221, -0.040156, -0.849383, -0.513431, 0.122221, -0.825928, -0.481098, 0.293918, -0.773952, -0.419140, 0.474679, -0.682036, -0.329882, 0.652690, -0.545384, -0.224963, 0.807433, -0.373218, -0.124593, 0.919339, -0.185254, -0.050615, 0.981386, -0, -0.022759, 0.999741, 0.185254, -0.050615, 0.981386, 0.373217, -0.124593, 0.919340, 0.545384, -0.224963, 0.807433, 0.682036, -0.329882, 0.652691, 0.773952, -0.419139, 0.474679, 0.825927, -0.481098, 0.293919, 0.849383, -0.513430, 0.122222, 0.854304, -0.518221, -0.040155, 0.844544, -0.494276, -0.206001, 0.812681, -0.437536, -0.384853, 0.743904, -0.349973, -0.569320, 0.627372, -0.242859, -0.739881, 0.467254, -0.134931, -0.873766, 0.281934, -0.046107, -0.958325, 0.092657, 0.007309, -0.995671, -0.074102, 0.067094, -0.994991, -0.252624, -0.012387, -0.967485, -0.433184, -0.130917, -0.891747, -0.593277, -0.258663, -0.762310, -0.715309, -0.369498, -0.593131, -0.795312, -0.449474, -0.406759, -0.839389, -0.496681, -0.220758, -0.855948, -0.515227, -0.043531, -0.850634, -0.509197, 0.130918, -0.821298, -0.476985, 0.312979, -0.760319, -0.413681, 0.500782, -0.659627, -0.317399, 0.681286, -0.517168, -0.195485, 0.833261, -0.343997, -0.068602, 0.936461, -0.161912, 0.034003, 0.986219, -0, 0.075244, 0.997165, 0.161912, 0.034003, 0.986219, 0.343996, -0.068601, 0.936462, 0.517167, -0.195484, 0.833261, 0.659626, -0.317399, 0.681286, 0.760319, -0.413681, 0.500783, 0.821297, -0.476985, 0.312980, 0.850634, -0.509197, 0.130919, 0.855948, -0.515227, -0.043530, 0.839389, -0.496681, -0.220757, 0.795312, -0.449474, -0.406757, 0.715310, -0.369499, -0.593129, 0.593278, -0.258664, -0.762308, 0.433187, -0.130919, -0.891745, 0.252627, -0.012388, -0.967485, 0.074104, 0.067093, -0.994991, -0.042489, 0.160812, -0.986070, -0.211634, 0.081812, -0.973919, -0.393661, -0.034841, -0.918595, -0.567383, -0.166964, -0.806349, -0.709723, -0.288681, -0.642617, -0.808552, -0.381034, -0.448393, -0.865037, -0.437374, -0.245796, -0.886644, -0.459886, -0.048656, -0.879686, -0.452542, 0.146146, -0.841673, -0.413703, 0.347039, -0.764751, -0.339222, 0.547799, -0.643588, -0.230586, 0.729812, -0.483135, -0.100618, 0.869745, -0.302151, 0.026992, 0.952878, -0.124544, 0.127084, 0.984042, -0, 0.166950, 0.985965, 0.124544, 0.127084, 0.984042, 0.302150, 0.026993, 0.952878, 0.483134, -0.100617, 0.869746, 0.643587, -0.230585, 0.729813, 0.764751, -0.339221, 0.547800, 0.841673, -0.413703, 0.347040, 0.879686, -0.452542, 0.146147, 0.886644, -0.459886, -0.048654, 0.865037, -0.437374, -0.245794, 0.808553, -0.381035, -0.448391, 0.709724, -0.288682, -0.642615, 0.567385, -0.166965, -0.806348, 0.393663, -0.034842, -0.918594, 0.211636, 0.081811, -0.973918, 0.042491, 0.160812, -0.986070, -0.000998, 0.257338, -0.966321, -0.160325, 0.183491, -0.969859, -0.341382, 0.074322, -0.936981, -0.527562, -0.056123, -0.847661, -0.693359, -0.185062, -0.696423, -0.817437, -0.289558, -0.497948, -0.892266, -0.356436, -0.277154, -0.921732, -0.383879, -0.055204, -0.912188, -0.374875, 0.165475, -0.860943, -0.328036, 0.388805, -0.761433, -0.241485, 0.601586, -0.614609, -0.122354, 0.779285, -0.435345, 0.010478, 0.900203, -0.248864, 0.132687, 0.959407, -0.077434, 0.225328, 0.971201, -0, 0.261735, 0.965140, 0.077433, 0.225328, 0.971201, 0.248863, 0.132687, 0.959407, 0.435345, 0.010479, 0.900203, 0.614609, -0.122354, 0.779285, 0.761432, -0.241484, 0.601587, 0.860943, -0.328036, 0.388807, 0.912188, -0.374875, 0.165477, 0.921732, -0.383879, -0.055202, 0.892267, -0.356437, -0.277152, 0.817438, -0.289559, -0.497946, 0.693361, -0.185063, -0.696421, 0.527564, -0.056125, -0.847659, 0.341385, 0.074321, -0.936981, 0.160327, 0.183490, -0.969859, 0.001000, 0.257337, -0.966321, 0.047408, 0.354201, -0.933967, -0.100139, 0.289852, -0.951818, -0.275653, 0.194624, -0.941348, -0.469690, 0.075004, -0.879639, -0.659328, -0.052551, -0.750017, -0.815572, -0.164710, -0.554719, -0.917482, -0.241492, -0.316082, -0.959533, -0.274319, -0.063601, -0.945777, -0.263450, 0.189999, -0.874024, -0.208362, 0.438939, -0.743271, -0.112014, 0.659546, -0.566893, 0.010819, 0.823720, -0.371501, 0.137078, 0.918257, -0.184671, 0.245899, 0.951541, -0.022771, 0.325988, 0.945100, -0, 0.357667, 0.933849, 0.022771, 0.325988, 0.945100, 0.184670, 0.245900, 0.951541, 0.371500, 0.137079, 0.918258, 0.566892, 0.010820, 0.823721, 0.743270, -0.112014, 0.659547, 0.874023, -0.208362, 0.438940, 0.945777, -0.263449, 0.190001, 0.959533, -0.274320, -0.063599, 0.917483, -0.241492, -0.316080, 0.815573, -0.164711, -0.554716, 0.659330, -0.052552, -0.750015, 0.469693, 0.075002, -0.879638, 0.275656, 0.194622, -0.941348, 0.100141, 0.289851, -0.951819, -0.047406, 0.354200, -0.933967, 0.100027, 0.448526, -0.888155, -0.033196, 0.396999, -0.917219, -0.197144, 0.321634, -0.926113, -0.390250, 0.223862, -0.893079, -0.597828, 0.112538, -0.793686, -0.789730, 0.005888, -0.613426, -0.929286, -0.073479, -0.361978, -0.991230, -0.109444, -0.074056, -0.970633, -0.097367, 0.219981, -0.868113, -0.038498, 0.494871, -0.698071, 0.057203, 0.713740, -0.493791, 0.168958, 0.853009, -0.290594, 0.275216, 0.916412, -0.111195, 0.362331, 0.925393, 0.037021, 0.425658, 0.904126, -0, 0.452742, 0.891641, -0.037021, 0.425659, 0.904126, 0.111194, 0.362331, 0.925393, 0.290594, 0.275216, 0.916412, 0.493790, 0.168958, 0.853009, 0.698070, 0.057203, 0.713741, 0.868112, -0.038497, 0.494872, 0.970632, -0.097366, 0.219983, 0.991231, -0.109444, -0.074054, 0.929287, -0.073479, -0.361976, 0.789732, 0.005887, -0.613424, 0.597830, 0.112537, -0.793684, 0.390253, 0.223861, -0.893078, 0.197146, 0.321633, -0.926113, 0.033198, 0.396998, -0.917219, -0.100025, 0.448525, -0.888155, 0.154276, 0.537358, -0.829123, 0.037648, 0.500325, -0.865019, -0.108596, 0.448400, -0.887212, -0.288734, 0.381863, -0.877960, -0.498749, 0.304956, -0.811327, -0.717057, 0.228203, -0.658599, -0.897933, 0.167842, -0.406873, -0.986604, 0.139057, -0.085300, -0.956413, 0.148880, 0.251215, -0.815813, 0.194877, 0.544492, -0.609168, 0.265634, 0.747230, -0.390822, 0.344213, 0.853683, -0.194389, 0.416817, 0.887962, -0.031397, 0.476268, 0.878739, 0.099256, 0.520634, 0.847991, -0, 0.544920, 0.838488, -0.099256, 0.520634, 0.847991, 0.031397, 0.476269, 0.878739, 0.194389, 0.416817, 0.887962, 0.390821, 0.344214, 0.853684, 0.609167, 0.265634, 0.747231, 0.815812, 0.194878, 0.544494, 0.956412, 0.148880, 0.251217, 0.986604, 0.139057, -0.085297, 0.897934, 0.167842, -0.406871, 0.717059, 0.228202, -0.658597, 0.498751, 0.304956, -0.811326, 0.288736, 0.381862, -0.877959, 0.108598, 0.448399, -0.887212, -0.037646, 0.500324, -0.865019, -0.154274, 0.537358, -0.829124, 0.207762, 0.618057, -0.758182, 0.109073, 0.595246, -0.796106, -0.014889, 0.566623, -0.823842, -0.170279, 0.534427, -0.827884, -0.359923, 0.503488, -0.785465, -0.574053, 0.480747, -0.662831, -0.771939, 0.470673, -0.427291, -0.878538, 0.468749, -0.091895, -0.841361, 0.469260, 0.268154, -0.679265, 0.474172, 0.560143, -0.465497, 0.490662, 0.736589, -0.260959, 0.518390, 0.814354, -0.088335, 0.550737, 0.829991, 0.050658, 0.581574, 0.811915, 0.161171, 0.607439, 0.777844, -0, 0.632201, 0.774805, -0.161171, 0.607439, 0.777844, -0.050659, 0.581574, 0.811915, 0.088335, 0.550737, 0.829991, 0.260958, 0.518390, 0.814354, 0.465496, 0.490662, 0.736590, 0.679264, 0.474172, 0.560144, 0.841360, 0.469260, 0.268156, 0.878538, 0.468749, -0.091892, 0.771940, 0.470672, -0.427288, 0.574055, 0.480747, -0.662830, 0.359925, 0.503487, -0.785464, 0.170281, 0.534427, -0.827884, 0.014891, 0.566623, -0.823843, -0.109071, 0.595246, -0.796107, -0.207761, 0.618057, -0.758183, 0.258447, 0.688630, -0.677490, 0.177797, 0.678054, -0.713184, 0.077935, 0.668894, -0.739261, -0.045702, 0.665756, -0.744769, -0.196033, 0.675702, -0.710632, -0.367828, 0.705229, -0.606098, -0.531138, 0.748969, -0.396154, -0.621914, 0.778349, -0.085997, -0.589949, 0.767742, 0.250065, -0.453955, 0.726598, 0.515732, -0.280275, 0.687871, 0.669537, -0.117531, 0.668594, 0.734281, 0.019349, 0.666180, 0.745540, 0.130559, 0.673070, 0.727964, 0.220236, 0.683356, 0.696075, -0, 0.712724, 0.701444, -0.220237, 0.683356, 0.696075, -0.130559, 0.673070, 0.727964, -0.019349, 0.666180, 0.745540, 0.117530, 0.668594, 0.734281, 0.280274, 0.687871, 0.669538, 0.453954, 0.726598, 0.515734, 0.589948, 0.767742, 0.250068, 0.621914, 0.778349, -0.085994, 0.531139, 0.748969, -0.396151, 0.367830, 0.705229, -0.606097, 0.196035, 0.675702, -0.710632, 0.045704, 0.665756, -0.744769, -0.077933, 0.668894, -0.739262, -0.177795, 0.678054, -0.713185, -0.258446, 0.688630, -0.677491, 0.304777, 0.747918, -0.589687, 0.241111, 0.746510, -0.620152, 0.164319, 0.750742, -0.639833, 0.072656, 0.765853, -0.638897, -0.033594, 0.798378, -0.601219, -0.148014, 0.851462, -0.503094, -0.249986, 0.913111, -0.322079, -0.304012, 0.950162, -0.069051, -0.285170, 0.937016, 0.201689, -0.202601, 0.882927, 0.423548, -0.090630, 0.822568, 0.561398, 0.021175, 0.779561, 0.625968, 0.120406, 0.756535, 0.642774, 0.204488, 0.747642, 0.631836, 0.274446, 0.746755, 0.605835, -0, 0.784876, 0.619652, -0.274446, 0.746755, 0.605835, -0.204488, 0.747642, 0.631836, -0.120406, 0.756534, 0.642774, -0.021175, 0.779561, 0.625968, 0.090630, 0.822568, 0.561399, 0.202600, 0.882927, 0.423549, 0.285170, 0.937016, 0.201690, 0.304013, 0.950162, -0.069049, 0.249986, 0.913112, -0.322077, 0.148015, 0.851463, -0.503093, 0.033595, 0.798379, -0.601218, -0.072655, 0.765853, -0.638897, -0.164318, 0.750742, -0.639833, -0.241110, 0.746510, -0.620153, -0.304776, 0.747918, -0.589687, 0.345742, 0.795591, -0.497492, 0.297215, 0.799981, -0.521242, 0.240525, 0.811291, -0.532873, 0.176087, 0.833602, -0.523546, 0.106454, 0.870486, -0.480543, 0.038161, 0.920488, -0.388903, -0.016621, 0.970506, -0.240505, -0.043408, 0.997778, -0.050538, -0.034226, 0.988293, 0.148677, 0.008126, 0.946853, 0.321565, 0.071515, 0.894330, 0.441655, 0.141631, 0.850116, 0.507191, 0.209182, 0.820802, 0.531532, 0.269898, 0.804533, 0.529039, 0.322476, 0.797141, 0.510466, -0, 0.847379, 0.530989, -0.322476, 0.797141, 0.510466, -0.269898, 0.804533, 0.529039, -0.209183, 0.820802, 0.531532, -0.141632, 0.850116, 0.507191, -0.071515, 0.894330, 0.441655, -0.008127, 0.946853, 0.321565, 0.034226, 0.988293, 0.148679, 0.043408, 0.997778, -0.050536, 0.016621, 0.970506, -0.240503, -0.038160, 0.920488, -0.388902, -0.106453, 0.870486, -0.480543, -0.176086, 0.833602, -0.523546, -0.240524, 0.811292, -0.532873, -0.297214, 0.799981, -0.521243, -0.345741, 0.795591, -0.497492, 0.380845, 0.832006, -0.403390, 0.345264, 0.839144, -0.420274, 0.304981, 0.852429, -0.424678, 0.261379, 0.874138, -0.409346, 0.217416, 0.905024, -0.365598, 0.177938, 0.941507, -0.286186, 0.149081, 0.973830, -0.171552, 0.135889, 0.990090, -0.035447, 0.140347, 0.984529, 0.104902, 0.161801, 0.958986, 0.232737, 0.196745, 0.923038, 0.330595, 0.239185, 0.888519, 0.391567, 0.283453, 0.862119, 0.420006, 0.325654, 0.844866, 0.424442, 0.363682, 0.834956, 0.413018, -0, 0.899352, 0.437226, -0.363682, 0.834956, 0.413018, -0.325655, 0.844866, 0.424442, -0.283453, 0.862119, 0.420006, -0.239185, 0.888519, 0.391567, -0.196745, 0.923037, 0.330595, -0.161801, 0.958986, 0.232737, -0.140347, 0.984529, 0.104903, -0.135889, 0.990090, -0.035445, -0.149081, 0.973830, -0.171551, -0.177938, 0.941507, -0.286185, -0.217416, 0.905024, -0.365597, -0.261379, 0.874138, -0.409346, -0.304980, 0.852429, -0.424678, -0.345263, 0.839144, -0.420274, -0.380844, 0.832006, -0.403390, 0.410001, 0.857991, -0.309437, 0.385192, 0.865492, -0.320237, 0.357817, 0.877393, -0.319605, 0.329349, 0.894504, -0.302310, 0.302162, 0.916144, -0.263398, 0.279269, 0.939019, -0.200628, 0.263550, 0.957462, -0.117506, 0.256665, 0.966202, -0.023996, 0.258970, 0.963250, 0.071306, 0.270368, 0.949181, 0.161112, 0.289983, 0.927746, 0.234942, 0.315416, 0.904894, 0.285797, 0.343592, 0.885290, 0.313379, 0.371754, 0.870822, 0.321665, 0.397975, 0.861267, 0.315966, 0, 0.940342, 0.340230, -0.397975, 0.861267, 0.315966, -0.371755, 0.870822, 0.321665, -0.343592, 0.885290, 0.313379, -0.315416, 0.904894, 0.285797, -0.289984, 0.927746, 0.234942, -0.270368, 0.949181, 0.161112, -0.258970, 0.963250, 0.071306, -0.256665, 0.966202, -0.023995, -0.263549, 0.957462, -0.117505, -0.279269, 0.939019, -0.200628, -0.302162, 0.916144, -0.263398, -0.329349, 0.894504, -0.302310, -0.357817, 0.877394, -0.319605, -0.385192, 0.865492, -0.320237, -0.410000, 0.857991, -0.309437, 0.433417, 0.874627, -0.217203, 0.417451, 0.880860, -0.223203, 0.400128, 0.889632, -0.220121, 0.382590, 0.900950, -0.204729, 0.366415, 0.913890, -0.174773, 0.353313, 0.926372, -0.130400, 0.344628, 0.935727, -0.075143, 0.340912, 0.939972, -0.015226, 0.342150, 0.938550, 0.045365, 0.348362, 0.931597, 0.103780, 0.359382, 0.920354, 0.154251, 0.374223, 0.907322, 0.191635, 0.391295, 0.895003, 0.214143, 0.408900, 0.884912, 0.223007, 0.425654, 0.877450, 0.221132, -0, 0.970315, 0.241844, -0.425654, 0.877450, 0.221132, -0.408900, 0.884912, 0.223007, -0.391295, 0.895003, 0.214143, -0.374223, 0.907322, 0.191635, -0.359382, 0.920354, 0.154251, -0.348362, 0.931597, 0.103780, -0.342150, 0.938550, 0.045366, -0.340912, 0.939972, -0.015225, -0.344628, 0.935727, -0.075142, -0.353313, 0.926372, -0.130399, -0.366415, 0.913890, -0.174773, -0.382589, 0.900950, -0.204729, -0.400128, 0.889632, -0.220121, -0.417450, 0.880861, -0.223204, -0.433417, 0.874627, -0.217203, 0.451481, 0.883081, -0.127801, 0.442764, 0.887099, -0.130444, 0.433371, 0.892181, -0.127288, 0.423981, 0.898115, -0.116746, 0.415470, 0.904301, -0.098105, 0.408702, 0.909815, -0.072114, 0.404288, 0.913708, -0.041099, 0.402422, 0.915417, -0.008285, 0.403042, 0.914847, 0.024729, 0.406178, 0.912012, 0.057040, 0.411821, 0.907206, 0.085917, 0.419558, 0.901229, 0.108431, 0.428624, 0.895069, 0.123014, 0.438116, 0.889512, 0.129703, 0.447239, 0.884956, 0.129733, -0, 0.989608, 0.143789, -0.447239, 0.884956, 0.129733, -0.438116, 0.889512, 0.129703, -0.428624, 0.895069, 0.123014, -0.419558, 0.901229, 0.108430, -0.411821, 0.907205, 0.085917, -0.406178, 0.912012, 0.057040, -0.403042, 0.914847, 0.024729, -0.402422, 0.915417, -0.008285, -0.404288, 0.913708, -0.041099, -0.408702, 0.909815, -0.072114, -0.415470, 0.904301, -0.098105, -0.423981, 0.898115, -0.116746, -0.433371, 0.892181, -0.127288, -0.442764, 0.887099, -0.130444, -0.451480, 0.883081, -0.127801 };
    NormalInterpolator_17.keyValue = m_keyValue;
    NormalInterpolator_17.keyValue_length = sizeof(m_keyValue) / sizeof(float);
    }
    NormalInterpolator_17.set_fraction = 0;
    {
    static float m_value_changed[1];
    NormalInterpolator_17.value_changed = NULL;
    NormalInterpolator_17.value_changed_length = 0;
    }
    NurbsSurface1.setGlName(0);
    NurbsSurface1.m_parent = (X3dNode *)&Shape_14;
    Coordinate1.m_parent = (X3dNode *)&NurbsSurface1;
    {
    static float m_point[] = { 0, -1, 0, 0, -1, 0, 0, -1, 0, 0, -1, 0, 0, -1, 0, 0, -1, 0, 0, -1, 0, 0, -1, 0, 0, -1, 0, 0, -1, 0, 0, -1, 0, 0, -1, 0, 0, -1, 0, 0, -1, 0, 0, -1, 0, 0, -1, 0, 0, -1, 0, 0, -1, 0, 0, -1, 0, 0, -1, 0, 0, -1, 0, 0, -1, 0, 0, -1, 0, 0, -1, 0, 0, -1, 0, 0, -1, 0, 0, -1, 0, 0, -1, 0, 0, -1, 0, 0, -1, 0, 0, -1, 0, 0, -1, 0, 0, -0.995685, -0.092796, -0.017442, -0.995685, -0.091142, -0.035262, -0.995685, -0.085836, -0.052311, -0.995685, -0.076647, -0.067347, -0.995685, -0.063840, -0.079303, -0.995685, -0.048189, -0.087525, -0.995685, -0.030831, -0.091880, -0.995685, -0.013006, -0.092698, -0.995685, 0.004271, -0.090174, -0.995685, 0.021902, -0.083901, -0.995685, 0.039645, -0.073762, -0.995685, 0.056305, -0.060154, -0.995685, 0.070658, -0.043961, -0.995685, 0.081723, -0.026371, -0.995685, 0.088970, -0.008611, -0.995685, 0.092396, 0.008611, -0.995685, 0.092396, 0.026371, -0.995685, 0.088970, 0.043961, -0.995685, 0.081723, 0.060154, -0.995685, 0.070658, 0.073762, -0.995685, 0.056305, 0.083901, -0.995685, 0.039645, 0.090174, -0.995685, 0.021903, 0.092698, -0.995685, 0.004272, 0.091880, -0.995685, -0.013006, 0.087525, -0.995685, -0.030831, 0.079303, -0.995685, -0.048189, 0.067347, -0.995685, -0.063840, 0.052311, -0.995685, -0.076647, 0.035262, -0.995685, -0.085835, 0.017442, -0.995685, -0.091142, 0, -0.995685, -0.092796, 0, -0.982177, -0.187956, -0.035328, -0.982177, -0.184607, -0.071422, -0.982177, -0.173858, -0.105954, -0.982177, -0.155246, -0.136409, -0.982177, -0.129307, -0.160626, -0.982177, -0.097607, -0.177279, -0.982177, -0.062447, -0.186101, -0.982177, -0.026343, -0.187757, -0.982177, 0.008652, -0.182646, -0.982177, 0.044363, -0.169940, -0.982177, 0.080300, -0.149404, -0.982177, 0.114045, -0.121841, -0.982177, 0.143117, -0.089042, -0.982177, 0.165527, -0.053415, -0.982177, 0.180207, -0.017442, -0.982177, 0.187145, 0.017442, -0.982177, 0.187145, 0.053415, -0.982177, 0.180207, 0.089042, -0.982177, 0.165527, 0.121841, -0.982177, 0.143117, 0.149404, -0.982177, 0.114045, 0.169940, -0.982177, 0.080301, 0.182646, -0.982177, 0.044363, 0.187757, -0.982177, 0.008652, 0.186101, -0.982177, -0.026343, 0.177280, -0.982177, -0.062447, 0.160626, -0.982177, -0.097606, 0.136409, -0.982177, -0.129306, 0.105954, -0.982177, -0.155246, 0.071422, -0.982177, -0.173858, 0.035328, -0.982177, -0.184606, 0.000001, -0.982177, -0.187956, 0, -0.958769, -0.284186, -0.053415, -0.958769, -0.279121, -0.107989, -0.958769, -0.262869, -0.160200, -0.958769, -0.234729, -0.206247, -0.958769, -0.195509, -0.242862, -0.958769, -0.147579, -0.268043, -0.958769, -0.094419, -0.281381, -0.958769, -0.039831, -0.283885, -0.958769, 0.013081, -0.276157, -0.958769, 0.067076, -0.256945, -0.958769, 0.121412, -0.225895, -0.958769, 0.172433, -0.184221, -0.958769, 0.216390, -0.134630, -0.958769, 0.250273, -0.080762, -0.958769, 0.272469, -0.026371, -0.958769, 0.282960, 0.026371, -0.958769, 0.282960, 0.080762, -0.958769, 0.272469, 0.134629, -0.958769, 0.250273, 0.184221, -0.958769, 0.216390, 0.225895, -0.958769, 0.172433, 0.256945, -0.958769, 0.121413, 0.276157, -0.958769, 0.067076, 0.283885, -0.958769, 0.013082, 0.281381, -0.958769, -0.039830, 0.268043, -0.958769, -0.094418, 0.242863, -0.958769, -0.147579, 0.206248, -0.958769, -0.195509, 0.160201, -0.958769, -0.234729, 0.107989, -0.958769, -0.262869, 0.053415, -0.958769, -0.279121, 0.000001, -0.958769, -0.284186, 0, -0.924990, -0.379992, -0.071422, -0.924990, -0.373220, -0.144394, -0.924990, -0.351489, -0.214207, -0.924990, -0.313862, -0.275778, -0.924990, -0.261420, -0.324737, -0.924990, -0.197332, -0.358407, -0.924990, -0.126249, -0.376242, -0.924990, -0.053258, -0.379590, -0.924990, 0.017491, -0.369256, -0.924990, 0.089688, -0.343568, -0.924990, 0.162344, -0.302050, -0.924990, 0.230564, -0.246326, -0.924990, 0.289340, -0.180017, -0.924990, 0.334646, -0.107989, -0.924990, 0.364325, -0.035262, -0.924990, 0.378353, 0.035262, -0.924990, 0.378353, 0.107988, -0.924990, 0.364325, 0.180016, -0.924990, 0.334646, 0.246326, -0.924990, 0.289340, 0.302050, -0.924990, 0.230565, 0.343568, -0.924990, 0.162344, 0.369256, -0.924990, 0.089689, 0.379590, -0.924990, 0.017492, 0.376242, -0.924990, -0.053258, 0.358407, -0.924990, -0.126249, 0.324738, -0.924990, -0.197331, 0.275779, -0.924990, -0.261419, 0.214208, -0.924990, -0.313862, 0.144395, -0.924990, -0.351489, 0.071423, -0.924990, -0.373220, 0.000001, -0.924990, -0.379992, 0, -0.880666, -0.473738, -0.089042, -0.880666, -0.465294, -0.180017, -0.880666, -0.438202, -0.267053, -0.880666, -0.391293, -0.343814, -0.880666, -0.325913, -0.404851, -0.880666, -0.246014, -0.446827, -0.880666, -0.157395, -0.469061, -0.880666, -0.066397, -0.473235, -0.880666, 0.021806, -0.460353, -0.880666, 0.111815, -0.428327, -0.880666, 0.202394, -0.376567, -0.880666, 0.287445, -0.307096, -0.880666, 0.360721, -0.224427, -0.880666, 0.417205, -0.134630, -0.880666, 0.454205, -0.043961, -0.880666, 0.471693, 0.043961, -0.880666, 0.471693, 0.134629, -0.880666, 0.454205, 0.224427, -0.880666, 0.417205, 0.307095, -0.880666, 0.360721, 0.376566, -0.880666, 0.287446, 0.428327, -0.880666, 0.202395, 0.460353, -0.880666, 0.111815, 0.473235, -0.880666, 0.021807, 0.469061, -0.880666, -0.066397, 0.446827, -0.880666, -0.157395, 0.404852, -0.880666, -0.246013, 0.343814, -0.880666, -0.325912, 0.267054, -0.880666, -0.391292, 0.180018, -0.880666, -0.438202, 0.089043, -0.880666, -0.465294, 0.000001, -0.880666, -0.473738, 0, -0.825969, -0.563715, -0.105954, -0.825969, -0.553668, -0.214207, -0.825969, -0.521430, -0.317775, -0.825969, -0.465611, -0.409115, -0.825969, -0.387814, -0.481745, -0.825969, -0.292740, -0.531693, -0.825969, -0.187290, -0.558151, -0.825969, -0.079008, -0.563117, -0.825969, 0.025948, -0.547788, -0.825969, 0.133052, -0.509679, -0.825969, 0.240835, -0.448088, -0.825969, 0.342040, -0.365423, -0.825969, 0.429233, -0.267053, -0.825969, 0.496445, -0.160200, -0.825969, 0.540472, -0.052311, -0.825969, 0.561283, 0.052311, -0.825969, 0.561283, 0.160200, -0.825969, 0.540473, 0.267053, -0.825969, 0.496445, 0.365422, -0.825969, 0.429233, 0.448088, -0.825969, 0.342041, 0.509679, -0.825969, 0.240836, 0.547788, -0.825969, 0.133053, 0.563117, -0.825969, 0.025949, 0.558151, -0.825970, -0.079007, 0.531693, -0.825969, -0.187289, 0.481746, -0.825969, -0.292738, 0.409116, -0.825969, -0.387813, 0.317776, -0.825969, -0.465610, 0.214209, -0.825969, -0.521430, 0.105955, -0.825969, -0.553668, 0.000002, -0.825969, -0.563715, 0, -0.761436, -0.648240, -0.121841, -0.761436, -0.636687, -0.246326, -0.761436, -0.599615, -0.365423, -0.761436, -0.535426, -0.470458, -0.761436, -0.445964, -0.553979, -0.761436, -0.336634, -0.611416, -0.761436, -0.215373, -0.641841, -0.761436, -0.090855, -0.647553, -0.761436, 0.029839, -0.629925, -0.761436, 0.153002, -0.586102, -0.761436, 0.276947, -0.515276, -0.761436, 0.393327, -0.420215, -0.761436, 0.493593, -0.307096, -0.761436, 0.570883, -0.184221, -0.761436, 0.621513, -0.060154, -0.761436, 0.645443, 0.060154, -0.761436, 0.645443, 0.184221, -0.761436, 0.621513, 0.307095, -0.761436, 0.570883, 0.420215, -0.761436, 0.493594, 0.515276, -0.761436, 0.393327, 0.586102, -0.761436, 0.276947, 0.629925, -0.761436, 0.153003, 0.647553, -0.761436, 0.029840, 0.641842, -0.761436, -0.090854, 0.611417, -0.761436, -0.215371, 0.553980, -0.761436, -0.336633, 0.470459, -0.761436, -0.445963, 0.365424, -0.761436, -0.535425, 0.246328, -0.761436, -0.599615, 0.121843, -0.761436, -0.636686, 0.000002, -0.761436, -0.648240, 0, -0.687961, -0.725747, -0.136409, -0.687961, -0.712813, -0.275778, -0.687961, -0.671309, -0.409115, -0.687961, -0.599445, -0.526709, -0.687961, -0.499286, -0.620216, -0.687961, -0.376884, -0.684521, -0.687961, -0.241124, -0.718584, -0.687961, -0.101718, -0.724978, -0.687961, 0.033406, -0.705243, -0.687961, 0.171296, -0.656180, -0.687961, 0.310060, -0.576885, -0.687961, 0.440355, -0.470459, -0.687961, 0.552610, -0.343814, -0.687961, 0.639141, -0.206247, -0.687961, 0.695824, -0.067347, -0.687961, 0.722616, 0.067347, -0.687961, 0.722616, 0.206247, -0.687961, 0.695824, 0.343813, -0.687961, 0.639141, 0.470458, -0.687961, 0.552611, 0.576885, -0.687961, 0.440355, 0.656179, -0.687961, 0.310061, 0.705242, -0.687961, 0.171297, 0.724978, -0.687961, 0.033407, 0.718584, -0.687961, -0.101717, 0.684521, -0.687961, -0.241122, 0.620217, -0.687961, -0.376882, 0.526710, -0.687961, -0.499285, 0.409116, -0.687961, -0.599444, 0.275780, -0.687961, -0.671308, 0.136411, -0.687961, -0.712812, 0.000002, -0.687961, -0.725747, 0, -0.606761, -0.794885, -0.149404, -0.606761, -0.780717, -0.302050, -0.606761, -0.735260, -0.448088, -0.606761, -0.656550, -0.576885, -0.606761, -0.546850, -0.679300, -0.606761, -0.412787, -0.749730, -0.606761, -0.264094, -0.787038, -0.606761, -0.111408, -0.794042, -0.606761, 0.036589, -0.772426, -0.606761, 0.187614, -0.718690, -0.606761, 0.339597, -0.631841, -0.606761, 0.482305, -0.515276, -0.606761, 0.605254, -0.376567, -0.606761, 0.700028, -0.225895, -0.606761, 0.762111, -0.073762, -0.606761, 0.791455, 0.073762, -0.606761, 0.791455, 0.225895, -0.606761, 0.762111, 0.376566, -0.606761, 0.700028, 0.515275, -0.606761, 0.605254, 0.631841, -0.606761, 0.482305, 0.718689, -0.606761, 0.339598, 0.772426, -0.606761, 0.187615, 0.794042, -0.606761, 0.036590, 0.787039, -0.606761, -0.111407, 0.749731, -0.606761, -0.264093, 0.679301, -0.606761, -0.412785, 0.576887, -0.606761, -0.546848, 0.448090, -0.606761, -0.656549, 0.302052, -0.606761, -0.735259, 0.149406, -0.606761, -0.780717, 0.000002, -0.606761, -0.794885, 0, -0.519304, -0.854590, -0.160626, -0.519304, -0.839358, -0.324737, -0.519304, -0.790487, -0.481745, -0.519304, -0.705865, -0.620216, -0.519304, -0.587925, -0.730323, -0.519304, -0.443792, -0.806044, -0.519304, -0.283931, -0.846154, -0.519304, -0.119776, -0.853684, -0.519304, 0.039337, -0.830444, -0.519304, 0.201706, -0.772672, -0.519304, 0.365105, -0.679300, -0.519304, 0.518531, -0.553979, -0.519304, 0.650715, -0.404851, -0.519304, 0.752608, -0.242863, -0.519304, 0.819354, -0.079303, -0.519304, 0.850902, 0.079303, -0.519304, 0.850902, 0.242862, -0.519304, 0.819354, 0.404851, -0.519304, 0.752608, 0.553979, -0.519304, 0.650716, 0.679299, -0.519304, 0.518532, 0.772671, -0.519304, 0.365106, 0.830444, -0.519304, 0.201707, 0.853684, -0.519304, 0.039338, 0.846154, -0.519304, -0.119775, 0.806044, -0.519304, -0.283929, 0.730324, -0.519304, -0.443790, 0.620217, -0.519304, -0.587923, 0.481747, -0.519304, -0.705864, 0.324740, -0.519304, -0.790486, 0.160628, -0.519304, -0.839358, 0.000002, -0.519304, -0.854589, 0, -0.427229, -0.904144, -0.169940, -0.427229, -0.888029, -0.343568, -0.427229, -0.836323, -0.509679, -0.427229, -0.746795, -0.656180, -0.427229, -0.622016, -0.772672, -0.427229, -0.469526, -0.852783, -0.427229, -0.300394, -0.895219, -0.427229, -0.126722, -0.903185, -0.427229, 0.041618, -0.878599, -0.427229, 0.213402, -0.817476, -0.427229, 0.386276, -0.718690, -0.427229, 0.548599, -0.586102, -0.427229, 0.688448, -0.428327, -0.427229, 0.796249, -0.256945, -0.427229, 0.866865, -0.083901, -0.427229, 0.900242, 0.083901, -0.427229, 0.900242, 0.256945, -0.427229, 0.866865, 0.428326, -0.427229, 0.796249, 0.586102, -0.427229, 0.688448, 0.718689, -0.427229, 0.548600, 0.817475, -0.427229, 0.386277, 0.878598, -0.427229, 0.213403, 0.903185, -0.427229, 0.041619, 0.895219, -0.427229, -0.126720, 0.852784, -0.427229, -0.300393, 0.772673, -0.427229, -0.469524, 0.656181, -0.427229, -0.622014, 0.509681, -0.427229, -0.746794, 0.343570, -0.427229, -0.836323, 0.169942, -0.427229, -0.888029, 0.000002, -0.427229, -0.904144, 0, -0.332242, -0.943194, -0.177279, -0.332242, -0.926384, -0.358407, -0.332242, -0.872445, -0.531693, -0.332242, -0.779050, -0.684521, -0.332242, -0.648881, -0.806044, -0.332242, -0.489805, -0.889615, -0.332242, -0.313369, -0.933884, -0.332242, -0.132195, -0.942194, -0.332242, 0.043416, -0.916546, -0.332242, 0.222619, -0.852783, -0.332242, 0.402959, -0.749730, -0.332242, 0.572293, -0.611416, -0.332242, 0.718182, -0.446827, -0.332242, 0.830639, -0.268043, -0.332242, 0.904305, -0.087525, -0.332242, 0.939124, 0.087525, -0.332242, 0.939124, 0.268042, -0.332242, 0.904306, 0.446826, -0.332242, 0.830639, 0.611416, -0.332242, 0.718183, 0.749730, -0.332242, 0.572294, 0.852783, -0.332242, 0.402961, 0.916545, -0.332242, 0.222620, 0.942194, -0.332242, 0.043417, 0.933884, -0.332242, -0.132193, 0.889616, -0.332242, -0.313367, 0.806045, -0.332242, -0.489803, 0.684522, -0.332242, -0.648880, 0.531695, -0.332242, -0.779048, 0.358409, -0.332242, -0.872444, 0.177282, -0.332242, -0.926383, 0.000003, -0.332242, -0.943194, 0, -0.236027, -0.971747, -0.182646, -0.236027, -0.954427, -0.369256, -0.236027, -0.898855, -0.547788, -0.236027, -0.802633, -0.705242, -0.236027, -0.668524, -0.830444, -0.236027, -0.504632, -0.916546, -0.236027, -0.322855, -0.962155, -0.236027, -0.136197, -0.970716, -0.236027, 0.044730, -0.944291, -0.236027, 0.229358, -0.878599, -0.236027, 0.415158, -0.772426, -0.236027, 0.589618, -0.629925, -0.236027, 0.739923, -0.460353, -0.236027, 0.855784, -0.276157, -0.236027, 0.931681, -0.090175, -0.236027, 0.967554, 0.090174, -0.236027, 0.967554, 0.276157, -0.236027, 0.931681, 0.460352, -0.236027, 0.855784, 0.629924, -0.236027, 0.739923, 0.772426, -0.236027, 0.589618, 0.878598, -0.236027, 0.415159, 0.944291, -0.236027, 0.229359, 0.970716, -0.236027, 0.044731, 0.962155, -0.236027, -0.136195, 0.916546, -0.236027, -0.322853, 0.830445, -0.236027, -0.504630, 0.705244, -0.236027, -0.668522, 0.547790, -0.236027, -0.802632, 0.369259, -0.236027, -0.898854, 0.182649, -0.236027, -0.954427, 0.000003, -0.236027, -0.971747, 0, -0.140157, -0.990129, -0.186101, -0.140157, -0.972483, -0.376242, -0.140157, -0.915859, -0.558151, -0.140157, -0.817816, -0.718584, -0.140157, -0.681171, -0.846154, -0.140157, -0.514178, -0.933884, -0.140157, -0.328963, -0.980356, -0.140157, -0.138773, -0.989080, -0.140157, 0.045576, -0.962155, -0.140157, 0.233697, -0.895219, -0.140157, 0.423012, -0.787039, -0.140157, 0.600772, -0.641842, -0.140157, 0.753920, -0.469061, -0.140157, 0.871973, -0.281381, -0.140157, 0.949305, -0.091880, -0.140157, 0.985857, 0.091880, -0.140157, 0.985857, 0.281381, -0.140157, 0.949306, 0.469061, -0.140157, 0.871974, 0.641841, -0.140157, 0.753921, 0.787038, -0.140157, 0.600772, 0.895219, -0.140157, 0.423013, 0.962155, -0.140157, 0.233698, 0.989080, -0.140157, 0.045577, 0.980356, -0.140157, -0.138772, 0.933885, -0.140157, -0.328961, 0.846155, -0.140157, -0.514176, 0.718585, -0.140157, -0.681169, 0.558153, -0.140157, -0.817815, 0.376244, -0.140157, -0.915858, 0.186104, -0.140157, -0.972482, 0.000003, -0.140157, -0.990129, 0, -0.046031, -0.998940, -0.187757, -0.046031, -0.981136, -0.379590, -0.046031, -0.924009, -0.563117, -0.046031, -0.825094, -0.724978, -0.046031, -0.687232, -0.853684, -0.046031, -0.518754, -0.942194, -0.046031, -0.331890, -0.989080, -0.046031, -0.140008, -0.997881, -0.046031, 0.045982, -0.970717, -0.046031, 0.235777, -0.903185, -0.046031, 0.426776, -0.794042, -0.046031, 0.606118, -0.647553, -0.046031, 0.760629, -0.473235, -0.046031, 0.879733, -0.283885, -0.046031, 0.957753, -0.092698, -0.046031, 0.994630, 0.092698, -0.046031, 0.994630, 0.283885, -0.046031, 0.957753, 0.473235, -0.046031, 0.879733, 0.647552, -0.046031, 0.760629, 0.794041, -0.046031, 0.606118, 0.903185, -0.046031, 0.426777, 0.970716, -0.046031, 0.235778, 0.997881, -0.046031, 0.045983, 0.989080, -0.046031, -0.140007, 0.942195, -0.046031, -0.331888, 0.853685, -0.046031, -0.518752, 0.724980, -0.046031, -0.687230, 0.563120, -0.046031, -0.825093, 0.379592, -0.046031, -0.924008, 0.187760, -0.046031, -0.981136, 0.000003, -0.046031, -0.998940, 0, 0.046030, -0.998940, -0.187757, 0.046030, -0.981136, -0.379590, 0.046030, -0.924009, -0.563117, 0.046030, -0.825094, -0.724978, 0.046030, -0.687232, -0.853684, 0.046030, -0.518754, -0.942194, 0.046030, -0.331890, -0.989080, 0.046030, -0.140008, -0.997856, 0.046030, 0.045982, -0.970599, 0.046030, 0.235777, -0.902997, 0.046030, 0.426776, -0.793814, 0.046030, 0.606118, -0.647321, 0.046030, 0.760629, -0.473035, 0.046030, 0.879733, -0.283747, 0.046030, 0.957753, -0.092648, 0.046030, 0.994630, 0.092698, 0.046030, 0.994630, 0.283885, 0.046030, 0.957753, 0.473235, 0.046030, 0.879733, 0.647552, 0.046030, 0.760629, 0.794041, 0.046030, 0.606118, 0.903185, 0.046030, 0.426777, 0.970716, 0.046030, 0.235778, 0.997881, 0.046030, 0.045983, 0.989105, 0.045509, -0.140007, 0.942339, 0.045256, -0.331888, 0.854053, 0.045604, -0.518752, 0.725674, 0.046595, -0.687230, 0.564224, 0.048190, -0.825092, 0.381162, 0.050269, -0.924008, 0.189816, 0.052658, -0.981136, 0.002534, 0.055177, -0.998940, 0, 0.140157, -0.990129, -0.186101, 0.140156, -0.972483, -0.376242, 0.140156, -0.915859, -0.558151, 0.140156, -0.817817, -0.718584, 0.140156, -0.681171, -0.846154, 0.140156, -0.514178, -0.933884, 0.140157, -0.328963, -0.980356, 0.140157, -0.138773, -0.989006, 0.140157, 0.045576, -0.961814, 0.140156, 0.233697, -0.894675, 0.140156, 0.423012, -0.786379, 0.140156, 0.600772, -0.641169, 0.140156, 0.753920, -0.468479, 0.140156, 0.871973, -0.280982, 0.140156, 0.949305, -0.091735, 0.140157, 0.985857, 0.091880, 0.140157, 0.985857, 0.281381, 0.140156, 0.949305, 0.469061, 0.140156, 0.871974, 0.641841, 0.140156, 0.753921, 0.787038, 0.140156, 0.600772, 0.895219, 0.140156, 0.423013, 0.962155, 0.140156, 0.233698, 0.989080, 0.140156, 0.045577, 0.980429, 0.138645, -0.138772, 0.934302, 0.137913, -0.328961, 0.847222, 0.138921, -0.514176, 0.720597, 0.141793, -0.681169, 0.561353, 0.146414, -0.817815, 0.380791, 0.152435, -0.915858, 0.192060, 0.159359, -0.972482, 0.007337, 0.166654, -0.990129, 0, 0.236027, -0.971747, -0.182646, 0.236027, -0.954427, -0.369256, 0.236027, -0.898856, -0.547788, 0.236027, -0.802633, -0.705242, 0.236027, -0.668524, -0.830444, 0.236027, -0.504632, -0.916546, 0.236027, -0.322855, -0.962155, 0.236027, -0.136197, -0.970599, 0.236027, 0.044730, -0.943747, 0.236027, 0.229358, -0.877731, 0.236027, 0.415158, -0.771374, 0.236027, 0.589618, -0.628852, 0.236027, 0.739923, -0.459425, 0.236027, 0.855784, -0.275521, 0.236027, 0.931681, -0.089943, 0.236027, 0.967554, 0.090174, 0.236027, 0.967554, 0.276157, 0.236027, 0.931681, 0.460352, 0.236027, 0.855785, 0.629924, 0.236027, 0.739923, 0.772426, 0.236027, 0.589618, 0.878598, 0.236027, 0.415159, 0.944291, 0.236027, 0.229359, 0.970717, 0.236027, 0.044731, 0.962271, 0.233616, -0.136195, 0.917211, 0.232449, -0.322853, 0.832146, 0.234057, -0.504630, 0.708452, 0.238637, -0.668523, 0.552893, 0.246005, -0.802632, 0.376511, 0.255607, -0.898855, 0.192147, 0.266649, -0.954427, 0.011699, 0.278284, -0.971747, 0, 0.332242, -0.943194, -0.177279, 0.332242, -0.926384, -0.358407, 0.332242, -0.872445, -0.531693, 0.332242, -0.779050, -0.684521, 0.332242, -0.648881, -0.806044, 0.332242, -0.489805, -0.889615, 0.332242, -0.313369, -0.933884, 0.332242, -0.132195, -0.942038, 0.332242, 0.043416, -0.915824, 0.332242, 0.222619, -0.851633, 0.332242, 0.402960, -0.748336, 0.332242, 0.572293, -0.609994, 0.332242, 0.718182, -0.445596, 0.332242, 0.830639, -0.267199, 0.332242, 0.904306, -0.087218, 0.332242, 0.939124, 0.087525, 0.332242, 0.939124, 0.268043, 0.332242, 0.904306, 0.446826, 0.332242, 0.830639, 0.611416, 0.332242, 0.718183, 0.749730, 0.332242, 0.572294, 0.852783, 0.332242, 0.402961, 0.916546, 0.332242, 0.222620, 0.942195, 0.332242, 0.043417, 0.934038, 0.329046, -0.132193, 0.890497, 0.327499, -0.313367, 0.808300, 0.329630, -0.489803, 0.688775, 0.335702, -0.648880, 0.538460, 0.345470, -0.779048, 0.368022, 0.358199, -0.872444, 0.189873, 0.372837, -0.926384, 0.015508, 0.388261, -0.943194, 0, 0.427228, -0.904144, -0.169940, 0.427228, -0.888030, -0.343568, 0.427228, -0.836324, -0.509679, 0.427228, -0.746795, -0.656180, 0.427228, -0.622016, -0.772672, 0.427228, -0.469526, -0.852783, 0.427228, -0.300395, -0.895219, 0.427228, -0.126722, -0.902998, 0.427228, 0.041618, -0.877731, 0.427228, 0.213402, -0.816092, 0.427228, 0.386276, -0.717012, 0.427228, 0.548599, -0.584391, 0.427228, 0.688448, -0.426847, 0.427228, 0.796249, -0.255930, 0.427228, 0.866865, -0.083532, 0.427228, 0.900243, 0.083901, 0.427228, 0.900243, 0.256945, 0.427228, 0.866865, 0.428326, 0.427228, 0.796249, 0.586102, 0.427228, 0.688448, 0.718689, 0.427228, 0.548600, 0.817475, 0.427228, 0.386277, 0.878598, 0.427228, 0.213403, 0.903185, 0.427228, 0.041619, 0.895404, 0.423384, -0.126720, 0.853843, 0.421523, -0.300393, 0.775385, 0.424086, -0.469524, 0.661297, 0.431392, -0.622015, 0.517820, 0.443143, -0.746794, 0.355136, 0.458457, -0.836323, 0.185090, 0.476067, -0.888029, 0.018657, 0.494624, -0.904144, 0, 0.519304, -0.854590, -0.160626, 0.519304, -0.839359, -0.324738, 0.519304, -0.790487, -0.481745, 0.519304, -0.705865, -0.620216, 0.519304, -0.587925, -0.730324, 0.519304, -0.443792, -0.806044, 0.519304, -0.283931, -0.846155, 0.519304, -0.119776, -0.853472, 0.519304, 0.039337, -0.829465, 0.519304, 0.201706, -0.771110, 0.519304, 0.365105, -0.677407, 0.519304, 0.518532, -0.552048, 0.519304, 0.650715, -0.403181, 0.519304, 0.752608, -0.241718, 0.519304, 0.819354, -0.078886, 0.519304, 0.850902, 0.079303, 0.519304, 0.850902, 0.242862, 0.519304, 0.819354, 0.404851, 0.519304, 0.752608, 0.553979, 0.519304, 0.650716, 0.679300, 0.519304, 0.518532, 0.772672, 0.519304, 0.365106, 0.830444, 0.519304, 0.201707, 0.853684, 0.519304, 0.039338, 0.846362, 0.514966, -0.119775, 0.807240, 0.512866, -0.283929, 0.733385, 0.515759, -0.443790, 0.625990, 0.524001, -0.587923, 0.490930, 0.537261, -0.705864, 0.337790, 0.554540, -0.790486, 0.177720, 0.574410, -0.839358, 0.021050, 0.595347, -0.854590, 0, 0.606760, -0.794885, -0.149404, 0.606760, -0.780718, -0.302050, 0.606760, -0.735260, -0.448089, 0.606760, -0.656551, -0.576886, 0.606760, -0.546850, -0.679300, 0.606760, -0.412787, -0.749731, 0.606760, -0.264094, -0.787039, 0.606760, -0.111408, -0.793815, 0.606760, 0.036589, -0.771375, 0.606760, 0.187614, -0.717012, 0.606760, 0.339598, -0.629808, 0.606760, 0.482305, -0.513202, 0.606760, 0.605254, -0.374772, 0.606760, 0.700028, -0.224665, 0.606760, 0.762111, -0.073314, 0.606760, 0.791455, 0.073762, 0.606760, 0.791455, 0.225895, 0.606760, 0.762111, 0.376566, 0.606760, 0.700028, 0.515276, 0.606760, 0.605255, 0.631841, 0.606760, 0.482306, 0.718690, 0.606760, 0.339598, 0.772426, 0.606760, 0.187615, 0.794042, 0.606760, 0.036590, 0.787262, 0.602101, -0.111407, 0.751016, 0.599845, -0.264093, 0.682589, 0.602952, -0.412786, 0.583088, 0.611806, -0.546849, 0.457955, 0.626050, -0.656550, 0.316071, 0.644612, -0.735260, 0.167766, 0.665956, -0.780717, 0.022612, 0.688448, -0.794885, 0, 0.687961, -0.725748, -0.136409, 0.687961, -0.712813, -0.275779, 0.687961, -0.671309, -0.409115, 0.687961, -0.599446, -0.526709, 0.687961, -0.499286, -0.620216, 0.687961, -0.376884, -0.684521, 0.687961, -0.241124, -0.718584, 0.687961, -0.101718, -0.724744, 0.687961, 0.033407, -0.704159, 0.687961, 0.171296, -0.654452, 0.687961, 0.310060, -0.574791, 0.687961, 0.440355, -0.468322, 0.687961, 0.552611, -0.341966, 0.687961, 0.639141, -0.204980, 0.687961, 0.695825, -0.066885, 0.687961, 0.722616, 0.067347, 0.687961, 0.722616, 0.206247, 0.687961, 0.695825, 0.343814, 0.687961, 0.639142, 0.470458, 0.687961, 0.552611, 0.576885, 0.687961, 0.440356, 0.656180, 0.687961, 0.310061, 0.705243, 0.687961, 0.171297, 0.724978, 0.687961, 0.033408, 0.718814, 0.683161, -0.101717, 0.685844, 0.680838, -0.241123, 0.623604, 0.684038, -0.376883, 0.533098, 0.693159, -0.499285, 0.419277, 0.707830, -0.599444, 0.290220, 0.726949, -0.671308, 0.155323, 0.748935, -0.712813, 0.023291, 0.772102, -0.725748, 0, 0.761436, -0.648241, -0.121841, 0.761436, -0.636687, -0.246326, 0.761436, -0.599616, -0.365423, 0.761436, -0.535427, -0.470459, 0.761436, -0.445965, -0.553980, 0.761436, -0.336634, -0.611417, 0.761436, -0.215373, -0.641842, 0.761436, -0.090855, -0.647321, 0.761436, 0.029839, -0.628853, 0.761436, 0.153002, -0.584391, 0.761436, 0.276947, -0.513202, 0.761436, 0.393327, -0.418100, 0.761436, 0.493594, -0.305266, 0.761436, 0.570884, -0.182966, 0.761436, 0.621513, -0.059697, 0.761436, 0.645444, 0.060154, 0.761436, 0.645444, 0.184221, 0.761436, 0.621513, 0.307096, 0.761436, 0.570884, 0.420215, 0.761436, 0.493594, 0.515276, 0.761436, 0.393327, 0.586102, 0.761436, 0.276948, 0.629925, 0.761436, 0.153003, 0.647554, 0.761436, 0.029840, 0.642070, 0.756683, -0.090854, 0.612727, 0.754382, -0.215372, 0.557334, 0.757551, -0.336633, 0.476785, 0.766583, -0.445963, 0.375486, 0.781111, -0.535426, 0.260627, 0.800044, -0.599615, 0.140570, 0.821815, -0.636687, 0.023064, 0.844757, -0.648241, 0, 0.825969, -0.563716, -0.105954, 0.825969, -0.553669, -0.214208, 0.825969, -0.521431, -0.317775, 0.825969, -0.465612, -0.409115, 0.825969, -0.387815, -0.481746, 0.825969, -0.292740, -0.531693, 0.825969, -0.187290, -0.558151, 0.825969, -0.079008, -0.562897, 0.825969, 0.025948, -0.546768, 0.825969, 0.133052, -0.508052, 0.825969, 0.240835, -0.446116, 0.825969, 0.342041, -0.363411, 0.825969, 0.429233, -0.265312, 0.825969, 0.496445, -0.159007, 0.825969, 0.540473, -0.051876, 0.825969, 0.561283, 0.052311, 0.825969, 0.561283, 0.160200, 0.825969, 0.540473, 0.267053, 0.825969, 0.496445, 0.365423, 0.825969, 0.429234, 0.448089, 0.825969, 0.342041, 0.509680, 0.825969, 0.240836, 0.547789, 0.825969, 0.133053, 0.563118, 0.825969, 0.025949, 0.558368, 0.821448, -0.079008, 0.532940, 0.819259, -0.187289, 0.484936, 0.822274, -0.292739, 0.415132, 0.830865, -0.387814, 0.327347, 0.844685, -0.465611, 0.227810, 0.862693, -0.521431, 0.123769, 0.883402, -0.553669, 0.021938, 0.905224, -0.563716, 0, 0.880666, -0.473738, -0.089042, 0.880666, -0.465295, -0.180017, 0.880666, -0.438203, -0.267053, 0.880666, -0.391293, -0.343814, 0.880666, -0.325914, -0.404852, 0.880666, -0.246014, -0.446827, 0.880666, -0.157396, -0.469062, 0.880666, -0.066398, -0.473035, 0.880666, 0.021806, -0.459425, 0.880666, 0.111815, -0.426847, 0.880666, 0.202395, -0.374773, 0.880666, 0.287446, -0.305266, 0.880666, 0.360722, -0.222844, 0.880666, 0.417205, -0.133545, 0.880666, 0.454206, -0.043566, 0.880666, 0.471694, 0.043961, 0.880666, 0.471694, 0.134630, 0.880666, 0.454206, 0.224427, 0.880666, 0.417206, 0.307096, 0.880666, 0.360722, 0.376567, 0.880666, 0.287446, 0.428327, 0.880666, 0.202395, 0.460354, 0.880666, 0.111816, 0.473236, 0.880666, 0.021807, 0.469259, 0.876554, -0.066397, 0.447961, 0.874564, -0.157395, 0.407753, 0.877305, -0.246013, 0.349287, 0.885118, -0.325913, 0.275759, 0.897687, -0.391293, 0.192388, 0.914065, -0.438203, 0.105244, 0.932899, -0.465295, 0.019952, 0.952745, -0.473738, 0, 0.924989, -0.379993, -0.071422, 0.924989, -0.373221, -0.144395, 0.924989, -0.351490, -0.214208, 0.924989, -0.313863, -0.275779, 0.924989, -0.261421, -0.324738, 0.924989, -0.197332, -0.358408, 0.924989, -0.126250, -0.376243, 0.924989, -0.053259, -0.379418, 0.924989, 0.017491, -0.368459, 0.924989, 0.089689, -0.342295, 0.924989, 0.162344, -0.300507, 0.924989, 0.230565, -0.244752, 0.924989, 0.289341, -0.178655, 0.924989, 0.334647, -0.107055, 0.924989, 0.364326, -0.034922, 0.924989, 0.378354, 0.035262, 0.924989, 0.378354, 0.107989, 0.924989, 0.364326, 0.180017, 0.924989, 0.334647, 0.246327, 0.924989, 0.289341, 0.302051, 0.924989, 0.230565, 0.343568, 0.924989, 0.162344, 0.369257, 0.924989, 0.089689, 0.379591, 0.924989, 0.017492, 0.376412, 0.921451, -0.053258, 0.359383, 0.919738, -0.126249, 0.327235, 0.922097, -0.197331, 0.280488, 0.928821, -0.261420, 0.221699, 0.939637, -0.313862, 0.155040, 0.953731, -0.351490, 0.085365, 0.969939, -0.373221, 0.017170, 0.987017, -0.379993, 0, 0.958769, -0.284187, -0.053415, 0.958769, -0.279122, -0.107989, 0.958769, -0.262870, -0.160201, 0.958769, -0.234730, -0.206248, 0.958769, -0.195510, -0.242863, 0.958769, -0.147580, -0.268044, 0.958769, -0.094419, -0.281382, 0.958769, -0.039831, -0.283748, 0.958769, 0.013081, -0.275522, 0.958769, 0.067076, -0.255931, 0.958769, 0.121413, -0.224666, 0.958769, 0.172434, -0.182967, 0.958769, 0.216390, -0.133545, 0.958769, 0.250274, -0.080018, 0.958769, 0.272470, -0.026101, 0.958769, 0.282961, 0.026371, 0.958769, 0.282961, 0.080762, 0.958769, 0.272470, 0.134630, 0.958769, 0.250274, 0.184221, 0.958769, 0.216391, 0.225896, 0.958769, 0.172434, 0.256946, 0.958769, 0.121413, 0.276158, 0.958769, 0.067076, 0.283886, 0.958769, 0.013082, 0.281517, 0.955950, -0.039830, 0.268821, 0.954586, -0.094418, 0.244853, 0.956465, -0.147579, 0.210000, 0.961821, -0.195509, 0.166168, 0.970437, -0.234730, 0.116470, 0.981665, -0.262870, 0.064522, 0.994577, -0.279122, 0.013678, 1.008182, -0.284187, 0, 0.982177, -0.187958, -0.035328, 0.982177, -0.184608, -0.071422, 0.982177, -0.173859, -0.105955, 0.982177, -0.155247, -0.136410, 0.982177, -0.129308, -0.160627, 0.982177, -0.097607, -0.177281, 0.982177, -0.062447, -0.186102, 0.982177, -0.026344, -0.187662, 0.982177, 0.008652, -0.182202, 0.982177, 0.044363, -0.169230, 0.982177, 0.080301, -0.148543, 0.982177, 0.114045, -0.120963, 0.982177, 0.143118, -0.088283, 0.982177, 0.165528, -0.052894, 0.982177, 0.180208, -0.017252, 0.982177, 0.187147, 0.017442, 0.982177, 0.187147, 0.053415, 0.982177, 0.180208, 0.089042, 0.982177, 0.165528, 0.121842, 0.982177, 0.143118, 0.149405, 0.982177, 0.114045, 0.169941, 0.982177, 0.080301, 0.182647, 0.982177, 0.044363, 0.187758, 0.982177, 0.008652, 0.186197, 0.980203, -0.026343, 0.177825, 0.979248, -0.062447, 0.162020, 0.980564, -0.097607, 0.139037, 0.984315, -0.129307, 0.110133, 0.990348, -0.155247, 0.077361, 0.998211, -0.173859, 0.043106, 1.007252, -0.184608, 0.009578, 1.016780, -0.187958, 0, 0.995685, -0.092798, -0.017442, 0.995685, -0.091144, -0.035262, 0.995685, -0.085837, -0.052311, 0.995685, -0.076648, -0.067348, 0.995685, -0.063841, -0.079304, 0.995685, -0.048190, -0.087526, 0.995685, -0.030831, -0.091882, 0.995685, -0.013006, -0.092649, 0.995685, 0.004272, -0.089944, 0.995685, 0.021903, -0.083533, 0.995685, 0.039646, -0.073315, 0.995685, 0.056306, -0.059698, 0.995685, 0.070659, -0.043566, 0.995685, 0.081724, -0.026101, 0.995685, 0.088971, -0.008513, 0.995685, 0.092397, 0.008611, 0.995685, 0.092397, 0.026372, 0.995685, 0.088971, 0.043962, 0.995685, 0.081724, 0.060155, 0.995685, 0.070659, 0.073763, 0.995685, 0.056306, 0.083902, 0.995685, 0.039646, 0.090176, 0.995685, 0.021903, 0.092699, 0.995685, 0.004272, 0.091931, 0.994658, -0.013006, 0.087809, 0.994162, -0.030831, 0.080028, 0.994846, -0.048190, 0.068714, 0.996797, -0.063841, 0.054485, 0.999935, -0.076648, 0.038351, 1.004024, -0.085837, 0.021487, 1.008726, -0.091144, 0.004981, 1.013681, -0.092798, 0, 1, -0.000001, -0, 1, -0.000001, -0.000001, 1, -0.000001, -0.000001, 1, -0.000001, -0.000001, 1, -0.000001, -0.000001, 1, -0.000001, -0.000001, 1, -0, -0.000001, 1, -0, -0.000001, 1, 0, -0.000001, 1, 0, -0.000001, 1, 0.000001, -0.000001, 1, 0.000001, -0.000001, 1, 0.000001, -0.000001, 1, 0.000001, -0, 1, 0.000001, -0, 1, 0.000001, 0, 1, 0.000001, 0, 1, 0.000001, 0.000001, 1, 0.000001, 0.000001, 1, 0.000001, 0.000001, 1, 0.000001, 0.000001, 1, 0.000001, 0.000001, 1, 0, 0.000001, 1, 0, 0.000001, 1, -0, 0.000001, 1, -0, 0.000001, 1, -0.000001, 0.000001, 1, -0.000001, 0.000001, 1, -0.000001, 0.000001, 1, -0.000001, 0, 1, -0.000001, 0, 1, -0.000001, -0.013192, -0.988931, -0.139125, -0.039863, -0.988931, -0.133861, -0.066237, -0.988931, -0.122897, -0.090505, -0.988931, -0.106260, -0.110921, -0.988931, -0.084736, -0.126183, -0.988931, -0.059768, -0.135696, -0.988931, -0.033157, -0.139609, -0.988931, -0.006607, -0.138319, -0.988931, 0.019797, -0.131665, -0.988931, 0.046553, -0.119252, -0.988931, 0.072574, -0.101290, -0.988931, 0.096031, -0.078750, -0.988931, 0.115256, -0.053197, -0.988931, 0.129107, -0.026460, -0.988931, 0.137180, -0, -0.988931, 0.139771, 0.026460, -0.988931, 0.137180, 0.053197, -0.988931, 0.129107, 0.078749, -0.988931, 0.115256, 0.101290, -0.988931, 0.096031, 0.119252, -0.988931, 0.072574, 0.131665, -0.988931, 0.046553, 0.138319, -0.988931, 0.019797, 0.139609, -0.988931, -0.006606, 0.135697, -0.988931, -0.033157, 0.126183, -0.988931, -0.059768, 0.110921, -0.988931, -0.084735, 0.090505, -0.988931, -0.106260, 0.066237, -0.988931, -0.122896, 0.039864, -0.988931, -0.133860, 0.013193, -0.988931, -0.139125, -0.022186, -0.970473, -0.233968, -0.067038, -0.970473, -0.225114, -0.111391, -0.970473, -0.206676, -0.152202, -0.970473, -0.178698, -0.186536, -0.970473, -0.142500, -0.212203, -0.970473, -0.100513, -0.228201, -0.970473, -0.055760, -0.234781, -0.970473, -0.011110, -0.232611, -0.970473, 0.033293, -0.221422, -0.970473, 0.078288, -0.200546, -0.970473, 0.122048, -0.170340, -0.970473, 0.161496, -0.132433, -0.970473, 0.193827, -0.089462, -0.970473, 0.217119, -0.044497, -0.970473, 0.230695, -0, -0.970473, 0.235053, 0.044497, -0.970473, 0.230695, 0.089462, -0.970473, 0.217119, 0.132433, -0.970473, 0.193827, 0.170340, -0.970473, 0.161496, 0.200546, -0.970473, 0.122048, 0.221422, -0.970473, 0.078288, 0.232611, -0.970473, 0.033293, 0.234781, -0.970473, -0.011110, 0.228201, -0.970473, -0.055759, 0.212203, -0.970473, -0.100512, 0.186536, -0.970473, -0.142500, 0.152203, -0.970473, -0.178697, 0.111392, -0.970473, -0.206675, 0.067039, -0.970473, -0.225114, 0.022186, -0.970473, -0.233968, -0.031209, -0.941879, -0.329130, -0.094305, -0.941879, -0.316675, -0.156698, -0.941879, -0.290737, -0.214108, -0.941879, -0.251380, -0.262406, -0.941879, -0.200460, -0.298512, -0.941879, -0.141395, -0.321018, -0.941879, -0.078439, -0.330274, -0.941879, -0.015629, -0.327222, -0.941879, 0.046834, -0.311481, -0.941879, 0.110130, -0.282114, -0.941879, 0.171688, -0.239623, -0.941879, 0.227182, -0.186298, -0.941879, 0.272662, -0.125849, -0.941879, 0.305428, -0.062596, -0.941879, 0.324527, -0, -0.941879, 0.330656, 0.062596, -0.941879, 0.324527, 0.125849, -0.941879, 0.305428, 0.186298, -0.941879, 0.272662, 0.239623, -0.941879, 0.227182, 0.282114, -0.941879, 0.171689, 0.311481, -0.941879, 0.110130, 0.327222, -0.941879, 0.046835, 0.330274, -0.941879, -0.015629, 0.321018, -0.941879, -0.078439, 0.298513, -0.941879, -0.141394, 0.262407, -0.941879, -0.200459, 0.214109, -0.941879, -0.251380, 0.156698, -0.941879, -0.290737, 0.094306, -0.941879, -0.316675, 0.031210, -0.941879, -0.329130, -0.040116, -0.902828, -0.423061, -0.121219, -0.902828, -0.407051, -0.201418, -0.902828, -0.373711, -0.275213, -0.902828, -0.323122, -0.337295, -0.902828, -0.257670, -0.383705, -0.902828, -0.181748, -0.412634, -0.902828, -0.100825, -0.424532, -0.902828, -0.020090, -0.420609, -0.902828, 0.060200, -0.400376, -0.902828, 0.141560, -0.362628, -0.902828, 0.220687, -0.308010, -0.902828, 0.292018, -0.239466, -0.902828, 0.350478, -0.161766, -0.902828, 0.392595, -0.080460, -0.902828, 0.417144, -0, -0.902828, 0.425023, 0.080460, -0.902828, 0.417144, 0.161765, -0.902828, 0.392595, 0.239466, -0.902828, 0.350478, 0.308009, -0.902828, 0.292018, 0.362628, -0.902828, 0.220687, 0.400376, -0.902828, 0.141561, 0.420608, -0.902828, 0.060201, 0.424532, -0.902828, -0.020089, 0.412634, -0.902828, -0.100824, 0.383706, -0.902828, -0.181747, 0.337296, -0.902828, -0.257669, 0.275214, -0.902828, -0.323121, 0.201419, -0.902828, -0.373711, 0.121220, -0.902828, -0.407051, 0.040117, -0.902828, -0.423061, -0.048749, -0.853318, -0.514104, -0.147305, -0.853318, -0.494649, -0.244763, -0.853318, -0.454134, -0.334439, -0.853318, -0.392658, -0.409881, -0.853318, -0.313120, -0.466279, -0.853318, -0.220860, -0.501433, -0.853318, -0.122523, -0.515891, -0.853318, -0.024413, -0.511123, -0.853318, 0.073155, -0.486537, -0.853318, 0.172024, -0.440665, -0.853318, 0.268179, -0.374293, -0.853318, 0.354860, -0.291000, -0.853318, 0.425901, -0.196577, -0.853318, 0.477082, -0.097775, -0.853318, 0.506913, -0, -0.853318, 0.516488, 0.097775, -0.853318, 0.506913, 0.196577, -0.853318, 0.477082, 0.290999, -0.853318, 0.425901, 0.374293, -0.853318, 0.354860, 0.440665, -0.853318, 0.268179, 0.486537, -0.853318, 0.172025, 0.511123, -0.853318, 0.073156, 0.515891, -0.853318, -0.024412, 0.501433, -0.853318, -0.122522, 0.466279, -0.853318, -0.220859, 0.409882, -0.853318, -0.313119, 0.334440, -0.853318, -0.392657, 0.244764, -0.853318, -0.454134, 0.147306, -0.853318, -0.494648, 0.048750, -0.853318, -0.514104, -0.056949, -0.793703, -0.600577, -0.172082, -0.793703, -0.577850, -0.285933, -0.793703, -0.530521, -0.390693, -0.793703, -0.458704, -0.478824, -0.793703, -0.365788, -0.544708, -0.793703, -0.258009, -0.585775, -0.793703, -0.143131, -0.602666, -0.793703, -0.028519, -0.597096, -0.793703, 0.085460, -0.568374, -0.793703, 0.200959, -0.514786, -0.793703, 0.313287, -0.437250, -0.793703, 0.414548, -0.339947, -0.793703, 0.497538, -0.229642, -0.793703, 0.557328, -0.114221, -0.793703, 0.592178, -0, -0.793703, 0.603363, 0.114221, -0.793703, 0.592178, 0.229642, -0.793703, 0.557328, 0.339946, -0.793703, 0.497539, 0.437250, -0.793703, 0.414549, 0.514786, -0.793703, 0.313288, 0.568373, -0.793703, 0.200960, 0.597096, -0.793703, 0.085461, 0.602666, -0.793703, -0.028518, 0.585776, -0.793703, -0.143130, 0.544709, -0.793703, -0.258008, 0.478825, -0.793703, -0.365787, 0.390694, -0.793703, -0.458703, 0.285934, -0.793703, -0.530520, 0.172084, -0.793703, -0.577850, 0.056950, -0.793703, -0.600577, -0.064562, -0.724699, -0.680872, -0.195089, -0.724699, -0.655106, -0.324160, -0.724699, -0.601449, -0.442926, -0.724699, -0.520030, -0.542841, -0.724699, -0.414692, -0.617533, -0.724699, -0.292503, -0.664090, -0.724699, -0.162267, -0.683239, -0.724699, -0.032332, -0.676925, -0.724699, 0.096886, -0.644362, -0.724699, 0.227826, -0.583611, -0.724699, 0.355172, -0.495709, -0.724699, 0.469971, -0.385396, -0.724699, 0.564057, -0.260344, -0.724699, 0.631840, -0.129492, -0.724699, 0.671349, -0, -0.724699, 0.684029, 0.129492, -0.724699, 0.671349, 0.260344, -0.724699, 0.631840, 0.385395, -0.724699, 0.564057, 0.495708, -0.724699, 0.469972, 0.583610, -0.724699, 0.355173, 0.644362, -0.724699, 0.227827, 0.676924, -0.724699, 0.096887, 0.683239, -0.724699, -0.032331, 0.664091, -0.724699, -0.162266, 0.617534, -0.724699, -0.292502, 0.542842, -0.724699, -0.414691, 0.442927, -0.724699, -0.520029, 0.324162, -0.724699, -0.601448, 0.195090, -0.724699, -0.655105, 0.064564, -0.724699, -0.680871, -0.071453, -0.647361, -0.753540, -0.215910, -0.647361, -0.725025, -0.358758, -0.647361, -0.665641, -0.490199, -0.647361, -0.575533, -0.600778, -0.647361, -0.458952, -0.683442, -0.647361, -0.323722, -0.734968, -0.647361, -0.179586, -0.756160, -0.647361, -0.035783, -0.749172, -0.647361, 0.107226, -0.713135, -0.647361, 0.252142, -0.645899, -0.647361, 0.393079, -0.548615, -0.647361, 0.520131, -0.426529, -0.647361, 0.624258, -0.288131, -0.647361, 0.699276, -0.143313, -0.647361, 0.743001, -0, -0.647361, 0.757035, 0.143313, -0.647361, 0.743001, 0.288130, -0.647361, 0.699276, 0.426528, -0.647361, 0.624258, 0.548615, -0.647361, 0.520131, 0.645899, -0.647361, 0.393080, 0.713134, -0.647361, 0.252143, 0.749172, -0.647361, 0.107227, 0.756161, -0.647361, -0.035782, 0.734969, -0.647361, -0.179585, 0.683442, -0.647361, -0.323721, 0.600779, -0.647361, -0.458950, 0.490201, -0.647361, -0.575532, 0.358760, -0.647361, -0.665640, 0.215912, -0.647361, -0.725024, 0.071455, -0.647361, -0.753540, -0.077507, -0.563033, -0.817387, -0.234204, -0.563033, -0.786456, -0.389155, -0.563033, -0.722040, -0.531734, -0.563033, -0.624297, -0.651681, -0.563032, -0.497838, -0.741349, -0.563033, -0.351151, -0.797242, -0.563033, -0.194802, -0.820230, -0.563033, -0.038815, -0.812649, -0.563033, 0.116312, -0.773558, -0.563033, 0.273506, -0.700626, -0.563033, 0.426385, -0.595099, -0.563033, 0.564201, -0.462668, -0.563033, 0.677151, -0.312544, -0.563033, 0.758525, -0.155456, -0.563033, 0.805955, -0, -0.563033, 0.821178, 0.155456, -0.563033, 0.805955, 0.312544, -0.563033, 0.758525, 0.462668, -0.563033, 0.677151, 0.595099, -0.563033, 0.564202, 0.700625, -0.563033, 0.426385, 0.773558, -0.563033, 0.273507, 0.812649, -0.563033, 0.116313, 0.820230, -0.563033, -0.038813, 0.797242, -0.563033, -0.194801, 0.741350, -0.563033, -0.351149, 0.651682, -0.563033, -0.497837, 0.531735, -0.563033, -0.624296, 0.389157, -0.563033, -0.722039, 0.234206, -0.563033, -0.786455, 0.077510, -0.563033, -0.817387, -0.082641, -0.473266, -0.871530, -0.249718, -0.473266, -0.838549, -0.414932, -0.473266, -0.769867, -0.566955, -0.473266, -0.665650, -0.694848, -0.473266, -0.530815, -0.790455, -0.473266, -0.374411, -0.850050, -0.473266, -0.207706, -0.874561, -0.473266, -0.041386, -0.866478, -0.473266, 0.124016, -0.824798, -0.473266, 0.291622, -0.747034, -0.473266, 0.454628, -0.634518, -0.473266, 0.601573, -0.493315, -0.473266, 0.722005, -0.333246, -0.473266, 0.808769, -0.165753, -0.473266, 0.859341, -0, -0.473266, 0.875572, 0.165753, -0.473266, 0.859341, 0.333246, -0.473266, 0.808769, 0.493314, -0.473266, 0.722005, 0.634517, -0.473266, 0.601574, 0.747034, -0.473266, 0.454629, 0.824797, -0.473266, 0.291623, 0.866478, -0.473266, 0.124017, 0.874561, -0.473266, -0.041384, 0.850050, -0.473266, -0.207704, 0.790456, -0.473266, -0.374409, 0.694849, -0.473266, -0.530813, 0.566957, -0.473266, -0.665649, 0.414934, -0.473266, -0.769866, 0.249720, -0.473266, -0.838549, 0.082644, -0.473266, -0.871530, -0.086805, -0.379735, -0.915438, -0.262298, -0.379735, -0.880795, -0.435837, -0.379735, -0.808653, -0.595518, -0.379735, -0.699185, -0.729854, -0.379735, -0.557557, -0.830278, -0.379735, -0.393273, -0.892875, -0.379735, -0.218170, -0.918621, -0.379735, -0.043471, -0.910131, -0.379735, 0.130264, -0.866351, -0.379735, 0.306314, -0.784670, -0.379735, 0.477532, -0.666485, -0.379735, 0.631880, -0.518168, -0.379735, 0.758379, -0.350035, -0.379735, 0.849515, -0.174104, -0.379735, 0.902634, -0, -0.379735, 0.919683, 0.174103, -0.379735, 0.902634, 0.350035, -0.379735, 0.849515, 0.518167, -0.379735, 0.758380, 0.666484, -0.379735, 0.631881, 0.784669, -0.379735, 0.477533, 0.866350, -0.379735, 0.306315, 0.910131, -0.379735, 0.130265, 0.918621, -0.379735, -0.043469, 0.892876, -0.379735, -0.218168, 0.830279, -0.379735, -0.393272, 0.729855, -0.379735, -0.557555, 0.595520, -0.379735, -0.699184, 0.435839, -0.379735, -0.808652, 0.262301, -0.379735, -0.880795, 0.086807, -0.379735, -0.915438, -0.089981, -0.284134, -0.948938, -0.271897, -0.284134, -0.913028, -0.451786, -0.284134, -0.838246, -0.617311, -0.284134, -0.724772, -0.756563, -0.284134, -0.577960, -0.860662, -0.284134, -0.407665, -0.925550, -0.284134, -0.226154, -0.952237, -0.284134, -0.045062, -0.943437, -0.284134, 0.135031, -0.898055, -0.284134, 0.317524, -0.813385, -0.284134, 0.495007, -0.690875, -0.284134, 0.655004, -0.537130, -0.284134, 0.786132, -0.362845, -0.284134, 0.880602, -0.180475, -0.284134, 0.935666, -0, -0.284134, 0.953339, 0.180475, -0.284134, 0.935666, 0.362844, -0.284134, 0.880602, 0.537130, -0.284134, 0.786132, 0.690874, -0.284134, 0.655005, 0.813384, -0.284134, 0.495008, 0.898054, -0.284134, 0.317525, 0.943437, -0.284134, 0.135032, 0.952238, -0.284134, -0.045060, 0.925550, -0.284134, -0.226152, 0.860663, -0.284134, -0.407663, 0.756564, -0.284134, -0.577959, 0.617313, -0.284134, -0.724770, 0.451788, -0.284134, -0.838245, 0.271900, -0.284134, -0.913027, 0.089984, -0.284134, -0.948938, -0.092187, -0.188092, -0.972196, -0.278561, -0.188092, -0.935406, -0.462859, -0.188092, -0.858791, -0.632441, -0.188092, -0.742536, -0.775106, -0.188092, -0.592126, -0.881757, -0.188092, -0.417657, -0.948235, -0.188092, -0.231697, -0.975577, -0.188092, -0.046166, -0.966561, -0.188092, 0.138340, -0.920066, -0.188092, 0.325306, -0.833321, -0.188092, 0.507140, -0.707808, -0.188092, 0.671058, -0.550295, -0.188092, 0.805400, -0.371738, -0.188092, 0.902186, -0.184898, -0.188092, 0.958599, -0, -0.188092, 0.976705, 0.184898, -0.188092, 0.958599, 0.371738, -0.188092, 0.902186, 0.550295, -0.188092, 0.805400, 0.707807, -0.188092, 0.671059, 0.833320, -0.188092, 0.507141, 0.920066, -0.188092, 0.325307, 0.966560, -0.188092, 0.138342, 0.975577, -0.188092, -0.046165, 0.948236, -0.188092, -0.231695, 0.881758, -0.188092, -0.417655, 0.775108, -0.188092, -0.592125, 0.632443, -0.188092, -0.742535, 0.462861, -0.188092, -0.858790, 0.278564, -0.188092, -0.935406, 0.092189, -0.188092, -0.972196, -0.093465, -0.093094, -0.985672, -0.282422, -0.093094, -0.948372, -0.469275, -0.093094, -0.870695, -0.641207, -0.093094, -0.752828, -0.785850, -0.093094, -0.600334, -0.893979, -0.093094, -0.423446, -0.961379, -0.093094, -0.234908, -0.989099, -0.093094, -0.046806, -0.979958, -0.093094, 0.140258, -0.932819, -0.093094, 0.329815, -0.844871, -0.093094, 0.514169, -0.717619, -0.093094, 0.680360, -0.557923, -0.093094, 0.816564, -0.376891, -0.093094, 0.914691, -0.187461, -0.093094, 0.971886, -0, -0.093094, 0.990243, 0.187461, -0.093094, 0.971886, 0.376890, -0.093094, 0.914691, 0.557922, -0.093094, 0.816564, 0.717618, -0.093094, 0.680360, 0.844871, -0.093094, 0.514170, 0.932819, -0.093094, 0.329816, 0.979958, -0.093094, 0.140259, 0.989099, -0.093094, -0.046804, 0.961379, -0.093094, -0.234907, 0.893980, -0.093094, -0.423444, 0.785851, -0.093094, -0.600332, 0.641209, -0.093094, -0.752827, 0.469277, -0.093094, -0.870694, 0.282425, -0.093094, -0.948371, 0.093467, -0.093094, -0.985672, -0.093879, -0, -0.990038, -0.283673, -0, -0.952573, -0.471354, -0, -0.874552, -0.644048, -0, -0.756163, -0.789331, -0, -0.602993, -0.897939, -0, -0.425322, -0.965637, -0, -0.235949, -0.993474, -0, -0.047013, -0.984263, -0, 0.140879, -0.936875, -0, 0.331276, -0.848510, -0, 0.516447, -0.720683, -0, 0.683373, -0.560286, -0, 0.820181, -0.378476, -0, 0.918743, -0.188245, -0, 0.976191, 0.000012, -0, 0.994630, 0.188291, -0, 0.976191, 0.378560, -0, 0.918743, 0.560394, -0, 0.820181, 0.720797, -0, 0.683374, 0.848613, -0, 0.516448, 0.936951, -0, 0.331277, 0.984299, -0, 0.140880, 0.993487, -0.000130, -0.047012, 0.965680, -0.000324, -0.235947, 0.898068, -0.000300, -0.425320, 0.789598, 0.000035, -0.602991, 0.644499, 0.000681, -0.756161, 0.472024, 0.001599, -0.874550, 0.284582, 0.002716, -0.952572, 0.095028, 0.003944, -0.990038, -0.093465, 0.093093, -0.985672, -0.282422, 0.093093, -0.948372, -0.469275, 0.093093, -0.870695, -0.641207, 0.093093, -0.752828, -0.785850, 0.093093, -0.600334, -0.893979, 0.093093, -0.423446, -0.961379, 0.093093, -0.234908, -0.989074, 0.093093, -0.046806, -0.979818, 0.093093, 0.140258, -0.932521, 0.093093, 0.329815, -0.844466, 0.093093, 0.514169, -0.717171, 0.093093, 0.680360, -0.557501, 0.093093, 0.816564, -0.376561, 0.093093, 0.914691, -0.187278, 0.093093, 0.971886, 0.000049, 0.093093, 0.990243, 0.187461, 0.093093, 0.971886, 0.376890, 0.093093, 0.914691, 0.557922, 0.093093, 0.816564, 0.717618, 0.093093, 0.680360, 0.844871, 0.093093, 0.514170, 0.932819, 0.093093, 0.329816, 0.979958, 0.093093, 0.140259, 0.989124, 0.092585, -0.046804, 0.961544, 0.091831, -0.234907, 0.894479, 0.091924, -0.423444, 0.786886, 0.093229, -0.600332, 0.642962, 0.095748, -0.752827, 0.471882, 0.099327, -0.870694, 0.285957, 0.103680, -0.948371, 0.097937, 0.108462, -0.985672, -0.092187, 0.188092, -0.972197, -0.278561, 0.188092, -0.935406, -0.462859, 0.188092, -0.858791, -0.632441, 0.188092, -0.742536, -0.775106, 0.188092, -0.592126, -0.881757, 0.188092, -0.417657, -0.948235, 0.188092, -0.231697, -0.975529, 0.188092, -0.046166, -0.966291, 0.188092, 0.138340, -0.919492, 0.188092, 0.325306, -0.832540, 0.188092, 0.507140, -0.706944, 0.188092, 0.671058, -0.549481, 0.188092, 0.805400, -0.371102, 0.188092, 0.902186, -0.184545, 0.188092, 0.958599, 0.000094, 0.188092, 0.976705, 0.184898, 0.188092, 0.958599, 0.371738, 0.188092, 0.902186, 0.550295, 0.188092, 0.805400, 0.707807, 0.188092, 0.671059, 0.833320, 0.188092, 0.507141, 0.920066, 0.188092, 0.325307, 0.966560, 0.188092, 0.138342, 0.975624, 0.187111, -0.046165, 0.948553, 0.185656, -0.231695, 0.882720, 0.185835, -0.417655, 0.777104, 0.188352, -0.592125, 0.635824, 0.193212, -0.742535, 0.467887, 0.200115, -0.858790, 0.285377, 0.208512, -0.935406, 0.100811, 0.217737, -0.972196, -0.089981, 0.284134, -0.948938, -0.271897, 0.284134, -0.913028, -0.451786, 0.284134, -0.838246, -0.617311, 0.284134, -0.724772, -0.756563, 0.284134, -0.577961, -0.860662, 0.284134, -0.407665, -0.925550, 0.284134, -0.226154, -0.952169, 0.284134, -0.045062, -0.943052, 0.284134, 0.135031, -0.897234, 0.284134, 0.317524, -0.812268, 0.284134, 0.495007, -0.689639, 0.284134, 0.655004, -0.535967, 0.284134, 0.786132, -0.361935, 0.284134, 0.880602, -0.179970, 0.284134, 0.935666, 0.000135, 0.284134, 0.953339, 0.180475, 0.284134, 0.935666, 0.362844, 0.284134, 0.880603, 0.537130, 0.284134, 0.786132, 0.690874, 0.284134, 0.655005, 0.813384, 0.284134, 0.495008, 0.898054, 0.284134, 0.317525, 0.943437, 0.284134, 0.135032, 0.952305, 0.282733, -0.045060, 0.926004, 0.280653, -0.226152, 0.862038, 0.280909, -0.407663, 0.759418, 0.284506, -0.577959, 0.622145, 0.291454, -0.724770, 0.458971, 0.301321, -0.838245, 0.281638, 0.313323, -0.913027, 0.102307, 0.326508, -0.948938, -0.086805, 0.379735, -0.915438, -0.262298, 0.379735, -0.880796, -0.435837, 0.379735, -0.808653, -0.595518, 0.379735, -0.699185, -0.729854, 0.379735, -0.557557, -0.830279, 0.379735, -0.393273, -0.892876, 0.379735, -0.218170, -0.918535, 0.379735, -0.043471, -0.909648, 0.379735, 0.130264, -0.865320, 0.379735, 0.306314, -0.783268, 0.379735, 0.477532, -0.664933, 0.379735, 0.631881, -0.516707, 0.379735, 0.758379, -0.348893, 0.379735, 0.849515, -0.173470, 0.379735, 0.902634, 0.000169, 0.379735, 0.919684, 0.174103, 0.379735, 0.902634, 0.350035, 0.379735, 0.849515, 0.518167, 0.379735, 0.758380, 0.666484, 0.379735, 0.631881, 0.784669, 0.379735, 0.477533, 0.866350, 0.379735, 0.306315, 0.910131, 0.379735, 0.130265, 0.918705, 0.377975, -0.043469, 0.893445, 0.375363, -0.218168, 0.832006, 0.375685, -0.393272, 0.733439, 0.380203, -0.557555, 0.601588, 0.388927, -0.699184, 0.444859, 0.401317, -0.808652, 0.274530, 0.416390, -0.880795, 0.102282, 0.432947, -0.915438, -0.082641, 0.473266, -0.871531, -0.249718, 0.473266, -0.838550, -0.414932, 0.473266, -0.769868, -0.566955, 0.473266, -0.665650, -0.694848, 0.473266, -0.530815, -0.790456, 0.473266, -0.374411, -0.850050, 0.473266, -0.207706, -0.874461, 0.473266, -0.041386, -0.865916, 0.473266, 0.124016, -0.823599, 0.473266, 0.291622, -0.745405, 0.473266, 0.454628, -0.632715, 0.473266, 0.601573, -0.491617, 0.473266, 0.722005, -0.331919, 0.473266, 0.808769, -0.165016, 0.473266, 0.859341, 0.000197, 0.473266, 0.875572, 0.165753, 0.473266, 0.859341, 0.333246, 0.473266, 0.808769, 0.493314, 0.473266, 0.722005, 0.634517, 0.473266, 0.601574, 0.747034, 0.473266, 0.454629, 0.824797, 0.473266, 0.291623, 0.866478, 0.473266, 0.124017, 0.874659, 0.471220, -0.041384, 0.850712, 0.468185, -0.207704, 0.792464, 0.468558, -0.374409, 0.699014, 0.473809, -0.530813, 0.574009, 0.483949, -0.665649, 0.425419, 0.498350, -0.769867, 0.263934, 0.515868, -0.838549, 0.100629, 0.535112, -0.871530, -0.077507, 0.563032, -0.817388, -0.234204, 0.563032, -0.786456, -0.389155, 0.563032, -0.722041, -0.531734, 0.563032, -0.624298, -0.651681, 0.563032, -0.497838, -0.741350, 0.563032, -0.351151, -0.797242, 0.563032, -0.194802, -0.820120, 0.563032, -0.038815, -0.812032, 0.563032, 0.116312, -0.772241, 0.563032, 0.273506, -0.698834, 0.563032, 0.426385, -0.593116, 0.563032, 0.564201, -0.460801, 0.563032, 0.677151, -0.311084, 0.563032, 0.758525, -0.154646, 0.563032, 0.805956, 0.000216, 0.563032, 0.821179, 0.155456, 0.563032, 0.805956, 0.312544, 0.563032, 0.758526, 0.462668, 0.563032, 0.677152, 0.595099, 0.563032, 0.564202, 0.700626, 0.563032, 0.426386, 0.773558, 0.563032, 0.273507, 0.812649, 0.563032, 0.116313, 0.820338, 0.560783, -0.038813, 0.797970, 0.557444, -0.194801, 0.743557, 0.557855, -0.351149, 0.656263, 0.563630, -0.497837, 0.539491, 0.574780, -0.624296, 0.400686, 0.590616, -0.722040, 0.249837, 0.609879, -0.786455, 0.097287, 0.631040, -0.817388, -0.071453, 0.647361, -0.753541, -0.215910, 0.647361, -0.725025, -0.358758, 0.647361, -0.665641, -0.490200, 0.647361, -0.575533, -0.600778, 0.647361, -0.458952, -0.683442, 0.647361, -0.323722, -0.734969, 0.647361, -0.179586, -0.756046, 0.647361, -0.035783, -0.748523, 0.647361, 0.107226, -0.711750, 0.647361, 0.252142, -0.644016, 0.647361, 0.393080, -0.546531, 0.647361, 0.520131, -0.424566, 0.647361, 0.624259, -0.286596, 0.647361, 0.699276, -0.142461, 0.647361, 0.743002, 0.000227, 0.647361, 0.757036, 0.143313, 0.647361, 0.743002, 0.288131, 0.647361, 0.699277, 0.426529, 0.647361, 0.624259, 0.548615, 0.647361, 0.520132, 0.645899, 0.647361, 0.393080, 0.713135, 0.647361, 0.252143, 0.749172, 0.647361, 0.107227, 0.756274, 0.644996, -0.035782, 0.735734, 0.641486, -0.179585, 0.685763, 0.641918, -0.323721, 0.605595, 0.647989, -0.458951, 0.498354, 0.659711, -0.575532, 0.370881, 0.676361, -0.665640, 0.232345, 0.696613, -0.725025, 0.092248, 0.718860, -0.753541, -0.064562, 0.724698, -0.680872, -0.195089, 0.724698, -0.655106, -0.324161, 0.724698, -0.601449, -0.442927, 0.724698, -0.520031, -0.542841, 0.724698, -0.414692, -0.617534, 0.724698, -0.292504, -0.664091, 0.724698, -0.162268, -0.683123, 0.724698, -0.032332, -0.676269, 0.724698, 0.096886, -0.642964, 0.724698, 0.227826, -0.581709, 0.724698, 0.355172, -0.493604, 0.724698, 0.469972, -0.383413, 0.724698, 0.564057, -0.258795, 0.724698, 0.631841, -0.128632, 0.724698, 0.671349, 0.000230, 0.724698, 0.684030, 0.129492, 0.724698, 0.671349, 0.260344, 0.724698, 0.631841, 0.385396, 0.724698, 0.564058, 0.495709, 0.724698, 0.469972, 0.583611, 0.724698, 0.355173, 0.644363, 0.724698, 0.227827, 0.676925, 0.724698, 0.096887, 0.683354, 0.722310, -0.032331, 0.664864, 0.718766, -0.162266, 0.619877, 0.719202, -0.292502, 0.547705, 0.725333, -0.414691, 0.451161, 0.737171, -0.520030, 0.336403, 0.753984, -0.601449, 0.211685, 0.774436, -0.655106, 0.085562, 0.796902, -0.680872, -0.056949, 0.793702, -0.600578, -0.172082, 0.793702, -0.577851, -0.285933, 0.793702, -0.530521, -0.390693, 0.793702, -0.458705, -0.478825, 0.793702, -0.365788, -0.544709, 0.793702, -0.258009, -0.585776, 0.793702, -0.143132, -0.602553, 0.793702, -0.028519, -0.596460, 0.793702, 0.085460, -0.567016, 0.793702, 0.200959, -0.512940, 0.793702, 0.313287, -0.435207, 0.793702, 0.414549, -0.338022, 0.793702, 0.497539, -0.228138, 0.793702, 0.557329, -0.113387, 0.793702, 0.592178, 0.000223, 0.793702, 0.603364, 0.114221, 0.793702, 0.592178, 0.229642, 0.793702, 0.557329, 0.339947, 0.793702, 0.497539, 0.437251, 0.793702, 0.414549, 0.514787, 0.793702, 0.313288, 0.568374, 0.793702, 0.200960, 0.597096, 0.793702, 0.085461, 0.602777, 0.791384, -0.028518, 0.586526, 0.787943, -0.143131, 0.546984, 0.788367, -0.258008, 0.483547, 0.794318, -0.365787, 0.398687, 0.805811, -0.458704, 0.297817, 0.822133, -0.530521, 0.188194, 0.841989, -0.577850, 0.077336, 0.863800, -0.600578, -0.048749, 0.853317, -0.514105, -0.147305, 0.853317, -0.494650, -0.244763, 0.853317, -0.454135, -0.334439, 0.853317, -0.392658, -0.409882, 0.853317, -0.313121, -0.466280, 0.853317, -0.220860, -0.501434, 0.853317, -0.122523, -0.515787, 0.853317, -0.024413, -0.510532, 0.853317, 0.073155, -0.485273, 0.853317, 0.172024, -0.438947, 0.853317, 0.268179, -0.372391, 0.853317, 0.354860, -0.289208, 0.853317, 0.425901, -0.195177, 0.853317, 0.477082, -0.096998, 0.853317, 0.506914, 0.000207, 0.853317, 0.516489, 0.097775, 0.853317, 0.506914, 0.196578, 0.853317, 0.477083, 0.291000, 0.853317, 0.425902, 0.374294, 0.853317, 0.354861, 0.440666, 0.853317, 0.268180, 0.486537, 0.853317, 0.172025, 0.511124, 0.853317, 0.073156, 0.515996, 0.851159, -0.024412, 0.502132, 0.847956, -0.122522, 0.468398, 0.848351, -0.220859, 0.414277, 0.853891, -0.313120, 0.341881, 0.864589, -0.392658, 0.255826, 0.879783, -0.454134, 0.162303, 0.898265, -0.494649, 0.067726, 0.918568, -0.514104, -0.040116, 0.902827, -0.423062, -0.121219, 0.902827, -0.407052, -0.201418, 0.902827, -0.373712, -0.275214, 0.902827, -0.323123, -0.337296, 0.902827, -0.257670, -0.383706, 0.902827, -0.181748, -0.412635, 0.902827, -0.100825, -0.424440, 0.902827, -0.020090, -0.420084, 0.902827, 0.060200, -0.399256, 0.902827, 0.141561, -0.361105, 0.902827, 0.220687, -0.306324, 0.902827, 0.292018, -0.237879, 0.902827, 0.350479, -0.160525, 0.902827, 0.392596, -0.079772, 0.902827, 0.417145, 0.000184, 0.902827, 0.425024, 0.080460, 0.902827, 0.417145, 0.161766, 0.902827, 0.392596, 0.239467, 0.902827, 0.350479, 0.308010, 0.902827, 0.292019, 0.362628, 0.902827, 0.220688, 0.400377, 0.902827, 0.141561, 0.420609, 0.902827, 0.060201, 0.424625, 0.900915, -0.020089, 0.413254, 0.898077, -0.100825, 0.385583, 0.898426, -0.181747, 0.341191, 0.903336, -0.257670, 0.281808, 0.912816, -0.323122, 0.211221, 0.926280, -0.373712, 0.134509, 0.942659, -0.407052, 0.056933, 0.960650, -0.423062, -0.031209, 0.941879, -0.329131, -0.094305, 0.941879, -0.316676, -0.156698, 0.941879, -0.290738, -0.214109, 0.941879, -0.251381, -0.262407, 0.941879, -0.200461, -0.298513, 0.941879, -0.141395, -0.321019, 0.941879, -0.078440, -0.330198, 0.941879, -0.015629, -0.326787, 0.941879, 0.046834, -0.310552, 0.941879, 0.110130, -0.280850, 0.941879, 0.171689, -0.238223, 0.941879, 0.227182, -0.184980, 0.941879, 0.272663, -0.124818, 0.941879, 0.305429, -0.062024, 0.941879, 0.324528, 0.000153, 0.941879, 0.330657, 0.062596, 0.941879, 0.324528, 0.125849, 0.941879, 0.305429, 0.186299, 0.941879, 0.272663, 0.239624, 0.941879, 0.227183, 0.282115, 0.941879, 0.171689, 0.311482, 0.941879, 0.110131, 0.327223, 0.941879, 0.046835, 0.330352, 0.940290, -0.015629, 0.321533, 0.937931, -0.078439, 0.300073, 0.938222, -0.141395, 0.265644, 0.942301, -0.200460, 0.219589, 0.950179, -0.251380, 0.164844, 0.961368, -0.290738, 0.105349, 0.974978, -0.316676, 0.045184, 0.989929, -0.329131, -0.022186, 0.970473, -0.233969, -0.067039, 0.970473, -0.225115, -0.111392, 0.970473, -0.206677, -0.152203, 0.970473, -0.178699, -0.186537, 0.970473, -0.142501, -0.212204, 0.970473, -0.100513, -0.228202, 0.970473, -0.055760, -0.234724, 0.970473, -0.011110, -0.232283, 0.970473, 0.033293, -0.220721, 0.970473, 0.078288, -0.199593, 0.970473, 0.122048, -0.169285, 0.970473, 0.161497, -0.131439, 0.970473, 0.193828, -0.088685, 0.970473, 0.217120, -0.044066, 0.970473, 0.230696, 0.000115, 0.970473, 0.235054, 0.044498, 0.970473, 0.230696, 0.089462, 0.970473, 0.217120, 0.132434, 0.970473, 0.193828, 0.170341, 0.970473, 0.161497, 0.200547, 0.970473, 0.122048, 0.221423, 0.970473, 0.078288, 0.232612, 0.970473, 0.033293, 0.234840, 0.969275, -0.011110, 0.228590, 0.967497, -0.055760, 0.213379, 0.967716, -0.100513, 0.188977, 0.970791, -0.142501, 0.156334, 0.976730, -0.178698, 0.117533, 0.985165, -0.206676, 0.075365, 0.995426, -0.225115, 0.032721, 1.006698, -0.233969, -0.013192, 0.988931, -0.139127, -0.039864, 0.988931, -0.133862, -0.066238, 0.988931, -0.122898, -0.090506, 0.988931, -0.106261, -0.110922, 0.988931, -0.084737, -0.126184, 0.988931, -0.059769, -0.135698, 0.988931, -0.033157, -0.139574, 0.988931, -0.006607, -0.138114, 0.988931, 0.019797, -0.131227, 0.988931, 0.046553, -0.118655, 0.988931, 0.072574, -0.100630, 0.988931, 0.096032, -0.078128, 0.988931, 0.115257, -0.052711, 0.988931, 0.129108, -0.026190, 0.988931, 0.137181, 0.000072, 0.988931, 0.139772, 0.026460, 0.988931, 0.137181, 0.053198, 0.988931, 0.129108, 0.078750, 0.988931, 0.115257, 0.101291, 0.988931, 0.096032, 0.119253, 0.988931, 0.072575, 0.131666, 0.988931, 0.046553, 0.138320, 0.988931, 0.019797, 0.139646, 0.988181, -0.006606, 0.135940, 0.987068, -0.033157, 0.126920, 0.987205, -0.059769, 0.112450, 0.989130, -0.084736, 0.093092, 0.992849, -0.106261, 0.070083, 0.998129, -0.122898, 0.045076, 1.004553, -0.133862, 0.019788, 1.011610, -0.139127 };
    Coordinate1.point = m_point;
    Coordinate1.point_length = sizeof(m_point) / sizeof(float);
    }
    Normal1.m_parent = (X3dNode *)&NurbsSurface1;
    {
    static float m_vector[] = { -0.004411, -0.998911, -0.046447, -0.013321, -0.998910, -0.044742, -0.022161, -0.998909, -0.041111, -0.030290, -0.998908, -0.035563, -0.037118, -0.998908, -0.028359, -0.042205, -0.998909, -0.019988, -0.045341, -0.998910, -0.011086, -0.046599, -0.998911, -0.002202, -0.046193, -0.998911, 0.006611, -0.044018, -0.998910, 0.015563, -0.039899, -0.998909, 0.024281, -0.033900, -0.998908, 0.032140, -0.026349, -0.998908, 0.038569, -0.017795, -0.998909, 0.043170, -0.008839, -0.998910, 0.045825, 0, -0.998911, 0.046649, 0.008839, -0.998910, 0.045825, 0.017795, -0.998909, 0.043170, 0.026349, -0.998908, 0.038569, 0.033900, -0.998908, 0.032140, 0.039899, -0.998909, 0.024281, 0.044018, -0.998909, 0.015564, 0.046193, -0.998911, 0.006611, 0.046599, -0.998911, -0.002205, 0.045342, -0.998910, -0.011082, 0.042205, -0.998909, -0.019988, 0.037118, -0.998908, -0.028359, 0.030292, -0.998908, -0.035560, 0.022158, -0.998909, -0.041112, 0.013321, -0.998910, -0.044742, 0.004411, -0.998911, -0.046447, 0.004411, -0.998911, -0.046447, 0, -0.995685, -0.092796, -0.017442, -0.995685, -0.091142, -0.035262, -0.995685, -0.085836, -0.052311, -0.995685, -0.076647, -0.067347, -0.995685, -0.063840, -0.079303, -0.995685, -0.048190, -0.087525, -0.995685, -0.030831, -0.091880, -0.995685, -0.013006, -0.092698, -0.995685, 0.004271, -0.090174, -0.995685, 0.021902, -0.083901, -0.995685, 0.039645, -0.073762, -0.995685, 0.056305, -0.060154, -0.995685, 0.070658, -0.043961, -0.995685, 0.081723, -0.026371, -0.995685, 0.088970, -0.008611, -0.995685, 0.092396, 0.008611, -0.995685, 0.092396, 0.026371, -0.995685, 0.088970, 0.043961, -0.995685, 0.081722, 0.060154, -0.995685, 0.070658, 0.073762, -0.995685, 0.056305, 0.083901, -0.995685, 0.039645, 0.090174, -0.995685, 0.021903, 0.092698, -0.995685, 0.004272, 0.091880, -0.995685, -0.013006, 0.087525, -0.995685, -0.030831, 0.079303, -0.995685, -0.048189, 0.067347, -0.995685, -0.063840, 0.052311, -0.995685, -0.076647, 0.035262, -0.995685, -0.085836, 0.017442, -0.995685, -0.091142, -0, -0.995685, -0.092796, 0, -0.982177, -0.187956, -0.035328, -0.982177, -0.184607, -0.071422, -0.982177, -0.173858, -0.105954, -0.982177, -0.155246, -0.136409, -0.982177, -0.129307, -0.160626, -0.982177, -0.097607, -0.177279, -0.982177, -0.062447, -0.186101, -0.982177, -0.026343, -0.187757, -0.982177, 0.008652, -0.182646, -0.982177, 0.044363, -0.169940, -0.982177, 0.080300, -0.149404, -0.982177, 0.114045, -0.121841, -0.982177, 0.143117, -0.089042, -0.982177, 0.165527, -0.053415, -0.982177, 0.180207, -0.017442, -0.982177, 0.187145, 0.017442, -0.982177, 0.187145, 0.053415, -0.982177, 0.180207, 0.089042, -0.982177, 0.165527, 0.121841, -0.982177, 0.143117, 0.149404, -0.982177, 0.114045, 0.169940, -0.982177, 0.080301, 0.182646, -0.982177, 0.044363, 0.187757, -0.982177, 0.008652, 0.186101, -0.982177, -0.026343, 0.177279, -0.982177, -0.062447, 0.160626, -0.982177, -0.097606, 0.136409, -0.982177, -0.129306, 0.105954, -0.982177, -0.155246, 0.071423, -0.982177, -0.173857, 0.035328, -0.982177, -0.184606, 0.000001, -0.982177, -0.187956, -0, -0.958769, -0.284186, -0.053415, -0.958769, -0.279121, -0.107989, -0.958769, -0.262869, -0.160200, -0.958769, -0.234729, -0.206247, -0.958769, -0.195509, -0.242862, -0.958769, -0.147579, -0.268043, -0.958769, -0.094419, -0.281381, -0.958769, -0.039831, -0.283885, -0.958769, 0.013081, -0.276157, -0.958769, 0.067076, -0.256945, -0.958769, 0.121412, -0.225895, -0.958769, 0.172433, -0.184221, -0.958769, 0.216390, -0.134630, -0.958769, 0.250273, -0.080762, -0.958769, 0.272469, -0.026372, -0.958769, 0.282960, 0.026371, -0.958769, 0.282960, 0.080762, -0.958769, 0.272469, 0.134630, -0.958769, 0.250273, 0.184221, -0.958769, 0.216390, 0.225895, -0.958769, 0.172433, 0.256945, -0.958769, 0.121413, 0.276157, -0.958769, 0.067076, 0.283885, -0.958769, 0.013082, 0.281381, -0.958769, -0.039830, 0.268043, -0.958769, -0.094418, 0.242863, -0.958769, -0.147579, 0.206248, -0.958769, -0.195509, 0.160201, -0.958769, -0.234729, 0.107989, -0.958769, -0.262869, 0.053415, -0.958769, -0.279121, 0.000001, -0.958769, -0.284186, -0, -0.924990, -0.379992, -0.071422, -0.924990, -0.373220, -0.144394, -0.924990, -0.351489, -0.214207, -0.924990, -0.313862, -0.275778, -0.924990, -0.261420, -0.324737, -0.924990, -0.197332, -0.358407, -0.924990, -0.126250, -0.376242, -0.924990, -0.053259, -0.379589, -0.924990, 0.017491, -0.369256, -0.924990, 0.089688, -0.343568, -0.924990, 0.162344, -0.302050, -0.924990, 0.230564, -0.246326, -0.924990, 0.289340, -0.180017, -0.924990, 0.334646, -0.107989, -0.924990, 0.364325, -0.035262, -0.924990, 0.378353, 0.035262, -0.924990, 0.378353, 0.107989, -0.924990, 0.364325, 0.180017, -0.924990, 0.334646, 0.246326, -0.924990, 0.289340, 0.302050, -0.924990, 0.230565, 0.343567, -0.924990, 0.162344, 0.369256, -0.924990, 0.089689, 0.379589, -0.924990, 0.017492, 0.376242, -0.924990, -0.053258, 0.358407, -0.924990, -0.126249, 0.324738, -0.924990, -0.197331, 0.275779, -0.924990, -0.261419, 0.214208, -0.924990, -0.313861, 0.144395, -0.924990, -0.351489, 0.071423, -0.924990, -0.373220, 0.000001, -0.924990, -0.379992, -0, -0.880666, -0.473737, -0.089042, -0.880666, -0.465294, -0.180017, -0.880666, -0.438202, -0.267053, -0.880666, -0.391293, -0.343814, -0.880666, -0.325913, -0.404851, -0.880666, -0.246014, -0.446826, -0.880666, -0.157396, -0.469061, -0.880666, -0.066398, -0.473235, -0.880666, 0.021806, -0.460353, -0.880666, 0.111815, -0.428327, -0.880666, 0.202394, -0.376567, -0.880666, 0.287445, -0.307096, -0.880666, 0.360721, -0.224427, -0.880666, 0.417204, -0.134630, -0.880666, 0.454205, -0.043961, -0.880666, 0.471693, 0.043961, -0.880666, 0.471693, 0.134630, -0.880666, 0.454205, 0.224427, -0.880666, 0.417205, 0.307095, -0.880666, 0.360721, 0.376566, -0.880666, 0.287446, 0.428326, -0.880666, 0.202395, 0.460353, -0.880666, 0.111815, 0.473235, -0.880666, 0.021807, 0.469061, -0.880666, -0.066397, 0.446827, -0.880666, -0.157395, 0.404852, -0.880666, -0.246013, 0.343814, -0.880666, -0.325912, 0.267054, -0.880666, -0.391292, 0.180018, -0.880666, -0.438202, 0.089043, -0.880666, -0.465294, 0.000001, -0.880666, -0.473737, -0, -0.825969, -0.563715, -0.105954, -0.825969, -0.553668, -0.214207, -0.825969, -0.521430, -0.317775, -0.825969, -0.465611, -0.409115, -0.825969, -0.387814, -0.481745, -0.825969, -0.292740, -0.531693, -0.825969, -0.187290, -0.558151, -0.825969, -0.079009, -0.563117, -0.825969, 0.025948, -0.547788, -0.825969, 0.133052, -0.509679, -0.825969, 0.240835, -0.448088, -0.825969, 0.342040, -0.365423, -0.825969, 0.429233, -0.267053, -0.825969, 0.496445, -0.160200, -0.825969, 0.540472, -0.052311, -0.825969, 0.561283, 0.052311, -0.825969, 0.561282, 0.160200, -0.825969, 0.540472, 0.267053, -0.825969, 0.496445, 0.365422, -0.825970, 0.429233, 0.448088, -0.825969, 0.342041, 0.509679, -0.825969, 0.240836, 0.547788, -0.825969, 0.133053, 0.563117, -0.825969, 0.025949, 0.558151, -0.825969, -0.079008, 0.531693, -0.825969, -0.187289, 0.481745, -0.825969, -0.292739, 0.409115, -0.825969, -0.387813, 0.317776, -0.825969, -0.465610, 0.214209, -0.825969, -0.521430, 0.105956, -0.825969, -0.553668, 0.000002, -0.825969, -0.563715, -0, -0.761436, -0.648240, -0.121841, -0.761436, -0.636687, -0.246326, -0.761436, -0.599615, -0.365423, -0.761436, -0.535426, -0.470458, -0.761436, -0.445964, -0.553979, -0.761436, -0.336634, -0.611416, -0.761436, -0.215373, -0.641841, -0.761436, -0.090855, -0.647553, -0.761436, 0.029839, -0.629925, -0.761436, 0.153002, -0.586102, -0.761436, 0.276947, -0.515276, -0.761436, 0.393327, -0.420215, -0.761436, 0.493593, -0.307096, -0.761436, 0.570883, -0.184221, -0.761436, 0.621512, -0.060154, -0.761436, 0.645443, 0.060154, -0.761436, 0.645443, 0.184221, -0.761436, 0.621512, 0.307095, -0.761436, 0.570883, 0.420215, -0.761436, 0.493594, 0.515276, -0.761436, 0.393327, 0.586102, -0.761436, 0.276947, 0.629925, -0.761436, 0.153003, 0.647553, -0.761436, 0.029840, 0.641842, -0.761436, -0.090854, 0.611417, -0.761436, -0.215372, 0.553980, -0.761436, -0.336633, 0.470459, -0.761436, -0.445963, 0.365424, -0.761436, -0.535425, 0.246328, -0.761436, -0.599615, 0.121843, -0.761436, -0.636686, 0.000002, -0.761436, -0.648240, -0, -0.687961, -0.725747, -0.136409, -0.687961, -0.712813, -0.275779, -0.687961, -0.671309, -0.409115, -0.687961, -0.599445, -0.526709, -0.687961, -0.499286, -0.620216, -0.687961, -0.376884, -0.684521, -0.687961, -0.241124, -0.718584, -0.687961, -0.101718, -0.724978, -0.687961, 0.033407, -0.705242, -0.687961, 0.171296, -0.656180, -0.687961, 0.310060, -0.576885, -0.687961, 0.440355, -0.470458, -0.687961, 0.552610, -0.343814, -0.687961, 0.639141, -0.206248, -0.687961, 0.695824, -0.067347, -0.687961, 0.722616, 0.067347, -0.687961, 0.722616, 0.206247, -0.687961, 0.695824, 0.343813, -0.687961, 0.639141, 0.470458, -0.687961, 0.552610, 0.576885, -0.687961, 0.440355, 0.656179, -0.687961, 0.310061, 0.705242, -0.687961, 0.171297, 0.724978, -0.687961, 0.033408, 0.718584, -0.687961, -0.101717, 0.684521, -0.687961, -0.241123, 0.620217, -0.687961, -0.376882, 0.526710, -0.687961, -0.499285, 0.409116, -0.687961, -0.599444, 0.275780, -0.687961, -0.671308, 0.136411, -0.687961, -0.712812, 0.000002, -0.687961, -0.725747, -0, -0.606761, -0.794885, -0.149404, -0.606761, -0.780717, -0.302050, -0.606761, -0.735260, -0.448088, -0.606761, -0.656550, -0.576885, -0.606761, -0.546850, -0.679300, -0.606761, -0.412787, -0.749730, -0.606761, -0.264094, -0.787038, -0.606761, -0.111408, -0.794042, -0.606761, 0.036589, -0.772426, -0.606761, 0.187614, -0.718690, -0.606761, 0.339597, -0.631841, -0.606761, 0.482305, -0.515276, -0.606761, 0.605254, -0.376567, -0.606761, 0.700028, -0.225895, -0.606761, 0.762111, -0.073763, -0.606761, 0.791455, 0.073762, -0.606761, 0.791455, 0.225895, -0.606761, 0.762111, 0.376566, -0.606761, 0.700028, 0.515275, -0.606761, 0.605254, 0.631841, -0.606761, 0.482305, 0.718689, -0.606761, 0.339598, 0.772426, -0.606761, 0.187615, 0.794042, -0.606761, 0.036590, 0.787039, -0.606761, -0.111407, 0.749731, -0.606761, -0.264093, 0.679301, -0.606761, -0.412785, 0.576886, -0.606761, -0.546848, 0.448090, -0.606761, -0.656549, 0.302052, -0.606761, -0.735259, 0.149406, -0.606761, -0.780717, 0.000002, -0.606761, -0.794884, -0, -0.519304, -0.854590, -0.160626, -0.519304, -0.839358, -0.324737, -0.519304, -0.790486, -0.481745, -0.519304, -0.705865, -0.620216, -0.519304, -0.587925, -0.730323, -0.519304, -0.443792, -0.806044, -0.519304, -0.283931, -0.846154, -0.519304, -0.119776, -0.853684, -0.519304, 0.039337, -0.830444, -0.519304, 0.201706, -0.772672, -0.519304, 0.365105, -0.679300, -0.519304, 0.518531, -0.553979, -0.519304, 0.650715, -0.404851, -0.519304, 0.752608, -0.242863, -0.519304, 0.819354, -0.079303, -0.519304, 0.850902, 0.079303, -0.519304, 0.850902, 0.242862, -0.519304, 0.819354, 0.404851, -0.519304, 0.752608, 0.553979, -0.519304, 0.650716, 0.679299, -0.519304, 0.518532, 0.772671, -0.519304, 0.365106, 0.830444, -0.519304, 0.201707, 0.853684, -0.519304, 0.039338, 0.846154, -0.519304, -0.119775, 0.806044, -0.519304, -0.283929, 0.730324, -0.519304, -0.443790, 0.620217, -0.519304, -0.587923, 0.481747, -0.519304, -0.705863, 0.324740, -0.519304, -0.790486, 0.160628, -0.519304, -0.839358, 0.000002, -0.519304, -0.854589, -0, -0.427229, -0.904144, -0.169940, -0.427229, -0.888029, -0.343568, -0.427229, -0.836323, -0.509679, -0.427229, -0.746795, -0.656180, -0.427229, -0.622016, -0.772672, -0.427229, -0.469526, -0.852783, -0.427229, -0.300395, -0.895219, -0.427229, -0.126722, -0.903185, -0.427229, 0.041618, -0.878598, -0.427229, 0.213402, -0.817476, -0.427229, 0.386276, -0.718690, -0.427229, 0.548599, -0.586102, -0.427229, 0.688447, -0.428327, -0.427229, 0.796249, -0.256945, -0.427229, 0.866865, -0.083901, -0.427229, 0.900242, 0.083901, -0.427229, 0.900242, 0.256945, -0.427229, 0.866865, 0.428326, -0.427229, 0.796249, 0.586102, -0.427229, 0.688448, 0.718689, -0.427229, 0.548600, 0.817475, -0.427229, 0.386277, 0.878598, -0.427229, 0.213403, 0.903185, -0.427229, 0.041619, 0.895219, -0.427229, -0.126720, 0.852784, -0.427229, -0.300393, 0.772673, -0.427229, -0.469524, 0.656181, -0.427229, -0.622014, 0.509681, -0.427229, -0.746794, 0.343570, -0.427229, -0.836322, 0.169942, -0.427229, -0.888029, 0.000003, -0.427229, -0.904144, -0, -0.332242, -0.943194, -0.177279, -0.332242, -0.926384, -0.358407, -0.332242, -0.872445, -0.531693, -0.332242, -0.779050, -0.684521, -0.332242, -0.648881, -0.806044, -0.332242, -0.489805, -0.889615, -0.332242, -0.313369, -0.933884, -0.332242, -0.132195, -0.942194, -0.332242, 0.043416, -0.916546, -0.332242, 0.222619, -0.852783, -0.332242, 0.402959, -0.749730, -0.332242, 0.572293, -0.611416, -0.332242, 0.718182, -0.446826, -0.332242, 0.830639, -0.268043, -0.332242, 0.904305, -0.087525, -0.332242, 0.939124, 0.087525, -0.332242, 0.939124, 0.268043, -0.332242, 0.904306, 0.446826, -0.332242, 0.830639, 0.611416, -0.332242, 0.718183, 0.749730, -0.332242, 0.572294, 0.852783, -0.332242, 0.402961, 0.916545, -0.332242, 0.222620, 0.942194, -0.332242, 0.043417, 0.933885, -0.332242, -0.132193, 0.889616, -0.332242, -0.313367, 0.806045, -0.332242, -0.489803, 0.684522, -0.332242, -0.648880, 0.531695, -0.332242, -0.779048, 0.358409, -0.332242, -0.872444, 0.177282, -0.332242, -0.926383, 0.000003, -0.332242, -0.943194, -0, -0.236027, -0.971747, -0.182646, -0.236027, -0.954427, -0.369256, -0.236027, -0.898855, -0.547788, -0.236027, -0.802633, -0.705242, -0.236027, -0.668524, -0.830444, -0.236027, -0.504632, -0.916546, -0.236027, -0.322855, -0.962155, -0.236027, -0.136197, -0.970717, -0.236027, 0.044730, -0.944291, -0.236027, 0.229358, -0.878598, -0.236027, 0.415158, -0.772426, -0.236027, 0.589618, -0.629925, -0.236027, 0.739923, -0.460353, -0.236027, 0.855784, -0.276157, -0.236027, 0.931681, -0.090174, -0.236027, 0.967554, 0.090174, -0.236027, 0.967554, 0.276157, -0.236027, 0.931681, 0.460352, -0.236027, 0.855784, 0.629924, -0.236027, 0.739923, 0.772426, -0.236027, 0.589618, 0.878598, -0.236027, 0.415159, 0.944291, -0.236027, 0.229359, 0.970716, -0.236027, 0.044731, 0.962155, -0.236027, -0.136195, 0.916546, -0.236027, -0.322853, 0.830445, -0.236027, -0.504630, 0.705244, -0.236027, -0.668522, 0.547790, -0.236027, -0.802632, 0.369259, -0.236027, -0.898854, 0.182649, -0.236027, -0.954427, 0.000003, -0.236027, -0.971747, -0, -0.140157, -0.990129, -0.186101, -0.140157, -0.972483, -0.376242, -0.140157, -0.915859, -0.558151, -0.140157, -0.817817, -0.718584, -0.140157, -0.681171, -0.846154, -0.140157, -0.514178, -0.933884, -0.140157, -0.328962, -0.980356, -0.140157, -0.138773, -0.989080, -0.140157, 0.045576, -0.962155, -0.140157, 0.233697, -0.895219, -0.140157, 0.423012, -0.787039, -0.140157, 0.600772, -0.641841, -0.140157, 0.753920, -0.469061, -0.140157, 0.871973, -0.281381, -0.140157, 0.949305, -0.091880, -0.140157, 0.985857, 0.091880, -0.140157, 0.985857, 0.281381, -0.140157, 0.949305, 0.469061, -0.140157, 0.871974, 0.641841, -0.140157, 0.753921, 0.787038, -0.140157, 0.600772, 0.895219, -0.140157, 0.423013, 0.962155, -0.140157, 0.233698, 0.989080, -0.140157, 0.045578, 0.980356, -0.140157, -0.138772, 0.933885, -0.140157, -0.328961, 0.846155, -0.140157, -0.514176, 0.718585, -0.140157, -0.681169, 0.558153, -0.140157, -0.817815, 0.376244, -0.140157, -0.915858, 0.186104, -0.140157, -0.972482, 0.000003, -0.140157, -0.990129, -0, -0.046031, -0.998940, -0.187757, -0.046031, -0.981136, -0.379589, -0.046031, -0.924009, -0.563117, -0.046031, -0.825094, -0.724978, -0.046031, -0.687232, -0.853684, -0.046031, -0.518754, -0.942194, -0.046031, -0.331890, -0.989080, -0.046031, -0.140008, -0.997881, -0.046031, 0.045982, -0.970717, -0.046031, 0.235777, -0.903185, -0.046031, 0.426776, -0.794042, -0.046031, 0.606118, -0.647553, -0.046031, 0.760629, -0.473235, -0.046031, 0.879733, -0.283885, -0.046031, 0.957753, -0.092698, -0.046031, 0.994630, 0.092698, -0.046031, 0.994630, 0.283885, -0.046031, 0.957753, 0.473235, -0.046031, 0.879733, 0.647552, -0.046031, 0.760629, 0.794041, -0.046031, 0.606118, 0.903185, -0.046031, 0.426777, 0.970716, -0.046031, 0.235778, 0.997881, -0.046031, 0.045983, 0.989080, -0.046030, -0.140006, 0.942195, -0.046031, -0.331888, 0.853685, -0.046031, -0.518752, 0.724980, -0.046031, -0.687230, 0.563119, -0.046031, -0.825092, 0.379592, -0.046031, -0.924008, 0.187760, -0.046031, -0.981136, 0.000003, -0.046031, -0.998940, -0, 0.046030, -0.998940, -0.187757, 0.046030, -0.981136, -0.379589, 0.046030, -0.924009, -0.563117, 0.046031, -0.825094, -0.724978, 0.046031, -0.687232, -0.853684, 0.046031, -0.518754, -0.942194, 0.046031, -0.331890, -0.989080, 0.046031, -0.140008, -0.997831, 0.046569, 0.046520, -0.970510, 0.048450, 0.236143, -0.902925, 0.049621, 0.426923, -0.793845, 0.049856, 0.606073, -0.647486, 0.049214, 0.760486, -0.473287, 0.048043, 0.879597, -0.283978, 0.046858, 0.957685, -0.092745, 0.046129, 0.994621, 0.092698, 0.046030, 0.994630, 0.283885, 0.046031, 0.957753, 0.473235, 0.046031, 0.879733, 0.647552, 0.046031, 0.760629, 0.794041, 0.046031, 0.606118, 0.903185, 0.046031, 0.426777, 0.970716, 0.046030, 0.235778, 0.997881, 0.046030, 0.045983, 0.989112, 0.046016, -0.139782, 0.942552, 0.043881, -0.331164, 0.854565, 0.039729, -0.517823, 0.726323, 0.034936, -0.686465, 0.564643, 0.031390, -0.824738, 0.380955, 0.030621, -0.924086, 0.188731, 0.033162, -0.981469, 0.000538, 0.038539, -0.999257, -0, 0.140156, -0.990129, -0.186101, 0.140157, -0.972483, -0.376242, 0.140156, -0.915859, -0.558151, 0.140157, -0.817817, -0.718584, 0.140157, -0.681171, -0.846154, 0.140157, -0.514178, -0.933884, 0.140157, -0.328962, -0.980356, 0.140157, -0.138773, -0.988940, 0.140628, 0.047135, -0.961583, 0.142276, 0.234766, -0.894510, 0.143300, 0.423459, -0.786508, 0.143507, 0.600675, -0.641675, 0.142945, 0.753539, -0.469221, 0.141920, 0.871602, -0.281654, 0.140882, 0.949117, -0.092016, 0.140243, 0.985832, 0.091880, 0.140156, 0.985857, 0.281381, 0.140157, 0.949306, 0.469061, 0.140156, 0.871974, 0.641841, 0.140157, 0.753921, 0.787038, 0.140157, 0.600772, 0.895219, 0.140156, 0.423013, 0.962155, 0.140157, 0.233698, 0.989080, 0.140156, 0.045577, 0.980213, 0.141075, -0.138854, 0.934735, 0.139664, -0.326748, 0.849063, 0.135385, -0.510650, 0.723766, 0.129374, -0.677809, 0.564868, 0.123468, -0.815892, 0.383259, 0.119396, -0.915892, 0.192330, 0.118075, -0.974201, 0.004877, 0.119448, -0.992828, -0, 0.236026, -0.971747, -0.182646, 0.236027, -0.954428, -0.369256, 0.236027, -0.898856, -0.547788, 0.236027, -0.802633, -0.705242, 0.236027, -0.668524, -0.830444, 0.236026, -0.504632, -0.916546, 0.236027, -0.322855, -0.962155, 0.236026, -0.136197, -0.970503, 0.236419, 0.047215, -0.943430, 0.237792, 0.231074, -0.877537, 0.238646, 0.415904, -0.771646, 0.238819, 0.589515, -0.629703, 0.238351, 0.739366, -0.460628, 0.237498, 0.855229, -0.276597, 0.236632, 0.931396, -0.090392, 0.236099, 0.967516, 0.090174, 0.236027, 0.967554, 0.276157, 0.236027, 0.931681, 0.460352, 0.236027, 0.855785, 0.629924, 0.236027, 0.739923, 0.772426, 0.236027, 0.589618, 0.878598, 0.236026, 0.415159, 0.944291, 0.236026, 0.229359, 0.970717, 0.236026, 0.044731, 0.961569, 0.237615, -0.137567, 0.917634, 0.236842, -0.319144, 0.835633, 0.232703, -0.497561, 0.715500, 0.226068, -0.661025, 0.562181, 0.218586, -0.797604, 0.385556, 0.212021, -0.897994, 0.198472, 0.207545, -0.957880, 0.013691, 0.205462, -0.978569, -0, 0.332242, -0.943194, -0.177279, 0.332242, -0.926384, -0.358407, 0.332242, -0.872445, -0.531693, 0.332242, -0.779050, -0.684521, 0.332242, -0.648881, -0.806044, 0.332242, -0.489805, -0.889615, 0.332242, -0.313369, -0.933884, 0.332241, -0.132195, -0.941929, 0.332547, 0.046711, -0.915484, 0.333622, 0.224913, -0.851489, 0.334290, 0.404001, -0.748802, 0.334425, 0.572237, -0.611194, 0.334060, 0.717528, -0.447224, 0.333393, 0.829964, -0.268635, 0.332716, 0.903956, -0.087814, 0.332298, 0.939078, 0.087525, 0.332242, 0.939125, 0.268043, 0.332242, 0.904306, 0.446826, 0.332242, 0.830639, 0.611416, 0.332242, 0.718183, 0.749730, 0.332242, 0.572294, 0.852783, 0.332242, 0.402960, 0.916546, 0.332242, 0.222620, 0.942194, 0.332242, 0.043417, 0.932678, 0.334174, -0.135794, 0.890785, 0.333908, -0.308233, 0.813721, 0.330175, -0.478374, 0.700831, 0.323579, -0.635714, 0.555836, 0.315484, -0.769101, 0.387229, 0.307512, -0.869189, 0.206851, 0.300924, -0.930945, 0.027083, 0.296281, -0.954717, -0, 0.427228, -0.904144, -0.169940, 0.427228, -0.888030, -0.343568, 0.427228, -0.836324, -0.509679, 0.427228, -0.746795, -0.656180, 0.427228, -0.622016, -0.772672, 0.427228, -0.469526, -0.852783, 0.427228, -0.300395, -0.895219, 0.427228, -0.126722, -0.902891, 0.427445, 0.045584, -0.877435, 0.428217, 0.216189, -0.816077, 0.428697, 0.387604, -0.717722, 0.428794, 0.548645, -0.585935, 0.428533, 0.687779, -0.428852, 0.428054, 0.795522, -0.257669, 0.427568, 0.866482, -0.084249, 0.427269, 0.900191, 0.083901, 0.427228, 0.900243, 0.256945, 0.427228, 0.866865, 0.428326, 0.427228, 0.796249, 0.586102, 0.427228, 0.688448, 0.718689, 0.427228, 0.548600, 0.817475, 0.427228, 0.386277, 0.878598, 0.427228, 0.213403, 0.903185, 0.427228, 0.041620, 0.893325, 0.429150, -0.133419, 0.854010, 0.429227, -0.293992, 0.783021, 0.426126, -0.453094, 0.679227, 0.420218, -0.601721, 0.545119, 0.412536, -0.729835, 0.387575, 0.404422, -0.828389, 0.217023, 0.397046, -0.891771, 0.045055, 0.391076, -0.919255, -0, 0.519304, -0.854590, -0.160626, 0.519304, -0.839359, -0.324738, 0.519304, -0.790487, -0.481745, 0.519304, -0.705865, -0.620216, 0.519304, -0.587925, -0.730323, 0.519304, -0.443792, -0.806044, 0.519304, -0.283931, -0.846154, 0.519304, -0.119776, -0.853385, 0.519437, 0.043813, -0.829278, 0.519923, 0.204886, -0.771296, 0.520225, 0.366699, -0.678397, 0.520287, 0.518728, -0.553919, 0.520123, 0.650112, -0.405503, 0.519823, 0.751899, -0.243695, 0.519517, 0.818972, -0.079697, 0.519329, 0.850850, 0.079303, 0.519304, 0.850902, 0.242862, 0.519304, 0.819354, 0.404851, 0.519304, 0.752608, 0.553979, 0.519304, 0.650716, 0.679300, 0.519304, 0.518532, 0.772672, 0.519304, 0.365106, 0.830444, 0.519304, 0.201707, 0.853684, 0.519304, 0.039338, 0.843625, 0.520869, -0.130350, 0.807450, 0.521119, -0.276512, 0.743519, 0.518800, -0.421931, 0.650378, 0.514118, -0.559187, 0.529419, 0.507787, -0.679608, 0.385848, 0.500799, -0.774804, 0.228386, 0.494089, -0.838878, 0.067425, 0.488269, -0.870085, -0, 0.606760, -0.794885, -0.149404, 0.606760, -0.780718, -0.302050, 0.606760, -0.735260, -0.448088, 0.606760, -0.656551, -0.576886, 0.606760, -0.546850, -0.679300, 0.606760, -0.412787, -0.749731, 0.606760, -0.264094, -0.787039, 0.606760, -0.111409, -0.793760, 0.606820, 0.041399, -0.771344, 0.607058, 0.191071, -0.717448, 0.607207, 0.341421, -0.631093, 0.607238, 0.482684, -0.515362, 0.607158, 0.604782, -0.377337, 0.607012, 0.699395, -0.226807, 0.606864, 0.761758, -0.074186, 0.606773, 0.791406, 0.073762, 0.606760, 0.791455, 0.225895, 0.606760, 0.762111, 0.376566, 0.606760, 0.700028, 0.515276, 0.606760, 0.605254, 0.631841, 0.606760, 0.482306, 0.718690, 0.606760, 0.339598, 0.772426, 0.606760, 0.187615, 0.794042, 0.606760, 0.036590, 0.784042, 0.607677, -0.126520, 0.751580, 0.607945, -0.255991, 0.695519, 0.606460, -0.385305, 0.614259, 0.603337, -0.508596, 0.508309, 0.599038, -0.618688, 0.381314, 0.594220, -0.708168, 0.240165, 0.589510, -0.771232, 0.093715, 0.585333, -0.805359, -0, 0.687961, -0.725748, -0.136409, 0.687961, -0.712813, -0.275779, 0.687961, -0.671309, -0.409115, 0.687961, -0.599445, -0.526709, 0.687961, -0.499286, -0.620216, 0.687961, -0.376884, -0.684521, 0.687961, -0.241124, -0.718584, 0.687961, -0.101718, -0.724731, 0.687964, 0.038363, -0.704313, 0.688007, 0.174902, -0.655155, 0.688034, 0.312059, -0.576352, 0.688041, 0.440928, -0.470709, 0.688027, 0.552314, -0.344683, 0.688003, 0.638628, -0.207206, 0.687978, 0.695523, -0.067785, 0.687963, 0.722573, 0.067347, 0.687961, 0.722616, 0.206247, 0.687961, 0.695825, 0.343814, 0.687961, 0.639142, 0.470458, 0.687961, 0.552611, 0.576885, 0.687961, 0.440356, 0.656180, 0.687961, 0.310061, 0.705243, 0.687961, 0.171297, 0.724979, 0.687961, 0.033408, 0.715377, 0.688025, -0.121891, 0.687182, 0.688199, -0.232730, 0.639635, 0.687491, -0.343836, 0.571153, 0.685992, -0.450775, 0.481617, 0.684008, -0.547885, 0.373346, 0.681937, -0.628948, 0.251451, 0.680122, -0.688626, 0.123059, 0.678746, -0.723989, -0, 0.761436, -0.648241, -0.121841, 0.761436, -0.636687, -0.246327, 0.761435, -0.599616, -0.365423, 0.761436, -0.535427, -0.470459, 0.761436, -0.445965, -0.553980, 0.761435, -0.336634, -0.611417, 0.761436, -0.215373, -0.641842, 0.761435, -0.090855, -0.647351, 0.761399, 0.034749, -0.629189, 0.761309, 0.156618, -0.585342, 0.761254, 0.279047, -0.514987, 0.761244, 0.394077, -0.420626, 0.761276, 0.493490, -0.308031, 0.761334, 0.570515, -0.185189, 0.761393, 0.621277, -0.060589, 0.761431, 0.645409, 0.060154, 0.761436, 0.645443, 0.184221, 0.761436, 0.621513, 0.307096, 0.761436, 0.570884, 0.420215, 0.761436, 0.493594, 0.515276, 0.761436, 0.393328, 0.586102, 0.761436, 0.276948, 0.629925, 0.761436, 0.153003, 0.647553, 0.761436, 0.029840, 0.638737, 0.760561, -0.116461, 0.615312, 0.760587, -0.207119, 0.576766, 0.760496, -0.298308, 0.521657, 0.760400, -0.386867, 0.449481, 0.760534, -0.468568, 0.361513, 0.761151, -0.538478, 0.261282, 0.762395, -0.592019, 0.154169, 0.764242, -0.626232, -0, 0.825969, -0.563716, -0.105954, 0.825969, -0.553669, -0.214208, 0.825969, -0.521431, -0.317775, 0.825969, -0.465612, -0.409115, 0.825969, -0.387815, -0.481745, 0.825969, -0.292740, -0.531693, 0.825969, -0.187290, -0.558151, 0.825969, -0.079009, -0.562966, 0.825913, 0.030621, -0.547259, 0.825752, 0.136534, -0.509191, 0.825652, 0.242945, -0.448034, 0.825633, 0.342922, -0.365963, 0.825689, 0.429311, -0.268013, 0.825791, 0.496223, -0.161139, 0.825895, 0.540306, -0.052725, 0.825960, 0.561258, 0.052311, 0.825969, 0.561283, 0.160200, 0.825969, 0.540473, 0.267053, 0.825969, 0.496445, 0.365423, 0.825969, 0.429234, 0.448089, 0.825969, 0.342041, 0.509680, 0.825969, 0.240836, 0.547789, 0.825969, 0.133053, 0.563118, 0.825969, 0.025949, 0.555472, 0.824193, -0.110255, 0.537235, 0.824087, -0.179609, 0.508031, 0.824374, -0.249623, 0.466643, 0.825201, -0.318256, 0.412357, 0.826795, -0.382585, 0.345667, 0.829357, -0.438956, 0.268768, 0.832945, -0.483701, 0.185423, 0.837423, -0.514141, -0, 0.880666, -0.473738, -0.089042, 0.880666, -0.465295, -0.180017, 0.880666, -0.438203, -0.267053, 0.880666, -0.391293, -0.343814, 0.880666, -0.325914, -0.404852, 0.880666, -0.246014, -0.446827, 0.880666, -0.157396, -0.469062, 0.880666, -0.066398, -0.473132, 0.880606, 0.026058, -0.460017, 0.880429, 0.115018, -0.428083, 0.880319, 0.204409, -0.376705, 0.880297, 0.288392, -0.307715, 0.880359, 0.360942, -0.225360, 0.880471, 0.417113, -0.135499, 0.880585, 0.454103, -0.044339, 0.880656, 0.471677, 0.043961, 0.880666, 0.471694, 0.134630, 0.880666, 0.454206, 0.224428, 0.880666, 0.417205, 0.307096, 0.880666, 0.360722, 0.376567, 0.880666, 0.287446, 0.428327, 0.880666, 0.202395, 0.460353, 0.880666, 0.111816, 0.473236, 0.880666, 0.021807, 0.467099, 0.878147, -0.103330, 0.454353, 0.877984, -0.150691, 0.434706, 0.878368, -0.198749, 0.407191, 0.879459, -0.246469, 0.370985, 0.881496, -0.292120, 0.325972, 0.884694, -0.333254, 0.273234, 0.889124, -0.367153, 0.215092, 0.894647, -0.391588, -0, 0.924989, -0.379993, -0.071422, 0.924989, -0.373221, -0.144395, 0.924989, -0.351490, -0.214208, 0.924989, -0.313863, -0.275779, 0.924989, -0.261421, -0.324738, 0.924989, -0.197332, -0.358407, 0.924989, -0.126250, -0.376242, 0.924989, -0.053259, -0.379528, 0.924938, 0.021151, -0.369081, 0.924785, 0.092473, -0.343514, 0.924690, 0.164152, -0.302315, 0.924672, 0.231491, -0.246959, 0.924725, 0.289647, -0.180866, 0.924821, 0.334653, -0.108748, 0.924920, 0.364276, -0.035588, 0.924981, 0.378343, 0.035262, 0.924989, 0.378354, 0.107989, 0.924989, 0.364326, 0.180017, 0.924989, 0.334647, 0.246327, 0.924989, 0.289341, 0.302051, 0.924989, 0.230565, 0.343569, 0.924989, 0.162344, 0.369257, 0.924989, 0.089689, 0.379591, 0.924989, 0.017492, 0.375217, 0.921977, -0.095764, 0.368130, 0.921884, -0.120870, 0.358137, 0.922078, -0.146660, 0.344505, 0.922694, -0.173066, 0.326307, 0.923976, -0.199480, 0.302882, 0.926189, -0.224582, 0.274319, 0.929489, -0.246573, 0.241645, 0.933844, -0.263711, -0, 0.958769, -0.284187, -0.053415, 0.958769, -0.279122, -0.107989, 0.958769, -0.262870, -0.160201, 0.958769, -0.234730, -0.206248, 0.958769, -0.195510, -0.242864, 0.958769, -0.147580, -0.268044, 0.958769, -0.094419, -0.281382, 0.958769, -0.039831, -0.283854, 0.958734, 0.015998, -0.276095, 0.958628, 0.069313, -0.257009, 0.958562, 0.122904, -0.226207, 0.958549, 0.173248, -0.184793, 0.958586, 0.216714, -0.135338, 0.958653, 0.250337, -0.081375, 0.958721, 0.272456, -0.026631, 0.958763, 0.282956, 0.026372, 0.958769, 0.282961, 0.080762, 0.958769, 0.272470, 0.134630, 0.958769, 0.250274, 0.184221, 0.958769, 0.216391, 0.225896, 0.958769, 0.172434, 0.256946, 0.958769, 0.121413, 0.276158, 0.958769, 0.067076, 0.283886, 0.958769, 0.013082, 0.281422, 0.955572, -0.087654, 0.280020, 0.955706, -0.090638, 0.279670, 0.955455, -0.094290, 0.279817, 0.954880, -0.099536, 0.279364, 0.954218, -0.106885, 0.277058, 0.953813, -0.116098, 0.272008, 0.953982, -0.126217, 0.264012, 0.954892, -0.135937, -0, 0.982177, -0.187958, -0.035328, 0.982177, -0.184608, -0.071422, 0.982177, -0.173859, -0.105955, 0.982177, -0.155247, -0.136410, 0.982177, -0.129308, -0.160627, 0.982177, -0.097607, -0.177280, 0.982177, -0.062447, -0.186102, 0.982177, -0.026344, -0.187747, 0.982159, 0.010695, -0.182648, 0.982104, 0.045941, -0.170046, 0.982071, 0.081374, -0.149680, 0.982064, 0.114659, -0.122281, 0.982083, 0.143390, -0.089557, 0.982117, 0.165606, -0.053849, 0.982152, 0.180213, -0.017624, 0.982174, 0.187145, 0.017442, 0.982177, 0.187147, 0.053415, 0.982177, 0.180208, 0.089043, 0.982177, 0.165528, 0.121841, 0.982177, 0.143118, 0.149404, 0.982177, 0.114046, 0.169941, 0.982177, 0.080301, 0.182647, 0.982177, 0.044363, 0.187758, 0.982177, 0.008652, 0.187235, 0.979124, -0.079110, 0.191404, 0.979648, -0.060457, 0.200581, 0.978755, -0.042490, 0.214307, 0.976387, -0.027213, 0.231192, 0.972772, -0.016296, 0.249262, 0.968378, -0.010559, 0.266571, 0.963766, -0.009790, 0.281694, 0.959416, -0.012991, -0, 0.995685, -0.092798, -0.017443, 0.995685, -0.091144, -0.035262, 0.995685, -0.085837, -0.052311, 0.995685, -0.076648, -0.067347, 0.995685, -0.063841, -0.079304, 0.995685, -0.048190, -0.087526, 0.995685, -0.030831, -0.091882, 0.995685, -0.013006, -0.092697, 0.995680, 0.005334, -0.090194, 0.995665, 0.022728, -0.083982, 0.995655, 0.040215, -0.073929, 0.995654, 0.056643, -0.060399, 0.995659, 0.070820, -0.044236, 0.995668, 0.081778, -0.026600, 0.995678, 0.088980, -0.008706, 0.995684, 0.092397, 0.008611, 0.995685, 0.092397, 0.026371, 0.995685, 0.088972, 0.043961, 0.995685, 0.081724, 0.060155, 0.995685, 0.070660, 0.073763, 0.995685, 0.056306, 0.083902, 0.995685, 0.039645, 0.090176, 0.995685, 0.021903, 0.092699, 0.995685, 0.004272, 0.094039, 0.993087, -0.070246, 0.103544, 0.994150, -0.030742, 0.122028, 0.992494, 0.008003, 0.149040, 0.987905, 0.042786, 0.182735, 0.980617, 0.070699, 0.220253, 0.971292, 0.089889, 0.258465, 0.960837, 0.099940, 0.294713, 0.950156, 0.101726, -0.004408, 0.998911, -0.046449, -0.013321, 0.998910, -0.044744, -0.022161, 0.998909, -0.041112, -0.030288, 0.998908, -0.035565, -0.037119, 0.998908, -0.028360, -0.042206, 0.998909, -0.019988, -0.045344, 0.998910, -0.011080, -0.046619, 0.998911, -0.002074, -0.046196, 0.998907, 0.007088, -0.044045, 0.998903, 0.015919, -0.039966, 0.998900, 0.024514, -0.034012, 0.998900, 0.032267, -0.026494, 0.998903, 0.038618, -0.017919, 0.998906, 0.043190, -0.008929, 0.998909, 0.045827, -0, 0.998911, 0.046650, 0.008842, 0.998910, 0.045826, 0.017786, 0.998909, 0.043175, 0.026349, 0.998909, 0.038569, 0.033902, 0.998908, 0.032138, 0.039901, 0.998909, 0.024279, 0.044018, 0.998909, 0.015567, 0.046194, 0.998911, 0.006608, 0.049235, 0.996897, -0.061421, 0.052333, 0.997832, -0.039908, 0.069240, 0.997566, 0.008293, 0.096562, 0.993858, 0.054064, 0.133153, 0.986646, 0.093809, 0.176487, 0.976382, 0.124621, 0.223175, 0.963949, 0.144899, 0.269820, 0.950419, 0.154599, 0.269820, 0.950419, 0.154600, -0.013209, -0.990162, -0.139299, -0.039913, -0.990173, -0.134029, -0.066321, -0.990182, -0.123052, -0.090620, -0.990186, -0.106395, -0.111062, -0.990185, -0.084843, -0.126342, -0.990180, -0.059844, -0.135866, -0.990171, -0.033198, -0.139783, -0.990160, -0.006615, -0.138491, -0.990165, 0.019822, -0.131831, -0.990176, 0.046611, -0.119403, -0.990183, 0.072666, -0.101419, -0.990186, 0.096153, -0.078849, -0.990184, 0.115402, -0.053264, -0.990178, 0.129269, -0.026493, -0.990168, 0.137351, -0, -0.990159, 0.139944, 0.026493, -0.990168, 0.137351, 0.053264, -0.990178, 0.129269, 0.078849, -0.990184, 0.115402, 0.101419, -0.990186, 0.096153, 0.119403, -0.990183, 0.072666, 0.131831, -0.990176, 0.046611, 0.138491, -0.990165, 0.019822, 0.139783, -0.990160, -0.006615, 0.135867, -0.990171, -0.033198, 0.126343, -0.990180, -0.059844, 0.111062, -0.990185, -0.084843, 0.090620, -0.990186, -0.106395, 0.066321, -0.990182, -0.123052, 0.039914, -0.990173, -0.134029, 0.013209, -0.990162, -0.139299, -0.022218, -0.971907, -0.234313, -0.067139, -0.971938, -0.225453, -0.111562, -0.971961, -0.206992, -0.152438, -0.971973, -0.178974, -0.186824, -0.971971, -0.142720, -0.212527, -0.971956, -0.100666, -0.228544, -0.971931, -0.055844, -0.235126, -0.971901, -0.011126, -0.232957, -0.971915, 0.033342, -0.221758, -0.971945, 0.078406, -0.200854, -0.971965, 0.122235, -0.170603, -0.971974, 0.161746, -0.132637, -0.971968, 0.194125, -0.089598, -0.971951, 0.217449, -0.044564, -0.971923, 0.231040, -0, -0.971899, 0.235398, 0.044564, -0.971923, 0.231040, 0.089598, -0.971951, 0.217449, 0.132637, -0.971969, 0.194125, 0.170603, -0.971974, 0.161746, 0.200854, -0.971965, 0.122235, 0.221757, -0.971944, 0.078407, 0.232957, -0.971915, 0.033343, 0.235126, -0.971901, -0.011126, 0.228544, -0.971931, -0.055843, 0.212527, -0.971956, -0.100666, 0.186824, -0.971971, -0.142720, 0.152438, -0.971973, -0.178974, 0.111562, -0.971961, -0.206992, 0.067140, -0.971938, -0.225453, 0.022219, -0.971907, -0.234313, -0.031265, -0.943562, -0.329718, -0.094479, -0.943621, -0.317260, -0.156995, -0.943665, -0.291288, -0.214519, -0.943688, -0.251863, -0.262909, -0.943684, -0.200844, -0.299075, -0.943656, -0.141661, -0.321607, -0.943607, -0.078583, -0.330860, -0.943550, -0.015657, -0.327812, -0.943577, 0.046919, -0.312061, -0.943633, 0.110335, -0.282652, -0.943673, 0.172015, -0.240084, -0.943689, 0.227618, -0.186654, -0.943680, 0.273183, -0.126085, -0.943645, 0.306001, -0.062710, -0.943592, 0.325117, -0, -0.943546, 0.331241, 0.062710, -0.943592, 0.325117, 0.126085, -0.943645, 0.306001, 0.186654, -0.943680, 0.273183, 0.240083, -0.943689, 0.227619, 0.282651, -0.943673, 0.172016, 0.312061, -0.943633, 0.110336, 0.327812, -0.943577, 0.046919, 0.330860, -0.943550, -0.015656, 0.321607, -0.943607, -0.078583, 0.299076, -0.943656, -0.141661, 0.262910, -0.943684, -0.200844, 0.214520, -0.943688, -0.251862, 0.156995, -0.943665, -0.291288, 0.094480, -0.943621, -0.317260, 0.031266, -0.943562, -0.329718, -0.040203, -0.904781, -0.423976, -0.121494, -0.904874, -0.407974, -0.201890, -0.904944, -0.374588, -0.275869, -0.904981, -0.323892, -0.338097, -0.904975, -0.258283, -0.384599, -0.904930, -0.182171, -0.413559, -0.904852, -0.101051, -0.425441, -0.904762, -0.020133, -0.421530, -0.904805, 0.060332, -0.401292, -0.904894, 0.141884, -0.363483, -0.904957, 0.221207, -0.308745, -0.904983, 0.292715, -0.240034, -0.904967, 0.351308, -0.162139, -0.904913, 0.393502, -0.080639, -0.904829, 0.418069, -0, -0.904756, 0.425931, 0.080639, -0.904829, 0.418069, 0.162139, -0.904913, 0.393502, 0.240034, -0.904967, 0.351309, 0.308745, -0.904983, 0.292715, 0.363483, -0.904957, 0.221208, 0.401292, -0.904894, 0.141885, 0.421530, -0.904805, 0.060333, 0.425441, -0.904762, -0.020132, 0.413559, -0.904852, -0.101051, 0.384599, -0.904930, -0.182170, 0.338098, -0.904975, -0.258282, 0.275870, -0.904981, -0.323892, 0.201891, -0.904944, -0.374587, 0.121495, -0.904874, -0.407973, 0.040204, -0.904781, -0.423976, -0.048876, -0.855532, -0.515438, -0.147710, -0.855662, -0.496008, -0.245464, -0.855761, -0.455435, -0.335416, -0.855811, -0.393805, -0.411075, -0.855804, -0.314033, -0.467602, -0.855740, -0.221487, -0.502793, -0.855632, -0.122855, -0.517214, -0.855506, -0.024475, -0.512470, -0.855567, 0.073348, -0.487890, -0.855691, 0.172502, -0.441936, -0.855779, 0.268952, -0.375389, -0.855815, 0.355898, -0.291844, -0.855793, 0.427136, -0.197130, -0.855717, 0.478423, -0.098037, -0.855600, 0.508269, 0, -0.855497, 0.517807, 0.098037, -0.855600, 0.508269, 0.197130, -0.855717, 0.478423, 0.291844, -0.855793, 0.427136, 0.375388, -0.855815, 0.355899, 0.441936, -0.855779, 0.268953, 0.487889, -0.855691, 0.172503, 0.512470, -0.855567, 0.073349, 0.517214, -0.855506, -0.024475, 0.502793, -0.855632, -0.122854, 0.467603, -0.855740, -0.221486, 0.411076, -0.855804, -0.314032, 0.335417, -0.855812, -0.393804, 0.245465, -0.855761, -0.455434, 0.147711, -0.855662, -0.496007, 0.048877, -0.855532, -0.515438, -0.057123, -0.796135, -0.602417, -0.172645, -0.796300, -0.579741, -0.286914, -0.796426, -0.532341, -0.392064, -0.796490, -0.460315, -0.480500, -0.796480, -0.367068, -0.546559, -0.796399, -0.258886, -0.587664, -0.796262, -0.143593, -0.604487, -0.796101, -0.028605, -0.598958, -0.796178, 0.085727, -0.570259, -0.796336, 0.201626, -0.516567, -0.796448, 0.314371, -0.438788, -0.796494, 0.416006, -0.341130, -0.796466, 0.499271, -0.230414, -0.796369, 0.559200, -0.114584, -0.796221, 0.594056, -0, -0.796090, 0.605178, 0.114584, -0.796221, 0.594056, 0.230414, -0.796369, 0.559201, 0.341130, -0.796466, 0.499271, 0.438788, -0.796495, 0.416007, 0.516567, -0.796448, 0.314371, 0.570259, -0.796336, 0.201626, 0.598958, -0.796178, 0.085728, 0.604487, -0.796101, -0.028604, 0.587664, -0.796262, -0.143592, 0.546559, -0.796399, -0.258884, 0.480501, -0.796480, -0.367067, 0.392066, -0.796490, -0.460314, 0.286915, -0.796426, -0.532340, 0.172647, -0.796300, -0.579741, 0.057125, -0.796135, -0.602417, -0.064792, -0.727270, -0.683287, -0.195833, -0.727464, -0.657606, -0.325464, -0.727612, -0.603866, -0.444753, -0.727687, -0.522175, -0.545071, -0.727676, -0.416396, -0.619989, -0.727581, -0.293667, -0.666583, -0.727419, -0.162877, -0.685626, -0.727231, -0.032445, -0.679374, -0.727321, 0.097236, -0.646859, -0.727507, 0.228709, -0.585978, -0.727638, 0.356613, -0.497757, -0.727693, 0.471913, -0.386970, -0.727660, 0.566361, -0.261367, -0.727546, 0.634322, -0.129970, -0.727371, 0.673824, -0, -0.727218, 0.686407, 0.129970, -0.727371, 0.673824, 0.261367, -0.727546, 0.634322, 0.386970, -0.727660, 0.566362, 0.497756, -0.727693, 0.471913, 0.585977, -0.727638, 0.356613, 0.646859, -0.727507, 0.228710, 0.679374, -0.727321, 0.097237, 0.685626, -0.727231, -0.032444, 0.666583, -0.727419, -0.162875, 0.619989, -0.727581, -0.293665, 0.545072, -0.727676, -0.416394, 0.444754, -0.727687, -0.522174, 0.325465, -0.727612, -0.603866, 0.195835, -0.727464, -0.657605, 0.064793, -0.727270, -0.683287, -0.071741, -0.649965, -0.756571, -0.216850, -0.650178, -0.728179, -0.360408, -0.650339, -0.668703, -0.492517, -0.650422, -0.578254, -0.603607, -0.650410, -0.461113, -0.686550, -0.650306, -0.325195, -0.738110, -0.650128, -0.180354, -0.759152, -0.649922, -0.035924, -0.752250, -0.650021, 0.107667, -0.716289, -0.650224, 0.253257, -0.648900, -0.650368, 0.394905, -0.551215, -0.650428, 0.522595, -0.428526, -0.650392, 0.627181, -0.289424, -0.650267, 0.702415, -0.143914, -0.650076, 0.746117, -0, -0.649908, 0.760013, 0.143914, -0.650076, 0.746117, 0.289424, -0.650267, 0.702415, 0.428525, -0.650392, 0.627181, 0.551214, -0.650428, 0.522596, 0.648899, -0.650368, 0.394906, 0.716288, -0.650224, 0.253258, 0.752250, -0.650021, 0.107668, 0.759152, -0.649922, -0.035923, 0.738110, -0.650128, -0.180353, 0.686551, -0.650306, -0.325193, 0.603608, -0.650410, -0.461112, 0.492519, -0.650422, -0.578253, 0.360410, -0.650340, -0.668702, 0.216852, -0.650178, -0.728179, 0.071743, -0.649965, -0.756571, -0.077853, -0.565545, -0.821035, -0.235340, -0.565763, -0.790270, -0.391157, -0.565929, -0.725755, -0.534549, -0.566014, -0.627603, -0.655117, -0.566001, -0.500463, -0.745117, -0.565894, -0.352936, -0.801036, -0.565712, -0.195730, -0.823826, -0.565501, -0.038985, -0.816359, -0.565603, 0.116843, -0.777375, -0.565811, 0.274855, -0.704267, -0.565959, 0.428601, -0.598257, -0.566020, 0.567195, -0.465093, -0.565983, 0.680700, -0.314111, -0.565855, 0.762327, -0.156181, -0.565659, 0.809715, -0, -0.565486, 0.824758, 0.156181, -0.565659, 0.809715, 0.314110, -0.565855, 0.762327, 0.465092, -0.565983, 0.680700, 0.598256, -0.566020, 0.567195, 0.704267, -0.565959, 0.428601, 0.777375, -0.565811, 0.274856, 0.816359, -0.565603, 0.116844, 0.823826, -0.565501, -0.038984, 0.801037, -0.565712, -0.195728, 0.745118, -0.565894, -0.352934, 0.655119, -0.566001, -0.500462, 0.534551, -0.566014, -0.627602, 0.391159, -0.565929, -0.725754, 0.235342, -0.565763, -0.790269, 0.077855, -0.565545, -0.821034, -0.083042, -0.475560, -0.875755, -0.251038, -0.475770, -0.842985, -0.417266, -0.475928, -0.774197, -0.570241, -0.476009, -0.669508, -0.698857, -0.475997, -0.533877, -0.794845, -0.475895, -0.376490, -0.854459, -0.475721, -0.208783, -0.878722, -0.475518, -0.041583, -0.870779, -0.475616, 0.124632, -0.829239, -0.475815, 0.293193, -0.751281, -0.475957, 0.457212, -0.638203, -0.476015, 0.605067, -0.496143, -0.475980, 0.726144, -0.335071, -0.475857, 0.813196, -0.166595, -0.475669, 0.863704, -0, -0.475505, 0.879713, 0.166594, -0.475669, 0.863704, 0.335070, -0.475857, 0.813196, 0.496143, -0.475980, 0.726145, 0.638203, -0.476015, 0.605068, 0.751280, -0.475957, 0.457213, 0.829239, -0.475815, 0.293194, 0.870779, -0.475616, 0.124633, 0.878722, -0.475519, -0.041581, 0.854459, -0.475721, -0.208782, 0.794846, -0.475895, -0.376488, 0.698858, -0.475997, -0.533876, 0.570242, -0.476009, -0.669506, 0.417268, -0.475928, -0.774196, 0.251041, -0.475770, -0.842984, 0.083044, -0.475560, -0.875755, -0.087253, -0.381695, -0.920161, -0.263780, -0.381880, -0.885770, -0.438459, -0.382020, -0.813519, -0.599214, -0.382092, -0.703525, -0.734364, -0.382082, -0.561002, -0.835210, -0.381991, -0.395609, -0.897816, -0.381837, -0.219377, -0.923271, -0.381657, -0.043691, -0.914944, -0.381744, 0.130953, -0.871336, -0.381920, 0.308077, -0.789444, -0.382046, 0.480437, -0.670631, -0.382098, 0.635811, -0.521348, -0.382066, 0.763034, -0.352084, -0.381957, 0.854486, -0.175046, -0.381791, 0.907521, -0, -0.381645, 0.924309, 0.175046, -0.381791, 0.907521, 0.352083, -0.381957, 0.854486, 0.521348, -0.382066, 0.763035, 0.670630, -0.382098, 0.635812, 0.789443, -0.382046, 0.480438, 0.871335, -0.381920, 0.308078, 0.914944, -0.381744, 0.130954, 0.923271, -0.381657, -0.043689, 0.897817, -0.381837, -0.219376, 0.835211, -0.381991, -0.395608, 0.734365, -0.382082, -0.561000, 0.599216, -0.382092, -0.703524, 0.438461, -0.382020, -0.813518, 0.263782, -0.381880, -0.885769, 0.087255, -0.381695, -0.920161, -0.090466, -0.285665, -0.954050, -0.273504, -0.285814, -0.918426, -0.454637, -0.285927, -0.843535, -0.621332, -0.285985, -0.729493, -0.761468, -0.285977, -0.581708, -0.866021, -0.285904, -0.410203, -0.930909, -0.285779, -0.227463, -0.957267, -0.285635, -0.045300, -0.948650, -0.285704, 0.135777, -0.903466, -0.285847, 0.319437, -0.818575, -0.285948, 0.498166, -0.695385, -0.285989, 0.659280, -0.540589, -0.285964, 0.791194, -0.365070, -0.285877, 0.886002, -0.181496, -0.285743, 0.940962, -0, -0.285625, 0.958341, 0.181496, -0.285743, 0.940962, 0.365069, -0.285877, 0.886002, 0.540588, -0.285964, 0.791194, 0.695384, -0.285989, 0.659281, 0.818574, -0.285948, 0.498167, 0.903466, -0.285847, 0.319438, 0.948650, -0.285704, 0.135778, 0.957267, -0.285635, -0.045298, 0.930909, -0.285779, -0.227462, 0.866022, -0.285904, -0.410201, 0.761469, -0.285977, -0.581706, 0.621333, -0.285985, -0.729491, 0.454639, -0.285927, -0.843534, 0.273507, -0.285814, -0.918425, 0.090469, -0.285665, -0.954050, -0.092696, -0.189131, -0.977567, -0.280253, -0.189234, -0.941089, -0.465865, -0.189313, -0.864367, -0.636683, -0.189353, -0.747516, -0.780280, -0.189347, -0.596079, -0.887405, -0.189297, -0.420332, -0.953874, -0.189210, -0.233075, -0.980858, -0.189110, -0.046416, -0.972041, -0.189158, 0.139125, -0.925766, -0.189257, 0.327321, -0.838794, -0.189327, 0.510471, -0.712566, -0.189356, 0.675569, -0.553943, -0.189339, 0.810739, -0.374082, -0.189278, 0.907875, -0.185973, -0.189185, 0.964170, -0, -0.189103, 0.981957, 0.185972, -0.189185, 0.964170, 0.374082, -0.189278, 0.907875, 0.553943, -0.189339, 0.810740, 0.712565, -0.189356, 0.675570, 0.838793, -0.189327, 0.510471, 0.925765, -0.189257, 0.327323, 0.972041, -0.189158, 0.139126, 0.980858, -0.189110, -0.046414, 0.953874, -0.189210, -0.233073, 0.887406, -0.189297, -0.420330, 0.780282, -0.189347, -0.596077, 0.636685, -0.189353, -0.747514, 0.465867, -0.189313, -0.864366, 0.280256, -0.189234, -0.941088, 0.092699, -0.189131, -0.977567, -0.093985, -0.093612, -0.991163, -0.284156, -0.093665, -0.954192, -0.472356, -0.093705, -0.876412, -0.645559, -0.093725, -0.757937, -0.791158, -0.093722, -0.604389, -0.899769, -0.093697, -0.426189, -0.967152, -0.093653, -0.236319, -0.994497, -0.093602, -0.047061, -0.985564, -0.093626, 0.141060, -0.938659, -0.093676, 0.331880, -0.850484, -0.093712, 0.517585, -0.722500, -0.093727, 0.684988, -0.561665, -0.093718, 0.822040, -0.379293, -0.093687, 0.920521, -0.188561, -0.093640, 0.977587, -0, -0.093598, 0.995610, 0.188560, -0.093640, 0.977587, 0.379293, -0.093687, 0.920521, 0.561664, -0.093718, 0.822040, 0.722500, -0.093727, 0.684988, 0.850484, -0.093712, 0.517586, 0.938658, -0.093676, 0.331881, 0.985564, -0.093626, 0.141061, 0.994497, -0.093602, -0.047060, 0.967152, -0.093653, -0.236317, 0.899770, -0.093697, -0.426187, 0.791159, -0.093722, -0.604387, 0.645561, -0.093725, -0.757936, 0.472359, -0.093705, -0.876411, 0.284158, -0.093665, -0.954191, 0.093988, -0.093612, -0.991162, -0.094400, -0, -0.995534, -0.285410, -0, -0.958405, -0.474444, -0, -0.880286, -0.648413, -0, -0.761289, -0.794656, -0, -0.607061, -0.903745, -0, -0.428072, -0.971421, -0, -0.237362, -0.998889, 0.000135, -0.047135, -0.989879, 0.000744, 0.141914, -0.942750, 0.001512, 0.333497, -0.854200, 0.001866, 0.519942, -0.725686, 0.001764, 0.688024, -0.564177, 0.001308, 0.825653, -0.381018, 0.000715, 0.924568, -0.189430, 0.000233, 0.981894, -0.000012, 0.000025, 1, 0.189393, -0, 0.981901, 0.380968, -0, 0.924588, 0.564147, -0, 0.825674, 0.725694, -0, 0.688017, 0.854243, -0, 0.519874, 0.942804, -0, 0.333347, 0.989912, -0, 0.141684, 0.998885, -0.000004, -0.047211, 0.971482, -0.000544, -0.237113, 0.903961, -0.002126, -0.427609, 0.795061, -0.004378, -0.606514, 0.648959, -0.006476, -0.760796, 0.475024, -0.007559, -0.879940, 0.285917, -0.007111, -0.958228, 0.094761, -0.005117, -0.995487, -0.093985, 0.093612, -0.991163, -0.284156, 0.093665, -0.954192, -0.472356, 0.093705, -0.876413, -0.645559, 0.093725, -0.757937, -0.791158, 0.093722, -0.604389, -0.899769, 0.093696, -0.426188, -0.967152, 0.093653, -0.236319, -0.994497, 0.093860, -0.046537, -0.985303, 0.095020, 0.141946, -0.938194, 0.096510, 0.332382, -0.850032, 0.097210, 0.517684, -0.722239, 0.097034, 0.684803, -0.561650, 0.096170, 0.821767, -0.379436, 0.095028, 0.920325, -0.188700, 0.094077, 0.977518, -0.000046, 0.093645, 0.995606, 0.188560, 0.093640, 0.977587, 0.379293, 0.093687, 0.920521, 0.561664, 0.093718, 0.822040, 0.722500, 0.093727, 0.684989, 0.850484, 0.093712, 0.517586, 0.938658, 0.093676, 0.331881, 0.985564, 0.093626, 0.141061, 0.994477, 0.093829, -0.047025, 0.967386, 0.093211, -0.235533, 0.901006, 0.090243, -0.424317, 0.793746, 0.085428, -0.602220, 0.649264, 0.080332, -0.756309, 0.476512, 0.076715, -0.875815, 0.288040, 0.075766, -0.954616, 0.097137, 0.077720, -0.992232, -0.092696, 0.189131, -0.977567, -0.280254, 0.189234, -0.941089, -0.465865, 0.189313, -0.864367, -0.636683, 0.189353, -0.747516, -0.780280, 0.189347, -0.596079, -0.887405, 0.189296, -0.420332, -0.953874, 0.189210, -0.233075, -0.980860, 0.189345, -0.045404, -0.971562, 0.190346, 0.140837, -0.924919, 0.191675, 0.328308, -0.837977, 0.192314, 0.510696, -0.712108, 0.192181, 0.675254, -0.553940, 0.191434, 0.810249, -0.374369, 0.190425, 0.907517, -0.186243, 0.189561, 0.964044, -0.000089, 0.189144, 0.981949, 0.185972, 0.189185, 0.964170, 0.374082, 0.189278, 0.907875, 0.553943, 0.189338, 0.810740, 0.712566, 0.189356, 0.675570, 0.838793, 0.189327, 0.510471, 0.925766, 0.189257, 0.327323, 0.972041, 0.189158, 0.139126, 0.980718, 0.189748, -0.046782, 0.954022, 0.189891, -0.231911, 0.889808, 0.187315, -0.416117, 0.786136, 0.182074, -0.590627, 0.645857, 0.175537, -0.743004, 0.477035, 0.169458, -0.862393, 0.291653, 0.165250, -0.942142, 0.102897, 0.163514, -0.981160, -0.090466, 0.285665, -0.954050, -0.273504, 0.285814, -0.918426, -0.454637, 0.285927, -0.843535, -0.621332, 0.285985, -0.729493, -0.761468, 0.285976, -0.581708, -0.866021, 0.285903, -0.410203, -0.930909, 0.285779, -0.227463, -0.957271, 0.285847, -0.043852, -0.948008, 0.286659, 0.138232, -0.902337, 0.287795, 0.320876, -0.817500, 0.288355, 0.498543, -0.694805, 0.288268, 0.658899, -0.540628, 0.287656, 0.790554, -0.365496, 0.286805, 0.885526, -0.181886, 0.286050, 0.940794, -0.000127, 0.285660, 0.958331, 0.181496, 0.285742, 0.940962, 0.365069, 0.285876, 0.886002, 0.540588, 0.285964, 0.791195, 0.695384, 0.285989, 0.659281, 0.818574, 0.285947, 0.498167, 0.903466, 0.285846, 0.319438, 0.948650, 0.285704, 0.135778, 0.956932, 0.286554, -0.046553, 0.930728, 0.287197, -0.226416, 0.869569, 0.285088, -0.403205, 0.771228, 0.279876, -0.571732, 0.637652, 0.272667, -0.720453, 0.475682, 0.265063, -0.838730, 0.296281, 0.258531, -0.919445, 0.112128, 0.253921, -0.960704, -0.087253, 0.381694, -0.920161, -0.263780, 0.381880, -0.885770, -0.438459, 0.382020, -0.813520, -0.599214, 0.382092, -0.703525, -0.734364, 0.382081, -0.561002, -0.835210, 0.381990, -0.395609, -0.897817, 0.381836, -0.219377, -0.923276, 0.381849, -0.041873, -0.914200, 0.382452, 0.134048, -0.870040, 0.383374, 0.309929, -0.788231, 0.383844, 0.480995, -0.670013, 0.383802, 0.635436, -0.521463, 0.383334, 0.762320, -0.352644, 0.382656, 0.853942, -0.175540, 0.382026, 0.907327, -0.000160, 0.381674, 0.924297, 0.175046, 0.381791, 0.907521, 0.352083, 0.381957, 0.854486, 0.521348, 0.382066, 0.763035, 0.670630, 0.382097, 0.635812, 0.789443, 0.382045, 0.480438, 0.871335, 0.381920, 0.308078, 0.914944, 0.381743, 0.130954, 0.922706, 0.382714, -0.046288, 0.897195, 0.383536, -0.218956, 0.839944, 0.381932, -0.385516, 0.748522, 0.377202, -0.545375, 0.623981, 0.370165, -0.688204, 0.471754, 0.362149, -0.803925, 0.301397, 0.354508, -0.885146, 0.124664, 0.348179, -0.929102, -0.083042, 0.475560, -0.875755, -0.251038, 0.475769, -0.842985, -0.417266, 0.475928, -0.774198, -0.570241, 0.476009, -0.669508, -0.698857, 0.475997, -0.533878, -0.794846, 0.475894, -0.376490, -0.854459, 0.475720, -0.208783, -0.878727, 0.475689, -0.039469, -0.869999, 0.476082, 0.128245, -0.827896, 0.476785, 0.295405, -0.750053, 0.477161, 0.457971, -0.637633, 0.477158, 0.604768, -0.496362, 0.476832, 0.725435, -0.335755, 0.476330, 0.812637, -0.167175, 0.475833, 0.863502, -0.000186, 0.475528, 0.879701, 0.166594, 0.475669, 0.863704, 0.335070, 0.475857, 0.813196, 0.496143, 0.475979, 0.726145, 0.638203, 0.476015, 0.605068, 0.751280, 0.475956, 0.457213, 0.829239, 0.475815, 0.293194, 0.870779, 0.475615, 0.124633, 0.877936, 0.476570, -0.045937, 0.853436, 0.477235, -0.209509, 0.800890, 0.476131, -0.363146, 0.717765, 0.472269, -0.511641, 0.604324, 0.466201, -0.646103, 0.464559, 0.458924, -0.757347, 0.306369, 0.451538, -0.838004, 0.140192, 0.444904, -0.884538, -0.077853, 0.565544, -0.821035, -0.235340, 0.565763, -0.790270, -0.391157, 0.565929, -0.725755, -0.534549, 0.566013, -0.627603, -0.655118, 0.566001, -0.500464, -0.745118, 0.565894, -0.352936, -0.801037, 0.565712, -0.195730, -0.823829, 0.565651, -0.036660, -0.815605, 0.565851, 0.120835, -0.776097, 0.566344, 0.277361, -0.703139, 0.566625, 0.429571, -0.597809, 0.566656, 0.567032, -0.465439, 0.566460, 0.680066, -0.314904, 0.566124, 0.761800, -0.156827, 0.565758, 0.809520, -0.000205, 0.565504, 0.824745, 0.156181, 0.565658, 0.809715, 0.314110, 0.565854, 0.762328, 0.465092, 0.565982, 0.680700, 0.598257, 0.566020, 0.567196, 0.704267, 0.565958, 0.428602, 0.777375, 0.565810, 0.274856, 0.816359, 0.565602, 0.116844, 0.822864, 0.566417, -0.045457, 0.799806, 0.566621, -0.198119, 0.752692, 0.565969, -0.336353, 0.678996, 0.563231, -0.470888, 0.578370, 0.558754, -0.594375, 0.453479, 0.553213, -0.698794, 0.310479, 0.547389, -0.777153, 0.158191, 0.541933, -0.825399, -0.071741, 0.649964, -0.756571, -0.216850, 0.650177, -0.728180, -0.360409, 0.650339, -0.668704, -0.492517, 0.650422, -0.578255, -0.603607, 0.650409, -0.461113, -0.686551, 0.650305, -0.325195, -0.738110, 0.650127, -0.180354, -0.759152, 0.650051, -0.033479, -0.751575, 0.650090, 0.111886, -0.715166, 0.650396, 0.255973, -0.647962, 0.650591, 0.396076, -0.550944, 0.650645, 0.522610, -0.429007, 0.650559, 0.626678, -0.290304, 0.650367, 0.701959, -0.144603, 0.650121, 0.745944, -0.000216, 0.649921, 0.760002, 0.143914, 0.650075, 0.746117, 0.289424, 0.650266, 0.702415, 0.428526, 0.650391, 0.627182, 0.551214, 0.650428, 0.522596, 0.648900, 0.650368, 0.394906, 0.716289, 0.650224, 0.253258, 0.752251, 0.650020, 0.107668, 0.758098, 0.650599, -0.044809, 0.736992, 0.650120, -0.184897, 0.695954, 0.649835, -0.305552, 0.632565, 0.648303, -0.423751, 0.546077, 0.645746, -0.533678, 0.438046, 0.642587, -0.628648, 0.312968, 0.639304, -0.702383, 0.177895, 0.636280, -0.750667, -0.064792, 0.727269, -0.683288, -0.195833, 0.727464, -0.657606, -0.325464, 0.727611, -0.603867, -0.444753, 0.727687, -0.522175, -0.545071, 0.727676, -0.416396, -0.619989, 0.727580, -0.293667, -0.666584, 0.727418, -0.162877, -0.685624, 0.727339, -0.029975, -0.678813, 0.727260, 0.101520, -0.645955, 0.727416, 0.231537, -0.585287, 0.727537, 0.357952, -0.497690, 0.727603, 0.472121, -0.387578, 0.727599, 0.566023, -0.262303, 0.727521, 0.633964, -0.130675, 0.727376, 0.673682, -0.000219, 0.727226, 0.686398, 0.129970, 0.727370, 0.673825, 0.261367, 0.727545, 0.634323, 0.386970, 0.727659, 0.566362, 0.497757, 0.727692, 0.471914, 0.585978, 0.727638, 0.356614, 0.646859, 0.727506, 0.228710, 0.679375, 0.727321, 0.097237, 0.684587, 0.727605, -0.043964, 0.665980, 0.726337, -0.170017, 0.631565, 0.726311, -0.271289, 0.579122, 0.725874, -0.371112, 0.507703, 0.725199, -0.465105, 0.418018, 0.724558, -0.547974, 0.313111, 0.724207, -0.614398, 0.198287, 0.724287, -0.660371, -0.057123, 0.796134, -0.602418, -0.172645, 0.796300, -0.579742, -0.286914, 0.796425, -0.532342, -0.392065, 0.796489, -0.460315, -0.480500, 0.796480, -0.367068, -0.546559, 0.796399, -0.258886, -0.587664, 0.796261, -0.143593, -0.604482, 0.796188, -0.026206, -0.598530, 0.796039, 0.089907, -0.569601, 0.796086, 0.204452, -0.516141, 0.796150, 0.315821, -0.438923, 0.796219, 0.416393, -0.341837, 0.796267, 0.499105, -0.231367, 0.796268, 0.558951, -0.115277, 0.796200, 0.593950, -0.000213, 0.796096, 0.605170, 0.114584, 0.796220, 0.594057, 0.230414, 0.796369, 0.559201, 0.341130, 0.796466, 0.499272, 0.438789, 0.796494, 0.416007, 0.516567, 0.796448, 0.314372, 0.570260, 0.796336, 0.201627, 0.598959, 0.796178, 0.085728, 0.603578, 0.796149, -0.042899, 0.587998, 0.794125, -0.153703, 0.560646, 0.794242, -0.234212, 0.519579, 0.794613, -0.314052, 0.463805, 0.795411, -0.390137, 0.393434, 0.796848, -0.458521, 0.310320, 0.799068, -0.514968, 0.218174, 0.802059, -0.555969, -0.048876, 0.855532, -0.515439, -0.147710, 0.855662, -0.496009, -0.245464, 0.855761, -0.455435, -0.335417, 0.855811, -0.393806, -0.411076, 0.855804, -0.314033, -0.467603, 0.855740, -0.221487, -0.502794, 0.855631, -0.122855, -0.517208, 0.855571, -0.022241, -0.512175, 0.855399, 0.077259, -0.487472, 0.855379, 0.175206, -0.441757, 0.855404, 0.270435, -0.375689, 0.855466, 0.356421, -0.292605, 0.855538, 0.427126, -0.198058, 0.855584, 0.478277, -0.098690, 0.855567, 0.508198, -0.000199, 0.855500, 0.517802, 0.098037, 0.855599, 0.508270, 0.197130, 0.855716, 0.478424, 0.291844, 0.855793, 0.427137, 0.375389, 0.855815, 0.355899, 0.441937, 0.855778, 0.268953, 0.487890, 0.855690, 0.172503, 0.512471, 0.855566, 0.073349, 0.516546, 0.855248, -0.041603, 0.504445, 0.852632, -0.136216, 0.484480, 0.852785, -0.195030, 0.455044, 0.853541, -0.253777, 0.415195, 0.855093, -0.310531, 0.364624, 0.857653, -0.362603, 0.304227, 0.861343, -0.406859, 0.236332, 0.866110, -0.440455, -0.040203, 0.904780, -0.423977, -0.121494, 0.904873, -0.407975, -0.201891, 0.904944, -0.374588, -0.275870, 0.904980, -0.323893, -0.338098, 0.904975, -0.258283, -0.384600, 0.904929, -0.182171, -0.413560, 0.904852, -0.101052, -0.425435, 0.904807, -0.018152, -0.421352, 0.904649, 0.063813, -0.401080, 0.904600, 0.144339, -0.363501, 0.904601, 0.222629, -0.309154, 0.904651, 0.293311, -0.240792, 0.904724, 0.351416, -0.162994, 0.904785, 0.393443, -0.081224, 0.904796, 0.418028, -0.000176, 0.904757, 0.425928, 0.080639, 0.904829, 0.418070, 0.162139, 0.904912, 0.393503, 0.240034, 0.904967, 0.351309, 0.308745, 0.904983, 0.292716, 0.363484, 0.904957, 0.221208, 0.401293, 0.904894, 0.141885, 0.421531, 0.904805, 0.060333, 0.425107, 0.904256, -0.040073, 0.416812, 0.901322, -0.117837, 0.404436, 0.901426, -0.154473, 0.386746, 0.902076, -0.191539, 0.362875, 0.903469, -0.228178, 0.332181, 0.905845, -0.262869, 0.294750, 0.909373, -0.293536, 0.251699, 0.914053, -0.318049, -0.031265, 0.943561, -0.329719, -0.094480, 0.943620, -0.317261, -0.156995, 0.943665, -0.291289, -0.214520, 0.943687, -0.251864, -0.262910, 0.943684, -0.200845, -0.299076, 0.943655, -0.141662, -0.321608, 0.943606, -0.078583, -0.330855, 0.943578, -0.014011, -0.327726, 0.943458, 0.049823, -0.312001, 0.943408, 0.112418, -0.282795, 0.943399, 0.173276, -0.240528, 0.943433, 0.228210, -0.187346, 0.943492, 0.273358, -0.126819, 0.943546, 0.306004, -0.063201, 0.943565, 0.325100, -0.000147, 0.943546, 0.331240, 0.062710, 0.943592, 0.325118, 0.126085, 0.943645, 0.306002, 0.186655, 0.943679, 0.273184, 0.240084, 0.943689, 0.227619, 0.282652, 0.943673, 0.172016, 0.312062, 0.943633, 0.110336, 0.327813, 0.943577, 0.046919, 0.330925, 0.942879, -0.038315, 0.326611, 0.939975, -0.098856, 0.321898, 0.939976, -0.113258, 0.315952, 0.940025, -0.128559, 0.307943, 0.940298, -0.144951, 0.296882, 0.941068, -0.162023, 0.282085, 0.942600, -0.178696, 0.263549, 0.945036, -0.193516, -0.022219, 0.971907, -0.234314, -0.067140, 0.971938, -0.225455, -0.111562, 0.971961, -0.206993, -0.152438, 0.971973, -0.178975, -0.186825, 0.971971, -0.142721, -0.212528, 0.971956, -0.100667, -0.228545, 0.971930, -0.055844, -0.235124, 0.971915, -0.009885, -0.232931, 0.971844, 0.035539, -0.221784, 0.971808, 0.080004, -0.201043, 0.971800, 0.123235, -0.171004, 0.971819, 0.162253, -0.133197, 0.971855, 0.194311, -0.090167, 0.971890, 0.217484, -0.044937, 0.971906, 0.231038, -0.000111, 0.971899, 0.235398, 0.044564, 0.971923, 0.231041, 0.089599, 0.971950, 0.217450, 0.132638, 0.971968, 0.194126, 0.170604, 0.971973, 0.161747, 0.200855, 0.971965, 0.122236, 0.221759, 0.971944, 0.078407, 0.232958, 0.971915, 0.033343, 0.235622, 0.971165, -0.036342, 0.235300, 0.968661, -0.079559, 0.238201, 0.968539, -0.072054, 0.243893, 0.967556, -0.065963, 0.251501, 0.965833, -0.062565, 0.259595, 0.963690, -0.062550, 0.266657, 0.961545, -0.065772, 0.271568, 0.959770, -0.071364, -0.013209, 0.990162, -0.139300, -0.039914, 0.990173, -0.134030, -0.066321, 0.990181, -0.123053, -0.090621, 0.990186, -0.106396, -0.111063, 0.990185, -0.084844, -0.126344, 0.990180, -0.059844, -0.135868, 0.990171, -0.033199, -0.139782, 0.990165, -0.005838, -0.138494, 0.990136, 0.021201, -0.131883, 0.990120, 0.047625, -0.119561, 0.990116, 0.073316, -0.101702, 0.990123, 0.096501, -0.079219, 0.990138, 0.115545, -0.053628, 0.990153, 0.129307, -0.026728, 0.990161, 0.137356, -0.000069, 0.990159, 0.139945, 0.026493, 0.990168, 0.137352, 0.053265, 0.990178, 0.129271, 0.078850, 0.990184, 0.115403, 0.101419, 0.990186, 0.096154, 0.119404, 0.990183, 0.072666, 0.131832, 0.990176, 0.046612, 0.138493, 0.990165, 0.019822, 0.140709, 0.989461, -0.034175, 0.144232, 0.987710, -0.060213, 0.154580, 0.987479, -0.031460, 0.171707, 0.985137, -0.004734, 0.194579, 0.980730, 0.017517, 0.221177, 0.974659, 0.033481, 0.249023, 0.967567, 0.042436, 0.275826, 0.960163, 0.044797 };
    Normal1.vector = m_vector;
    Normal1.vector_length = sizeof(m_vector) / sizeof(float);
    }
    TextureCoordinate1.m_parent = (X3dNode *)&NurbsSurface1;
    {
    static float m_point[] = { 0, 0, 0.032258, 0, 0.064516, 0, 0.096774, 0, 0.129032, 0, 0.161290, 0, 0.193548, 0, 0.225806, 0, 0.258065, 0, 0.290323, 0, 0.322581, 0, 0.354839, 0, 0.387097, 0, 0.419355, 0, 0.451613, 0, 0.483871, 0, 0.516129, 0, 0.548387, 0, 0.580645, 0, 0.612903, 0, 0.645161, 0, 0.677419, 0, 0.709677, 0, 0.741935, 0, 0.774194, 0, 0.806452, 0, 0.838710, 0, 0.870968, 0, 0.903226, 0, 0.935484, 0, 0.967742, 0, 1, 0, 0, 0.032258, 0.032258, 0.032258, 0.064516, 0.032258, 0.096774, 0.032258, 0.129032, 0.032258, 0.161290, 0.032258, 0.193548, 0.032258, 0.225806, 0.032258, 0.258065, 0.032258, 0.290323, 0.032258, 0.322581, 0.032258, 0.354839, 0.032258, 0.387097, 0.032258, 0.419355, 0.032258, 0.451613, 0.032258, 0.483871, 0.032258, 0.516129, 0.032258, 0.548387, 0.032258, 0.580645, 0.032258, 0.612903, 0.032258, 0.645161, 0.032258, 0.677419, 0.032258, 0.709677, 0.032258, 0.741935, 0.032258, 0.774194, 0.032258, 0.806452, 0.032258, 0.838710, 0.032258, 0.870968, 0.032258, 0.903226, 0.032258, 0.935484, 0.032258, 0.967742, 0.032258, 1, 0.032258, 0, 0.064516, 0.032258, 0.064516, 0.064516, 0.064516, 0.096774, 0.064516, 0.129032, 0.064516, 0.161290, 0.064516, 0.193548, 0.064516, 0.225806, 0.064516, 0.258065, 0.064516, 0.290323, 0.064516, 0.322581, 0.064516, 0.354839, 0.064516, 0.387097, 0.064516, 0.419355, 0.064516, 0.451613, 0.064516, 0.483871, 0.064516, 0.516129, 0.064516, 0.548387, 0.064516, 0.580645, 0.064516, 0.612903, 0.064516, 0.645161, 0.064516, 0.677419, 0.064516, 0.709677, 0.064516, 0.741935, 0.064516, 0.774194, 0.064516, 0.806452, 0.064516, 0.838710, 0.064516, 0.870968, 0.064516, 0.903226, 0.064516, 0.935484, 0.064516, 0.967742, 0.064516, 1, 0.064516, 0, 0.096774, 0.032258, 0.096774, 0.064516, 0.096774, 0.096774, 0.096774, 0.129032, 0.096774, 0.161290, 0.096774, 0.193548, 0.096774, 0.225806, 0.096774, 0.258065, 0.096774, 0.290323, 0.096774, 0.322581, 0.096774, 0.354839, 0.096774, 0.387097, 0.096774, 0.419355, 0.096774, 0.451613, 0.096774, 0.483871, 0.096774, 0.516129, 0.096774, 0.548387, 0.096774, 0.580645, 0.096774, 0.612903, 0.096774, 0.645161, 0.096774, 0.677419, 0.096774, 0.709677, 0.096774, 0.741935, 0.096774, 0.774194, 0.096774, 0.806452, 0.096774, 0.838710, 0.096774, 0.870968, 0.096774, 0.903226, 0.096774, 0.935484, 0.096774, 0.967742, 0.096774, 1, 0.096774, 0, 0.129032, 0.032258, 0.129032, 0.064516, 0.129032, 0.096774, 0.129032, 0.129032, 0.129032, 0.161290, 0.129032, 0.193548, 0.129032, 0.225806, 0.129032, 0.258065, 0.129032, 0.290323, 0.129032, 0.322581, 0.129032, 0.354839, 0.129032, 0.387097, 0.129032, 0.419355, 0.129032, 0.451613, 0.129032, 0.483871, 0.129032, 0.516129, 0.129032, 0.548387, 0.129032, 0.580645, 0.129032, 0.612903, 0.129032, 0.645161, 0.129032, 0.677419, 0.129032, 0.709677, 0.129032, 0.741935, 0.129032, 0.774194, 0.129032, 0.806452, 0.129032, 0.838710, 0.129032, 0.870968, 0.129032, 0.903226, 0.129032, 0.935484, 0.129032, 0.967742, 0.129032, 1, 0.129032, 0, 0.161290, 0.032258, 0.161290, 0.064516, 0.161290, 0.096774, 0.161290, 0.129032, 0.161290, 0.161290, 0.161290, 0.193548, 0.161290, 0.225806, 0.161290, 0.258065, 0.161290, 0.290323, 0.161290, 0.322581, 0.161290, 0.354839, 0.161290, 0.387097, 0.161290, 0.419355, 0.161290, 0.451613, 0.161290, 0.483871, 0.161290, 0.516129, 0.161290, 0.548387, 0.161290, 0.580645, 0.161290, 0.612903, 0.161290, 0.645161, 0.161290, 0.677419, 0.161290, 0.709677, 0.161290, 0.741935, 0.161290, 0.774194, 0.161290, 0.806452, 0.161290, 0.838710, 0.161290, 0.870968, 0.161290, 0.903226, 0.161290, 0.935484, 0.161290, 0.967742, 0.161290, 1, 0.161290, 0, 0.193548, 0.032258, 0.193548, 0.064516, 0.193548, 0.096774, 0.193548, 0.129032, 0.193548, 0.161290, 0.193548, 0.193548, 0.193548, 0.225806, 0.193548, 0.258065, 0.193548, 0.290323, 0.193548, 0.322581, 0.193548, 0.354839, 0.193548, 0.387097, 0.193548, 0.419355, 0.193548, 0.451613, 0.193548, 0.483871, 0.193548, 0.516129, 0.193548, 0.548387, 0.193548, 0.580645, 0.193548, 0.612903, 0.193548, 0.645161, 0.193548, 0.677419, 0.193548, 0.709677, 0.193548, 0.741935, 0.193548, 0.774194, 0.193548, 0.806452, 0.193548, 0.838710, 0.193548, 0.870968, 0.193548, 0.903226, 0.193548, 0.935484, 0.193548, 0.967742, 0.193548, 1, 0.193548, 0, 0.225806, 0.032258, 0.225806, 0.064516, 0.225806, 0.096774, 0.225806, 0.129032, 0.225806, 0.161290, 0.225806, 0.193548, 0.225806, 0.225806, 0.225806, 0.258065, 0.225806, 0.290323, 0.225806, 0.322581, 0.225806, 0.354839, 0.225806, 0.387097, 0.225806, 0.419355, 0.225806, 0.451613, 0.225806, 0.483871, 0.225806, 0.516129, 0.225806, 0.548387, 0.225806, 0.580645, 0.225806, 0.612903, 0.225806, 0.645161, 0.225806, 0.677419, 0.225806, 0.709677, 0.225806, 0.741935, 0.225806, 0.774194, 0.225806, 0.806452, 0.225806, 0.838710, 0.225806, 0.870968, 0.225806, 0.903226, 0.225806, 0.935484, 0.225806, 0.967742, 0.225806, 1, 0.225806, 0, 0.258065, 0.032258, 0.258065, 0.064516, 0.258065, 0.096774, 0.258065, 0.129032, 0.258065, 0.161290, 0.258065, 0.193548, 0.258065, 0.225806, 0.258065, 0.258065, 0.258065, 0.290323, 0.258065, 0.322581, 0.258065, 0.354839, 0.258065, 0.387097, 0.258065, 0.419355, 0.258065, 0.451613, 0.258065, 0.483871, 0.258065, 0.516129, 0.258065, 0.548387, 0.258065, 0.580645, 0.258065, 0.612903, 0.258065, 0.645161, 0.258065, 0.677419, 0.258065, 0.709677, 0.258065, 0.741935, 0.258065, 0.774194, 0.258065, 0.806452, 0.258065, 0.838710, 0.258065, 0.870968, 0.258065, 0.903226, 0.258065, 0.935484, 0.258065, 0.967742, 0.258065, 1, 0.258065, 0, 0.290323, 0.032258, 0.290323, 0.064516, 0.290323, 0.096774, 0.290323, 0.129032, 0.290323, 0.161290, 0.290323, 0.193548, 0.290323, 0.225806, 0.290323, 0.258065, 0.290323, 0.290323, 0.290323, 0.322581, 0.290323, 0.354839, 0.290323, 0.387097, 0.290323, 0.419355, 0.290323, 0.451613, 0.290323, 0.483871, 0.290323, 0.516129, 0.290323, 0.548387, 0.290323, 0.580645, 0.290323, 0.612903, 0.290323, 0.645161, 0.290323, 0.677419, 0.290323, 0.709677, 0.290323, 0.741935, 0.290323, 0.774194, 0.290323, 0.806452, 0.290323, 0.838710, 0.290323, 0.870968, 0.290323, 0.903226, 0.290323, 0.935484, 0.290323, 0.967742, 0.290323, 1, 0.290323, 0, 0.322581, 0.032258, 0.322581, 0.064516, 0.322581, 0.096774, 0.322581, 0.129032, 0.322581, 0.161290, 0.322581, 0.193548, 0.322581, 0.225806, 0.322581, 0.258065, 0.322581, 0.290323, 0.322581, 0.322581, 0.322581, 0.354839, 0.322581, 0.387097, 0.322581, 0.419355, 0.322581, 0.451613, 0.322581, 0.483871, 0.322581, 0.516129, 0.322581, 0.548387, 0.322581, 0.580645, 0.322581, 0.612903, 0.322581, 0.645161, 0.322581, 0.677419, 0.322581, 0.709677, 0.322581, 0.741935, 0.322581, 0.774194, 0.322581, 0.806452, 0.322581, 0.838710, 0.322581, 0.870968, 0.322581, 0.903226, 0.322581, 0.935484, 0.322581, 0.967742, 0.322581, 1, 0.322581, 0, 0.354839, 0.032258, 0.354839, 0.064516, 0.354839, 0.096774, 0.354839, 0.129032, 0.354839, 0.161290, 0.354839, 0.193548, 0.354839, 0.225806, 0.354839, 0.258065, 0.354839, 0.290323, 0.354839, 0.322581, 0.354839, 0.354839, 0.354839, 0.387097, 0.354839, 0.419355, 0.354839, 0.451613, 0.354839, 0.483871, 0.354839, 0.516129, 0.354839, 0.548387, 0.354839, 0.580645, 0.354839, 0.612903, 0.354839, 0.645161, 0.354839, 0.677419, 0.354839, 0.709677, 0.354839, 0.741935, 0.354839, 0.774194, 0.354839, 0.806452, 0.354839, 0.838710, 0.354839, 0.870968, 0.354839, 0.903226, 0.354839, 0.935484, 0.354839, 0.967742, 0.354839, 1, 0.354839, 0, 0.387097, 0.032258, 0.387097, 0.064516, 0.387097, 0.096774, 0.387097, 0.129032, 0.387097, 0.161290, 0.387097, 0.193548, 0.387097, 0.225806, 0.387097, 0.258065, 0.387097, 0.290323, 0.387097, 0.322581, 0.387097, 0.354839, 0.387097, 0.387097, 0.387097, 0.419355, 0.387097, 0.451613, 0.387097, 0.483871, 0.387097, 0.516129, 0.387097, 0.548387, 0.387097, 0.580645, 0.387097, 0.612903, 0.387097, 0.645161, 0.387097, 0.677419, 0.387097, 0.709677, 0.387097, 0.741935, 0.387097, 0.774194, 0.387097, 0.806452, 0.387097, 0.838710, 0.387097, 0.870968, 0.387097, 0.903226, 0.387097, 0.935484, 0.387097, 0.967742, 0.387097, 1, 0.387097, 0, 0.419355, 0.032258, 0.419355, 0.064516, 0.419355, 0.096774, 0.419355, 0.129032, 0.419355, 0.161290, 0.419355, 0.193548, 0.419355, 0.225806, 0.419355, 0.258065, 0.419355, 0.290323, 0.419355, 0.322581, 0.419355, 0.354839, 0.419355, 0.387097, 0.419355, 0.419355, 0.419355, 0.451613, 0.419355, 0.483871, 0.419355, 0.516129, 0.419355, 0.548387, 0.419355, 0.580645, 0.419355, 0.612903, 0.419355, 0.645161, 0.419355, 0.677419, 0.419355, 0.709677, 0.419355, 0.741935, 0.419355, 0.774194, 0.419355, 0.806452, 0.419355, 0.838710, 0.419355, 0.870968, 0.419355, 0.903226, 0.419355, 0.935484, 0.419355, 0.967742, 0.419355, 1, 0.419355, 0, 0.451613, 0.032258, 0.451613, 0.064516, 0.451613, 0.096774, 0.451613, 0.129032, 0.451613, 0.161290, 0.451613, 0.193548, 0.451613, 0.225806, 0.451613, 0.258065, 0.451613, 0.290323, 0.451613, 0.322581, 0.451613, 0.354839, 0.451613, 0.387097, 0.451613, 0.419355, 0.451613, 0.451613, 0.451613, 0.483871, 0.451613, 0.516129, 0.451613, 0.548387, 0.451613, 0.580645, 0.451613, 0.612903, 0.451613, 0.645161, 0.451613, 0.677419, 0.451613, 0.709677, 0.451613, 0.741935, 0.451613, 0.774194, 0.451613, 0.806452, 0.451613, 0.838710, 0.451613, 0.870968, 0.451613, 0.903226, 0.451613, 0.935484, 0.451613, 0.967742, 0.451613, 1, 0.451613, 0, 0.483871, 0.032258, 0.483871, 0.064516, 0.483871, 0.096774, 0.483871, 0.129032, 0.483871, 0.161290, 0.483871, 0.193548, 0.483871, 0.225806, 0.483871, 0.258065, 0.483871, 0.290323, 0.483871, 0.322581, 0.483871, 0.354839, 0.483871, 0.387097, 0.483871, 0.419355, 0.483871, 0.451613, 0.483871, 0.483871, 0.483871, 0.516129, 0.483871, 0.548387, 0.483871, 0.580645, 0.483871, 0.612903, 0.483871, 0.645161, 0.483871, 0.677419, 0.483871, 0.709677, 0.483871, 0.741935, 0.483871, 0.774194, 0.483871, 0.806452, 0.483871, 0.838710, 0.483871, 0.870968, 0.483871, 0.903226, 0.483871, 0.935484, 0.483871, 0.967742, 0.483871, 1, 0.483871, 0, 0.516129, 0.032258, 0.516129, 0.064516, 0.516129, 0.096774, 0.516129, 0.129032, 0.516129, 0.161290, 0.516129, 0.193548, 0.516129, 0.225806, 0.516129, 0.258065, 0.516129, 0.290323, 0.516129, 0.322581, 0.516129, 0.354839, 0.516129, 0.387097, 0.516129, 0.419355, 0.516129, 0.451613, 0.516129, 0.483871, 0.516129, 0.516129, 0.516129, 0.548387, 0.516129, 0.580645, 0.516129, 0.612903, 0.516129, 0.645161, 0.516129, 0.677419, 0.516129, 0.709677, 0.516129, 0.741935, 0.516129, 0.774194, 0.516129, 0.806452, 0.516129, 0.838710, 0.516129, 0.870968, 0.516129, 0.903226, 0.516129, 0.935484, 0.516129, 0.967742, 0.516129, 1, 0.516129, 0, 0.548387, 0.032258, 0.548387, 0.064516, 0.548387, 0.096774, 0.548387, 0.129032, 0.548387, 0.161290, 0.548387, 0.193548, 0.548387, 0.225806, 0.548387, 0.258065, 0.548387, 0.290323, 0.548387, 0.322581, 0.548387, 0.354839, 0.548387, 0.387097, 0.548387, 0.419355, 0.548387, 0.451613, 0.548387, 0.483871, 0.548387, 0.516129, 0.548387, 0.548387, 0.548387, 0.580645, 0.548387, 0.612903, 0.548387, 0.645161, 0.548387, 0.677419, 0.548387, 0.709677, 0.548387, 0.741935, 0.548387, 0.774194, 0.548387, 0.806452, 0.548387, 0.838710, 0.548387, 0.870968, 0.548387, 0.903226, 0.548387, 0.935484, 0.548387, 0.967742, 0.548387, 1, 0.548387, 0, 0.580645, 0.032258, 0.580645, 0.064516, 0.580645, 0.096774, 0.580645, 0.129032, 0.580645, 0.161290, 0.580645, 0.193548, 0.580645, 0.225806, 0.580645, 0.258065, 0.580645, 0.290323, 0.580645, 0.322581, 0.580645, 0.354839, 0.580645, 0.387097, 0.580645, 0.419355, 0.580645, 0.451613, 0.580645, 0.483871, 0.580645, 0.516129, 0.580645, 0.548387, 0.580645, 0.580645, 0.580645, 0.612903, 0.580645, 0.645161, 0.580645, 0.677419, 0.580645, 0.709677, 0.580645, 0.741935, 0.580645, 0.774194, 0.580645, 0.806452, 0.580645, 0.838710, 0.580645, 0.870968, 0.580645, 0.903226, 0.580645, 0.935484, 0.580645, 0.967742, 0.580645, 1, 0.580645, 0, 0.612903, 0.032258, 0.612903, 0.064516, 0.612903, 0.096774, 0.612903, 0.129032, 0.612903, 0.161290, 0.612903, 0.193548, 0.612903, 0.225806, 0.612903, 0.258065, 0.612903, 0.290323, 0.612903, 0.322581, 0.612903, 0.354839, 0.612903, 0.387097, 0.612903, 0.419355, 0.612903, 0.451613, 0.612903, 0.483871, 0.612903, 0.516129, 0.612903, 0.548387, 0.612903, 0.580645, 0.612903, 0.612903, 0.612903, 0.645161, 0.612903, 0.677419, 0.612903, 0.709677, 0.612903, 0.741935, 0.612903, 0.774194, 0.612903, 0.806452, 0.612903, 0.838710, 0.612903, 0.870968, 0.612903, 0.903226, 0.612903, 0.935484, 0.612903, 0.967742, 0.612903, 1, 0.612903, 0, 0.645161, 0.032258, 0.645161, 0.064516, 0.645161, 0.096774, 0.645161, 0.129032, 0.645161, 0.161290, 0.645161, 0.193548, 0.645161, 0.225806, 0.645161, 0.258065, 0.645161, 0.290323, 0.645161, 0.322581, 0.645161, 0.354839, 0.645161, 0.387097, 0.645161, 0.419355, 0.645161, 0.451613, 0.645161, 0.483871, 0.645161, 0.516129, 0.645161, 0.548387, 0.645161, 0.580645, 0.645161, 0.612903, 0.645161, 0.645161, 0.645161, 0.677419, 0.645161, 0.709677, 0.645161, 0.741935, 0.645161, 0.774194, 0.645161, 0.806452, 0.645161, 0.838710, 0.645161, 0.870968, 0.645161, 0.903226, 0.645161, 0.935484, 0.645161, 0.967742, 0.645161, 1, 0.645161, 0, 0.677419, 0.032258, 0.677419, 0.064516, 0.677419, 0.096774, 0.677419, 0.129032, 0.677419, 0.161290, 0.677419, 0.193548, 0.677419, 0.225806, 0.677419, 0.258065, 0.677419, 0.290323, 0.677419, 0.322581, 0.677419, 0.354839, 0.677419, 0.387097, 0.677419, 0.419355, 0.677419, 0.451613, 0.677419, 0.483871, 0.677419, 0.516129, 0.677419, 0.548387, 0.677419, 0.580645, 0.677419, 0.612903, 0.677419, 0.645161, 0.677419, 0.677419, 0.677419, 0.709677, 0.677419, 0.741935, 0.677419, 0.774194, 0.677419, 0.806452, 0.677419, 0.838710, 0.677419, 0.870968, 0.677419, 0.903226, 0.677419, 0.935484, 0.677419, 0.967742, 0.677419, 1, 0.677419, 0, 0.709677, 0.032258, 0.709677, 0.064516, 0.709677, 0.096774, 0.709677, 0.129032, 0.709677, 0.161290, 0.709677, 0.193548, 0.709677, 0.225806, 0.709677, 0.258065, 0.709677, 0.290323, 0.709677, 0.322581, 0.709677, 0.354839, 0.709677, 0.387097, 0.709677, 0.419355, 0.709677, 0.451613, 0.709677, 0.483871, 0.709677, 0.516129, 0.709677, 0.548387, 0.709677, 0.580645, 0.709677, 0.612903, 0.709677, 0.645161, 0.709677, 0.677419, 0.709677, 0.709677, 0.709677, 0.741935, 0.709677, 0.774194, 0.709677, 0.806452, 0.709677, 0.838710, 0.709677, 0.870968, 0.709677, 0.903226, 0.709677, 0.935484, 0.709677, 0.967742, 0.709677, 1, 0.709677, 0, 0.741935, 0.032258, 0.741935, 0.064516, 0.741935, 0.096774, 0.741935, 0.129032, 0.741935, 0.161290, 0.741935, 0.193548, 0.741935, 0.225806, 0.741935, 0.258065, 0.741935, 0.290323, 0.741935, 0.322581, 0.741935, 0.354839, 0.741935, 0.387097, 0.741935, 0.419355, 0.741935, 0.451613, 0.741935, 0.483871, 0.741935, 0.516129, 0.741935, 0.548387, 0.741935, 0.580645, 0.741935, 0.612903, 0.741935, 0.645161, 0.741935, 0.677419, 0.741935, 0.709677, 0.741935, 0.741935, 0.741935, 0.774194, 0.741935, 0.806452, 0.741935, 0.838710, 0.741935, 0.870968, 0.741935, 0.903226, 0.741935, 0.935484, 0.741935, 0.967742, 0.741935, 1, 0.741935, 0, 0.774194, 0.032258, 0.774194, 0.064516, 0.774194, 0.096774, 0.774194, 0.129032, 0.774194, 0.161290, 0.774194, 0.193548, 0.774194, 0.225806, 0.774194, 0.258065, 0.774194, 0.290323, 0.774194, 0.322581, 0.774194, 0.354839, 0.774194, 0.387097, 0.774194, 0.419355, 0.774194, 0.451613, 0.774194, 0.483871, 0.774194, 0.516129, 0.774194, 0.548387, 0.774194, 0.580645, 0.774194, 0.612903, 0.774194, 0.645161, 0.774194, 0.677419, 0.774194, 0.709677, 0.774194, 0.741935, 0.774194, 0.774194, 0.774194, 0.806452, 0.774194, 0.838710, 0.774194, 0.870968, 0.774194, 0.903226, 0.774194, 0.935484, 0.774194, 0.967742, 0.774194, 1, 0.774194, 0, 0.806452, 0.032258, 0.806452, 0.064516, 0.806452, 0.096774, 0.806452, 0.129032, 0.806452, 0.161290, 0.806452, 0.193548, 0.806452, 0.225806, 0.806452, 0.258065, 0.806452, 0.290323, 0.806452, 0.322581, 0.806452, 0.354839, 0.806452, 0.387097, 0.806452, 0.419355, 0.806452, 0.451613, 0.806452, 0.483871, 0.806452, 0.516129, 0.806452, 0.548387, 0.806452, 0.580645, 0.806452, 0.612903, 0.806452, 0.645161, 0.806452, 0.677419, 0.806452, 0.709677, 0.806452, 0.741935, 0.806452, 0.774194, 0.806452, 0.806452, 0.806452, 0.838710, 0.806452, 0.870968, 0.806452, 0.903226, 0.806452, 0.935484, 0.806452, 0.967742, 0.806452, 1, 0.806452, 0, 0.838710, 0.032258, 0.838710, 0.064516, 0.838710, 0.096774, 0.838710, 0.129032, 0.838710, 0.161290, 0.838710, 0.193548, 0.838710, 0.225806, 0.838710, 0.258065, 0.838710, 0.290323, 0.838710, 0.322581, 0.838710, 0.354839, 0.838710, 0.387097, 0.838710, 0.419355, 0.838710, 0.451613, 0.838710, 0.483871, 0.838710, 0.516129, 0.838710, 0.548387, 0.838710, 0.580645, 0.838710, 0.612903, 0.838710, 0.645161, 0.838710, 0.677419, 0.838710, 0.709677, 0.838710, 0.741935, 0.838710, 0.774194, 0.838710, 0.806452, 0.838710, 0.838710, 0.838710, 0.870968, 0.838710, 0.903226, 0.838710, 0.935484, 0.838710, 0.967742, 0.838710, 1, 0.838710, 0, 0.870968, 0.032258, 0.870968, 0.064516, 0.870968, 0.096774, 0.870968, 0.129032, 0.870968, 0.161290, 0.870968, 0.193548, 0.870968, 0.225806, 0.870968, 0.258065, 0.870968, 0.290323, 0.870968, 0.322581, 0.870968, 0.354839, 0.870968, 0.387097, 0.870968, 0.419355, 0.870968, 0.451613, 0.870968, 0.483871, 0.870968, 0.516129, 0.870968, 0.548387, 0.870968, 0.580645, 0.870968, 0.612903, 0.870968, 0.645161, 0.870968, 0.677419, 0.870968, 0.709677, 0.870968, 0.741935, 0.870968, 0.774194, 0.870968, 0.806452, 0.870968, 0.838710, 0.870968, 0.870968, 0.870968, 0.903226, 0.870968, 0.935484, 0.870968, 0.967742, 0.870968, 1, 0.870968, 0, 0.903226, 0.032258, 0.903226, 0.064516, 0.903226, 0.096774, 0.903226, 0.129032, 0.903226, 0.161290, 0.903226, 0.193548, 0.903226, 0.225806, 0.903226, 0.258065, 0.903226, 0.290323, 0.903226, 0.322581, 0.903226, 0.354839, 0.903226, 0.387097, 0.903226, 0.419355, 0.903226, 0.451613, 0.903226, 0.483871, 0.903226, 0.516129, 0.903226, 0.548387, 0.903226, 0.580645, 0.903226, 0.612903, 0.903226, 0.645161, 0.903226, 0.677419, 0.903226, 0.709677, 0.903226, 0.741935, 0.903226, 0.774194, 0.903226, 0.806452, 0.903226, 0.838710, 0.903226, 0.870968, 0.903226, 0.903226, 0.903226, 0.935484, 0.903226, 0.967742, 0.903226, 1, 0.903226, 0, 0.935484, 0.032258, 0.935484, 0.064516, 0.935484, 0.096774, 0.935484, 0.129032, 0.935484, 0.161290, 0.935484, 0.193548, 0.935484, 0.225806, 0.935484, 0.258065, 0.935484, 0.290323, 0.935484, 0.322581, 0.935484, 0.354839, 0.935484, 0.387097, 0.935484, 0.419355, 0.935484, 0.451613, 0.935484, 0.483871, 0.935484, 0.516129, 0.935484, 0.548387, 0.935484, 0.580645, 0.935484, 0.612903, 0.935484, 0.645161, 0.935484, 0.677419, 0.935484, 0.709677, 0.935484, 0.741935, 0.935484, 0.774194, 0.935484, 0.806452, 0.935484, 0.838710, 0.935484, 0.870968, 0.935484, 0.903226, 0.935484, 0.935484, 0.935484, 0.967742, 0.935484, 1, 0.935484, 0, 0.967742, 0.032258, 0.967742, 0.064516, 0.967742, 0.096774, 0.967742, 0.129032, 0.967742, 0.161290, 0.967742, 0.193548, 0.967742, 0.225806, 0.967742, 0.258065, 0.967742, 0.290323, 0.967742, 0.322581, 0.967742, 0.354839, 0.967742, 0.387097, 0.967742, 0.419355, 0.967742, 0.451613, 0.967742, 0.483871, 0.967742, 0.516129, 0.967742, 0.548387, 0.967742, 0.580645, 0.967742, 0.612903, 0.967742, 0.645161, 0.967742, 0.677419, 0.967742, 0.709677, 0.967742, 0.741935, 0.967742, 0.774194, 0.967742, 0.806452, 0.967742, 0.838710, 0.967742, 0.870968, 0.967742, 0.903226, 0.967742, 0.935484, 0.967742, 0.967742, 0.967742, 1, 0.967742, 0, 1, 0.032258, 1, 0.064516, 1, 0.096774, 1, 0.129032, 1, 0.161290, 1, 0.193548, 1, 0.225806, 1, 0.258065, 1, 0.290323, 1, 0.322581, 1, 0.354839, 1, 0.387097, 1, 0.419355, 1, 0.451613, 1, 0.483871, 1, 0.516129, 1, 0.548387, 1, 0.580645, 1, 0.612903, 1, 0.645161, 1, 0.677419, 1, 0.709677, 1, 0.741935, 1, 0.774194, 1, 0.806452, 1, 0.838710, 1, 0.870968, 1, 0.903226, 1, 0.935484, 1, 0.967742, 1, 1, 1, 0.016129, 0.048387, 0.048387, 0.048387, 0.080645, 0.048387, 0.112903, 0.048387, 0.145161, 0.048387, 0.177419, 0.048387, 0.209677, 0.048387, 0.241935, 0.048387, 0.274194, 0.048387, 0.306452, 0.048387, 0.338710, 0.048387, 0.370968, 0.048387, 0.403226, 0.048387, 0.435484, 0.048387, 0.467742, 0.048387, 0.500000, 0.048387, 0.532258, 0.048387, 0.564516, 0.048387, 0.596774, 0.048387, 0.629032, 0.048387, 0.661290, 0.048387, 0.693548, 0.048387, 0.725806, 0.048387, 0.758065, 0.048387, 0.790323, 0.048387, 0.822581, 0.048387, 0.854839, 0.048387, 0.887097, 0.048387, 0.919355, 0.048387, 0.951613, 0.048387, 0.983871, 0.048387, 0.016129, 0.080645, 0.048387, 0.080645, 0.080645, 0.080645, 0.112903, 0.080645, 0.145161, 0.080645, 0.177419, 0.080645, 0.209677, 0.080645, 0.241935, 0.080645, 0.274194, 0.080645, 0.306452, 0.080645, 0.338710, 0.080645, 0.370968, 0.080645, 0.403226, 0.080645, 0.435484, 0.080645, 0.467742, 0.080645, 0.500000, 0.080645, 0.532258, 0.080645, 0.564516, 0.080645, 0.596774, 0.080645, 0.629032, 0.080645, 0.661290, 0.080645, 0.693548, 0.080645, 0.725806, 0.080645, 0.758065, 0.080645, 0.790323, 0.080645, 0.822581, 0.080645, 0.854839, 0.080645, 0.887097, 0.080645, 0.919355, 0.080645, 0.951613, 0.080645, 0.983871, 0.080645, 0.016129, 0.112903, 0.048387, 0.112903, 0.080645, 0.112903, 0.112903, 0.112903, 0.145161, 0.112903, 0.177419, 0.112903, 0.209677, 0.112903, 0.241935, 0.112903, 0.274194, 0.112903, 0.306452, 0.112903, 0.338710, 0.112903, 0.370968, 0.112903, 0.403226, 0.112903, 0.435484, 0.112903, 0.467742, 0.112903, 0.500000, 0.112903, 0.532258, 0.112903, 0.564516, 0.112903, 0.596774, 0.112903, 0.629032, 0.112903, 0.661290, 0.112903, 0.693548, 0.112903, 0.725806, 0.112903, 0.758065, 0.112903, 0.790323, 0.112903, 0.822581, 0.112903, 0.854839, 0.112903, 0.887097, 0.112903, 0.919355, 0.112903, 0.951613, 0.112903, 0.983871, 0.112903, 0.016129, 0.145161, 0.048387, 0.145161, 0.080645, 0.145161, 0.112903, 0.145161, 0.145161, 0.145161, 0.177419, 0.145161, 0.209677, 0.145161, 0.241935, 0.145161, 0.274194, 0.145161, 0.306452, 0.145161, 0.338710, 0.145161, 0.370968, 0.145161, 0.403226, 0.145161, 0.435484, 0.145161, 0.467742, 0.145161, 0.500000, 0.145161, 0.532258, 0.145161, 0.564516, 0.145161, 0.596774, 0.145161, 0.629032, 0.145161, 0.661290, 0.145161, 0.693548, 0.145161, 0.725806, 0.145161, 0.758065, 0.145161, 0.790323, 0.145161, 0.822581, 0.145161, 0.854839, 0.145161, 0.887097, 0.145161, 0.919355, 0.145161, 0.951613, 0.145161, 0.983871, 0.145161, 0.016129, 0.177419, 0.048387, 0.177419, 0.080645, 0.177419, 0.112903, 0.177419, 0.145161, 0.177419, 0.177419, 0.177419, 0.209677, 0.177419, 0.241935, 0.177419, 0.274194, 0.177419, 0.306452, 0.177419, 0.338710, 0.177419, 0.370968, 0.177419, 0.403226, 0.177419, 0.435484, 0.177419, 0.467742, 0.177419, 0.500000, 0.177419, 0.532258, 0.177419, 0.564516, 0.177419, 0.596774, 0.177419, 0.629032, 0.177419, 0.661290, 0.177419, 0.693548, 0.177419, 0.725806, 0.177419, 0.758065, 0.177419, 0.790323, 0.177419, 0.822581, 0.177419, 0.854839, 0.177419, 0.887097, 0.177419, 0.919355, 0.177419, 0.951613, 0.177419, 0.983871, 0.177419, 0.016129, 0.209677, 0.048387, 0.209677, 0.080645, 0.209677, 0.112903, 0.209677, 0.145161, 0.209677, 0.177419, 0.209677, 0.209677, 0.209677, 0.241935, 0.209677, 0.274194, 0.209677, 0.306452, 0.209677, 0.338710, 0.209677, 0.370968, 0.209677, 0.403226, 0.209677, 0.435484, 0.209677, 0.467742, 0.209677, 0.500000, 0.209677, 0.532258, 0.209677, 0.564516, 0.209677, 0.596774, 0.209677, 0.629032, 0.209677, 0.661290, 0.209677, 0.693548, 0.209677, 0.725806, 0.209677, 0.758065, 0.209677, 0.790323, 0.209677, 0.822581, 0.209677, 0.854839, 0.209677, 0.887097, 0.209677, 0.919355, 0.209677, 0.951613, 0.209677, 0.983871, 0.209677, 0.016129, 0.241935, 0.048387, 0.241935, 0.080645, 0.241935, 0.112903, 0.241935, 0.145161, 0.241935, 0.177419, 0.241935, 0.209677, 0.241935, 0.241935, 0.241935, 0.274194, 0.241935, 0.306452, 0.241935, 0.338710, 0.241935, 0.370968, 0.241935, 0.403226, 0.241935, 0.435484, 0.241935, 0.467742, 0.241935, 0.500000, 0.241935, 0.532258, 0.241935, 0.564516, 0.241935, 0.596774, 0.241935, 0.629032, 0.241935, 0.661290, 0.241935, 0.693548, 0.241935, 0.725806, 0.241935, 0.758065, 0.241935, 0.790323, 0.241935, 0.822581, 0.241935, 0.854839, 0.241935, 0.887097, 0.241935, 0.919355, 0.241935, 0.951613, 0.241935, 0.983871, 0.241935, 0.016129, 0.274194, 0.048387, 0.274194, 0.080645, 0.274194, 0.112903, 0.274194, 0.145161, 0.274194, 0.177419, 0.274194, 0.209677, 0.274194, 0.241935, 0.274194, 0.274194, 0.274194, 0.306452, 0.274194, 0.338710, 0.274194, 0.370968, 0.274194, 0.403226, 0.274194, 0.435484, 0.274194, 0.467742, 0.274194, 0.500000, 0.274194, 0.532258, 0.274194, 0.564516, 0.274194, 0.596774, 0.274194, 0.629032, 0.274194, 0.661290, 0.274194, 0.693548, 0.274194, 0.725806, 0.274194, 0.758065, 0.274194, 0.790323, 0.274194, 0.822581, 0.274194, 0.854839, 0.274194, 0.887097, 0.274194, 0.919355, 0.274194, 0.951613, 0.274194, 0.983871, 0.274194, 0.016129, 0.306452, 0.048387, 0.306452, 0.080645, 0.306452, 0.112903, 0.306452, 0.145161, 0.306452, 0.177419, 0.306452, 0.209677, 0.306452, 0.241935, 0.306452, 0.274194, 0.306452, 0.306452, 0.306452, 0.338710, 0.306452, 0.370968, 0.306452, 0.403226, 0.306452, 0.435484, 0.306452, 0.467742, 0.306452, 0.500000, 0.306452, 0.532258, 0.306452, 0.564516, 0.306452, 0.596774, 0.306452, 0.629032, 0.306452, 0.661290, 0.306452, 0.693548, 0.306452, 0.725806, 0.306452, 0.758065, 0.306452, 0.790323, 0.306452, 0.822581, 0.306452, 0.854839, 0.306452, 0.887097, 0.306452, 0.919355, 0.306452, 0.951613, 0.306452, 0.983871, 0.306452, 0.016129, 0.338710, 0.048387, 0.338710, 0.080645, 0.338710, 0.112903, 0.338710, 0.145161, 0.338710, 0.177419, 0.338710, 0.209677, 0.338710, 0.241935, 0.338710, 0.274194, 0.338710, 0.306452, 0.338710, 0.338710, 0.338710, 0.370968, 0.338710, 0.403226, 0.338710, 0.435484, 0.338710, 0.467742, 0.338710, 0.500000, 0.338710, 0.532258, 0.338710, 0.564516, 0.338710, 0.596774, 0.338710, 0.629032, 0.338710, 0.661290, 0.338710, 0.693548, 0.338710, 0.725806, 0.338710, 0.758065, 0.338710, 0.790323, 0.338710, 0.822581, 0.338710, 0.854839, 0.338710, 0.887097, 0.338710, 0.919355, 0.338710, 0.951613, 0.338710, 0.983871, 0.338710, 0.016129, 0.370968, 0.048387, 0.370968, 0.080645, 0.370968, 0.112903, 0.370968, 0.145161, 0.370968, 0.177419, 0.370968, 0.209677, 0.370968, 0.241935, 0.370968, 0.274194, 0.370968, 0.306452, 0.370968, 0.338710, 0.370968, 0.370968, 0.370968, 0.403226, 0.370968, 0.435484, 0.370968, 0.467742, 0.370968, 0.500000, 0.370968, 0.532258, 0.370968, 0.564516, 0.370968, 0.596774, 0.370968, 0.629032, 0.370968, 0.661290, 0.370968, 0.693548, 0.370968, 0.725806, 0.370968, 0.758065, 0.370968, 0.790323, 0.370968, 0.822581, 0.370968, 0.854839, 0.370968, 0.887097, 0.370968, 0.919355, 0.370968, 0.951613, 0.370968, 0.983871, 0.370968, 0.016129, 0.403226, 0.048387, 0.403226, 0.080645, 0.403226, 0.112903, 0.403226, 0.145161, 0.403226, 0.177419, 0.403226, 0.209677, 0.403226, 0.241935, 0.403226, 0.274194, 0.403226, 0.306452, 0.403226, 0.338710, 0.403226, 0.370968, 0.403226, 0.403226, 0.403226, 0.435484, 0.403226, 0.467742, 0.403226, 0.500000, 0.403226, 0.532258, 0.403226, 0.564516, 0.403226, 0.596774, 0.403226, 0.629032, 0.403226, 0.661290, 0.403226, 0.693548, 0.403226, 0.725806, 0.403226, 0.758065, 0.403226, 0.790323, 0.403226, 0.822581, 0.403226, 0.854839, 0.403226, 0.887097, 0.403226, 0.919355, 0.403226, 0.951613, 0.403226, 0.983871, 0.403226, 0.016129, 0.435484, 0.048387, 0.435484, 0.080645, 0.435484, 0.112903, 0.435484, 0.145161, 0.435484, 0.177419, 0.435484, 0.209677, 0.435484, 0.241935, 0.435484, 0.274194, 0.435484, 0.306452, 0.435484, 0.338710, 0.435484, 0.370968, 0.435484, 0.403226, 0.435484, 0.435484, 0.435484, 0.467742, 0.435484, 0.500000, 0.435484, 0.532258, 0.435484, 0.564516, 0.435484, 0.596774, 0.435484, 0.629032, 0.435484, 0.661290, 0.435484, 0.693548, 0.435484, 0.725806, 0.435484, 0.758065, 0.435484, 0.790323, 0.435484, 0.822581, 0.435484, 0.854839, 0.435484, 0.887097, 0.435484, 0.919355, 0.435484, 0.951613, 0.435484, 0.983871, 0.435484, 0.016129, 0.467742, 0.048387, 0.467742, 0.080645, 0.467742, 0.112903, 0.467742, 0.145161, 0.467742, 0.177419, 0.467742, 0.209677, 0.467742, 0.241935, 0.467742, 0.274194, 0.467742, 0.306452, 0.467742, 0.338710, 0.467742, 0.370968, 0.467742, 0.403226, 0.467742, 0.435484, 0.467742, 0.467742, 0.467742, 0.500000, 0.467742, 0.532258, 0.467742, 0.564516, 0.467742, 0.596774, 0.467742, 0.629032, 0.467742, 0.661290, 0.467742, 0.693548, 0.467742, 0.725806, 0.467742, 0.758065, 0.467742, 0.790323, 0.467742, 0.822581, 0.467742, 0.854839, 0.467742, 0.887097, 0.467742, 0.919355, 0.467742, 0.951613, 0.467742, 0.983871, 0.467742, 0.016129, 0.500000, 0.048387, 0.500000, 0.080645, 0.500000, 0.112903, 0.500000, 0.145161, 0.500000, 0.177419, 0.500000, 0.209677, 0.500000, 0.241935, 0.500000, 0.274194, 0.500000, 0.306452, 0.500000, 0.338710, 0.500000, 0.370968, 0.500000, 0.403226, 0.500000, 0.435484, 0.500000, 0.467742, 0.500000, 0.500000, 0.500000, 0.532258, 0.500000, 0.564516, 0.500000, 0.596774, 0.500000, 0.629032, 0.500000, 0.661290, 0.500000, 0.693548, 0.500000, 0.725806, 0.500000, 0.758065, 0.500000, 0.790323, 0.500000, 0.822581, 0.500000, 0.854839, 0.500000, 0.887097, 0.500000, 0.919355, 0.500000, 0.951613, 0.500000, 0.983871, 0.500000, 0.016129, 0.532258, 0.048387, 0.532258, 0.080645, 0.532258, 0.112903, 0.532258, 0.145161, 0.532258, 0.177419, 0.532258, 0.209677, 0.532258, 0.241935, 0.532258, 0.274194, 0.532258, 0.306452, 0.532258, 0.338710, 0.532258, 0.370968, 0.532258, 0.403226, 0.532258, 0.435484, 0.532258, 0.467742, 0.532258, 0.500000, 0.532258, 0.532258, 0.532258, 0.564516, 0.532258, 0.596774, 0.532258, 0.629032, 0.532258, 0.661290, 0.532258, 0.693548, 0.532258, 0.725806, 0.532258, 0.758065, 0.532258, 0.790323, 0.532258, 0.822581, 0.532258, 0.854839, 0.532258, 0.887097, 0.532258, 0.919355, 0.532258, 0.951613, 0.532258, 0.983871, 0.532258, 0.016129, 0.564516, 0.048387, 0.564516, 0.080645, 0.564516, 0.112903, 0.564516, 0.145161, 0.564516, 0.177419, 0.564516, 0.209677, 0.564516, 0.241935, 0.564516, 0.274194, 0.564516, 0.306452, 0.564516, 0.338710, 0.564516, 0.370968, 0.564516, 0.403226, 0.564516, 0.435484, 0.564516, 0.467742, 0.564516, 0.500000, 0.564516, 0.532258, 0.564516, 0.564516, 0.564516, 0.596774, 0.564516, 0.629032, 0.564516, 0.661290, 0.564516, 0.693548, 0.564516, 0.725806, 0.564516, 0.758065, 0.564516, 0.790323, 0.564516, 0.822581, 0.564516, 0.854839, 0.564516, 0.887097, 0.564516, 0.919355, 0.564516, 0.951613, 0.564516, 0.983871, 0.564516, 0.016129, 0.596774, 0.048387, 0.596774, 0.080645, 0.596774, 0.112903, 0.596774, 0.145161, 0.596774, 0.177419, 0.596774, 0.209677, 0.596774, 0.241935, 0.596774, 0.274194, 0.596774, 0.306452, 0.596774, 0.338710, 0.596774, 0.370968, 0.596774, 0.403226, 0.596774, 0.435484, 0.596774, 0.467742, 0.596774, 0.500000, 0.596774, 0.532258, 0.596774, 0.564516, 0.596774, 0.596774, 0.596774, 0.629032, 0.596774, 0.661290, 0.596774, 0.693548, 0.596774, 0.725806, 0.596774, 0.758065, 0.596774, 0.790323, 0.596774, 0.822581, 0.596774, 0.854839, 0.596774, 0.887097, 0.596774, 0.919355, 0.596774, 0.951613, 0.596774, 0.983871, 0.596774, 0.016129, 0.629032, 0.048387, 0.629032, 0.080645, 0.629032, 0.112903, 0.629032, 0.145161, 0.629032, 0.177419, 0.629032, 0.209677, 0.629032, 0.241935, 0.629032, 0.274194, 0.629032, 0.306452, 0.629032, 0.338710, 0.629032, 0.370968, 0.629032, 0.403226, 0.629032, 0.435484, 0.629032, 0.467742, 0.629032, 0.500000, 0.629032, 0.532258, 0.629032, 0.564516, 0.629032, 0.596774, 0.629032, 0.629032, 0.629032, 0.661290, 0.629032, 0.693548, 0.629032, 0.725806, 0.629032, 0.758065, 0.629032, 0.790323, 0.629032, 0.822581, 0.629032, 0.854839, 0.629032, 0.887097, 0.629032, 0.919355, 0.629032, 0.951613, 0.629032, 0.983871, 0.629032, 0.016129, 0.661290, 0.048387, 0.661290, 0.080645, 0.661290, 0.112903, 0.661290, 0.145161, 0.661290, 0.177419, 0.661290, 0.209677, 0.661290, 0.241935, 0.661290, 0.274194, 0.661290, 0.306452, 0.661290, 0.338710, 0.661290, 0.370968, 0.661290, 0.403226, 0.661290, 0.435484, 0.661290, 0.467742, 0.661290, 0.500000, 0.661290, 0.532258, 0.661290, 0.564516, 0.661290, 0.596774, 0.661290, 0.629032, 0.661290, 0.661290, 0.661290, 0.693548, 0.661290, 0.725806, 0.661290, 0.758065, 0.661290, 0.790323, 0.661290, 0.822581, 0.661290, 0.854839, 0.661290, 0.887097, 0.661290, 0.919355, 0.661290, 0.951613, 0.661290, 0.983871, 0.661290, 0.016129, 0.693548, 0.048387, 0.693548, 0.080645, 0.693548, 0.112903, 0.693548, 0.145161, 0.693548, 0.177419, 0.693548, 0.209677, 0.693548, 0.241935, 0.693548, 0.274194, 0.693548, 0.306452, 0.693548, 0.338710, 0.693548, 0.370968, 0.693548, 0.403226, 0.693548, 0.435484, 0.693548, 0.467742, 0.693548, 0.500000, 0.693548, 0.532258, 0.693548, 0.564516, 0.693548, 0.596774, 0.693548, 0.629032, 0.693548, 0.661290, 0.693548, 0.693548, 0.693548, 0.725806, 0.693548, 0.758065, 0.693548, 0.790323, 0.693548, 0.822581, 0.693548, 0.854839, 0.693548, 0.887097, 0.693548, 0.919355, 0.693548, 0.951613, 0.693548, 0.983871, 0.693548, 0.016129, 0.725806, 0.048387, 0.725806, 0.080645, 0.725806, 0.112903, 0.725806, 0.145161, 0.725806, 0.177419, 0.725806, 0.209677, 0.725806, 0.241935, 0.725806, 0.274194, 0.725806, 0.306452, 0.725806, 0.338710, 0.725806, 0.370968, 0.725806, 0.403226, 0.725806, 0.435484, 0.725806, 0.467742, 0.725806, 0.500000, 0.725806, 0.532258, 0.725806, 0.564516, 0.725806, 0.596774, 0.725806, 0.629032, 0.725806, 0.661290, 0.725806, 0.693548, 0.725806, 0.725806, 0.725806, 0.758065, 0.725806, 0.790323, 0.725806, 0.822581, 0.725806, 0.854839, 0.725806, 0.887097, 0.725806, 0.919355, 0.725806, 0.951613, 0.725806, 0.983871, 0.725806, 0.016129, 0.758065, 0.048387, 0.758065, 0.080645, 0.758065, 0.112903, 0.758065, 0.145161, 0.758065, 0.177419, 0.758065, 0.209677, 0.758065, 0.241935, 0.758065, 0.274194, 0.758065, 0.306452, 0.758065, 0.338710, 0.758065, 0.370968, 0.758065, 0.403226, 0.758065, 0.435484, 0.758065, 0.467742, 0.758065, 0.500000, 0.758065, 0.532258, 0.758065, 0.564516, 0.758065, 0.596774, 0.758065, 0.629032, 0.758065, 0.661290, 0.758065, 0.693548, 0.758065, 0.725806, 0.758065, 0.758065, 0.758065, 0.790323, 0.758065, 0.822581, 0.758065, 0.854839, 0.758065, 0.887097, 0.758065, 0.919355, 0.758065, 0.951613, 0.758065, 0.983871, 0.758065, 0.016129, 0.790323, 0.048387, 0.790323, 0.080645, 0.790323, 0.112903, 0.790323, 0.145161, 0.790323, 0.177419, 0.790323, 0.209677, 0.790323, 0.241935, 0.790323, 0.274194, 0.790323, 0.306452, 0.790323, 0.338710, 0.790323, 0.370968, 0.790323, 0.403226, 0.790323, 0.435484, 0.790323, 0.467742, 0.790323, 0.500000, 0.790323, 0.532258, 0.790323, 0.564516, 0.790323, 0.596774, 0.790323, 0.629032, 0.790323, 0.661290, 0.790323, 0.693548, 0.790323, 0.725806, 0.790323, 0.758065, 0.790323, 0.790323, 0.790323, 0.822581, 0.790323, 0.854839, 0.790323, 0.887097, 0.790323, 0.919355, 0.790323, 0.951613, 0.790323, 0.983871, 0.790323, 0.016129, 0.822581, 0.048387, 0.822581, 0.080645, 0.822581, 0.112903, 0.822581, 0.145161, 0.822581, 0.177419, 0.822581, 0.209677, 0.822581, 0.241935, 0.822581, 0.274194, 0.822581, 0.306452, 0.822581, 0.338710, 0.822581, 0.370968, 0.822581, 0.403226, 0.822581, 0.435484, 0.822581, 0.467742, 0.822581, 0.500000, 0.822581, 0.532258, 0.822581, 0.564516, 0.822581, 0.596774, 0.822581, 0.629032, 0.822581, 0.661290, 0.822581, 0.693548, 0.822581, 0.725806, 0.822581, 0.758065, 0.822581, 0.790323, 0.822581, 0.822581, 0.822581, 0.854839, 0.822581, 0.887097, 0.822581, 0.919355, 0.822581, 0.951613, 0.822581, 0.983871, 0.822581, 0.016129, 0.854839, 0.048387, 0.854839, 0.080645, 0.854839, 0.112903, 0.854839, 0.145161, 0.854839, 0.177419, 0.854839, 0.209677, 0.854839, 0.241935, 0.854839, 0.274194, 0.854839, 0.306452, 0.854839, 0.338710, 0.854839, 0.370968, 0.854839, 0.403226, 0.854839, 0.435484, 0.854839, 0.467742, 0.854839, 0.500000, 0.854839, 0.532258, 0.854839, 0.564516, 0.854839, 0.596774, 0.854839, 0.629032, 0.854839, 0.661290, 0.854839, 0.693548, 0.854839, 0.725806, 0.854839, 0.758065, 0.854839, 0.790323, 0.854839, 0.822581, 0.854839, 0.854839, 0.854839, 0.887097, 0.854839, 0.919355, 0.854839, 0.951613, 0.854839, 0.983871, 0.854839, 0.016129, 0.887097, 0.048387, 0.887097, 0.080645, 0.887097, 0.112903, 0.887097, 0.145161, 0.887097, 0.177419, 0.887097, 0.209677, 0.887097, 0.241935, 0.887097, 0.274194, 0.887097, 0.306452, 0.887097, 0.338710, 0.887097, 0.370968, 0.887097, 0.403226, 0.887097, 0.435484, 0.887097, 0.467742, 0.887097, 0.500000, 0.887097, 0.532258, 0.887097, 0.564516, 0.887097, 0.596774, 0.887097, 0.629032, 0.887097, 0.661290, 0.887097, 0.693548, 0.887097, 0.725806, 0.887097, 0.758065, 0.887097, 0.790323, 0.887097, 0.822581, 0.887097, 0.854839, 0.887097, 0.887097, 0.887097, 0.919355, 0.887097, 0.951613, 0.887097, 0.983871, 0.887097, 0.016129, 0.919355, 0.048387, 0.919355, 0.080645, 0.919355, 0.112903, 0.919355, 0.145161, 0.919355, 0.177419, 0.919355, 0.209677, 0.919355, 0.241935, 0.919355, 0.274194, 0.919355, 0.306452, 0.919355, 0.338710, 0.919355, 0.370968, 0.919355, 0.403226, 0.919355, 0.435484, 0.919355, 0.467742, 0.919355, 0.500000, 0.919355, 0.532258, 0.919355, 0.564516, 0.919355, 0.596774, 0.919355, 0.629032, 0.919355, 0.661290, 0.919355, 0.693548, 0.919355, 0.725806, 0.919355, 0.758065, 0.919355, 0.790323, 0.919355, 0.822581, 0.919355, 0.854839, 0.919355, 0.887097, 0.919355, 0.919355, 0.919355, 0.951613, 0.919355, 0.983871, 0.919355, 0.016129, 0.951613, 0.048387, 0.951613, 0.080645, 0.951613, 0.112903, 0.951613, 0.145161, 0.951613, 0.177419, 0.951613, 0.209677, 0.951613, 0.241935, 0.951613, 0.274194, 0.951613, 0.306452, 0.951613, 0.338710, 0.951613, 0.370968, 0.951613, 0.403226, 0.951613, 0.435484, 0.951613, 0.467742, 0.951613, 0.500000, 0.951613, 0.532258, 0.951613, 0.564516, 0.951613, 0.596774, 0.951613, 0.629032, 0.951613, 0.661290, 0.951613, 0.693548, 0.951613, 0.725806, 0.951613, 0.758065, 0.951613, 0.790323, 0.951613, 0.822581, 0.951613, 0.854839, 0.951613, 0.887097, 0.951613, 0.919355, 0.951613, 0.951613, 0.951613, 0.983871, 0.951613 };
    TextureCoordinate1.point = m_point;
    TextureCoordinate1.point_length = sizeof(m_point) / sizeof(float);
    }
    NurbsSurface1.color = NULL;
    NurbsSurface1.coord = &Coordinate1;
    NurbsSurface1.normal = &Normal1;
    NurbsSurface1.texCoord = &TextureCoordinate1;
    NurbsSurface1.ccw = true;
    {
    static int m_colorIndex[] = { 1, 33, 32, -1, 2, 34, 33, -1, 3, 35, 34, -1, 4, 36, 35, -1, 5, 37, 36, -1, 6, 38, 37, -1, 7, 39, 38, -1, 8, 40, 39, -1, 9, 41, 40, -1, 10, 42, 41, -1, 11, 43, 42, -1, 12, 44, 43, -1, 13, 45, 44, -1, 14, 46, 45, -1, 15, 47, 46, -1, 16, 48, 47, -1, 17, 49, 48, -1, 18, 50, 49, -1, 19, 51, 50, -1, 20, 52, 51, -1, 21, 53, 52, -1, 22, 54, 53, -1, 23, 55, 54, -1, 24, 56, 55, -1, 25, 57, 56, -1, 26, 58, 57, -1, 27, 59, 58, -1, 28, 60, 59, -1, 29, 61, 60, -1, 30, 62, 61, -1, 31, 63, 62, -1, 33, 1024, 32, -1, 65, 1024, 33, -1, 64, 1024, 65, -1, 32, 1024, 64, -1, 34, 1025, 33, -1, 66, 1025, 34, -1, 65, 1025, 66, -1, 33, 1025, 65, -1, 35, 1026, 34, -1, 67, 1026, 35, -1, 66, 1026, 67, -1, 34, 1026, 66, -1, 36, 1027, 35, -1, 68, 1027, 36, -1, 67, 1027, 68, -1, 35, 1027, 67, -1, 37, 1028, 36, -1, 69, 1028, 37, -1, 68, 1028, 69, -1, 36, 1028, 68, -1, 38, 1029, 37, -1, 70, 1029, 38, -1, 69, 1029, 70, -1, 37, 1029, 69, -1, 39, 1030, 38, -1, 71, 1030, 39, -1, 70, 1030, 71, -1, 38, 1030, 70, -1, 40, 1031, 39, -1, 72, 1031, 40, -1, 71, 1031, 72, -1, 39, 1031, 71, -1, 41, 1032, 40, -1, 73, 1032, 41, -1, 72, 1032, 73, -1, 40, 1032, 72, -1, 42, 1033, 41, -1, 74, 1033, 42, -1, 73, 1033, 74, -1, 41, 1033, 73, -1, 43, 1034, 42, -1, 75, 1034, 43, -1, 74, 1034, 75, -1, 42, 1034, 74, -1, 44, 1035, 43, -1, 76, 1035, 44, -1, 75, 1035, 76, -1, 43, 1035, 75, -1, 45, 1036, 44, -1, 77, 1036, 45, -1, 76, 1036, 77, -1, 44, 1036, 76, -1, 46, 1037, 45, -1, 78, 1037, 46, -1, 77, 1037, 78, -1, 45, 1037, 77, -1, 47, 1038, 46, -1, 79, 1038, 47, -1, 78, 1038, 79, -1, 46, 1038, 78, -1, 48, 1039, 47, -1, 80, 1039, 48, -1, 79, 1039, 80, -1, 47, 1039, 79, -1, 49, 1040, 48, -1, 81, 1040, 49, -1, 80, 1040, 81, -1, 48, 1040, 80, -1, 50, 1041, 49, -1, 82, 1041, 50, -1, 81, 1041, 82, -1, 49, 1041, 81, -1, 51, 1042, 50, -1, 83, 1042, 51, -1, 82, 1042, 83, -1, 50, 1042, 82, -1, 52, 1043, 51, -1, 84, 1043, 52, -1, 83, 1043, 84, -1, 51, 1043, 83, -1, 53, 1044, 52, -1, 85, 1044, 53, -1, 84, 1044, 85, -1, 52, 1044, 84, -1, 54, 1045, 53, -1, 86, 1045, 54, -1, 85, 1045, 86, -1, 53, 1045, 85, -1, 55, 1046, 54, -1, 87, 1046, 55, -1, 86, 1046, 87, -1, 54, 1046, 86, -1, 56, 1047, 55, -1, 88, 1047, 56, -1, 87, 1047, 88, -1, 55, 1047, 87, -1, 57, 1048, 56, -1, 89, 1048, 57, -1, 88, 1048, 89, -1, 56, 1048, 88, -1, 58, 1049, 57, -1, 90, 1049, 58, -1, 89, 1049, 90, -1, 57, 1049, 89, -1, 59, 1050, 58, -1, 91, 1050, 59, -1, 90, 1050, 91, -1, 58, 1050, 90, -1, 60, 1051, 59, -1, 92, 1051, 60, -1, 91, 1051, 92, -1, 59, 1051, 91, -1, 61, 1052, 60, -1, 93, 1052, 61, -1, 92, 1052, 93, -1, 60, 1052, 92, -1, 62, 1053, 61, -1, 94, 1053, 62, -1, 93, 1053, 94, -1, 61, 1053, 93, -1, 63, 1054, 62, -1, 95, 1054, 63, -1, 94, 1054, 95, -1, 62, 1054, 94, -1, 65, 1055, 64, -1, 97, 1055, 65, -1, 96, 1055, 97, -1, 64, 1055, 96, -1, 66, 1056, 65, -1, 98, 1056, 66, -1, 97, 1056, 98, -1, 65, 1056, 97, -1, 67, 1057, 66, -1, 99, 1057, 67, -1, 98, 1057, 99, -1, 66, 1057, 98, -1, 68, 1058, 67, -1, 100, 1058, 68, -1, 99, 1058, 100, -1, 67, 1058, 99, -1, 69, 1059, 68, -1, 101, 1059, 69, -1, 100, 1059, 101, -1, 68, 1059, 100, -1, 70, 1060, 69, -1, 102, 1060, 70, -1, 101, 1060, 102, -1, 69, 1060, 101, -1, 71, 1061, 70, -1, 103, 1061, 71, -1, 102, 1061, 103, -1, 70, 1061, 102, -1, 72, 1062, 71, -1, 104, 1062, 72, -1, 103, 1062, 104, -1, 71, 1062, 103, -1, 73, 1063, 72, -1, 105, 1063, 73, -1, 104, 1063, 105, -1, 72, 1063, 104, -1, 74, 1064, 73, -1, 106, 1064, 74, -1, 105, 1064, 106, -1, 73, 1064, 105, -1, 75, 1065, 74, -1, 107, 1065, 75, -1, 106, 1065, 107, -1, 74, 1065, 106, -1, 76, 1066, 75, -1, 108, 1066, 76, -1, 107, 1066, 108, -1, 75, 1066, 107, -1, 77, 1067, 76, -1, 109, 1067, 77, -1, 108, 1067, 109, -1, 76, 1067, 108, -1, 78, 1068, 77, -1, 110, 1068, 78, -1, 109, 1068, 110, -1, 77, 1068, 109, -1, 79, 1069, 78, -1, 111, 1069, 79, -1, 110, 1069, 111, -1, 78, 1069, 110, -1, 80, 1070, 79, -1, 112, 1070, 80, -1, 111, 1070, 112, -1, 79, 1070, 111, -1, 81, 1071, 80, -1, 113, 1071, 81, -1, 112, 1071, 113, -1, 80, 1071, 112, -1, 82, 1072, 81, -1, 114, 1072, 82, -1, 113, 1072, 114, -1, 81, 1072, 113, -1, 83, 1073, 82, -1, 115, 1073, 83, -1, 114, 1073, 115, -1, 82, 1073, 114, -1, 84, 1074, 83, -1, 116, 1074, 84, -1, 115, 1074, 116, -1, 83, 1074, 115, -1, 85, 1075, 84, -1, 117, 1075, 85, -1, 116, 1075, 117, -1, 84, 1075, 116, -1, 86, 1076, 85, -1, 118, 1076, 86, -1, 117, 1076, 118, -1, 85, 1076, 117, -1, 87, 1077, 86, -1, 119, 1077, 87, -1, 118, 1077, 119, -1, 86, 1077, 118, -1, 88, 1078, 87, -1, 120, 1078, 88, -1, 119, 1078, 120, -1, 87, 1078, 119, -1, 89, 1079, 88, -1, 121, 1079, 89, -1, 120, 1079, 121, -1, 88, 1079, 120, -1, 90, 1080, 89, -1, 122, 1080, 90, -1, 121, 1080, 122, -1, 89, 1080, 121, -1, 91, 1081, 90, -1, 123, 1081, 91, -1, 122, 1081, 123, -1, 90, 1081, 122, -1, 92, 1082, 91, -1, 124, 1082, 92, -1, 123, 1082, 124, -1, 91, 1082, 123, -1, 93, 1083, 92, -1, 125, 1083, 93, -1, 124, 1083, 125, -1, 92, 1083, 124, -1, 94, 1084, 93, -1, 126, 1084, 94, -1, 125, 1084, 126, -1, 93, 1084, 125, -1, 95, 1085, 94, -1, 127, 1085, 95, -1, 126, 1085, 127, -1, 94, 1085, 126, -1, 97, 1086, 96, -1, 129, 1086, 97, -1, 128, 1086, 129, -1, 96, 1086, 128, -1, 98, 1087, 97, -1, 130, 1087, 98, -1, 129, 1087, 130, -1, 97, 1087, 129, -1, 99, 1088, 98, -1, 131, 1088, 99, -1, 130, 1088, 131, -1, 98, 1088, 130, -1, 100, 1089, 99, -1, 132, 1089, 100, -1, 131, 1089, 132, -1, 99, 1089, 131, -1, 101, 1090, 100, -1, 133, 1090, 101, -1, 132, 1090, 133, -1, 100, 1090, 132, -1, 102, 1091, 101, -1, 134, 1091, 102, -1, 133, 1091, 134, -1, 101, 1091, 133, -1, 103, 1092, 102, -1, 135, 1092, 103, -1, 134, 1092, 135, -1, 102, 1092, 134, -1, 104, 1093, 103, -1, 136, 1093, 104, -1, 135, 1093, 136, -1, 103, 1093, 135, -1, 105, 1094, 104, -1, 137, 1094, 105, -1, 136, 1094, 137, -1, 104, 1094, 136, -1, 106, 1095, 105, -1, 138, 1095, 106, -1, 137, 1095, 138, -1, 105, 1095, 137, -1, 107, 1096, 106, -1, 139, 1096, 107, -1, 138, 1096, 139, -1, 106, 1096, 138, -1, 108, 1097, 107, -1, 140, 1097, 108, -1, 139, 1097, 140, -1, 107, 1097, 139, -1, 109, 1098, 108, -1, 141, 1098, 109, -1, 140, 1098, 141, -1, 108, 1098, 140, -1, 110, 1099, 109, -1, 142, 1099, 110, -1, 141, 1099, 142, -1, 109, 1099, 141, -1, 111, 1100, 110, -1, 143, 1100, 111, -1, 142, 1100, 143, -1, 110, 1100, 142, -1, 112, 1101, 111, -1, 144, 1101, 112, -1, 143, 1101, 144, -1, 111, 1101, 143, -1, 113, 1102, 112, -1, 145, 1102, 113, -1, 144, 1102, 145, -1, 112, 1102, 144, -1, 114, 1103, 113, -1, 146, 1103, 114, -1, 145, 1103, 146, -1, 113, 1103, 145, -1, 115, 1104, 114, -1, 147, 1104, 115, -1, 146, 1104, 147, -1, 114, 1104, 146, -1, 116, 1105, 115, -1, 148, 1105, 116, -1, 147, 1105, 148, -1, 115, 1105, 147, -1, 117, 1106, 116, -1, 149, 1106, 117, -1, 148, 1106, 149, -1, 116, 1106, 148, -1, 118, 1107, 117, -1, 150, 1107, 118, -1, 149, 1107, 150, -1, 117, 1107, 149, -1, 119, 1108, 118, -1, 151, 1108, 119, -1, 150, 1108, 151, -1, 118, 1108, 150, -1, 120, 1109, 119, -1, 152, 1109, 120, -1, 151, 1109, 152, -1, 119, 1109, 151, -1, 121, 1110, 120, -1, 153, 1110, 121, -1, 152, 1110, 153, -1, 120, 1110, 152, -1, 122, 1111, 121, -1, 154, 1111, 122, -1, 153, 1111, 154, -1, 121, 1111, 153, -1, 123, 1112, 122, -1, 155, 1112, 123, -1, 154, 1112, 155, -1, 122, 1112, 154, -1, 124, 1113, 123, -1, 156, 1113, 124, -1, 155, 1113, 156, -1, 123, 1113, 155, -1, 125, 1114, 124, -1, 157, 1114, 125, -1, 156, 1114, 157, -1, 124, 1114, 156, -1, 126, 1115, 125, -1, 158, 1115, 126, -1, 157, 1115, 158, -1, 125, 1115, 157, -1, 127, 1116, 126, -1, 159, 1116, 127, -1, 158, 1116, 159, -1, 126, 1116, 158, -1, 129, 1117, 128, -1, 161, 1117, 129, -1, 160, 1117, 161, -1, 128, 1117, 160, -1, 130, 1118, 129, -1, 162, 1118, 130, -1, 161, 1118, 162, -1, 129, 1118, 161, -1, 131, 1119, 130, -1, 163, 1119, 131, -1, 162, 1119, 163, -1, 130, 1119, 162, -1, 132, 1120, 131, -1, 164, 1120, 132, -1, 163, 1120, 164, -1, 131, 1120, 163, -1, 133, 1121, 132, -1, 165, 1121, 133, -1, 164, 1121, 165, -1, 132, 1121, 164, -1, 134, 1122, 133, -1, 166, 1122, 134, -1, 165, 1122, 166, -1, 133, 1122, 165, -1, 135, 1123, 134, -1, 167, 1123, 135, -1, 166, 1123, 167, -1, 134, 1123, 166, -1, 136, 1124, 135, -1, 168, 1124, 136, -1, 167, 1124, 168, -1, 135, 1124, 167, -1, 137, 1125, 136, -1, 169, 1125, 137, -1, 168, 1125, 169, -1, 136, 1125, 168, -1, 138, 1126, 137, -1, 170, 1126, 138, -1, 169, 1126, 170, -1, 137, 1126, 169, -1, 139, 1127, 138, -1, 171, 1127, 139, -1, 170, 1127, 171, -1, 138, 1127, 170, -1, 140, 1128, 139, -1, 172, 1128, 140, -1, 171, 1128, 172, -1, 139, 1128, 171, -1, 141, 1129, 140, -1, 173, 1129, 141, -1, 172, 1129, 173, -1, 140, 1129, 172, -1, 142, 1130, 141, -1, 174, 1130, 142, -1, 173, 1130, 174, -1, 141, 1130, 173, -1, 143, 1131, 142, -1, 175, 1131, 143, -1, 174, 1131, 175, -1, 142, 1131, 174, -1, 144, 1132, 143, -1, 176, 1132, 144, -1, 175, 1132, 176, -1, 143, 1132, 175, -1, 145, 1133, 144, -1, 177, 1133, 145, -1, 176, 1133, 177, -1, 144, 1133, 176, -1, 146, 1134, 145, -1, 178, 1134, 146, -1, 177, 1134, 178, -1, 145, 1134, 177, -1, 147, 1135, 146, -1, 179, 1135, 147, -1, 178, 1135, 179, -1, 146, 1135, 178, -1, 148, 1136, 147, -1, 180, 1136, 148, -1, 179, 1136, 180, -1, 147, 1136, 179, -1, 149, 1137, 148, -1, 181, 1137, 149, -1, 180, 1137, 181, -1, 148, 1137, 180, -1, 150, 1138, 149, -1, 182, 1138, 150, -1, 181, 1138, 182, -1, 149, 1138, 181, -1, 151, 1139, 150, -1, 183, 1139, 151, -1, 182, 1139, 183, -1, 150, 1139, 182, -1, 152, 1140, 151, -1, 184, 1140, 152, -1, 183, 1140, 184, -1, 151, 1140, 183, -1, 153, 1141, 152, -1, 185, 1141, 153, -1, 184, 1141, 185, -1, 152, 1141, 184, -1, 154, 1142, 153, -1, 186, 1142, 154, -1, 185, 1142, 186, -1, 153, 1142, 185, -1, 155, 1143, 154, -1, 187, 1143, 155, -1, 186, 1143, 187, -1, 154, 1143, 186, -1, 156, 1144, 155, -1, 188, 1144, 156, -1, 187, 1144, 188, -1, 155, 1144, 187, -1, 157, 1145, 156, -1, 189, 1145, 157, -1, 188, 1145, 189, -1, 156, 1145, 188, -1, 158, 1146, 157, -1, 190, 1146, 158, -1, 189, 1146, 190, -1, 157, 1146, 189, -1, 159, 1147, 158, -1, 191, 1147, 159, -1, 190, 1147, 191, -1, 158, 1147, 190, -1, 161, 1148, 160, -1, 193, 1148, 161, -1, 192, 1148, 193, -1, 160, 1148, 192, -1, 162, 1149, 161, -1, 194, 1149, 162, -1, 193, 1149, 194, -1, 161, 1149, 193, -1, 163, 1150, 162, -1, 195, 1150, 163, -1, 194, 1150, 195, -1, 162, 1150, 194, -1, 164, 1151, 163, -1, 196, 1151, 164, -1, 195, 1151, 196, -1, 163, 1151, 195, -1, 165, 1152, 164, -1, 197, 1152, 165, -1, 196, 1152, 197, -1, 164, 1152, 196, -1, 166, 1153, 165, -1, 198, 1153, 166, -1, 197, 1153, 198, -1, 165, 1153, 197, -1, 167, 1154, 166, -1, 199, 1154, 167, -1, 198, 1154, 199, -1, 166, 1154, 198, -1, 168, 1155, 167, -1, 200, 1155, 168, -1, 199, 1155, 200, -1, 167, 1155, 199, -1, 169, 1156, 168, -1, 201, 1156, 169, -1, 200, 1156, 201, -1, 168, 1156, 200, -1, 170, 1157, 169, -1, 202, 1157, 170, -1, 201, 1157, 202, -1, 169, 1157, 201, -1, 171, 1158, 170, -1, 203, 1158, 171, -1, 202, 1158, 203, -1, 170, 1158, 202, -1, 172, 1159, 171, -1, 204, 1159, 172, -1, 203, 1159, 204, -1, 171, 1159, 203, -1, 173, 1160, 172, -1, 205, 1160, 173, -1, 204, 1160, 205, -1, 172, 1160, 204, -1, 174, 1161, 173, -1, 206, 1161, 174, -1, 205, 1161, 206, -1, 173, 1161, 205, -1, 175, 1162, 174, -1, 207, 1162, 175, -1, 206, 1162, 207, -1, 174, 1162, 206, -1, 176, 1163, 175, -1, 208, 1163, 176, -1, 207, 1163, 208, -1, 175, 1163, 207, -1, 177, 1164, 176, -1, 209, 1164, 177, -1, 208, 1164, 209, -1, 176, 1164, 208, -1, 178, 1165, 177, -1, 210, 1165, 178, -1, 209, 1165, 210, -1, 177, 1165, 209, -1, 179, 1166, 178, -1, 211, 1166, 179, -1, 210, 1166, 211, -1, 178, 1166, 210, -1, 180, 1167, 179, -1, 212, 1167, 180, -1, 211, 1167, 212, -1, 179, 1167, 211, -1, 181, 1168, 180, -1, 213, 1168, 181, -1, 212, 1168, 213, -1, 180, 1168, 212, -1, 182, 1169, 181, -1, 214, 1169, 182, -1, 213, 1169, 214, -1, 181, 1169, 213, -1, 183, 1170, 182, -1, 215, 1170, 183, -1, 214, 1170, 215, -1, 182, 1170, 214, -1, 184, 1171, 183, -1, 216, 1171, 184, -1, 215, 1171, 216, -1, 183, 1171, 215, -1, 185, 1172, 184, -1, 217, 1172, 185, -1, 216, 1172, 217, -1, 184, 1172, 216, -1, 186, 1173, 185, -1, 218, 1173, 186, -1, 217, 1173, 218, -1, 185, 1173, 217, -1, 187, 1174, 186, -1, 219, 1174, 187, -1, 218, 1174, 219, -1, 186, 1174, 218, -1, 188, 1175, 187, -1, 220, 1175, 188, -1, 219, 1175, 220, -1, 187, 1175, 219, -1, 189, 1176, 188, -1, 221, 1176, 189, -1, 220, 1176, 221, -1, 188, 1176, 220, -1, 190, 1177, 189, -1, 222, 1177, 190, -1, 221, 1177, 222, -1, 189, 1177, 221, -1, 191, 1178, 190, -1, 223, 1178, 191, -1, 222, 1178, 223, -1, 190, 1178, 222, -1, 193, 1179, 192, -1, 225, 1179, 193, -1, 224, 1179, 225, -1, 192, 1179, 224, -1, 194, 1180, 193, -1, 226, 1180, 194, -1, 225, 1180, 226, -1, 193, 1180, 225, -1, 195, 1181, 194, -1, 227, 1181, 195, -1, 226, 1181, 227, -1, 194, 1181, 226, -1, 196, 1182, 195, -1, 228, 1182, 196, -1, 227, 1182, 228, -1, 195, 1182, 227, -1, 197, 1183, 196, -1, 229, 1183, 197, -1, 228, 1183, 229, -1, 196, 1183, 228, -1, 198, 1184, 197, -1, 230, 1184, 198, -1, 229, 1184, 230, -1, 197, 1184, 229, -1, 199, 1185, 198, -1, 231, 1185, 199, -1, 230, 1185, 231, -1, 198, 1185, 230, -1, 200, 1186, 199, -1, 232, 1186, 200, -1, 231, 1186, 232, -1, 199, 1186, 231, -1, 201, 1187, 200, -1, 233, 1187, 201, -1, 232, 1187, 233, -1, 200, 1187, 232, -1, 202, 1188, 201, -1, 234, 1188, 202, -1, 233, 1188, 234, -1, 201, 1188, 233, -1, 203, 1189, 202, -1, 235, 1189, 203, -1, 234, 1189, 235, -1, 202, 1189, 234, -1, 204, 1190, 203, -1, 236, 1190, 204, -1, 235, 1190, 236, -1, 203, 1190, 235, -1, 205, 1191, 204, -1, 237, 1191, 205, -1, 236, 1191, 237, -1, 204, 1191, 236, -1, 206, 1192, 205, -1, 238, 1192, 206, -1, 237, 1192, 238, -1, 205, 1192, 237, -1, 207, 1193, 206, -1, 239, 1193, 207, -1, 238, 1193, 239, -1, 206, 1193, 238, -1, 208, 1194, 207, -1, 240, 1194, 208, -1, 239, 1194, 240, -1, 207, 1194, 239, -1, 209, 1195, 208, -1, 241, 1195, 209, -1, 240, 1195, 241, -1, 208, 1195, 240, -1, 210, 1196, 209, -1, 242, 1196, 210, -1, 241, 1196, 242, -1, 209, 1196, 241, -1, 211, 1197, 210, -1, 243, 1197, 211, -1, 242, 1197, 243, -1, 210, 1197, 242, -1, 212, 1198, 211, -1, 244, 1198, 212, -1, 243, 1198, 244, -1, 211, 1198, 243, -1, 213, 1199, 212, -1, 245, 1199, 213, -1, 244, 1199, 245, -1, 212, 1199, 244, -1, 214, 1200, 213, -1, 246, 1200, 214, -1, 245, 1200, 246, -1, 213, 1200, 245, -1, 215, 1201, 214, -1, 247, 1201, 215, -1, 246, 1201, 247, -1, 214, 1201, 246, -1, 216, 1202, 215, -1, 248, 1202, 216, -1, 247, 1202, 248, -1, 215, 1202, 247, -1, 217, 1203, 216, -1, 249, 1203, 217, -1, 248, 1203, 249, -1, 216, 1203, 248, -1, 218, 1204, 217, -1, 250, 1204, 218, -1, 249, 1204, 250, -1, 217, 1204, 249, -1, 219, 1205, 218, -1, 251, 1205, 219, -1, 250, 1205, 251, -1, 218, 1205, 250, -1, 220, 1206, 219, -1, 252, 1206, 220, -1, 251, 1206, 252, -1, 219, 1206, 251, -1, 221, 1207, 220, -1, 253, 1207, 221, -1, 252, 1207, 253, -1, 220, 1207, 252, -1, 222, 1208, 221, -1, 254, 1208, 222, -1, 253, 1208, 254, -1, 221, 1208, 253, -1, 223, 1209, 222, -1, 255, 1209, 223, -1, 254, 1209, 255, -1, 222, 1209, 254, -1, 225, 1210, 224, -1, 257, 1210, 225, -1, 256, 1210, 257, -1, 224, 1210, 256, -1, 226, 1211, 225, -1, 258, 1211, 226, -1, 257, 1211, 258, -1, 225, 1211, 257, -1, 227, 1212, 226, -1, 259, 1212, 227, -1, 258, 1212, 259, -1, 226, 1212, 258, -1, 228, 1213, 227, -1, 260, 1213, 228, -1, 259, 1213, 260, -1, 227, 1213, 259, -1, 229, 1214, 228, -1, 261, 1214, 229, -1, 260, 1214, 261, -1, 228, 1214, 260, -1, 230, 1215, 229, -1, 262, 1215, 230, -1, 261, 1215, 262, -1, 229, 1215, 261, -1, 231, 1216, 230, -1, 263, 1216, 231, -1, 262, 1216, 263, -1, 230, 1216, 262, -1, 232, 1217, 231, -1, 264, 1217, 232, -1, 263, 1217, 264, -1, 231, 1217, 263, -1, 233, 1218, 232, -1, 265, 1218, 233, -1, 264, 1218, 265, -1, 232, 1218, 264, -1, 234, 1219, 233, -1, 266, 1219, 234, -1, 265, 1219, 266, -1, 233, 1219, 265, -1, 235, 1220, 234, -1, 267, 1220, 235, -1, 266, 1220, 267, -1, 234, 1220, 266, -1, 236, 1221, 235, -1, 268, 1221, 236, -1, 267, 1221, 268, -1, 235, 1221, 267, -1, 237, 1222, 236, -1, 269, 1222, 237, -1, 268, 1222, 269, -1, 236, 1222, 268, -1, 238, 1223, 237, -1, 270, 1223, 238, -1, 269, 1223, 270, -1, 237, 1223, 269, -1, 239, 1224, 238, -1, 271, 1224, 239, -1, 270, 1224, 271, -1, 238, 1224, 270, -1, 240, 1225, 239, -1, 272, 1225, 240, -1, 271, 1225, 272, -1, 239, 1225, 271, -1, 241, 1226, 240, -1, 273, 1226, 241, -1, 272, 1226, 273, -1, 240, 1226, 272, -1, 242, 1227, 241, -1, 274, 1227, 242, -1, 273, 1227, 274, -1, 241, 1227, 273, -1, 243, 1228, 242, -1, 275, 1228, 243, -1, 274, 1228, 275, -1, 242, 1228, 274, -1, 244, 1229, 243, -1, 276, 1229, 244, -1, 275, 1229, 276, -1, 243, 1229, 275, -1, 245, 1230, 244, -1, 277, 1230, 245, -1, 276, 1230, 277, -1, 244, 1230, 276, -1, 246, 1231, 245, -1, 278, 1231, 246, -1, 277, 1231, 278, -1, 245, 1231, 277, -1, 247, 1232, 246, -1, 279, 1232, 247, -1, 278, 1232, 279, -1, 246, 1232, 278, -1, 248, 1233, 247, -1, 280, 1233, 248, -1, 279, 1233, 280, -1, 247, 1233, 279, -1, 249, 1234, 248, -1, 281, 1234, 249, -1, 280, 1234, 281, -1, 248, 1234, 280, -1, 250, 1235, 249, -1, 282, 1235, 250, -1, 281, 1235, 282, -1, 249, 1235, 281, -1, 251, 1236, 250, -1, 283, 1236, 251, -1, 282, 1236, 283, -1, 250, 1236, 282, -1, 252, 1237, 251, -1, 284, 1237, 252, -1, 283, 1237, 284, -1, 251, 1237, 283, -1, 253, 1238, 252, -1, 285, 1238, 253, -1, 284, 1238, 285, -1, 252, 1238, 284, -1, 254, 1239, 253, -1, 286, 1239, 254, -1, 285, 1239, 286, -1, 253, 1239, 285, -1, 255, 1240, 254, -1, 287, 1240, 255, -1, 286, 1240, 287, -1, 254, 1240, 286, -1, 257, 1241, 256, -1, 289, 1241, 257, -1, 288, 1241, 289, -1, 256, 1241, 288, -1, 258, 1242, 257, -1, 290, 1242, 258, -1, 289, 1242, 290, -1, 257, 1242, 289, -1, 259, 1243, 258, -1, 291, 1243, 259, -1, 290, 1243, 291, -1, 258, 1243, 290, -1, 260, 1244, 259, -1, 292, 1244, 260, -1, 291, 1244, 292, -1, 259, 1244, 291, -1, 261, 1245, 260, -1, 293, 1245, 261, -1, 292, 1245, 293, -1, 260, 1245, 292, -1, 262, 1246, 261, -1, 294, 1246, 262, -1, 293, 1246, 294, -1, 261, 1246, 293, -1, 263, 1247, 262, -1, 295, 1247, 263, -1, 294, 1247, 295, -1, 262, 1247, 294, -1, 264, 1248, 263, -1, 296, 1248, 264, -1, 295, 1248, 296, -1, 263, 1248, 295, -1, 265, 1249, 264, -1, 297, 1249, 265, -1, 296, 1249, 297, -1, 264, 1249, 296, -1, 266, 1250, 265, -1, 298, 1250, 266, -1, 297, 1250, 298, -1, 265, 1250, 297, -1, 267, 1251, 266, -1, 299, 1251, 267, -1, 298, 1251, 299, -1, 266, 1251, 298, -1, 268, 1252, 267, -1, 300, 1252, 268, -1, 299, 1252, 300, -1, 267, 1252, 299, -1, 269, 1253, 268, -1, 301, 1253, 269, -1, 300, 1253, 301, -1, 268, 1253, 300, -1, 270, 1254, 269, -1, 302, 1254, 270, -1, 301, 1254, 302, -1, 269, 1254, 301, -1, 271, 1255, 270, -1, 303, 1255, 271, -1, 302, 1255, 303, -1, 270, 1255, 302, -1, 272, 1256, 271, -1, 304, 1256, 272, -1, 303, 1256, 304, -1, 271, 1256, 303, -1, 273, 1257, 272, -1, 305, 1257, 273, -1, 304, 1257, 305, -1, 272, 1257, 304, -1, 274, 1258, 273, -1, 306, 1258, 274, -1, 305, 1258, 306, -1, 273, 1258, 305, -1, 275, 1259, 274, -1, 307, 1259, 275, -1, 306, 1259, 307, -1, 274, 1259, 306, -1, 276, 1260, 275, -1, 308, 1260, 276, -1, 307, 1260, 308, -1, 275, 1260, 307, -1, 277, 1261, 276, -1, 309, 1261, 277, -1, 308, 1261, 309, -1, 276, 1261, 308, -1, 278, 1262, 277, -1, 310, 1262, 278, -1, 309, 1262, 310, -1, 277, 1262, 309, -1, 279, 1263, 278, -1, 311, 1263, 279, -1, 310, 1263, 311, -1, 278, 1263, 310, -1, 280, 1264, 279, -1, 312, 1264, 280, -1, 311, 1264, 312, -1, 279, 1264, 311, -1, 281, 1265, 280, -1, 313, 1265, 281, -1, 312, 1265, 313, -1, 280, 1265, 312, -1, 282, 1266, 281, -1, 314, 1266, 282, -1, 313, 1266, 314, -1, 281, 1266, 313, -1, 283, 1267, 282, -1, 315, 1267, 283, -1, 314, 1267, 315, -1, 282, 1267, 314, -1, 284, 1268, 283, -1, 316, 1268, 284, -1, 315, 1268, 316, -1, 283, 1268, 315, -1, 285, 1269, 284, -1, 317, 1269, 285, -1, 316, 1269, 317, -1, 284, 1269, 316, -1, 286, 1270, 285, -1, 318, 1270, 286, -1, 317, 1270, 318, -1, 285, 1270, 317, -1, 287, 1271, 286, -1, 319, 1271, 287, -1, 318, 1271, 319, -1, 286, 1271, 318, -1, 289, 1272, 288, -1, 321, 1272, 289, -1, 320, 1272, 321, -1, 288, 1272, 320, -1, 290, 1273, 289, -1, 322, 1273, 290, -1, 321, 1273, 322, -1, 289, 1273, 321, -1, 291, 1274, 290, -1, 323, 1274, 291, -1, 322, 1274, 323, -1, 290, 1274, 322, -1, 292, 1275, 291, -1, 324, 1275, 292, -1, 323, 1275, 324, -1, 291, 1275, 323, -1, 293, 1276, 292, -1, 325, 1276, 293, -1, 324, 1276, 325, -1, 292, 1276, 324, -1, 294, 1277, 293, -1, 326, 1277, 294, -1, 325, 1277, 326, -1, 293, 1277, 325, -1, 295, 1278, 294, -1, 327, 1278, 295, -1, 326, 1278, 327, -1, 294, 1278, 326, -1, 296, 1279, 295, -1, 328, 1279, 296, -1, 327, 1279, 328, -1, 295, 1279, 327, -1, 297, 1280, 296, -1, 329, 1280, 297, -1, 328, 1280, 329, -1, 296, 1280, 328, -1, 298, 1281, 297, -1, 330, 1281, 298, -1, 329, 1281, 330, -1, 297, 1281, 329, -1, 299, 1282, 298, -1, 331, 1282, 299, -1, 330, 1282, 331, -1, 298, 1282, 330, -1, 300, 1283, 299, -1, 332, 1283, 300, -1, 331, 1283, 332, -1, 299, 1283, 331, -1, 301, 1284, 300, -1, 333, 1284, 301, -1, 332, 1284, 333, -1, 300, 1284, 332, -1, 302, 1285, 301, -1, 334, 1285, 302, -1, 333, 1285, 334, -1, 301, 1285, 333, -1, 303, 1286, 302, -1, 335, 1286, 303, -1, 334, 1286, 335, -1, 302, 1286, 334, -1, 304, 1287, 303, -1, 336, 1287, 304, -1, 335, 1287, 336, -1, 303, 1287, 335, -1, 305, 1288, 304, -1, 337, 1288, 305, -1, 336, 1288, 337, -1, 304, 1288, 336, -1, 306, 1289, 305, -1, 338, 1289, 306, -1, 337, 1289, 338, -1, 305, 1289, 337, -1, 307, 1290, 306, -1, 339, 1290, 307, -1, 338, 1290, 339, -1, 306, 1290, 338, -1, 308, 1291, 307, -1, 340, 1291, 308, -1, 339, 1291, 340, -1, 307, 1291, 339, -1, 309, 1292, 308, -1, 341, 1292, 309, -1, 340, 1292, 341, -1, 308, 1292, 340, -1, 310, 1293, 309, -1, 342, 1293, 310, -1, 341, 1293, 342, -1, 309, 1293, 341, -1, 311, 1294, 310, -1, 343, 1294, 311, -1, 342, 1294, 343, -1, 310, 1294, 342, -1, 312, 1295, 311, -1, 344, 1295, 312, -1, 343, 1295, 344, -1, 311, 1295, 343, -1, 313, 1296, 312, -1, 345, 1296, 313, -1, 344, 1296, 345, -1, 312, 1296, 344, -1, 314, 1297, 313, -1, 346, 1297, 314, -1, 345, 1297, 346, -1, 313, 1297, 345, -1, 315, 1298, 314, -1, 347, 1298, 315, -1, 346, 1298, 347, -1, 314, 1298, 346, -1, 316, 1299, 315, -1, 348, 1299, 316, -1, 347, 1299, 348, -1, 315, 1299, 347, -1, 317, 1300, 316, -1, 349, 1300, 317, -1, 348, 1300, 349, -1, 316, 1300, 348, -1, 318, 1301, 317, -1, 350, 1301, 318, -1, 349, 1301, 350, -1, 317, 1301, 349, -1, 319, 1302, 318, -1, 351, 1302, 319, -1, 350, 1302, 351, -1, 318, 1302, 350, -1, 321, 1303, 320, -1, 353, 1303, 321, -1, 352, 1303, 353, -1, 320, 1303, 352, -1, 322, 1304, 321, -1, 354, 1304, 322, -1, 353, 1304, 354, -1, 321, 1304, 353, -1, 323, 1305, 322, -1, 355, 1305, 323, -1, 354, 1305, 355, -1, 322, 1305, 354, -1, 324, 1306, 323, -1, 356, 1306, 324, -1, 355, 1306, 356, -1, 323, 1306, 355, -1, 325, 1307, 324, -1, 357, 1307, 325, -1, 356, 1307, 357, -1, 324, 1307, 356, -1, 326, 1308, 325, -1, 358, 1308, 326, -1, 357, 1308, 358, -1, 325, 1308, 357, -1, 327, 1309, 326, -1, 359, 1309, 327, -1, 358, 1309, 359, -1, 326, 1309, 358, -1, 328, 1310, 327, -1, 360, 1310, 328, -1, 359, 1310, 360, -1, 327, 1310, 359, -1, 329, 1311, 328, -1, 361, 1311, 329, -1, 360, 1311, 361, -1, 328, 1311, 360, -1, 330, 1312, 329, -1, 362, 1312, 330, -1, 361, 1312, 362, -1, 329, 1312, 361, -1, 331, 1313, 330, -1, 363, 1313, 331, -1, 362, 1313, 363, -1, 330, 1313, 362, -1, 332, 1314, 331, -1, 364, 1314, 332, -1, 363, 1314, 364, -1, 331, 1314, 363, -1, 333, 1315, 332, -1, 365, 1315, 333, -1, 364, 1315, 365, -1, 332, 1315, 364, -1, 334, 1316, 333, -1, 366, 1316, 334, -1, 365, 1316, 366, -1, 333, 1316, 365, -1, 335, 1317, 334, -1, 367, 1317, 335, -1, 366, 1317, 367, -1, 334, 1317, 366, -1, 336, 1318, 335, -1, 368, 1318, 336, -1, 367, 1318, 368, -1, 335, 1318, 367, -1, 337, 1319, 336, -1, 369, 1319, 337, -1, 368, 1319, 369, -1, 336, 1319, 368, -1, 338, 1320, 337, -1, 370, 1320, 338, -1, 369, 1320, 370, -1, 337, 1320, 369, -1, 339, 1321, 338, -1, 371, 1321, 339, -1, 370, 1321, 371, -1, 338, 1321, 370, -1, 340, 1322, 339, -1, 372, 1322, 340, -1, 371, 1322, 372, -1, 339, 1322, 371, -1, 341, 1323, 340, -1, 373, 1323, 341, -1, 372, 1323, 373, -1, 340, 1323, 372, -1, 342, 1324, 341, -1, 374, 1324, 342, -1, 373, 1324, 374, -1, 341, 1324, 373, -1, 343, 1325, 342, -1, 375, 1325, 343, -1, 374, 1325, 375, -1, 342, 1325, 374, -1, 344, 1326, 343, -1, 376, 1326, 344, -1, 375, 1326, 376, -1, 343, 1326, 375, -1, 345, 1327, 344, -1, 377, 1327, 345, -1, 376, 1327, 377, -1, 344, 1327, 376, -1, 346, 1328, 345, -1, 378, 1328, 346, -1, 377, 1328, 378, -1, 345, 1328, 377, -1, 347, 1329, 346, -1, 379, 1329, 347, -1, 378, 1329, 379, -1, 346, 1329, 378, -1, 348, 1330, 347, -1, 380, 1330, 348, -1, 379, 1330, 380, -1, 347, 1330, 379, -1, 349, 1331, 348, -1, 381, 1331, 349, -1, 380, 1331, 381, -1, 348, 1331, 380, -1, 350, 1332, 349, -1, 382, 1332, 350, -1, 381, 1332, 382, -1, 349, 1332, 381, -1, 351, 1333, 350, -1, 383, 1333, 351, -1, 382, 1333, 383, -1, 350, 1333, 382, -1, 353, 1334, 352, -1, 385, 1334, 353, -1, 384, 1334, 385, -1, 352, 1334, 384, -1, 354, 1335, 353, -1, 386, 1335, 354, -1, 385, 1335, 386, -1, 353, 1335, 385, -1, 355, 1336, 354, -1, 387, 1336, 355, -1, 386, 1336, 387, -1, 354, 1336, 386, -1, 356, 1337, 355, -1, 388, 1337, 356, -1, 387, 1337, 388, -1, 355, 1337, 387, -1, 357, 1338, 356, -1, 389, 1338, 357, -1, 388, 1338, 389, -1, 356, 1338, 388, -1, 358, 1339, 357, -1, 390, 1339, 358, -1, 389, 1339, 390, -1, 357, 1339, 389, -1, 359, 1340, 358, -1, 391, 1340, 359, -1, 390, 1340, 391, -1, 358, 1340, 390, -1, 360, 1341, 359, -1, 392, 1341, 360, -1, 391, 1341, 392, -1, 359, 1341, 391, -1, 361, 1342, 360, -1, 393, 1342, 361, -1, 392, 1342, 393, -1, 360, 1342, 392, -1, 362, 1343, 361, -1, 394, 1343, 362, -1, 393, 1343, 394, -1, 361, 1343, 393, -1, 363, 1344, 362, -1, 395, 1344, 363, -1, 394, 1344, 395, -1, 362, 1344, 394, -1, 364, 1345, 363, -1, 396, 1345, 364, -1, 395, 1345, 396, -1, 363, 1345, 395, -1, 365, 1346, 364, -1, 397, 1346, 365, -1, 396, 1346, 397, -1, 364, 1346, 396, -1, 366, 1347, 365, -1, 398, 1347, 366, -1, 397, 1347, 398, -1, 365, 1347, 397, -1, 367, 1348, 366, -1, 399, 1348, 367, -1, 398, 1348, 399, -1, 366, 1348, 398, -1, 368, 1349, 367, -1, 400, 1349, 368, -1, 399, 1349, 400, -1, 367, 1349, 399, -1, 369, 1350, 368, -1, 401, 1350, 369, -1, 400, 1350, 401, -1, 368, 1350, 400, -1, 370, 1351, 369, -1, 402, 1351, 370, -1, 401, 1351, 402, -1, 369, 1351, 401, -1, 371, 1352, 370, -1, 403, 1352, 371, -1, 402, 1352, 403, -1, 370, 1352, 402, -1, 372, 1353, 371, -1, 404, 1353, 372, -1, 403, 1353, 404, -1, 371, 1353, 403, -1, 373, 1354, 372, -1, 405, 1354, 373, -1, 404, 1354, 405, -1, 372, 1354, 404, -1, 374, 1355, 373, -1, 406, 1355, 374, -1, 405, 1355, 406, -1, 373, 1355, 405, -1, 375, 1356, 374, -1, 407, 1356, 375, -1, 406, 1356, 407, -1, 374, 1356, 406, -1, 376, 1357, 375, -1, 408, 1357, 376, -1, 407, 1357, 408, -1, 375, 1357, 407, -1, 377, 1358, 376, -1, 409, 1358, 377, -1, 408, 1358, 409, -1, 376, 1358, 408, -1, 378, 1359, 377, -1, 410, 1359, 378, -1, 409, 1359, 410, -1, 377, 1359, 409, -1, 379, 1360, 378, -1, 411, 1360, 379, -1, 410, 1360, 411, -1, 378, 1360, 410, -1, 380, 1361, 379, -1, 412, 1361, 380, -1, 411, 1361, 412, -1, 379, 1361, 411, -1, 381, 1362, 380, -1, 413, 1362, 381, -1, 412, 1362, 413, -1, 380, 1362, 412, -1, 382, 1363, 381, -1, 414, 1363, 382, -1, 413, 1363, 414, -1, 381, 1363, 413, -1, 383, 1364, 382, -1, 415, 1364, 383, -1, 414, 1364, 415, -1, 382, 1364, 414, -1, 385, 1365, 384, -1, 417, 1365, 385, -1, 416, 1365, 417, -1, 384, 1365, 416, -1, 386, 1366, 385, -1, 418, 1366, 386, -1, 417, 1366, 418, -1, 385, 1366, 417, -1, 387, 1367, 386, -1, 419, 1367, 387, -1, 418, 1367, 419, -1, 386, 1367, 418, -1, 388, 1368, 387, -1, 420, 1368, 388, -1, 419, 1368, 420, -1, 387, 1368, 419, -1, 389, 1369, 388, -1, 421, 1369, 389, -1, 420, 1369, 421, -1, 388, 1369, 420, -1, 390, 1370, 389, -1, 422, 1370, 390, -1, 421, 1370, 422, -1, 389, 1370, 421, -1, 391, 1371, 390, -1, 423, 1371, 391, -1, 422, 1371, 423, -1, 390, 1371, 422, -1, 392, 1372, 391, -1, 424, 1372, 392, -1, 423, 1372, 424, -1, 391, 1372, 423, -1, 393, 1373, 392, -1, 425, 1373, 393, -1, 424, 1373, 425, -1, 392, 1373, 424, -1, 394, 1374, 393, -1, 426, 1374, 394, -1, 425, 1374, 426, -1, 393, 1374, 425, -1, 395, 1375, 394, -1, 427, 1375, 395, -1, 426, 1375, 427, -1, 394, 1375, 426, -1, 396, 1376, 395, -1, 428, 1376, 396, -1, 427, 1376, 428, -1, 395, 1376, 427, -1, 397, 1377, 396, -1, 429, 1377, 397, -1, 428, 1377, 429, -1, 396, 1377, 428, -1, 398, 1378, 397, -1, 430, 1378, 398, -1, 429, 1378, 430, -1, 397, 1378, 429, -1, 399, 1379, 398, -1, 431, 1379, 399, -1, 430, 1379, 431, -1, 398, 1379, 430, -1, 400, 1380, 399, -1, 432, 1380, 400, -1, 431, 1380, 432, -1, 399, 1380, 431, -1, 401, 1381, 400, -1, 433, 1381, 401, -1, 432, 1381, 433, -1, 400, 1381, 432, -1, 402, 1382, 401, -1, 434, 1382, 402, -1, 433, 1382, 434, -1, 401, 1382, 433, -1, 403, 1383, 402, -1, 435, 1383, 403, -1, 434, 1383, 435, -1, 402, 1383, 434, -1, 404, 1384, 403, -1, 436, 1384, 404, -1, 435, 1384, 436, -1, 403, 1384, 435, -1, 405, 1385, 404, -1, 437, 1385, 405, -1, 436, 1385, 437, -1, 404, 1385, 436, -1, 406, 1386, 405, -1, 438, 1386, 406, -1, 437, 1386, 438, -1, 405, 1386, 437, -1, 407, 1387, 406, -1, 439, 1387, 407, -1, 438, 1387, 439, -1, 406, 1387, 438, -1, 408, 1388, 407, -1, 440, 1388, 408, -1, 439, 1388, 440, -1, 407, 1388, 439, -1, 409, 1389, 408, -1, 441, 1389, 409, -1, 440, 1389, 441, -1, 408, 1389, 440, -1, 410, 1390, 409, -1, 442, 1390, 410, -1, 441, 1390, 442, -1, 409, 1390, 441, -1, 411, 1391, 410, -1, 443, 1391, 411, -1, 442, 1391, 443, -1, 410, 1391, 442, -1, 412, 1392, 411, -1, 444, 1392, 412, -1, 443, 1392, 444, -1, 411, 1392, 443, -1, 413, 1393, 412, -1, 445, 1393, 413, -1, 444, 1393, 445, -1, 412, 1393, 444, -1, 414, 1394, 413, -1, 446, 1394, 414, -1, 445, 1394, 446, -1, 413, 1394, 445, -1, 415, 1395, 414, -1, 447, 1395, 415, -1, 446, 1395, 447, -1, 414, 1395, 446, -1, 417, 1396, 416, -1, 449, 1396, 417, -1, 448, 1396, 449, -1, 416, 1396, 448, -1, 418, 1397, 417, -1, 450, 1397, 418, -1, 449, 1397, 450, -1, 417, 1397, 449, -1, 419, 1398, 418, -1, 451, 1398, 419, -1, 450, 1398, 451, -1, 418, 1398, 450, -1, 420, 1399, 419, -1, 452, 1399, 420, -1, 451, 1399, 452, -1, 419, 1399, 451, -1, 421, 1400, 420, -1, 453, 1400, 421, -1, 452, 1400, 453, -1, 420, 1400, 452, -1, 422, 1401, 421, -1, 454, 1401, 422, -1, 453, 1401, 454, -1, 421, 1401, 453, -1, 423, 1402, 422, -1, 455, 1402, 423, -1, 454, 1402, 455, -1, 422, 1402, 454, -1, 424, 1403, 423, -1, 456, 1403, 424, -1, 455, 1403, 456, -1, 423, 1403, 455, -1, 425, 1404, 424, -1, 457, 1404, 425, -1, 456, 1404, 457, -1, 424, 1404, 456, -1, 426, 1405, 425, -1, 458, 1405, 426, -1, 457, 1405, 458, -1, 425, 1405, 457, -1, 427, 1406, 426, -1, 459, 1406, 427, -1, 458, 1406, 459, -1, 426, 1406, 458, -1, 428, 1407, 427, -1, 460, 1407, 428, -1, 459, 1407, 460, -1, 427, 1407, 459, -1, 429, 1408, 428, -1, 461, 1408, 429, -1, 460, 1408, 461, -1, 428, 1408, 460, -1, 430, 1409, 429, -1, 462, 1409, 430, -1, 461, 1409, 462, -1, 429, 1409, 461, -1, 431, 1410, 430, -1, 463, 1410, 431, -1, 462, 1410, 463, -1, 430, 1410, 462, -1, 432, 1411, 431, -1, 464, 1411, 432, -1, 463, 1411, 464, -1, 431, 1411, 463, -1, 433, 1412, 432, -1, 465, 1412, 433, -1, 464, 1412, 465, -1, 432, 1412, 464, -1, 434, 1413, 433, -1, 466, 1413, 434, -1, 465, 1413, 466, -1, 433, 1413, 465, -1, 435, 1414, 434, -1, 467, 1414, 435, -1, 466, 1414, 467, -1, 434, 1414, 466, -1, 436, 1415, 435, -1, 468, 1415, 436, -1, 467, 1415, 468, -1, 435, 1415, 467, -1, 437, 1416, 436, -1, 469, 1416, 437, -1, 468, 1416, 469, -1, 436, 1416, 468, -1, 438, 1417, 437, -1, 470, 1417, 438, -1, 469, 1417, 470, -1, 437, 1417, 469, -1, 439, 1418, 438, -1, 471, 1418, 439, -1, 470, 1418, 471, -1, 438, 1418, 470, -1, 440, 1419, 439, -1, 472, 1419, 440, -1, 471, 1419, 472, -1, 439, 1419, 471, -1, 441, 1420, 440, -1, 473, 1420, 441, -1, 472, 1420, 473, -1, 440, 1420, 472, -1, 442, 1421, 441, -1, 474, 1421, 442, -1, 473, 1421, 474, -1, 441, 1421, 473, -1, 443, 1422, 442, -1, 475, 1422, 443, -1, 474, 1422, 475, -1, 442, 1422, 474, -1, 444, 1423, 443, -1, 476, 1423, 444, -1, 475, 1423, 476, -1, 443, 1423, 475, -1, 445, 1424, 444, -1, 477, 1424, 445, -1, 476, 1424, 477, -1, 444, 1424, 476, -1, 446, 1425, 445, -1, 478, 1425, 446, -1, 477, 1425, 478, -1, 445, 1425, 477, -1, 447, 1426, 446, -1, 479, 1426, 447, -1, 478, 1426, 479, -1, 446, 1426, 478, -1, 449, 1427, 448, -1, 481, 1427, 449, -1, 480, 1427, 481, -1, 448, 1427, 480, -1, 450, 1428, 449, -1, 482, 1428, 450, -1, 481, 1428, 482, -1, 449, 1428, 481, -1, 451, 1429, 450, -1, 483, 1429, 451, -1, 482, 1429, 483, -1, 450, 1429, 482, -1, 452, 1430, 451, -1, 484, 1430, 452, -1, 483, 1430, 484, -1, 451, 1430, 483, -1, 453, 1431, 452, -1, 485, 1431, 453, -1, 484, 1431, 485, -1, 452, 1431, 484, -1, 454, 1432, 453, -1, 486, 1432, 454, -1, 485, 1432, 486, -1, 453, 1432, 485, -1, 455, 1433, 454, -1, 487, 1433, 455, -1, 486, 1433, 487, -1, 454, 1433, 486, -1, 456, 1434, 455, -1, 488, 1434, 456, -1, 487, 1434, 488, -1, 455, 1434, 487, -1, 457, 1435, 456, -1, 489, 1435, 457, -1, 488, 1435, 489, -1, 456, 1435, 488, -1, 458, 1436, 457, -1, 490, 1436, 458, -1, 489, 1436, 490, -1, 457, 1436, 489, -1, 459, 1437, 458, -1, 491, 1437, 459, -1, 490, 1437, 491, -1, 458, 1437, 490, -1, 460, 1438, 459, -1, 492, 1438, 460, -1, 491, 1438, 492, -1, 459, 1438, 491, -1, 461, 1439, 460, -1, 493, 1439, 461, -1, 492, 1439, 493, -1, 460, 1439, 492, -1, 462, 1440, 461, -1, 494, 1440, 462, -1, 493, 1440, 494, -1, 461, 1440, 493, -1, 463, 1441, 462, -1, 495, 1441, 463, -1, 494, 1441, 495, -1, 462, 1441, 494, -1, 464, 1442, 463, -1, 496, 1442, 464, -1, 495, 1442, 496, -1, 463, 1442, 495, -1, 465, 1443, 464, -1, 497, 1443, 465, -1, 496, 1443, 497, -1, 464, 1443, 496, -1, 466, 1444, 465, -1, 498, 1444, 466, -1, 497, 1444, 498, -1, 465, 1444, 497, -1, 467, 1445, 466, -1, 499, 1445, 467, -1, 498, 1445, 499, -1, 466, 1445, 498, -1, 468, 1446, 467, -1, 500, 1446, 468, -1, 499, 1446, 500, -1, 467, 1446, 499, -1, 469, 1447, 468, -1, 501, 1447, 469, -1, 500, 1447, 501, -1, 468, 1447, 500, -1, 470, 1448, 469, -1, 502, 1448, 470, -1, 501, 1448, 502, -1, 469, 1448, 501, -1, 471, 1449, 470, -1, 503, 1449, 471, -1, 502, 1449, 503, -1, 470, 1449, 502, -1, 472, 1450, 471, -1, 504, 1450, 472, -1, 503, 1450, 504, -1, 471, 1450, 503, -1, 473, 1451, 472, -1, 505, 1451, 473, -1, 504, 1451, 505, -1, 472, 1451, 504, -1, 474, 1452, 473, -1, 506, 1452, 474, -1, 505, 1452, 506, -1, 473, 1452, 505, -1, 475, 1453, 474, -1, 507, 1453, 475, -1, 506, 1453, 507, -1, 474, 1453, 506, -1, 476, 1454, 475, -1, 508, 1454, 476, -1, 507, 1454, 508, -1, 475, 1454, 507, -1, 477, 1455, 476, -1, 509, 1455, 477, -1, 508, 1455, 509, -1, 476, 1455, 508, -1, 478, 1456, 477, -1, 510, 1456, 478, -1, 509, 1456, 510, -1, 477, 1456, 509, -1, 479, 1457, 478, -1, 511, 1457, 479, -1, 510, 1457, 511, -1, 478, 1457, 510, -1, 481, 1458, 480, -1, 513, 1458, 481, -1, 512, 1458, 513, -1, 480, 1458, 512, -1, 482, 1459, 481, -1, 514, 1459, 482, -1, 513, 1459, 514, -1, 481, 1459, 513, -1, 483, 1460, 482, -1, 515, 1460, 483, -1, 514, 1460, 515, -1, 482, 1460, 514, -1, 484, 1461, 483, -1, 516, 1461, 484, -1, 515, 1461, 516, -1, 483, 1461, 515, -1, 485, 1462, 484, -1, 517, 1462, 485, -1, 516, 1462, 517, -1, 484, 1462, 516, -1, 486, 1463, 485, -1, 518, 1463, 486, -1, 517, 1463, 518, -1, 485, 1463, 517, -1, 487, 1464, 486, -1, 519, 1464, 487, -1, 518, 1464, 519, -1, 486, 1464, 518, -1, 488, 1465, 487, -1, 520, 1465, 488, -1, 519, 1465, 520, -1, 487, 1465, 519, -1, 489, 1466, 488, -1, 521, 1466, 489, -1, 520, 1466, 521, -1, 488, 1466, 520, -1, 490, 1467, 489, -1, 522, 1467, 490, -1, 521, 1467, 522, -1, 489, 1467, 521, -1, 491, 1468, 490, -1, 523, 1468, 491, -1, 522, 1468, 523, -1, 490, 1468, 522, -1, 492, 1469, 491, -1, 524, 1469, 492, -1, 523, 1469, 524, -1, 491, 1469, 523, -1, 493, 1470, 492, -1, 525, 1470, 493, -1, 524, 1470, 525, -1, 492, 1470, 524, -1, 494, 1471, 493, -1, 526, 1471, 494, -1, 525, 1471, 526, -1, 493, 1471, 525, -1, 495, 1472, 494, -1, 527, 1472, 495, -1, 526, 1472, 527, -1, 494, 1472, 526, -1, 496, 1473, 495, -1, 528, 1473, 496, -1, 527, 1473, 528, -1, 495, 1473, 527, -1, 497, 1474, 496, -1, 529, 1474, 497, -1, 528, 1474, 529, -1, 496, 1474, 528, -1, 498, 1475, 497, -1, 530, 1475, 498, -1, 529, 1475, 530, -1, 497, 1475, 529, -1, 499, 1476, 498, -1, 531, 1476, 499, -1, 530, 1476, 531, -1, 498, 1476, 530, -1, 500, 1477, 499, -1, 532, 1477, 500, -1, 531, 1477, 532, -1, 499, 1477, 531, -1, 501, 1478, 500, -1, 533, 1478, 501, -1, 532, 1478, 533, -1, 500, 1478, 532, -1, 502, 1479, 501, -1, 534, 1479, 502, -1, 533, 1479, 534, -1, 501, 1479, 533, -1, 503, 1480, 502, -1, 535, 1480, 503, -1, 534, 1480, 535, -1, 502, 1480, 534, -1, 504, 1481, 503, -1, 536, 1481, 504, -1, 535, 1481, 536, -1, 503, 1481, 535, -1, 505, 1482, 504, -1, 537, 1482, 505, -1, 536, 1482, 537, -1, 504, 1482, 536, -1, 506, 1483, 505, -1, 538, 1483, 506, -1, 537, 1483, 538, -1, 505, 1483, 537, -1, 507, 1484, 506, -1, 539, 1484, 507, -1, 538, 1484, 539, -1, 506, 1484, 538, -1, 508, 1485, 507, -1, 540, 1485, 508, -1, 539, 1485, 540, -1, 507, 1485, 539, -1, 509, 1486, 508, -1, 541, 1486, 509, -1, 540, 1486, 541, -1, 508, 1486, 540, -1, 510, 1487, 509, -1, 542, 1487, 510, -1, 541, 1487, 542, -1, 509, 1487, 541, -1, 511, 1488, 510, -1, 543, 1488, 511, -1, 542, 1488, 543, -1, 510, 1488, 542, -1, 513, 1489, 512, -1, 545, 1489, 513, -1, 544, 1489, 545, -1, 512, 1489, 544, -1, 514, 1490, 513, -1, 546, 1490, 514, -1, 545, 1490, 546, -1, 513, 1490, 545, -1, 515, 1491, 514, -1, 547, 1491, 515, -1, 546, 1491, 547, -1, 514, 1491, 546, -1, 516, 1492, 515, -1, 548, 1492, 516, -1, 547, 1492, 548, -1, 515, 1492, 547, -1, 517, 1493, 516, -1, 549, 1493, 517, -1, 548, 1493, 549, -1, 516, 1493, 548, -1, 518, 1494, 517, -1, 550, 1494, 518, -1, 549, 1494, 550, -1, 517, 1494, 549, -1, 519, 1495, 518, -1, 551, 1495, 519, -1, 550, 1495, 551, -1, 518, 1495, 550, -1, 520, 1496, 519, -1, 552, 1496, 520, -1, 551, 1496, 552, -1, 519, 1496, 551, -1, 521, 1497, 520, -1, 553, 1497, 521, -1, 552, 1497, 553, -1, 520, 1497, 552, -1, 522, 1498, 521, -1, 554, 1498, 522, -1, 553, 1498, 554, -1, 521, 1498, 553, -1, 523, 1499, 522, -1, 555, 1499, 523, -1, 554, 1499, 555, -1, 522, 1499, 554, -1, 524, 1500, 523, -1, 556, 1500, 524, -1, 555, 1500, 556, -1, 523, 1500, 555, -1, 525, 1501, 524, -1, 557, 1501, 525, -1, 556, 1501, 557, -1, 524, 1501, 556, -1, 526, 1502, 525, -1, 558, 1502, 526, -1, 557, 1502, 558, -1, 525, 1502, 557, -1, 527, 1503, 526, -1, 559, 1503, 527, -1, 558, 1503, 559, -1, 526, 1503, 558, -1, 528, 1504, 527, -1, 560, 1504, 528, -1, 559, 1504, 560, -1, 527, 1504, 559, -1, 529, 1505, 528, -1, 561, 1505, 529, -1, 560, 1505, 561, -1, 528, 1505, 560, -1, 530, 1506, 529, -1, 562, 1506, 530, -1, 561, 1506, 562, -1, 529, 1506, 561, -1, 531, 1507, 530, -1, 563, 1507, 531, -1, 562, 1507, 563, -1, 530, 1507, 562, -1, 532, 1508, 531, -1, 564, 1508, 532, -1, 563, 1508, 564, -1, 531, 1508, 563, -1, 533, 1509, 532, -1, 565, 1509, 533, -1, 564, 1509, 565, -1, 532, 1509, 564, -1, 534, 1510, 533, -1, 566, 1510, 534, -1, 565, 1510, 566, -1, 533, 1510, 565, -1, 535, 1511, 534, -1, 567, 1511, 535, -1, 566, 1511, 567, -1, 534, 1511, 566, -1, 536, 1512, 535, -1, 568, 1512, 536, -1, 567, 1512, 568, -1, 535, 1512, 567, -1, 537, 1513, 536, -1, 569, 1513, 537, -1, 568, 1513, 569, -1, 536, 1513, 568, -1, 538, 1514, 537, -1, 570, 1514, 538, -1, 569, 1514, 570, -1, 537, 1514, 569, -1, 539, 1515, 538, -1, 571, 1515, 539, -1, 570, 1515, 571, -1, 538, 1515, 570, -1, 540, 1516, 539, -1, 572, 1516, 540, -1, 571, 1516, 572, -1, 539, 1516, 571, -1, 541, 1517, 540, -1, 573, 1517, 541, -1, 572, 1517, 573, -1, 540, 1517, 572, -1, 542, 1518, 541, -1, 574, 1518, 542, -1, 573, 1518, 574, -1, 541, 1518, 573, -1, 543, 1519, 542, -1, 575, 1519, 543, -1, 574, 1519, 575, -1, 542, 1519, 574, -1, 545, 1520, 544, -1, 577, 1520, 545, -1, 576, 1520, 577, -1, 544, 1520, 576, -1, 546, 1521, 545, -1, 578, 1521, 546, -1, 577, 1521, 578, -1, 545, 1521, 577, -1, 547, 1522, 546, -1, 579, 1522, 547, -1, 578, 1522, 579, -1, 546, 1522, 578, -1, 548, 1523, 547, -1, 580, 1523, 548, -1, 579, 1523, 580, -1, 547, 1523, 579, -1, 549, 1524, 548, -1, 581, 1524, 549, -1, 580, 1524, 581, -1, 548, 1524, 580, -1, 550, 1525, 549, -1, 582, 1525, 550, -1, 581, 1525, 582, -1, 549, 1525, 581, -1, 551, 1526, 550, -1, 583, 1526, 551, -1, 582, 1526, 583, -1, 550, 1526, 582, -1, 552, 1527, 551, -1, 584, 1527, 552, -1, 583, 1527, 584, -1, 551, 1527, 583, -1, 553, 1528, 552, -1, 585, 1528, 553, -1, 584, 1528, 585, -1, 552, 1528, 584, -1, 554, 1529, 553, -1, 586, 1529, 554, -1, 585, 1529, 586, -1, 553, 1529, 585, -1, 555, 1530, 554, -1, 587, 1530, 555, -1, 586, 1530, 587, -1, 554, 1530, 586, -1, 556, 1531, 555, -1, 588, 1531, 556, -1, 587, 1531, 588, -1, 555, 1531, 587, -1, 557, 1532, 556, -1, 589, 1532, 557, -1, 588, 1532, 589, -1, 556, 1532, 588, -1, 558, 1533, 557, -1, 590, 1533, 558, -1, 589, 1533, 590, -1, 557, 1533, 589, -1, 559, 1534, 558, -1, 591, 1534, 559, -1, 590, 1534, 591, -1, 558, 1534, 590, -1, 560, 1535, 559, -1, 592, 1535, 560, -1, 591, 1535, 592, -1, 559, 1535, 591, -1, 561, 1536, 560, -1, 593, 1536, 561, -1, 592, 1536, 593, -1, 560, 1536, 592, -1, 562, 1537, 561, -1, 594, 1537, 562, -1, 593, 1537, 594, -1, 561, 1537, 593, -1, 563, 1538, 562, -1, 595, 1538, 563, -1, 594, 1538, 595, -1, 562, 1538, 594, -1, 564, 1539, 563, -1, 596, 1539, 564, -1, 595, 1539, 596, -1, 563, 1539, 595, -1, 565, 1540, 564, -1, 597, 1540, 565, -1, 596, 1540, 597, -1, 564, 1540, 596, -1, 566, 1541, 565, -1, 598, 1541, 566, -1, 597, 1541, 598, -1, 565, 1541, 597, -1, 567, 1542, 566, -1, 599, 1542, 567, -1, 598, 1542, 599, -1, 566, 1542, 598, -1, 568, 1543, 567, -1, 600, 1543, 568, -1, 599, 1543, 600, -1, 567, 1543, 599, -1, 569, 1544, 568, -1, 601, 1544, 569, -1, 600, 1544, 601, -1, 568, 1544, 600, -1, 570, 1545, 569, -1, 602, 1545, 570, -1, 601, 1545, 602, -1, 569, 1545, 601, -1, 571, 1546, 570, -1, 603, 1546, 571, -1, 602, 1546, 603, -1, 570, 1546, 602, -1, 572, 1547, 571, -1, 604, 1547, 572, -1, 603, 1547, 604, -1, 571, 1547, 603, -1, 573, 1548, 572, -1, 605, 1548, 573, -1, 604, 1548, 605, -1, 572, 1548, 604, -1, 574, 1549, 573, -1, 606, 1549, 574, -1, 605, 1549, 606, -1, 573, 1549, 605, -1, 575, 1550, 574, -1, 607, 1550, 575, -1, 606, 1550, 607, -1, 574, 1550, 606, -1, 577, 1551, 576, -1, 609, 1551, 577, -1, 608, 1551, 609, -1, 576, 1551, 608, -1, 578, 1552, 577, -1, 610, 1552, 578, -1, 609, 1552, 610, -1, 577, 1552, 609, -1, 579, 1553, 578, -1, 611, 1553, 579, -1, 610, 1553, 611, -1, 578, 1553, 610, -1, 580, 1554, 579, -1, 612, 1554, 580, -1, 611, 1554, 612, -1, 579, 1554, 611, -1, 581, 1555, 580, -1, 613, 1555, 581, -1, 612, 1555, 613, -1, 580, 1555, 612, -1, 582, 1556, 581, -1, 614, 1556, 582, -1, 613, 1556, 614, -1, 581, 1556, 613, -1, 583, 1557, 582, -1, 615, 1557, 583, -1, 614, 1557, 615, -1, 582, 1557, 614, -1, 584, 1558, 583, -1, 616, 1558, 584, -1, 615, 1558, 616, -1, 583, 1558, 615, -1, 585, 1559, 584, -1, 617, 1559, 585, -1, 616, 1559, 617, -1, 584, 1559, 616, -1, 586, 1560, 585, -1, 618, 1560, 586, -1, 617, 1560, 618, -1, 585, 1560, 617, -1, 587, 1561, 586, -1, 619, 1561, 587, -1, 618, 1561, 619, -1, 586, 1561, 618, -1, 588, 1562, 587, -1, 620, 1562, 588, -1, 619, 1562, 620, -1, 587, 1562, 619, -1, 589, 1563, 588, -1, 621, 1563, 589, -1, 620, 1563, 621, -1, 588, 1563, 620, -1, 590, 1564, 589, -1, 622, 1564, 590, -1, 621, 1564, 622, -1, 589, 1564, 621, -1, 591, 1565, 590, -1, 623, 1565, 591, -1, 622, 1565, 623, -1, 590, 1565, 622, -1, 592, 1566, 591, -1, 624, 1566, 592, -1, 623, 1566, 624, -1, 591, 1566, 623, -1, 593, 1567, 592, -1, 625, 1567, 593, -1, 624, 1567, 625, -1, 592, 1567, 624, -1, 594, 1568, 593, -1, 626, 1568, 594, -1, 625, 1568, 626, -1, 593, 1568, 625, -1, 595, 1569, 594, -1, 627, 1569, 595, -1, 626, 1569, 627, -1, 594, 1569, 626, -1, 596, 1570, 595, -1, 628, 1570, 596, -1, 627, 1570, 628, -1, 595, 1570, 627, -1, 597, 1571, 596, -1, 629, 1571, 597, -1, 628, 1571, 629, -1, 596, 1571, 628, -1, 598, 1572, 597, -1, 630, 1572, 598, -1, 629, 1572, 630, -1, 597, 1572, 629, -1, 599, 1573, 598, -1, 631, 1573, 599, -1, 630, 1573, 631, -1, 598, 1573, 630, -1, 600, 1574, 599, -1, 632, 1574, 600, -1, 631, 1574, 632, -1, 599, 1574, 631, -1, 601, 1575, 600, -1, 633, 1575, 601, -1, 632, 1575, 633, -1, 600, 1575, 632, -1, 602, 1576, 601, -1, 634, 1576, 602, -1, 633, 1576, 634, -1, 601, 1576, 633, -1, 603, 1577, 602, -1, 635, 1577, 603, -1, 634, 1577, 635, -1, 602, 1577, 634, -1, 604, 1578, 603, -1, 636, 1578, 604, -1, 635, 1578, 636, -1, 603, 1578, 635, -1, 605, 1579, 604, -1, 637, 1579, 605, -1, 636, 1579, 637, -1, 604, 1579, 636, -1, 606, 1580, 605, -1, 638, 1580, 606, -1, 637, 1580, 638, -1, 605, 1580, 637, -1, 607, 1581, 606, -1, 639, 1581, 607, -1, 638, 1581, 639, -1, 606, 1581, 638, -1, 609, 1582, 608, -1, 641, 1582, 609, -1, 640, 1582, 641, -1, 608, 1582, 640, -1, 610, 1583, 609, -1, 642, 1583, 610, -1, 641, 1583, 642, -1, 609, 1583, 641, -1, 611, 1584, 610, -1, 643, 1584, 611, -1, 642, 1584, 643, -1, 610, 1584, 642, -1, 612, 1585, 611, -1, 644, 1585, 612, -1, 643, 1585, 644, -1, 611, 1585, 643, -1, 613, 1586, 612, -1, 645, 1586, 613, -1, 644, 1586, 645, -1, 612, 1586, 644, -1, 614, 1587, 613, -1, 646, 1587, 614, -1, 645, 1587, 646, -1, 613, 1587, 645, -1, 615, 1588, 614, -1, 647, 1588, 615, -1, 646, 1588, 647, -1, 614, 1588, 646, -1, 616, 1589, 615, -1, 648, 1589, 616, -1, 647, 1589, 648, -1, 615, 1589, 647, -1, 617, 1590, 616, -1, 649, 1590, 617, -1, 648, 1590, 649, -1, 616, 1590, 648, -1, 618, 1591, 617, -1, 650, 1591, 618, -1, 649, 1591, 650, -1, 617, 1591, 649, -1, 619, 1592, 618, -1, 651, 1592, 619, -1, 650, 1592, 651, -1, 618, 1592, 650, -1, 620, 1593, 619, -1, 652, 1593, 620, -1, 651, 1593, 652, -1, 619, 1593, 651, -1, 621, 1594, 620, -1, 653, 1594, 621, -1, 652, 1594, 653, -1, 620, 1594, 652, -1, 622, 1595, 621, -1, 654, 1595, 622, -1, 653, 1595, 654, -1, 621, 1595, 653, -1, 623, 1596, 622, -1, 655, 1596, 623, -1, 654, 1596, 655, -1, 622, 1596, 654, -1, 624, 1597, 623, -1, 656, 1597, 624, -1, 655, 1597, 656, -1, 623, 1597, 655, -1, 625, 1598, 624, -1, 657, 1598, 625, -1, 656, 1598, 657, -1, 624, 1598, 656, -1, 626, 1599, 625, -1, 658, 1599, 626, -1, 657, 1599, 658, -1, 625, 1599, 657, -1, 627, 1600, 626, -1, 659, 1600, 627, -1, 658, 1600, 659, -1, 626, 1600, 658, -1, 628, 1601, 627, -1, 660, 1601, 628, -1, 659, 1601, 660, -1, 627, 1601, 659, -1, 629, 1602, 628, -1, 661, 1602, 629, -1, 660, 1602, 661, -1, 628, 1602, 660, -1, 630, 1603, 629, -1, 662, 1603, 630, -1, 661, 1603, 662, -1, 629, 1603, 661, -1, 631, 1604, 630, -1, 663, 1604, 631, -1, 662, 1604, 663, -1, 630, 1604, 662, -1, 632, 1605, 631, -1, 664, 1605, 632, -1, 663, 1605, 664, -1, 631, 1605, 663, -1, 633, 1606, 632, -1, 665, 1606, 633, -1, 664, 1606, 665, -1, 632, 1606, 664, -1, 634, 1607, 633, -1, 666, 1607, 634, -1, 665, 1607, 666, -1, 633, 1607, 665, -1, 635, 1608, 634, -1, 667, 1608, 635, -1, 666, 1608, 667, -1, 634, 1608, 666, -1, 636, 1609, 635, -1, 668, 1609, 636, -1, 667, 1609, 668, -1, 635, 1609, 667, -1, 637, 1610, 636, -1, 669, 1610, 637, -1, 668, 1610, 669, -1, 636, 1610, 668, -1, 638, 1611, 637, -1, 670, 1611, 638, -1, 669, 1611, 670, -1, 637, 1611, 669, -1, 639, 1612, 638, -1, 671, 1612, 639, -1, 670, 1612, 671, -1, 638, 1612, 670, -1, 641, 1613, 640, -1, 673, 1613, 641, -1, 672, 1613, 673, -1, 640, 1613, 672, -1, 642, 1614, 641, -1, 674, 1614, 642, -1, 673, 1614, 674, -1, 641, 1614, 673, -1, 643, 1615, 642, -1, 675, 1615, 643, -1, 674, 1615, 675, -1, 642, 1615, 674, -1, 644, 1616, 643, -1, 676, 1616, 644, -1, 675, 1616, 676, -1, 643, 1616, 675, -1, 645, 1617, 644, -1, 677, 1617, 645, -1, 676, 1617, 677, -1, 644, 1617, 676, -1, 646, 1618, 645, -1, 678, 1618, 646, -1, 677, 1618, 678, -1, 645, 1618, 677, -1, 647, 1619, 646, -1, 679, 1619, 647, -1, 678, 1619, 679, -1, 646, 1619, 678, -1, 648, 1620, 647, -1, 680, 1620, 648, -1, 679, 1620, 680, -1, 647, 1620, 679, -1, 649, 1621, 648, -1, 681, 1621, 649, -1, 680, 1621, 681, -1, 648, 1621, 680, -1, 650, 1622, 649, -1, 682, 1622, 650, -1, 681, 1622, 682, -1, 649, 1622, 681, -1, 651, 1623, 650, -1, 683, 1623, 651, -1, 682, 1623, 683, -1, 650, 1623, 682, -1, 652, 1624, 651, -1, 684, 1624, 652, -1, 683, 1624, 684, -1, 651, 1624, 683, -1, 653, 1625, 652, -1, 685, 1625, 653, -1, 684, 1625, 685, -1, 652, 1625, 684, -1, 654, 1626, 653, -1, 686, 1626, 654, -1, 685, 1626, 686, -1, 653, 1626, 685, -1, 655, 1627, 654, -1, 687, 1627, 655, -1, 686, 1627, 687, -1, 654, 1627, 686, -1, 656, 1628, 655, -1, 688, 1628, 656, -1, 687, 1628, 688, -1, 655, 1628, 687, -1, 657, 1629, 656, -1, 689, 1629, 657, -1, 688, 1629, 689, -1, 656, 1629, 688, -1, 658, 1630, 657, -1, 690, 1630, 658, -1, 689, 1630, 690, -1, 657, 1630, 689, -1, 659, 1631, 658, -1, 691, 1631, 659, -1, 690, 1631, 691, -1, 658, 1631, 690, -1, 660, 1632, 659, -1, 692, 1632, 660, -1, 691, 1632, 692, -1, 659, 1632, 691, -1, 661, 1633, 660, -1, 693, 1633, 661, -1, 692, 1633, 693, -1, 660, 1633, 692, -1, 662, 1634, 661, -1, 694, 1634, 662, -1, 693, 1634, 694, -1, 661, 1634, 693, -1, 663, 1635, 662, -1, 695, 1635, 663, -1, 694, 1635, 695, -1, 662, 1635, 694, -1, 664, 1636, 663, -1, 696, 1636, 664, -1, 695, 1636, 696, -1, 663, 1636, 695, -1, 665, 1637, 664, -1, 697, 1637, 665, -1, 696, 1637, 697, -1, 664, 1637, 696, -1, 666, 1638, 665, -1, 698, 1638, 666, -1, 697, 1638, 698, -1, 665, 1638, 697, -1, 667, 1639, 666, -1, 699, 1639, 667, -1, 698, 1639, 699, -1, 666, 1639, 698, -1, 668, 1640, 667, -1, 700, 1640, 668, -1, 699, 1640, 700, -1, 667, 1640, 699, -1, 669, 1641, 668, -1, 701, 1641, 669, -1, 700, 1641, 701, -1, 668, 1641, 700, -1, 670, 1642, 669, -1, 702, 1642, 670, -1, 701, 1642, 702, -1, 669, 1642, 701, -1, 671, 1643, 670, -1, 703, 1643, 671, -1, 702, 1643, 703, -1, 670, 1643, 702, -1, 673, 1644, 672, -1, 705, 1644, 673, -1, 704, 1644, 705, -1, 672, 1644, 704, -1, 674, 1645, 673, -1, 706, 1645, 674, -1, 705, 1645, 706, -1, 673, 1645, 705, -1, 675, 1646, 674, -1, 707, 1646, 675, -1, 706, 1646, 707, -1, 674, 1646, 706, -1, 676, 1647, 675, -1, 708, 1647, 676, -1, 707, 1647, 708, -1, 675, 1647, 707, -1, 677, 1648, 676, -1, 709, 1648, 677, -1, 708, 1648, 709, -1, 676, 1648, 708, -1, 678, 1649, 677, -1, 710, 1649, 678, -1, 709, 1649, 710, -1, 677, 1649, 709, -1, 679, 1650, 678, -1, 711, 1650, 679, -1, 710, 1650, 711, -1, 678, 1650, 710, -1, 680, 1651, 679, -1, 712, 1651, 680, -1, 711, 1651, 712, -1, 679, 1651, 711, -1, 681, 1652, 680, -1, 713, 1652, 681, -1, 712, 1652, 713, -1, 680, 1652, 712, -1, 682, 1653, 681, -1, 714, 1653, 682, -1, 713, 1653, 714, -1, 681, 1653, 713, -1, 683, 1654, 682, -1, 715, 1654, 683, -1, 714, 1654, 715, -1, 682, 1654, 714, -1, 684, 1655, 683, -1, 716, 1655, 684, -1, 715, 1655, 716, -1, 683, 1655, 715, -1, 685, 1656, 684, -1, 717, 1656, 685, -1, 716, 1656, 717, -1, 684, 1656, 716, -1, 686, 1657, 685, -1, 718, 1657, 686, -1, 717, 1657, 718, -1, 685, 1657, 717, -1, 687, 1658, 686, -1, 719, 1658, 687, -1, 718, 1658, 719, -1, 686, 1658, 718, -1, 688, 1659, 687, -1, 720, 1659, 688, -1, 719, 1659, 720, -1, 687, 1659, 719, -1, 689, 1660, 688, -1, 721, 1660, 689, -1, 720, 1660, 721, -1, 688, 1660, 720, -1, 690, 1661, 689, -1, 722, 1661, 690, -1, 721, 1661, 722, -1, 689, 1661, 721, -1, 691, 1662, 690, -1, 723, 1662, 691, -1, 722, 1662, 723, -1, 690, 1662, 722, -1, 692, 1663, 691, -1, 724, 1663, 692, -1, 723, 1663, 724, -1, 691, 1663, 723, -1, 693, 1664, 692, -1, 725, 1664, 693, -1, 724, 1664, 725, -1, 692, 1664, 724, -1, 694, 1665, 693, -1, 726, 1665, 694, -1, 725, 1665, 726, -1, 693, 1665, 725, -1, 695, 1666, 694, -1, 727, 1666, 695, -1, 726, 1666, 727, -1, 694, 1666, 726, -1, 696, 1667, 695, -1, 728, 1667, 696, -1, 727, 1667, 728, -1, 695, 1667, 727, -1, 697, 1668, 696, -1, 729, 1668, 697, -1, 728, 1668, 729, -1, 696, 1668, 728, -1, 698, 1669, 697, -1, 730, 1669, 698, -1, 729, 1669, 730, -1, 697, 1669, 729, -1, 699, 1670, 698, -1, 731, 1670, 699, -1, 730, 1670, 731, -1, 698, 1670, 730, -1, 700, 1671, 699, -1, 732, 1671, 700, -1, 731, 1671, 732, -1, 699, 1671, 731, -1, 701, 1672, 700, -1, 733, 1672, 701, -1, 732, 1672, 733, -1, 700, 1672, 732, -1, 702, 1673, 701, -1, 734, 1673, 702, -1, 733, 1673, 734, -1, 701, 1673, 733, -1, 703, 1674, 702, -1, 735, 1674, 703, -1, 734, 1674, 735, -1, 702, 1674, 734, -1, 705, 1675, 704, -1, 737, 1675, 705, -1, 736, 1675, 737, -1, 704, 1675, 736, -1, 706, 1676, 705, -1, 738, 1676, 706, -1, 737, 1676, 738, -1, 705, 1676, 737, -1, 707, 1677, 706, -1, 739, 1677, 707, -1, 738, 1677, 739, -1, 706, 1677, 738, -1, 708, 1678, 707, -1, 740, 1678, 708, -1, 739, 1678, 740, -1, 707, 1678, 739, -1, 709, 1679, 708, -1, 741, 1679, 709, -1, 740, 1679, 741, -1, 708, 1679, 740, -1, 710, 1680, 709, -1, 742, 1680, 710, -1, 741, 1680, 742, -1, 709, 1680, 741, -1, 711, 1681, 710, -1, 743, 1681, 711, -1, 742, 1681, 743, -1, 710, 1681, 742, -1, 712, 1682, 711, -1, 744, 1682, 712, -1, 743, 1682, 744, -1, 711, 1682, 743, -1, 713, 1683, 712, -1, 745, 1683, 713, -1, 744, 1683, 745, -1, 712, 1683, 744, -1, 714, 1684, 713, -1, 746, 1684, 714, -1, 745, 1684, 746, -1, 713, 1684, 745, -1, 715, 1685, 714, -1, 747, 1685, 715, -1, 746, 1685, 747, -1, 714, 1685, 746, -1, 716, 1686, 715, -1, 748, 1686, 716, -1, 747, 1686, 748, -1, 715, 1686, 747, -1, 717, 1687, 716, -1, 749, 1687, 717, -1, 748, 1687, 749, -1, 716, 1687, 748, -1, 718, 1688, 717, -1, 750, 1688, 718, -1, 749, 1688, 750, -1, 717, 1688, 749, -1, 719, 1689, 718, -1, 751, 1689, 719, -1, 750, 1689, 751, -1, 718, 1689, 750, -1, 720, 1690, 719, -1, 752, 1690, 720, -1, 751, 1690, 752, -1, 719, 1690, 751, -1, 721, 1691, 720, -1, 753, 1691, 721, -1, 752, 1691, 753, -1, 720, 1691, 752, -1, 722, 1692, 721, -1, 754, 1692, 722, -1, 753, 1692, 754, -1, 721, 1692, 753, -1, 723, 1693, 722, -1, 755, 1693, 723, -1, 754, 1693, 755, -1, 722, 1693, 754, -1, 724, 1694, 723, -1, 756, 1694, 724, -1, 755, 1694, 756, -1, 723, 1694, 755, -1, 725, 1695, 724, -1, 757, 1695, 725, -1, 756, 1695, 757, -1, 724, 1695, 756, -1, 726, 1696, 725, -1, 758, 1696, 726, -1, 757, 1696, 758, -1, 725, 1696, 757, -1, 727, 1697, 726, -1, 759, 1697, 727, -1, 758, 1697, 759, -1, 726, 1697, 758, -1, 728, 1698, 727, -1, 760, 1698, 728, -1, 759, 1698, 760, -1, 727, 1698, 759, -1, 729, 1699, 728, -1, 761, 1699, 729, -1, 760, 1699, 761, -1, 728, 1699, 760, -1, 730, 1700, 729, -1, 762, 1700, 730, -1, 761, 1700, 762, -1, 729, 1700, 761, -1, 731, 1701, 730, -1, 763, 1701, 731, -1, 762, 1701, 763, -1, 730, 1701, 762, -1, 732, 1702, 731, -1, 764, 1702, 732, -1, 763, 1702, 764, -1, 731, 1702, 763, -1, 733, 1703, 732, -1, 765, 1703, 733, -1, 764, 1703, 765, -1, 732, 1703, 764, -1, 734, 1704, 733, -1, 766, 1704, 734, -1, 765, 1704, 766, -1, 733, 1704, 765, -1, 735, 1705, 734, -1, 767, 1705, 735, -1, 766, 1705, 767, -1, 734, 1705, 766, -1, 737, 1706, 736, -1, 769, 1706, 737, -1, 768, 1706, 769, -1, 736, 1706, 768, -1, 738, 1707, 737, -1, 770, 1707, 738, -1, 769, 1707, 770, -1, 737, 1707, 769, -1, 739, 1708, 738, -1, 771, 1708, 739, -1, 770, 1708, 771, -1, 738, 1708, 770, -1, 740, 1709, 739, -1, 772, 1709, 740, -1, 771, 1709, 772, -1, 739, 1709, 771, -1, 741, 1710, 740, -1, 773, 1710, 741, -1, 772, 1710, 773, -1, 740, 1710, 772, -1, 742, 1711, 741, -1, 774, 1711, 742, -1, 773, 1711, 774, -1, 741, 1711, 773, -1, 743, 1712, 742, -1, 775, 1712, 743, -1, 774, 1712, 775, -1, 742, 1712, 774, -1, 744, 1713, 743, -1, 776, 1713, 744, -1, 775, 1713, 776, -1, 743, 1713, 775, -1, 745, 1714, 744, -1, 777, 1714, 745, -1, 776, 1714, 777, -1, 744, 1714, 776, -1, 746, 1715, 745, -1, 778, 1715, 746, -1, 777, 1715, 778, -1, 745, 1715, 777, -1, 747, 1716, 746, -1, 779, 1716, 747, -1, 778, 1716, 779, -1, 746, 1716, 778, -1, 748, 1717, 747, -1, 780, 1717, 748, -1, 779, 1717, 780, -1, 747, 1717, 779, -1, 749, 1718, 748, -1, 781, 1718, 749, -1, 780, 1718, 781, -1, 748, 1718, 780, -1, 750, 1719, 749, -1, 782, 1719, 750, -1, 781, 1719, 782, -1, 749, 1719, 781, -1, 751, 1720, 750, -1, 783, 1720, 751, -1, 782, 1720, 783, -1, 750, 1720, 782, -1, 752, 1721, 751, -1, 784, 1721, 752, -1, 783, 1721, 784, -1, 751, 1721, 783, -1, 753, 1722, 752, -1, 785, 1722, 753, -1, 784, 1722, 785, -1, 752, 1722, 784, -1, 754, 1723, 753, -1, 786, 1723, 754, -1, 785, 1723, 786, -1, 753, 1723, 785, -1, 755, 1724, 754, -1, 787, 1724, 755, -1, 786, 1724, 787, -1, 754, 1724, 786, -1, 756, 1725, 755, -1, 788, 1725, 756, -1, 787, 1725, 788, -1, 755, 1725, 787, -1, 757, 1726, 756, -1, 789, 1726, 757, -1, 788, 1726, 789, -1, 756, 1726, 788, -1, 758, 1727, 757, -1, 790, 1727, 758, -1, 789, 1727, 790, -1, 757, 1727, 789, -1, 759, 1728, 758, -1, 791, 1728, 759, -1, 790, 1728, 791, -1, 758, 1728, 790, -1, 760, 1729, 759, -1, 792, 1729, 760, -1, 791, 1729, 792, -1, 759, 1729, 791, -1, 761, 1730, 760, -1, 793, 1730, 761, -1, 792, 1730, 793, -1, 760, 1730, 792, -1, 762, 1731, 761, -1, 794, 1731, 762, -1, 793, 1731, 794, -1, 761, 1731, 793, -1, 763, 1732, 762, -1, 795, 1732, 763, -1, 794, 1732, 795, -1, 762, 1732, 794, -1, 764, 1733, 763, -1, 796, 1733, 764, -1, 795, 1733, 796, -1, 763, 1733, 795, -1, 765, 1734, 764, -1, 797, 1734, 765, -1, 796, 1734, 797, -1, 764, 1734, 796, -1, 766, 1735, 765, -1, 798, 1735, 766, -1, 797, 1735, 798, -1, 765, 1735, 797, -1, 767, 1736, 766, -1, 799, 1736, 767, -1, 798, 1736, 799, -1, 766, 1736, 798, -1, 769, 1737, 768, -1, 801, 1737, 769, -1, 800, 1737, 801, -1, 768, 1737, 800, -1, 770, 1738, 769, -1, 802, 1738, 770, -1, 801, 1738, 802, -1, 769, 1738, 801, -1, 771, 1739, 770, -1, 803, 1739, 771, -1, 802, 1739, 803, -1, 770, 1739, 802, -1, 772, 1740, 771, -1, 804, 1740, 772, -1, 803, 1740, 804, -1, 771, 1740, 803, -1, 773, 1741, 772, -1, 805, 1741, 773, -1, 804, 1741, 805, -1, 772, 1741, 804, -1, 774, 1742, 773, -1, 806, 1742, 774, -1, 805, 1742, 806, -1, 773, 1742, 805, -1, 775, 1743, 774, -1, 807, 1743, 775, -1, 806, 1743, 807, -1, 774, 1743, 806, -1, 776, 1744, 775, -1, 808, 1744, 776, -1, 807, 1744, 808, -1, 775, 1744, 807, -1, 777, 1745, 776, -1, 809, 1745, 777, -1, 808, 1745, 809, -1, 776, 1745, 808, -1, 778, 1746, 777, -1, 810, 1746, 778, -1, 809, 1746, 810, -1, 777, 1746, 809, -1, 779, 1747, 778, -1, 811, 1747, 779, -1, 810, 1747, 811, -1, 778, 1747, 810, -1, 780, 1748, 779, -1, 812, 1748, 780, -1, 811, 1748, 812, -1, 779, 1748, 811, -1, 781, 1749, 780, -1, 813, 1749, 781, -1, 812, 1749, 813, -1, 780, 1749, 812, -1, 782, 1750, 781, -1, 814, 1750, 782, -1, 813, 1750, 814, -1, 781, 1750, 813, -1, 783, 1751, 782, -1, 815, 1751, 783, -1, 814, 1751, 815, -1, 782, 1751, 814, -1, 784, 1752, 783, -1, 816, 1752, 784, -1, 815, 1752, 816, -1, 783, 1752, 815, -1, 785, 1753, 784, -1, 817, 1753, 785, -1, 816, 1753, 817, -1, 784, 1753, 816, -1, 786, 1754, 785, -1, 818, 1754, 786, -1, 817, 1754, 818, -1, 785, 1754, 817, -1, 787, 1755, 786, -1, 819, 1755, 787, -1, 818, 1755, 819, -1, 786, 1755, 818, -1, 788, 1756, 787, -1, 820, 1756, 788, -1, 819, 1756, 820, -1, 787, 1756, 819, -1, 789, 1757, 788, -1, 821, 1757, 789, -1, 820, 1757, 821, -1, 788, 1757, 820, -1, 790, 1758, 789, -1, 822, 1758, 790, -1, 821, 1758, 822, -1, 789, 1758, 821, -1, 791, 1759, 790, -1, 823, 1759, 791, -1, 822, 1759, 823, -1, 790, 1759, 822, -1, 792, 1760, 791, -1, 824, 1760, 792, -1, 823, 1760, 824, -1, 791, 1760, 823, -1, 793, 1761, 792, -1, 825, 1761, 793, -1, 824, 1761, 825, -1, 792, 1761, 824, -1, 794, 1762, 793, -1, 826, 1762, 794, -1, 825, 1762, 826, -1, 793, 1762, 825, -1, 795, 1763, 794, -1, 827, 1763, 795, -1, 826, 1763, 827, -1, 794, 1763, 826, -1, 796, 1764, 795, -1, 828, 1764, 796, -1, 827, 1764, 828, -1, 795, 1764, 827, -1, 797, 1765, 796, -1, 829, 1765, 797, -1, 828, 1765, 829, -1, 796, 1765, 828, -1, 798, 1766, 797, -1, 830, 1766, 798, -1, 829, 1766, 830, -1, 797, 1766, 829, -1, 799, 1767, 798, -1, 831, 1767, 799, -1, 830, 1767, 831, -1, 798, 1767, 830, -1, 801, 1768, 800, -1, 833, 1768, 801, -1, 832, 1768, 833, -1, 800, 1768, 832, -1, 802, 1769, 801, -1, 834, 1769, 802, -1, 833, 1769, 834, -1, 801, 1769, 833, -1, 803, 1770, 802, -1, 835, 1770, 803, -1, 834, 1770, 835, -1, 802, 1770, 834, -1, 804, 1771, 803, -1, 836, 1771, 804, -1, 835, 1771, 836, -1, 803, 1771, 835, -1, 805, 1772, 804, -1, 837, 1772, 805, -1, 836, 1772, 837, -1, 804, 1772, 836, -1, 806, 1773, 805, -1, 838, 1773, 806, -1, 837, 1773, 838, -1, 805, 1773, 837, -1, 807, 1774, 806, -1, 839, 1774, 807, -1, 838, 1774, 839, -1, 806, 1774, 838, -1, 808, 1775, 807, -1, 840, 1775, 808, -1, 839, 1775, 840, -1, 807, 1775, 839, -1, 809, 1776, 808, -1, 841, 1776, 809, -1, 840, 1776, 841, -1, 808, 1776, 840, -1, 810, 1777, 809, -1, 842, 1777, 810, -1, 841, 1777, 842, -1, 809, 1777, 841, -1, 811, 1778, 810, -1, 843, 1778, 811, -1, 842, 1778, 843, -1, 810, 1778, 842, -1, 812, 1779, 811, -1, 844, 1779, 812, -1, 843, 1779, 844, -1, 811, 1779, 843, -1, 813, 1780, 812, -1, 845, 1780, 813, -1, 844, 1780, 845, -1, 812, 1780, 844, -1, 814, 1781, 813, -1, 846, 1781, 814, -1, 845, 1781, 846, -1, 813, 1781, 845, -1, 815, 1782, 814, -1, 847, 1782, 815, -1, 846, 1782, 847, -1, 814, 1782, 846, -1, 816, 1783, 815, -1, 848, 1783, 816, -1, 847, 1783, 848, -1, 815, 1783, 847, -1, 817, 1784, 816, -1, 849, 1784, 817, -1, 848, 1784, 849, -1, 816, 1784, 848, -1, 818, 1785, 817, -1, 850, 1785, 818, -1, 849, 1785, 850, -1, 817, 1785, 849, -1, 819, 1786, 818, -1, 851, 1786, 819, -1, 850, 1786, 851, -1, 818, 1786, 850, -1, 820, 1787, 819, -1, 852, 1787, 820, -1, 851, 1787, 852, -1, 819, 1787, 851, -1, 821, 1788, 820, -1, 853, 1788, 821, -1, 852, 1788, 853, -1, 820, 1788, 852, -1, 822, 1789, 821, -1, 854, 1789, 822, -1, 853, 1789, 854, -1, 821, 1789, 853, -1, 823, 1790, 822, -1, 855, 1790, 823, -1, 854, 1790, 855, -1, 822, 1790, 854, -1, 824, 1791, 823, -1, 856, 1791, 824, -1, 855, 1791, 856, -1, 823, 1791, 855, -1, 825, 1792, 824, -1, 857, 1792, 825, -1, 856, 1792, 857, -1, 824, 1792, 856, -1, 826, 1793, 825, -1, 858, 1793, 826, -1, 857, 1793, 858, -1, 825, 1793, 857, -1, 827, 1794, 826, -1, 859, 1794, 827, -1, 858, 1794, 859, -1, 826, 1794, 858, -1, 828, 1795, 827, -1, 860, 1795, 828, -1, 859, 1795, 860, -1, 827, 1795, 859, -1, 829, 1796, 828, -1, 861, 1796, 829, -1, 860, 1796, 861, -1, 828, 1796, 860, -1, 830, 1797, 829, -1, 862, 1797, 830, -1, 861, 1797, 862, -1, 829, 1797, 861, -1, 831, 1798, 830, -1, 863, 1798, 831, -1, 862, 1798, 863, -1, 830, 1798, 862, -1, 833, 1799, 832, -1, 865, 1799, 833, -1, 864, 1799, 865, -1, 832, 1799, 864, -1, 834, 1800, 833, -1, 866, 1800, 834, -1, 865, 1800, 866, -1, 833, 1800, 865, -1, 835, 1801, 834, -1, 867, 1801, 835, -1, 866, 1801, 867, -1, 834, 1801, 866, -1, 836, 1802, 835, -1, 868, 1802, 836, -1, 867, 1802, 868, -1, 835, 1802, 867, -1, 837, 1803, 836, -1, 869, 1803, 837, -1, 868, 1803, 869, -1, 836, 1803, 868, -1, 838, 1804, 837, -1, 870, 1804, 838, -1, 869, 1804, 870, -1, 837, 1804, 869, -1, 839, 1805, 838, -1, 871, 1805, 839, -1, 870, 1805, 871, -1, 838, 1805, 870, -1, 840, 1806, 839, -1, 872, 1806, 840, -1, 871, 1806, 872, -1, 839, 1806, 871, -1, 841, 1807, 840, -1, 873, 1807, 841, -1, 872, 1807, 873, -1, 840, 1807, 872, -1, 842, 1808, 841, -1, 874, 1808, 842, -1, 873, 1808, 874, -1, 841, 1808, 873, -1, 843, 1809, 842, -1, 875, 1809, 843, -1, 874, 1809, 875, -1, 842, 1809, 874, -1, 844, 1810, 843, -1, 876, 1810, 844, -1, 875, 1810, 876, -1, 843, 1810, 875, -1, 845, 1811, 844, -1, 877, 1811, 845, -1, 876, 1811, 877, -1, 844, 1811, 876, -1, 846, 1812, 845, -1, 878, 1812, 846, -1, 877, 1812, 878, -1, 845, 1812, 877, -1, 847, 1813, 846, -1, 879, 1813, 847, -1, 878, 1813, 879, -1, 846, 1813, 878, -1, 848, 1814, 847, -1, 880, 1814, 848, -1, 879, 1814, 880, -1, 847, 1814, 879, -1, 849, 1815, 848, -1, 881, 1815, 849, -1, 880, 1815, 881, -1, 848, 1815, 880, -1, 850, 1816, 849, -1, 882, 1816, 850, -1, 881, 1816, 882, -1, 849, 1816, 881, -1, 851, 1817, 850, -1, 883, 1817, 851, -1, 882, 1817, 883, -1, 850, 1817, 882, -1, 852, 1818, 851, -1, 884, 1818, 852, -1, 883, 1818, 884, -1, 851, 1818, 883, -1, 853, 1819, 852, -1, 885, 1819, 853, -1, 884, 1819, 885, -1, 852, 1819, 884, -1, 854, 1820, 853, -1, 886, 1820, 854, -1, 885, 1820, 886, -1, 853, 1820, 885, -1, 855, 1821, 854, -1, 887, 1821, 855, -1, 886, 1821, 887, -1, 854, 1821, 886, -1, 856, 1822, 855, -1, 888, 1822, 856, -1, 887, 1822, 888, -1, 855, 1822, 887, -1, 857, 1823, 856, -1, 889, 1823, 857, -1, 888, 1823, 889, -1, 856, 1823, 888, -1, 858, 1824, 857, -1, 890, 1824, 858, -1, 889, 1824, 890, -1, 857, 1824, 889, -1, 859, 1825, 858, -1, 891, 1825, 859, -1, 890, 1825, 891, -1, 858, 1825, 890, -1, 860, 1826, 859, -1, 892, 1826, 860, -1, 891, 1826, 892, -1, 859, 1826, 891, -1, 861, 1827, 860, -1, 893, 1827, 861, -1, 892, 1827, 893, -1, 860, 1827, 892, -1, 862, 1828, 861, -1, 894, 1828, 862, -1, 893, 1828, 894, -1, 861, 1828, 893, -1, 863, 1829, 862, -1, 895, 1829, 863, -1, 894, 1829, 895, -1, 862, 1829, 894, -1, 865, 1830, 864, -1, 897, 1830, 865, -1, 896, 1830, 897, -1, 864, 1830, 896, -1, 866, 1831, 865, -1, 898, 1831, 866, -1, 897, 1831, 898, -1, 865, 1831, 897, -1, 867, 1832, 866, -1, 899, 1832, 867, -1, 898, 1832, 899, -1, 866, 1832, 898, -1, 868, 1833, 867, -1, 900, 1833, 868, -1, 899, 1833, 900, -1, 867, 1833, 899, -1, 869, 1834, 868, -1, 901, 1834, 869, -1, 900, 1834, 901, -1, 868, 1834, 900, -1, 870, 1835, 869, -1, 902, 1835, 870, -1, 901, 1835, 902, -1, 869, 1835, 901, -1, 871, 1836, 870, -1, 903, 1836, 871, -1, 902, 1836, 903, -1, 870, 1836, 902, -1, 872, 1837, 871, -1, 904, 1837, 872, -1, 903, 1837, 904, -1, 871, 1837, 903, -1, 873, 1838, 872, -1, 905, 1838, 873, -1, 904, 1838, 905, -1, 872, 1838, 904, -1, 874, 1839, 873, -1, 906, 1839, 874, -1, 905, 1839, 906, -1, 873, 1839, 905, -1, 875, 1840, 874, -1, 907, 1840, 875, -1, 906, 1840, 907, -1, 874, 1840, 906, -1, 876, 1841, 875, -1, 908, 1841, 876, -1, 907, 1841, 908, -1, 875, 1841, 907, -1, 877, 1842, 876, -1, 909, 1842, 877, -1, 908, 1842, 909, -1, 876, 1842, 908, -1, 878, 1843, 877, -1, 910, 1843, 878, -1, 909, 1843, 910, -1, 877, 1843, 909, -1, 879, 1844, 878, -1, 911, 1844, 879, -1, 910, 1844, 911, -1, 878, 1844, 910, -1, 880, 1845, 879, -1, 912, 1845, 880, -1, 911, 1845, 912, -1, 879, 1845, 911, -1, 881, 1846, 880, -1, 913, 1846, 881, -1, 912, 1846, 913, -1, 880, 1846, 912, -1, 882, 1847, 881, -1, 914, 1847, 882, -1, 913, 1847, 914, -1, 881, 1847, 913, -1, 883, 1848, 882, -1, 915, 1848, 883, -1, 914, 1848, 915, -1, 882, 1848, 914, -1, 884, 1849, 883, -1, 916, 1849, 884, -1, 915, 1849, 916, -1, 883, 1849, 915, -1, 885, 1850, 884, -1, 917, 1850, 885, -1, 916, 1850, 917, -1, 884, 1850, 916, -1, 886, 1851, 885, -1, 918, 1851, 886, -1, 917, 1851, 918, -1, 885, 1851, 917, -1, 887, 1852, 886, -1, 919, 1852, 887, -1, 918, 1852, 919, -1, 886, 1852, 918, -1, 888, 1853, 887, -1, 920, 1853, 888, -1, 919, 1853, 920, -1, 887, 1853, 919, -1, 889, 1854, 888, -1, 921, 1854, 889, -1, 920, 1854, 921, -1, 888, 1854, 920, -1, 890, 1855, 889, -1, 922, 1855, 890, -1, 921, 1855, 922, -1, 889, 1855, 921, -1, 891, 1856, 890, -1, 923, 1856, 891, -1, 922, 1856, 923, -1, 890, 1856, 922, -1, 892, 1857, 891, -1, 924, 1857, 892, -1, 923, 1857, 924, -1, 891, 1857, 923, -1, 893, 1858, 892, -1, 925, 1858, 893, -1, 924, 1858, 925, -1, 892, 1858, 924, -1, 894, 1859, 893, -1, 926, 1859, 894, -1, 925, 1859, 926, -1, 893, 1859, 925, -1, 895, 1860, 894, -1, 927, 1860, 895, -1, 926, 1860, 927, -1, 894, 1860, 926, -1, 897, 1861, 896, -1, 929, 1861, 897, -1, 928, 1861, 929, -1, 896, 1861, 928, -1, 898, 1862, 897, -1, 930, 1862, 898, -1, 929, 1862, 930, -1, 897, 1862, 929, -1, 899, 1863, 898, -1, 931, 1863, 899, -1, 930, 1863, 931, -1, 898, 1863, 930, -1, 900, 1864, 899, -1, 932, 1864, 900, -1, 931, 1864, 932, -1, 899, 1864, 931, -1, 901, 1865, 900, -1, 933, 1865, 901, -1, 932, 1865, 933, -1, 900, 1865, 932, -1, 902, 1866, 901, -1, 934, 1866, 902, -1, 933, 1866, 934, -1, 901, 1866, 933, -1, 903, 1867, 902, -1, 935, 1867, 903, -1, 934, 1867, 935, -1, 902, 1867, 934, -1, 904, 1868, 903, -1, 936, 1868, 904, -1, 935, 1868, 936, -1, 903, 1868, 935, -1, 905, 1869, 904, -1, 937, 1869, 905, -1, 936, 1869, 937, -1, 904, 1869, 936, -1, 906, 1870, 905, -1, 938, 1870, 906, -1, 937, 1870, 938, -1, 905, 1870, 937, -1, 907, 1871, 906, -1, 939, 1871, 907, -1, 938, 1871, 939, -1, 906, 1871, 938, -1, 908, 1872, 907, -1, 940, 1872, 908, -1, 939, 1872, 940, -1, 907, 1872, 939, -1, 909, 1873, 908, -1, 941, 1873, 909, -1, 940, 1873, 941, -1, 908, 1873, 940, -1, 910, 1874, 909, -1, 942, 1874, 910, -1, 941, 1874, 942, -1, 909, 1874, 941, -1, 911, 1875, 910, -1, 943, 1875, 911, -1, 942, 1875, 943, -1, 910, 1875, 942, -1, 912, 1876, 911, -1, 944, 1876, 912, -1, 943, 1876, 944, -1, 911, 1876, 943, -1, 913, 1877, 912, -1, 945, 1877, 913, -1, 944, 1877, 945, -1, 912, 1877, 944, -1, 914, 1878, 913, -1, 946, 1878, 914, -1, 945, 1878, 946, -1, 913, 1878, 945, -1, 915, 1879, 914, -1, 947, 1879, 915, -1, 946, 1879, 947, -1, 914, 1879, 946, -1, 916, 1880, 915, -1, 948, 1880, 916, -1, 947, 1880, 948, -1, 915, 1880, 947, -1, 917, 1881, 916, -1, 949, 1881, 917, -1, 948, 1881, 949, -1, 916, 1881, 948, -1, 918, 1882, 917, -1, 950, 1882, 918, -1, 949, 1882, 950, -1, 917, 1882, 949, -1, 919, 1883, 918, -1, 951, 1883, 919, -1, 950, 1883, 951, -1, 918, 1883, 950, -1, 920, 1884, 919, -1, 952, 1884, 920, -1, 951, 1884, 952, -1, 919, 1884, 951, -1, 921, 1885, 920, -1, 953, 1885, 921, -1, 952, 1885, 953, -1, 920, 1885, 952, -1, 922, 1886, 921, -1, 954, 1886, 922, -1, 953, 1886, 954, -1, 921, 1886, 953, -1, 923, 1887, 922, -1, 955, 1887, 923, -1, 954, 1887, 955, -1, 922, 1887, 954, -1, 924, 1888, 923, -1, 956, 1888, 924, -1, 955, 1888, 956, -1, 923, 1888, 955, -1, 925, 1889, 924, -1, 957, 1889, 925, -1, 956, 1889, 957, -1, 924, 1889, 956, -1, 926, 1890, 925, -1, 958, 1890, 926, -1, 957, 1890, 958, -1, 925, 1890, 957, -1, 927, 1891, 926, -1, 959, 1891, 927, -1, 958, 1891, 959, -1, 926, 1891, 958, -1, 929, 1892, 928, -1, 961, 1892, 929, -1, 960, 1892, 961, -1, 928, 1892, 960, -1, 930, 1893, 929, -1, 962, 1893, 930, -1, 961, 1893, 962, -1, 929, 1893, 961, -1, 931, 1894, 930, -1, 963, 1894, 931, -1, 962, 1894, 963, -1, 930, 1894, 962, -1, 932, 1895, 931, -1, 964, 1895, 932, -1, 963, 1895, 964, -1, 931, 1895, 963, -1, 933, 1896, 932, -1, 965, 1896, 933, -1, 964, 1896, 965, -1, 932, 1896, 964, -1, 934, 1897, 933, -1, 966, 1897, 934, -1, 965, 1897, 966, -1, 933, 1897, 965, -1, 935, 1898, 934, -1, 967, 1898, 935, -1, 966, 1898, 967, -1, 934, 1898, 966, -1, 936, 1899, 935, -1, 968, 1899, 936, -1, 967, 1899, 968, -1, 935, 1899, 967, -1, 937, 1900, 936, -1, 969, 1900, 937, -1, 968, 1900, 969, -1, 936, 1900, 968, -1, 938, 1901, 937, -1, 970, 1901, 938, -1, 969, 1901, 970, -1, 937, 1901, 969, -1, 939, 1902, 938, -1, 971, 1902, 939, -1, 970, 1902, 971, -1, 938, 1902, 970, -1, 940, 1903, 939, -1, 972, 1903, 940, -1, 971, 1903, 972, -1, 939, 1903, 971, -1, 941, 1904, 940, -1, 973, 1904, 941, -1, 972, 1904, 973, -1, 940, 1904, 972, -1, 942, 1905, 941, -1, 974, 1905, 942, -1, 973, 1905, 974, -1, 941, 1905, 973, -1, 943, 1906, 942, -1, 975, 1906, 943, -1, 974, 1906, 975, -1, 942, 1906, 974, -1, 944, 1907, 943, -1, 976, 1907, 944, -1, 975, 1907, 976, -1, 943, 1907, 975, -1, 945, 1908, 944, -1, 977, 1908, 945, -1, 976, 1908, 977, -1, 944, 1908, 976, -1, 946, 1909, 945, -1, 978, 1909, 946, -1, 977, 1909, 978, -1, 945, 1909, 977, -1, 947, 1910, 946, -1, 979, 1910, 947, -1, 978, 1910, 979, -1, 946, 1910, 978, -1, 948, 1911, 947, -1, 980, 1911, 948, -1, 979, 1911, 980, -1, 947, 1911, 979, -1, 949, 1912, 948, -1, 981, 1912, 949, -1, 980, 1912, 981, -1, 948, 1912, 980, -1, 950, 1913, 949, -1, 982, 1913, 950, -1, 981, 1913, 982, -1, 949, 1913, 981, -1, 951, 1914, 950, -1, 983, 1914, 951, -1, 982, 1914, 983, -1, 950, 1914, 982, -1, 952, 1915, 951, -1, 984, 1915, 952, -1, 983, 1915, 984, -1, 951, 1915, 983, -1, 953, 1916, 952, -1, 985, 1916, 953, -1, 984, 1916, 985, -1, 952, 1916, 984, -1, 954, 1917, 953, -1, 986, 1917, 954, -1, 985, 1917, 986, -1, 953, 1917, 985, -1, 955, 1918, 954, -1, 987, 1918, 955, -1, 986, 1918, 987, -1, 954, 1918, 986, -1, 956, 1919, 955, -1, 988, 1919, 956, -1, 987, 1919, 988, -1, 955, 1919, 987, -1, 957, 1920, 956, -1, 989, 1920, 957, -1, 988, 1920, 989, -1, 956, 1920, 988, -1, 958, 1921, 957, -1, 990, 1921, 958, -1, 989, 1921, 990, -1, 957, 1921, 989, -1, 959, 1922, 958, -1, 991, 1922, 959, -1, 990, 1922, 991, -1, 958, 1922, 990, -1, 960, 961, 992, -1, 961, 962, 993, -1, 962, 963, 994, -1, 963, 964, 995, -1, 964, 965, 996, -1, 965, 966, 997, -1, 966, 967, 998, -1, 967, 968, 999, -1, 968, 969, 1000, -1, 969, 970, 1001, -1, 970, 971, 1002, -1, 971, 972, 1003, -1, 972, 973, 1004, -1, 973, 974, 1005, -1, 974, 975, 1006, -1, 975, 976, 1007, -1, 976, 977, 1008, -1, 977, 978, 1009, -1, 978, 979, 1010, -1, 979, 980, 1011, -1, 980, 981, 1012, -1, 981, 982, 1013, -1, 982, 983, 1014, -1, 983, 984, 1015, -1, 984, 985, 1016, -1, 985, 986, 1017, -1, 986, 987, 1018, -1, 987, 988, 1019, -1, 988, 989, 1020, -1, 989, 990, 1021, -1, 990, 991, 1022, -1 };
    NurbsSurface1.colorIndex = m_colorIndex;
    NurbsSurface1.colorIndex_length = sizeof(m_colorIndex) / sizeof(int);
    }
    NurbsSurface1.colorPerVertex = true;
    NurbsSurface1.convex = true;
    {
    static int m_coordIndex[] = { 1, 33, 32, -1, 2, 34, 33, -1, 3, 35, 34, -1, 4, 36, 35, -1, 5, 37, 36, -1, 6, 38, 37, -1, 7, 39, 38, -1, 8, 40, 39, -1, 9, 41, 40, -1, 10, 42, 41, -1, 11, 43, 42, -1, 12, 44, 43, -1, 13, 45, 44, -1, 14, 46, 45, -1, 15, 47, 46, -1, 16, 48, 47, -1, 17, 49, 48, -1, 18, 50, 49, -1, 19, 51, 50, -1, 20, 52, 51, -1, 21, 53, 52, -1, 22, 54, 53, -1, 23, 55, 54, -1, 24, 56, 55, -1, 25, 57, 56, -1, 26, 58, 57, -1, 27, 59, 58, -1, 28, 60, 59, -1, 29, 61, 60, -1, 30, 62, 61, -1, 31, 63, 62, -1, 33, 1024, 32, -1, 65, 1024, 33, -1, 64, 1024, 65, -1, 32, 1024, 64, -1, 34, 1025, 33, -1, 66, 1025, 34, -1, 65, 1025, 66, -1, 33, 1025, 65, -1, 35, 1026, 34, -1, 67, 1026, 35, -1, 66, 1026, 67, -1, 34, 1026, 66, -1, 36, 1027, 35, -1, 68, 1027, 36, -1, 67, 1027, 68, -1, 35, 1027, 67, -1, 37, 1028, 36, -1, 69, 1028, 37, -1, 68, 1028, 69, -1, 36, 1028, 68, -1, 38, 1029, 37, -1, 70, 1029, 38, -1, 69, 1029, 70, -1, 37, 1029, 69, -1, 39, 1030, 38, -1, 71, 1030, 39, -1, 70, 1030, 71, -1, 38, 1030, 70, -1, 40, 1031, 39, -1, 72, 1031, 40, -1, 71, 1031, 72, -1, 39, 1031, 71, -1, 41, 1032, 40, -1, 73, 1032, 41, -1, 72, 1032, 73, -1, 40, 1032, 72, -1, 42, 1033, 41, -1, 74, 1033, 42, -1, 73, 1033, 74, -1, 41, 1033, 73, -1, 43, 1034, 42, -1, 75, 1034, 43, -1, 74, 1034, 75, -1, 42, 1034, 74, -1, 44, 1035, 43, -1, 76, 1035, 44, -1, 75, 1035, 76, -1, 43, 1035, 75, -1, 45, 1036, 44, -1, 77, 1036, 45, -1, 76, 1036, 77, -1, 44, 1036, 76, -1, 46, 1037, 45, -1, 78, 1037, 46, -1, 77, 1037, 78, -1, 45, 1037, 77, -1, 47, 1038, 46, -1, 79, 1038, 47, -1, 78, 1038, 79, -1, 46, 1038, 78, -1, 48, 1039, 47, -1, 80, 1039, 48, -1, 79, 1039, 80, -1, 47, 1039, 79, -1, 49, 1040, 48, -1, 81, 1040, 49, -1, 80, 1040, 81, -1, 48, 1040, 80, -1, 50, 1041, 49, -1, 82, 1041, 50, -1, 81, 1041, 82, -1, 49, 1041, 81, -1, 51, 1042, 50, -1, 83, 1042, 51, -1, 82, 1042, 83, -1, 50, 1042, 82, -1, 52, 1043, 51, -1, 84, 1043, 52, -1, 83, 1043, 84, -1, 51, 1043, 83, -1, 53, 1044, 52, -1, 85, 1044, 53, -1, 84, 1044, 85, -1, 52, 1044, 84, -1, 54, 1045, 53, -1, 86, 1045, 54, -1, 85, 1045, 86, -1, 53, 1045, 85, -1, 55, 1046, 54, -1, 87, 1046, 55, -1, 86, 1046, 87, -1, 54, 1046, 86, -1, 56, 1047, 55, -1, 88, 1047, 56, -1, 87, 1047, 88, -1, 55, 1047, 87, -1, 57, 1048, 56, -1, 89, 1048, 57, -1, 88, 1048, 89, -1, 56, 1048, 88, -1, 58, 1049, 57, -1, 90, 1049, 58, -1, 89, 1049, 90, -1, 57, 1049, 89, -1, 59, 1050, 58, -1, 91, 1050, 59, -1, 90, 1050, 91, -1, 58, 1050, 90, -1, 60, 1051, 59, -1, 92, 1051, 60, -1, 91, 1051, 92, -1, 59, 1051, 91, -1, 61, 1052, 60, -1, 93, 1052, 61, -1, 92, 1052, 93, -1, 60, 1052, 92, -1, 62, 1053, 61, -1, 94, 1053, 62, -1, 93, 1053, 94, -1, 61, 1053, 93, -1, 63, 1054, 62, -1, 95, 1054, 63, -1, 94, 1054, 95, -1, 62, 1054, 94, -1, 65, 1055, 64, -1, 97, 1055, 65, -1, 96, 1055, 97, -1, 64, 1055, 96, -1, 66, 1056, 65, -1, 98, 1056, 66, -1, 97, 1056, 98, -1, 65, 1056, 97, -1, 67, 1057, 66, -1, 99, 1057, 67, -1, 98, 1057, 99, -1, 66, 1057, 98, -1, 68, 1058, 67, -1, 100, 1058, 68, -1, 99, 1058, 100, -1, 67, 1058, 99, -1, 69, 1059, 68, -1, 101, 1059, 69, -1, 100, 1059, 101, -1, 68, 1059, 100, -1, 70, 1060, 69, -1, 102, 1060, 70, -1, 101, 1060, 102, -1, 69, 1060, 101, -1, 71, 1061, 70, -1, 103, 1061, 71, -1, 102, 1061, 103, -1, 70, 1061, 102, -1, 72, 1062, 71, -1, 104, 1062, 72, -1, 103, 1062, 104, -1, 71, 1062, 103, -1, 73, 1063, 72, -1, 105, 1063, 73, -1, 104, 1063, 105, -1, 72, 1063, 104, -1, 74, 1064, 73, -1, 106, 1064, 74, -1, 105, 1064, 106, -1, 73, 1064, 105, -1, 75, 1065, 74, -1, 107, 1065, 75, -1, 106, 1065, 107, -1, 74, 1065, 106, -1, 76, 1066, 75, -1, 108, 1066, 76, -1, 107, 1066, 108, -1, 75, 1066, 107, -1, 77, 1067, 76, -1, 109, 1067, 77, -1, 108, 1067, 109, -1, 76, 1067, 108, -1, 78, 1068, 77, -1, 110, 1068, 78, -1, 109, 1068, 110, -1, 77, 1068, 109, -1, 79, 1069, 78, -1, 111, 1069, 79, -1, 110, 1069, 111, -1, 78, 1069, 110, -1, 80, 1070, 79, -1, 112, 1070, 80, -1, 111, 1070, 112, -1, 79, 1070, 111, -1, 81, 1071, 80, -1, 113, 1071, 81, -1, 112, 1071, 113, -1, 80, 1071, 112, -1, 82, 1072, 81, -1, 114, 1072, 82, -1, 113, 1072, 114, -1, 81, 1072, 113, -1, 83, 1073, 82, -1, 115, 1073, 83, -1, 114, 1073, 115, -1, 82, 1073, 114, -1, 84, 1074, 83, -1, 116, 1074, 84, -1, 115, 1074, 116, -1, 83, 1074, 115, -1, 85, 1075, 84, -1, 117, 1075, 85, -1, 116, 1075, 117, -1, 84, 1075, 116, -1, 86, 1076, 85, -1, 118, 1076, 86, -1, 117, 1076, 118, -1, 85, 1076, 117, -1, 87, 1077, 86, -1, 119, 1077, 87, -1, 118, 1077, 119, -1, 86, 1077, 118, -1, 88, 1078, 87, -1, 120, 1078, 88, -1, 119, 1078, 120, -1, 87, 1078, 119, -1, 89, 1079, 88, -1, 121, 1079, 89, -1, 120, 1079, 121, -1, 88, 1079, 120, -1, 90, 1080, 89, -1, 122, 1080, 90, -1, 121, 1080, 122, -1, 89, 1080, 121, -1, 91, 1081, 90, -1, 123, 1081, 91, -1, 122, 1081, 123, -1, 90, 1081, 122, -1, 92, 1082, 91, -1, 124, 1082, 92, -1, 123, 1082, 124, -1, 91, 1082, 123, -1, 93, 1083, 92, -1, 125, 1083, 93, -1, 124, 1083, 125, -1, 92, 1083, 124, -1, 94, 1084, 93, -1, 126, 1084, 94, -1, 125, 1084, 126, -1, 93, 1084, 125, -1, 95, 1085, 94, -1, 127, 1085, 95, -1, 126, 1085, 127, -1, 94, 1085, 126, -1, 97, 1086, 96, -1, 129, 1086, 97, -1, 128, 1086, 129, -1, 96, 1086, 128, -1, 98, 1087, 97, -1, 130, 1087, 98, -1, 129, 1087, 130, -1, 97, 1087, 129, -1, 99, 1088, 98, -1, 131, 1088, 99, -1, 130, 1088, 131, -1, 98, 1088, 130, -1, 100, 1089, 99, -1, 132, 1089, 100, -1, 131, 1089, 132, -1, 99, 1089, 131, -1, 101, 1090, 100, -1, 133, 1090, 101, -1, 132, 1090, 133, -1, 100, 1090, 132, -1, 102, 1091, 101, -1, 134, 1091, 102, -1, 133, 1091, 134, -1, 101, 1091, 133, -1, 103, 1092, 102, -1, 135, 1092, 103, -1, 134, 1092, 135, -1, 102, 1092, 134, -1, 104, 1093, 103, -1, 136, 1093, 104, -1, 135, 1093, 136, -1, 103, 1093, 135, -1, 105, 1094, 104, -1, 137, 1094, 105, -1, 136, 1094, 137, -1, 104, 1094, 136, -1, 106, 1095, 105, -1, 138, 1095, 106, -1, 137, 1095, 138, -1, 105, 1095, 137, -1, 107, 1096, 106, -1, 139, 1096, 107, -1, 138, 1096, 139, -1, 106, 1096, 138, -1, 108, 1097, 107, -1, 140, 1097, 108, -1, 139, 1097, 140, -1, 107, 1097, 139, -1, 109, 1098, 108, -1, 141, 1098, 109, -1, 140, 1098, 141, -1, 108, 1098, 140, -1, 110, 1099, 109, -1, 142, 1099, 110, -1, 141, 1099, 142, -1, 109, 1099, 141, -1, 111, 1100, 110, -1, 143, 1100, 111, -1, 142, 1100, 143, -1, 110, 1100, 142, -1, 112, 1101, 111, -1, 144, 1101, 112, -1, 143, 1101, 144, -1, 111, 1101, 143, -1, 113, 1102, 112, -1, 145, 1102, 113, -1, 144, 1102, 145, -1, 112, 1102, 144, -1, 114, 1103, 113, -1, 146, 1103, 114, -1, 145, 1103, 146, -1, 113, 1103, 145, -1, 115, 1104, 114, -1, 147, 1104, 115, -1, 146, 1104, 147, -1, 114, 1104, 146, -1, 116, 1105, 115, -1, 148, 1105, 116, -1, 147, 1105, 148, -1, 115, 1105, 147, -1, 117, 1106, 116, -1, 149, 1106, 117, -1, 148, 1106, 149, -1, 116, 1106, 148, -1, 118, 1107, 117, -1, 150, 1107, 118, -1, 149, 1107, 150, -1, 117, 1107, 149, -1, 119, 1108, 118, -1, 151, 1108, 119, -1, 150, 1108, 151, -1, 118, 1108, 150, -1, 120, 1109, 119, -1, 152, 1109, 120, -1, 151, 1109, 152, -1, 119, 1109, 151, -1, 121, 1110, 120, -1, 153, 1110, 121, -1, 152, 1110, 153, -1, 120, 1110, 152, -1, 122, 1111, 121, -1, 154, 1111, 122, -1, 153, 1111, 154, -1, 121, 1111, 153, -1, 123, 1112, 122, -1, 155, 1112, 123, -1, 154, 1112, 155, -1, 122, 1112, 154, -1, 124, 1113, 123, -1, 156, 1113, 124, -1, 155, 1113, 156, -1, 123, 1113, 155, -1, 125, 1114, 124, -1, 157, 1114, 125, -1, 156, 1114, 157, -1, 124, 1114, 156, -1, 126, 1115, 125, -1, 158, 1115, 126, -1, 157, 1115, 158, -1, 125, 1115, 157, -1, 127, 1116, 126, -1, 159, 1116, 127, -1, 158, 1116, 159, -1, 126, 1116, 158, -1, 129, 1117, 128, -1, 161, 1117, 129, -1, 160, 1117, 161, -1, 128, 1117, 160, -1, 130, 1118, 129, -1, 162, 1118, 130, -1, 161, 1118, 162, -1, 129, 1118, 161, -1, 131, 1119, 130, -1, 163, 1119, 131, -1, 162, 1119, 163, -1, 130, 1119, 162, -1, 132, 1120, 131, -1, 164, 1120, 132, -1, 163, 1120, 164, -1, 131, 1120, 163, -1, 133, 1121, 132, -1, 165, 1121, 133, -1, 164, 1121, 165, -1, 132, 1121, 164, -1, 134, 1122, 133, -1, 166, 1122, 134, -1, 165, 1122, 166, -1, 133, 1122, 165, -1, 135, 1123, 134, -1, 167, 1123, 135, -1, 166, 1123, 167, -1, 134, 1123, 166, -1, 136, 1124, 135, -1, 168, 1124, 136, -1, 167, 1124, 168, -1, 135, 1124, 167, -1, 137, 1125, 136, -1, 169, 1125, 137, -1, 168, 1125, 169, -1, 136, 1125, 168, -1, 138, 1126, 137, -1, 170, 1126, 138, -1, 169, 1126, 170, -1, 137, 1126, 169, -1, 139, 1127, 138, -1, 171, 1127, 139, -1, 170, 1127, 171, -1, 138, 1127, 170, -1, 140, 1128, 139, -1, 172, 1128, 140, -1, 171, 1128, 172, -1, 139, 1128, 171, -1, 141, 1129, 140, -1, 173, 1129, 141, -1, 172, 1129, 173, -1, 140, 1129, 172, -1, 142, 1130, 141, -1, 174, 1130, 142, -1, 173, 1130, 174, -1, 141, 1130, 173, -1, 143, 1131, 142, -1, 175, 1131, 143, -1, 174, 1131, 175, -1, 142, 1131, 174, -1, 144, 1132, 143, -1, 176, 1132, 144, -1, 175, 1132, 176, -1, 143, 1132, 175, -1, 145, 1133, 144, -1, 177, 1133, 145, -1, 176, 1133, 177, -1, 144, 1133, 176, -1, 146, 1134, 145, -1, 178, 1134, 146, -1, 177, 1134, 178, -1, 145, 1134, 177, -1, 147, 1135, 146, -1, 179, 1135, 147, -1, 178, 1135, 179, -1, 146, 1135, 178, -1, 148, 1136, 147, -1, 180, 1136, 148, -1, 179, 1136, 180, -1, 147, 1136, 179, -1, 149, 1137, 148, -1, 181, 1137, 149, -1, 180, 1137, 181, -1, 148, 1137, 180, -1, 150, 1138, 149, -1, 182, 1138, 150, -1, 181, 1138, 182, -1, 149, 1138, 181, -1, 151, 1139, 150, -1, 183, 1139, 151, -1, 182, 1139, 183, -1, 150, 1139, 182, -1, 152, 1140, 151, -1, 184, 1140, 152, -1, 183, 1140, 184, -1, 151, 1140, 183, -1, 153, 1141, 152, -1, 185, 1141, 153, -1, 184, 1141, 185, -1, 152, 1141, 184, -1, 154, 1142, 153, -1, 186, 1142, 154, -1, 185, 1142, 186, -1, 153, 1142, 185, -1, 155, 1143, 154, -1, 187, 1143, 155, -1, 186, 1143, 187, -1, 154, 1143, 186, -1, 156, 1144, 155, -1, 188, 1144, 156, -1, 187, 1144, 188, -1, 155, 1144, 187, -1, 157, 1145, 156, -1, 189, 1145, 157, -1, 188, 1145, 189, -1, 156, 1145, 188, -1, 158, 1146, 157, -1, 190, 1146, 158, -1, 189, 1146, 190, -1, 157, 1146, 189, -1, 159, 1147, 158, -1, 191, 1147, 159, -1, 190, 1147, 191, -1, 158, 1147, 190, -1, 161, 1148, 160, -1, 193, 1148, 161, -1, 192, 1148, 193, -1, 160, 1148, 192, -1, 162, 1149, 161, -1, 194, 1149, 162, -1, 193, 1149, 194, -1, 161, 1149, 193, -1, 163, 1150, 162, -1, 195, 1150, 163, -1, 194, 1150, 195, -1, 162, 1150, 194, -1, 164, 1151, 163, -1, 196, 1151, 164, -1, 195, 1151, 196, -1, 163, 1151, 195, -1, 165, 1152, 164, -1, 197, 1152, 165, -1, 196, 1152, 197, -1, 164, 1152, 196, -1, 166, 1153, 165, -1, 198, 1153, 166, -1, 197, 1153, 198, -1, 165, 1153, 197, -1, 167, 1154, 166, -1, 199, 1154, 167, -1, 198, 1154, 199, -1, 166, 1154, 198, -1, 168, 1155, 167, -1, 200, 1155, 168, -1, 199, 1155, 200, -1, 167, 1155, 199, -1, 169, 1156, 168, -1, 201, 1156, 169, -1, 200, 1156, 201, -1, 168, 1156, 200, -1, 170, 1157, 169, -1, 202, 1157, 170, -1, 201, 1157, 202, -1, 169, 1157, 201, -1, 171, 1158, 170, -1, 203, 1158, 171, -1, 202, 1158, 203, -1, 170, 1158, 202, -1, 172, 1159, 171, -1, 204, 1159, 172, -1, 203, 1159, 204, -1, 171, 1159, 203, -1, 173, 1160, 172, -1, 205, 1160, 173, -1, 204, 1160, 205, -1, 172, 1160, 204, -1, 174, 1161, 173, -1, 206, 1161, 174, -1, 205, 1161, 206, -1, 173, 1161, 205, -1, 175, 1162, 174, -1, 207, 1162, 175, -1, 206, 1162, 207, -1, 174, 1162, 206, -1, 176, 1163, 175, -1, 208, 1163, 176, -1, 207, 1163, 208, -1, 175, 1163, 207, -1, 177, 1164, 176, -1, 209, 1164, 177, -1, 208, 1164, 209, -1, 176, 1164, 208, -1, 178, 1165, 177, -1, 210, 1165, 178, -1, 209, 1165, 210, -1, 177, 1165, 209, -1, 179, 1166, 178, -1, 211, 1166, 179, -1, 210, 1166, 211, -1, 178, 1166, 210, -1, 180, 1167, 179, -1, 212, 1167, 180, -1, 211, 1167, 212, -1, 179, 1167, 211, -1, 181, 1168, 180, -1, 213, 1168, 181, -1, 212, 1168, 213, -1, 180, 1168, 212, -1, 182, 1169, 181, -1, 214, 1169, 182, -1, 213, 1169, 214, -1, 181, 1169, 213, -1, 183, 1170, 182, -1, 215, 1170, 183, -1, 214, 1170, 215, -1, 182, 1170, 214, -1, 184, 1171, 183, -1, 216, 1171, 184, -1, 215, 1171, 216, -1, 183, 1171, 215, -1, 185, 1172, 184, -1, 217, 1172, 185, -1, 216, 1172, 217, -1, 184, 1172, 216, -1, 186, 1173, 185, -1, 218, 1173, 186, -1, 217, 1173, 218, -1, 185, 1173, 217, -1, 187, 1174, 186, -1, 219, 1174, 187, -1, 218, 1174, 219, -1, 186, 1174, 218, -1, 188, 1175, 187, -1, 220, 1175, 188, -1, 219, 1175, 220, -1, 187, 1175, 219, -1, 189, 1176, 188, -1, 221, 1176, 189, -1, 220, 1176, 221, -1, 188, 1176, 220, -1, 190, 1177, 189, -1, 222, 1177, 190, -1, 221, 1177, 222, -1, 189, 1177, 221, -1, 191, 1178, 190, -1, 223, 1178, 191, -1, 222, 1178, 223, -1, 190, 1178, 222, -1, 193, 1179, 192, -1, 225, 1179, 193, -1, 224, 1179, 225, -1, 192, 1179, 224, -1, 194, 1180, 193, -1, 226, 1180, 194, -1, 225, 1180, 226, -1, 193, 1180, 225, -1, 195, 1181, 194, -1, 227, 1181, 195, -1, 226, 1181, 227, -1, 194, 1181, 226, -1, 196, 1182, 195, -1, 228, 1182, 196, -1, 227, 1182, 228, -1, 195, 1182, 227, -1, 197, 1183, 196, -1, 229, 1183, 197, -1, 228, 1183, 229, -1, 196, 1183, 228, -1, 198, 1184, 197, -1, 230, 1184, 198, -1, 229, 1184, 230, -1, 197, 1184, 229, -1, 199, 1185, 198, -1, 231, 1185, 199, -1, 230, 1185, 231, -1, 198, 1185, 230, -1, 200, 1186, 199, -1, 232, 1186, 200, -1, 231, 1186, 232, -1, 199, 1186, 231, -1, 201, 1187, 200, -1, 233, 1187, 201, -1, 232, 1187, 233, -1, 200, 1187, 232, -1, 202, 1188, 201, -1, 234, 1188, 202, -1, 233, 1188, 234, -1, 201, 1188, 233, -1, 203, 1189, 202, -1, 235, 1189, 203, -1, 234, 1189, 235, -1, 202, 1189, 234, -1, 204, 1190, 203, -1, 236, 1190, 204, -1, 235, 1190, 236, -1, 203, 1190, 235, -1, 205, 1191, 204, -1, 237, 1191, 205, -1, 236, 1191, 237, -1, 204, 1191, 236, -1, 206, 1192, 205, -1, 238, 1192, 206, -1, 237, 1192, 238, -1, 205, 1192, 237, -1, 207, 1193, 206, -1, 239, 1193, 207, -1, 238, 1193, 239, -1, 206, 1193, 238, -1, 208, 1194, 207, -1, 240, 1194, 208, -1, 239, 1194, 240, -1, 207, 1194, 239, -1, 209, 1195, 208, -1, 241, 1195, 209, -1, 240, 1195, 241, -1, 208, 1195, 240, -1, 210, 1196, 209, -1, 242, 1196, 210, -1, 241, 1196, 242, -1, 209, 1196, 241, -1, 211, 1197, 210, -1, 243, 1197, 211, -1, 242, 1197, 243, -1, 210, 1197, 242, -1, 212, 1198, 211, -1, 244, 1198, 212, -1, 243, 1198, 244, -1, 211, 1198, 243, -1, 213, 1199, 212, -1, 245, 1199, 213, -1, 244, 1199, 245, -1, 212, 1199, 244, -1, 214, 1200, 213, -1, 246, 1200, 214, -1, 245, 1200, 246, -1, 213, 1200, 245, -1, 215, 1201, 214, -1, 247, 1201, 215, -1, 246, 1201, 247, -1, 214, 1201, 246, -1, 216, 1202, 215, -1, 248, 1202, 216, -1, 247, 1202, 248, -1, 215, 1202, 247, -1, 217, 1203, 216, -1, 249, 1203, 217, -1, 248, 1203, 249, -1, 216, 1203, 248, -1, 218, 1204, 217, -1, 250, 1204, 218, -1, 249, 1204, 250, -1, 217, 1204, 249, -1, 219, 1205, 218, -1, 251, 1205, 219, -1, 250, 1205, 251, -1, 218, 1205, 250, -1, 220, 1206, 219, -1, 252, 1206, 220, -1, 251, 1206, 252, -1, 219, 1206, 251, -1, 221, 1207, 220, -1, 253, 1207, 221, -1, 252, 1207, 253, -1, 220, 1207, 252, -1, 222, 1208, 221, -1, 254, 1208, 222, -1, 253, 1208, 254, -1, 221, 1208, 253, -1, 223, 1209, 222, -1, 255, 1209, 223, -1, 254, 1209, 255, -1, 222, 1209, 254, -1, 225, 1210, 224, -1, 257, 1210, 225, -1, 256, 1210, 257, -1, 224, 1210, 256, -1, 226, 1211, 225, -1, 258, 1211, 226, -1, 257, 1211, 258, -1, 225, 1211, 257, -1, 227, 1212, 226, -1, 259, 1212, 227, -1, 258, 1212, 259, -1, 226, 1212, 258, -1, 228, 1213, 227, -1, 260, 1213, 228, -1, 259, 1213, 260, -1, 227, 1213, 259, -1, 229, 1214, 228, -1, 261, 1214, 229, -1, 260, 1214, 261, -1, 228, 1214, 260, -1, 230, 1215, 229, -1, 262, 1215, 230, -1, 261, 1215, 262, -1, 229, 1215, 261, -1, 231, 1216, 230, -1, 263, 1216, 231, -1, 262, 1216, 263, -1, 230, 1216, 262, -1, 232, 1217, 231, -1, 264, 1217, 232, -1, 263, 1217, 264, -1, 231, 1217, 263, -1, 233, 1218, 232, -1, 265, 1218, 233, -1, 264, 1218, 265, -1, 232, 1218, 264, -1, 234, 1219, 233, -1, 266, 1219, 234, -1, 265, 1219, 266, -1, 233, 1219, 265, -1, 235, 1220, 234, -1, 267, 1220, 235, -1, 266, 1220, 267, -1, 234, 1220, 266, -1, 236, 1221, 235, -1, 268, 1221, 236, -1, 267, 1221, 268, -1, 235, 1221, 267, -1, 237, 1222, 236, -1, 269, 1222, 237, -1, 268, 1222, 269, -1, 236, 1222, 268, -1, 238, 1223, 237, -1, 270, 1223, 238, -1, 269, 1223, 270, -1, 237, 1223, 269, -1, 239, 1224, 238, -1, 271, 1224, 239, -1, 270, 1224, 271, -1, 238, 1224, 270, -1, 240, 1225, 239, -1, 272, 1225, 240, -1, 271, 1225, 272, -1, 239, 1225, 271, -1, 241, 1226, 240, -1, 273, 1226, 241, -1, 272, 1226, 273, -1, 240, 1226, 272, -1, 242, 1227, 241, -1, 274, 1227, 242, -1, 273, 1227, 274, -1, 241, 1227, 273, -1, 243, 1228, 242, -1, 275, 1228, 243, -1, 274, 1228, 275, -1, 242, 1228, 274, -1, 244, 1229, 243, -1, 276, 1229, 244, -1, 275, 1229, 276, -1, 243, 1229, 275, -1, 245, 1230, 244, -1, 277, 1230, 245, -1, 276, 1230, 277, -1, 244, 1230, 276, -1, 246, 1231, 245, -1, 278, 1231, 246, -1, 277, 1231, 278, -1, 245, 1231, 277, -1, 247, 1232, 246, -1, 279, 1232, 247, -1, 278, 1232, 279, -1, 246, 1232, 278, -1, 248, 1233, 247, -1, 280, 1233, 248, -1, 279, 1233, 280, -1, 247, 1233, 279, -1, 249, 1234, 248, -1, 281, 1234, 249, -1, 280, 1234, 281, -1, 248, 1234, 280, -1, 250, 1235, 249, -1, 282, 1235, 250, -1, 281, 1235, 282, -1, 249, 1235, 281, -1, 251, 1236, 250, -1, 283, 1236, 251, -1, 282, 1236, 283, -1, 250, 1236, 282, -1, 252, 1237, 251, -1, 284, 1237, 252, -1, 283, 1237, 284, -1, 251, 1237, 283, -1, 253, 1238, 252, -1, 285, 1238, 253, -1, 284, 1238, 285, -1, 252, 1238, 284, -1, 254, 1239, 253, -1, 286, 1239, 254, -1, 285, 1239, 286, -1, 253, 1239, 285, -1, 255, 1240, 254, -1, 287, 1240, 255, -1, 286, 1240, 287, -1, 254, 1240, 286, -1, 257, 1241, 256, -1, 289, 1241, 257, -1, 288, 1241, 289, -1, 256, 1241, 288, -1, 258, 1242, 257, -1, 290, 1242, 258, -1, 289, 1242, 290, -1, 257, 1242, 289, -1, 259, 1243, 258, -1, 291, 1243, 259, -1, 290, 1243, 291, -1, 258, 1243, 290, -1, 260, 1244, 259, -1, 292, 1244, 260, -1, 291, 1244, 292, -1, 259, 1244, 291, -1, 261, 1245, 260, -1, 293, 1245, 261, -1, 292, 1245, 293, -1, 260, 1245, 292, -1, 262, 1246, 261, -1, 294, 1246, 262, -1, 293, 1246, 294, -1, 261, 1246, 293, -1, 263, 1247, 262, -1, 295, 1247, 263, -1, 294, 1247, 295, -1, 262, 1247, 294, -1, 264, 1248, 263, -1, 296, 1248, 264, -1, 295, 1248, 296, -1, 263, 1248, 295, -1, 265, 1249, 264, -1, 297, 1249, 265, -1, 296, 1249, 297, -1, 264, 1249, 296, -1, 266, 1250, 265, -1, 298, 1250, 266, -1, 297, 1250, 298, -1, 265, 1250, 297, -1, 267, 1251, 266, -1, 299, 1251, 267, -1, 298, 1251, 299, -1, 266, 1251, 298, -1, 268, 1252, 267, -1, 300, 1252, 268, -1, 299, 1252, 300, -1, 267, 1252, 299, -1, 269, 1253, 268, -1, 301, 1253, 269, -1, 300, 1253, 301, -1, 268, 1253, 300, -1, 270, 1254, 269, -1, 302, 1254, 270, -1, 301, 1254, 302, -1, 269, 1254, 301, -1, 271, 1255, 270, -1, 303, 1255, 271, -1, 302, 1255, 303, -1, 270, 1255, 302, -1, 272, 1256, 271, -1, 304, 1256, 272, -1, 303, 1256, 304, -1, 271, 1256, 303, -1, 273, 1257, 272, -1, 305, 1257, 273, -1, 304, 1257, 305, -1, 272, 1257, 304, -1, 274, 1258, 273, -1, 306, 1258, 274, -1, 305, 1258, 306, -1, 273, 1258, 305, -1, 275, 1259, 274, -1, 307, 1259, 275, -1, 306, 1259, 307, -1, 274, 1259, 306, -1, 276, 1260, 275, -1, 308, 1260, 276, -1, 307, 1260, 308, -1, 275, 1260, 307, -1, 277, 1261, 276, -1, 309, 1261, 277, -1, 308, 1261, 309, -1, 276, 1261, 308, -1, 278, 1262, 277, -1, 310, 1262, 278, -1, 309, 1262, 310, -1, 277, 1262, 309, -1, 279, 1263, 278, -1, 311, 1263, 279, -1, 310, 1263, 311, -1, 278, 1263, 310, -1, 280, 1264, 279, -1, 312, 1264, 280, -1, 311, 1264, 312, -1, 279, 1264, 311, -1, 281, 1265, 280, -1, 313, 1265, 281, -1, 312, 1265, 313, -1, 280, 1265, 312, -1, 282, 1266, 281, -1, 314, 1266, 282, -1, 313, 1266, 314, -1, 281, 1266, 313, -1, 283, 1267, 282, -1, 315, 1267, 283, -1, 314, 1267, 315, -1, 282, 1267, 314, -1, 284, 1268, 283, -1, 316, 1268, 284, -1, 315, 1268, 316, -1, 283, 1268, 315, -1, 285, 1269, 284, -1, 317, 1269, 285, -1, 316, 1269, 317, -1, 284, 1269, 316, -1, 286, 1270, 285, -1, 318, 1270, 286, -1, 317, 1270, 318, -1, 285, 1270, 317, -1, 287, 1271, 286, -1, 319, 1271, 287, -1, 318, 1271, 319, -1, 286, 1271, 318, -1, 289, 1272, 288, -1, 321, 1272, 289, -1, 320, 1272, 321, -1, 288, 1272, 320, -1, 290, 1273, 289, -1, 322, 1273, 290, -1, 321, 1273, 322, -1, 289, 1273, 321, -1, 291, 1274, 290, -1, 323, 1274, 291, -1, 322, 1274, 323, -1, 290, 1274, 322, -1, 292, 1275, 291, -1, 324, 1275, 292, -1, 323, 1275, 324, -1, 291, 1275, 323, -1, 293, 1276, 292, -1, 325, 1276, 293, -1, 324, 1276, 325, -1, 292, 1276, 324, -1, 294, 1277, 293, -1, 326, 1277, 294, -1, 325, 1277, 326, -1, 293, 1277, 325, -1, 295, 1278, 294, -1, 327, 1278, 295, -1, 326, 1278, 327, -1, 294, 1278, 326, -1, 296, 1279, 295, -1, 328, 1279, 296, -1, 327, 1279, 328, -1, 295, 1279, 327, -1, 297, 1280, 296, -1, 329, 1280, 297, -1, 328, 1280, 329, -1, 296, 1280, 328, -1, 298, 1281, 297, -1, 330, 1281, 298, -1, 329, 1281, 330, -1, 297, 1281, 329, -1, 299, 1282, 298, -1, 331, 1282, 299, -1, 330, 1282, 331, -1, 298, 1282, 330, -1, 300, 1283, 299, -1, 332, 1283, 300, -1, 331, 1283, 332, -1, 299, 1283, 331, -1, 301, 1284, 300, -1, 333, 1284, 301, -1, 332, 1284, 333, -1, 300, 1284, 332, -1, 302, 1285, 301, -1, 334, 1285, 302, -1, 333, 1285, 334, -1, 301, 1285, 333, -1, 303, 1286, 302, -1, 335, 1286, 303, -1, 334, 1286, 335, -1, 302, 1286, 334, -1, 304, 1287, 303, -1, 336, 1287, 304, -1, 335, 1287, 336, -1, 303, 1287, 335, -1, 305, 1288, 304, -1, 337, 1288, 305, -1, 336, 1288, 337, -1, 304, 1288, 336, -1, 306, 1289, 305, -1, 338, 1289, 306, -1, 337, 1289, 338, -1, 305, 1289, 337, -1, 307, 1290, 306, -1, 339, 1290, 307, -1, 338, 1290, 339, -1, 306, 1290, 338, -1, 308, 1291, 307, -1, 340, 1291, 308, -1, 339, 1291, 340, -1, 307, 1291, 339, -1, 309, 1292, 308, -1, 341, 1292, 309, -1, 340, 1292, 341, -1, 308, 1292, 340, -1, 310, 1293, 309, -1, 342, 1293, 310, -1, 341, 1293, 342, -1, 309, 1293, 341, -1, 311, 1294, 310, -1, 343, 1294, 311, -1, 342, 1294, 343, -1, 310, 1294, 342, -1, 312, 1295, 311, -1, 344, 1295, 312, -1, 343, 1295, 344, -1, 311, 1295, 343, -1, 313, 1296, 312, -1, 345, 1296, 313, -1, 344, 1296, 345, -1, 312, 1296, 344, -1, 314, 1297, 313, -1, 346, 1297, 314, -1, 345, 1297, 346, -1, 313, 1297, 345, -1, 315, 1298, 314, -1, 347, 1298, 315, -1, 346, 1298, 347, -1, 314, 1298, 346, -1, 316, 1299, 315, -1, 348, 1299, 316, -1, 347, 1299, 348, -1, 315, 1299, 347, -1, 317, 1300, 316, -1, 349, 1300, 317, -1, 348, 1300, 349, -1, 316, 1300, 348, -1, 318, 1301, 317, -1, 350, 1301, 318, -1, 349, 1301, 350, -1, 317, 1301, 349, -1, 319, 1302, 318, -1, 351, 1302, 319, -1, 350, 1302, 351, -1, 318, 1302, 350, -1, 321, 1303, 320, -1, 353, 1303, 321, -1, 352, 1303, 353, -1, 320, 1303, 352, -1, 322, 1304, 321, -1, 354, 1304, 322, -1, 353, 1304, 354, -1, 321, 1304, 353, -1, 323, 1305, 322, -1, 355, 1305, 323, -1, 354, 1305, 355, -1, 322, 1305, 354, -1, 324, 1306, 323, -1, 356, 1306, 324, -1, 355, 1306, 356, -1, 323, 1306, 355, -1, 325, 1307, 324, -1, 357, 1307, 325, -1, 356, 1307, 357, -1, 324, 1307, 356, -1, 326, 1308, 325, -1, 358, 1308, 326, -1, 357, 1308, 358, -1, 325, 1308, 357, -1, 327, 1309, 326, -1, 359, 1309, 327, -1, 358, 1309, 359, -1, 326, 1309, 358, -1, 328, 1310, 327, -1, 360, 1310, 328, -1, 359, 1310, 360, -1, 327, 1310, 359, -1, 329, 1311, 328, -1, 361, 1311, 329, -1, 360, 1311, 361, -1, 328, 1311, 360, -1, 330, 1312, 329, -1, 362, 1312, 330, -1, 361, 1312, 362, -1, 329, 1312, 361, -1, 331, 1313, 330, -1, 363, 1313, 331, -1, 362, 1313, 363, -1, 330, 1313, 362, -1, 332, 1314, 331, -1, 364, 1314, 332, -1, 363, 1314, 364, -1, 331, 1314, 363, -1, 333, 1315, 332, -1, 365, 1315, 333, -1, 364, 1315, 365, -1, 332, 1315, 364, -1, 334, 1316, 333, -1, 366, 1316, 334, -1, 365, 1316, 366, -1, 333, 1316, 365, -1, 335, 1317, 334, -1, 367, 1317, 335, -1, 366, 1317, 367, -1, 334, 1317, 366, -1, 336, 1318, 335, -1, 368, 1318, 336, -1, 367, 1318, 368, -1, 335, 1318, 367, -1, 337, 1319, 336, -1, 369, 1319, 337, -1, 368, 1319, 369, -1, 336, 1319, 368, -1, 338, 1320, 337, -1, 370, 1320, 338, -1, 369, 1320, 370, -1, 337, 1320, 369, -1, 339, 1321, 338, -1, 371, 1321, 339, -1, 370, 1321, 371, -1, 338, 1321, 370, -1, 340, 1322, 339, -1, 372, 1322, 340, -1, 371, 1322, 372, -1, 339, 1322, 371, -1, 341, 1323, 340, -1, 373, 1323, 341, -1, 372, 1323, 373, -1, 340, 1323, 372, -1, 342, 1324, 341, -1, 374, 1324, 342, -1, 373, 1324, 374, -1, 341, 1324, 373, -1, 343, 1325, 342, -1, 375, 1325, 343, -1, 374, 1325, 375, -1, 342, 1325, 374, -1, 344, 1326, 343, -1, 376, 1326, 344, -1, 375, 1326, 376, -1, 343, 1326, 375, -1, 345, 1327, 344, -1, 377, 1327, 345, -1, 376, 1327, 377, -1, 344, 1327, 376, -1, 346, 1328, 345, -1, 378, 1328, 346, -1, 377, 1328, 378, -1, 345, 1328, 377, -1, 347, 1329, 346, -1, 379, 1329, 347, -1, 378, 1329, 379, -1, 346, 1329, 378, -1, 348, 1330, 347, -1, 380, 1330, 348, -1, 379, 1330, 380, -1, 347, 1330, 379, -1, 349, 1331, 348, -1, 381, 1331, 349, -1, 380, 1331, 381, -1, 348, 1331, 380, -1, 350, 1332, 349, -1, 382, 1332, 350, -1, 381, 1332, 382, -1, 349, 1332, 381, -1, 351, 1333, 350, -1, 383, 1333, 351, -1, 382, 1333, 383, -1, 350, 1333, 382, -1, 353, 1334, 352, -1, 385, 1334, 353, -1, 384, 1334, 385, -1, 352, 1334, 384, -1, 354, 1335, 353, -1, 386, 1335, 354, -1, 385, 1335, 386, -1, 353, 1335, 385, -1, 355, 1336, 354, -1, 387, 1336, 355, -1, 386, 1336, 387, -1, 354, 1336, 386, -1, 356, 1337, 355, -1, 388, 1337, 356, -1, 387, 1337, 388, -1, 355, 1337, 387, -1, 357, 1338, 356, -1, 389, 1338, 357, -1, 388, 1338, 389, -1, 356, 1338, 388, -1, 358, 1339, 357, -1, 390, 1339, 358, -1, 389, 1339, 390, -1, 357, 1339, 389, -1, 359, 1340, 358, -1, 391, 1340, 359, -1, 390, 1340, 391, -1, 358, 1340, 390, -1, 360, 1341, 359, -1, 392, 1341, 360, -1, 391, 1341, 392, -1, 359, 1341, 391, -1, 361, 1342, 360, -1, 393, 1342, 361, -1, 392, 1342, 393, -1, 360, 1342, 392, -1, 362, 1343, 361, -1, 394, 1343, 362, -1, 393, 1343, 394, -1, 361, 1343, 393, -1, 363, 1344, 362, -1, 395, 1344, 363, -1, 394, 1344, 395, -1, 362, 1344, 394, -1, 364, 1345, 363, -1, 396, 1345, 364, -1, 395, 1345, 396, -1, 363, 1345, 395, -1, 365, 1346, 364, -1, 397, 1346, 365, -1, 396, 1346, 397, -1, 364, 1346, 396, -1, 366, 1347, 365, -1, 398, 1347, 366, -1, 397, 1347, 398, -1, 365, 1347, 397, -1, 367, 1348, 366, -1, 399, 1348, 367, -1, 398, 1348, 399, -1, 366, 1348, 398, -1, 368, 1349, 367, -1, 400, 1349, 368, -1, 399, 1349, 400, -1, 367, 1349, 399, -1, 369, 1350, 368, -1, 401, 1350, 369, -1, 400, 1350, 401, -1, 368, 1350, 400, -1, 370, 1351, 369, -1, 402, 1351, 370, -1, 401, 1351, 402, -1, 369, 1351, 401, -1, 371, 1352, 370, -1, 403, 1352, 371, -1, 402, 1352, 403, -1, 370, 1352, 402, -1, 372, 1353, 371, -1, 404, 1353, 372, -1, 403, 1353, 404, -1, 371, 1353, 403, -1, 373, 1354, 372, -1, 405, 1354, 373, -1, 404, 1354, 405, -1, 372, 1354, 404, -1, 374, 1355, 373, -1, 406, 1355, 374, -1, 405, 1355, 406, -1, 373, 1355, 405, -1, 375, 1356, 374, -1, 407, 1356, 375, -1, 406, 1356, 407, -1, 374, 1356, 406, -1, 376, 1357, 375, -1, 408, 1357, 376, -1, 407, 1357, 408, -1, 375, 1357, 407, -1, 377, 1358, 376, -1, 409, 1358, 377, -1, 408, 1358, 409, -1, 376, 1358, 408, -1, 378, 1359, 377, -1, 410, 1359, 378, -1, 409, 1359, 410, -1, 377, 1359, 409, -1, 379, 1360, 378, -1, 411, 1360, 379, -1, 410, 1360, 411, -1, 378, 1360, 410, -1, 380, 1361, 379, -1, 412, 1361, 380, -1, 411, 1361, 412, -1, 379, 1361, 411, -1, 381, 1362, 380, -1, 413, 1362, 381, -1, 412, 1362, 413, -1, 380, 1362, 412, -1, 382, 1363, 381, -1, 414, 1363, 382, -1, 413, 1363, 414, -1, 381, 1363, 413, -1, 383, 1364, 382, -1, 415, 1364, 383, -1, 414, 1364, 415, -1, 382, 1364, 414, -1, 385, 1365, 384, -1, 417, 1365, 385, -1, 416, 1365, 417, -1, 384, 1365, 416, -1, 386, 1366, 385, -1, 418, 1366, 386, -1, 417, 1366, 418, -1, 385, 1366, 417, -1, 387, 1367, 386, -1, 419, 1367, 387, -1, 418, 1367, 419, -1, 386, 1367, 418, -1, 388, 1368, 387, -1, 420, 1368, 388, -1, 419, 1368, 420, -1, 387, 1368, 419, -1, 389, 1369, 388, -1, 421, 1369, 389, -1, 420, 1369, 421, -1, 388, 1369, 420, -1, 390, 1370, 389, -1, 422, 1370, 390, -1, 421, 1370, 422, -1, 389, 1370, 421, -1, 391, 1371, 390, -1, 423, 1371, 391, -1, 422, 1371, 423, -1, 390, 1371, 422, -1, 392, 1372, 391, -1, 424, 1372, 392, -1, 423, 1372, 424, -1, 391, 1372, 423, -1, 393, 1373, 392, -1, 425, 1373, 393, -1, 424, 1373, 425, -1, 392, 1373, 424, -1, 394, 1374, 393, -1, 426, 1374, 394, -1, 425, 1374, 426, -1, 393, 1374, 425, -1, 395, 1375, 394, -1, 427, 1375, 395, -1, 426, 1375, 427, -1, 394, 1375, 426, -1, 396, 1376, 395, -1, 428, 1376, 396, -1, 427, 1376, 428, -1, 395, 1376, 427, -1, 397, 1377, 396, -1, 429, 1377, 397, -1, 428, 1377, 429, -1, 396, 1377, 428, -1, 398, 1378, 397, -1, 430, 1378, 398, -1, 429, 1378, 430, -1, 397, 1378, 429, -1, 399, 1379, 398, -1, 431, 1379, 399, -1, 430, 1379, 431, -1, 398, 1379, 430, -1, 400, 1380, 399, -1, 432, 1380, 400, -1, 431, 1380, 432, -1, 399, 1380, 431, -1, 401, 1381, 400, -1, 433, 1381, 401, -1, 432, 1381, 433, -1, 400, 1381, 432, -1, 402, 1382, 401, -1, 434, 1382, 402, -1, 433, 1382, 434, -1, 401, 1382, 433, -1, 403, 1383, 402, -1, 435, 1383, 403, -1, 434, 1383, 435, -1, 402, 1383, 434, -1, 404, 1384, 403, -1, 436, 1384, 404, -1, 435, 1384, 436, -1, 403, 1384, 435, -1, 405, 1385, 404, -1, 437, 1385, 405, -1, 436, 1385, 437, -1, 404, 1385, 436, -1, 406, 1386, 405, -1, 438, 1386, 406, -1, 437, 1386, 438, -1, 405, 1386, 437, -1, 407, 1387, 406, -1, 439, 1387, 407, -1, 438, 1387, 439, -1, 406, 1387, 438, -1, 408, 1388, 407, -1, 440, 1388, 408, -1, 439, 1388, 440, -1, 407, 1388, 439, -1, 409, 1389, 408, -1, 441, 1389, 409, -1, 440, 1389, 441, -1, 408, 1389, 440, -1, 410, 1390, 409, -1, 442, 1390, 410, -1, 441, 1390, 442, -1, 409, 1390, 441, -1, 411, 1391, 410, -1, 443, 1391, 411, -1, 442, 1391, 443, -1, 410, 1391, 442, -1, 412, 1392, 411, -1, 444, 1392, 412, -1, 443, 1392, 444, -1, 411, 1392, 443, -1, 413, 1393, 412, -1, 445, 1393, 413, -1, 444, 1393, 445, -1, 412, 1393, 444, -1, 414, 1394, 413, -1, 446, 1394, 414, -1, 445, 1394, 446, -1, 413, 1394, 445, -1, 415, 1395, 414, -1, 447, 1395, 415, -1, 446, 1395, 447, -1, 414, 1395, 446, -1, 417, 1396, 416, -1, 449, 1396, 417, -1, 448, 1396, 449, -1, 416, 1396, 448, -1, 418, 1397, 417, -1, 450, 1397, 418, -1, 449, 1397, 450, -1, 417, 1397, 449, -1, 419, 1398, 418, -1, 451, 1398, 419, -1, 450, 1398, 451, -1, 418, 1398, 450, -1, 420, 1399, 419, -1, 452, 1399, 420, -1, 451, 1399, 452, -1, 419, 1399, 451, -1, 421, 1400, 420, -1, 453, 1400, 421, -1, 452, 1400, 453, -1, 420, 1400, 452, -1, 422, 1401, 421, -1, 454, 1401, 422, -1, 453, 1401, 454, -1, 421, 1401, 453, -1, 423, 1402, 422, -1, 455, 1402, 423, -1, 454, 1402, 455, -1, 422, 1402, 454, -1, 424, 1403, 423, -1, 456, 1403, 424, -1, 455, 1403, 456, -1, 423, 1403, 455, -1, 425, 1404, 424, -1, 457, 1404, 425, -1, 456, 1404, 457, -1, 424, 1404, 456, -1, 426, 1405, 425, -1, 458, 1405, 426, -1, 457, 1405, 458, -1, 425, 1405, 457, -1, 427, 1406, 426, -1, 459, 1406, 427, -1, 458, 1406, 459, -1, 426, 1406, 458, -1, 428, 1407, 427, -1, 460, 1407, 428, -1, 459, 1407, 460, -1, 427, 1407, 459, -1, 429, 1408, 428, -1, 461, 1408, 429, -1, 460, 1408, 461, -1, 428, 1408, 460, -1, 430, 1409, 429, -1, 462, 1409, 430, -1, 461, 1409, 462, -1, 429, 1409, 461, -1, 431, 1410, 430, -1, 463, 1410, 431, -1, 462, 1410, 463, -1, 430, 1410, 462, -1, 432, 1411, 431, -1, 464, 1411, 432, -1, 463, 1411, 464, -1, 431, 1411, 463, -1, 433, 1412, 432, -1, 465, 1412, 433, -1, 464, 1412, 465, -1, 432, 1412, 464, -1, 434, 1413, 433, -1, 466, 1413, 434, -1, 465, 1413, 466, -1, 433, 1413, 465, -1, 435, 1414, 434, -1, 467, 1414, 435, -1, 466, 1414, 467, -1, 434, 1414, 466, -1, 436, 1415, 435, -1, 468, 1415, 436, -1, 467, 1415, 468, -1, 435, 1415, 467, -1, 437, 1416, 436, -1, 469, 1416, 437, -1, 468, 1416, 469, -1, 436, 1416, 468, -1, 438, 1417, 437, -1, 470, 1417, 438, -1, 469, 1417, 470, -1, 437, 1417, 469, -1, 439, 1418, 438, -1, 471, 1418, 439, -1, 470, 1418, 471, -1, 438, 1418, 470, -1, 440, 1419, 439, -1, 472, 1419, 440, -1, 471, 1419, 472, -1, 439, 1419, 471, -1, 441, 1420, 440, -1, 473, 1420, 441, -1, 472, 1420, 473, -1, 440, 1420, 472, -1, 442, 1421, 441, -1, 474, 1421, 442, -1, 473, 1421, 474, -1, 441, 1421, 473, -1, 443, 1422, 442, -1, 475, 1422, 443, -1, 474, 1422, 475, -1, 442, 1422, 474, -1, 444, 1423, 443, -1, 476, 1423, 444, -1, 475, 1423, 476, -1, 443, 1423, 475, -1, 445, 1424, 444, -1, 477, 1424, 445, -1, 476, 1424, 477, -1, 444, 1424, 476, -1, 446, 1425, 445, -1, 478, 1425, 446, -1, 477, 1425, 478, -1, 445, 1425, 477, -1, 447, 1426, 446, -1, 479, 1426, 447, -1, 478, 1426, 479, -1, 446, 1426, 478, -1, 449, 1427, 448, -1, 481, 1427, 449, -1, 480, 1427, 481, -1, 448, 1427, 480, -1, 450, 1428, 449, -1, 482, 1428, 450, -1, 481, 1428, 482, -1, 449, 1428, 481, -1, 451, 1429, 450, -1, 483, 1429, 451, -1, 482, 1429, 483, -1, 450, 1429, 482, -1, 452, 1430, 451, -1, 484, 1430, 452, -1, 483, 1430, 484, -1, 451, 1430, 483, -1, 453, 1431, 452, -1, 485, 1431, 453, -1, 484, 1431, 485, -1, 452, 1431, 484, -1, 454, 1432, 453, -1, 486, 1432, 454, -1, 485, 1432, 486, -1, 453, 1432, 485, -1, 455, 1433, 454, -1, 487, 1433, 455, -1, 486, 1433, 487, -1, 454, 1433, 486, -1, 456, 1434, 455, -1, 488, 1434, 456, -1, 487, 1434, 488, -1, 455, 1434, 487, -1, 457, 1435, 456, -1, 489, 1435, 457, -1, 488, 1435, 489, -1, 456, 1435, 488, -1, 458, 1436, 457, -1, 490, 1436, 458, -1, 489, 1436, 490, -1, 457, 1436, 489, -1, 459, 1437, 458, -1, 491, 1437, 459, -1, 490, 1437, 491, -1, 458, 1437, 490, -1, 460, 1438, 459, -1, 492, 1438, 460, -1, 491, 1438, 492, -1, 459, 1438, 491, -1, 461, 1439, 460, -1, 493, 1439, 461, -1, 492, 1439, 493, -1, 460, 1439, 492, -1, 462, 1440, 461, -1, 494, 1440, 462, -1, 493, 1440, 494, -1, 461, 1440, 493, -1, 463, 1441, 462, -1, 495, 1441, 463, -1, 494, 1441, 495, -1, 462, 1441, 494, -1, 464, 1442, 463, -1, 496, 1442, 464, -1, 495, 1442, 496, -1, 463, 1442, 495, -1, 465, 1443, 464, -1, 497, 1443, 465, -1, 496, 1443, 497, -1, 464, 1443, 496, -1, 466, 1444, 465, -1, 498, 1444, 466, -1, 497, 1444, 498, -1, 465, 1444, 497, -1, 467, 1445, 466, -1, 499, 1445, 467, -1, 498, 1445, 499, -1, 466, 1445, 498, -1, 468, 1446, 467, -1, 500, 1446, 468, -1, 499, 1446, 500, -1, 467, 1446, 499, -1, 469, 1447, 468, -1, 501, 1447, 469, -1, 500, 1447, 501, -1, 468, 1447, 500, -1, 470, 1448, 469, -1, 502, 1448, 470, -1, 501, 1448, 502, -1, 469, 1448, 501, -1, 471, 1449, 470, -1, 503, 1449, 471, -1, 502, 1449, 503, -1, 470, 1449, 502, -1, 472, 1450, 471, -1, 504, 1450, 472, -1, 503, 1450, 504, -1, 471, 1450, 503, -1, 473, 1451, 472, -1, 505, 1451, 473, -1, 504, 1451, 505, -1, 472, 1451, 504, -1, 474, 1452, 473, -1, 506, 1452, 474, -1, 505, 1452, 506, -1, 473, 1452, 505, -1, 475, 1453, 474, -1, 507, 1453, 475, -1, 506, 1453, 507, -1, 474, 1453, 506, -1, 476, 1454, 475, -1, 508, 1454, 476, -1, 507, 1454, 508, -1, 475, 1454, 507, -1, 477, 1455, 476, -1, 509, 1455, 477, -1, 508, 1455, 509, -1, 476, 1455, 508, -1, 478, 1456, 477, -1, 510, 1456, 478, -1, 509, 1456, 510, -1, 477, 1456, 509, -1, 479, 1457, 478, -1, 511, 1457, 479, -1, 510, 1457, 511, -1, 478, 1457, 510, -1, 481, 1458, 480, -1, 513, 1458, 481, -1, 512, 1458, 513, -1, 480, 1458, 512, -1, 482, 1459, 481, -1, 514, 1459, 482, -1, 513, 1459, 514, -1, 481, 1459, 513, -1, 483, 1460, 482, -1, 515, 1460, 483, -1, 514, 1460, 515, -1, 482, 1460, 514, -1, 484, 1461, 483, -1, 516, 1461, 484, -1, 515, 1461, 516, -1, 483, 1461, 515, -1, 485, 1462, 484, -1, 517, 1462, 485, -1, 516, 1462, 517, -1, 484, 1462, 516, -1, 486, 1463, 485, -1, 518, 1463, 486, -1, 517, 1463, 518, -1, 485, 1463, 517, -1, 487, 1464, 486, -1, 519, 1464, 487, -1, 518, 1464, 519, -1, 486, 1464, 518, -1, 488, 1465, 487, -1, 520, 1465, 488, -1, 519, 1465, 520, -1, 487, 1465, 519, -1, 489, 1466, 488, -1, 521, 1466, 489, -1, 520, 1466, 521, -1, 488, 1466, 520, -1, 490, 1467, 489, -1, 522, 1467, 490, -1, 521, 1467, 522, -1, 489, 1467, 521, -1, 491, 1468, 490, -1, 523, 1468, 491, -1, 522, 1468, 523, -1, 490, 1468, 522, -1, 492, 1469, 491, -1, 524, 1469, 492, -1, 523, 1469, 524, -1, 491, 1469, 523, -1, 493, 1470, 492, -1, 525, 1470, 493, -1, 524, 1470, 525, -1, 492, 1470, 524, -1, 494, 1471, 493, -1, 526, 1471, 494, -1, 525, 1471, 526, -1, 493, 1471, 525, -1, 495, 1472, 494, -1, 527, 1472, 495, -1, 526, 1472, 527, -1, 494, 1472, 526, -1, 496, 1473, 495, -1, 528, 1473, 496, -1, 527, 1473, 528, -1, 495, 1473, 527, -1, 497, 1474, 496, -1, 529, 1474, 497, -1, 528, 1474, 529, -1, 496, 1474, 528, -1, 498, 1475, 497, -1, 530, 1475, 498, -1, 529, 1475, 530, -1, 497, 1475, 529, -1, 499, 1476, 498, -1, 531, 1476, 499, -1, 530, 1476, 531, -1, 498, 1476, 530, -1, 500, 1477, 499, -1, 532, 1477, 500, -1, 531, 1477, 532, -1, 499, 1477, 531, -1, 501, 1478, 500, -1, 533, 1478, 501, -1, 532, 1478, 533, -1, 500, 1478, 532, -1, 502, 1479, 501, -1, 534, 1479, 502, -1, 533, 1479, 534, -1, 501, 1479, 533, -1, 503, 1480, 502, -1, 535, 1480, 503, -1, 534, 1480, 535, -1, 502, 1480, 534, -1, 504, 1481, 503, -1, 536, 1481, 504, -1, 535, 1481, 536, -1, 503, 1481, 535, -1, 505, 1482, 504, -1, 537, 1482, 505, -1, 536, 1482, 537, -1, 504, 1482, 536, -1, 506, 1483, 505, -1, 538, 1483, 506, -1, 537, 1483, 538, -1, 505, 1483, 537, -1, 507, 1484, 506, -1, 539, 1484, 507, -1, 538, 1484, 539, -1, 506, 1484, 538, -1, 508, 1485, 507, -1, 540, 1485, 508, -1, 539, 1485, 540, -1, 507, 1485, 539, -1, 509, 1486, 508, -1, 541, 1486, 509, -1, 540, 1486, 541, -1, 508, 1486, 540, -1, 510, 1487, 509, -1, 542, 1487, 510, -1, 541, 1487, 542, -1, 509, 1487, 541, -1, 511, 1488, 510, -1, 543, 1488, 511, -1, 542, 1488, 543, -1, 510, 1488, 542, -1, 513, 1489, 512, -1, 545, 1489, 513, -1, 544, 1489, 545, -1, 512, 1489, 544, -1, 514, 1490, 513, -1, 546, 1490, 514, -1, 545, 1490, 546, -1, 513, 1490, 545, -1, 515, 1491, 514, -1, 547, 1491, 515, -1, 546, 1491, 547, -1, 514, 1491, 546, -1, 516, 1492, 515, -1, 548, 1492, 516, -1, 547, 1492, 548, -1, 515, 1492, 547, -1, 517, 1493, 516, -1, 549, 1493, 517, -1, 548, 1493, 549, -1, 516, 1493, 548, -1, 518, 1494, 517, -1, 550, 1494, 518, -1, 549, 1494, 550, -1, 517, 1494, 549, -1, 519, 1495, 518, -1, 551, 1495, 519, -1, 550, 1495, 551, -1, 518, 1495, 550, -1, 520, 1496, 519, -1, 552, 1496, 520, -1, 551, 1496, 552, -1, 519, 1496, 551, -1, 521, 1497, 520, -1, 553, 1497, 521, -1, 552, 1497, 553, -1, 520, 1497, 552, -1, 522, 1498, 521, -1, 554, 1498, 522, -1, 553, 1498, 554, -1, 521, 1498, 553, -1, 523, 1499, 522, -1, 555, 1499, 523, -1, 554, 1499, 555, -1, 522, 1499, 554, -1, 524, 1500, 523, -1, 556, 1500, 524, -1, 555, 1500, 556, -1, 523, 1500, 555, -1, 525, 1501, 524, -1, 557, 1501, 525, -1, 556, 1501, 557, -1, 524, 1501, 556, -1, 526, 1502, 525, -1, 558, 1502, 526, -1, 557, 1502, 558, -1, 525, 1502, 557, -1, 527, 1503, 526, -1, 559, 1503, 527, -1, 558, 1503, 559, -1, 526, 1503, 558, -1, 528, 1504, 527, -1, 560, 1504, 528, -1, 559, 1504, 560, -1, 527, 1504, 559, -1, 529, 1505, 528, -1, 561, 1505, 529, -1, 560, 1505, 561, -1, 528, 1505, 560, -1, 530, 1506, 529, -1, 562, 1506, 530, -1, 561, 1506, 562, -1, 529, 1506, 561, -1, 531, 1507, 530, -1, 563, 1507, 531, -1, 562, 1507, 563, -1, 530, 1507, 562, -1, 532, 1508, 531, -1, 564, 1508, 532, -1, 563, 1508, 564, -1, 531, 1508, 563, -1, 533, 1509, 532, -1, 565, 1509, 533, -1, 564, 1509, 565, -1, 532, 1509, 564, -1, 534, 1510, 533, -1, 566, 1510, 534, -1, 565, 1510, 566, -1, 533, 1510, 565, -1, 535, 1511, 534, -1, 567, 1511, 535, -1, 566, 1511, 567, -1, 534, 1511, 566, -1, 536, 1512, 535, -1, 568, 1512, 536, -1, 567, 1512, 568, -1, 535, 1512, 567, -1, 537, 1513, 536, -1, 569, 1513, 537, -1, 568, 1513, 569, -1, 536, 1513, 568, -1, 538, 1514, 537, -1, 570, 1514, 538, -1, 569, 1514, 570, -1, 537, 1514, 569, -1, 539, 1515, 538, -1, 571, 1515, 539, -1, 570, 1515, 571, -1, 538, 1515, 570, -1, 540, 1516, 539, -1, 572, 1516, 540, -1, 571, 1516, 572, -1, 539, 1516, 571, -1, 541, 1517, 540, -1, 573, 1517, 541, -1, 572, 1517, 573, -1, 540, 1517, 572, -1, 542, 1518, 541, -1, 574, 1518, 542, -1, 573, 1518, 574, -1, 541, 1518, 573, -1, 543, 1519, 542, -1, 575, 1519, 543, -1, 574, 1519, 575, -1, 542, 1519, 574, -1, 545, 1520, 544, -1, 577, 1520, 545, -1, 576, 1520, 577, -1, 544, 1520, 576, -1, 546, 1521, 545, -1, 578, 1521, 546, -1, 577, 1521, 578, -1, 545, 1521, 577, -1, 547, 1522, 546, -1, 579, 1522, 547, -1, 578, 1522, 579, -1, 546, 1522, 578, -1, 548, 1523, 547, -1, 580, 1523, 548, -1, 579, 1523, 580, -1, 547, 1523, 579, -1, 549, 1524, 548, -1, 581, 1524, 549, -1, 580, 1524, 581, -1, 548, 1524, 580, -1, 550, 1525, 549, -1, 582, 1525, 550, -1, 581, 1525, 582, -1, 549, 1525, 581, -1, 551, 1526, 550, -1, 583, 1526, 551, -1, 582, 1526, 583, -1, 550, 1526, 582, -1, 552, 1527, 551, -1, 584, 1527, 552, -1, 583, 1527, 584, -1, 551, 1527, 583, -1, 553, 1528, 552, -1, 585, 1528, 553, -1, 584, 1528, 585, -1, 552, 1528, 584, -1, 554, 1529, 553, -1, 586, 1529, 554, -1, 585, 1529, 586, -1, 553, 1529, 585, -1, 555, 1530, 554, -1, 587, 1530, 555, -1, 586, 1530, 587, -1, 554, 1530, 586, -1, 556, 1531, 555, -1, 588, 1531, 556, -1, 587, 1531, 588, -1, 555, 1531, 587, -1, 557, 1532, 556, -1, 589, 1532, 557, -1, 588, 1532, 589, -1, 556, 1532, 588, -1, 558, 1533, 557, -1, 590, 1533, 558, -1, 589, 1533, 590, -1, 557, 1533, 589, -1, 559, 1534, 558, -1, 591, 1534, 559, -1, 590, 1534, 591, -1, 558, 1534, 590, -1, 560, 1535, 559, -1, 592, 1535, 560, -1, 591, 1535, 592, -1, 559, 1535, 591, -1, 561, 1536, 560, -1, 593, 1536, 561, -1, 592, 1536, 593, -1, 560, 1536, 592, -1, 562, 1537, 561, -1, 594, 1537, 562, -1, 593, 1537, 594, -1, 561, 1537, 593, -1, 563, 1538, 562, -1, 595, 1538, 563, -1, 594, 1538, 595, -1, 562, 1538, 594, -1, 564, 1539, 563, -1, 596, 1539, 564, -1, 595, 1539, 596, -1, 563, 1539, 595, -1, 565, 1540, 564, -1, 597, 1540, 565, -1, 596, 1540, 597, -1, 564, 1540, 596, -1, 566, 1541, 565, -1, 598, 1541, 566, -1, 597, 1541, 598, -1, 565, 1541, 597, -1, 567, 1542, 566, -1, 599, 1542, 567, -1, 598, 1542, 599, -1, 566, 1542, 598, -1, 568, 1543, 567, -1, 600, 1543, 568, -1, 599, 1543, 600, -1, 567, 1543, 599, -1, 569, 1544, 568, -1, 601, 1544, 569, -1, 600, 1544, 601, -1, 568, 1544, 600, -1, 570, 1545, 569, -1, 602, 1545, 570, -1, 601, 1545, 602, -1, 569, 1545, 601, -1, 571, 1546, 570, -1, 603, 1546, 571, -1, 602, 1546, 603, -1, 570, 1546, 602, -1, 572, 1547, 571, -1, 604, 1547, 572, -1, 603, 1547, 604, -1, 571, 1547, 603, -1, 573, 1548, 572, -1, 605, 1548, 573, -1, 604, 1548, 605, -1, 572, 1548, 604, -1, 574, 1549, 573, -1, 606, 1549, 574, -1, 605, 1549, 606, -1, 573, 1549, 605, -1, 575, 1550, 574, -1, 607, 1550, 575, -1, 606, 1550, 607, -1, 574, 1550, 606, -1, 577, 1551, 576, -1, 609, 1551, 577, -1, 608, 1551, 609, -1, 576, 1551, 608, -1, 578, 1552, 577, -1, 610, 1552, 578, -1, 609, 1552, 610, -1, 577, 1552, 609, -1, 579, 1553, 578, -1, 611, 1553, 579, -1, 610, 1553, 611, -1, 578, 1553, 610, -1, 580, 1554, 579, -1, 612, 1554, 580, -1, 611, 1554, 612, -1, 579, 1554, 611, -1, 581, 1555, 580, -1, 613, 1555, 581, -1, 612, 1555, 613, -1, 580, 1555, 612, -1, 582, 1556, 581, -1, 614, 1556, 582, -1, 613, 1556, 614, -1, 581, 1556, 613, -1, 583, 1557, 582, -1, 615, 1557, 583, -1, 614, 1557, 615, -1, 582, 1557, 614, -1, 584, 1558, 583, -1, 616, 1558, 584, -1, 615, 1558, 616, -1, 583, 1558, 615, -1, 585, 1559, 584, -1, 617, 1559, 585, -1, 616, 1559, 617, -1, 584, 1559, 616, -1, 586, 1560, 585, -1, 618, 1560, 586, -1, 617, 1560, 618, -1, 585, 1560, 617, -1, 587, 1561, 586, -1, 619, 1561, 587, -1, 618, 1561, 619, -1, 586, 1561, 618, -1, 588, 1562, 587, -1, 620, 1562, 588, -1, 619, 1562, 620, -1, 587, 1562, 619, -1, 589, 1563, 588, -1, 621, 1563, 589, -1, 620, 1563, 621, -1, 588, 1563, 620, -1, 590, 1564, 589, -1, 622, 1564, 590, -1, 621, 1564, 622, -1, 589, 1564, 621, -1, 591, 1565, 590, -1, 623, 1565, 591, -1, 622, 1565, 623, -1, 590, 1565, 622, -1, 592, 1566, 591, -1, 624, 1566, 592, -1, 623, 1566, 624, -1, 591, 1566, 623, -1, 593, 1567, 592, -1, 625, 1567, 593, -1, 624, 1567, 625, -1, 592, 1567, 624, -1, 594, 1568, 593, -1, 626, 1568, 594, -1, 625, 1568, 626, -1, 593, 1568, 625, -1, 595, 1569, 594, -1, 627, 1569, 595, -1, 626, 1569, 627, -1, 594, 1569, 626, -1, 596, 1570, 595, -1, 628, 1570, 596, -1, 627, 1570, 628, -1, 595, 1570, 627, -1, 597, 1571, 596, -1, 629, 1571, 597, -1, 628, 1571, 629, -1, 596, 1571, 628, -1, 598, 1572, 597, -1, 630, 1572, 598, -1, 629, 1572, 630, -1, 597, 1572, 629, -1, 599, 1573, 598, -1, 631, 1573, 599, -1, 630, 1573, 631, -1, 598, 1573, 630, -1, 600, 1574, 599, -1, 632, 1574, 600, -1, 631, 1574, 632, -1, 599, 1574, 631, -1, 601, 1575, 600, -1, 633, 1575, 601, -1, 632, 1575, 633, -1, 600, 1575, 632, -1, 602, 1576, 601, -1, 634, 1576, 602, -1, 633, 1576, 634, -1, 601, 1576, 633, -1, 603, 1577, 602, -1, 635, 1577, 603, -1, 634, 1577, 635, -1, 602, 1577, 634, -1, 604, 1578, 603, -1, 636, 1578, 604, -1, 635, 1578, 636, -1, 603, 1578, 635, -1, 605, 1579, 604, -1, 637, 1579, 605, -1, 636, 1579, 637, -1, 604, 1579, 636, -1, 606, 1580, 605, -1, 638, 1580, 606, -1, 637, 1580, 638, -1, 605, 1580, 637, -1, 607, 1581, 606, -1, 639, 1581, 607, -1, 638, 1581, 639, -1, 606, 1581, 638, -1, 609, 1582, 608, -1, 641, 1582, 609, -1, 640, 1582, 641, -1, 608, 1582, 640, -1, 610, 1583, 609, -1, 642, 1583, 610, -1, 641, 1583, 642, -1, 609, 1583, 641, -1, 611, 1584, 610, -1, 643, 1584, 611, -1, 642, 1584, 643, -1, 610, 1584, 642, -1, 612, 1585, 611, -1, 644, 1585, 612, -1, 643, 1585, 644, -1, 611, 1585, 643, -1, 613, 1586, 612, -1, 645, 1586, 613, -1, 644, 1586, 645, -1, 612, 1586, 644, -1, 614, 1587, 613, -1, 646, 1587, 614, -1, 645, 1587, 646, -1, 613, 1587, 645, -1, 615, 1588, 614, -1, 647, 1588, 615, -1, 646, 1588, 647, -1, 614, 1588, 646, -1, 616, 1589, 615, -1, 648, 1589, 616, -1, 647, 1589, 648, -1, 615, 1589, 647, -1, 617, 1590, 616, -1, 649, 1590, 617, -1, 648, 1590, 649, -1, 616, 1590, 648, -1, 618, 1591, 617, -1, 650, 1591, 618, -1, 649, 1591, 650, -1, 617, 1591, 649, -1, 619, 1592, 618, -1, 651, 1592, 619, -1, 650, 1592, 651, -1, 618, 1592, 650, -1, 620, 1593, 619, -1, 652, 1593, 620, -1, 651, 1593, 652, -1, 619, 1593, 651, -1, 621, 1594, 620, -1, 653, 1594, 621, -1, 652, 1594, 653, -1, 620, 1594, 652, -1, 622, 1595, 621, -1, 654, 1595, 622, -1, 653, 1595, 654, -1, 621, 1595, 653, -1, 623, 1596, 622, -1, 655, 1596, 623, -1, 654, 1596, 655, -1, 622, 1596, 654, -1, 624, 1597, 623, -1, 656, 1597, 624, -1, 655, 1597, 656, -1, 623, 1597, 655, -1, 625, 1598, 624, -1, 657, 1598, 625, -1, 656, 1598, 657, -1, 624, 1598, 656, -1, 626, 1599, 625, -1, 658, 1599, 626, -1, 657, 1599, 658, -1, 625, 1599, 657, -1, 627, 1600, 626, -1, 659, 1600, 627, -1, 658, 1600, 659, -1, 626, 1600, 658, -1, 628, 1601, 627, -1, 660, 1601, 628, -1, 659, 1601, 660, -1, 627, 1601, 659, -1, 629, 1602, 628, -1, 661, 1602, 629, -1, 660, 1602, 661, -1, 628, 1602, 660, -1, 630, 1603, 629, -1, 662, 1603, 630, -1, 661, 1603, 662, -1, 629, 1603, 661, -1, 631, 1604, 630, -1, 663, 1604, 631, -1, 662, 1604, 663, -1, 630, 1604, 662, -1, 632, 1605, 631, -1, 664, 1605, 632, -1, 663, 1605, 664, -1, 631, 1605, 663, -1, 633, 1606, 632, -1, 665, 1606, 633, -1, 664, 1606, 665, -1, 632, 1606, 664, -1, 634, 1607, 633, -1, 666, 1607, 634, -1, 665, 1607, 666, -1, 633, 1607, 665, -1, 635, 1608, 634, -1, 667, 1608, 635, -1, 666, 1608, 667, -1, 634, 1608, 666, -1, 636, 1609, 635, -1, 668, 1609, 636, -1, 667, 1609, 668, -1, 635, 1609, 667, -1, 637, 1610, 636, -1, 669, 1610, 637, -1, 668, 1610, 669, -1, 636, 1610, 668, -1, 638, 1611, 637, -1, 670, 1611, 638, -1, 669, 1611, 670, -1, 637, 1611, 669, -1, 639, 1612, 638, -1, 671, 1612, 639, -1, 670, 1612, 671, -1, 638, 1612, 670, -1, 641, 1613, 640, -1, 673, 1613, 641, -1, 672, 1613, 673, -1, 640, 1613, 672, -1, 642, 1614, 641, -1, 674, 1614, 642, -1, 673, 1614, 674, -1, 641, 1614, 673, -1, 643, 1615, 642, -1, 675, 1615, 643, -1, 674, 1615, 675, -1, 642, 1615, 674, -1, 644, 1616, 643, -1, 676, 1616, 644, -1, 675, 1616, 676, -1, 643, 1616, 675, -1, 645, 1617, 644, -1, 677, 1617, 645, -1, 676, 1617, 677, -1, 644, 1617, 676, -1, 646, 1618, 645, -1, 678, 1618, 646, -1, 677, 1618, 678, -1, 645, 1618, 677, -1, 647, 1619, 646, -1, 679, 1619, 647, -1, 678, 1619, 679, -1, 646, 1619, 678, -1, 648, 1620, 647, -1, 680, 1620, 648, -1, 679, 1620, 680, -1, 647, 1620, 679, -1, 649, 1621, 648, -1, 681, 1621, 649, -1, 680, 1621, 681, -1, 648, 1621, 680, -1, 650, 1622, 649, -1, 682, 1622, 650, -1, 681, 1622, 682, -1, 649, 1622, 681, -1, 651, 1623, 650, -1, 683, 1623, 651, -1, 682, 1623, 683, -1, 650, 1623, 682, -1, 652, 1624, 651, -1, 684, 1624, 652, -1, 683, 1624, 684, -1, 651, 1624, 683, -1, 653, 1625, 652, -1, 685, 1625, 653, -1, 684, 1625, 685, -1, 652, 1625, 684, -1, 654, 1626, 653, -1, 686, 1626, 654, -1, 685, 1626, 686, -1, 653, 1626, 685, -1, 655, 1627, 654, -1, 687, 1627, 655, -1, 686, 1627, 687, -1, 654, 1627, 686, -1, 656, 1628, 655, -1, 688, 1628, 656, -1, 687, 1628, 688, -1, 655, 1628, 687, -1, 657, 1629, 656, -1, 689, 1629, 657, -1, 688, 1629, 689, -1, 656, 1629, 688, -1, 658, 1630, 657, -1, 690, 1630, 658, -1, 689, 1630, 690, -1, 657, 1630, 689, -1, 659, 1631, 658, -1, 691, 1631, 659, -1, 690, 1631, 691, -1, 658, 1631, 690, -1, 660, 1632, 659, -1, 692, 1632, 660, -1, 691, 1632, 692, -1, 659, 1632, 691, -1, 661, 1633, 660, -1, 693, 1633, 661, -1, 692, 1633, 693, -1, 660, 1633, 692, -1, 662, 1634, 661, -1, 694, 1634, 662, -1, 693, 1634, 694, -1, 661, 1634, 693, -1, 663, 1635, 662, -1, 695, 1635, 663, -1, 694, 1635, 695, -1, 662, 1635, 694, -1, 664, 1636, 663, -1, 696, 1636, 664, -1, 695, 1636, 696, -1, 663, 1636, 695, -1, 665, 1637, 664, -1, 697, 1637, 665, -1, 696, 1637, 697, -1, 664, 1637, 696, -1, 666, 1638, 665, -1, 698, 1638, 666, -1, 697, 1638, 698, -1, 665, 1638, 697, -1, 667, 1639, 666, -1, 699, 1639, 667, -1, 698, 1639, 699, -1, 666, 1639, 698, -1, 668, 1640, 667, -1, 700, 1640, 668, -1, 699, 1640, 700, -1, 667, 1640, 699, -1, 669, 1641, 668, -1, 701, 1641, 669, -1, 700, 1641, 701, -1, 668, 1641, 700, -1, 670, 1642, 669, -1, 702, 1642, 670, -1, 701, 1642, 702, -1, 669, 1642, 701, -1, 671, 1643, 670, -1, 703, 1643, 671, -1, 702, 1643, 703, -1, 670, 1643, 702, -1, 673, 1644, 672, -1, 705, 1644, 673, -1, 704, 1644, 705, -1, 672, 1644, 704, -1, 674, 1645, 673, -1, 706, 1645, 674, -1, 705, 1645, 706, -1, 673, 1645, 705, -1, 675, 1646, 674, -1, 707, 1646, 675, -1, 706, 1646, 707, -1, 674, 1646, 706, -1, 676, 1647, 675, -1, 708, 1647, 676, -1, 707, 1647, 708, -1, 675, 1647, 707, -1, 677, 1648, 676, -1, 709, 1648, 677, -1, 708, 1648, 709, -1, 676, 1648, 708, -1, 678, 1649, 677, -1, 710, 1649, 678, -1, 709, 1649, 710, -1, 677, 1649, 709, -1, 679, 1650, 678, -1, 711, 1650, 679, -1, 710, 1650, 711, -1, 678, 1650, 710, -1, 680, 1651, 679, -1, 712, 1651, 680, -1, 711, 1651, 712, -1, 679, 1651, 711, -1, 681, 1652, 680, -1, 713, 1652, 681, -1, 712, 1652, 713, -1, 680, 1652, 712, -1, 682, 1653, 681, -1, 714, 1653, 682, -1, 713, 1653, 714, -1, 681, 1653, 713, -1, 683, 1654, 682, -1, 715, 1654, 683, -1, 714, 1654, 715, -1, 682, 1654, 714, -1, 684, 1655, 683, -1, 716, 1655, 684, -1, 715, 1655, 716, -1, 683, 1655, 715, -1, 685, 1656, 684, -1, 717, 1656, 685, -1, 716, 1656, 717, -1, 684, 1656, 716, -1, 686, 1657, 685, -1, 718, 1657, 686, -1, 717, 1657, 718, -1, 685, 1657, 717, -1, 687, 1658, 686, -1, 719, 1658, 687, -1, 718, 1658, 719, -1, 686, 1658, 718, -1, 688, 1659, 687, -1, 720, 1659, 688, -1, 719, 1659, 720, -1, 687, 1659, 719, -1, 689, 1660, 688, -1, 721, 1660, 689, -1, 720, 1660, 721, -1, 688, 1660, 720, -1, 690, 1661, 689, -1, 722, 1661, 690, -1, 721, 1661, 722, -1, 689, 1661, 721, -1, 691, 1662, 690, -1, 723, 1662, 691, -1, 722, 1662, 723, -1, 690, 1662, 722, -1, 692, 1663, 691, -1, 724, 1663, 692, -1, 723, 1663, 724, -1, 691, 1663, 723, -1, 693, 1664, 692, -1, 725, 1664, 693, -1, 724, 1664, 725, -1, 692, 1664, 724, -1, 694, 1665, 693, -1, 726, 1665, 694, -1, 725, 1665, 726, -1, 693, 1665, 725, -1, 695, 1666, 694, -1, 727, 1666, 695, -1, 726, 1666, 727, -1, 694, 1666, 726, -1, 696, 1667, 695, -1, 728, 1667, 696, -1, 727, 1667, 728, -1, 695, 1667, 727, -1, 697, 1668, 696, -1, 729, 1668, 697, -1, 728, 1668, 729, -1, 696, 1668, 728, -1, 698, 1669, 697, -1, 730, 1669, 698, -1, 729, 1669, 730, -1, 697, 1669, 729, -1, 699, 1670, 698, -1, 731, 1670, 699, -1, 730, 1670, 731, -1, 698, 1670, 730, -1, 700, 1671, 699, -1, 732, 1671, 700, -1, 731, 1671, 732, -1, 699, 1671, 731, -1, 701, 1672, 700, -1, 733, 1672, 701, -1, 732, 1672, 733, -1, 700, 1672, 732, -1, 702, 1673, 701, -1, 734, 1673, 702, -1, 733, 1673, 734, -1, 701, 1673, 733, -1, 703, 1674, 702, -1, 735, 1674, 703, -1, 734, 1674, 735, -1, 702, 1674, 734, -1, 705, 1675, 704, -1, 737, 1675, 705, -1, 736, 1675, 737, -1, 704, 1675, 736, -1, 706, 1676, 705, -1, 738, 1676, 706, -1, 737, 1676, 738, -1, 705, 1676, 737, -1, 707, 1677, 706, -1, 739, 1677, 707, -1, 738, 1677, 739, -1, 706, 1677, 738, -1, 708, 1678, 707, -1, 740, 1678, 708, -1, 739, 1678, 740, -1, 707, 1678, 739, -1, 709, 1679, 708, -1, 741, 1679, 709, -1, 740, 1679, 741, -1, 708, 1679, 740, -1, 710, 1680, 709, -1, 742, 1680, 710, -1, 741, 1680, 742, -1, 709, 1680, 741, -1, 711, 1681, 710, -1, 743, 1681, 711, -1, 742, 1681, 743, -1, 710, 1681, 742, -1, 712, 1682, 711, -1, 744, 1682, 712, -1, 743, 1682, 744, -1, 711, 1682, 743, -1, 713, 1683, 712, -1, 745, 1683, 713, -1, 744, 1683, 745, -1, 712, 1683, 744, -1, 714, 1684, 713, -1, 746, 1684, 714, -1, 745, 1684, 746, -1, 713, 1684, 745, -1, 715, 1685, 714, -1, 747, 1685, 715, -1, 746, 1685, 747, -1, 714, 1685, 746, -1, 716, 1686, 715, -1, 748, 1686, 716, -1, 747, 1686, 748, -1, 715, 1686, 747, -1, 717, 1687, 716, -1, 749, 1687, 717, -1, 748, 1687, 749, -1, 716, 1687, 748, -1, 718, 1688, 717, -1, 750, 1688, 718, -1, 749, 1688, 750, -1, 717, 1688, 749, -1, 719, 1689, 718, -1, 751, 1689, 719, -1, 750, 1689, 751, -1, 718, 1689, 750, -1, 720, 1690, 719, -1, 752, 1690, 720, -1, 751, 1690, 752, -1, 719, 1690, 751, -1, 721, 1691, 720, -1, 753, 1691, 721, -1, 752, 1691, 753, -1, 720, 1691, 752, -1, 722, 1692, 721, -1, 754, 1692, 722, -1, 753, 1692, 754, -1, 721, 1692, 753, -1, 723, 1693, 722, -1, 755, 1693, 723, -1, 754, 1693, 755, -1, 722, 1693, 754, -1, 724, 1694, 723, -1, 756, 1694, 724, -1, 755, 1694, 756, -1, 723, 1694, 755, -1, 725, 1695, 724, -1, 757, 1695, 725, -1, 756, 1695, 757, -1, 724, 1695, 756, -1, 726, 1696, 725, -1, 758, 1696, 726, -1, 757, 1696, 758, -1, 725, 1696, 757, -1, 727, 1697, 726, -1, 759, 1697, 727, -1, 758, 1697, 759, -1, 726, 1697, 758, -1, 728, 1698, 727, -1, 760, 1698, 728, -1, 759, 1698, 760, -1, 727, 1698, 759, -1, 729, 1699, 728, -1, 761, 1699, 729, -1, 760, 1699, 761, -1, 728, 1699, 760, -1, 730, 1700, 729, -1, 762, 1700, 730, -1, 761, 1700, 762, -1, 729, 1700, 761, -1, 731, 1701, 730, -1, 763, 1701, 731, -1, 762, 1701, 763, -1, 730, 1701, 762, -1, 732, 1702, 731, -1, 764, 1702, 732, -1, 763, 1702, 764, -1, 731, 1702, 763, -1, 733, 1703, 732, -1, 765, 1703, 733, -1, 764, 1703, 765, -1, 732, 1703, 764, -1, 734, 1704, 733, -1, 766, 1704, 734, -1, 765, 1704, 766, -1, 733, 1704, 765, -1, 735, 1705, 734, -1, 767, 1705, 735, -1, 766, 1705, 767, -1, 734, 1705, 766, -1, 737, 1706, 736, -1, 769, 1706, 737, -1, 768, 1706, 769, -1, 736, 1706, 768, -1, 738, 1707, 737, -1, 770, 1707, 738, -1, 769, 1707, 770, -1, 737, 1707, 769, -1, 739, 1708, 738, -1, 771, 1708, 739, -1, 770, 1708, 771, -1, 738, 1708, 770, -1, 740, 1709, 739, -1, 772, 1709, 740, -1, 771, 1709, 772, -1, 739, 1709, 771, -1, 741, 1710, 740, -1, 773, 1710, 741, -1, 772, 1710, 773, -1, 740, 1710, 772, -1, 742, 1711, 741, -1, 774, 1711, 742, -1, 773, 1711, 774, -1, 741, 1711, 773, -1, 743, 1712, 742, -1, 775, 1712, 743, -1, 774, 1712, 775, -1, 742, 1712, 774, -1, 744, 1713, 743, -1, 776, 1713, 744, -1, 775, 1713, 776, -1, 743, 1713, 775, -1, 745, 1714, 744, -1, 777, 1714, 745, -1, 776, 1714, 777, -1, 744, 1714, 776, -1, 746, 1715, 745, -1, 778, 1715, 746, -1, 777, 1715, 778, -1, 745, 1715, 777, -1, 747, 1716, 746, -1, 779, 1716, 747, -1, 778, 1716, 779, -1, 746, 1716, 778, -1, 748, 1717, 747, -1, 780, 1717, 748, -1, 779, 1717, 780, -1, 747, 1717, 779, -1, 749, 1718, 748, -1, 781, 1718, 749, -1, 780, 1718, 781, -1, 748, 1718, 780, -1, 750, 1719, 749, -1, 782, 1719, 750, -1, 781, 1719, 782, -1, 749, 1719, 781, -1, 751, 1720, 750, -1, 783, 1720, 751, -1, 782, 1720, 783, -1, 750, 1720, 782, -1, 752, 1721, 751, -1, 784, 1721, 752, -1, 783, 1721, 784, -1, 751, 1721, 783, -1, 753, 1722, 752, -1, 785, 1722, 753, -1, 784, 1722, 785, -1, 752, 1722, 784, -1, 754, 1723, 753, -1, 786, 1723, 754, -1, 785, 1723, 786, -1, 753, 1723, 785, -1, 755, 1724, 754, -1, 787, 1724, 755, -1, 786, 1724, 787, -1, 754, 1724, 786, -1, 756, 1725, 755, -1, 788, 1725, 756, -1, 787, 1725, 788, -1, 755, 1725, 787, -1, 757, 1726, 756, -1, 789, 1726, 757, -1, 788, 1726, 789, -1, 756, 1726, 788, -1, 758, 1727, 757, -1, 790, 1727, 758, -1, 789, 1727, 790, -1, 757, 1727, 789, -1, 759, 1728, 758, -1, 791, 1728, 759, -1, 790, 1728, 791, -1, 758, 1728, 790, -1, 760, 1729, 759, -1, 792, 1729, 760, -1, 791, 1729, 792, -1, 759, 1729, 791, -1, 761, 1730, 760, -1, 793, 1730, 761, -1, 792, 1730, 793, -1, 760, 1730, 792, -1, 762, 1731, 761, -1, 794, 1731, 762, -1, 793, 1731, 794, -1, 761, 1731, 793, -1, 763, 1732, 762, -1, 795, 1732, 763, -1, 794, 1732, 795, -1, 762, 1732, 794, -1, 764, 1733, 763, -1, 796, 1733, 764, -1, 795, 1733, 796, -1, 763, 1733, 795, -1, 765, 1734, 764, -1, 797, 1734, 765, -1, 796, 1734, 797, -1, 764, 1734, 796, -1, 766, 1735, 765, -1, 798, 1735, 766, -1, 797, 1735, 798, -1, 765, 1735, 797, -1, 767, 1736, 766, -1, 799, 1736, 767, -1, 798, 1736, 799, -1, 766, 1736, 798, -1, 769, 1737, 768, -1, 801, 1737, 769, -1, 800, 1737, 801, -1, 768, 1737, 800, -1, 770, 1738, 769, -1, 802, 1738, 770, -1, 801, 1738, 802, -1, 769, 1738, 801, -1, 771, 1739, 770, -1, 803, 1739, 771, -1, 802, 1739, 803, -1, 770, 1739, 802, -1, 772, 1740, 771, -1, 804, 1740, 772, -1, 803, 1740, 804, -1, 771, 1740, 803, -1, 773, 1741, 772, -1, 805, 1741, 773, -1, 804, 1741, 805, -1, 772, 1741, 804, -1, 774, 1742, 773, -1, 806, 1742, 774, -1, 805, 1742, 806, -1, 773, 1742, 805, -1, 775, 1743, 774, -1, 807, 1743, 775, -1, 806, 1743, 807, -1, 774, 1743, 806, -1, 776, 1744, 775, -1, 808, 1744, 776, -1, 807, 1744, 808, -1, 775, 1744, 807, -1, 777, 1745, 776, -1, 809, 1745, 777, -1, 808, 1745, 809, -1, 776, 1745, 808, -1, 778, 1746, 777, -1, 810, 1746, 778, -1, 809, 1746, 810, -1, 777, 1746, 809, -1, 779, 1747, 778, -1, 811, 1747, 779, -1, 810, 1747, 811, -1, 778, 1747, 810, -1, 780, 1748, 779, -1, 812, 1748, 780, -1, 811, 1748, 812, -1, 779, 1748, 811, -1, 781, 1749, 780, -1, 813, 1749, 781, -1, 812, 1749, 813, -1, 780, 1749, 812, -1, 782, 1750, 781, -1, 814, 1750, 782, -1, 813, 1750, 814, -1, 781, 1750, 813, -1, 783, 1751, 782, -1, 815, 1751, 783, -1, 814, 1751, 815, -1, 782, 1751, 814, -1, 784, 1752, 783, -1, 816, 1752, 784, -1, 815, 1752, 816, -1, 783, 1752, 815, -1, 785, 1753, 784, -1, 817, 1753, 785, -1, 816, 1753, 817, -1, 784, 1753, 816, -1, 786, 1754, 785, -1, 818, 1754, 786, -1, 817, 1754, 818, -1, 785, 1754, 817, -1, 787, 1755, 786, -1, 819, 1755, 787, -1, 818, 1755, 819, -1, 786, 1755, 818, -1, 788, 1756, 787, -1, 820, 1756, 788, -1, 819, 1756, 820, -1, 787, 1756, 819, -1, 789, 1757, 788, -1, 821, 1757, 789, -1, 820, 1757, 821, -1, 788, 1757, 820, -1, 790, 1758, 789, -1, 822, 1758, 790, -1, 821, 1758, 822, -1, 789, 1758, 821, -1, 791, 1759, 790, -1, 823, 1759, 791, -1, 822, 1759, 823, -1, 790, 1759, 822, -1, 792, 1760, 791, -1, 824, 1760, 792, -1, 823, 1760, 824, -1, 791, 1760, 823, -1, 793, 1761, 792, -1, 825, 1761, 793, -1, 824, 1761, 825, -1, 792, 1761, 824, -1, 794, 1762, 793, -1, 826, 1762, 794, -1, 825, 1762, 826, -1, 793, 1762, 825, -1, 795, 1763, 794, -1, 827, 1763, 795, -1, 826, 1763, 827, -1, 794, 1763, 826, -1, 796, 1764, 795, -1, 828, 1764, 796, -1, 827, 1764, 828, -1, 795, 1764, 827, -1, 797, 1765, 796, -1, 829, 1765, 797, -1, 828, 1765, 829, -1, 796, 1765, 828, -1, 798, 1766, 797, -1, 830, 1766, 798, -1, 829, 1766, 830, -1, 797, 1766, 829, -1, 799, 1767, 798, -1, 831, 1767, 799, -1, 830, 1767, 831, -1, 798, 1767, 830, -1, 801, 1768, 800, -1, 833, 1768, 801, -1, 832, 1768, 833, -1, 800, 1768, 832, -1, 802, 1769, 801, -1, 834, 1769, 802, -1, 833, 1769, 834, -1, 801, 1769, 833, -1, 803, 1770, 802, -1, 835, 1770, 803, -1, 834, 1770, 835, -1, 802, 1770, 834, -1, 804, 1771, 803, -1, 836, 1771, 804, -1, 835, 1771, 836, -1, 803, 1771, 835, -1, 805, 1772, 804, -1, 837, 1772, 805, -1, 836, 1772, 837, -1, 804, 1772, 836, -1, 806, 1773, 805, -1, 838, 1773, 806, -1, 837, 1773, 838, -1, 805, 1773, 837, -1, 807, 1774, 806, -1, 839, 1774, 807, -1, 838, 1774, 839, -1, 806, 1774, 838, -1, 808, 1775, 807, -1, 840, 1775, 808, -1, 839, 1775, 840, -1, 807, 1775, 839, -1, 809, 1776, 808, -1, 841, 1776, 809, -1, 840, 1776, 841, -1, 808, 1776, 840, -1, 810, 1777, 809, -1, 842, 1777, 810, -1, 841, 1777, 842, -1, 809, 1777, 841, -1, 811, 1778, 810, -1, 843, 1778, 811, -1, 842, 1778, 843, -1, 810, 1778, 842, -1, 812, 1779, 811, -1, 844, 1779, 812, -1, 843, 1779, 844, -1, 811, 1779, 843, -1, 813, 1780, 812, -1, 845, 1780, 813, -1, 844, 1780, 845, -1, 812, 1780, 844, -1, 814, 1781, 813, -1, 846, 1781, 814, -1, 845, 1781, 846, -1, 813, 1781, 845, -1, 815, 1782, 814, -1, 847, 1782, 815, -1, 846, 1782, 847, -1, 814, 1782, 846, -1, 816, 1783, 815, -1, 848, 1783, 816, -1, 847, 1783, 848, -1, 815, 1783, 847, -1, 817, 1784, 816, -1, 849, 1784, 817, -1, 848, 1784, 849, -1, 816, 1784, 848, -1, 818, 1785, 817, -1, 850, 1785, 818, -1, 849, 1785, 850, -1, 817, 1785, 849, -1, 819, 1786, 818, -1, 851, 1786, 819, -1, 850, 1786, 851, -1, 818, 1786, 850, -1, 820, 1787, 819, -1, 852, 1787, 820, -1, 851, 1787, 852, -1, 819, 1787, 851, -1, 821, 1788, 820, -1, 853, 1788, 821, -1, 852, 1788, 853, -1, 820, 1788, 852, -1, 822, 1789, 821, -1, 854, 1789, 822, -1, 853, 1789, 854, -1, 821, 1789, 853, -1, 823, 1790, 822, -1, 855, 1790, 823, -1, 854, 1790, 855, -1, 822, 1790, 854, -1, 824, 1791, 823, -1, 856, 1791, 824, -1, 855, 1791, 856, -1, 823, 1791, 855, -1, 825, 1792, 824, -1, 857, 1792, 825, -1, 856, 1792, 857, -1, 824, 1792, 856, -1, 826, 1793, 825, -1, 858, 1793, 826, -1, 857, 1793, 858, -1, 825, 1793, 857, -1, 827, 1794, 826, -1, 859, 1794, 827, -1, 858, 1794, 859, -1, 826, 1794, 858, -1, 828, 1795, 827, -1, 860, 1795, 828, -1, 859, 1795, 860, -1, 827, 1795, 859, -1, 829, 1796, 828, -1, 861, 1796, 829, -1, 860, 1796, 861, -1, 828, 1796, 860, -1, 830, 1797, 829, -1, 862, 1797, 830, -1, 861, 1797, 862, -1, 829, 1797, 861, -1, 831, 1798, 830, -1, 863, 1798, 831, -1, 862, 1798, 863, -1, 830, 1798, 862, -1, 833, 1799, 832, -1, 865, 1799, 833, -1, 864, 1799, 865, -1, 832, 1799, 864, -1, 834, 1800, 833, -1, 866, 1800, 834, -1, 865, 1800, 866, -1, 833, 1800, 865, -1, 835, 1801, 834, -1, 867, 1801, 835, -1, 866, 1801, 867, -1, 834, 1801, 866, -1, 836, 1802, 835, -1, 868, 1802, 836, -1, 867, 1802, 868, -1, 835, 1802, 867, -1, 837, 1803, 836, -1, 869, 1803, 837, -1, 868, 1803, 869, -1, 836, 1803, 868, -1, 838, 1804, 837, -1, 870, 1804, 838, -1, 869, 1804, 870, -1, 837, 1804, 869, -1, 839, 1805, 838, -1, 871, 1805, 839, -1, 870, 1805, 871, -1, 838, 1805, 870, -1, 840, 1806, 839, -1, 872, 1806, 840, -1, 871, 1806, 872, -1, 839, 1806, 871, -1, 841, 1807, 840, -1, 873, 1807, 841, -1, 872, 1807, 873, -1, 840, 1807, 872, -1, 842, 1808, 841, -1, 874, 1808, 842, -1, 873, 1808, 874, -1, 841, 1808, 873, -1, 843, 1809, 842, -1, 875, 1809, 843, -1, 874, 1809, 875, -1, 842, 1809, 874, -1, 844, 1810, 843, -1, 876, 1810, 844, -1, 875, 1810, 876, -1, 843, 1810, 875, -1, 845, 1811, 844, -1, 877, 1811, 845, -1, 876, 1811, 877, -1, 844, 1811, 876, -1, 846, 1812, 845, -1, 878, 1812, 846, -1, 877, 1812, 878, -1, 845, 1812, 877, -1, 847, 1813, 846, -1, 879, 1813, 847, -1, 878, 1813, 879, -1, 846, 1813, 878, -1, 848, 1814, 847, -1, 880, 1814, 848, -1, 879, 1814, 880, -1, 847, 1814, 879, -1, 849, 1815, 848, -1, 881, 1815, 849, -1, 880, 1815, 881, -1, 848, 1815, 880, -1, 850, 1816, 849, -1, 882, 1816, 850, -1, 881, 1816, 882, -1, 849, 1816, 881, -1, 851, 1817, 850, -1, 883, 1817, 851, -1, 882, 1817, 883, -1, 850, 1817, 882, -1, 852, 1818, 851, -1, 884, 1818, 852, -1, 883, 1818, 884, -1, 851, 1818, 883, -1, 853, 1819, 852, -1, 885, 1819, 853, -1, 884, 1819, 885, -1, 852, 1819, 884, -1, 854, 1820, 853, -1, 886, 1820, 854, -1, 885, 1820, 886, -1, 853, 1820, 885, -1, 855, 1821, 854, -1, 887, 1821, 855, -1, 886, 1821, 887, -1, 854, 1821, 886, -1, 856, 1822, 855, -1, 888, 1822, 856, -1, 887, 1822, 888, -1, 855, 1822, 887, -1, 857, 1823, 856, -1, 889, 1823, 857, -1, 888, 1823, 889, -1, 856, 1823, 888, -1, 858, 1824, 857, -1, 890, 1824, 858, -1, 889, 1824, 890, -1, 857, 1824, 889, -1, 859, 1825, 858, -1, 891, 1825, 859, -1, 890, 1825, 891, -1, 858, 1825, 890, -1, 860, 1826, 859, -1, 892, 1826, 860, -1, 891, 1826, 892, -1, 859, 1826, 891, -1, 861, 1827, 860, -1, 893, 1827, 861, -1, 892, 1827, 893, -1, 860, 1827, 892, -1, 862, 1828, 861, -1, 894, 1828, 862, -1, 893, 1828, 894, -1, 861, 1828, 893, -1, 863, 1829, 862, -1, 895, 1829, 863, -1, 894, 1829, 895, -1, 862, 1829, 894, -1, 865, 1830, 864, -1, 897, 1830, 865, -1, 896, 1830, 897, -1, 864, 1830, 896, -1, 866, 1831, 865, -1, 898, 1831, 866, -1, 897, 1831, 898, -1, 865, 1831, 897, -1, 867, 1832, 866, -1, 899, 1832, 867, -1, 898, 1832, 899, -1, 866, 1832, 898, -1, 868, 1833, 867, -1, 900, 1833, 868, -1, 899, 1833, 900, -1, 867, 1833, 899, -1, 869, 1834, 868, -1, 901, 1834, 869, -1, 900, 1834, 901, -1, 868, 1834, 900, -1, 870, 1835, 869, -1, 902, 1835, 870, -1, 901, 1835, 902, -1, 869, 1835, 901, -1, 871, 1836, 870, -1, 903, 1836, 871, -1, 902, 1836, 903, -1, 870, 1836, 902, -1, 872, 1837, 871, -1, 904, 1837, 872, -1, 903, 1837, 904, -1, 871, 1837, 903, -1, 873, 1838, 872, -1, 905, 1838, 873, -1, 904, 1838, 905, -1, 872, 1838, 904, -1, 874, 1839, 873, -1, 906, 1839, 874, -1, 905, 1839, 906, -1, 873, 1839, 905, -1, 875, 1840, 874, -1, 907, 1840, 875, -1, 906, 1840, 907, -1, 874, 1840, 906, -1, 876, 1841, 875, -1, 908, 1841, 876, -1, 907, 1841, 908, -1, 875, 1841, 907, -1, 877, 1842, 876, -1, 909, 1842, 877, -1, 908, 1842, 909, -1, 876, 1842, 908, -1, 878, 1843, 877, -1, 910, 1843, 878, -1, 909, 1843, 910, -1, 877, 1843, 909, -1, 879, 1844, 878, -1, 911, 1844, 879, -1, 910, 1844, 911, -1, 878, 1844, 910, -1, 880, 1845, 879, -1, 912, 1845, 880, -1, 911, 1845, 912, -1, 879, 1845, 911, -1, 881, 1846, 880, -1, 913, 1846, 881, -1, 912, 1846, 913, -1, 880, 1846, 912, -1, 882, 1847, 881, -1, 914, 1847, 882, -1, 913, 1847, 914, -1, 881, 1847, 913, -1, 883, 1848, 882, -1, 915, 1848, 883, -1, 914, 1848, 915, -1, 882, 1848, 914, -1, 884, 1849, 883, -1, 916, 1849, 884, -1, 915, 1849, 916, -1, 883, 1849, 915, -1, 885, 1850, 884, -1, 917, 1850, 885, -1, 916, 1850, 917, -1, 884, 1850, 916, -1, 886, 1851, 885, -1, 918, 1851, 886, -1, 917, 1851, 918, -1, 885, 1851, 917, -1, 887, 1852, 886, -1, 919, 1852, 887, -1, 918, 1852, 919, -1, 886, 1852, 918, -1, 888, 1853, 887, -1, 920, 1853, 888, -1, 919, 1853, 920, -1, 887, 1853, 919, -1, 889, 1854, 888, -1, 921, 1854, 889, -1, 920, 1854, 921, -1, 888, 1854, 920, -1, 890, 1855, 889, -1, 922, 1855, 890, -1, 921, 1855, 922, -1, 889, 1855, 921, -1, 891, 1856, 890, -1, 923, 1856, 891, -1, 922, 1856, 923, -1, 890, 1856, 922, -1, 892, 1857, 891, -1, 924, 1857, 892, -1, 923, 1857, 924, -1, 891, 1857, 923, -1, 893, 1858, 892, -1, 925, 1858, 893, -1, 924, 1858, 925, -1, 892, 1858, 924, -1, 894, 1859, 893, -1, 926, 1859, 894, -1, 925, 1859, 926, -1, 893, 1859, 925, -1, 895, 1860, 894, -1, 927, 1860, 895, -1, 926, 1860, 927, -1, 894, 1860, 926, -1, 897, 1861, 896, -1, 929, 1861, 897, -1, 928, 1861, 929, -1, 896, 1861, 928, -1, 898, 1862, 897, -1, 930, 1862, 898, -1, 929, 1862, 930, -1, 897, 1862, 929, -1, 899, 1863, 898, -1, 931, 1863, 899, -1, 930, 1863, 931, -1, 898, 1863, 930, -1, 900, 1864, 899, -1, 932, 1864, 900, -1, 931, 1864, 932, -1, 899, 1864, 931, -1, 901, 1865, 900, -1, 933, 1865, 901, -1, 932, 1865, 933, -1, 900, 1865, 932, -1, 902, 1866, 901, -1, 934, 1866, 902, -1, 933, 1866, 934, -1, 901, 1866, 933, -1, 903, 1867, 902, -1, 935, 1867, 903, -1, 934, 1867, 935, -1, 902, 1867, 934, -1, 904, 1868, 903, -1, 936, 1868, 904, -1, 935, 1868, 936, -1, 903, 1868, 935, -1, 905, 1869, 904, -1, 937, 1869, 905, -1, 936, 1869, 937, -1, 904, 1869, 936, -1, 906, 1870, 905, -1, 938, 1870, 906, -1, 937, 1870, 938, -1, 905, 1870, 937, -1, 907, 1871, 906, -1, 939, 1871, 907, -1, 938, 1871, 939, -1, 906, 1871, 938, -1, 908, 1872, 907, -1, 940, 1872, 908, -1, 939, 1872, 940, -1, 907, 1872, 939, -1, 909, 1873, 908, -1, 941, 1873, 909, -1, 940, 1873, 941, -1, 908, 1873, 940, -1, 910, 1874, 909, -1, 942, 1874, 910, -1, 941, 1874, 942, -1, 909, 1874, 941, -1, 911, 1875, 910, -1, 943, 1875, 911, -1, 942, 1875, 943, -1, 910, 1875, 942, -1, 912, 1876, 911, -1, 944, 1876, 912, -1, 943, 1876, 944, -1, 911, 1876, 943, -1, 913, 1877, 912, -1, 945, 1877, 913, -1, 944, 1877, 945, -1, 912, 1877, 944, -1, 914, 1878, 913, -1, 946, 1878, 914, -1, 945, 1878, 946, -1, 913, 1878, 945, -1, 915, 1879, 914, -1, 947, 1879, 915, -1, 946, 1879, 947, -1, 914, 1879, 946, -1, 916, 1880, 915, -1, 948, 1880, 916, -1, 947, 1880, 948, -1, 915, 1880, 947, -1, 917, 1881, 916, -1, 949, 1881, 917, -1, 948, 1881, 949, -1, 916, 1881, 948, -1, 918, 1882, 917, -1, 950, 1882, 918, -1, 949, 1882, 950, -1, 917, 1882, 949, -1, 919, 1883, 918, -1, 951, 1883, 919, -1, 950, 1883, 951, -1, 918, 1883, 950, -1, 920, 1884, 919, -1, 952, 1884, 920, -1, 951, 1884, 952, -1, 919, 1884, 951, -1, 921, 1885, 920, -1, 953, 1885, 921, -1, 952, 1885, 953, -1, 920, 1885, 952, -1, 922, 1886, 921, -1, 954, 1886, 922, -1, 953, 1886, 954, -1, 921, 1886, 953, -1, 923, 1887, 922, -1, 955, 1887, 923, -1, 954, 1887, 955, -1, 922, 1887, 954, -1, 924, 1888, 923, -1, 956, 1888, 924, -1, 955, 1888, 956, -1, 923, 1888, 955, -1, 925, 1889, 924, -1, 957, 1889, 925, -1, 956, 1889, 957, -1, 924, 1889, 956, -1, 926, 1890, 925, -1, 958, 1890, 926, -1, 957, 1890, 958, -1, 925, 1890, 957, -1, 927, 1891, 926, -1, 959, 1891, 927, -1, 958, 1891, 959, -1, 926, 1891, 958, -1, 929, 1892, 928, -1, 961, 1892, 929, -1, 960, 1892, 961, -1, 928, 1892, 960, -1, 930, 1893, 929, -1, 962, 1893, 930, -1, 961, 1893, 962, -1, 929, 1893, 961, -1, 931, 1894, 930, -1, 963, 1894, 931, -1, 962, 1894, 963, -1, 930, 1894, 962, -1, 932, 1895, 931, -1, 964, 1895, 932, -1, 963, 1895, 964, -1, 931, 1895, 963, -1, 933, 1896, 932, -1, 965, 1896, 933, -1, 964, 1896, 965, -1, 932, 1896, 964, -1, 934, 1897, 933, -1, 966, 1897, 934, -1, 965, 1897, 966, -1, 933, 1897, 965, -1, 935, 1898, 934, -1, 967, 1898, 935, -1, 966, 1898, 967, -1, 934, 1898, 966, -1, 936, 1899, 935, -1, 968, 1899, 936, -1, 967, 1899, 968, -1, 935, 1899, 967, -1, 937, 1900, 936, -1, 969, 1900, 937, -1, 968, 1900, 969, -1, 936, 1900, 968, -1, 938, 1901, 937, -1, 970, 1901, 938, -1, 969, 1901, 970, -1, 937, 1901, 969, -1, 939, 1902, 938, -1, 971, 1902, 939, -1, 970, 1902, 971, -1, 938, 1902, 970, -1, 940, 1903, 939, -1, 972, 1903, 940, -1, 971, 1903, 972, -1, 939, 1903, 971, -1, 941, 1904, 940, -1, 973, 1904, 941, -1, 972, 1904, 973, -1, 940, 1904, 972, -1, 942, 1905, 941, -1, 974, 1905, 942, -1, 973, 1905, 974, -1, 941, 1905, 973, -1, 943, 1906, 942, -1, 975, 1906, 943, -1, 974, 1906, 975, -1, 942, 1906, 974, -1, 944, 1907, 943, -1, 976, 1907, 944, -1, 975, 1907, 976, -1, 943, 1907, 975, -1, 945, 1908, 944, -1, 977, 1908, 945, -1, 976, 1908, 977, -1, 944, 1908, 976, -1, 946, 1909, 945, -1, 978, 1909, 946, -1, 977, 1909, 978, -1, 945, 1909, 977, -1, 947, 1910, 946, -1, 979, 1910, 947, -1, 978, 1910, 979, -1, 946, 1910, 978, -1, 948, 1911, 947, -1, 980, 1911, 948, -1, 979, 1911, 980, -1, 947, 1911, 979, -1, 949, 1912, 948, -1, 981, 1912, 949, -1, 980, 1912, 981, -1, 948, 1912, 980, -1, 950, 1913, 949, -1, 982, 1913, 950, -1, 981, 1913, 982, -1, 949, 1913, 981, -1, 951, 1914, 950, -1, 983, 1914, 951, -1, 982, 1914, 983, -1, 950, 1914, 982, -1, 952, 1915, 951, -1, 984, 1915, 952, -1, 983, 1915, 984, -1, 951, 1915, 983, -1, 953, 1916, 952, -1, 985, 1916, 953, -1, 984, 1916, 985, -1, 952, 1916, 984, -1, 954, 1917, 953, -1, 986, 1917, 954, -1, 985, 1917, 986, -1, 953, 1917, 985, -1, 955, 1918, 954, -1, 987, 1918, 955, -1, 986, 1918, 987, -1, 954, 1918, 986, -1, 956, 1919, 955, -1, 988, 1919, 956, -1, 987, 1919, 988, -1, 955, 1919, 987, -1, 957, 1920, 956, -1, 989, 1920, 957, -1, 988, 1920, 989, -1, 956, 1920, 988, -1, 958, 1921, 957, -1, 990, 1921, 958, -1, 989, 1921, 990, -1, 957, 1921, 989, -1, 959, 1922, 958, -1, 991, 1922, 959, -1, 990, 1922, 991, -1, 958, 1922, 990, -1, 960, 961, 992, -1, 961, 962, 993, -1, 962, 963, 994, -1, 963, 964, 995, -1, 964, 965, 996, -1, 965, 966, 997, -1, 966, 967, 998, -1, 967, 968, 999, -1, 968, 969, 1000, -1, 969, 970, 1001, -1, 970, 971, 1002, -1, 971, 972, 1003, -1, 972, 973, 1004, -1, 973, 974, 1005, -1, 974, 975, 1006, -1, 975, 976, 1007, -1, 976, 977, 1008, -1, 977, 978, 1009, -1, 978, 979, 1010, -1, 979, 980, 1011, -1, 980, 981, 1012, -1, 981, 982, 1013, -1, 982, 983, 1014, -1, 983, 984, 1015, -1, 984, 985, 1016, -1, 985, 986, 1017, -1, 986, 987, 1018, -1, 987, 988, 1019, -1, 988, 989, 1020, -1, 989, 990, 1021, -1, 990, 991, 1022, -1 };
    NurbsSurface1.coordIndex = m_coordIndex;
    NurbsSurface1.coordIndex_length = sizeof(m_coordIndex) / sizeof(int);
    }
    NurbsSurface1.creaseAngle = 1.570000;
    {
    static int m_normalIndex[] = { 1, 33, 32, -1, 2, 34, 33, -1, 3, 35, 34, -1, 4, 36, 35, -1, 5, 37, 36, -1, 6, 38, 37, -1, 7, 39, 38, -1, 8, 40, 39, -1, 9, 41, 40, -1, 10, 42, 41, -1, 11, 43, 42, -1, 12, 44, 43, -1, 13, 45, 44, -1, 14, 46, 45, -1, 15, 47, 46, -1, 16, 48, 47, -1, 17, 49, 48, -1, 18, 50, 49, -1, 19, 51, 50, -1, 20, 52, 51, -1, 21, 53, 52, -1, 22, 54, 53, -1, 23, 55, 54, -1, 24, 56, 55, -1, 25, 57, 56, -1, 26, 58, 57, -1, 27, 59, 58, -1, 28, 60, 59, -1, 29, 61, 60, -1, 30, 62, 61, -1, 31, 63, 62, -1, 33, 1024, 32, -1, 65, 1024, 33, -1, 64, 1024, 65, -1, 32, 1024, 64, -1, 34, 1025, 33, -1, 66, 1025, 34, -1, 65, 1025, 66, -1, 33, 1025, 65, -1, 35, 1026, 34, -1, 67, 1026, 35, -1, 66, 1026, 67, -1, 34, 1026, 66, -1, 36, 1027, 35, -1, 68, 1027, 36, -1, 67, 1027, 68, -1, 35, 1027, 67, -1, 37, 1028, 36, -1, 69, 1028, 37, -1, 68, 1028, 69, -1, 36, 1028, 68, -1, 38, 1029, 37, -1, 70, 1029, 38, -1, 69, 1029, 70, -1, 37, 1029, 69, -1, 39, 1030, 38, -1, 71, 1030, 39, -1, 70, 1030, 71, -1, 38, 1030, 70, -1, 40, 1031, 39, -1, 72, 1031, 40, -1, 71, 1031, 72, -1, 39, 1031, 71, -1, 41, 1032, 40, -1, 73, 1032, 41, -1, 72, 1032, 73, -1, 40, 1032, 72, -1, 42, 1033, 41, -1, 74, 1033, 42, -1, 73, 1033, 74, -1, 41, 1033, 73, -1, 43, 1034, 42, -1, 75, 1034, 43, -1, 74, 1034, 75, -1, 42, 1034, 74, -1, 44, 1035, 43, -1, 76, 1035, 44, -1, 75, 1035, 76, -1, 43, 1035, 75, -1, 45, 1036, 44, -1, 77, 1036, 45, -1, 76, 1036, 77, -1, 44, 1036, 76, -1, 46, 1037, 45, -1, 78, 1037, 46, -1, 77, 1037, 78, -1, 45, 1037, 77, -1, 47, 1038, 46, -1, 79, 1038, 47, -1, 78, 1038, 79, -1, 46, 1038, 78, -1, 48, 1039, 47, -1, 80, 1039, 48, -1, 79, 1039, 80, -1, 47, 1039, 79, -1, 49, 1040, 48, -1, 81, 1040, 49, -1, 80, 1040, 81, -1, 48, 1040, 80, -1, 50, 1041, 49, -1, 82, 1041, 50, -1, 81, 1041, 82, -1, 49, 1041, 81, -1, 51, 1042, 50, -1, 83, 1042, 51, -1, 82, 1042, 83, -1, 50, 1042, 82, -1, 52, 1043, 51, -1, 84, 1043, 52, -1, 83, 1043, 84, -1, 51, 1043, 83, -1, 53, 1044, 52, -1, 85, 1044, 53, -1, 84, 1044, 85, -1, 52, 1044, 84, -1, 54, 1045, 53, -1, 86, 1045, 54, -1, 85, 1045, 86, -1, 53, 1045, 85, -1, 55, 1046, 54, -1, 87, 1046, 55, -1, 86, 1046, 87, -1, 54, 1046, 86, -1, 56, 1047, 55, -1, 88, 1047, 56, -1, 87, 1047, 88, -1, 55, 1047, 87, -1, 57, 1048, 56, -1, 89, 1048, 57, -1, 88, 1048, 89, -1, 56, 1048, 88, -1, 58, 1049, 57, -1, 90, 1049, 58, -1, 89, 1049, 90, -1, 57, 1049, 89, -1, 59, 1050, 58, -1, 91, 1050, 59, -1, 90, 1050, 91, -1, 58, 1050, 90, -1, 60, 1051, 59, -1, 92, 1051, 60, -1, 91, 1051, 92, -1, 59, 1051, 91, -1, 61, 1052, 60, -1, 93, 1052, 61, -1, 92, 1052, 93, -1, 60, 1052, 92, -1, 62, 1053, 61, -1, 94, 1053, 62, -1, 93, 1053, 94, -1, 61, 1053, 93, -1, 63, 1054, 62, -1, 95, 1054, 63, -1, 94, 1054, 95, -1, 62, 1054, 94, -1, 65, 1055, 64, -1, 97, 1055, 65, -1, 96, 1055, 97, -1, 64, 1055, 96, -1, 66, 1056, 65, -1, 98, 1056, 66, -1, 97, 1056, 98, -1, 65, 1056, 97, -1, 67, 1057, 66, -1, 99, 1057, 67, -1, 98, 1057, 99, -1, 66, 1057, 98, -1, 68, 1058, 67, -1, 100, 1058, 68, -1, 99, 1058, 100, -1, 67, 1058, 99, -1, 69, 1059, 68, -1, 101, 1059, 69, -1, 100, 1059, 101, -1, 68, 1059, 100, -1, 70, 1060, 69, -1, 102, 1060, 70, -1, 101, 1060, 102, -1, 69, 1060, 101, -1, 71, 1061, 70, -1, 103, 1061, 71, -1, 102, 1061, 103, -1, 70, 1061, 102, -1, 72, 1062, 71, -1, 104, 1062, 72, -1, 103, 1062, 104, -1, 71, 1062, 103, -1, 73, 1063, 72, -1, 105, 1063, 73, -1, 104, 1063, 105, -1, 72, 1063, 104, -1, 74, 1064, 73, -1, 106, 1064, 74, -1, 105, 1064, 106, -1, 73, 1064, 105, -1, 75, 1065, 74, -1, 107, 1065, 75, -1, 106, 1065, 107, -1, 74, 1065, 106, -1, 76, 1066, 75, -1, 108, 1066, 76, -1, 107, 1066, 108, -1, 75, 1066, 107, -1, 77, 1067, 76, -1, 109, 1067, 77, -1, 108, 1067, 109, -1, 76, 1067, 108, -1, 78, 1068, 77, -1, 110, 1068, 78, -1, 109, 1068, 110, -1, 77, 1068, 109, -1, 79, 1069, 78, -1, 111, 1069, 79, -1, 110, 1069, 111, -1, 78, 1069, 110, -1, 80, 1070, 79, -1, 112, 1070, 80, -1, 111, 1070, 112, -1, 79, 1070, 111, -1, 81, 1071, 80, -1, 113, 1071, 81, -1, 112, 1071, 113, -1, 80, 1071, 112, -1, 82, 1072, 81, -1, 114, 1072, 82, -1, 113, 1072, 114, -1, 81, 1072, 113, -1, 83, 1073, 82, -1, 115, 1073, 83, -1, 114, 1073, 115, -1, 82, 1073, 114, -1, 84, 1074, 83, -1, 116, 1074, 84, -1, 115, 1074, 116, -1, 83, 1074, 115, -1, 85, 1075, 84, -1, 117, 1075, 85, -1, 116, 1075, 117, -1, 84, 1075, 116, -1, 86, 1076, 85, -1, 118, 1076, 86, -1, 117, 1076, 118, -1, 85, 1076, 117, -1, 87, 1077, 86, -1, 119, 1077, 87, -1, 118, 1077, 119, -1, 86, 1077, 118, -1, 88, 1078, 87, -1, 120, 1078, 88, -1, 119, 1078, 120, -1, 87, 1078, 119, -1, 89, 1079, 88, -1, 121, 1079, 89, -1, 120, 1079, 121, -1, 88, 1079, 120, -1, 90, 1080, 89, -1, 122, 1080, 90, -1, 121, 1080, 122, -1, 89, 1080, 121, -1, 91, 1081, 90, -1, 123, 1081, 91, -1, 122, 1081, 123, -1, 90, 1081, 122, -1, 92, 1082, 91, -1, 124, 1082, 92, -1, 123, 1082, 124, -1, 91, 1082, 123, -1, 93, 1083, 92, -1, 125, 1083, 93, -1, 124, 1083, 125, -1, 92, 1083, 124, -1, 94, 1084, 93, -1, 126, 1084, 94, -1, 125, 1084, 126, -1, 93, 1084, 125, -1, 95, 1085, 94, -1, 127, 1085, 95, -1, 126, 1085, 127, -1, 94, 1085, 126, -1, 97, 1086, 96, -1, 129, 1086, 97, -1, 128, 1086, 129, -1, 96, 1086, 128, -1, 98, 1087, 97, -1, 130, 1087, 98, -1, 129, 1087, 130, -1, 97, 1087, 129, -1, 99, 1088, 98, -1, 131, 1088, 99, -1, 130, 1088, 131, -1, 98, 1088, 130, -1, 100, 1089, 99, -1, 132, 1089, 100, -1, 131, 1089, 132, -1, 99, 1089, 131, -1, 101, 1090, 100, -1, 133, 1090, 101, -1, 132, 1090, 133, -1, 100, 1090, 132, -1, 102, 1091, 101, -1, 134, 1091, 102, -1, 133, 1091, 134, -1, 101, 1091, 133, -1, 103, 1092, 102, -1, 135, 1092, 103, -1, 134, 1092, 135, -1, 102, 1092, 134, -1, 104, 1093, 103, -1, 136, 1093, 104, -1, 135, 1093, 136, -1, 103, 1093, 135, -1, 105, 1094, 104, -1, 137, 1094, 105, -1, 136, 1094, 137, -1, 104, 1094, 136, -1, 106, 1095, 105, -1, 138, 1095, 106, -1, 137, 1095, 138, -1, 105, 1095, 137, -1, 107, 1096, 106, -1, 139, 1096, 107, -1, 138, 1096, 139, -1, 106, 1096, 138, -1, 108, 1097, 107, -1, 140, 1097, 108, -1, 139, 1097, 140, -1, 107, 1097, 139, -1, 109, 1098, 108, -1, 141, 1098, 109, -1, 140, 1098, 141, -1, 108, 1098, 140, -1, 110, 1099, 109, -1, 142, 1099, 110, -1, 141, 1099, 142, -1, 109, 1099, 141, -1, 111, 1100, 110, -1, 143, 1100, 111, -1, 142, 1100, 143, -1, 110, 1100, 142, -1, 112, 1101, 111, -1, 144, 1101, 112, -1, 143, 1101, 144, -1, 111, 1101, 143, -1, 113, 1102, 112, -1, 145, 1102, 113, -1, 144, 1102, 145, -1, 112, 1102, 144, -1, 114, 1103, 113, -1, 146, 1103, 114, -1, 145, 1103, 146, -1, 113, 1103, 145, -1, 115, 1104, 114, -1, 147, 1104, 115, -1, 146, 1104, 147, -1, 114, 1104, 146, -1, 116, 1105, 115, -1, 148, 1105, 116, -1, 147, 1105, 148, -1, 115, 1105, 147, -1, 117, 1106, 116, -1, 149, 1106, 117, -1, 148, 1106, 149, -1, 116, 1106, 148, -1, 118, 1107, 117, -1, 150, 1107, 118, -1, 149, 1107, 150, -1, 117, 1107, 149, -1, 119, 1108, 118, -1, 151, 1108, 119, -1, 150, 1108, 151, -1, 118, 1108, 150, -1, 120, 1109, 119, -1, 152, 1109, 120, -1, 151, 1109, 152, -1, 119, 1109, 151, -1, 121, 1110, 120, -1, 153, 1110, 121, -1, 152, 1110, 153, -1, 120, 1110, 152, -1, 122, 1111, 121, -1, 154, 1111, 122, -1, 153, 1111, 154, -1, 121, 1111, 153, -1, 123, 1112, 122, -1, 155, 1112, 123, -1, 154, 1112, 155, -1, 122, 1112, 154, -1, 124, 1113, 123, -1, 156, 1113, 124, -1, 155, 1113, 156, -1, 123, 1113, 155, -1, 125, 1114, 124, -1, 157, 1114, 125, -1, 156, 1114, 157, -1, 124, 1114, 156, -1, 126, 1115, 125, -1, 158, 1115, 126, -1, 157, 1115, 158, -1, 125, 1115, 157, -1, 127, 1116, 126, -1, 159, 1116, 127, -1, 158, 1116, 159, -1, 126, 1116, 158, -1, 129, 1117, 128, -1, 161, 1117, 129, -1, 160, 1117, 161, -1, 128, 1117, 160, -1, 130, 1118, 129, -1, 162, 1118, 130, -1, 161, 1118, 162, -1, 129, 1118, 161, -1, 131, 1119, 130, -1, 163, 1119, 131, -1, 162, 1119, 163, -1, 130, 1119, 162, -1, 132, 1120, 131, -1, 164, 1120, 132, -1, 163, 1120, 164, -1, 131, 1120, 163, -1, 133, 1121, 132, -1, 165, 1121, 133, -1, 164, 1121, 165, -1, 132, 1121, 164, -1, 134, 1122, 133, -1, 166, 1122, 134, -1, 165, 1122, 166, -1, 133, 1122, 165, -1, 135, 1123, 134, -1, 167, 1123, 135, -1, 166, 1123, 167, -1, 134, 1123, 166, -1, 136, 1124, 135, -1, 168, 1124, 136, -1, 167, 1124, 168, -1, 135, 1124, 167, -1, 137, 1125, 136, -1, 169, 1125, 137, -1, 168, 1125, 169, -1, 136, 1125, 168, -1, 138, 1126, 137, -1, 170, 1126, 138, -1, 169, 1126, 170, -1, 137, 1126, 169, -1, 139, 1127, 138, -1, 171, 1127, 139, -1, 170, 1127, 171, -1, 138, 1127, 170, -1, 140, 1128, 139, -1, 172, 1128, 140, -1, 171, 1128, 172, -1, 139, 1128, 171, -1, 141, 1129, 140, -1, 173, 1129, 141, -1, 172, 1129, 173, -1, 140, 1129, 172, -1, 142, 1130, 141, -1, 174, 1130, 142, -1, 173, 1130, 174, -1, 141, 1130, 173, -1, 143, 1131, 142, -1, 175, 1131, 143, -1, 174, 1131, 175, -1, 142, 1131, 174, -1, 144, 1132, 143, -1, 176, 1132, 144, -1, 175, 1132, 176, -1, 143, 1132, 175, -1, 145, 1133, 144, -1, 177, 1133, 145, -1, 176, 1133, 177, -1, 144, 1133, 176, -1, 146, 1134, 145, -1, 178, 1134, 146, -1, 177, 1134, 178, -1, 145, 1134, 177, -1, 147, 1135, 146, -1, 179, 1135, 147, -1, 178, 1135, 179, -1, 146, 1135, 178, -1, 148, 1136, 147, -1, 180, 1136, 148, -1, 179, 1136, 180, -1, 147, 1136, 179, -1, 149, 1137, 148, -1, 181, 1137, 149, -1, 180, 1137, 181, -1, 148, 1137, 180, -1, 150, 1138, 149, -1, 182, 1138, 150, -1, 181, 1138, 182, -1, 149, 1138, 181, -1, 151, 1139, 150, -1, 183, 1139, 151, -1, 182, 1139, 183, -1, 150, 1139, 182, -1, 152, 1140, 151, -1, 184, 1140, 152, -1, 183, 1140, 184, -1, 151, 1140, 183, -1, 153, 1141, 152, -1, 185, 1141, 153, -1, 184, 1141, 185, -1, 152, 1141, 184, -1, 154, 1142, 153, -1, 186, 1142, 154, -1, 185, 1142, 186, -1, 153, 1142, 185, -1, 155, 1143, 154, -1, 187, 1143, 155, -1, 186, 1143, 187, -1, 154, 1143, 186, -1, 156, 1144, 155, -1, 188, 1144, 156, -1, 187, 1144, 188, -1, 155, 1144, 187, -1, 157, 1145, 156, -1, 189, 1145, 157, -1, 188, 1145, 189, -1, 156, 1145, 188, -1, 158, 1146, 157, -1, 190, 1146, 158, -1, 189, 1146, 190, -1, 157, 1146, 189, -1, 159, 1147, 158, -1, 191, 1147, 159, -1, 190, 1147, 191, -1, 158, 1147, 190, -1, 161, 1148, 160, -1, 193, 1148, 161, -1, 192, 1148, 193, -1, 160, 1148, 192, -1, 162, 1149, 161, -1, 194, 1149, 162, -1, 193, 1149, 194, -1, 161, 1149, 193, -1, 163, 1150, 162, -1, 195, 1150, 163, -1, 194, 1150, 195, -1, 162, 1150, 194, -1, 164, 1151, 163, -1, 196, 1151, 164, -1, 195, 1151, 196, -1, 163, 1151, 195, -1, 165, 1152, 164, -1, 197, 1152, 165, -1, 196, 1152, 197, -1, 164, 1152, 196, -1, 166, 1153, 165, -1, 198, 1153, 166, -1, 197, 1153, 198, -1, 165, 1153, 197, -1, 167, 1154, 166, -1, 199, 1154, 167, -1, 198, 1154, 199, -1, 166, 1154, 198, -1, 168, 1155, 167, -1, 200, 1155, 168, -1, 199, 1155, 200, -1, 167, 1155, 199, -1, 169, 1156, 168, -1, 201, 1156, 169, -1, 200, 1156, 201, -1, 168, 1156, 200, -1, 170, 1157, 169, -1, 202, 1157, 170, -1, 201, 1157, 202, -1, 169, 1157, 201, -1, 171, 1158, 170, -1, 203, 1158, 171, -1, 202, 1158, 203, -1, 170, 1158, 202, -1, 172, 1159, 171, -1, 204, 1159, 172, -1, 203, 1159, 204, -1, 171, 1159, 203, -1, 173, 1160, 172, -1, 205, 1160, 173, -1, 204, 1160, 205, -1, 172, 1160, 204, -1, 174, 1161, 173, -1, 206, 1161, 174, -1, 205, 1161, 206, -1, 173, 1161, 205, -1, 175, 1162, 174, -1, 207, 1162, 175, -1, 206, 1162, 207, -1, 174, 1162, 206, -1, 176, 1163, 175, -1, 208, 1163, 176, -1, 207, 1163, 208, -1, 175, 1163, 207, -1, 177, 1164, 176, -1, 209, 1164, 177, -1, 208, 1164, 209, -1, 176, 1164, 208, -1, 178, 1165, 177, -1, 210, 1165, 178, -1, 209, 1165, 210, -1, 177, 1165, 209, -1, 179, 1166, 178, -1, 211, 1166, 179, -1, 210, 1166, 211, -1, 178, 1166, 210, -1, 180, 1167, 179, -1, 212, 1167, 180, -1, 211, 1167, 212, -1, 179, 1167, 211, -1, 181, 1168, 180, -1, 213, 1168, 181, -1, 212, 1168, 213, -1, 180, 1168, 212, -1, 182, 1169, 181, -1, 214, 1169, 182, -1, 213, 1169, 214, -1, 181, 1169, 213, -1, 183, 1170, 182, -1, 215, 1170, 183, -1, 214, 1170, 215, -1, 182, 1170, 214, -1, 184, 1171, 183, -1, 216, 1171, 184, -1, 215, 1171, 216, -1, 183, 1171, 215, -1, 185, 1172, 184, -1, 217, 1172, 185, -1, 216, 1172, 217, -1, 184, 1172, 216, -1, 186, 1173, 185, -1, 218, 1173, 186, -1, 217, 1173, 218, -1, 185, 1173, 217, -1, 187, 1174, 186, -1, 219, 1174, 187, -1, 218, 1174, 219, -1, 186, 1174, 218, -1, 188, 1175, 187, -1, 220, 1175, 188, -1, 219, 1175, 220, -1, 187, 1175, 219, -1, 189, 1176, 188, -1, 221, 1176, 189, -1, 220, 1176, 221, -1, 188, 1176, 220, -1, 190, 1177, 189, -1, 222, 1177, 190, -1, 221, 1177, 222, -1, 189, 1177, 221, -1, 191, 1178, 190, -1, 223, 1178, 191, -1, 222, 1178, 223, -1, 190, 1178, 222, -1, 193, 1179, 192, -1, 225, 1179, 193, -1, 224, 1179, 225, -1, 192, 1179, 224, -1, 194, 1180, 193, -1, 226, 1180, 194, -1, 225, 1180, 226, -1, 193, 1180, 225, -1, 195, 1181, 194, -1, 227, 1181, 195, -1, 226, 1181, 227, -1, 194, 1181, 226, -1, 196, 1182, 195, -1, 228, 1182, 196, -1, 227, 1182, 228, -1, 195, 1182, 227, -1, 197, 1183, 196, -1, 229, 1183, 197, -1, 228, 1183, 229, -1, 196, 1183, 228, -1, 198, 1184, 197, -1, 230, 1184, 198, -1, 229, 1184, 230, -1, 197, 1184, 229, -1, 199, 1185, 198, -1, 231, 1185, 199, -1, 230, 1185, 231, -1, 198, 1185, 230, -1, 200, 1186, 199, -1, 232, 1186, 200, -1, 231, 1186, 232, -1, 199, 1186, 231, -1, 201, 1187, 200, -1, 233, 1187, 201, -1, 232, 1187, 233, -1, 200, 1187, 232, -1, 202, 1188, 201, -1, 234, 1188, 202, -1, 233, 1188, 234, -1, 201, 1188, 233, -1, 203, 1189, 202, -1, 235, 1189, 203, -1, 234, 1189, 235, -1, 202, 1189, 234, -1, 204, 1190, 203, -1, 236, 1190, 204, -1, 235, 1190, 236, -1, 203, 1190, 235, -1, 205, 1191, 204, -1, 237, 1191, 205, -1, 236, 1191, 237, -1, 204, 1191, 236, -1, 206, 1192, 205, -1, 238, 1192, 206, -1, 237, 1192, 238, -1, 205, 1192, 237, -1, 207, 1193, 206, -1, 239, 1193, 207, -1, 238, 1193, 239, -1, 206, 1193, 238, -1, 208, 1194, 207, -1, 240, 1194, 208, -1, 239, 1194, 240, -1, 207, 1194, 239, -1, 209, 1195, 208, -1, 241, 1195, 209, -1, 240, 1195, 241, -1, 208, 1195, 240, -1, 210, 1196, 209, -1, 242, 1196, 210, -1, 241, 1196, 242, -1, 209, 1196, 241, -1, 211, 1197, 210, -1, 243, 1197, 211, -1, 242, 1197, 243, -1, 210, 1197, 242, -1, 212, 1198, 211, -1, 244, 1198, 212, -1, 243, 1198, 244, -1, 211, 1198, 243, -1, 213, 1199, 212, -1, 245, 1199, 213, -1, 244, 1199, 245, -1, 212, 1199, 244, -1, 214, 1200, 213, -1, 246, 1200, 214, -1, 245, 1200, 246, -1, 213, 1200, 245, -1, 215, 1201, 214, -1, 247, 1201, 215, -1, 246, 1201, 247, -1, 214, 1201, 246, -1, 216, 1202, 215, -1, 248, 1202, 216, -1, 247, 1202, 248, -1, 215, 1202, 247, -1, 217, 1203, 216, -1, 249, 1203, 217, -1, 248, 1203, 249, -1, 216, 1203, 248, -1, 218, 1204, 217, -1, 250, 1204, 218, -1, 249, 1204, 250, -1, 217, 1204, 249, -1, 219, 1205, 218, -1, 251, 1205, 219, -1, 250, 1205, 251, -1, 218, 1205, 250, -1, 220, 1206, 219, -1, 252, 1206, 220, -1, 251, 1206, 252, -1, 219, 1206, 251, -1, 221, 1207, 220, -1, 253, 1207, 221, -1, 252, 1207, 253, -1, 220, 1207, 252, -1, 222, 1208, 221, -1, 254, 1208, 222, -1, 253, 1208, 254, -1, 221, 1208, 253, -1, 223, 1209, 222, -1, 255, 1209, 223, -1, 254, 1209, 255, -1, 222, 1209, 254, -1, 225, 1210, 224, -1, 257, 1210, 225, -1, 256, 1210, 257, -1, 224, 1210, 256, -1, 226, 1211, 225, -1, 258, 1211, 226, -1, 257, 1211, 258, -1, 225, 1211, 257, -1, 227, 1212, 226, -1, 259, 1212, 227, -1, 258, 1212, 259, -1, 226, 1212, 258, -1, 228, 1213, 227, -1, 260, 1213, 228, -1, 259, 1213, 260, -1, 227, 1213, 259, -1, 229, 1214, 228, -1, 261, 1214, 229, -1, 260, 1214, 261, -1, 228, 1214, 260, -1, 230, 1215, 229, -1, 262, 1215, 230, -1, 261, 1215, 262, -1, 229, 1215, 261, -1, 231, 1216, 230, -1, 263, 1216, 231, -1, 262, 1216, 263, -1, 230, 1216, 262, -1, 232, 1217, 231, -1, 264, 1217, 232, -1, 263, 1217, 264, -1, 231, 1217, 263, -1, 233, 1218, 232, -1, 265, 1218, 233, -1, 264, 1218, 265, -1, 232, 1218, 264, -1, 234, 1219, 233, -1, 266, 1219, 234, -1, 265, 1219, 266, -1, 233, 1219, 265, -1, 235, 1220, 234, -1, 267, 1220, 235, -1, 266, 1220, 267, -1, 234, 1220, 266, -1, 236, 1221, 235, -1, 268, 1221, 236, -1, 267, 1221, 268, -1, 235, 1221, 267, -1, 237, 1222, 236, -1, 269, 1222, 237, -1, 268, 1222, 269, -1, 236, 1222, 268, -1, 238, 1223, 237, -1, 270, 1223, 238, -1, 269, 1223, 270, -1, 237, 1223, 269, -1, 239, 1224, 238, -1, 271, 1224, 239, -1, 270, 1224, 271, -1, 238, 1224, 270, -1, 240, 1225, 239, -1, 272, 1225, 240, -1, 271, 1225, 272, -1, 239, 1225, 271, -1, 241, 1226, 240, -1, 273, 1226, 241, -1, 272, 1226, 273, -1, 240, 1226, 272, -1, 242, 1227, 241, -1, 274, 1227, 242, -1, 273, 1227, 274, -1, 241, 1227, 273, -1, 243, 1228, 242, -1, 275, 1228, 243, -1, 274, 1228, 275, -1, 242, 1228, 274, -1, 244, 1229, 243, -1, 276, 1229, 244, -1, 275, 1229, 276, -1, 243, 1229, 275, -1, 245, 1230, 244, -1, 277, 1230, 245, -1, 276, 1230, 277, -1, 244, 1230, 276, -1, 246, 1231, 245, -1, 278, 1231, 246, -1, 277, 1231, 278, -1, 245, 1231, 277, -1, 247, 1232, 246, -1, 279, 1232, 247, -1, 278, 1232, 279, -1, 246, 1232, 278, -1, 248, 1233, 247, -1, 280, 1233, 248, -1, 279, 1233, 280, -1, 247, 1233, 279, -1, 249, 1234, 248, -1, 281, 1234, 249, -1, 280, 1234, 281, -1, 248, 1234, 280, -1, 250, 1235, 249, -1, 282, 1235, 250, -1, 281, 1235, 282, -1, 249, 1235, 281, -1, 251, 1236, 250, -1, 283, 1236, 251, -1, 282, 1236, 283, -1, 250, 1236, 282, -1, 252, 1237, 251, -1, 284, 1237, 252, -1, 283, 1237, 284, -1, 251, 1237, 283, -1, 253, 1238, 252, -1, 285, 1238, 253, -1, 284, 1238, 285, -1, 252, 1238, 284, -1, 254, 1239, 253, -1, 286, 1239, 254, -1, 285, 1239, 286, -1, 253, 1239, 285, -1, 255, 1240, 254, -1, 287, 1240, 255, -1, 286, 1240, 287, -1, 254, 1240, 286, -1, 257, 1241, 256, -1, 289, 1241, 257, -1, 288, 1241, 289, -1, 256, 1241, 288, -1, 258, 1242, 257, -1, 290, 1242, 258, -1, 289, 1242, 290, -1, 257, 1242, 289, -1, 259, 1243, 258, -1, 291, 1243, 259, -1, 290, 1243, 291, -1, 258, 1243, 290, -1, 260, 1244, 259, -1, 292, 1244, 260, -1, 291, 1244, 292, -1, 259, 1244, 291, -1, 261, 1245, 260, -1, 293, 1245, 261, -1, 292, 1245, 293, -1, 260, 1245, 292, -1, 262, 1246, 261, -1, 294, 1246, 262, -1, 293, 1246, 294, -1, 261, 1246, 293, -1, 263, 1247, 262, -1, 295, 1247, 263, -1, 294, 1247, 295, -1, 262, 1247, 294, -1, 264, 1248, 263, -1, 296, 1248, 264, -1, 295, 1248, 296, -1, 263, 1248, 295, -1, 265, 1249, 264, -1, 297, 1249, 265, -1, 296, 1249, 297, -1, 264, 1249, 296, -1, 266, 1250, 265, -1, 298, 1250, 266, -1, 297, 1250, 298, -1, 265, 1250, 297, -1, 267, 1251, 266, -1, 299, 1251, 267, -1, 298, 1251, 299, -1, 266, 1251, 298, -1, 268, 1252, 267, -1, 300, 1252, 268, -1, 299, 1252, 300, -1, 267, 1252, 299, -1, 269, 1253, 268, -1, 301, 1253, 269, -1, 300, 1253, 301, -1, 268, 1253, 300, -1, 270, 1254, 269, -1, 302, 1254, 270, -1, 301, 1254, 302, -1, 269, 1254, 301, -1, 271, 1255, 270, -1, 303, 1255, 271, -1, 302, 1255, 303, -1, 270, 1255, 302, -1, 272, 1256, 271, -1, 304, 1256, 272, -1, 303, 1256, 304, -1, 271, 1256, 303, -1, 273, 1257, 272, -1, 305, 1257, 273, -1, 304, 1257, 305, -1, 272, 1257, 304, -1, 274, 1258, 273, -1, 306, 1258, 274, -1, 305, 1258, 306, -1, 273, 1258, 305, -1, 275, 1259, 274, -1, 307, 1259, 275, -1, 306, 1259, 307, -1, 274, 1259, 306, -1, 276, 1260, 275, -1, 308, 1260, 276, -1, 307, 1260, 308, -1, 275, 1260, 307, -1, 277, 1261, 276, -1, 309, 1261, 277, -1, 308, 1261, 309, -1, 276, 1261, 308, -1, 278, 1262, 277, -1, 310, 1262, 278, -1, 309, 1262, 310, -1, 277, 1262, 309, -1, 279, 1263, 278, -1, 311, 1263, 279, -1, 310, 1263, 311, -1, 278, 1263, 310, -1, 280, 1264, 279, -1, 312, 1264, 280, -1, 311, 1264, 312, -1, 279, 1264, 311, -1, 281, 1265, 280, -1, 313, 1265, 281, -1, 312, 1265, 313, -1, 280, 1265, 312, -1, 282, 1266, 281, -1, 314, 1266, 282, -1, 313, 1266, 314, -1, 281, 1266, 313, -1, 283, 1267, 282, -1, 315, 1267, 283, -1, 314, 1267, 315, -1, 282, 1267, 314, -1, 284, 1268, 283, -1, 316, 1268, 284, -1, 315, 1268, 316, -1, 283, 1268, 315, -1, 285, 1269, 284, -1, 317, 1269, 285, -1, 316, 1269, 317, -1, 284, 1269, 316, -1, 286, 1270, 285, -1, 318, 1270, 286, -1, 317, 1270, 318, -1, 285, 1270, 317, -1, 287, 1271, 286, -1, 319, 1271, 287, -1, 318, 1271, 319, -1, 286, 1271, 318, -1, 289, 1272, 288, -1, 321, 1272, 289, -1, 320, 1272, 321, -1, 288, 1272, 320, -1, 290, 1273, 289, -1, 322, 1273, 290, -1, 321, 1273, 322, -1, 289, 1273, 321, -1, 291, 1274, 290, -1, 323, 1274, 291, -1, 322, 1274, 323, -1, 290, 1274, 322, -1, 292, 1275, 291, -1, 324, 1275, 292, -1, 323, 1275, 324, -1, 291, 1275, 323, -1, 293, 1276, 292, -1, 325, 1276, 293, -1, 324, 1276, 325, -1, 292, 1276, 324, -1, 294, 1277, 293, -1, 326, 1277, 294, -1, 325, 1277, 326, -1, 293, 1277, 325, -1, 295, 1278, 294, -1, 327, 1278, 295, -1, 326, 1278, 327, -1, 294, 1278, 326, -1, 296, 1279, 295, -1, 328, 1279, 296, -1, 327, 1279, 328, -1, 295, 1279, 327, -1, 297, 1280, 296, -1, 329, 1280, 297, -1, 328, 1280, 329, -1, 296, 1280, 328, -1, 298, 1281, 297, -1, 330, 1281, 298, -1, 329, 1281, 330, -1, 297, 1281, 329, -1, 299, 1282, 298, -1, 331, 1282, 299, -1, 330, 1282, 331, -1, 298, 1282, 330, -1, 300, 1283, 299, -1, 332, 1283, 300, -1, 331, 1283, 332, -1, 299, 1283, 331, -1, 301, 1284, 300, -1, 333, 1284, 301, -1, 332, 1284, 333, -1, 300, 1284, 332, -1, 302, 1285, 301, -1, 334, 1285, 302, -1, 333, 1285, 334, -1, 301, 1285, 333, -1, 303, 1286, 302, -1, 335, 1286, 303, -1, 334, 1286, 335, -1, 302, 1286, 334, -1, 304, 1287, 303, -1, 336, 1287, 304, -1, 335, 1287, 336, -1, 303, 1287, 335, -1, 305, 1288, 304, -1, 337, 1288, 305, -1, 336, 1288, 337, -1, 304, 1288, 336, -1, 306, 1289, 305, -1, 338, 1289, 306, -1, 337, 1289, 338, -1, 305, 1289, 337, -1, 307, 1290, 306, -1, 339, 1290, 307, -1, 338, 1290, 339, -1, 306, 1290, 338, -1, 308, 1291, 307, -1, 340, 1291, 308, -1, 339, 1291, 340, -1, 307, 1291, 339, -1, 309, 1292, 308, -1, 341, 1292, 309, -1, 340, 1292, 341, -1, 308, 1292, 340, -1, 310, 1293, 309, -1, 342, 1293, 310, -1, 341, 1293, 342, -1, 309, 1293, 341, -1, 311, 1294, 310, -1, 343, 1294, 311, -1, 342, 1294, 343, -1, 310, 1294, 342, -1, 312, 1295, 311, -1, 344, 1295, 312, -1, 343, 1295, 344, -1, 311, 1295, 343, -1, 313, 1296, 312, -1, 345, 1296, 313, -1, 344, 1296, 345, -1, 312, 1296, 344, -1, 314, 1297, 313, -1, 346, 1297, 314, -1, 345, 1297, 346, -1, 313, 1297, 345, -1, 315, 1298, 314, -1, 347, 1298, 315, -1, 346, 1298, 347, -1, 314, 1298, 346, -1, 316, 1299, 315, -1, 348, 1299, 316, -1, 347, 1299, 348, -1, 315, 1299, 347, -1, 317, 1300, 316, -1, 349, 1300, 317, -1, 348, 1300, 349, -1, 316, 1300, 348, -1, 318, 1301, 317, -1, 350, 1301, 318, -1, 349, 1301, 350, -1, 317, 1301, 349, -1, 319, 1302, 318, -1, 351, 1302, 319, -1, 350, 1302, 351, -1, 318, 1302, 350, -1, 321, 1303, 320, -1, 353, 1303, 321, -1, 352, 1303, 353, -1, 320, 1303, 352, -1, 322, 1304, 321, -1, 354, 1304, 322, -1, 353, 1304, 354, -1, 321, 1304, 353, -1, 323, 1305, 322, -1, 355, 1305, 323, -1, 354, 1305, 355, -1, 322, 1305, 354, -1, 324, 1306, 323, -1, 356, 1306, 324, -1, 355, 1306, 356, -1, 323, 1306, 355, -1, 325, 1307, 324, -1, 357, 1307, 325, -1, 356, 1307, 357, -1, 324, 1307, 356, -1, 326, 1308, 325, -1, 358, 1308, 326, -1, 357, 1308, 358, -1, 325, 1308, 357, -1, 327, 1309, 326, -1, 359, 1309, 327, -1, 358, 1309, 359, -1, 326, 1309, 358, -1, 328, 1310, 327, -1, 360, 1310, 328, -1, 359, 1310, 360, -1, 327, 1310, 359, -1, 329, 1311, 328, -1, 361, 1311, 329, -1, 360, 1311, 361, -1, 328, 1311, 360, -1, 330, 1312, 329, -1, 362, 1312, 330, -1, 361, 1312, 362, -1, 329, 1312, 361, -1, 331, 1313, 330, -1, 363, 1313, 331, -1, 362, 1313, 363, -1, 330, 1313, 362, -1, 332, 1314, 331, -1, 364, 1314, 332, -1, 363, 1314, 364, -1, 331, 1314, 363, -1, 333, 1315, 332, -1, 365, 1315, 333, -1, 364, 1315, 365, -1, 332, 1315, 364, -1, 334, 1316, 333, -1, 366, 1316, 334, -1, 365, 1316, 366, -1, 333, 1316, 365, -1, 335, 1317, 334, -1, 367, 1317, 335, -1, 366, 1317, 367, -1, 334, 1317, 366, -1, 336, 1318, 335, -1, 368, 1318, 336, -1, 367, 1318, 368, -1, 335, 1318, 367, -1, 337, 1319, 336, -1, 369, 1319, 337, -1, 368, 1319, 369, -1, 336, 1319, 368, -1, 338, 1320, 337, -1, 370, 1320, 338, -1, 369, 1320, 370, -1, 337, 1320, 369, -1, 339, 1321, 338, -1, 371, 1321, 339, -1, 370, 1321, 371, -1, 338, 1321, 370, -1, 340, 1322, 339, -1, 372, 1322, 340, -1, 371, 1322, 372, -1, 339, 1322, 371, -1, 341, 1323, 340, -1, 373, 1323, 341, -1, 372, 1323, 373, -1, 340, 1323, 372, -1, 342, 1324, 341, -1, 374, 1324, 342, -1, 373, 1324, 374, -1, 341, 1324, 373, -1, 343, 1325, 342, -1, 375, 1325, 343, -1, 374, 1325, 375, -1, 342, 1325, 374, -1, 344, 1326, 343, -1, 376, 1326, 344, -1, 375, 1326, 376, -1, 343, 1326, 375, -1, 345, 1327, 344, -1, 377, 1327, 345, -1, 376, 1327, 377, -1, 344, 1327, 376, -1, 346, 1328, 345, -1, 378, 1328, 346, -1, 377, 1328, 378, -1, 345, 1328, 377, -1, 347, 1329, 346, -1, 379, 1329, 347, -1, 378, 1329, 379, -1, 346, 1329, 378, -1, 348, 1330, 347, -1, 380, 1330, 348, -1, 379, 1330, 380, -1, 347, 1330, 379, -1, 349, 1331, 348, -1, 381, 1331, 349, -1, 380, 1331, 381, -1, 348, 1331, 380, -1, 350, 1332, 349, -1, 382, 1332, 350, -1, 381, 1332, 382, -1, 349, 1332, 381, -1, 351, 1333, 350, -1, 383, 1333, 351, -1, 382, 1333, 383, -1, 350, 1333, 382, -1, 353, 1334, 352, -1, 385, 1334, 353, -1, 384, 1334, 385, -1, 352, 1334, 384, -1, 354, 1335, 353, -1, 386, 1335, 354, -1, 385, 1335, 386, -1, 353, 1335, 385, -1, 355, 1336, 354, -1, 387, 1336, 355, -1, 386, 1336, 387, -1, 354, 1336, 386, -1, 356, 1337, 355, -1, 388, 1337, 356, -1, 387, 1337, 388, -1, 355, 1337, 387, -1, 357, 1338, 356, -1, 389, 1338, 357, -1, 388, 1338, 389, -1, 356, 1338, 388, -1, 358, 1339, 357, -1, 390, 1339, 358, -1, 389, 1339, 390, -1, 357, 1339, 389, -1, 359, 1340, 358, -1, 391, 1340, 359, -1, 390, 1340, 391, -1, 358, 1340, 390, -1, 360, 1341, 359, -1, 392, 1341, 360, -1, 391, 1341, 392, -1, 359, 1341, 391, -1, 361, 1342, 360, -1, 393, 1342, 361, -1, 392, 1342, 393, -1, 360, 1342, 392, -1, 362, 1343, 361, -1, 394, 1343, 362, -1, 393, 1343, 394, -1, 361, 1343, 393, -1, 363, 1344, 362, -1, 395, 1344, 363, -1, 394, 1344, 395, -1, 362, 1344, 394, -1, 364, 1345, 363, -1, 396, 1345, 364, -1, 395, 1345, 396, -1, 363, 1345, 395, -1, 365, 1346, 364, -1, 397, 1346, 365, -1, 396, 1346, 397, -1, 364, 1346, 396, -1, 366, 1347, 365, -1, 398, 1347, 366, -1, 397, 1347, 398, -1, 365, 1347, 397, -1, 367, 1348, 366, -1, 399, 1348, 367, -1, 398, 1348, 399, -1, 366, 1348, 398, -1, 368, 1349, 367, -1, 400, 1349, 368, -1, 399, 1349, 400, -1, 367, 1349, 399, -1, 369, 1350, 368, -1, 401, 1350, 369, -1, 400, 1350, 401, -1, 368, 1350, 400, -1, 370, 1351, 369, -1, 402, 1351, 370, -1, 401, 1351, 402, -1, 369, 1351, 401, -1, 371, 1352, 370, -1, 403, 1352, 371, -1, 402, 1352, 403, -1, 370, 1352, 402, -1, 372, 1353, 371, -1, 404, 1353, 372, -1, 403, 1353, 404, -1, 371, 1353, 403, -1, 373, 1354, 372, -1, 405, 1354, 373, -1, 404, 1354, 405, -1, 372, 1354, 404, -1, 374, 1355, 373, -1, 406, 1355, 374, -1, 405, 1355, 406, -1, 373, 1355, 405, -1, 375, 1356, 374, -1, 407, 1356, 375, -1, 406, 1356, 407, -1, 374, 1356, 406, -1, 376, 1357, 375, -1, 408, 1357, 376, -1, 407, 1357, 408, -1, 375, 1357, 407, -1, 377, 1358, 376, -1, 409, 1358, 377, -1, 408, 1358, 409, -1, 376, 1358, 408, -1, 378, 1359, 377, -1, 410, 1359, 378, -1, 409, 1359, 410, -1, 377, 1359, 409, -1, 379, 1360, 378, -1, 411, 1360, 379, -1, 410, 1360, 411, -1, 378, 1360, 410, -1, 380, 1361, 379, -1, 412, 1361, 380, -1, 411, 1361, 412, -1, 379, 1361, 411, -1, 381, 1362, 380, -1, 413, 1362, 381, -1, 412, 1362, 413, -1, 380, 1362, 412, -1, 382, 1363, 381, -1, 414, 1363, 382, -1, 413, 1363, 414, -1, 381, 1363, 413, -1, 383, 1364, 382, -1, 415, 1364, 383, -1, 414, 1364, 415, -1, 382, 1364, 414, -1, 385, 1365, 384, -1, 417, 1365, 385, -1, 416, 1365, 417, -1, 384, 1365, 416, -1, 386, 1366, 385, -1, 418, 1366, 386, -1, 417, 1366, 418, -1, 385, 1366, 417, -1, 387, 1367, 386, -1, 419, 1367, 387, -1, 418, 1367, 419, -1, 386, 1367, 418, -1, 388, 1368, 387, -1, 420, 1368, 388, -1, 419, 1368, 420, -1, 387, 1368, 419, -1, 389, 1369, 388, -1, 421, 1369, 389, -1, 420, 1369, 421, -1, 388, 1369, 420, -1, 390, 1370, 389, -1, 422, 1370, 390, -1, 421, 1370, 422, -1, 389, 1370, 421, -1, 391, 1371, 390, -1, 423, 1371, 391, -1, 422, 1371, 423, -1, 390, 1371, 422, -1, 392, 1372, 391, -1, 424, 1372, 392, -1, 423, 1372, 424, -1, 391, 1372, 423, -1, 393, 1373, 392, -1, 425, 1373, 393, -1, 424, 1373, 425, -1, 392, 1373, 424, -1, 394, 1374, 393, -1, 426, 1374, 394, -1, 425, 1374, 426, -1, 393, 1374, 425, -1, 395, 1375, 394, -1, 427, 1375, 395, -1, 426, 1375, 427, -1, 394, 1375, 426, -1, 396, 1376, 395, -1, 428, 1376, 396, -1, 427, 1376, 428, -1, 395, 1376, 427, -1, 397, 1377, 396, -1, 429, 1377, 397, -1, 428, 1377, 429, -1, 396, 1377, 428, -1, 398, 1378, 397, -1, 430, 1378, 398, -1, 429, 1378, 430, -1, 397, 1378, 429, -1, 399, 1379, 398, -1, 431, 1379, 399, -1, 430, 1379, 431, -1, 398, 1379, 430, -1, 400, 1380, 399, -1, 432, 1380, 400, -1, 431, 1380, 432, -1, 399, 1380, 431, -1, 401, 1381, 400, -1, 433, 1381, 401, -1, 432, 1381, 433, -1, 400, 1381, 432, -1, 402, 1382, 401, -1, 434, 1382, 402, -1, 433, 1382, 434, -1, 401, 1382, 433, -1, 403, 1383, 402, -1, 435, 1383, 403, -1, 434, 1383, 435, -1, 402, 1383, 434, -1, 404, 1384, 403, -1, 436, 1384, 404, -1, 435, 1384, 436, -1, 403, 1384, 435, -1, 405, 1385, 404, -1, 437, 1385, 405, -1, 436, 1385, 437, -1, 404, 1385, 436, -1, 406, 1386, 405, -1, 438, 1386, 406, -1, 437, 1386, 438, -1, 405, 1386, 437, -1, 407, 1387, 406, -1, 439, 1387, 407, -1, 438, 1387, 439, -1, 406, 1387, 438, -1, 408, 1388, 407, -1, 440, 1388, 408, -1, 439, 1388, 440, -1, 407, 1388, 439, -1, 409, 1389, 408, -1, 441, 1389, 409, -1, 440, 1389, 441, -1, 408, 1389, 440, -1, 410, 1390, 409, -1, 442, 1390, 410, -1, 441, 1390, 442, -1, 409, 1390, 441, -1, 411, 1391, 410, -1, 443, 1391, 411, -1, 442, 1391, 443, -1, 410, 1391, 442, -1, 412, 1392, 411, -1, 444, 1392, 412, -1, 443, 1392, 444, -1, 411, 1392, 443, -1, 413, 1393, 412, -1, 445, 1393, 413, -1, 444, 1393, 445, -1, 412, 1393, 444, -1, 414, 1394, 413, -1, 446, 1394, 414, -1, 445, 1394, 446, -1, 413, 1394, 445, -1, 415, 1395, 414, -1, 447, 1395, 415, -1, 446, 1395, 447, -1, 414, 1395, 446, -1, 417, 1396, 416, -1, 449, 1396, 417, -1, 448, 1396, 449, -1, 416, 1396, 448, -1, 418, 1397, 417, -1, 450, 1397, 418, -1, 449, 1397, 450, -1, 417, 1397, 449, -1, 419, 1398, 418, -1, 451, 1398, 419, -1, 450, 1398, 451, -1, 418, 1398, 450, -1, 420, 1399, 419, -1, 452, 1399, 420, -1, 451, 1399, 452, -1, 419, 1399, 451, -1, 421, 1400, 420, -1, 453, 1400, 421, -1, 452, 1400, 453, -1, 420, 1400, 452, -1, 422, 1401, 421, -1, 454, 1401, 422, -1, 453, 1401, 454, -1, 421, 1401, 453, -1, 423, 1402, 422, -1, 455, 1402, 423, -1, 454, 1402, 455, -1, 422, 1402, 454, -1, 424, 1403, 423, -1, 456, 1403, 424, -1, 455, 1403, 456, -1, 423, 1403, 455, -1, 425, 1404, 424, -1, 457, 1404, 425, -1, 456, 1404, 457, -1, 424, 1404, 456, -1, 426, 1405, 425, -1, 458, 1405, 426, -1, 457, 1405, 458, -1, 425, 1405, 457, -1, 427, 1406, 426, -1, 459, 1406, 427, -1, 458, 1406, 459, -1, 426, 1406, 458, -1, 428, 1407, 427, -1, 460, 1407, 428, -1, 459, 1407, 460, -1, 427, 1407, 459, -1, 429, 1408, 428, -1, 461, 1408, 429, -1, 460, 1408, 461, -1, 428, 1408, 460, -1, 430, 1409, 429, -1, 462, 1409, 430, -1, 461, 1409, 462, -1, 429, 1409, 461, -1, 431, 1410, 430, -1, 463, 1410, 431, -1, 462, 1410, 463, -1, 430, 1410, 462, -1, 432, 1411, 431, -1, 464, 1411, 432, -1, 463, 1411, 464, -1, 431, 1411, 463, -1, 433, 1412, 432, -1, 465, 1412, 433, -1, 464, 1412, 465, -1, 432, 1412, 464, -1, 434, 1413, 433, -1, 466, 1413, 434, -1, 465, 1413, 466, -1, 433, 1413, 465, -1, 435, 1414, 434, -1, 467, 1414, 435, -1, 466, 1414, 467, -1, 434, 1414, 466, -1, 436, 1415, 435, -1, 468, 1415, 436, -1, 467, 1415, 468, -1, 435, 1415, 467, -1, 437, 1416, 436, -1, 469, 1416, 437, -1, 468, 1416, 469, -1, 436, 1416, 468, -1, 438, 1417, 437, -1, 470, 1417, 438, -1, 469, 1417, 470, -1, 437, 1417, 469, -1, 439, 1418, 438, -1, 471, 1418, 439, -1, 470, 1418, 471, -1, 438, 1418, 470, -1, 440, 1419, 439, -1, 472, 1419, 440, -1, 471, 1419, 472, -1, 439, 1419, 471, -1, 441, 1420, 440, -1, 473, 1420, 441, -1, 472, 1420, 473, -1, 440, 1420, 472, -1, 442, 1421, 441, -1, 474, 1421, 442, -1, 473, 1421, 474, -1, 441, 1421, 473, -1, 443, 1422, 442, -1, 475, 1422, 443, -1, 474, 1422, 475, -1, 442, 1422, 474, -1, 444, 1423, 443, -1, 476, 1423, 444, -1, 475, 1423, 476, -1, 443, 1423, 475, -1, 445, 1424, 444, -1, 477, 1424, 445, -1, 476, 1424, 477, -1, 444, 1424, 476, -1, 446, 1425, 445, -1, 478, 1425, 446, -1, 477, 1425, 478, -1, 445, 1425, 477, -1, 447, 1426, 446, -1, 479, 1426, 447, -1, 478, 1426, 479, -1, 446, 1426, 478, -1, 449, 1427, 448, -1, 481, 1427, 449, -1, 480, 1427, 481, -1, 448, 1427, 480, -1, 450, 1428, 449, -1, 482, 1428, 450, -1, 481, 1428, 482, -1, 449, 1428, 481, -1, 451, 1429, 450, -1, 483, 1429, 451, -1, 482, 1429, 483, -1, 450, 1429, 482, -1, 452, 1430, 451, -1, 484, 1430, 452, -1, 483, 1430, 484, -1, 451, 1430, 483, -1, 453, 1431, 452, -1, 485, 1431, 453, -1, 484, 1431, 485, -1, 452, 1431, 484, -1, 454, 1432, 453, -1, 486, 1432, 454, -1, 485, 1432, 486, -1, 453, 1432, 485, -1, 455, 1433, 454, -1, 487, 1433, 455, -1, 486, 1433, 487, -1, 454, 1433, 486, -1, 456, 1434, 455, -1, 488, 1434, 456, -1, 487, 1434, 488, -1, 455, 1434, 487, -1, 457, 1435, 456, -1, 489, 1435, 457, -1, 488, 1435, 489, -1, 456, 1435, 488, -1, 458, 1436, 457, -1, 490, 1436, 458, -1, 489, 1436, 490, -1, 457, 1436, 489, -1, 459, 1437, 458, -1, 491, 1437, 459, -1, 490, 1437, 491, -1, 458, 1437, 490, -1, 460, 1438, 459, -1, 492, 1438, 460, -1, 491, 1438, 492, -1, 459, 1438, 491, -1, 461, 1439, 460, -1, 493, 1439, 461, -1, 492, 1439, 493, -1, 460, 1439, 492, -1, 462, 1440, 461, -1, 494, 1440, 462, -1, 493, 1440, 494, -1, 461, 1440, 493, -1, 463, 1441, 462, -1, 495, 1441, 463, -1, 494, 1441, 495, -1, 462, 1441, 494, -1, 464, 1442, 463, -1, 496, 1442, 464, -1, 495, 1442, 496, -1, 463, 1442, 495, -1, 465, 1443, 464, -1, 497, 1443, 465, -1, 496, 1443, 497, -1, 464, 1443, 496, -1, 466, 1444, 465, -1, 498, 1444, 466, -1, 497, 1444, 498, -1, 465, 1444, 497, -1, 467, 1445, 466, -1, 499, 1445, 467, -1, 498, 1445, 499, -1, 466, 1445, 498, -1, 468, 1446, 467, -1, 500, 1446, 468, -1, 499, 1446, 500, -1, 467, 1446, 499, -1, 469, 1447, 468, -1, 501, 1447, 469, -1, 500, 1447, 501, -1, 468, 1447, 500, -1, 470, 1448, 469, -1, 502, 1448, 470, -1, 501, 1448, 502, -1, 469, 1448, 501, -1, 471, 1449, 470, -1, 503, 1449, 471, -1, 502, 1449, 503, -1, 470, 1449, 502, -1, 472, 1450, 471, -1, 504, 1450, 472, -1, 503, 1450, 504, -1, 471, 1450, 503, -1, 473, 1451, 472, -1, 505, 1451, 473, -1, 504, 1451, 505, -1, 472, 1451, 504, -1, 474, 1452, 473, -1, 506, 1452, 474, -1, 505, 1452, 506, -1, 473, 1452, 505, -1, 475, 1453, 474, -1, 507, 1453, 475, -1, 506, 1453, 507, -1, 474, 1453, 506, -1, 476, 1454, 475, -1, 508, 1454, 476, -1, 507, 1454, 508, -1, 475, 1454, 507, -1, 477, 1455, 476, -1, 509, 1455, 477, -1, 508, 1455, 509, -1, 476, 1455, 508, -1, 478, 1456, 477, -1, 510, 1456, 478, -1, 509, 1456, 510, -1, 477, 1456, 509, -1, 479, 1457, 478, -1, 511, 1457, 479, -1, 510, 1457, 511, -1, 478, 1457, 510, -1, 481, 1458, 480, -1, 513, 1458, 481, -1, 512, 1458, 513, -1, 480, 1458, 512, -1, 482, 1459, 481, -1, 514, 1459, 482, -1, 513, 1459, 514, -1, 481, 1459, 513, -1, 483, 1460, 482, -1, 515, 1460, 483, -1, 514, 1460, 515, -1, 482, 1460, 514, -1, 484, 1461, 483, -1, 516, 1461, 484, -1, 515, 1461, 516, -1, 483, 1461, 515, -1, 485, 1462, 484, -1, 517, 1462, 485, -1, 516, 1462, 517, -1, 484, 1462, 516, -1, 486, 1463, 485, -1, 518, 1463, 486, -1, 517, 1463, 518, -1, 485, 1463, 517, -1, 487, 1464, 486, -1, 519, 1464, 487, -1, 518, 1464, 519, -1, 486, 1464, 518, -1, 488, 1465, 487, -1, 520, 1465, 488, -1, 519, 1465, 520, -1, 487, 1465, 519, -1, 489, 1466, 488, -1, 521, 1466, 489, -1, 520, 1466, 521, -1, 488, 1466, 520, -1, 490, 1467, 489, -1, 522, 1467, 490, -1, 521, 1467, 522, -1, 489, 1467, 521, -1, 491, 1468, 490, -1, 523, 1468, 491, -1, 522, 1468, 523, -1, 490, 1468, 522, -1, 492, 1469, 491, -1, 524, 1469, 492, -1, 523, 1469, 524, -1, 491, 1469, 523, -1, 493, 1470, 492, -1, 525, 1470, 493, -1, 524, 1470, 525, -1, 492, 1470, 524, -1, 494, 1471, 493, -1, 526, 1471, 494, -1, 525, 1471, 526, -1, 493, 1471, 525, -1, 495, 1472, 494, -1, 527, 1472, 495, -1, 526, 1472, 527, -1, 494, 1472, 526, -1, 496, 1473, 495, -1, 528, 1473, 496, -1, 527, 1473, 528, -1, 495, 1473, 527, -1, 497, 1474, 496, -1, 529, 1474, 497, -1, 528, 1474, 529, -1, 496, 1474, 528, -1, 498, 1475, 497, -1, 530, 1475, 498, -1, 529, 1475, 530, -1, 497, 1475, 529, -1, 499, 1476, 498, -1, 531, 1476, 499, -1, 530, 1476, 531, -1, 498, 1476, 530, -1, 500, 1477, 499, -1, 532, 1477, 500, -1, 531, 1477, 532, -1, 499, 1477, 531, -1, 501, 1478, 500, -1, 533, 1478, 501, -1, 532, 1478, 533, -1, 500, 1478, 532, -1, 502, 1479, 501, -1, 534, 1479, 502, -1, 533, 1479, 534, -1, 501, 1479, 533, -1, 503, 1480, 502, -1, 535, 1480, 503, -1, 534, 1480, 535, -1, 502, 1480, 534, -1, 504, 1481, 503, -1, 536, 1481, 504, -1, 535, 1481, 536, -1, 503, 1481, 535, -1, 505, 1482, 504, -1, 537, 1482, 505, -1, 536, 1482, 537, -1, 504, 1482, 536, -1, 506, 1483, 505, -1, 538, 1483, 506, -1, 537, 1483, 538, -1, 505, 1483, 537, -1, 507, 1484, 506, -1, 539, 1484, 507, -1, 538, 1484, 539, -1, 506, 1484, 538, -1, 508, 1485, 507, -1, 540, 1485, 508, -1, 539, 1485, 540, -1, 507, 1485, 539, -1, 509, 1486, 508, -1, 541, 1486, 509, -1, 540, 1486, 541, -1, 508, 1486, 540, -1, 510, 1487, 509, -1, 542, 1487, 510, -1, 541, 1487, 542, -1, 509, 1487, 541, -1, 511, 1488, 510, -1, 543, 1488, 511, -1, 542, 1488, 543, -1, 510, 1488, 542, -1, 513, 1489, 512, -1, 545, 1489, 513, -1, 544, 1489, 545, -1, 512, 1489, 544, -1, 514, 1490, 513, -1, 546, 1490, 514, -1, 545, 1490, 546, -1, 513, 1490, 545, -1, 515, 1491, 514, -1, 547, 1491, 515, -1, 546, 1491, 547, -1, 514, 1491, 546, -1, 516, 1492, 515, -1, 548, 1492, 516, -1, 547, 1492, 548, -1, 515, 1492, 547, -1, 517, 1493, 516, -1, 549, 1493, 517, -1, 548, 1493, 549, -1, 516, 1493, 548, -1, 518, 1494, 517, -1, 550, 1494, 518, -1, 549, 1494, 550, -1, 517, 1494, 549, -1, 519, 1495, 518, -1, 551, 1495, 519, -1, 550, 1495, 551, -1, 518, 1495, 550, -1, 520, 1496, 519, -1, 552, 1496, 520, -1, 551, 1496, 552, -1, 519, 1496, 551, -1, 521, 1497, 520, -1, 553, 1497, 521, -1, 552, 1497, 553, -1, 520, 1497, 552, -1, 522, 1498, 521, -1, 554, 1498, 522, -1, 553, 1498, 554, -1, 521, 1498, 553, -1, 523, 1499, 522, -1, 555, 1499, 523, -1, 554, 1499, 555, -1, 522, 1499, 554, -1, 524, 1500, 523, -1, 556, 1500, 524, -1, 555, 1500, 556, -1, 523, 1500, 555, -1, 525, 1501, 524, -1, 557, 1501, 525, -1, 556, 1501, 557, -1, 524, 1501, 556, -1, 526, 1502, 525, -1, 558, 1502, 526, -1, 557, 1502, 558, -1, 525, 1502, 557, -1, 527, 1503, 526, -1, 559, 1503, 527, -1, 558, 1503, 559, -1, 526, 1503, 558, -1, 528, 1504, 527, -1, 560, 1504, 528, -1, 559, 1504, 560, -1, 527, 1504, 559, -1, 529, 1505, 528, -1, 561, 1505, 529, -1, 560, 1505, 561, -1, 528, 1505, 560, -1, 530, 1506, 529, -1, 562, 1506, 530, -1, 561, 1506, 562, -1, 529, 1506, 561, -1, 531, 1507, 530, -1, 563, 1507, 531, -1, 562, 1507, 563, -1, 530, 1507, 562, -1, 532, 1508, 531, -1, 564, 1508, 532, -1, 563, 1508, 564, -1, 531, 1508, 563, -1, 533, 1509, 532, -1, 565, 1509, 533, -1, 564, 1509, 565, -1, 532, 1509, 564, -1, 534, 1510, 533, -1, 566, 1510, 534, -1, 565, 1510, 566, -1, 533, 1510, 565, -1, 535, 1511, 534, -1, 567, 1511, 535, -1, 566, 1511, 567, -1, 534, 1511, 566, -1, 536, 1512, 535, -1, 568, 1512, 536, -1, 567, 1512, 568, -1, 535, 1512, 567, -1, 537, 1513, 536, -1, 569, 1513, 537, -1, 568, 1513, 569, -1, 536, 1513, 568, -1, 538, 1514, 537, -1, 570, 1514, 538, -1, 569, 1514, 570, -1, 537, 1514, 569, -1, 539, 1515, 538, -1, 571, 1515, 539, -1, 570, 1515, 571, -1, 538, 1515, 570, -1, 540, 1516, 539, -1, 572, 1516, 540, -1, 571, 1516, 572, -1, 539, 1516, 571, -1, 541, 1517, 540, -1, 573, 1517, 541, -1, 572, 1517, 573, -1, 540, 1517, 572, -1, 542, 1518, 541, -1, 574, 1518, 542, -1, 573, 1518, 574, -1, 541, 1518, 573, -1, 543, 1519, 542, -1, 575, 1519, 543, -1, 574, 1519, 575, -1, 542, 1519, 574, -1, 545, 1520, 544, -1, 577, 1520, 545, -1, 576, 1520, 577, -1, 544, 1520, 576, -1, 546, 1521, 545, -1, 578, 1521, 546, -1, 577, 1521, 578, -1, 545, 1521, 577, -1, 547, 1522, 546, -1, 579, 1522, 547, -1, 578, 1522, 579, -1, 546, 1522, 578, -1, 548, 1523, 547, -1, 580, 1523, 548, -1, 579, 1523, 580, -1, 547, 1523, 579, -1, 549, 1524, 548, -1, 581, 1524, 549, -1, 580, 1524, 581, -1, 548, 1524, 580, -1, 550, 1525, 549, -1, 582, 1525, 550, -1, 581, 1525, 582, -1, 549, 1525, 581, -1, 551, 1526, 550, -1, 583, 1526, 551, -1, 582, 1526, 583, -1, 550, 1526, 582, -1, 552, 1527, 551, -1, 584, 1527, 552, -1, 583, 1527, 584, -1, 551, 1527, 583, -1, 553, 1528, 552, -1, 585, 1528, 553, -1, 584, 1528, 585, -1, 552, 1528, 584, -1, 554, 1529, 553, -1, 586, 1529, 554, -1, 585, 1529, 586, -1, 553, 1529, 585, -1, 555, 1530, 554, -1, 587, 1530, 555, -1, 586, 1530, 587, -1, 554, 1530, 586, -1, 556, 1531, 555, -1, 588, 1531, 556, -1, 587, 1531, 588, -1, 555, 1531, 587, -1, 557, 1532, 556, -1, 589, 1532, 557, -1, 588, 1532, 589, -1, 556, 1532, 588, -1, 558, 1533, 557, -1, 590, 1533, 558, -1, 589, 1533, 590, -1, 557, 1533, 589, -1, 559, 1534, 558, -1, 591, 1534, 559, -1, 590, 1534, 591, -1, 558, 1534, 590, -1, 560, 1535, 559, -1, 592, 1535, 560, -1, 591, 1535, 592, -1, 559, 1535, 591, -1, 561, 1536, 560, -1, 593, 1536, 561, -1, 592, 1536, 593, -1, 560, 1536, 592, -1, 562, 1537, 561, -1, 594, 1537, 562, -1, 593, 1537, 594, -1, 561, 1537, 593, -1, 563, 1538, 562, -1, 595, 1538, 563, -1, 594, 1538, 595, -1, 562, 1538, 594, -1, 564, 1539, 563, -1, 596, 1539, 564, -1, 595, 1539, 596, -1, 563, 1539, 595, -1, 565, 1540, 564, -1, 597, 1540, 565, -1, 596, 1540, 597, -1, 564, 1540, 596, -1, 566, 1541, 565, -1, 598, 1541, 566, -1, 597, 1541, 598, -1, 565, 1541, 597, -1, 567, 1542, 566, -1, 599, 1542, 567, -1, 598, 1542, 599, -1, 566, 1542, 598, -1, 568, 1543, 567, -1, 600, 1543, 568, -1, 599, 1543, 600, -1, 567, 1543, 599, -1, 569, 1544, 568, -1, 601, 1544, 569, -1, 600, 1544, 601, -1, 568, 1544, 600, -1, 570, 1545, 569, -1, 602, 1545, 570, -1, 601, 1545, 602, -1, 569, 1545, 601, -1, 571, 1546, 570, -1, 603, 1546, 571, -1, 602, 1546, 603, -1, 570, 1546, 602, -1, 572, 1547, 571, -1, 604, 1547, 572, -1, 603, 1547, 604, -1, 571, 1547, 603, -1, 573, 1548, 572, -1, 605, 1548, 573, -1, 604, 1548, 605, -1, 572, 1548, 604, -1, 574, 1549, 573, -1, 606, 1549, 574, -1, 605, 1549, 606, -1, 573, 1549, 605, -1, 575, 1550, 574, -1, 607, 1550, 575, -1, 606, 1550, 607, -1, 574, 1550, 606, -1, 577, 1551, 576, -1, 609, 1551, 577, -1, 608, 1551, 609, -1, 576, 1551, 608, -1, 578, 1552, 577, -1, 610, 1552, 578, -1, 609, 1552, 610, -1, 577, 1552, 609, -1, 579, 1553, 578, -1, 611, 1553, 579, -1, 610, 1553, 611, -1, 578, 1553, 610, -1, 580, 1554, 579, -1, 612, 1554, 580, -1, 611, 1554, 612, -1, 579, 1554, 611, -1, 581, 1555, 580, -1, 613, 1555, 581, -1, 612, 1555, 613, -1, 580, 1555, 612, -1, 582, 1556, 581, -1, 614, 1556, 582, -1, 613, 1556, 614, -1, 581, 1556, 613, -1, 583, 1557, 582, -1, 615, 1557, 583, -1, 614, 1557, 615, -1, 582, 1557, 614, -1, 584, 1558, 583, -1, 616, 1558, 584, -1, 615, 1558, 616, -1, 583, 1558, 615, -1, 585, 1559, 584, -1, 617, 1559, 585, -1, 616, 1559, 617, -1, 584, 1559, 616, -1, 586, 1560, 585, -1, 618, 1560, 586, -1, 617, 1560, 618, -1, 585, 1560, 617, -1, 587, 1561, 586, -1, 619, 1561, 587, -1, 618, 1561, 619, -1, 586, 1561, 618, -1, 588, 1562, 587, -1, 620, 1562, 588, -1, 619, 1562, 620, -1, 587, 1562, 619, -1, 589, 1563, 588, -1, 621, 1563, 589, -1, 620, 1563, 621, -1, 588, 1563, 620, -1, 590, 1564, 589, -1, 622, 1564, 590, -1, 621, 1564, 622, -1, 589, 1564, 621, -1, 591, 1565, 590, -1, 623, 1565, 591, -1, 622, 1565, 623, -1, 590, 1565, 622, -1, 592, 1566, 591, -1, 624, 1566, 592, -1, 623, 1566, 624, -1, 591, 1566, 623, -1, 593, 1567, 592, -1, 625, 1567, 593, -1, 624, 1567, 625, -1, 592, 1567, 624, -1, 594, 1568, 593, -1, 626, 1568, 594, -1, 625, 1568, 626, -1, 593, 1568, 625, -1, 595, 1569, 594, -1, 627, 1569, 595, -1, 626, 1569, 627, -1, 594, 1569, 626, -1, 596, 1570, 595, -1, 628, 1570, 596, -1, 627, 1570, 628, -1, 595, 1570, 627, -1, 597, 1571, 596, -1, 629, 1571, 597, -1, 628, 1571, 629, -1, 596, 1571, 628, -1, 598, 1572, 597, -1, 630, 1572, 598, -1, 629, 1572, 630, -1, 597, 1572, 629, -1, 599, 1573, 598, -1, 631, 1573, 599, -1, 630, 1573, 631, -1, 598, 1573, 630, -1, 600, 1574, 599, -1, 632, 1574, 600, -1, 631, 1574, 632, -1, 599, 1574, 631, -1, 601, 1575, 600, -1, 633, 1575, 601, -1, 632, 1575, 633, -1, 600, 1575, 632, -1, 602, 1576, 601, -1, 634, 1576, 602, -1, 633, 1576, 634, -1, 601, 1576, 633, -1, 603, 1577, 602, -1, 635, 1577, 603, -1, 634, 1577, 635, -1, 602, 1577, 634, -1, 604, 1578, 603, -1, 636, 1578, 604, -1, 635, 1578, 636, -1, 603, 1578, 635, -1, 605, 1579, 604, -1, 637, 1579, 605, -1, 636, 1579, 637, -1, 604, 1579, 636, -1, 606, 1580, 605, -1, 638, 1580, 606, -1, 637, 1580, 638, -1, 605, 1580, 637, -1, 607, 1581, 606, -1, 639, 1581, 607, -1, 638, 1581, 639, -1, 606, 1581, 638, -1, 609, 1582, 608, -1, 641, 1582, 609, -1, 640, 1582, 641, -1, 608, 1582, 640, -1, 610, 1583, 609, -1, 642, 1583, 610, -1, 641, 1583, 642, -1, 609, 1583, 641, -1, 611, 1584, 610, -1, 643, 1584, 611, -1, 642, 1584, 643, -1, 610, 1584, 642, -1, 612, 1585, 611, -1, 644, 1585, 612, -1, 643, 1585, 644, -1, 611, 1585, 643, -1, 613, 1586, 612, -1, 645, 1586, 613, -1, 644, 1586, 645, -1, 612, 1586, 644, -1, 614, 1587, 613, -1, 646, 1587, 614, -1, 645, 1587, 646, -1, 613, 1587, 645, -1, 615, 1588, 614, -1, 647, 1588, 615, -1, 646, 1588, 647, -1, 614, 1588, 646, -1, 616, 1589, 615, -1, 648, 1589, 616, -1, 647, 1589, 648, -1, 615, 1589, 647, -1, 617, 1590, 616, -1, 649, 1590, 617, -1, 648, 1590, 649, -1, 616, 1590, 648, -1, 618, 1591, 617, -1, 650, 1591, 618, -1, 649, 1591, 650, -1, 617, 1591, 649, -1, 619, 1592, 618, -1, 651, 1592, 619, -1, 650, 1592, 651, -1, 618, 1592, 650, -1, 620, 1593, 619, -1, 652, 1593, 620, -1, 651, 1593, 652, -1, 619, 1593, 651, -1, 621, 1594, 620, -1, 653, 1594, 621, -1, 652, 1594, 653, -1, 620, 1594, 652, -1, 622, 1595, 621, -1, 654, 1595, 622, -1, 653, 1595, 654, -1, 621, 1595, 653, -1, 623, 1596, 622, -1, 655, 1596, 623, -1, 654, 1596, 655, -1, 622, 1596, 654, -1, 624, 1597, 623, -1, 656, 1597, 624, -1, 655, 1597, 656, -1, 623, 1597, 655, -1, 625, 1598, 624, -1, 657, 1598, 625, -1, 656, 1598, 657, -1, 624, 1598, 656, -1, 626, 1599, 625, -1, 658, 1599, 626, -1, 657, 1599, 658, -1, 625, 1599, 657, -1, 627, 1600, 626, -1, 659, 1600, 627, -1, 658, 1600, 659, -1, 626, 1600, 658, -1, 628, 1601, 627, -1, 660, 1601, 628, -1, 659, 1601, 660, -1, 627, 1601, 659, -1, 629, 1602, 628, -1, 661, 1602, 629, -1, 660, 1602, 661, -1, 628, 1602, 660, -1, 630, 1603, 629, -1, 662, 1603, 630, -1, 661, 1603, 662, -1, 629, 1603, 661, -1, 631, 1604, 630, -1, 663, 1604, 631, -1, 662, 1604, 663, -1, 630, 1604, 662, -1, 632, 1605, 631, -1, 664, 1605, 632, -1, 663, 1605, 664, -1, 631, 1605, 663, -1, 633, 1606, 632, -1, 665, 1606, 633, -1, 664, 1606, 665, -1, 632, 1606, 664, -1, 634, 1607, 633, -1, 666, 1607, 634, -1, 665, 1607, 666, -1, 633, 1607, 665, -1, 635, 1608, 634, -1, 667, 1608, 635, -1, 666, 1608, 667, -1, 634, 1608, 666, -1, 636, 1609, 635, -1, 668, 1609, 636, -1, 667, 1609, 668, -1, 635, 1609, 667, -1, 637, 1610, 636, -1, 669, 1610, 637, -1, 668, 1610, 669, -1, 636, 1610, 668, -1, 638, 1611, 637, -1, 670, 1611, 638, -1, 669, 1611, 670, -1, 637, 1611, 669, -1, 639, 1612, 638, -1, 671, 1612, 639, -1, 670, 1612, 671, -1, 638, 1612, 670, -1, 641, 1613, 640, -1, 673, 1613, 641, -1, 672, 1613, 673, -1, 640, 1613, 672, -1, 642, 1614, 641, -1, 674, 1614, 642, -1, 673, 1614, 674, -1, 641, 1614, 673, -1, 643, 1615, 642, -1, 675, 1615, 643, -1, 674, 1615, 675, -1, 642, 1615, 674, -1, 644, 1616, 643, -1, 676, 1616, 644, -1, 675, 1616, 676, -1, 643, 1616, 675, -1, 645, 1617, 644, -1, 677, 1617, 645, -1, 676, 1617, 677, -1, 644, 1617, 676, -1, 646, 1618, 645, -1, 678, 1618, 646, -1, 677, 1618, 678, -1, 645, 1618, 677, -1, 647, 1619, 646, -1, 679, 1619, 647, -1, 678, 1619, 679, -1, 646, 1619, 678, -1, 648, 1620, 647, -1, 680, 1620, 648, -1, 679, 1620, 680, -1, 647, 1620, 679, -1, 649, 1621, 648, -1, 681, 1621, 649, -1, 680, 1621, 681, -1, 648, 1621, 680, -1, 650, 1622, 649, -1, 682, 1622, 650, -1, 681, 1622, 682, -1, 649, 1622, 681, -1, 651, 1623, 650, -1, 683, 1623, 651, -1, 682, 1623, 683, -1, 650, 1623, 682, -1, 652, 1624, 651, -1, 684, 1624, 652, -1, 683, 1624, 684, -1, 651, 1624, 683, -1, 653, 1625, 652, -1, 685, 1625, 653, -1, 684, 1625, 685, -1, 652, 1625, 684, -1, 654, 1626, 653, -1, 686, 1626, 654, -1, 685, 1626, 686, -1, 653, 1626, 685, -1, 655, 1627, 654, -1, 687, 1627, 655, -1, 686, 1627, 687, -1, 654, 1627, 686, -1, 656, 1628, 655, -1, 688, 1628, 656, -1, 687, 1628, 688, -1, 655, 1628, 687, -1, 657, 1629, 656, -1, 689, 1629, 657, -1, 688, 1629, 689, -1, 656, 1629, 688, -1, 658, 1630, 657, -1, 690, 1630, 658, -1, 689, 1630, 690, -1, 657, 1630, 689, -1, 659, 1631, 658, -1, 691, 1631, 659, -1, 690, 1631, 691, -1, 658, 1631, 690, -1, 660, 1632, 659, -1, 692, 1632, 660, -1, 691, 1632, 692, -1, 659, 1632, 691, -1, 661, 1633, 660, -1, 693, 1633, 661, -1, 692, 1633, 693, -1, 660, 1633, 692, -1, 662, 1634, 661, -1, 694, 1634, 662, -1, 693, 1634, 694, -1, 661, 1634, 693, -1, 663, 1635, 662, -1, 695, 1635, 663, -1, 694, 1635, 695, -1, 662, 1635, 694, -1, 664, 1636, 663, -1, 696, 1636, 664, -1, 695, 1636, 696, -1, 663, 1636, 695, -1, 665, 1637, 664, -1, 697, 1637, 665, -1, 696, 1637, 697, -1, 664, 1637, 696, -1, 666, 1638, 665, -1, 698, 1638, 666, -1, 697, 1638, 698, -1, 665, 1638, 697, -1, 667, 1639, 666, -1, 699, 1639, 667, -1, 698, 1639, 699, -1, 666, 1639, 698, -1, 668, 1640, 667, -1, 700, 1640, 668, -1, 699, 1640, 700, -1, 667, 1640, 699, -1, 669, 1641, 668, -1, 701, 1641, 669, -1, 700, 1641, 701, -1, 668, 1641, 700, -1, 670, 1642, 669, -1, 702, 1642, 670, -1, 701, 1642, 702, -1, 669, 1642, 701, -1, 671, 1643, 670, -1, 703, 1643, 671, -1, 702, 1643, 703, -1, 670, 1643, 702, -1, 673, 1644, 672, -1, 705, 1644, 673, -1, 704, 1644, 705, -1, 672, 1644, 704, -1, 674, 1645, 673, -1, 706, 1645, 674, -1, 705, 1645, 706, -1, 673, 1645, 705, -1, 675, 1646, 674, -1, 707, 1646, 675, -1, 706, 1646, 707, -1, 674, 1646, 706, -1, 676, 1647, 675, -1, 708, 1647, 676, -1, 707, 1647, 708, -1, 675, 1647, 707, -1, 677, 1648, 676, -1, 709, 1648, 677, -1, 708, 1648, 709, -1, 676, 1648, 708, -1, 678, 1649, 677, -1, 710, 1649, 678, -1, 709, 1649, 710, -1, 677, 1649, 709, -1, 679, 1650, 678, -1, 711, 1650, 679, -1, 710, 1650, 711, -1, 678, 1650, 710, -1, 680, 1651, 679, -1, 712, 1651, 680, -1, 711, 1651, 712, -1, 679, 1651, 711, -1, 681, 1652, 680, -1, 713, 1652, 681, -1, 712, 1652, 713, -1, 680, 1652, 712, -1, 682, 1653, 681, -1, 714, 1653, 682, -1, 713, 1653, 714, -1, 681, 1653, 713, -1, 683, 1654, 682, -1, 715, 1654, 683, -1, 714, 1654, 715, -1, 682, 1654, 714, -1, 684, 1655, 683, -1, 716, 1655, 684, -1, 715, 1655, 716, -1, 683, 1655, 715, -1, 685, 1656, 684, -1, 717, 1656, 685, -1, 716, 1656, 717, -1, 684, 1656, 716, -1, 686, 1657, 685, -1, 718, 1657, 686, -1, 717, 1657, 718, -1, 685, 1657, 717, -1, 687, 1658, 686, -1, 719, 1658, 687, -1, 718, 1658, 719, -1, 686, 1658, 718, -1, 688, 1659, 687, -1, 720, 1659, 688, -1, 719, 1659, 720, -1, 687, 1659, 719, -1, 689, 1660, 688, -1, 721, 1660, 689, -1, 720, 1660, 721, -1, 688, 1660, 720, -1, 690, 1661, 689, -1, 722, 1661, 690, -1, 721, 1661, 722, -1, 689, 1661, 721, -1, 691, 1662, 690, -1, 723, 1662, 691, -1, 722, 1662, 723, -1, 690, 1662, 722, -1, 692, 1663, 691, -1, 724, 1663, 692, -1, 723, 1663, 724, -1, 691, 1663, 723, -1, 693, 1664, 692, -1, 725, 1664, 693, -1, 724, 1664, 725, -1, 692, 1664, 724, -1, 694, 1665, 693, -1, 726, 1665, 694, -1, 725, 1665, 726, -1, 693, 1665, 725, -1, 695, 1666, 694, -1, 727, 1666, 695, -1, 726, 1666, 727, -1, 694, 1666, 726, -1, 696, 1667, 695, -1, 728, 1667, 696, -1, 727, 1667, 728, -1, 695, 1667, 727, -1, 697, 1668, 696, -1, 729, 1668, 697, -1, 728, 1668, 729, -1, 696, 1668, 728, -1, 698, 1669, 697, -1, 730, 1669, 698, -1, 729, 1669, 730, -1, 697, 1669, 729, -1, 699, 1670, 698, -1, 731, 1670, 699, -1, 730, 1670, 731, -1, 698, 1670, 730, -1, 700, 1671, 699, -1, 732, 1671, 700, -1, 731, 1671, 732, -1, 699, 1671, 731, -1, 701, 1672, 700, -1, 733, 1672, 701, -1, 732, 1672, 733, -1, 700, 1672, 732, -1, 702, 1673, 701, -1, 734, 1673, 702, -1, 733, 1673, 734, -1, 701, 1673, 733, -1, 703, 1674, 702, -1, 735, 1674, 703, -1, 734, 1674, 735, -1, 702, 1674, 734, -1, 705, 1675, 704, -1, 737, 1675, 705, -1, 736, 1675, 737, -1, 704, 1675, 736, -1, 706, 1676, 705, -1, 738, 1676, 706, -1, 737, 1676, 738, -1, 705, 1676, 737, -1, 707, 1677, 706, -1, 739, 1677, 707, -1, 738, 1677, 739, -1, 706, 1677, 738, -1, 708, 1678, 707, -1, 740, 1678, 708, -1, 739, 1678, 740, -1, 707, 1678, 739, -1, 709, 1679, 708, -1, 741, 1679, 709, -1, 740, 1679, 741, -1, 708, 1679, 740, -1, 710, 1680, 709, -1, 742, 1680, 710, -1, 741, 1680, 742, -1, 709, 1680, 741, -1, 711, 1681, 710, -1, 743, 1681, 711, -1, 742, 1681, 743, -1, 710, 1681, 742, -1, 712, 1682, 711, -1, 744, 1682, 712, -1, 743, 1682, 744, -1, 711, 1682, 743, -1, 713, 1683, 712, -1, 745, 1683, 713, -1, 744, 1683, 745, -1, 712, 1683, 744, -1, 714, 1684, 713, -1, 746, 1684, 714, -1, 745, 1684, 746, -1, 713, 1684, 745, -1, 715, 1685, 714, -1, 747, 1685, 715, -1, 746, 1685, 747, -1, 714, 1685, 746, -1, 716, 1686, 715, -1, 748, 1686, 716, -1, 747, 1686, 748, -1, 715, 1686, 747, -1, 717, 1687, 716, -1, 749, 1687, 717, -1, 748, 1687, 749, -1, 716, 1687, 748, -1, 718, 1688, 717, -1, 750, 1688, 718, -1, 749, 1688, 750, -1, 717, 1688, 749, -1, 719, 1689, 718, -1, 751, 1689, 719, -1, 750, 1689, 751, -1, 718, 1689, 750, -1, 720, 1690, 719, -1, 752, 1690, 720, -1, 751, 1690, 752, -1, 719, 1690, 751, -1, 721, 1691, 720, -1, 753, 1691, 721, -1, 752, 1691, 753, -1, 720, 1691, 752, -1, 722, 1692, 721, -1, 754, 1692, 722, -1, 753, 1692, 754, -1, 721, 1692, 753, -1, 723, 1693, 722, -1, 755, 1693, 723, -1, 754, 1693, 755, -1, 722, 1693, 754, -1, 724, 1694, 723, -1, 756, 1694, 724, -1, 755, 1694, 756, -1, 723, 1694, 755, -1, 725, 1695, 724, -1, 757, 1695, 725, -1, 756, 1695, 757, -1, 724, 1695, 756, -1, 726, 1696, 725, -1, 758, 1696, 726, -1, 757, 1696, 758, -1, 725, 1696, 757, -1, 727, 1697, 726, -1, 759, 1697, 727, -1, 758, 1697, 759, -1, 726, 1697, 758, -1, 728, 1698, 727, -1, 760, 1698, 728, -1, 759, 1698, 760, -1, 727, 1698, 759, -1, 729, 1699, 728, -1, 761, 1699, 729, -1, 760, 1699, 761, -1, 728, 1699, 760, -1, 730, 1700, 729, -1, 762, 1700, 730, -1, 761, 1700, 762, -1, 729, 1700, 761, -1, 731, 1701, 730, -1, 763, 1701, 731, -1, 762, 1701, 763, -1, 730, 1701, 762, -1, 732, 1702, 731, -1, 764, 1702, 732, -1, 763, 1702, 764, -1, 731, 1702, 763, -1, 733, 1703, 732, -1, 765, 1703, 733, -1, 764, 1703, 765, -1, 732, 1703, 764, -1, 734, 1704, 733, -1, 766, 1704, 734, -1, 765, 1704, 766, -1, 733, 1704, 765, -1, 735, 1705, 734, -1, 767, 1705, 735, -1, 766, 1705, 767, -1, 734, 1705, 766, -1, 737, 1706, 736, -1, 769, 1706, 737, -1, 768, 1706, 769, -1, 736, 1706, 768, -1, 738, 1707, 737, -1, 770, 1707, 738, -1, 769, 1707, 770, -1, 737, 1707, 769, -1, 739, 1708, 738, -1, 771, 1708, 739, -1, 770, 1708, 771, -1, 738, 1708, 770, -1, 740, 1709, 739, -1, 772, 1709, 740, -1, 771, 1709, 772, -1, 739, 1709, 771, -1, 741, 1710, 740, -1, 773, 1710, 741, -1, 772, 1710, 773, -1, 740, 1710, 772, -1, 742, 1711, 741, -1, 774, 1711, 742, -1, 773, 1711, 774, -1, 741, 1711, 773, -1, 743, 1712, 742, -1, 775, 1712, 743, -1, 774, 1712, 775, -1, 742, 1712, 774, -1, 744, 1713, 743, -1, 776, 1713, 744, -1, 775, 1713, 776, -1, 743, 1713, 775, -1, 745, 1714, 744, -1, 777, 1714, 745, -1, 776, 1714, 777, -1, 744, 1714, 776, -1, 746, 1715, 745, -1, 778, 1715, 746, -1, 777, 1715, 778, -1, 745, 1715, 777, -1, 747, 1716, 746, -1, 779, 1716, 747, -1, 778, 1716, 779, -1, 746, 1716, 778, -1, 748, 1717, 747, -1, 780, 1717, 748, -1, 779, 1717, 780, -1, 747, 1717, 779, -1, 749, 1718, 748, -1, 781, 1718, 749, -1, 780, 1718, 781, -1, 748, 1718, 780, -1, 750, 1719, 749, -1, 782, 1719, 750, -1, 781, 1719, 782, -1, 749, 1719, 781, -1, 751, 1720, 750, -1, 783, 1720, 751, -1, 782, 1720, 783, -1, 750, 1720, 782, -1, 752, 1721, 751, -1, 784, 1721, 752, -1, 783, 1721, 784, -1, 751, 1721, 783, -1, 753, 1722, 752, -1, 785, 1722, 753, -1, 784, 1722, 785, -1, 752, 1722, 784, -1, 754, 1723, 753, -1, 786, 1723, 754, -1, 785, 1723, 786, -1, 753, 1723, 785, -1, 755, 1724, 754, -1, 787, 1724, 755, -1, 786, 1724, 787, -1, 754, 1724, 786, -1, 756, 1725, 755, -1, 788, 1725, 756, -1, 787, 1725, 788, -1, 755, 1725, 787, -1, 757, 1726, 756, -1, 789, 1726, 757, -1, 788, 1726, 789, -1, 756, 1726, 788, -1, 758, 1727, 757, -1, 790, 1727, 758, -1, 789, 1727, 790, -1, 757, 1727, 789, -1, 759, 1728, 758, -1, 791, 1728, 759, -1, 790, 1728, 791, -1, 758, 1728, 790, -1, 760, 1729, 759, -1, 792, 1729, 760, -1, 791, 1729, 792, -1, 759, 1729, 791, -1, 761, 1730, 760, -1, 793, 1730, 761, -1, 792, 1730, 793, -1, 760, 1730, 792, -1, 762, 1731, 761, -1, 794, 1731, 762, -1, 793, 1731, 794, -1, 761, 1731, 793, -1, 763, 1732, 762, -1, 795, 1732, 763, -1, 794, 1732, 795, -1, 762, 1732, 794, -1, 764, 1733, 763, -1, 796, 1733, 764, -1, 795, 1733, 796, -1, 763, 1733, 795, -1, 765, 1734, 764, -1, 797, 1734, 765, -1, 796, 1734, 797, -1, 764, 1734, 796, -1, 766, 1735, 765, -1, 798, 1735, 766, -1, 797, 1735, 798, -1, 765, 1735, 797, -1, 767, 1736, 766, -1, 799, 1736, 767, -1, 798, 1736, 799, -1, 766, 1736, 798, -1, 769, 1737, 768, -1, 801, 1737, 769, -1, 800, 1737, 801, -1, 768, 1737, 800, -1, 770, 1738, 769, -1, 802, 1738, 770, -1, 801, 1738, 802, -1, 769, 1738, 801, -1, 771, 1739, 770, -1, 803, 1739, 771, -1, 802, 1739, 803, -1, 770, 1739, 802, -1, 772, 1740, 771, -1, 804, 1740, 772, -1, 803, 1740, 804, -1, 771, 1740, 803, -1, 773, 1741, 772, -1, 805, 1741, 773, -1, 804, 1741, 805, -1, 772, 1741, 804, -1, 774, 1742, 773, -1, 806, 1742, 774, -1, 805, 1742, 806, -1, 773, 1742, 805, -1, 775, 1743, 774, -1, 807, 1743, 775, -1, 806, 1743, 807, -1, 774, 1743, 806, -1, 776, 1744, 775, -1, 808, 1744, 776, -1, 807, 1744, 808, -1, 775, 1744, 807, -1, 777, 1745, 776, -1, 809, 1745, 777, -1, 808, 1745, 809, -1, 776, 1745, 808, -1, 778, 1746, 777, -1, 810, 1746, 778, -1, 809, 1746, 810, -1, 777, 1746, 809, -1, 779, 1747, 778, -1, 811, 1747, 779, -1, 810, 1747, 811, -1, 778, 1747, 810, -1, 780, 1748, 779, -1, 812, 1748, 780, -1, 811, 1748, 812, -1, 779, 1748, 811, -1, 781, 1749, 780, -1, 813, 1749, 781, -1, 812, 1749, 813, -1, 780, 1749, 812, -1, 782, 1750, 781, -1, 814, 1750, 782, -1, 813, 1750, 814, -1, 781, 1750, 813, -1, 783, 1751, 782, -1, 815, 1751, 783, -1, 814, 1751, 815, -1, 782, 1751, 814, -1, 784, 1752, 783, -1, 816, 1752, 784, -1, 815, 1752, 816, -1, 783, 1752, 815, -1, 785, 1753, 784, -1, 817, 1753, 785, -1, 816, 1753, 817, -1, 784, 1753, 816, -1, 786, 1754, 785, -1, 818, 1754, 786, -1, 817, 1754, 818, -1, 785, 1754, 817, -1, 787, 1755, 786, -1, 819, 1755, 787, -1, 818, 1755, 819, -1, 786, 1755, 818, -1, 788, 1756, 787, -1, 820, 1756, 788, -1, 819, 1756, 820, -1, 787, 1756, 819, -1, 789, 1757, 788, -1, 821, 1757, 789, -1, 820, 1757, 821, -1, 788, 1757, 820, -1, 790, 1758, 789, -1, 822, 1758, 790, -1, 821, 1758, 822, -1, 789, 1758, 821, -1, 791, 1759, 790, -1, 823, 1759, 791, -1, 822, 1759, 823, -1, 790, 1759, 822, -1, 792, 1760, 791, -1, 824, 1760, 792, -1, 823, 1760, 824, -1, 791, 1760, 823, -1, 793, 1761, 792, -1, 825, 1761, 793, -1, 824, 1761, 825, -1, 792, 1761, 824, -1, 794, 1762, 793, -1, 826, 1762, 794, -1, 825, 1762, 826, -1, 793, 1762, 825, -1, 795, 1763, 794, -1, 827, 1763, 795, -1, 826, 1763, 827, -1, 794, 1763, 826, -1, 796, 1764, 795, -1, 828, 1764, 796, -1, 827, 1764, 828, -1, 795, 1764, 827, -1, 797, 1765, 796, -1, 829, 1765, 797, -1, 828, 1765, 829, -1, 796, 1765, 828, -1, 798, 1766, 797, -1, 830, 1766, 798, -1, 829, 1766, 830, -1, 797, 1766, 829, -1, 799, 1767, 798, -1, 831, 1767, 799, -1, 830, 1767, 831, -1, 798, 1767, 830, -1, 801, 1768, 800, -1, 833, 1768, 801, -1, 832, 1768, 833, -1, 800, 1768, 832, -1, 802, 1769, 801, -1, 834, 1769, 802, -1, 833, 1769, 834, -1, 801, 1769, 833, -1, 803, 1770, 802, -1, 835, 1770, 803, -1, 834, 1770, 835, -1, 802, 1770, 834, -1, 804, 1771, 803, -1, 836, 1771, 804, -1, 835, 1771, 836, -1, 803, 1771, 835, -1, 805, 1772, 804, -1, 837, 1772, 805, -1, 836, 1772, 837, -1, 804, 1772, 836, -1, 806, 1773, 805, -1, 838, 1773, 806, -1, 837, 1773, 838, -1, 805, 1773, 837, -1, 807, 1774, 806, -1, 839, 1774, 807, -1, 838, 1774, 839, -1, 806, 1774, 838, -1, 808, 1775, 807, -1, 840, 1775, 808, -1, 839, 1775, 840, -1, 807, 1775, 839, -1, 809, 1776, 808, -1, 841, 1776, 809, -1, 840, 1776, 841, -1, 808, 1776, 840, -1, 810, 1777, 809, -1, 842, 1777, 810, -1, 841, 1777, 842, -1, 809, 1777, 841, -1, 811, 1778, 810, -1, 843, 1778, 811, -1, 842, 1778, 843, -1, 810, 1778, 842, -1, 812, 1779, 811, -1, 844, 1779, 812, -1, 843, 1779, 844, -1, 811, 1779, 843, -1, 813, 1780, 812, -1, 845, 1780, 813, -1, 844, 1780, 845, -1, 812, 1780, 844, -1, 814, 1781, 813, -1, 846, 1781, 814, -1, 845, 1781, 846, -1, 813, 1781, 845, -1, 815, 1782, 814, -1, 847, 1782, 815, -1, 846, 1782, 847, -1, 814, 1782, 846, -1, 816, 1783, 815, -1, 848, 1783, 816, -1, 847, 1783, 848, -1, 815, 1783, 847, -1, 817, 1784, 816, -1, 849, 1784, 817, -1, 848, 1784, 849, -1, 816, 1784, 848, -1, 818, 1785, 817, -1, 850, 1785, 818, -1, 849, 1785, 850, -1, 817, 1785, 849, -1, 819, 1786, 818, -1, 851, 1786, 819, -1, 850, 1786, 851, -1, 818, 1786, 850, -1, 820, 1787, 819, -1, 852, 1787, 820, -1, 851, 1787, 852, -1, 819, 1787, 851, -1, 821, 1788, 820, -1, 853, 1788, 821, -1, 852, 1788, 853, -1, 820, 1788, 852, -1, 822, 1789, 821, -1, 854, 1789, 822, -1, 853, 1789, 854, -1, 821, 1789, 853, -1, 823, 1790, 822, -1, 855, 1790, 823, -1, 854, 1790, 855, -1, 822, 1790, 854, -1, 824, 1791, 823, -1, 856, 1791, 824, -1, 855, 1791, 856, -1, 823, 1791, 855, -1, 825, 1792, 824, -1, 857, 1792, 825, -1, 856, 1792, 857, -1, 824, 1792, 856, -1, 826, 1793, 825, -1, 858, 1793, 826, -1, 857, 1793, 858, -1, 825, 1793, 857, -1, 827, 1794, 826, -1, 859, 1794, 827, -1, 858, 1794, 859, -1, 826, 1794, 858, -1, 828, 1795, 827, -1, 860, 1795, 828, -1, 859, 1795, 860, -1, 827, 1795, 859, -1, 829, 1796, 828, -1, 861, 1796, 829, -1, 860, 1796, 861, -1, 828, 1796, 860, -1, 830, 1797, 829, -1, 862, 1797, 830, -1, 861, 1797, 862, -1, 829, 1797, 861, -1, 831, 1798, 830, -1, 863, 1798, 831, -1, 862, 1798, 863, -1, 830, 1798, 862, -1, 833, 1799, 832, -1, 865, 1799, 833, -1, 864, 1799, 865, -1, 832, 1799, 864, -1, 834, 1800, 833, -1, 866, 1800, 834, -1, 865, 1800, 866, -1, 833, 1800, 865, -1, 835, 1801, 834, -1, 867, 1801, 835, -1, 866, 1801, 867, -1, 834, 1801, 866, -1, 836, 1802, 835, -1, 868, 1802, 836, -1, 867, 1802, 868, -1, 835, 1802, 867, -1, 837, 1803, 836, -1, 869, 1803, 837, -1, 868, 1803, 869, -1, 836, 1803, 868, -1, 838, 1804, 837, -1, 870, 1804, 838, -1, 869, 1804, 870, -1, 837, 1804, 869, -1, 839, 1805, 838, -1, 871, 1805, 839, -1, 870, 1805, 871, -1, 838, 1805, 870, -1, 840, 1806, 839, -1, 872, 1806, 840, -1, 871, 1806, 872, -1, 839, 1806, 871, -1, 841, 1807, 840, -1, 873, 1807, 841, -1, 872, 1807, 873, -1, 840, 1807, 872, -1, 842, 1808, 841, -1, 874, 1808, 842, -1, 873, 1808, 874, -1, 841, 1808, 873, -1, 843, 1809, 842, -1, 875, 1809, 843, -1, 874, 1809, 875, -1, 842, 1809, 874, -1, 844, 1810, 843, -1, 876, 1810, 844, -1, 875, 1810, 876, -1, 843, 1810, 875, -1, 845, 1811, 844, -1, 877, 1811, 845, -1, 876, 1811, 877, -1, 844, 1811, 876, -1, 846, 1812, 845, -1, 878, 1812, 846, -1, 877, 1812, 878, -1, 845, 1812, 877, -1, 847, 1813, 846, -1, 879, 1813, 847, -1, 878, 1813, 879, -1, 846, 1813, 878, -1, 848, 1814, 847, -1, 880, 1814, 848, -1, 879, 1814, 880, -1, 847, 1814, 879, -1, 849, 1815, 848, -1, 881, 1815, 849, -1, 880, 1815, 881, -1, 848, 1815, 880, -1, 850, 1816, 849, -1, 882, 1816, 850, -1, 881, 1816, 882, -1, 849, 1816, 881, -1, 851, 1817, 850, -1, 883, 1817, 851, -1, 882, 1817, 883, -1, 850, 1817, 882, -1, 852, 1818, 851, -1, 884, 1818, 852, -1, 883, 1818, 884, -1, 851, 1818, 883, -1, 853, 1819, 852, -1, 885, 1819, 853, -1, 884, 1819, 885, -1, 852, 1819, 884, -1, 854, 1820, 853, -1, 886, 1820, 854, -1, 885, 1820, 886, -1, 853, 1820, 885, -1, 855, 1821, 854, -1, 887, 1821, 855, -1, 886, 1821, 887, -1, 854, 1821, 886, -1, 856, 1822, 855, -1, 888, 1822, 856, -1, 887, 1822, 888, -1, 855, 1822, 887, -1, 857, 1823, 856, -1, 889, 1823, 857, -1, 888, 1823, 889, -1, 856, 1823, 888, -1, 858, 1824, 857, -1, 890, 1824, 858, -1, 889, 1824, 890, -1, 857, 1824, 889, -1, 859, 1825, 858, -1, 891, 1825, 859, -1, 890, 1825, 891, -1, 858, 1825, 890, -1, 860, 1826, 859, -1, 892, 1826, 860, -1, 891, 1826, 892, -1, 859, 1826, 891, -1, 861, 1827, 860, -1, 893, 1827, 861, -1, 892, 1827, 893, -1, 860, 1827, 892, -1, 862, 1828, 861, -1, 894, 1828, 862, -1, 893, 1828, 894, -1, 861, 1828, 893, -1, 863, 1829, 862, -1, 895, 1829, 863, -1, 894, 1829, 895, -1, 862, 1829, 894, -1, 865, 1830, 864, -1, 897, 1830, 865, -1, 896, 1830, 897, -1, 864, 1830, 896, -1, 866, 1831, 865, -1, 898, 1831, 866, -1, 897, 1831, 898, -1, 865, 1831, 897, -1, 867, 1832, 866, -1, 899, 1832, 867, -1, 898, 1832, 899, -1, 866, 1832, 898, -1, 868, 1833, 867, -1, 900, 1833, 868, -1, 899, 1833, 900, -1, 867, 1833, 899, -1, 869, 1834, 868, -1, 901, 1834, 869, -1, 900, 1834, 901, -1, 868, 1834, 900, -1, 870, 1835, 869, -1, 902, 1835, 870, -1, 901, 1835, 902, -1, 869, 1835, 901, -1, 871, 1836, 870, -1, 903, 1836, 871, -1, 902, 1836, 903, -1, 870, 1836, 902, -1, 872, 1837, 871, -1, 904, 1837, 872, -1, 903, 1837, 904, -1, 871, 1837, 903, -1, 873, 1838, 872, -1, 905, 1838, 873, -1, 904, 1838, 905, -1, 872, 1838, 904, -1, 874, 1839, 873, -1, 906, 1839, 874, -1, 905, 1839, 906, -1, 873, 1839, 905, -1, 875, 1840, 874, -1, 907, 1840, 875, -1, 906, 1840, 907, -1, 874, 1840, 906, -1, 876, 1841, 875, -1, 908, 1841, 876, -1, 907, 1841, 908, -1, 875, 1841, 907, -1, 877, 1842, 876, -1, 909, 1842, 877, -1, 908, 1842, 909, -1, 876, 1842, 908, -1, 878, 1843, 877, -1, 910, 1843, 878, -1, 909, 1843, 910, -1, 877, 1843, 909, -1, 879, 1844, 878, -1, 911, 1844, 879, -1, 910, 1844, 911, -1, 878, 1844, 910, -1, 880, 1845, 879, -1, 912, 1845, 880, -1, 911, 1845, 912, -1, 879, 1845, 911, -1, 881, 1846, 880, -1, 913, 1846, 881, -1, 912, 1846, 913, -1, 880, 1846, 912, -1, 882, 1847, 881, -1, 914, 1847, 882, -1, 913, 1847, 914, -1, 881, 1847, 913, -1, 883, 1848, 882, -1, 915, 1848, 883, -1, 914, 1848, 915, -1, 882, 1848, 914, -1, 884, 1849, 883, -1, 916, 1849, 884, -1, 915, 1849, 916, -1, 883, 1849, 915, -1, 885, 1850, 884, -1, 917, 1850, 885, -1, 916, 1850, 917, -1, 884, 1850, 916, -1, 886, 1851, 885, -1, 918, 1851, 886, -1, 917, 1851, 918, -1, 885, 1851, 917, -1, 887, 1852, 886, -1, 919, 1852, 887, -1, 918, 1852, 919, -1, 886, 1852, 918, -1, 888, 1853, 887, -1, 920, 1853, 888, -1, 919, 1853, 920, -1, 887, 1853, 919, -1, 889, 1854, 888, -1, 921, 1854, 889, -1, 920, 1854, 921, -1, 888, 1854, 920, -1, 890, 1855, 889, -1, 922, 1855, 890, -1, 921, 1855, 922, -1, 889, 1855, 921, -1, 891, 1856, 890, -1, 923, 1856, 891, -1, 922, 1856, 923, -1, 890, 1856, 922, -1, 892, 1857, 891, -1, 924, 1857, 892, -1, 923, 1857, 924, -1, 891, 1857, 923, -1, 893, 1858, 892, -1, 925, 1858, 893, -1, 924, 1858, 925, -1, 892, 1858, 924, -1, 894, 1859, 893, -1, 926, 1859, 894, -1, 925, 1859, 926, -1, 893, 1859, 925, -1, 895, 1860, 894, -1, 927, 1860, 895, -1, 926, 1860, 927, -1, 894, 1860, 926, -1, 897, 1861, 896, -1, 929, 1861, 897, -1, 928, 1861, 929, -1, 896, 1861, 928, -1, 898, 1862, 897, -1, 930, 1862, 898, -1, 929, 1862, 930, -1, 897, 1862, 929, -1, 899, 1863, 898, -1, 931, 1863, 899, -1, 930, 1863, 931, -1, 898, 1863, 930, -1, 900, 1864, 899, -1, 932, 1864, 900, -1, 931, 1864, 932, -1, 899, 1864, 931, -1, 901, 1865, 900, -1, 933, 1865, 901, -1, 932, 1865, 933, -1, 900, 1865, 932, -1, 902, 1866, 901, -1, 934, 1866, 902, -1, 933, 1866, 934, -1, 901, 1866, 933, -1, 903, 1867, 902, -1, 935, 1867, 903, -1, 934, 1867, 935, -1, 902, 1867, 934, -1, 904, 1868, 903, -1, 936, 1868, 904, -1, 935, 1868, 936, -1, 903, 1868, 935, -1, 905, 1869, 904, -1, 937, 1869, 905, -1, 936, 1869, 937, -1, 904, 1869, 936, -1, 906, 1870, 905, -1, 938, 1870, 906, -1, 937, 1870, 938, -1, 905, 1870, 937, -1, 907, 1871, 906, -1, 939, 1871, 907, -1, 938, 1871, 939, -1, 906, 1871, 938, -1, 908, 1872, 907, -1, 940, 1872, 908, -1, 939, 1872, 940, -1, 907, 1872, 939, -1, 909, 1873, 908, -1, 941, 1873, 909, -1, 940, 1873, 941, -1, 908, 1873, 940, -1, 910, 1874, 909, -1, 942, 1874, 910, -1, 941, 1874, 942, -1, 909, 1874, 941, -1, 911, 1875, 910, -1, 943, 1875, 911, -1, 942, 1875, 943, -1, 910, 1875, 942, -1, 912, 1876, 911, -1, 944, 1876, 912, -1, 943, 1876, 944, -1, 911, 1876, 943, -1, 913, 1877, 912, -1, 945, 1877, 913, -1, 944, 1877, 945, -1, 912, 1877, 944, -1, 914, 1878, 913, -1, 946, 1878, 914, -1, 945, 1878, 946, -1, 913, 1878, 945, -1, 915, 1879, 914, -1, 947, 1879, 915, -1, 946, 1879, 947, -1, 914, 1879, 946, -1, 916, 1880, 915, -1, 948, 1880, 916, -1, 947, 1880, 948, -1, 915, 1880, 947, -1, 917, 1881, 916, -1, 949, 1881, 917, -1, 948, 1881, 949, -1, 916, 1881, 948, -1, 918, 1882, 917, -1, 950, 1882, 918, -1, 949, 1882, 950, -1, 917, 1882, 949, -1, 919, 1883, 918, -1, 951, 1883, 919, -1, 950, 1883, 951, -1, 918, 1883, 950, -1, 920, 1884, 919, -1, 952, 1884, 920, -1, 951, 1884, 952, -1, 919, 1884, 951, -1, 921, 1885, 920, -1, 953, 1885, 921, -1, 952, 1885, 953, -1, 920, 1885, 952, -1, 922, 1886, 921, -1, 954, 1886, 922, -1, 953, 1886, 954, -1, 921, 1886, 953, -1, 923, 1887, 922, -1, 955, 1887, 923, -1, 954, 1887, 955, -1, 922, 1887, 954, -1, 924, 1888, 923, -1, 956, 1888, 924, -1, 955, 1888, 956, -1, 923, 1888, 955, -1, 925, 1889, 924, -1, 957, 1889, 925, -1, 956, 1889, 957, -1, 924, 1889, 956, -1, 926, 1890, 925, -1, 958, 1890, 926, -1, 957, 1890, 958, -1, 925, 1890, 957, -1, 927, 1891, 926, -1, 959, 1891, 927, -1, 958, 1891, 959, -1, 926, 1891, 958, -1, 929, 1892, 928, -1, 961, 1892, 929, -1, 960, 1892, 961, -1, 928, 1892, 960, -1, 930, 1893, 929, -1, 962, 1893, 930, -1, 961, 1893, 962, -1, 929, 1893, 961, -1, 931, 1894, 930, -1, 963, 1894, 931, -1, 962, 1894, 963, -1, 930, 1894, 962, -1, 932, 1895, 931, -1, 964, 1895, 932, -1, 963, 1895, 964, -1, 931, 1895, 963, -1, 933, 1896, 932, -1, 965, 1896, 933, -1, 964, 1896, 965, -1, 932, 1896, 964, -1, 934, 1897, 933, -1, 966, 1897, 934, -1, 965, 1897, 966, -1, 933, 1897, 965, -1, 935, 1898, 934, -1, 967, 1898, 935, -1, 966, 1898, 967, -1, 934, 1898, 966, -1, 936, 1899, 935, -1, 968, 1899, 936, -1, 967, 1899, 968, -1, 935, 1899, 967, -1, 937, 1900, 936, -1, 969, 1900, 937, -1, 968, 1900, 969, -1, 936, 1900, 968, -1, 938, 1901, 937, -1, 970, 1901, 938, -1, 969, 1901, 970, -1, 937, 1901, 969, -1, 939, 1902, 938, -1, 971, 1902, 939, -1, 970, 1902, 971, -1, 938, 1902, 970, -1, 940, 1903, 939, -1, 972, 1903, 940, -1, 971, 1903, 972, -1, 939, 1903, 971, -1, 941, 1904, 940, -1, 973, 1904, 941, -1, 972, 1904, 973, -1, 940, 1904, 972, -1, 942, 1905, 941, -1, 974, 1905, 942, -1, 973, 1905, 974, -1, 941, 1905, 973, -1, 943, 1906, 942, -1, 975, 1906, 943, -1, 974, 1906, 975, -1, 942, 1906, 974, -1, 944, 1907, 943, -1, 976, 1907, 944, -1, 975, 1907, 976, -1, 943, 1907, 975, -1, 945, 1908, 944, -1, 977, 1908, 945, -1, 976, 1908, 977, -1, 944, 1908, 976, -1, 946, 1909, 945, -1, 978, 1909, 946, -1, 977, 1909, 978, -1, 945, 1909, 977, -1, 947, 1910, 946, -1, 979, 1910, 947, -1, 978, 1910, 979, -1, 946, 1910, 978, -1, 948, 1911, 947, -1, 980, 1911, 948, -1, 979, 1911, 980, -1, 947, 1911, 979, -1, 949, 1912, 948, -1, 981, 1912, 949, -1, 980, 1912, 981, -1, 948, 1912, 980, -1, 950, 1913, 949, -1, 982, 1913, 950, -1, 981, 1913, 982, -1, 949, 1913, 981, -1, 951, 1914, 950, -1, 983, 1914, 951, -1, 982, 1914, 983, -1, 950, 1914, 982, -1, 952, 1915, 951, -1, 984, 1915, 952, -1, 983, 1915, 984, -1, 951, 1915, 983, -1, 953, 1916, 952, -1, 985, 1916, 953, -1, 984, 1916, 985, -1, 952, 1916, 984, -1, 954, 1917, 953, -1, 986, 1917, 954, -1, 985, 1917, 986, -1, 953, 1917, 985, -1, 955, 1918, 954, -1, 987, 1918, 955, -1, 986, 1918, 987, -1, 954, 1918, 986, -1, 956, 1919, 955, -1, 988, 1919, 956, -1, 987, 1919, 988, -1, 955, 1919, 987, -1, 957, 1920, 956, -1, 989, 1920, 957, -1, 988, 1920, 989, -1, 956, 1920, 988, -1, 958, 1921, 957, -1, 990, 1921, 958, -1, 989, 1921, 990, -1, 957, 1921, 989, -1, 959, 1922, 958, -1, 991, 1922, 959, -1, 990, 1922, 991, -1, 958, 1922, 990, -1, 960, 961, 992, -1, 961, 962, 993, -1, 962, 963, 994, -1, 963, 964, 995, -1, 964, 965, 996, -1, 965, 966, 997, -1, 966, 967, 998, -1, 967, 968, 999, -1, 968, 969, 1000, -1, 969, 970, 1001, -1, 970, 971, 1002, -1, 971, 972, 1003, -1, 972, 973, 1004, -1, 973, 974, 1005, -1, 974, 975, 1006, -1, 975, 976, 1007, -1, 976, 977, 1008, -1, 977, 978, 1009, -1, 978, 979, 1010, -1, 979, 980, 1011, -1, 980, 981, 1012, -1, 981, 982, 1013, -1, 982, 983, 1014, -1, 983, 984, 1015, -1, 984, 985, 1016, -1, 985, 986, 1017, -1, 986, 987, 1018, -1, 987, 988, 1019, -1, 988, 989, 1020, -1, 989, 990, 1021, -1, 990, 991, 1022, -1 };
    NurbsSurface1.normalIndex = m_normalIndex;
    NurbsSurface1.normalIndex_length = sizeof(m_normalIndex) / sizeof(int);
    }
    NurbsSurface1.normalPerVertex = true;
    NurbsSurface1.solid = true;
    {
    static int m_texCoordIndex[] = { 1, 33, 32, -1, 2, 34, 33, -1, 3, 35, 34, -1, 4, 36, 35, -1, 5, 37, 36, -1, 6, 38, 37, -1, 7, 39, 38, -1, 8, 40, 39, -1, 9, 41, 40, -1, 10, 42, 41, -1, 11, 43, 42, -1, 12, 44, 43, -1, 13, 45, 44, -1, 14, 46, 45, -1, 15, 47, 46, -1, 16, 48, 47, -1, 17, 49, 48, -1, 18, 50, 49, -1, 19, 51, 50, -1, 20, 52, 51, -1, 21, 53, 52, -1, 22, 54, 53, -1, 23, 55, 54, -1, 24, 56, 55, -1, 25, 57, 56, -1, 26, 58, 57, -1, 27, 59, 58, -1, 28, 60, 59, -1, 29, 61, 60, -1, 30, 62, 61, -1, 31, 63, 62, -1, 33, 1024, 32, -1, 65, 1024, 33, -1, 64, 1024, 65, -1, 32, 1024, 64, -1, 34, 1025, 33, -1, 66, 1025, 34, -1, 65, 1025, 66, -1, 33, 1025, 65, -1, 35, 1026, 34, -1, 67, 1026, 35, -1, 66, 1026, 67, -1, 34, 1026, 66, -1, 36, 1027, 35, -1, 68, 1027, 36, -1, 67, 1027, 68, -1, 35, 1027, 67, -1, 37, 1028, 36, -1, 69, 1028, 37, -1, 68, 1028, 69, -1, 36, 1028, 68, -1, 38, 1029, 37, -1, 70, 1029, 38, -1, 69, 1029, 70, -1, 37, 1029, 69, -1, 39, 1030, 38, -1, 71, 1030, 39, -1, 70, 1030, 71, -1, 38, 1030, 70, -1, 40, 1031, 39, -1, 72, 1031, 40, -1, 71, 1031, 72, -1, 39, 1031, 71, -1, 41, 1032, 40, -1, 73, 1032, 41, -1, 72, 1032, 73, -1, 40, 1032, 72, -1, 42, 1033, 41, -1, 74, 1033, 42, -1, 73, 1033, 74, -1, 41, 1033, 73, -1, 43, 1034, 42, -1, 75, 1034, 43, -1, 74, 1034, 75, -1, 42, 1034, 74, -1, 44, 1035, 43, -1, 76, 1035, 44, -1, 75, 1035, 76, -1, 43, 1035, 75, -1, 45, 1036, 44, -1, 77, 1036, 45, -1, 76, 1036, 77, -1, 44, 1036, 76, -1, 46, 1037, 45, -1, 78, 1037, 46, -1, 77, 1037, 78, -1, 45, 1037, 77, -1, 47, 1038, 46, -1, 79, 1038, 47, -1, 78, 1038, 79, -1, 46, 1038, 78, -1, 48, 1039, 47, -1, 80, 1039, 48, -1, 79, 1039, 80, -1, 47, 1039, 79, -1, 49, 1040, 48, -1, 81, 1040, 49, -1, 80, 1040, 81, -1, 48, 1040, 80, -1, 50, 1041, 49, -1, 82, 1041, 50, -1, 81, 1041, 82, -1, 49, 1041, 81, -1, 51, 1042, 50, -1, 83, 1042, 51, -1, 82, 1042, 83, -1, 50, 1042, 82, -1, 52, 1043, 51, -1, 84, 1043, 52, -1, 83, 1043, 84, -1, 51, 1043, 83, -1, 53, 1044, 52, -1, 85, 1044, 53, -1, 84, 1044, 85, -1, 52, 1044, 84, -1, 54, 1045, 53, -1, 86, 1045, 54, -1, 85, 1045, 86, -1, 53, 1045, 85, -1, 55, 1046, 54, -1, 87, 1046, 55, -1, 86, 1046, 87, -1, 54, 1046, 86, -1, 56, 1047, 55, -1, 88, 1047, 56, -1, 87, 1047, 88, -1, 55, 1047, 87, -1, 57, 1048, 56, -1, 89, 1048, 57, -1, 88, 1048, 89, -1, 56, 1048, 88, -1, 58, 1049, 57, -1, 90, 1049, 58, -1, 89, 1049, 90, -1, 57, 1049, 89, -1, 59, 1050, 58, -1, 91, 1050, 59, -1, 90, 1050, 91, -1, 58, 1050, 90, -1, 60, 1051, 59, -1, 92, 1051, 60, -1, 91, 1051, 92, -1, 59, 1051, 91, -1, 61, 1052, 60, -1, 93, 1052, 61, -1, 92, 1052, 93, -1, 60, 1052, 92, -1, 62, 1053, 61, -1, 94, 1053, 62, -1, 93, 1053, 94, -1, 61, 1053, 93, -1, 63, 1054, 62, -1, 95, 1054, 63, -1, 94, 1054, 95, -1, 62, 1054, 94, -1, 65, 1055, 64, -1, 97, 1055, 65, -1, 96, 1055, 97, -1, 64, 1055, 96, -1, 66, 1056, 65, -1, 98, 1056, 66, -1, 97, 1056, 98, -1, 65, 1056, 97, -1, 67, 1057, 66, -1, 99, 1057, 67, -1, 98, 1057, 99, -1, 66, 1057, 98, -1, 68, 1058, 67, -1, 100, 1058, 68, -1, 99, 1058, 100, -1, 67, 1058, 99, -1, 69, 1059, 68, -1, 101, 1059, 69, -1, 100, 1059, 101, -1, 68, 1059, 100, -1, 70, 1060, 69, -1, 102, 1060, 70, -1, 101, 1060, 102, -1, 69, 1060, 101, -1, 71, 1061, 70, -1, 103, 1061, 71, -1, 102, 1061, 103, -1, 70, 1061, 102, -1, 72, 1062, 71, -1, 104, 1062, 72, -1, 103, 1062, 104, -1, 71, 1062, 103, -1, 73, 1063, 72, -1, 105, 1063, 73, -1, 104, 1063, 105, -1, 72, 1063, 104, -1, 74, 1064, 73, -1, 106, 1064, 74, -1, 105, 1064, 106, -1, 73, 1064, 105, -1, 75, 1065, 74, -1, 107, 1065, 75, -1, 106, 1065, 107, -1, 74, 1065, 106, -1, 76, 1066, 75, -1, 108, 1066, 76, -1, 107, 1066, 108, -1, 75, 1066, 107, -1, 77, 1067, 76, -1, 109, 1067, 77, -1, 108, 1067, 109, -1, 76, 1067, 108, -1, 78, 1068, 77, -1, 110, 1068, 78, -1, 109, 1068, 110, -1, 77, 1068, 109, -1, 79, 1069, 78, -1, 111, 1069, 79, -1, 110, 1069, 111, -1, 78, 1069, 110, -1, 80, 1070, 79, -1, 112, 1070, 80, -1, 111, 1070, 112, -1, 79, 1070, 111, -1, 81, 1071, 80, -1, 113, 1071, 81, -1, 112, 1071, 113, -1, 80, 1071, 112, -1, 82, 1072, 81, -1, 114, 1072, 82, -1, 113, 1072, 114, -1, 81, 1072, 113, -1, 83, 1073, 82, -1, 115, 1073, 83, -1, 114, 1073, 115, -1, 82, 1073, 114, -1, 84, 1074, 83, -1, 116, 1074, 84, -1, 115, 1074, 116, -1, 83, 1074, 115, -1, 85, 1075, 84, -1, 117, 1075, 85, -1, 116, 1075, 117, -1, 84, 1075, 116, -1, 86, 1076, 85, -1, 118, 1076, 86, -1, 117, 1076, 118, -1, 85, 1076, 117, -1, 87, 1077, 86, -1, 119, 1077, 87, -1, 118, 1077, 119, -1, 86, 1077, 118, -1, 88, 1078, 87, -1, 120, 1078, 88, -1, 119, 1078, 120, -1, 87, 1078, 119, -1, 89, 1079, 88, -1, 121, 1079, 89, -1, 120, 1079, 121, -1, 88, 1079, 120, -1, 90, 1080, 89, -1, 122, 1080, 90, -1, 121, 1080, 122, -1, 89, 1080, 121, -1, 91, 1081, 90, -1, 123, 1081, 91, -1, 122, 1081, 123, -1, 90, 1081, 122, -1, 92, 1082, 91, -1, 124, 1082, 92, -1, 123, 1082, 124, -1, 91, 1082, 123, -1, 93, 1083, 92, -1, 125, 1083, 93, -1, 124, 1083, 125, -1, 92, 1083, 124, -1, 94, 1084, 93, -1, 126, 1084, 94, -1, 125, 1084, 126, -1, 93, 1084, 125, -1, 95, 1085, 94, -1, 127, 1085, 95, -1, 126, 1085, 127, -1, 94, 1085, 126, -1, 97, 1086, 96, -1, 129, 1086, 97, -1, 128, 1086, 129, -1, 96, 1086, 128, -1, 98, 1087, 97, -1, 130, 1087, 98, -1, 129, 1087, 130, -1, 97, 1087, 129, -1, 99, 1088, 98, -1, 131, 1088, 99, -1, 130, 1088, 131, -1, 98, 1088, 130, -1, 100, 1089, 99, -1, 132, 1089, 100, -1, 131, 1089, 132, -1, 99, 1089, 131, -1, 101, 1090, 100, -1, 133, 1090, 101, -1, 132, 1090, 133, -1, 100, 1090, 132, -1, 102, 1091, 101, -1, 134, 1091, 102, -1, 133, 1091, 134, -1, 101, 1091, 133, -1, 103, 1092, 102, -1, 135, 1092, 103, -1, 134, 1092, 135, -1, 102, 1092, 134, -1, 104, 1093, 103, -1, 136, 1093, 104, -1, 135, 1093, 136, -1, 103, 1093, 135, -1, 105, 1094, 104, -1, 137, 1094, 105, -1, 136, 1094, 137, -1, 104, 1094, 136, -1, 106, 1095, 105, -1, 138, 1095, 106, -1, 137, 1095, 138, -1, 105, 1095, 137, -1, 107, 1096, 106, -1, 139, 1096, 107, -1, 138, 1096, 139, -1, 106, 1096, 138, -1, 108, 1097, 107, -1, 140, 1097, 108, -1, 139, 1097, 140, -1, 107, 1097, 139, -1, 109, 1098, 108, -1, 141, 1098, 109, -1, 140, 1098, 141, -1, 108, 1098, 140, -1, 110, 1099, 109, -1, 142, 1099, 110, -1, 141, 1099, 142, -1, 109, 1099, 141, -1, 111, 1100, 110, -1, 143, 1100, 111, -1, 142, 1100, 143, -1, 110, 1100, 142, -1, 112, 1101, 111, -1, 144, 1101, 112, -1, 143, 1101, 144, -1, 111, 1101, 143, -1, 113, 1102, 112, -1, 145, 1102, 113, -1, 144, 1102, 145, -1, 112, 1102, 144, -1, 114, 1103, 113, -1, 146, 1103, 114, -1, 145, 1103, 146, -1, 113, 1103, 145, -1, 115, 1104, 114, -1, 147, 1104, 115, -1, 146, 1104, 147, -1, 114, 1104, 146, -1, 116, 1105, 115, -1, 148, 1105, 116, -1, 147, 1105, 148, -1, 115, 1105, 147, -1, 117, 1106, 116, -1, 149, 1106, 117, -1, 148, 1106, 149, -1, 116, 1106, 148, -1, 118, 1107, 117, -1, 150, 1107, 118, -1, 149, 1107, 150, -1, 117, 1107, 149, -1, 119, 1108, 118, -1, 151, 1108, 119, -1, 150, 1108, 151, -1, 118, 1108, 150, -1, 120, 1109, 119, -1, 152, 1109, 120, -1, 151, 1109, 152, -1, 119, 1109, 151, -1, 121, 1110, 120, -1, 153, 1110, 121, -1, 152, 1110, 153, -1, 120, 1110, 152, -1, 122, 1111, 121, -1, 154, 1111, 122, -1, 153, 1111, 154, -1, 121, 1111, 153, -1, 123, 1112, 122, -1, 155, 1112, 123, -1, 154, 1112, 155, -1, 122, 1112, 154, -1, 124, 1113, 123, -1, 156, 1113, 124, -1, 155, 1113, 156, -1, 123, 1113, 155, -1, 125, 1114, 124, -1, 157, 1114, 125, -1, 156, 1114, 157, -1, 124, 1114, 156, -1, 126, 1115, 125, -1, 158, 1115, 126, -1, 157, 1115, 158, -1, 125, 1115, 157, -1, 127, 1116, 126, -1, 159, 1116, 127, -1, 158, 1116, 159, -1, 126, 1116, 158, -1, 129, 1117, 128, -1, 161, 1117, 129, -1, 160, 1117, 161, -1, 128, 1117, 160, -1, 130, 1118, 129, -1, 162, 1118, 130, -1, 161, 1118, 162, -1, 129, 1118, 161, -1, 131, 1119, 130, -1, 163, 1119, 131, -1, 162, 1119, 163, -1, 130, 1119, 162, -1, 132, 1120, 131, -1, 164, 1120, 132, -1, 163, 1120, 164, -1, 131, 1120, 163, -1, 133, 1121, 132, -1, 165, 1121, 133, -1, 164, 1121, 165, -1, 132, 1121, 164, -1, 134, 1122, 133, -1, 166, 1122, 134, -1, 165, 1122, 166, -1, 133, 1122, 165, -1, 135, 1123, 134, -1, 167, 1123, 135, -1, 166, 1123, 167, -1, 134, 1123, 166, -1, 136, 1124, 135, -1, 168, 1124, 136, -1, 167, 1124, 168, -1, 135, 1124, 167, -1, 137, 1125, 136, -1, 169, 1125, 137, -1, 168, 1125, 169, -1, 136, 1125, 168, -1, 138, 1126, 137, -1, 170, 1126, 138, -1, 169, 1126, 170, -1, 137, 1126, 169, -1, 139, 1127, 138, -1, 171, 1127, 139, -1, 170, 1127, 171, -1, 138, 1127, 170, -1, 140, 1128, 139, -1, 172, 1128, 140, -1, 171, 1128, 172, -1, 139, 1128, 171, -1, 141, 1129, 140, -1, 173, 1129, 141, -1, 172, 1129, 173, -1, 140, 1129, 172, -1, 142, 1130, 141, -1, 174, 1130, 142, -1, 173, 1130, 174, -1, 141, 1130, 173, -1, 143, 1131, 142, -1, 175, 1131, 143, -1, 174, 1131, 175, -1, 142, 1131, 174, -1, 144, 1132, 143, -1, 176, 1132, 144, -1, 175, 1132, 176, -1, 143, 1132, 175, -1, 145, 1133, 144, -1, 177, 1133, 145, -1, 176, 1133, 177, -1, 144, 1133, 176, -1, 146, 1134, 145, -1, 178, 1134, 146, -1, 177, 1134, 178, -1, 145, 1134, 177, -1, 147, 1135, 146, -1, 179, 1135, 147, -1, 178, 1135, 179, -1, 146, 1135, 178, -1, 148, 1136, 147, -1, 180, 1136, 148, -1, 179, 1136, 180, -1, 147, 1136, 179, -1, 149, 1137, 148, -1, 181, 1137, 149, -1, 180, 1137, 181, -1, 148, 1137, 180, -1, 150, 1138, 149, -1, 182, 1138, 150, -1, 181, 1138, 182, -1, 149, 1138, 181, -1, 151, 1139, 150, -1, 183, 1139, 151, -1, 182, 1139, 183, -1, 150, 1139, 182, -1, 152, 1140, 151, -1, 184, 1140, 152, -1, 183, 1140, 184, -1, 151, 1140, 183, -1, 153, 1141, 152, -1, 185, 1141, 153, -1, 184, 1141, 185, -1, 152, 1141, 184, -1, 154, 1142, 153, -1, 186, 1142, 154, -1, 185, 1142, 186, -1, 153, 1142, 185, -1, 155, 1143, 154, -1, 187, 1143, 155, -1, 186, 1143, 187, -1, 154, 1143, 186, -1, 156, 1144, 155, -1, 188, 1144, 156, -1, 187, 1144, 188, -1, 155, 1144, 187, -1, 157, 1145, 156, -1, 189, 1145, 157, -1, 188, 1145, 189, -1, 156, 1145, 188, -1, 158, 1146, 157, -1, 190, 1146, 158, -1, 189, 1146, 190, -1, 157, 1146, 189, -1, 159, 1147, 158, -1, 191, 1147, 159, -1, 190, 1147, 191, -1, 158, 1147, 190, -1, 161, 1148, 160, -1, 193, 1148, 161, -1, 192, 1148, 193, -1, 160, 1148, 192, -1, 162, 1149, 161, -1, 194, 1149, 162, -1, 193, 1149, 194, -1, 161, 1149, 193, -1, 163, 1150, 162, -1, 195, 1150, 163, -1, 194, 1150, 195, -1, 162, 1150, 194, -1, 164, 1151, 163, -1, 196, 1151, 164, -1, 195, 1151, 196, -1, 163, 1151, 195, -1, 165, 1152, 164, -1, 197, 1152, 165, -1, 196, 1152, 197, -1, 164, 1152, 196, -1, 166, 1153, 165, -1, 198, 1153, 166, -1, 197, 1153, 198, -1, 165, 1153, 197, -1, 167, 1154, 166, -1, 199, 1154, 167, -1, 198, 1154, 199, -1, 166, 1154, 198, -1, 168, 1155, 167, -1, 200, 1155, 168, -1, 199, 1155, 200, -1, 167, 1155, 199, -1, 169, 1156, 168, -1, 201, 1156, 169, -1, 200, 1156, 201, -1, 168, 1156, 200, -1, 170, 1157, 169, -1, 202, 1157, 170, -1, 201, 1157, 202, -1, 169, 1157, 201, -1, 171, 1158, 170, -1, 203, 1158, 171, -1, 202, 1158, 203, -1, 170, 1158, 202, -1, 172, 1159, 171, -1, 204, 1159, 172, -1, 203, 1159, 204, -1, 171, 1159, 203, -1, 173, 1160, 172, -1, 205, 1160, 173, -1, 204, 1160, 205, -1, 172, 1160, 204, -1, 174, 1161, 173, -1, 206, 1161, 174, -1, 205, 1161, 206, -1, 173, 1161, 205, -1, 175, 1162, 174, -1, 207, 1162, 175, -1, 206, 1162, 207, -1, 174, 1162, 206, -1, 176, 1163, 175, -1, 208, 1163, 176, -1, 207, 1163, 208, -1, 175, 1163, 207, -1, 177, 1164, 176, -1, 209, 1164, 177, -1, 208, 1164, 209, -1, 176, 1164, 208, -1, 178, 1165, 177, -1, 210, 1165, 178, -1, 209, 1165, 210, -1, 177, 1165, 209, -1, 179, 1166, 178, -1, 211, 1166, 179, -1, 210, 1166, 211, -1, 178, 1166, 210, -1, 180, 1167, 179, -1, 212, 1167, 180, -1, 211, 1167, 212, -1, 179, 1167, 211, -1, 181, 1168, 180, -1, 213, 1168, 181, -1, 212, 1168, 213, -1, 180, 1168, 212, -1, 182, 1169, 181, -1, 214, 1169, 182, -1, 213, 1169, 214, -1, 181, 1169, 213, -1, 183, 1170, 182, -1, 215, 1170, 183, -1, 214, 1170, 215, -1, 182, 1170, 214, -1, 184, 1171, 183, -1, 216, 1171, 184, -1, 215, 1171, 216, -1, 183, 1171, 215, -1, 185, 1172, 184, -1, 217, 1172, 185, -1, 216, 1172, 217, -1, 184, 1172, 216, -1, 186, 1173, 185, -1, 218, 1173, 186, -1, 217, 1173, 218, -1, 185, 1173, 217, -1, 187, 1174, 186, -1, 219, 1174, 187, -1, 218, 1174, 219, -1, 186, 1174, 218, -1, 188, 1175, 187, -1, 220, 1175, 188, -1, 219, 1175, 220, -1, 187, 1175, 219, -1, 189, 1176, 188, -1, 221, 1176, 189, -1, 220, 1176, 221, -1, 188, 1176, 220, -1, 190, 1177, 189, -1, 222, 1177, 190, -1, 221, 1177, 222, -1, 189, 1177, 221, -1, 191, 1178, 190, -1, 223, 1178, 191, -1, 222, 1178, 223, -1, 190, 1178, 222, -1, 193, 1179, 192, -1, 225, 1179, 193, -1, 224, 1179, 225, -1, 192, 1179, 224, -1, 194, 1180, 193, -1, 226, 1180, 194, -1, 225, 1180, 226, -1, 193, 1180, 225, -1, 195, 1181, 194, -1, 227, 1181, 195, -1, 226, 1181, 227, -1, 194, 1181, 226, -1, 196, 1182, 195, -1, 228, 1182, 196, -1, 227, 1182, 228, -1, 195, 1182, 227, -1, 197, 1183, 196, -1, 229, 1183, 197, -1, 228, 1183, 229, -1, 196, 1183, 228, -1, 198, 1184, 197, -1, 230, 1184, 198, -1, 229, 1184, 230, -1, 197, 1184, 229, -1, 199, 1185, 198, -1, 231, 1185, 199, -1, 230, 1185, 231, -1, 198, 1185, 230, -1, 200, 1186, 199, -1, 232, 1186, 200, -1, 231, 1186, 232, -1, 199, 1186, 231, -1, 201, 1187, 200, -1, 233, 1187, 201, -1, 232, 1187, 233, -1, 200, 1187, 232, -1, 202, 1188, 201, -1, 234, 1188, 202, -1, 233, 1188, 234, -1, 201, 1188, 233, -1, 203, 1189, 202, -1, 235, 1189, 203, -1, 234, 1189, 235, -1, 202, 1189, 234, -1, 204, 1190, 203, -1, 236, 1190, 204, -1, 235, 1190, 236, -1, 203, 1190, 235, -1, 205, 1191, 204, -1, 237, 1191, 205, -1, 236, 1191, 237, -1, 204, 1191, 236, -1, 206, 1192, 205, -1, 238, 1192, 206, -1, 237, 1192, 238, -1, 205, 1192, 237, -1, 207, 1193, 206, -1, 239, 1193, 207, -1, 238, 1193, 239, -1, 206, 1193, 238, -1, 208, 1194, 207, -1, 240, 1194, 208, -1, 239, 1194, 240, -1, 207, 1194, 239, -1, 209, 1195, 208, -1, 241, 1195, 209, -1, 240, 1195, 241, -1, 208, 1195, 240, -1, 210, 1196, 209, -1, 242, 1196, 210, -1, 241, 1196, 242, -1, 209, 1196, 241, -1, 211, 1197, 210, -1, 243, 1197, 211, -1, 242, 1197, 243, -1, 210, 1197, 242, -1, 212, 1198, 211, -1, 244, 1198, 212, -1, 243, 1198, 244, -1, 211, 1198, 243, -1, 213, 1199, 212, -1, 245, 1199, 213, -1, 244, 1199, 245, -1, 212, 1199, 244, -1, 214, 1200, 213, -1, 246, 1200, 214, -1, 245, 1200, 246, -1, 213, 1200, 245, -1, 215, 1201, 214, -1, 247, 1201, 215, -1, 246, 1201, 247, -1, 214, 1201, 246, -1, 216, 1202, 215, -1, 248, 1202, 216, -1, 247, 1202, 248, -1, 215, 1202, 247, -1, 217, 1203, 216, -1, 249, 1203, 217, -1, 248, 1203, 249, -1, 216, 1203, 248, -1, 218, 1204, 217, -1, 250, 1204, 218, -1, 249, 1204, 250, -1, 217, 1204, 249, -1, 219, 1205, 218, -1, 251, 1205, 219, -1, 250, 1205, 251, -1, 218, 1205, 250, -1, 220, 1206, 219, -1, 252, 1206, 220, -1, 251, 1206, 252, -1, 219, 1206, 251, -1, 221, 1207, 220, -1, 253, 1207, 221, -1, 252, 1207, 253, -1, 220, 1207, 252, -1, 222, 1208, 221, -1, 254, 1208, 222, -1, 253, 1208, 254, -1, 221, 1208, 253, -1, 223, 1209, 222, -1, 255, 1209, 223, -1, 254, 1209, 255, -1, 222, 1209, 254, -1, 225, 1210, 224, -1, 257, 1210, 225, -1, 256, 1210, 257, -1, 224, 1210, 256, -1, 226, 1211, 225, -1, 258, 1211, 226, -1, 257, 1211, 258, -1, 225, 1211, 257, -1, 227, 1212, 226, -1, 259, 1212, 227, -1, 258, 1212, 259, -1, 226, 1212, 258, -1, 228, 1213, 227, -1, 260, 1213, 228, -1, 259, 1213, 260, -1, 227, 1213, 259, -1, 229, 1214, 228, -1, 261, 1214, 229, -1, 260, 1214, 261, -1, 228, 1214, 260, -1, 230, 1215, 229, -1, 262, 1215, 230, -1, 261, 1215, 262, -1, 229, 1215, 261, -1, 231, 1216, 230, -1, 263, 1216, 231, -1, 262, 1216, 263, -1, 230, 1216, 262, -1, 232, 1217, 231, -1, 264, 1217, 232, -1, 263, 1217, 264, -1, 231, 1217, 263, -1, 233, 1218, 232, -1, 265, 1218, 233, -1, 264, 1218, 265, -1, 232, 1218, 264, -1, 234, 1219, 233, -1, 266, 1219, 234, -1, 265, 1219, 266, -1, 233, 1219, 265, -1, 235, 1220, 234, -1, 267, 1220, 235, -1, 266, 1220, 267, -1, 234, 1220, 266, -1, 236, 1221, 235, -1, 268, 1221, 236, -1, 267, 1221, 268, -1, 235, 1221, 267, -1, 237, 1222, 236, -1, 269, 1222, 237, -1, 268, 1222, 269, -1, 236, 1222, 268, -1, 238, 1223, 237, -1, 270, 1223, 238, -1, 269, 1223, 270, -1, 237, 1223, 269, -1, 239, 1224, 238, -1, 271, 1224, 239, -1, 270, 1224, 271, -1, 238, 1224, 270, -1, 240, 1225, 239, -1, 272, 1225, 240, -1, 271, 1225, 272, -1, 239, 1225, 271, -1, 241, 1226, 240, -1, 273, 1226, 241, -1, 272, 1226, 273, -1, 240, 1226, 272, -1, 242, 1227, 241, -1, 274, 1227, 242, -1, 273, 1227, 274, -1, 241, 1227, 273, -1, 243, 1228, 242, -1, 275, 1228, 243, -1, 274, 1228, 275, -1, 242, 1228, 274, -1, 244, 1229, 243, -1, 276, 1229, 244, -1, 275, 1229, 276, -1, 243, 1229, 275, -1, 245, 1230, 244, -1, 277, 1230, 245, -1, 276, 1230, 277, -1, 244, 1230, 276, -1, 246, 1231, 245, -1, 278, 1231, 246, -1, 277, 1231, 278, -1, 245, 1231, 277, -1, 247, 1232, 246, -1, 279, 1232, 247, -1, 278, 1232, 279, -1, 246, 1232, 278, -1, 248, 1233, 247, -1, 280, 1233, 248, -1, 279, 1233, 280, -1, 247, 1233, 279, -1, 249, 1234, 248, -1, 281, 1234, 249, -1, 280, 1234, 281, -1, 248, 1234, 280, -1, 250, 1235, 249, -1, 282, 1235, 250, -1, 281, 1235, 282, -1, 249, 1235, 281, -1, 251, 1236, 250, -1, 283, 1236, 251, -1, 282, 1236, 283, -1, 250, 1236, 282, -1, 252, 1237, 251, -1, 284, 1237, 252, -1, 283, 1237, 284, -1, 251, 1237, 283, -1, 253, 1238, 252, -1, 285, 1238, 253, -1, 284, 1238, 285, -1, 252, 1238, 284, -1, 254, 1239, 253, -1, 286, 1239, 254, -1, 285, 1239, 286, -1, 253, 1239, 285, -1, 255, 1240, 254, -1, 287, 1240, 255, -1, 286, 1240, 287, -1, 254, 1240, 286, -1, 257, 1241, 256, -1, 289, 1241, 257, -1, 288, 1241, 289, -1, 256, 1241, 288, -1, 258, 1242, 257, -1, 290, 1242, 258, -1, 289, 1242, 290, -1, 257, 1242, 289, -1, 259, 1243, 258, -1, 291, 1243, 259, -1, 290, 1243, 291, -1, 258, 1243, 290, -1, 260, 1244, 259, -1, 292, 1244, 260, -1, 291, 1244, 292, -1, 259, 1244, 291, -1, 261, 1245, 260, -1, 293, 1245, 261, -1, 292, 1245, 293, -1, 260, 1245, 292, -1, 262, 1246, 261, -1, 294, 1246, 262, -1, 293, 1246, 294, -1, 261, 1246, 293, -1, 263, 1247, 262, -1, 295, 1247, 263, -1, 294, 1247, 295, -1, 262, 1247, 294, -1, 264, 1248, 263, -1, 296, 1248, 264, -1, 295, 1248, 296, -1, 263, 1248, 295, -1, 265, 1249, 264, -1, 297, 1249, 265, -1, 296, 1249, 297, -1, 264, 1249, 296, -1, 266, 1250, 265, -1, 298, 1250, 266, -1, 297, 1250, 298, -1, 265, 1250, 297, -1, 267, 1251, 266, -1, 299, 1251, 267, -1, 298, 1251, 299, -1, 266, 1251, 298, -1, 268, 1252, 267, -1, 300, 1252, 268, -1, 299, 1252, 300, -1, 267, 1252, 299, -1, 269, 1253, 268, -1, 301, 1253, 269, -1, 300, 1253, 301, -1, 268, 1253, 300, -1, 270, 1254, 269, -1, 302, 1254, 270, -1, 301, 1254, 302, -1, 269, 1254, 301, -1, 271, 1255, 270, -1, 303, 1255, 271, -1, 302, 1255, 303, -1, 270, 1255, 302, -1, 272, 1256, 271, -1, 304, 1256, 272, -1, 303, 1256, 304, -1, 271, 1256, 303, -1, 273, 1257, 272, -1, 305, 1257, 273, -1, 304, 1257, 305, -1, 272, 1257, 304, -1, 274, 1258, 273, -1, 306, 1258, 274, -1, 305, 1258, 306, -1, 273, 1258, 305, -1, 275, 1259, 274, -1, 307, 1259, 275, -1, 306, 1259, 307, -1, 274, 1259, 306, -1, 276, 1260, 275, -1, 308, 1260, 276, -1, 307, 1260, 308, -1, 275, 1260, 307, -1, 277, 1261, 276, -1, 309, 1261, 277, -1, 308, 1261, 309, -1, 276, 1261, 308, -1, 278, 1262, 277, -1, 310, 1262, 278, -1, 309, 1262, 310, -1, 277, 1262, 309, -1, 279, 1263, 278, -1, 311, 1263, 279, -1, 310, 1263, 311, -1, 278, 1263, 310, -1, 280, 1264, 279, -1, 312, 1264, 280, -1, 311, 1264, 312, -1, 279, 1264, 311, -1, 281, 1265, 280, -1, 313, 1265, 281, -1, 312, 1265, 313, -1, 280, 1265, 312, -1, 282, 1266, 281, -1, 314, 1266, 282, -1, 313, 1266, 314, -1, 281, 1266, 313, -1, 283, 1267, 282, -1, 315, 1267, 283, -1, 314, 1267, 315, -1, 282, 1267, 314, -1, 284, 1268, 283, -1, 316, 1268, 284, -1, 315, 1268, 316, -1, 283, 1268, 315, -1, 285, 1269, 284, -1, 317, 1269, 285, -1, 316, 1269, 317, -1, 284, 1269, 316, -1, 286, 1270, 285, -1, 318, 1270, 286, -1, 317, 1270, 318, -1, 285, 1270, 317, -1, 287, 1271, 286, -1, 319, 1271, 287, -1, 318, 1271, 319, -1, 286, 1271, 318, -1, 289, 1272, 288, -1, 321, 1272, 289, -1, 320, 1272, 321, -1, 288, 1272, 320, -1, 290, 1273, 289, -1, 322, 1273, 290, -1, 321, 1273, 322, -1, 289, 1273, 321, -1, 291, 1274, 290, -1, 323, 1274, 291, -1, 322, 1274, 323, -1, 290, 1274, 322, -1, 292, 1275, 291, -1, 324, 1275, 292, -1, 323, 1275, 324, -1, 291, 1275, 323, -1, 293, 1276, 292, -1, 325, 1276, 293, -1, 324, 1276, 325, -1, 292, 1276, 324, -1, 294, 1277, 293, -1, 326, 1277, 294, -1, 325, 1277, 326, -1, 293, 1277, 325, -1, 295, 1278, 294, -1, 327, 1278, 295, -1, 326, 1278, 327, -1, 294, 1278, 326, -1, 296, 1279, 295, -1, 328, 1279, 296, -1, 327, 1279, 328, -1, 295, 1279, 327, -1, 297, 1280, 296, -1, 329, 1280, 297, -1, 328, 1280, 329, -1, 296, 1280, 328, -1, 298, 1281, 297, -1, 330, 1281, 298, -1, 329, 1281, 330, -1, 297, 1281, 329, -1, 299, 1282, 298, -1, 331, 1282, 299, -1, 330, 1282, 331, -1, 298, 1282, 330, -1, 300, 1283, 299, -1, 332, 1283, 300, -1, 331, 1283, 332, -1, 299, 1283, 331, -1, 301, 1284, 300, -1, 333, 1284, 301, -1, 332, 1284, 333, -1, 300, 1284, 332, -1, 302, 1285, 301, -1, 334, 1285, 302, -1, 333, 1285, 334, -1, 301, 1285, 333, -1, 303, 1286, 302, -1, 335, 1286, 303, -1, 334, 1286, 335, -1, 302, 1286, 334, -1, 304, 1287, 303, -1, 336, 1287, 304, -1, 335, 1287, 336, -1, 303, 1287, 335, -1, 305, 1288, 304, -1, 337, 1288, 305, -1, 336, 1288, 337, -1, 304, 1288, 336, -1, 306, 1289, 305, -1, 338, 1289, 306, -1, 337, 1289, 338, -1, 305, 1289, 337, -1, 307, 1290, 306, -1, 339, 1290, 307, -1, 338, 1290, 339, -1, 306, 1290, 338, -1, 308, 1291, 307, -1, 340, 1291, 308, -1, 339, 1291, 340, -1, 307, 1291, 339, -1, 309, 1292, 308, -1, 341, 1292, 309, -1, 340, 1292, 341, -1, 308, 1292, 340, -1, 310, 1293, 309, -1, 342, 1293, 310, -1, 341, 1293, 342, -1, 309, 1293, 341, -1, 311, 1294, 310, -1, 343, 1294, 311, -1, 342, 1294, 343, -1, 310, 1294, 342, -1, 312, 1295, 311, -1, 344, 1295, 312, -1, 343, 1295, 344, -1, 311, 1295, 343, -1, 313, 1296, 312, -1, 345, 1296, 313, -1, 344, 1296, 345, -1, 312, 1296, 344, -1, 314, 1297, 313, -1, 346, 1297, 314, -1, 345, 1297, 346, -1, 313, 1297, 345, -1, 315, 1298, 314, -1, 347, 1298, 315, -1, 346, 1298, 347, -1, 314, 1298, 346, -1, 316, 1299, 315, -1, 348, 1299, 316, -1, 347, 1299, 348, -1, 315, 1299, 347, -1, 317, 1300, 316, -1, 349, 1300, 317, -1, 348, 1300, 349, -1, 316, 1300, 348, -1, 318, 1301, 317, -1, 350, 1301, 318, -1, 349, 1301, 350, -1, 317, 1301, 349, -1, 319, 1302, 318, -1, 351, 1302, 319, -1, 350, 1302, 351, -1, 318, 1302, 350, -1, 321, 1303, 320, -1, 353, 1303, 321, -1, 352, 1303, 353, -1, 320, 1303, 352, -1, 322, 1304, 321, -1, 354, 1304, 322, -1, 353, 1304, 354, -1, 321, 1304, 353, -1, 323, 1305, 322, -1, 355, 1305, 323, -1, 354, 1305, 355, -1, 322, 1305, 354, -1, 324, 1306, 323, -1, 356, 1306, 324, -1, 355, 1306, 356, -1, 323, 1306, 355, -1, 325, 1307, 324, -1, 357, 1307, 325, -1, 356, 1307, 357, -1, 324, 1307, 356, -1, 326, 1308, 325, -1, 358, 1308, 326, -1, 357, 1308, 358, -1, 325, 1308, 357, -1, 327, 1309, 326, -1, 359, 1309, 327, -1, 358, 1309, 359, -1, 326, 1309, 358, -1, 328, 1310, 327, -1, 360, 1310, 328, -1, 359, 1310, 360, -1, 327, 1310, 359, -1, 329, 1311, 328, -1, 361, 1311, 329, -1, 360, 1311, 361, -1, 328, 1311, 360, -1, 330, 1312, 329, -1, 362, 1312, 330, -1, 361, 1312, 362, -1, 329, 1312, 361, -1, 331, 1313, 330, -1, 363, 1313, 331, -1, 362, 1313, 363, -1, 330, 1313, 362, -1, 332, 1314, 331, -1, 364, 1314, 332, -1, 363, 1314, 364, -1, 331, 1314, 363, -1, 333, 1315, 332, -1, 365, 1315, 333, -1, 364, 1315, 365, -1, 332, 1315, 364, -1, 334, 1316, 333, -1, 366, 1316, 334, -1, 365, 1316, 366, -1, 333, 1316, 365, -1, 335, 1317, 334, -1, 367, 1317, 335, -1, 366, 1317, 367, -1, 334, 1317, 366, -1, 336, 1318, 335, -1, 368, 1318, 336, -1, 367, 1318, 368, -1, 335, 1318, 367, -1, 337, 1319, 336, -1, 369, 1319, 337, -1, 368, 1319, 369, -1, 336, 1319, 368, -1, 338, 1320, 337, -1, 370, 1320, 338, -1, 369, 1320, 370, -1, 337, 1320, 369, -1, 339, 1321, 338, -1, 371, 1321, 339, -1, 370, 1321, 371, -1, 338, 1321, 370, -1, 340, 1322, 339, -1, 372, 1322, 340, -1, 371, 1322, 372, -1, 339, 1322, 371, -1, 341, 1323, 340, -1, 373, 1323, 341, -1, 372, 1323, 373, -1, 340, 1323, 372, -1, 342, 1324, 341, -1, 374, 1324, 342, -1, 373, 1324, 374, -1, 341, 1324, 373, -1, 343, 1325, 342, -1, 375, 1325, 343, -1, 374, 1325, 375, -1, 342, 1325, 374, -1, 344, 1326, 343, -1, 376, 1326, 344, -1, 375, 1326, 376, -1, 343, 1326, 375, -1, 345, 1327, 344, -1, 377, 1327, 345, -1, 376, 1327, 377, -1, 344, 1327, 376, -1, 346, 1328, 345, -1, 378, 1328, 346, -1, 377, 1328, 378, -1, 345, 1328, 377, -1, 347, 1329, 346, -1, 379, 1329, 347, -1, 378, 1329, 379, -1, 346, 1329, 378, -1, 348, 1330, 347, -1, 380, 1330, 348, -1, 379, 1330, 380, -1, 347, 1330, 379, -1, 349, 1331, 348, -1, 381, 1331, 349, -1, 380, 1331, 381, -1, 348, 1331, 380, -1, 350, 1332, 349, -1, 382, 1332, 350, -1, 381, 1332, 382, -1, 349, 1332, 381, -1, 351, 1333, 350, -1, 383, 1333, 351, -1, 382, 1333, 383, -1, 350, 1333, 382, -1, 353, 1334, 352, -1, 385, 1334, 353, -1, 384, 1334, 385, -1, 352, 1334, 384, -1, 354, 1335, 353, -1, 386, 1335, 354, -1, 385, 1335, 386, -1, 353, 1335, 385, -1, 355, 1336, 354, -1, 387, 1336, 355, -1, 386, 1336, 387, -1, 354, 1336, 386, -1, 356, 1337, 355, -1, 388, 1337, 356, -1, 387, 1337, 388, -1, 355, 1337, 387, -1, 357, 1338, 356, -1, 389, 1338, 357, -1, 388, 1338, 389, -1, 356, 1338, 388, -1, 358, 1339, 357, -1, 390, 1339, 358, -1, 389, 1339, 390, -1, 357, 1339, 389, -1, 359, 1340, 358, -1, 391, 1340, 359, -1, 390, 1340, 391, -1, 358, 1340, 390, -1, 360, 1341, 359, -1, 392, 1341, 360, -1, 391, 1341, 392, -1, 359, 1341, 391, -1, 361, 1342, 360, -1, 393, 1342, 361, -1, 392, 1342, 393, -1, 360, 1342, 392, -1, 362, 1343, 361, -1, 394, 1343, 362, -1, 393, 1343, 394, -1, 361, 1343, 393, -1, 363, 1344, 362, -1, 395, 1344, 363, -1, 394, 1344, 395, -1, 362, 1344, 394, -1, 364, 1345, 363, -1, 396, 1345, 364, -1, 395, 1345, 396, -1, 363, 1345, 395, -1, 365, 1346, 364, -1, 397, 1346, 365, -1, 396, 1346, 397, -1, 364, 1346, 396, -1, 366, 1347, 365, -1, 398, 1347, 366, -1, 397, 1347, 398, -1, 365, 1347, 397, -1, 367, 1348, 366, -1, 399, 1348, 367, -1, 398, 1348, 399, -1, 366, 1348, 398, -1, 368, 1349, 367, -1, 400, 1349, 368, -1, 399, 1349, 400, -1, 367, 1349, 399, -1, 369, 1350, 368, -1, 401, 1350, 369, -1, 400, 1350, 401, -1, 368, 1350, 400, -1, 370, 1351, 369, -1, 402, 1351, 370, -1, 401, 1351, 402, -1, 369, 1351, 401, -1, 371, 1352, 370, -1, 403, 1352, 371, -1, 402, 1352, 403, -1, 370, 1352, 402, -1, 372, 1353, 371, -1, 404, 1353, 372, -1, 403, 1353, 404, -1, 371, 1353, 403, -1, 373, 1354, 372, -1, 405, 1354, 373, -1, 404, 1354, 405, -1, 372, 1354, 404, -1, 374, 1355, 373, -1, 406, 1355, 374, -1, 405, 1355, 406, -1, 373, 1355, 405, -1, 375, 1356, 374, -1, 407, 1356, 375, -1, 406, 1356, 407, -1, 374, 1356, 406, -1, 376, 1357, 375, -1, 408, 1357, 376, -1, 407, 1357, 408, -1, 375, 1357, 407, -1, 377, 1358, 376, -1, 409, 1358, 377, -1, 408, 1358, 409, -1, 376, 1358, 408, -1, 378, 1359, 377, -1, 410, 1359, 378, -1, 409, 1359, 410, -1, 377, 1359, 409, -1, 379, 1360, 378, -1, 411, 1360, 379, -1, 410, 1360, 411, -1, 378, 1360, 410, -1, 380, 1361, 379, -1, 412, 1361, 380, -1, 411, 1361, 412, -1, 379, 1361, 411, -1, 381, 1362, 380, -1, 413, 1362, 381, -1, 412, 1362, 413, -1, 380, 1362, 412, -1, 382, 1363, 381, -1, 414, 1363, 382, -1, 413, 1363, 414, -1, 381, 1363, 413, -1, 383, 1364, 382, -1, 415, 1364, 383, -1, 414, 1364, 415, -1, 382, 1364, 414, -1, 385, 1365, 384, -1, 417, 1365, 385, -1, 416, 1365, 417, -1, 384, 1365, 416, -1, 386, 1366, 385, -1, 418, 1366, 386, -1, 417, 1366, 418, -1, 385, 1366, 417, -1, 387, 1367, 386, -1, 419, 1367, 387, -1, 418, 1367, 419, -1, 386, 1367, 418, -1, 388, 1368, 387, -1, 420, 1368, 388, -1, 419, 1368, 420, -1, 387, 1368, 419, -1, 389, 1369, 388, -1, 421, 1369, 389, -1, 420, 1369, 421, -1, 388, 1369, 420, -1, 390, 1370, 389, -1, 422, 1370, 390, -1, 421, 1370, 422, -1, 389, 1370, 421, -1, 391, 1371, 390, -1, 423, 1371, 391, -1, 422, 1371, 423, -1, 390, 1371, 422, -1, 392, 1372, 391, -1, 424, 1372, 392, -1, 423, 1372, 424, -1, 391, 1372, 423, -1, 393, 1373, 392, -1, 425, 1373, 393, -1, 424, 1373, 425, -1, 392, 1373, 424, -1, 394, 1374, 393, -1, 426, 1374, 394, -1, 425, 1374, 426, -1, 393, 1374, 425, -1, 395, 1375, 394, -1, 427, 1375, 395, -1, 426, 1375, 427, -1, 394, 1375, 426, -1, 396, 1376, 395, -1, 428, 1376, 396, -1, 427, 1376, 428, -1, 395, 1376, 427, -1, 397, 1377, 396, -1, 429, 1377, 397, -1, 428, 1377, 429, -1, 396, 1377, 428, -1, 398, 1378, 397, -1, 430, 1378, 398, -1, 429, 1378, 430, -1, 397, 1378, 429, -1, 399, 1379, 398, -1, 431, 1379, 399, -1, 430, 1379, 431, -1, 398, 1379, 430, -1, 400, 1380, 399, -1, 432, 1380, 400, -1, 431, 1380, 432, -1, 399, 1380, 431, -1, 401, 1381, 400, -1, 433, 1381, 401, -1, 432, 1381, 433, -1, 400, 1381, 432, -1, 402, 1382, 401, -1, 434, 1382, 402, -1, 433, 1382, 434, -1, 401, 1382, 433, -1, 403, 1383, 402, -1, 435, 1383, 403, -1, 434, 1383, 435, -1, 402, 1383, 434, -1, 404, 1384, 403, -1, 436, 1384, 404, -1, 435, 1384, 436, -1, 403, 1384, 435, -1, 405, 1385, 404, -1, 437, 1385, 405, -1, 436, 1385, 437, -1, 404, 1385, 436, -1, 406, 1386, 405, -1, 438, 1386, 406, -1, 437, 1386, 438, -1, 405, 1386, 437, -1, 407, 1387, 406, -1, 439, 1387, 407, -1, 438, 1387, 439, -1, 406, 1387, 438, -1, 408, 1388, 407, -1, 440, 1388, 408, -1, 439, 1388, 440, -1, 407, 1388, 439, -1, 409, 1389, 408, -1, 441, 1389, 409, -1, 440, 1389, 441, -1, 408, 1389, 440, -1, 410, 1390, 409, -1, 442, 1390, 410, -1, 441, 1390, 442, -1, 409, 1390, 441, -1, 411, 1391, 410, -1, 443, 1391, 411, -1, 442, 1391, 443, -1, 410, 1391, 442, -1, 412, 1392, 411, -1, 444, 1392, 412, -1, 443, 1392, 444, -1, 411, 1392, 443, -1, 413, 1393, 412, -1, 445, 1393, 413, -1, 444, 1393, 445, -1, 412, 1393, 444, -1, 414, 1394, 413, -1, 446, 1394, 414, -1, 445, 1394, 446, -1, 413, 1394, 445, -1, 415, 1395, 414, -1, 447, 1395, 415, -1, 446, 1395, 447, -1, 414, 1395, 446, -1, 417, 1396, 416, -1, 449, 1396, 417, -1, 448, 1396, 449, -1, 416, 1396, 448, -1, 418, 1397, 417, -1, 450, 1397, 418, -1, 449, 1397, 450, -1, 417, 1397, 449, -1, 419, 1398, 418, -1, 451, 1398, 419, -1, 450, 1398, 451, -1, 418, 1398, 450, -1, 420, 1399, 419, -1, 452, 1399, 420, -1, 451, 1399, 452, -1, 419, 1399, 451, -1, 421, 1400, 420, -1, 453, 1400, 421, -1, 452, 1400, 453, -1, 420, 1400, 452, -1, 422, 1401, 421, -1, 454, 1401, 422, -1, 453, 1401, 454, -1, 421, 1401, 453, -1, 423, 1402, 422, -1, 455, 1402, 423, -1, 454, 1402, 455, -1, 422, 1402, 454, -1, 424, 1403, 423, -1, 456, 1403, 424, -1, 455, 1403, 456, -1, 423, 1403, 455, -1, 425, 1404, 424, -1, 457, 1404, 425, -1, 456, 1404, 457, -1, 424, 1404, 456, -1, 426, 1405, 425, -1, 458, 1405, 426, -1, 457, 1405, 458, -1, 425, 1405, 457, -1, 427, 1406, 426, -1, 459, 1406, 427, -1, 458, 1406, 459, -1, 426, 1406, 458, -1, 428, 1407, 427, -1, 460, 1407, 428, -1, 459, 1407, 460, -1, 427, 1407, 459, -1, 429, 1408, 428, -1, 461, 1408, 429, -1, 460, 1408, 461, -1, 428, 1408, 460, -1, 430, 1409, 429, -1, 462, 1409, 430, -1, 461, 1409, 462, -1, 429, 1409, 461, -1, 431, 1410, 430, -1, 463, 1410, 431, -1, 462, 1410, 463, -1, 430, 1410, 462, -1, 432, 1411, 431, -1, 464, 1411, 432, -1, 463, 1411, 464, -1, 431, 1411, 463, -1, 433, 1412, 432, -1, 465, 1412, 433, -1, 464, 1412, 465, -1, 432, 1412, 464, -1, 434, 1413, 433, -1, 466, 1413, 434, -1, 465, 1413, 466, -1, 433, 1413, 465, -1, 435, 1414, 434, -1, 467, 1414, 435, -1, 466, 1414, 467, -1, 434, 1414, 466, -1, 436, 1415, 435, -1, 468, 1415, 436, -1, 467, 1415, 468, -1, 435, 1415, 467, -1, 437, 1416, 436, -1, 469, 1416, 437, -1, 468, 1416, 469, -1, 436, 1416, 468, -1, 438, 1417, 437, -1, 470, 1417, 438, -1, 469, 1417, 470, -1, 437, 1417, 469, -1, 439, 1418, 438, -1, 471, 1418, 439, -1, 470, 1418, 471, -1, 438, 1418, 470, -1, 440, 1419, 439, -1, 472, 1419, 440, -1, 471, 1419, 472, -1, 439, 1419, 471, -1, 441, 1420, 440, -1, 473, 1420, 441, -1, 472, 1420, 473, -1, 440, 1420, 472, -1, 442, 1421, 441, -1, 474, 1421, 442, -1, 473, 1421, 474, -1, 441, 1421, 473, -1, 443, 1422, 442, -1, 475, 1422, 443, -1, 474, 1422, 475, -1, 442, 1422, 474, -1, 444, 1423, 443, -1, 476, 1423, 444, -1, 475, 1423, 476, -1, 443, 1423, 475, -1, 445, 1424, 444, -1, 477, 1424, 445, -1, 476, 1424, 477, -1, 444, 1424, 476, -1, 446, 1425, 445, -1, 478, 1425, 446, -1, 477, 1425, 478, -1, 445, 1425, 477, -1, 447, 1426, 446, -1, 479, 1426, 447, -1, 478, 1426, 479, -1, 446, 1426, 478, -1, 449, 1427, 448, -1, 481, 1427, 449, -1, 480, 1427, 481, -1, 448, 1427, 480, -1, 450, 1428, 449, -1, 482, 1428, 450, -1, 481, 1428, 482, -1, 449, 1428, 481, -1, 451, 1429, 450, -1, 483, 1429, 451, -1, 482, 1429, 483, -1, 450, 1429, 482, -1, 452, 1430, 451, -1, 484, 1430, 452, -1, 483, 1430, 484, -1, 451, 1430, 483, -1, 453, 1431, 452, -1, 485, 1431, 453, -1, 484, 1431, 485, -1, 452, 1431, 484, -1, 454, 1432, 453, -1, 486, 1432, 454, -1, 485, 1432, 486, -1, 453, 1432, 485, -1, 455, 1433, 454, -1, 487, 1433, 455, -1, 486, 1433, 487, -1, 454, 1433, 486, -1, 456, 1434, 455, -1, 488, 1434, 456, -1, 487, 1434, 488, -1, 455, 1434, 487, -1, 457, 1435, 456, -1, 489, 1435, 457, -1, 488, 1435, 489, -1, 456, 1435, 488, -1, 458, 1436, 457, -1, 490, 1436, 458, -1, 489, 1436, 490, -1, 457, 1436, 489, -1, 459, 1437, 458, -1, 491, 1437, 459, -1, 490, 1437, 491, -1, 458, 1437, 490, -1, 460, 1438, 459, -1, 492, 1438, 460, -1, 491, 1438, 492, -1, 459, 1438, 491, -1, 461, 1439, 460, -1, 493, 1439, 461, -1, 492, 1439, 493, -1, 460, 1439, 492, -1, 462, 1440, 461, -1, 494, 1440, 462, -1, 493, 1440, 494, -1, 461, 1440, 493, -1, 463, 1441, 462, -1, 495, 1441, 463, -1, 494, 1441, 495, -1, 462, 1441, 494, -1, 464, 1442, 463, -1, 496, 1442, 464, -1, 495, 1442, 496, -1, 463, 1442, 495, -1, 465, 1443, 464, -1, 497, 1443, 465, -1, 496, 1443, 497, -1, 464, 1443, 496, -1, 466, 1444, 465, -1, 498, 1444, 466, -1, 497, 1444, 498, -1, 465, 1444, 497, -1, 467, 1445, 466, -1, 499, 1445, 467, -1, 498, 1445, 499, -1, 466, 1445, 498, -1, 468, 1446, 467, -1, 500, 1446, 468, -1, 499, 1446, 500, -1, 467, 1446, 499, -1, 469, 1447, 468, -1, 501, 1447, 469, -1, 500, 1447, 501, -1, 468, 1447, 500, -1, 470, 1448, 469, -1, 502, 1448, 470, -1, 501, 1448, 502, -1, 469, 1448, 501, -1, 471, 1449, 470, -1, 503, 1449, 471, -1, 502, 1449, 503, -1, 470, 1449, 502, -1, 472, 1450, 471, -1, 504, 1450, 472, -1, 503, 1450, 504, -1, 471, 1450, 503, -1, 473, 1451, 472, -1, 505, 1451, 473, -1, 504, 1451, 505, -1, 472, 1451, 504, -1, 474, 1452, 473, -1, 506, 1452, 474, -1, 505, 1452, 506, -1, 473, 1452, 505, -1, 475, 1453, 474, -1, 507, 1453, 475, -1, 506, 1453, 507, -1, 474, 1453, 506, -1, 476, 1454, 475, -1, 508, 1454, 476, -1, 507, 1454, 508, -1, 475, 1454, 507, -1, 477, 1455, 476, -1, 509, 1455, 477, -1, 508, 1455, 509, -1, 476, 1455, 508, -1, 478, 1456, 477, -1, 510, 1456, 478, -1, 509, 1456, 510, -1, 477, 1456, 509, -1, 479, 1457, 478, -1, 511, 1457, 479, -1, 510, 1457, 511, -1, 478, 1457, 510, -1, 481, 1458, 480, -1, 513, 1458, 481, -1, 512, 1458, 513, -1, 480, 1458, 512, -1, 482, 1459, 481, -1, 514, 1459, 482, -1, 513, 1459, 514, -1, 481, 1459, 513, -1, 483, 1460, 482, -1, 515, 1460, 483, -1, 514, 1460, 515, -1, 482, 1460, 514, -1, 484, 1461, 483, -1, 516, 1461, 484, -1, 515, 1461, 516, -1, 483, 1461, 515, -1, 485, 1462, 484, -1, 517, 1462, 485, -1, 516, 1462, 517, -1, 484, 1462, 516, -1, 486, 1463, 485, -1, 518, 1463, 486, -1, 517, 1463, 518, -1, 485, 1463, 517, -1, 487, 1464, 486, -1, 519, 1464, 487, -1, 518, 1464, 519, -1, 486, 1464, 518, -1, 488, 1465, 487, -1, 520, 1465, 488, -1, 519, 1465, 520, -1, 487, 1465, 519, -1, 489, 1466, 488, -1, 521, 1466, 489, -1, 520, 1466, 521, -1, 488, 1466, 520, -1, 490, 1467, 489, -1, 522, 1467, 490, -1, 521, 1467, 522, -1, 489, 1467, 521, -1, 491, 1468, 490, -1, 523, 1468, 491, -1, 522, 1468, 523, -1, 490, 1468, 522, -1, 492, 1469, 491, -1, 524, 1469, 492, -1, 523, 1469, 524, -1, 491, 1469, 523, -1, 493, 1470, 492, -1, 525, 1470, 493, -1, 524, 1470, 525, -1, 492, 1470, 524, -1, 494, 1471, 493, -1, 526, 1471, 494, -1, 525, 1471, 526, -1, 493, 1471, 525, -1, 495, 1472, 494, -1, 527, 1472, 495, -1, 526, 1472, 527, -1, 494, 1472, 526, -1, 496, 1473, 495, -1, 528, 1473, 496, -1, 527, 1473, 528, -1, 495, 1473, 527, -1, 497, 1474, 496, -1, 529, 1474, 497, -1, 528, 1474, 529, -1, 496, 1474, 528, -1, 498, 1475, 497, -1, 530, 1475, 498, -1, 529, 1475, 530, -1, 497, 1475, 529, -1, 499, 1476, 498, -1, 531, 1476, 499, -1, 530, 1476, 531, -1, 498, 1476, 530, -1, 500, 1477, 499, -1, 532, 1477, 500, -1, 531, 1477, 532, -1, 499, 1477, 531, -1, 501, 1478, 500, -1, 533, 1478, 501, -1, 532, 1478, 533, -1, 500, 1478, 532, -1, 502, 1479, 501, -1, 534, 1479, 502, -1, 533, 1479, 534, -1, 501, 1479, 533, -1, 503, 1480, 502, -1, 535, 1480, 503, -1, 534, 1480, 535, -1, 502, 1480, 534, -1, 504, 1481, 503, -1, 536, 1481, 504, -1, 535, 1481, 536, -1, 503, 1481, 535, -1, 505, 1482, 504, -1, 537, 1482, 505, -1, 536, 1482, 537, -1, 504, 1482, 536, -1, 506, 1483, 505, -1, 538, 1483, 506, -1, 537, 1483, 538, -1, 505, 1483, 537, -1, 507, 1484, 506, -1, 539, 1484, 507, -1, 538, 1484, 539, -1, 506, 1484, 538, -1, 508, 1485, 507, -1, 540, 1485, 508, -1, 539, 1485, 540, -1, 507, 1485, 539, -1, 509, 1486, 508, -1, 541, 1486, 509, -1, 540, 1486, 541, -1, 508, 1486, 540, -1, 510, 1487, 509, -1, 542, 1487, 510, -1, 541, 1487, 542, -1, 509, 1487, 541, -1, 511, 1488, 510, -1, 543, 1488, 511, -1, 542, 1488, 543, -1, 510, 1488, 542, -1, 513, 1489, 512, -1, 545, 1489, 513, -1, 544, 1489, 545, -1, 512, 1489, 544, -1, 514, 1490, 513, -1, 546, 1490, 514, -1, 545, 1490, 546, -1, 513, 1490, 545, -1, 515, 1491, 514, -1, 547, 1491, 515, -1, 546, 1491, 547, -1, 514, 1491, 546, -1, 516, 1492, 515, -1, 548, 1492, 516, -1, 547, 1492, 548, -1, 515, 1492, 547, -1, 517, 1493, 516, -1, 549, 1493, 517, -1, 548, 1493, 549, -1, 516, 1493, 548, -1, 518, 1494, 517, -1, 550, 1494, 518, -1, 549, 1494, 550, -1, 517, 1494, 549, -1, 519, 1495, 518, -1, 551, 1495, 519, -1, 550, 1495, 551, -1, 518, 1495, 550, -1, 520, 1496, 519, -1, 552, 1496, 520, -1, 551, 1496, 552, -1, 519, 1496, 551, -1, 521, 1497, 520, -1, 553, 1497, 521, -1, 552, 1497, 553, -1, 520, 1497, 552, -1, 522, 1498, 521, -1, 554, 1498, 522, -1, 553, 1498, 554, -1, 521, 1498, 553, -1, 523, 1499, 522, -1, 555, 1499, 523, -1, 554, 1499, 555, -1, 522, 1499, 554, -1, 524, 1500, 523, -1, 556, 1500, 524, -1, 555, 1500, 556, -1, 523, 1500, 555, -1, 525, 1501, 524, -1, 557, 1501, 525, -1, 556, 1501, 557, -1, 524, 1501, 556, -1, 526, 1502, 525, -1, 558, 1502, 526, -1, 557, 1502, 558, -1, 525, 1502, 557, -1, 527, 1503, 526, -1, 559, 1503, 527, -1, 558, 1503, 559, -1, 526, 1503, 558, -1, 528, 1504, 527, -1, 560, 1504, 528, -1, 559, 1504, 560, -1, 527, 1504, 559, -1, 529, 1505, 528, -1, 561, 1505, 529, -1, 560, 1505, 561, -1, 528, 1505, 560, -1, 530, 1506, 529, -1, 562, 1506, 530, -1, 561, 1506, 562, -1, 529, 1506, 561, -1, 531, 1507, 530, -1, 563, 1507, 531, -1, 562, 1507, 563, -1, 530, 1507, 562, -1, 532, 1508, 531, -1, 564, 1508, 532, -1, 563, 1508, 564, -1, 531, 1508, 563, -1, 533, 1509, 532, -1, 565, 1509, 533, -1, 564, 1509, 565, -1, 532, 1509, 564, -1, 534, 1510, 533, -1, 566, 1510, 534, -1, 565, 1510, 566, -1, 533, 1510, 565, -1, 535, 1511, 534, -1, 567, 1511, 535, -1, 566, 1511, 567, -1, 534, 1511, 566, -1, 536, 1512, 535, -1, 568, 1512, 536, -1, 567, 1512, 568, -1, 535, 1512, 567, -1, 537, 1513, 536, -1, 569, 1513, 537, -1, 568, 1513, 569, -1, 536, 1513, 568, -1, 538, 1514, 537, -1, 570, 1514, 538, -1, 569, 1514, 570, -1, 537, 1514, 569, -1, 539, 1515, 538, -1, 571, 1515, 539, -1, 570, 1515, 571, -1, 538, 1515, 570, -1, 540, 1516, 539, -1, 572, 1516, 540, -1, 571, 1516, 572, -1, 539, 1516, 571, -1, 541, 1517, 540, -1, 573, 1517, 541, -1, 572, 1517, 573, -1, 540, 1517, 572, -1, 542, 1518, 541, -1, 574, 1518, 542, -1, 573, 1518, 574, -1, 541, 1518, 573, -1, 543, 1519, 542, -1, 575, 1519, 543, -1, 574, 1519, 575, -1, 542, 1519, 574, -1, 545, 1520, 544, -1, 577, 1520, 545, -1, 576, 1520, 577, -1, 544, 1520, 576, -1, 546, 1521, 545, -1, 578, 1521, 546, -1, 577, 1521, 578, -1, 545, 1521, 577, -1, 547, 1522, 546, -1, 579, 1522, 547, -1, 578, 1522, 579, -1, 546, 1522, 578, -1, 548, 1523, 547, -1, 580, 1523, 548, -1, 579, 1523, 580, -1, 547, 1523, 579, -1, 549, 1524, 548, -1, 581, 1524, 549, -1, 580, 1524, 581, -1, 548, 1524, 580, -1, 550, 1525, 549, -1, 582, 1525, 550, -1, 581, 1525, 582, -1, 549, 1525, 581, -1, 551, 1526, 550, -1, 583, 1526, 551, -1, 582, 1526, 583, -1, 550, 1526, 582, -1, 552, 1527, 551, -1, 584, 1527, 552, -1, 583, 1527, 584, -1, 551, 1527, 583, -1, 553, 1528, 552, -1, 585, 1528, 553, -1, 584, 1528, 585, -1, 552, 1528, 584, -1, 554, 1529, 553, -1, 586, 1529, 554, -1, 585, 1529, 586, -1, 553, 1529, 585, -1, 555, 1530, 554, -1, 587, 1530, 555, -1, 586, 1530, 587, -1, 554, 1530, 586, -1, 556, 1531, 555, -1, 588, 1531, 556, -1, 587, 1531, 588, -1, 555, 1531, 587, -1, 557, 1532, 556, -1, 589, 1532, 557, -1, 588, 1532, 589, -1, 556, 1532, 588, -1, 558, 1533, 557, -1, 590, 1533, 558, -1, 589, 1533, 590, -1, 557, 1533, 589, -1, 559, 1534, 558, -1, 591, 1534, 559, -1, 590, 1534, 591, -1, 558, 1534, 590, -1, 560, 1535, 559, -1, 592, 1535, 560, -1, 591, 1535, 592, -1, 559, 1535, 591, -1, 561, 1536, 560, -1, 593, 1536, 561, -1, 592, 1536, 593, -1, 560, 1536, 592, -1, 562, 1537, 561, -1, 594, 1537, 562, -1, 593, 1537, 594, -1, 561, 1537, 593, -1, 563, 1538, 562, -1, 595, 1538, 563, -1, 594, 1538, 595, -1, 562, 1538, 594, -1, 564, 1539, 563, -1, 596, 1539, 564, -1, 595, 1539, 596, -1, 563, 1539, 595, -1, 565, 1540, 564, -1, 597, 1540, 565, -1, 596, 1540, 597, -1, 564, 1540, 596, -1, 566, 1541, 565, -1, 598, 1541, 566, -1, 597, 1541, 598, -1, 565, 1541, 597, -1, 567, 1542, 566, -1, 599, 1542, 567, -1, 598, 1542, 599, -1, 566, 1542, 598, -1, 568, 1543, 567, -1, 600, 1543, 568, -1, 599, 1543, 600, -1, 567, 1543, 599, -1, 569, 1544, 568, -1, 601, 1544, 569, -1, 600, 1544, 601, -1, 568, 1544, 600, -1, 570, 1545, 569, -1, 602, 1545, 570, -1, 601, 1545, 602, -1, 569, 1545, 601, -1, 571, 1546, 570, -1, 603, 1546, 571, -1, 602, 1546, 603, -1, 570, 1546, 602, -1, 572, 1547, 571, -1, 604, 1547, 572, -1, 603, 1547, 604, -1, 571, 1547, 603, -1, 573, 1548, 572, -1, 605, 1548, 573, -1, 604, 1548, 605, -1, 572, 1548, 604, -1, 574, 1549, 573, -1, 606, 1549, 574, -1, 605, 1549, 606, -1, 573, 1549, 605, -1, 575, 1550, 574, -1, 607, 1550, 575, -1, 606, 1550, 607, -1, 574, 1550, 606, -1, 577, 1551, 576, -1, 609, 1551, 577, -1, 608, 1551, 609, -1, 576, 1551, 608, -1, 578, 1552, 577, -1, 610, 1552, 578, -1, 609, 1552, 610, -1, 577, 1552, 609, -1, 579, 1553, 578, -1, 611, 1553, 579, -1, 610, 1553, 611, -1, 578, 1553, 610, -1, 580, 1554, 579, -1, 612, 1554, 580, -1, 611, 1554, 612, -1, 579, 1554, 611, -1, 581, 1555, 580, -1, 613, 1555, 581, -1, 612, 1555, 613, -1, 580, 1555, 612, -1, 582, 1556, 581, -1, 614, 1556, 582, -1, 613, 1556, 614, -1, 581, 1556, 613, -1, 583, 1557, 582, -1, 615, 1557, 583, -1, 614, 1557, 615, -1, 582, 1557, 614, -1, 584, 1558, 583, -1, 616, 1558, 584, -1, 615, 1558, 616, -1, 583, 1558, 615, -1, 585, 1559, 584, -1, 617, 1559, 585, -1, 616, 1559, 617, -1, 584, 1559, 616, -1, 586, 1560, 585, -1, 618, 1560, 586, -1, 617, 1560, 618, -1, 585, 1560, 617, -1, 587, 1561, 586, -1, 619, 1561, 587, -1, 618, 1561, 619, -1, 586, 1561, 618, -1, 588, 1562, 587, -1, 620, 1562, 588, -1, 619, 1562, 620, -1, 587, 1562, 619, -1, 589, 1563, 588, -1, 621, 1563, 589, -1, 620, 1563, 621, -1, 588, 1563, 620, -1, 590, 1564, 589, -1, 622, 1564, 590, -1, 621, 1564, 622, -1, 589, 1564, 621, -1, 591, 1565, 590, -1, 623, 1565, 591, -1, 622, 1565, 623, -1, 590, 1565, 622, -1, 592, 1566, 591, -1, 624, 1566, 592, -1, 623, 1566, 624, -1, 591, 1566, 623, -1, 593, 1567, 592, -1, 625, 1567, 593, -1, 624, 1567, 625, -1, 592, 1567, 624, -1, 594, 1568, 593, -1, 626, 1568, 594, -1, 625, 1568, 626, -1, 593, 1568, 625, -1, 595, 1569, 594, -1, 627, 1569, 595, -1, 626, 1569, 627, -1, 594, 1569, 626, -1, 596, 1570, 595, -1, 628, 1570, 596, -1, 627, 1570, 628, -1, 595, 1570, 627, -1, 597, 1571, 596, -1, 629, 1571, 597, -1, 628, 1571, 629, -1, 596, 1571, 628, -1, 598, 1572, 597, -1, 630, 1572, 598, -1, 629, 1572, 630, -1, 597, 1572, 629, -1, 599, 1573, 598, -1, 631, 1573, 599, -1, 630, 1573, 631, -1, 598, 1573, 630, -1, 600, 1574, 599, -1, 632, 1574, 600, -1, 631, 1574, 632, -1, 599, 1574, 631, -1, 601, 1575, 600, -1, 633, 1575, 601, -1, 632, 1575, 633, -1, 600, 1575, 632, -1, 602, 1576, 601, -1, 634, 1576, 602, -1, 633, 1576, 634, -1, 601, 1576, 633, -1, 603, 1577, 602, -1, 635, 1577, 603, -1, 634, 1577, 635, -1, 602, 1577, 634, -1, 604, 1578, 603, -1, 636, 1578, 604, -1, 635, 1578, 636, -1, 603, 1578, 635, -1, 605, 1579, 604, -1, 637, 1579, 605, -1, 636, 1579, 637, -1, 604, 1579, 636, -1, 606, 1580, 605, -1, 638, 1580, 606, -1, 637, 1580, 638, -1, 605, 1580, 637, -1, 607, 1581, 606, -1, 639, 1581, 607, -1, 638, 1581, 639, -1, 606, 1581, 638, -1, 609, 1582, 608, -1, 641, 1582, 609, -1, 640, 1582, 641, -1, 608, 1582, 640, -1, 610, 1583, 609, -1, 642, 1583, 610, -1, 641, 1583, 642, -1, 609, 1583, 641, -1, 611, 1584, 610, -1, 643, 1584, 611, -1, 642, 1584, 643, -1, 610, 1584, 642, -1, 612, 1585, 611, -1, 644, 1585, 612, -1, 643, 1585, 644, -1, 611, 1585, 643, -1, 613, 1586, 612, -1, 645, 1586, 613, -1, 644, 1586, 645, -1, 612, 1586, 644, -1, 614, 1587, 613, -1, 646, 1587, 614, -1, 645, 1587, 646, -1, 613, 1587, 645, -1, 615, 1588, 614, -1, 647, 1588, 615, -1, 646, 1588, 647, -1, 614, 1588, 646, -1, 616, 1589, 615, -1, 648, 1589, 616, -1, 647, 1589, 648, -1, 615, 1589, 647, -1, 617, 1590, 616, -1, 649, 1590, 617, -1, 648, 1590, 649, -1, 616, 1590, 648, -1, 618, 1591, 617, -1, 650, 1591, 618, -1, 649, 1591, 650, -1, 617, 1591, 649, -1, 619, 1592, 618, -1, 651, 1592, 619, -1, 650, 1592, 651, -1, 618, 1592, 650, -1, 620, 1593, 619, -1, 652, 1593, 620, -1, 651, 1593, 652, -1, 619, 1593, 651, -1, 621, 1594, 620, -1, 653, 1594, 621, -1, 652, 1594, 653, -1, 620, 1594, 652, -1, 622, 1595, 621, -1, 654, 1595, 622, -1, 653, 1595, 654, -1, 621, 1595, 653, -1, 623, 1596, 622, -1, 655, 1596, 623, -1, 654, 1596, 655, -1, 622, 1596, 654, -1, 624, 1597, 623, -1, 656, 1597, 624, -1, 655, 1597, 656, -1, 623, 1597, 655, -1, 625, 1598, 624, -1, 657, 1598, 625, -1, 656, 1598, 657, -1, 624, 1598, 656, -1, 626, 1599, 625, -1, 658, 1599, 626, -1, 657, 1599, 658, -1, 625, 1599, 657, -1, 627, 1600, 626, -1, 659, 1600, 627, -1, 658, 1600, 659, -1, 626, 1600, 658, -1, 628, 1601, 627, -1, 660, 1601, 628, -1, 659, 1601, 660, -1, 627, 1601, 659, -1, 629, 1602, 628, -1, 661, 1602, 629, -1, 660, 1602, 661, -1, 628, 1602, 660, -1, 630, 1603, 629, -1, 662, 1603, 630, -1, 661, 1603, 662, -1, 629, 1603, 661, -1, 631, 1604, 630, -1, 663, 1604, 631, -1, 662, 1604, 663, -1, 630, 1604, 662, -1, 632, 1605, 631, -1, 664, 1605, 632, -1, 663, 1605, 664, -1, 631, 1605, 663, -1, 633, 1606, 632, -1, 665, 1606, 633, -1, 664, 1606, 665, -1, 632, 1606, 664, -1, 634, 1607, 633, -1, 666, 1607, 634, -1, 665, 1607, 666, -1, 633, 1607, 665, -1, 635, 1608, 634, -1, 667, 1608, 635, -1, 666, 1608, 667, -1, 634, 1608, 666, -1, 636, 1609, 635, -1, 668, 1609, 636, -1, 667, 1609, 668, -1, 635, 1609, 667, -1, 637, 1610, 636, -1, 669, 1610, 637, -1, 668, 1610, 669, -1, 636, 1610, 668, -1, 638, 1611, 637, -1, 670, 1611, 638, -1, 669, 1611, 670, -1, 637, 1611, 669, -1, 639, 1612, 638, -1, 671, 1612, 639, -1, 670, 1612, 671, -1, 638, 1612, 670, -1, 641, 1613, 640, -1, 673, 1613, 641, -1, 672, 1613, 673, -1, 640, 1613, 672, -1, 642, 1614, 641, -1, 674, 1614, 642, -1, 673, 1614, 674, -1, 641, 1614, 673, -1, 643, 1615, 642, -1, 675, 1615, 643, -1, 674, 1615, 675, -1, 642, 1615, 674, -1, 644, 1616, 643, -1, 676, 1616, 644, -1, 675, 1616, 676, -1, 643, 1616, 675, -1, 645, 1617, 644, -1, 677, 1617, 645, -1, 676, 1617, 677, -1, 644, 1617, 676, -1, 646, 1618, 645, -1, 678, 1618, 646, -1, 677, 1618, 678, -1, 645, 1618, 677, -1, 647, 1619, 646, -1, 679, 1619, 647, -1, 678, 1619, 679, -1, 646, 1619, 678, -1, 648, 1620, 647, -1, 680, 1620, 648, -1, 679, 1620, 680, -1, 647, 1620, 679, -1, 649, 1621, 648, -1, 681, 1621, 649, -1, 680, 1621, 681, -1, 648, 1621, 680, -1, 650, 1622, 649, -1, 682, 1622, 650, -1, 681, 1622, 682, -1, 649, 1622, 681, -1, 651, 1623, 650, -1, 683, 1623, 651, -1, 682, 1623, 683, -1, 650, 1623, 682, -1, 652, 1624, 651, -1, 684, 1624, 652, -1, 683, 1624, 684, -1, 651, 1624, 683, -1, 653, 1625, 652, -1, 685, 1625, 653, -1, 684, 1625, 685, -1, 652, 1625, 684, -1, 654, 1626, 653, -1, 686, 1626, 654, -1, 685, 1626, 686, -1, 653, 1626, 685, -1, 655, 1627, 654, -1, 687, 1627, 655, -1, 686, 1627, 687, -1, 654, 1627, 686, -1, 656, 1628, 655, -1, 688, 1628, 656, -1, 687, 1628, 688, -1, 655, 1628, 687, -1, 657, 1629, 656, -1, 689, 1629, 657, -1, 688, 1629, 689, -1, 656, 1629, 688, -1, 658, 1630, 657, -1, 690, 1630, 658, -1, 689, 1630, 690, -1, 657, 1630, 689, -1, 659, 1631, 658, -1, 691, 1631, 659, -1, 690, 1631, 691, -1, 658, 1631, 690, -1, 660, 1632, 659, -1, 692, 1632, 660, -1, 691, 1632, 692, -1, 659, 1632, 691, -1, 661, 1633, 660, -1, 693, 1633, 661, -1, 692, 1633, 693, -1, 660, 1633, 692, -1, 662, 1634, 661, -1, 694, 1634, 662, -1, 693, 1634, 694, -1, 661, 1634, 693, -1, 663, 1635, 662, -1, 695, 1635, 663, -1, 694, 1635, 695, -1, 662, 1635, 694, -1, 664, 1636, 663, -1, 696, 1636, 664, -1, 695, 1636, 696, -1, 663, 1636, 695, -1, 665, 1637, 664, -1, 697, 1637, 665, -1, 696, 1637, 697, -1, 664, 1637, 696, -1, 666, 1638, 665, -1, 698, 1638, 666, -1, 697, 1638, 698, -1, 665, 1638, 697, -1, 667, 1639, 666, -1, 699, 1639, 667, -1, 698, 1639, 699, -1, 666, 1639, 698, -1, 668, 1640, 667, -1, 700, 1640, 668, -1, 699, 1640, 700, -1, 667, 1640, 699, -1, 669, 1641, 668, -1, 701, 1641, 669, -1, 700, 1641, 701, -1, 668, 1641, 700, -1, 670, 1642, 669, -1, 702, 1642, 670, -1, 701, 1642, 702, -1, 669, 1642, 701, -1, 671, 1643, 670, -1, 703, 1643, 671, -1, 702, 1643, 703, -1, 670, 1643, 702, -1, 673, 1644, 672, -1, 705, 1644, 673, -1, 704, 1644, 705, -1, 672, 1644, 704, -1, 674, 1645, 673, -1, 706, 1645, 674, -1, 705, 1645, 706, -1, 673, 1645, 705, -1, 675, 1646, 674, -1, 707, 1646, 675, -1, 706, 1646, 707, -1, 674, 1646, 706, -1, 676, 1647, 675, -1, 708, 1647, 676, -1, 707, 1647, 708, -1, 675, 1647, 707, -1, 677, 1648, 676, -1, 709, 1648, 677, -1, 708, 1648, 709, -1, 676, 1648, 708, -1, 678, 1649, 677, -1, 710, 1649, 678, -1, 709, 1649, 710, -1, 677, 1649, 709, -1, 679, 1650, 678, -1, 711, 1650, 679, -1, 710, 1650, 711, -1, 678, 1650, 710, -1, 680, 1651, 679, -1, 712, 1651, 680, -1, 711, 1651, 712, -1, 679, 1651, 711, -1, 681, 1652, 680, -1, 713, 1652, 681, -1, 712, 1652, 713, -1, 680, 1652, 712, -1, 682, 1653, 681, -1, 714, 1653, 682, -1, 713, 1653, 714, -1, 681, 1653, 713, -1, 683, 1654, 682, -1, 715, 1654, 683, -1, 714, 1654, 715, -1, 682, 1654, 714, -1, 684, 1655, 683, -1, 716, 1655, 684, -1, 715, 1655, 716, -1, 683, 1655, 715, -1, 685, 1656, 684, -1, 717, 1656, 685, -1, 716, 1656, 717, -1, 684, 1656, 716, -1, 686, 1657, 685, -1, 718, 1657, 686, -1, 717, 1657, 718, -1, 685, 1657, 717, -1, 687, 1658, 686, -1, 719, 1658, 687, -1, 718, 1658, 719, -1, 686, 1658, 718, -1, 688, 1659, 687, -1, 720, 1659, 688, -1, 719, 1659, 720, -1, 687, 1659, 719, -1, 689, 1660, 688, -1, 721, 1660, 689, -1, 720, 1660, 721, -1, 688, 1660, 720, -1, 690, 1661, 689, -1, 722, 1661, 690, -1, 721, 1661, 722, -1, 689, 1661, 721, -1, 691, 1662, 690, -1, 723, 1662, 691, -1, 722, 1662, 723, -1, 690, 1662, 722, -1, 692, 1663, 691, -1, 724, 1663, 692, -1, 723, 1663, 724, -1, 691, 1663, 723, -1, 693, 1664, 692, -1, 725, 1664, 693, -1, 724, 1664, 725, -1, 692, 1664, 724, -1, 694, 1665, 693, -1, 726, 1665, 694, -1, 725, 1665, 726, -1, 693, 1665, 725, -1, 695, 1666, 694, -1, 727, 1666, 695, -1, 726, 1666, 727, -1, 694, 1666, 726, -1, 696, 1667, 695, -1, 728, 1667, 696, -1, 727, 1667, 728, -1, 695, 1667, 727, -1, 697, 1668, 696, -1, 729, 1668, 697, -1, 728, 1668, 729, -1, 696, 1668, 728, -1, 698, 1669, 697, -1, 730, 1669, 698, -1, 729, 1669, 730, -1, 697, 1669, 729, -1, 699, 1670, 698, -1, 731, 1670, 699, -1, 730, 1670, 731, -1, 698, 1670, 730, -1, 700, 1671, 699, -1, 732, 1671, 700, -1, 731, 1671, 732, -1, 699, 1671, 731, -1, 701, 1672, 700, -1, 733, 1672, 701, -1, 732, 1672, 733, -1, 700, 1672, 732, -1, 702, 1673, 701, -1, 734, 1673, 702, -1, 733, 1673, 734, -1, 701, 1673, 733, -1, 703, 1674, 702, -1, 735, 1674, 703, -1, 734, 1674, 735, -1, 702, 1674, 734, -1, 705, 1675, 704, -1, 737, 1675, 705, -1, 736, 1675, 737, -1, 704, 1675, 736, -1, 706, 1676, 705, -1, 738, 1676, 706, -1, 737, 1676, 738, -1, 705, 1676, 737, -1, 707, 1677, 706, -1, 739, 1677, 707, -1, 738, 1677, 739, -1, 706, 1677, 738, -1, 708, 1678, 707, -1, 740, 1678, 708, -1, 739, 1678, 740, -1, 707, 1678, 739, -1, 709, 1679, 708, -1, 741, 1679, 709, -1, 740, 1679, 741, -1, 708, 1679, 740, -1, 710, 1680, 709, -1, 742, 1680, 710, -1, 741, 1680, 742, -1, 709, 1680, 741, -1, 711, 1681, 710, -1, 743, 1681, 711, -1, 742, 1681, 743, -1, 710, 1681, 742, -1, 712, 1682, 711, -1, 744, 1682, 712, -1, 743, 1682, 744, -1, 711, 1682, 743, -1, 713, 1683, 712, -1, 745, 1683, 713, -1, 744, 1683, 745, -1, 712, 1683, 744, -1, 714, 1684, 713, -1, 746, 1684, 714, -1, 745, 1684, 746, -1, 713, 1684, 745, -1, 715, 1685, 714, -1, 747, 1685, 715, -1, 746, 1685, 747, -1, 714, 1685, 746, -1, 716, 1686, 715, -1, 748, 1686, 716, -1, 747, 1686, 748, -1, 715, 1686, 747, -1, 717, 1687, 716, -1, 749, 1687, 717, -1, 748, 1687, 749, -1, 716, 1687, 748, -1, 718, 1688, 717, -1, 750, 1688, 718, -1, 749, 1688, 750, -1, 717, 1688, 749, -1, 719, 1689, 718, -1, 751, 1689, 719, -1, 750, 1689, 751, -1, 718, 1689, 750, -1, 720, 1690, 719, -1, 752, 1690, 720, -1, 751, 1690, 752, -1, 719, 1690, 751, -1, 721, 1691, 720, -1, 753, 1691, 721, -1, 752, 1691, 753, -1, 720, 1691, 752, -1, 722, 1692, 721, -1, 754, 1692, 722, -1, 753, 1692, 754, -1, 721, 1692, 753, -1, 723, 1693, 722, -1, 755, 1693, 723, -1, 754, 1693, 755, -1, 722, 1693, 754, -1, 724, 1694, 723, -1, 756, 1694, 724, -1, 755, 1694, 756, -1, 723, 1694, 755, -1, 725, 1695, 724, -1, 757, 1695, 725, -1, 756, 1695, 757, -1, 724, 1695, 756, -1, 726, 1696, 725, -1, 758, 1696, 726, -1, 757, 1696, 758, -1, 725, 1696, 757, -1, 727, 1697, 726, -1, 759, 1697, 727, -1, 758, 1697, 759, -1, 726, 1697, 758, -1, 728, 1698, 727, -1, 760, 1698, 728, -1, 759, 1698, 760, -1, 727, 1698, 759, -1, 729, 1699, 728, -1, 761, 1699, 729, -1, 760, 1699, 761, -1, 728, 1699, 760, -1, 730, 1700, 729, -1, 762, 1700, 730, -1, 761, 1700, 762, -1, 729, 1700, 761, -1, 731, 1701, 730, -1, 763, 1701, 731, -1, 762, 1701, 763, -1, 730, 1701, 762, -1, 732, 1702, 731, -1, 764, 1702, 732, -1, 763, 1702, 764, -1, 731, 1702, 763, -1, 733, 1703, 732, -1, 765, 1703, 733, -1, 764, 1703, 765, -1, 732, 1703, 764, -1, 734, 1704, 733, -1, 766, 1704, 734, -1, 765, 1704, 766, -1, 733, 1704, 765, -1, 735, 1705, 734, -1, 767, 1705, 735, -1, 766, 1705, 767, -1, 734, 1705, 766, -1, 737, 1706, 736, -1, 769, 1706, 737, -1, 768, 1706, 769, -1, 736, 1706, 768, -1, 738, 1707, 737, -1, 770, 1707, 738, -1, 769, 1707, 770, -1, 737, 1707, 769, -1, 739, 1708, 738, -1, 771, 1708, 739, -1, 770, 1708, 771, -1, 738, 1708, 770, -1, 740, 1709, 739, -1, 772, 1709, 740, -1, 771, 1709, 772, -1, 739, 1709, 771, -1, 741, 1710, 740, -1, 773, 1710, 741, -1, 772, 1710, 773, -1, 740, 1710, 772, -1, 742, 1711, 741, -1, 774, 1711, 742, -1, 773, 1711, 774, -1, 741, 1711, 773, -1, 743, 1712, 742, -1, 775, 1712, 743, -1, 774, 1712, 775, -1, 742, 1712, 774, -1, 744, 1713, 743, -1, 776, 1713, 744, -1, 775, 1713, 776, -1, 743, 1713, 775, -1, 745, 1714, 744, -1, 777, 1714, 745, -1, 776, 1714, 777, -1, 744, 1714, 776, -1, 746, 1715, 745, -1, 778, 1715, 746, -1, 777, 1715, 778, -1, 745, 1715, 777, -1, 747, 1716, 746, -1, 779, 1716, 747, -1, 778, 1716, 779, -1, 746, 1716, 778, -1, 748, 1717, 747, -1, 780, 1717, 748, -1, 779, 1717, 780, -1, 747, 1717, 779, -1, 749, 1718, 748, -1, 781, 1718, 749, -1, 780, 1718, 781, -1, 748, 1718, 780, -1, 750, 1719, 749, -1, 782, 1719, 750, -1, 781, 1719, 782, -1, 749, 1719, 781, -1, 751, 1720, 750, -1, 783, 1720, 751, -1, 782, 1720, 783, -1, 750, 1720, 782, -1, 752, 1721, 751, -1, 784, 1721, 752, -1, 783, 1721, 784, -1, 751, 1721, 783, -1, 753, 1722, 752, -1, 785, 1722, 753, -1, 784, 1722, 785, -1, 752, 1722, 784, -1, 754, 1723, 753, -1, 786, 1723, 754, -1, 785, 1723, 786, -1, 753, 1723, 785, -1, 755, 1724, 754, -1, 787, 1724, 755, -1, 786, 1724, 787, -1, 754, 1724, 786, -1, 756, 1725, 755, -1, 788, 1725, 756, -1, 787, 1725, 788, -1, 755, 1725, 787, -1, 757, 1726, 756, -1, 789, 1726, 757, -1, 788, 1726, 789, -1, 756, 1726, 788, -1, 758, 1727, 757, -1, 790, 1727, 758, -1, 789, 1727, 790, -1, 757, 1727, 789, -1, 759, 1728, 758, -1, 791, 1728, 759, -1, 790, 1728, 791, -1, 758, 1728, 790, -1, 760, 1729, 759, -1, 792, 1729, 760, -1, 791, 1729, 792, -1, 759, 1729, 791, -1, 761, 1730, 760, -1, 793, 1730, 761, -1, 792, 1730, 793, -1, 760, 1730, 792, -1, 762, 1731, 761, -1, 794, 1731, 762, -1, 793, 1731, 794, -1, 761, 1731, 793, -1, 763, 1732, 762, -1, 795, 1732, 763, -1, 794, 1732, 795, -1, 762, 1732, 794, -1, 764, 1733, 763, -1, 796, 1733, 764, -1, 795, 1733, 796, -1, 763, 1733, 795, -1, 765, 1734, 764, -1, 797, 1734, 765, -1, 796, 1734, 797, -1, 764, 1734, 796, -1, 766, 1735, 765, -1, 798, 1735, 766, -1, 797, 1735, 798, -1, 765, 1735, 797, -1, 767, 1736, 766, -1, 799, 1736, 767, -1, 798, 1736, 799, -1, 766, 1736, 798, -1, 769, 1737, 768, -1, 801, 1737, 769, -1, 800, 1737, 801, -1, 768, 1737, 800, -1, 770, 1738, 769, -1, 802, 1738, 770, -1, 801, 1738, 802, -1, 769, 1738, 801, -1, 771, 1739, 770, -1, 803, 1739, 771, -1, 802, 1739, 803, -1, 770, 1739, 802, -1, 772, 1740, 771, -1, 804, 1740, 772, -1, 803, 1740, 804, -1, 771, 1740, 803, -1, 773, 1741, 772, -1, 805, 1741, 773, -1, 804, 1741, 805, -1, 772, 1741, 804, -1, 774, 1742, 773, -1, 806, 1742, 774, -1, 805, 1742, 806, -1, 773, 1742, 805, -1, 775, 1743, 774, -1, 807, 1743, 775, -1, 806, 1743, 807, -1, 774, 1743, 806, -1, 776, 1744, 775, -1, 808, 1744, 776, -1, 807, 1744, 808, -1, 775, 1744, 807, -1, 777, 1745, 776, -1, 809, 1745, 777, -1, 808, 1745, 809, -1, 776, 1745, 808, -1, 778, 1746, 777, -1, 810, 1746, 778, -1, 809, 1746, 810, -1, 777, 1746, 809, -1, 779, 1747, 778, -1, 811, 1747, 779, -1, 810, 1747, 811, -1, 778, 1747, 810, -1, 780, 1748, 779, -1, 812, 1748, 780, -1, 811, 1748, 812, -1, 779, 1748, 811, -1, 781, 1749, 780, -1, 813, 1749, 781, -1, 812, 1749, 813, -1, 780, 1749, 812, -1, 782, 1750, 781, -1, 814, 1750, 782, -1, 813, 1750, 814, -1, 781, 1750, 813, -1, 783, 1751, 782, -1, 815, 1751, 783, -1, 814, 1751, 815, -1, 782, 1751, 814, -1, 784, 1752, 783, -1, 816, 1752, 784, -1, 815, 1752, 816, -1, 783, 1752, 815, -1, 785, 1753, 784, -1, 817, 1753, 785, -1, 816, 1753, 817, -1, 784, 1753, 816, -1, 786, 1754, 785, -1, 818, 1754, 786, -1, 817, 1754, 818, -1, 785, 1754, 817, -1, 787, 1755, 786, -1, 819, 1755, 787, -1, 818, 1755, 819, -1, 786, 1755, 818, -1, 788, 1756, 787, -1, 820, 1756, 788, -1, 819, 1756, 820, -1, 787, 1756, 819, -1, 789, 1757, 788, -1, 821, 1757, 789, -1, 820, 1757, 821, -1, 788, 1757, 820, -1, 790, 1758, 789, -1, 822, 1758, 790, -1, 821, 1758, 822, -1, 789, 1758, 821, -1, 791, 1759, 790, -1, 823, 1759, 791, -1, 822, 1759, 823, -1, 790, 1759, 822, -1, 792, 1760, 791, -1, 824, 1760, 792, -1, 823, 1760, 824, -1, 791, 1760, 823, -1, 793, 1761, 792, -1, 825, 1761, 793, -1, 824, 1761, 825, -1, 792, 1761, 824, -1, 794, 1762, 793, -1, 826, 1762, 794, -1, 825, 1762, 826, -1, 793, 1762, 825, -1, 795, 1763, 794, -1, 827, 1763, 795, -1, 826, 1763, 827, -1, 794, 1763, 826, -1, 796, 1764, 795, -1, 828, 1764, 796, -1, 827, 1764, 828, -1, 795, 1764, 827, -1, 797, 1765, 796, -1, 829, 1765, 797, -1, 828, 1765, 829, -1, 796, 1765, 828, -1, 798, 1766, 797, -1, 830, 1766, 798, -1, 829, 1766, 830, -1, 797, 1766, 829, -1, 799, 1767, 798, -1, 831, 1767, 799, -1, 830, 1767, 831, -1, 798, 1767, 830, -1, 801, 1768, 800, -1, 833, 1768, 801, -1, 832, 1768, 833, -1, 800, 1768, 832, -1, 802, 1769, 801, -1, 834, 1769, 802, -1, 833, 1769, 834, -1, 801, 1769, 833, -1, 803, 1770, 802, -1, 835, 1770, 803, -1, 834, 1770, 835, -1, 802, 1770, 834, -1, 804, 1771, 803, -1, 836, 1771, 804, -1, 835, 1771, 836, -1, 803, 1771, 835, -1, 805, 1772, 804, -1, 837, 1772, 805, -1, 836, 1772, 837, -1, 804, 1772, 836, -1, 806, 1773, 805, -1, 838, 1773, 806, -1, 837, 1773, 838, -1, 805, 1773, 837, -1, 807, 1774, 806, -1, 839, 1774, 807, -1, 838, 1774, 839, -1, 806, 1774, 838, -1, 808, 1775, 807, -1, 840, 1775, 808, -1, 839, 1775, 840, -1, 807, 1775, 839, -1, 809, 1776, 808, -1, 841, 1776, 809, -1, 840, 1776, 841, -1, 808, 1776, 840, -1, 810, 1777, 809, -1, 842, 1777, 810, -1, 841, 1777, 842, -1, 809, 1777, 841, -1, 811, 1778, 810, -1, 843, 1778, 811, -1, 842, 1778, 843, -1, 810, 1778, 842, -1, 812, 1779, 811, -1, 844, 1779, 812, -1, 843, 1779, 844, -1, 811, 1779, 843, -1, 813, 1780, 812, -1, 845, 1780, 813, -1, 844, 1780, 845, -1, 812, 1780, 844, -1, 814, 1781, 813, -1, 846, 1781, 814, -1, 845, 1781, 846, -1, 813, 1781, 845, -1, 815, 1782, 814, -1, 847, 1782, 815, -1, 846, 1782, 847, -1, 814, 1782, 846, -1, 816, 1783, 815, -1, 848, 1783, 816, -1, 847, 1783, 848, -1, 815, 1783, 847, -1, 817, 1784, 816, -1, 849, 1784, 817, -1, 848, 1784, 849, -1, 816, 1784, 848, -1, 818, 1785, 817, -1, 850, 1785, 818, -1, 849, 1785, 850, -1, 817, 1785, 849, -1, 819, 1786, 818, -1, 851, 1786, 819, -1, 850, 1786, 851, -1, 818, 1786, 850, -1, 820, 1787, 819, -1, 852, 1787, 820, -1, 851, 1787, 852, -1, 819, 1787, 851, -1, 821, 1788, 820, -1, 853, 1788, 821, -1, 852, 1788, 853, -1, 820, 1788, 852, -1, 822, 1789, 821, -1, 854, 1789, 822, -1, 853, 1789, 854, -1, 821, 1789, 853, -1, 823, 1790, 822, -1, 855, 1790, 823, -1, 854, 1790, 855, -1, 822, 1790, 854, -1, 824, 1791, 823, -1, 856, 1791, 824, -1, 855, 1791, 856, -1, 823, 1791, 855, -1, 825, 1792, 824, -1, 857, 1792, 825, -1, 856, 1792, 857, -1, 824, 1792, 856, -1, 826, 1793, 825, -1, 858, 1793, 826, -1, 857, 1793, 858, -1, 825, 1793, 857, -1, 827, 1794, 826, -1, 859, 1794, 827, -1, 858, 1794, 859, -1, 826, 1794, 858, -1, 828, 1795, 827, -1, 860, 1795, 828, -1, 859, 1795, 860, -1, 827, 1795, 859, -1, 829, 1796, 828, -1, 861, 1796, 829, -1, 860, 1796, 861, -1, 828, 1796, 860, -1, 830, 1797, 829, -1, 862, 1797, 830, -1, 861, 1797, 862, -1, 829, 1797, 861, -1, 831, 1798, 830, -1, 863, 1798, 831, -1, 862, 1798, 863, -1, 830, 1798, 862, -1, 833, 1799, 832, -1, 865, 1799, 833, -1, 864, 1799, 865, -1, 832, 1799, 864, -1, 834, 1800, 833, -1, 866, 1800, 834, -1, 865, 1800, 866, -1, 833, 1800, 865, -1, 835, 1801, 834, -1, 867, 1801, 835, -1, 866, 1801, 867, -1, 834, 1801, 866, -1, 836, 1802, 835, -1, 868, 1802, 836, -1, 867, 1802, 868, -1, 835, 1802, 867, -1, 837, 1803, 836, -1, 869, 1803, 837, -1, 868, 1803, 869, -1, 836, 1803, 868, -1, 838, 1804, 837, -1, 870, 1804, 838, -1, 869, 1804, 870, -1, 837, 1804, 869, -1, 839, 1805, 838, -1, 871, 1805, 839, -1, 870, 1805, 871, -1, 838, 1805, 870, -1, 840, 1806, 839, -1, 872, 1806, 840, -1, 871, 1806, 872, -1, 839, 1806, 871, -1, 841, 1807, 840, -1, 873, 1807, 841, -1, 872, 1807, 873, -1, 840, 1807, 872, -1, 842, 1808, 841, -1, 874, 1808, 842, -1, 873, 1808, 874, -1, 841, 1808, 873, -1, 843, 1809, 842, -1, 875, 1809, 843, -1, 874, 1809, 875, -1, 842, 1809, 874, -1, 844, 1810, 843, -1, 876, 1810, 844, -1, 875, 1810, 876, -1, 843, 1810, 875, -1, 845, 1811, 844, -1, 877, 1811, 845, -1, 876, 1811, 877, -1, 844, 1811, 876, -1, 846, 1812, 845, -1, 878, 1812, 846, -1, 877, 1812, 878, -1, 845, 1812, 877, -1, 847, 1813, 846, -1, 879, 1813, 847, -1, 878, 1813, 879, -1, 846, 1813, 878, -1, 848, 1814, 847, -1, 880, 1814, 848, -1, 879, 1814, 880, -1, 847, 1814, 879, -1, 849, 1815, 848, -1, 881, 1815, 849, -1, 880, 1815, 881, -1, 848, 1815, 880, -1, 850, 1816, 849, -1, 882, 1816, 850, -1, 881, 1816, 882, -1, 849, 1816, 881, -1, 851, 1817, 850, -1, 883, 1817, 851, -1, 882, 1817, 883, -1, 850, 1817, 882, -1, 852, 1818, 851, -1, 884, 1818, 852, -1, 883, 1818, 884, -1, 851, 1818, 883, -1, 853, 1819, 852, -1, 885, 1819, 853, -1, 884, 1819, 885, -1, 852, 1819, 884, -1, 854, 1820, 853, -1, 886, 1820, 854, -1, 885, 1820, 886, -1, 853, 1820, 885, -1, 855, 1821, 854, -1, 887, 1821, 855, -1, 886, 1821, 887, -1, 854, 1821, 886, -1, 856, 1822, 855, -1, 888, 1822, 856, -1, 887, 1822, 888, -1, 855, 1822, 887, -1, 857, 1823, 856, -1, 889, 1823, 857, -1, 888, 1823, 889, -1, 856, 1823, 888, -1, 858, 1824, 857, -1, 890, 1824, 858, -1, 889, 1824, 890, -1, 857, 1824, 889, -1, 859, 1825, 858, -1, 891, 1825, 859, -1, 890, 1825, 891, -1, 858, 1825, 890, -1, 860, 1826, 859, -1, 892, 1826, 860, -1, 891, 1826, 892, -1, 859, 1826, 891, -1, 861, 1827, 860, -1, 893, 1827, 861, -1, 892, 1827, 893, -1, 860, 1827, 892, -1, 862, 1828, 861, -1, 894, 1828, 862, -1, 893, 1828, 894, -1, 861, 1828, 893, -1, 863, 1829, 862, -1, 895, 1829, 863, -1, 894, 1829, 895, -1, 862, 1829, 894, -1, 865, 1830, 864, -1, 897, 1830, 865, -1, 896, 1830, 897, -1, 864, 1830, 896, -1, 866, 1831, 865, -1, 898, 1831, 866, -1, 897, 1831, 898, -1, 865, 1831, 897, -1, 867, 1832, 866, -1, 899, 1832, 867, -1, 898, 1832, 899, -1, 866, 1832, 898, -1, 868, 1833, 867, -1, 900, 1833, 868, -1, 899, 1833, 900, -1, 867, 1833, 899, -1, 869, 1834, 868, -1, 901, 1834, 869, -1, 900, 1834, 901, -1, 868, 1834, 900, -1, 870, 1835, 869, -1, 902, 1835, 870, -1, 901, 1835, 902, -1, 869, 1835, 901, -1, 871, 1836, 870, -1, 903, 1836, 871, -1, 902, 1836, 903, -1, 870, 1836, 902, -1, 872, 1837, 871, -1, 904, 1837, 872, -1, 903, 1837, 904, -1, 871, 1837, 903, -1, 873, 1838, 872, -1, 905, 1838, 873, -1, 904, 1838, 905, -1, 872, 1838, 904, -1, 874, 1839, 873, -1, 906, 1839, 874, -1, 905, 1839, 906, -1, 873, 1839, 905, -1, 875, 1840, 874, -1, 907, 1840, 875, -1, 906, 1840, 907, -1, 874, 1840, 906, -1, 876, 1841, 875, -1, 908, 1841, 876, -1, 907, 1841, 908, -1, 875, 1841, 907, -1, 877, 1842, 876, -1, 909, 1842, 877, -1, 908, 1842, 909, -1, 876, 1842, 908, -1, 878, 1843, 877, -1, 910, 1843, 878, -1, 909, 1843, 910, -1, 877, 1843, 909, -1, 879, 1844, 878, -1, 911, 1844, 879, -1, 910, 1844, 911, -1, 878, 1844, 910, -1, 880, 1845, 879, -1, 912, 1845, 880, -1, 911, 1845, 912, -1, 879, 1845, 911, -1, 881, 1846, 880, -1, 913, 1846, 881, -1, 912, 1846, 913, -1, 880, 1846, 912, -1, 882, 1847, 881, -1, 914, 1847, 882, -1, 913, 1847, 914, -1, 881, 1847, 913, -1, 883, 1848, 882, -1, 915, 1848, 883, -1, 914, 1848, 915, -1, 882, 1848, 914, -1, 884, 1849, 883, -1, 916, 1849, 884, -1, 915, 1849, 916, -1, 883, 1849, 915, -1, 885, 1850, 884, -1, 917, 1850, 885, -1, 916, 1850, 917, -1, 884, 1850, 916, -1, 886, 1851, 885, -1, 918, 1851, 886, -1, 917, 1851, 918, -1, 885, 1851, 917, -1, 887, 1852, 886, -1, 919, 1852, 887, -1, 918, 1852, 919, -1, 886, 1852, 918, -1, 888, 1853, 887, -1, 920, 1853, 888, -1, 919, 1853, 920, -1, 887, 1853, 919, -1, 889, 1854, 888, -1, 921, 1854, 889, -1, 920, 1854, 921, -1, 888, 1854, 920, -1, 890, 1855, 889, -1, 922, 1855, 890, -1, 921, 1855, 922, -1, 889, 1855, 921, -1, 891, 1856, 890, -1, 923, 1856, 891, -1, 922, 1856, 923, -1, 890, 1856, 922, -1, 892, 1857, 891, -1, 924, 1857, 892, -1, 923, 1857, 924, -1, 891, 1857, 923, -1, 893, 1858, 892, -1, 925, 1858, 893, -1, 924, 1858, 925, -1, 892, 1858, 924, -1, 894, 1859, 893, -1, 926, 1859, 894, -1, 925, 1859, 926, -1, 893, 1859, 925, -1, 895, 1860, 894, -1, 927, 1860, 895, -1, 926, 1860, 927, -1, 894, 1860, 926, -1, 897, 1861, 896, -1, 929, 1861, 897, -1, 928, 1861, 929, -1, 896, 1861, 928, -1, 898, 1862, 897, -1, 930, 1862, 898, -1, 929, 1862, 930, -1, 897, 1862, 929, -1, 899, 1863, 898, -1, 931, 1863, 899, -1, 930, 1863, 931, -1, 898, 1863, 930, -1, 900, 1864, 899, -1, 932, 1864, 900, -1, 931, 1864, 932, -1, 899, 1864, 931, -1, 901, 1865, 900, -1, 933, 1865, 901, -1, 932, 1865, 933, -1, 900, 1865, 932, -1, 902, 1866, 901, -1, 934, 1866, 902, -1, 933, 1866, 934, -1, 901, 1866, 933, -1, 903, 1867, 902, -1, 935, 1867, 903, -1, 934, 1867, 935, -1, 902, 1867, 934, -1, 904, 1868, 903, -1, 936, 1868, 904, -1, 935, 1868, 936, -1, 903, 1868, 935, -1, 905, 1869, 904, -1, 937, 1869, 905, -1, 936, 1869, 937, -1, 904, 1869, 936, -1, 906, 1870, 905, -1, 938, 1870, 906, -1, 937, 1870, 938, -1, 905, 1870, 937, -1, 907, 1871, 906, -1, 939, 1871, 907, -1, 938, 1871, 939, -1, 906, 1871, 938, -1, 908, 1872, 907, -1, 940, 1872, 908, -1, 939, 1872, 940, -1, 907, 1872, 939, -1, 909, 1873, 908, -1, 941, 1873, 909, -1, 940, 1873, 941, -1, 908, 1873, 940, -1, 910, 1874, 909, -1, 942, 1874, 910, -1, 941, 1874, 942, -1, 909, 1874, 941, -1, 911, 1875, 910, -1, 943, 1875, 911, -1, 942, 1875, 943, -1, 910, 1875, 942, -1, 912, 1876, 911, -1, 944, 1876, 912, -1, 943, 1876, 944, -1, 911, 1876, 943, -1, 913, 1877, 912, -1, 945, 1877, 913, -1, 944, 1877, 945, -1, 912, 1877, 944, -1, 914, 1878, 913, -1, 946, 1878, 914, -1, 945, 1878, 946, -1, 913, 1878, 945, -1, 915, 1879, 914, -1, 947, 1879, 915, -1, 946, 1879, 947, -1, 914, 1879, 946, -1, 916, 1880, 915, -1, 948, 1880, 916, -1, 947, 1880, 948, -1, 915, 1880, 947, -1, 917, 1881, 916, -1, 949, 1881, 917, -1, 948, 1881, 949, -1, 916, 1881, 948, -1, 918, 1882, 917, -1, 950, 1882, 918, -1, 949, 1882, 950, -1, 917, 1882, 949, -1, 919, 1883, 918, -1, 951, 1883, 919, -1, 950, 1883, 951, -1, 918, 1883, 950, -1, 920, 1884, 919, -1, 952, 1884, 920, -1, 951, 1884, 952, -1, 919, 1884, 951, -1, 921, 1885, 920, -1, 953, 1885, 921, -1, 952, 1885, 953, -1, 920, 1885, 952, -1, 922, 1886, 921, -1, 954, 1886, 922, -1, 953, 1886, 954, -1, 921, 1886, 953, -1, 923, 1887, 922, -1, 955, 1887, 923, -1, 954, 1887, 955, -1, 922, 1887, 954, -1, 924, 1888, 923, -1, 956, 1888, 924, -1, 955, 1888, 956, -1, 923, 1888, 955, -1, 925, 1889, 924, -1, 957, 1889, 925, -1, 956, 1889, 957, -1, 924, 1889, 956, -1, 926, 1890, 925, -1, 958, 1890, 926, -1, 957, 1890, 958, -1, 925, 1890, 957, -1, 927, 1891, 926, -1, 959, 1891, 927, -1, 958, 1891, 959, -1, 926, 1891, 958, -1, 929, 1892, 928, -1, 961, 1892, 929, -1, 960, 1892, 961, -1, 928, 1892, 960, -1, 930, 1893, 929, -1, 962, 1893, 930, -1, 961, 1893, 962, -1, 929, 1893, 961, -1, 931, 1894, 930, -1, 963, 1894, 931, -1, 962, 1894, 963, -1, 930, 1894, 962, -1, 932, 1895, 931, -1, 964, 1895, 932, -1, 963, 1895, 964, -1, 931, 1895, 963, -1, 933, 1896, 932, -1, 965, 1896, 933, -1, 964, 1896, 965, -1, 932, 1896, 964, -1, 934, 1897, 933, -1, 966, 1897, 934, -1, 965, 1897, 966, -1, 933, 1897, 965, -1, 935, 1898, 934, -1, 967, 1898, 935, -1, 966, 1898, 967, -1, 934, 1898, 966, -1, 936, 1899, 935, -1, 968, 1899, 936, -1, 967, 1899, 968, -1, 935, 1899, 967, -1, 937, 1900, 936, -1, 969, 1900, 937, -1, 968, 1900, 969, -1, 936, 1900, 968, -1, 938, 1901, 937, -1, 970, 1901, 938, -1, 969, 1901, 970, -1, 937, 1901, 969, -1, 939, 1902, 938, -1, 971, 1902, 939, -1, 970, 1902, 971, -1, 938, 1902, 970, -1, 940, 1903, 939, -1, 972, 1903, 940, -1, 971, 1903, 972, -1, 939, 1903, 971, -1, 941, 1904, 940, -1, 973, 1904, 941, -1, 972, 1904, 973, -1, 940, 1904, 972, -1, 942, 1905, 941, -1, 974, 1905, 942, -1, 973, 1905, 974, -1, 941, 1905, 973, -1, 943, 1906, 942, -1, 975, 1906, 943, -1, 974, 1906, 975, -1, 942, 1906, 974, -1, 944, 1907, 943, -1, 976, 1907, 944, -1, 975, 1907, 976, -1, 943, 1907, 975, -1, 945, 1908, 944, -1, 977, 1908, 945, -1, 976, 1908, 977, -1, 944, 1908, 976, -1, 946, 1909, 945, -1, 978, 1909, 946, -1, 977, 1909, 978, -1, 945, 1909, 977, -1, 947, 1910, 946, -1, 979, 1910, 947, -1, 978, 1910, 979, -1, 946, 1910, 978, -1, 948, 1911, 947, -1, 980, 1911, 948, -1, 979, 1911, 980, -1, 947, 1911, 979, -1, 949, 1912, 948, -1, 981, 1912, 949, -1, 980, 1912, 981, -1, 948, 1912, 980, -1, 950, 1913, 949, -1, 982, 1913, 950, -1, 981, 1913, 982, -1, 949, 1913, 981, -1, 951, 1914, 950, -1, 983, 1914, 951, -1, 982, 1914, 983, -1, 950, 1914, 982, -1, 952, 1915, 951, -1, 984, 1915, 952, -1, 983, 1915, 984, -1, 951, 1915, 983, -1, 953, 1916, 952, -1, 985, 1916, 953, -1, 984, 1916, 985, -1, 952, 1916, 984, -1, 954, 1917, 953, -1, 986, 1917, 954, -1, 985, 1917, 986, -1, 953, 1917, 985, -1, 955, 1918, 954, -1, 987, 1918, 955, -1, 986, 1918, 987, -1, 954, 1918, 986, -1, 956, 1919, 955, -1, 988, 1919, 956, -1, 987, 1919, 988, -1, 955, 1919, 987, -1, 957, 1920, 956, -1, 989, 1920, 957, -1, 988, 1920, 989, -1, 956, 1920, 988, -1, 958, 1921, 957, -1, 990, 1921, 958, -1, 989, 1921, 990, -1, 957, 1921, 989, -1, 959, 1922, 958, -1, 991, 1922, 959, -1, 990, 1922, 991, -1, 958, 1922, 990, -1, 960, 961, 992, -1, 961, 962, 993, -1, 962, 963, 994, -1, 963, 964, 995, -1, 964, 965, 996, -1, 965, 966, 997, -1, 966, 967, 998, -1, 967, 968, 999, -1, 968, 969, 1000, -1, 969, 970, 1001, -1, 970, 971, 1002, -1, 971, 972, 1003, -1, 972, 973, 1004, -1, 973, 974, 1005, -1, 974, 975, 1006, -1, 975, 976, 1007, -1, 976, 977, 1008, -1, 977, 978, 1009, -1, 978, 979, 1010, -1, 979, 980, 1011, -1, 980, 981, 1012, -1, 981, 982, 1013, -1, 982, 983, 1014, -1, 983, 984, 1015, -1, 984, 985, 1016, -1, 985, 986, 1017, -1, 986, 987, 1018, -1, 987, 988, 1019, -1, 988, 989, 1020, -1, 989, 990, 1021, -1, 990, 991, 1022, -1 };
    NurbsSurface1.texCoordIndex = m_texCoordIndex;
    NurbsSurface1.texCoordIndex_length = sizeof(m_texCoordIndex) / sizeof(int);
    }
    {
    static float m_radianceTransfer[1];
    NurbsSurface1.radianceTransfer = NULL;
    NurbsSurface1.radianceTransfer_length = 0;
    }
    {
    static int m_set_colorIndex[1];
    NurbsSurface1.set_colorIndex = NULL;
    NurbsSurface1.set_colorIndex_length = 0;
    }
    {
    static int m_set_coordIndex[1];
    NurbsSurface1.set_coordIndex = NULL;
    NurbsSurface1.set_coordIndex_length = 0;
    }
    {
    static int m_set_normalIndex[1];
    NurbsSurface1.set_normalIndex = NULL;
    NurbsSurface1.set_normalIndex_length = 0;
    }
    {
    static int m_set_texCoordIndex[1];
    NurbsSurface1.set_texCoordIndex = NULL;
    NurbsSurface1.set_texCoordIndex_length = 0;
    }
    Shape_14.appearance = &Appearance_15;
    Shape_14.geometry = &NurbsSurface1;
    Shape_14.octreeTriangles = NULL;
    Shape_14.shading = "DEFAULT";
    TimeSensor1.m_parent = (X3dNode *)&Transform1;
    TimeSensor1.cycleInterval = 4;
    TimeSensor1.enabled = true;
    TimeSensor1.loop = false;
    TimeSensor1.startTime = 0;
    TimeSensor1.stopTime = 0;
    TimeSensor1.cycleTime = 0;
    TimeSensor1.fraction_changed = 0;
    TimeSensor1.isActive = false;
    TimeSensor1.time = 0;
    CoordinateInterpolator1.m_parent = (X3dNode *)&Transform1;
    {
    static float m_key[] = { 0, 1 };
    CoordinateInterpolator1.key = m_key;
    CoordinateInterpolator1.key_length = sizeof(m_key) / sizeof(float);
    }
    {
    static float m_keyValue[] = { 0, -1, 0, 0, -0.707107, 0, 0, -1, 0, 0, -0.707107, 0, 0, -1, 0, 0, -0.707107, 0, 0, -1, 0, 0, -0.707107, 0, 0, -1, 0, 0, -0.707107, -0.707107, -0.500000, -0.500000, -0.500000, -0.707107, -0.707107, 0, -0.500000, -0.500000, 0.500000, 0, -0.707107, 0.707107, 0.500000, -0.500000, 0.500000, 0.707107, -0.707107, 0, 0.500000, -0.500000, -0.500000, 0, -0.707107, -0.707107, 0, 0, -1, -0.707107, 0, -0.707107, -1, 0, 0, -0.707107, 0, 0.707107, 0, 0, 1, 0.707107, 0, 0.707107, 1, 0, 0, 0.707107, 0, -0.707107, 0, 0, -1, 0, 0.707107, -0.707107, -0.500000, 0.500000, -0.500000, -0.707107, 0.707107, 0, -0.493697, 0.500000, 0.500000, 0, 0.707107, 0.707107, 0.500000, 0.500000, 0.500000, 0.707107, 0.707107, 0, 0.500000, 0.447772, -0.500000, 0, 0.707107, -0.707107, 0, 1, 0, 0, 0.707107, 0, 0, 1, 0, 0, 0.707107, 0, 0, 1, 0, 0, 0.707107, 0, 0, 1, 0, 0, 0.707107, 0, 0, 1, 0, 0, -1.641960, -0.106933, 0, -1.161041, -0.075613, 0, -1.641960, -0.106933, 0, -1.161041, -0.075613, 0, -1.641960, -0.106933, 0, -1.161041, -0.075613, 0, -1.641960, -0.106933, 0, -1.161041, -0.075613, 0, -1.641960, -0.106933, 0, -1.306497, -0.738463, -0.263081, -0.410032, -0.503937, -0.372053, -0.579872, -0.005568, -0.263081, -0.410032, 0.496063, 0, -0.823694, 0.680927, 0.263081, -0.410032, 0.496063, 0.372053, -0.579872, -0.005568, 0.263081, -0.410032, -0.503937, 0, -1.306497, -0.738463, 0, 0, -1, -0.707107, 0, -0.707107, -1, 0, 0, -0.707107, 0, 0.707107, 0, 0, 1, 0.707107, 0, 0.707107, 1, 0, 0, 0.707107, 0, -0.707107, 0, 0, -1, 0, 0.707107, -0.707107, -1.307082, 1.195424, -0.500000, -1.848494, 1.690584, 0, -1.307082, 1.195424, 0.500000, 0, 0.707107, 0.707107, 1.307082, 1.195424, 0.500000, 1.848494, 1.690584, 0, 1.307082, 1.195424, -0.500000, 0, 0.707107, -0.707107, 0, 1, 0, 0, 0.707107, 0, 0, 1, 0, 0, 0.707107, 0, 0, 1, 0, 0, 0.707107, 0, 0, 1, 0, 0, 0.707107, 0, 0, 1, 0 };
    CoordinateInterpolator1.keyValue = m_keyValue;
    CoordinateInterpolator1.keyValue_length = sizeof(m_keyValue) / sizeof(float);
    }
    CoordinateInterpolator1.set_fraction = 0;
    {
    static float m_value_changed[1];
    CoordinateInterpolator1.value_changed = NULL;
    CoordinateInterpolator1.value_changed_length = 0;
    }
    ColorInterpolator1.m_parent = (X3dNode *)&Transform1;
    {
    static float m_key[] = { 0, 1 };
    ColorInterpolator1.key = m_key;
    ColorInterpolator1.key_length = sizeof(m_key) / sizeof(float);
    }
    {
    static float m_keyValue[] = { 0.137255, 0.113725, 1, 1, 0.086275, 0.168627 };
    ColorInterpolator1.keyValue = m_keyValue;
    ColorInterpolator1.keyValue_length = sizeof(m_keyValue) / sizeof(float);
    }
    ColorInterpolator1.set_fraction = 0;
    {
    static float m_value_changed[] = { 1, 1, 1 };
    ColorInterpolator1.value_changed = m_value_changed;
    ColorInterpolator1.value_changed_length = sizeof(m_value_changed) / sizeof(float);
    }
    {
    static float m_rotation[] = { 0, 0, 1, 0 };
    Transform1.rotation = m_rotation;
    Transform1.rotation_length = sizeof(m_rotation) / sizeof(float);
    }
    {
    static float m_translation[] = { 0, -1.044069, 1.307000e-3 };
    Transform1.translation = m_translation;
    Transform1.translation_length = sizeof(m_translation) / sizeof(float);
    }
    {
    static float m_bboxCenter[] = { 0, 0, 0 };
    Transform1.bboxCenter = m_bboxCenter;
    Transform1.bboxCenter_length = sizeof(m_bboxCenter) / sizeof(float);
    }
    {
    static float m_bboxSize[] = { -1, -1, -1 };
    Transform1.bboxSize = m_bboxSize;
    Transform1.bboxSize_length = sizeof(m_bboxSize) / sizeof(float);
    }
    {
    static float m_center[] = { 0, 0, 0 };
    Transform1.center = m_center;
    Transform1.center_length = sizeof(m_center) / sizeof(float);
    }
    {
    static float m_scale[] = { 1, 1, 1 };
    Transform1.scale = m_scale;
    Transform1.scale_length = sizeof(m_scale) / sizeof(float);
    }
    {
    static float m_scaleOrientation[] = { 0, 0, 1, 0 };
    Transform1.scaleOrientation = m_scaleOrientation;
    Transform1.scaleOrientation_length = sizeof(m_scaleOrientation) / sizeof(float);
    }
    {
    static X3dNode* m_children[] = { &Shape_14, &TimeSensor1, &CoordinateInterpolator1, &ColorInterpolator1 };
    Transform1.children = m_children;
    Transform1.children_length = sizeof(m_children) / sizeof(X3dNode*);
    }
    {
    static X3dNode* m_addChildren[1];
    Transform1.addChildren = NULL;
    Transform1.addChildren_length = 0;
    }
    {
    static X3dNode* m_removeChildren[1];
    Transform1.removeChildren = NULL;
    Transform1.removeChildren_length = 0;
    }
    PositionInterpolator1.m_parent = (X3dNode *)&root;
    {
    static float m_key[] = { 0, 1 };
    PositionInterpolator1.key = m_key;
    PositionInterpolator1.key_length = sizeof(m_key) / sizeof(float);
    }
    {
    static float m_keyValue[] = { 0, -1.044069, 0.001307, 1.971103, -0.193154, -0.071192 };
    PositionInterpolator1.keyValue = m_keyValue;
    PositionInterpolator1.keyValue_length = sizeof(m_keyValue) / sizeof(float);
    }
    PositionInterpolator1.set_fraction = 0;
    {
    static float m_value_changed[] = { 0, 0, 0 };
    PositionInterpolator1.value_changed = m_value_changed;
    PositionInterpolator1.value_changed_length = sizeof(m_value_changed) / sizeof(float);
    }
    Transform_18.route_sources =  NULL;
    Transform_18.num_route_source = 0;
    Transform_18.m_parent = (X3dNode *)&root;
    Shape_19.m_parent = (X3dNode *)&Transform_18;
    Appearance_20.m_parent = (X3dNode *)&Shape_19;
    Material_21.m_parent = (X3dNode *)&Appearance_20;
    Material_21.ambientIntensity = 0.200000;
    {
    static float m_diffuseColor[] = { 0.800000, 0.800000, 0.800000 };
    Material_21.diffuseColor = m_diffuseColor;
    Material_21.diffuseColor_length = sizeof(m_diffuseColor) / sizeof(float);
    }
    {
    static float m_emissiveColor[] = { 0, 0, 0 };
    Material_21.emissiveColor = m_emissiveColor;
    Material_21.emissiveColor_length = sizeof(m_emissiveColor) / sizeof(float);
    }
    Material_21.shininess = 0.200000;
    {
    static float m_specularColor[] = { 0, 0, 0 };
    Material_21.specularColor = m_specularColor;
    Material_21.specularColor_length = sizeof(m_specularColor) / sizeof(float);
    }
    Material_21.transparency = 0;
    Material_21.mirror = 0;
    {
    static float m_reflSpecular[1];
    Material_21.reflSpecular = NULL;
    Material_21.reflSpecular_length = 0;
    }
    {
    static float m_reflDiffuse[1];
    Material_21.reflDiffuse = NULL;
    Material_21.reflDiffuse_length = 0;
    }
    {
    static float m_transSpecular[1];
    Material_21.transSpecular = NULL;
    Material_21.transSpecular_length = 0;
    }
    {
    static float m_transDiffuse[1];
    Material_21.transDiffuse = NULL;
    Material_21.transDiffuse_length = 0;
    }
    Material_21.reflSpecularExp = 10e5;
    Material_21.transSpecularExp = 10e5;
    Appearance_20.material = &Material_21;
    Appearance_20.texture = NULL;
    Appearance_20.textureTransform = NULL;
    {
    static X3dNode* m_receiveShadows[1];
    Appearance_20.receiveShadows = NULL;
    Appearance_20.receiveShadows_length = 0;
    }
    Appearance_20.shadowCaster = true;
    Appearance_20.normalMap = NULL;
    Appearance_20.heightMap = NULL;
    Appearance_20.heightMapScale = 10.000000e-3;
    {
    static X3dNode* m_effects[1];
    Appearance_20.effects = NULL;
    Appearance_20.effects_length = 0;
    }
    Text_13.setGlName(1);
    Text_13.m_parent = (X3dNode *)&Shape_19;
    Coordinate2.m_parent = (X3dNode *)&Text_13;
    {
    Coordinate2.point = m_point;
    Coordinate2.point_length = sizeof(m_point) / sizeof(float);
    }
    Normal2.m_parent = (X3dNode *)&Text_13;
    {
    Normal2.vector = m_vector;
    Normal2.vector_length = sizeof(m_vector) / sizeof(float);
    }
    TextureCoordinate2.m_parent = (X3dNode *)&Text_13;
    {
    TextureCoordinate2.point = m_point;
    TextureCoordinate2.point_length = sizeof(m_point) / sizeof(float);
    }
    Text_13.color = NULL;
    Text_13.coord = &Coordinate2;
    Text_13.normal = &Normal2;
    Text_13.texCoord = &TextureCoordinate2;
    Text_13.ccw = false;
    {
    Text_13.colorIndex = m_colorIndex;
    Text_13.colorIndex_length = sizeof(m_colorIndex) / sizeof(int);
    }
    Text_13.colorPerVertex = false;
    Text_13.convex = false;
    {
    Text_13.coordIndex = m_coordIndex;
    Text_13.coordIndex_length = sizeof(m_coordIndex) / sizeof(int);
    }
    Text_13.creaseAngle = 0;
    {
    Text_13.normalIndex = m_normalIndex;
    Text_13.normalIndex_length = sizeof(m_normalIndex) / sizeof(int);
    }
    Text_13.normalPerVertex = true;
    Text_13.solid = false;
    {
    Text_13.texCoordIndex = m_texCoordIndex;
    Text_13.texCoordIndex_length = sizeof(m_texCoordIndex) / sizeof(int);
    }
    {
    static float m_radianceTransfer[1];
    Text_13.radianceTransfer = NULL;
    Text_13.radianceTransfer_length = 0;
    }
    {
    static int m_set_colorIndex[1];
    Text_13.set_colorIndex = NULL;
    Text_13.set_colorIndex_length = 0;
    }
    {
    static int m_set_coordIndex[1];
    Text_13.set_coordIndex = NULL;
    Text_13.set_coordIndex_length = 0;
    }
    {
    static int m_set_normalIndex[1];
    Text_13.set_normalIndex = NULL;
    Text_13.set_normalIndex_length = 0;
    }
    {
    static int m_set_texCoordIndex[1];
    Text_13.set_texCoordIndex = NULL;
    Text_13.set_texCoordIndex_length = 0;
    }
    Shape_19.appearance = &Appearance_20;
    Shape_19.geometry = &Text_13;
    Shape_19.octreeTriangles = NULL;
    Shape_19.shading = "DEFAULT";
    {
    static float m_rotation[] = { 0, 0, 1, 0 };
    Transform_18.rotation = m_rotation;
    Transform_18.rotation_length = sizeof(m_rotation) / sizeof(float);
    }
    {
    static float m_translation[] = { -2.787300, 3.118130, 0 };
    Transform_18.translation = m_translation;
    Transform_18.translation_length = sizeof(m_translation) / sizeof(float);
    }
    {
    static float m_bboxCenter[] = { 0, 0, 0 };
    Transform_18.bboxCenter = m_bboxCenter;
    Transform_18.bboxCenter_length = sizeof(m_bboxCenter) / sizeof(float);
    }
    {
    static float m_bboxSize[] = { -1, -1, -1 };
    Transform_18.bboxSize = m_bboxSize;
    Transform_18.bboxSize_length = sizeof(m_bboxSize) / sizeof(float);
    }
    {
    static float m_center[] = { 0, 0, 0 };
    Transform_18.center = m_center;
    Transform_18.center_length = sizeof(m_center) / sizeof(float);
    }
    {
    static float m_scale[] = { 0.566765, 0.566765, 0.566765 };
    Transform_18.scale = m_scale;
    Transform_18.scale_length = sizeof(m_scale) / sizeof(float);
    }
    {
    static float m_scaleOrientation[] = { 0, 0, 1, 0 };
    Transform_18.scaleOrientation = m_scaleOrientation;
    Transform_18.scaleOrientation_length = sizeof(m_scaleOrientation) / sizeof(float);
    }
    {
    static X3dNode* m_children[] = { &Shape_19 };
    Transform_18.children = m_children;
    Transform_18.children_length = sizeof(m_children) / sizeof(X3dNode*);
    }
    {
    static X3dNode* m_addChildren[1];
    Transform_18.addChildren = NULL;
    Transform_18.addChildren_length = 0;
    }
    {
    static X3dNode* m_removeChildren[1];
    Transform_18.removeChildren = NULL;
    Transform_18.removeChildren_length = 0;
    }
    NavigationInfo_23.m_parent = (X3dNode *)&root;
    {
    static float m_avatarSize[] = { 0.250000, 1.600000, 0.750000 };
    NavigationInfo_23.avatarSize = m_avatarSize;
    NavigationInfo_23.avatarSize_length = sizeof(m_avatarSize) / sizeof(float);
    }
    NavigationInfo_23.headlight = true;
    NavigationInfo_23.speed = 1;
    {
    static const char* m_type[] = { "EXAMINE", "ANY" };
    NavigationInfo_23.type = m_type;
    NavigationInfo_23.type_length = sizeof(m_type) / sizeof(const char*);
    }
    NavigationInfo_23.visibilityLimit = 0;
    NavigationInfo_23.blendingSort = "DEFAULT";
    NavigationInfo_23.set_bind = false;
    NavigationInfo_23.isBound = false;
    {
    static X3dNode* m_children[] = { &Transform1, &PositionInterpolator1, &Transform_18, &NavigationInfo_23 };
    root.children = m_children;
    root.children_length = sizeof(m_children) / sizeof(X3dNode*);
    }
    {
    static float m_bboxCenter[] = { 0, 0, 0 };
    root.bboxCenter = m_bboxCenter;
    root.bboxCenter_length = sizeof(m_bboxCenter) / sizeof(float);
    }
    {
    static float m_bboxSize[] = { -1, -1, -1 };
    root.bboxSize = m_bboxSize;
    root.bboxSize_length = sizeof(m_bboxSize) / sizeof(float);
    }
    {
    static X3dNode* m_addChildren[1];
    root.addChildren = NULL;
    root.addChildren_length = 0;
    }
    {
    static X3dNode* m_removeChildren[1];
    root.removeChildren = NULL;
    root.removeChildren_length = 0;
    }
}
X3dNode *X3dSceneGraph::getNodeFromGlName(int glName) {
    switch (glName) {
       case 0:
         return &NurbsSurface1;
       case 1:
         return &Text_13;
    }
    return NULL;
}
void X3dMFBoolSendEvent(bool* target, bool* source, int size) {
    int i;
    if ((target == NULL) || (source == NULL)) return;
    for (i = 0; i < size; i++)
        target[i] = source[i];
}
void X3dMFColorSendEvent(float* target, float* source, int size) {
    int i;
    if ((target == NULL) || (source == NULL)) return;
    for (i = 0; i < size; i++)
        target[i] = source[i];
}
void X3dMFColorRGBASendEvent(float* target, float* source, int size) {
    int i;
    if ((target == NULL) || (source == NULL)) return;
    for (i = 0; i < size; i++)
        target[i] = source[i];
}
void X3dMFDoubleSendEvent(double* target, double* source, int size) {
    int i;
    if ((target == NULL) || (source == NULL)) return;
    for (i = 0; i < size; i++)
        target[i] = source[i];
}
void X3dMFFloatSendEvent(float* target, float* source, int size) {
    int i;
    if ((target == NULL) || (source == NULL)) return;
    for (i = 0; i < size; i++)
        target[i] = source[i];
}
void X3dMFInt32SendEvent(int* target, int* source, int size) {
    int i;
    if ((target == NULL) || (source == NULL)) return;
    for (i = 0; i < size; i++)
        target[i] = source[i];
}
void X3dMFMatrix3fSendEvent(float* target, float* source, int size) {
    int i;
    if ((target == NULL) || (source == NULL)) return;
    for (i = 0; i < size; i++)
        target[i] = source[i];
}
void X3dMFMatrix4fSendEvent(float* target, float* source, int size) {
    int i;
    if ((target == NULL) || (source == NULL)) return;
    for (i = 0; i < size; i++)
        target[i] = source[i];
}
void X3dMFNodeSendEvent(X3dNode** target, X3dNode** source, int size) {
    int i;
    if ((target == NULL) || (source == NULL)) return;
    for (i = 0; i < size; i++)
        target[i] = source[i];
}
void X3dMFRotationSendEvent(float* target, float* source, int size) {
    int i;
    if ((target == NULL) || (source == NULL)) return;
    for (i = 0; i < size; i++)
        target[i] = source[i];
}
void X3dMFStringSendEvent(const char** target, const char** source, int size) {
    int i;
    if ((target == NULL) || (source == NULL)) return;
    for (i = 0; i < size; i++)
        target[i] = source[i];
}
void X3dMFTimeSendEvent(double* target, double* source, int size) {
    int i;
    if ((target == NULL) || (source == NULL)) return;
    for (i = 0; i < size; i++)
        target[i] = source[i];
}
void X3dMFVec2dSendEvent(double* target, double* source, int size) {
    int i;
    if ((target == NULL) || (source == NULL)) return;
    for (i = 0; i < size; i++)
        target[i] = source[i];
}
void X3dMFVec2fSendEvent(float* target, float* source, int size) {
    int i;
    if ((target == NULL) || (source == NULL)) return;
    for (i = 0; i < size; i++)
        target[i] = source[i];
}
void X3dMFVec3dSendEvent(double* target, double* source, int size) {
    int i;
    if ((target == NULL) || (source == NULL)) return;
    for (i = 0; i < size; i++)
        target[i] = source[i];
}
void X3dMFVec3fSendEvent(float* target, float* source, int size) {
    int i;
    if ((target == NULL) || (source == NULL)) return;
    for (i = 0; i < size; i++)
        target[i] = source[i];
}
void X3dMFVec4fSendEvent(float* target, float* source, int size) {
    int i;
    if ((target == NULL) || (source == NULL)) return;
    for (i = 0; i < size; i++)
        target[i] = source[i];
}
void X3dSFBoolSendEvent(bool* target, bool source) {
    *target = source;
}
void X3dSFColorSendEvent(float* target, float* source) {
    int i;
    if ((target == NULL) || (source == NULL)) return;
    for (i = 0; i < 3; i++)
        target[i] = source[i];
}
void X3dSFColorRGBASendEvent(float* target, float* source) {
    int i;
    if ((target == NULL) || (source == NULL)) return;
    for (i = 0; i < 4; i++)
        target[i] = source[i];
}
void X3dSFDoubleSendEvent(double* target, double source) {
    *target = source;
}
void X3dSFFloatSendEvent(float* target, float source) {
    *target = source;
}
void X3dSFImageSendEvent(int* target, int* source, int size) {
    int i;
    if ((target == NULL) || (source == NULL)) return;
    for (i = 0; i < size; i++)
        target[i] = source[i];
}
void X3dSFInt32SendEvent(int* target, int source) {
    *target = source;
}
void X3dSFMatrix3fSendEvent(float* target, float* source) {
    int i;
    if ((target == NULL) || (source == NULL)) return;
    for (i = 0; i < 9; i++)
        target[i] = source[i];
}
void X3dSFMatrix4fSendEvent(float* target, float* source) {
    int i;
    if ((target == NULL) || (source == NULL)) return;
    for (i = 0; i < 9; i++)
        target[i] = source[i];
}
void X3dSFNodeSendEvent(X3dNode** target, X3dNode* source) {
    *target = source;
}
void X3dSFRotationSendEvent(float* target, float* source) {
    int i;
    if ((target == NULL) || (source == NULL)) return;
    for (i = 0; i < 4; i++)
        target[i] = source[i];
}
void X3dSFStringSendEvent(const char** target, const char* source) {
    *target = source;
}
void X3dSFTimeSendEvent(double* target, double source) {
    *target = source;
}
void X3dSFVec2dSendEvent(double* target, double* source) {
    int i;
    if ((target == NULL) || (source == NULL)) return;
    for (i = 0; i < 2; i++)
        target[i] = source[i];
}
void X3dSFVec2fSendEvent(float* target, float* source) {
    int i;
    if ((target == NULL) || (source == NULL)) return;
    for (i = 0; i < 2; i++)
        target[i] = source[i];
}
void X3dSFVec3dSendEvent(double* target, double* source) {
    int i;
    if ((target == NULL) || (source == NULL)) return;
    for (i = 0; i < 3; i++)
        target[i] = source[i];
}
void X3dSFVec3fSendEvent(float* target, float* source) {
    int i;
    if ((target == NULL) || (source == NULL)) return;
    for (i = 0; i < 3; i++)
        target[i] = source[i];
}
void X3dProcessEvents(X3dSceneGraph *self, void *data) {
    int nextEvent = 0;
    if (X3dTimeSensor::processEventCallback != NULL) {
        nextEvent = X3dTimeSensor::processEventCallback(&self->TimeSensor1, "", data);
        if (nextEvent) {
            {
                X3dSFFloatSendEvent(&(self->CoordinateInterpolator1.set_fraction), self->TimeSensor1.fraction_changed);
                if (X3dCoordinateInterpolator::processEventCallback != NULL) {
                    nextEvent = X3dCoordinateInterpolator::processEventCallback(&self->CoordinateInterpolator1, "set_fraction", data);
                    if (nextEvent) {
                        {
                            X3dMFVec3fSendEvent(((X3dCoordinate *)self->NurbsSurface1.coord)->point, self->CoordinateInterpolator1.value_changed, self->CoordinateInterpolator1.value_changed_length);
                            nextEvent = false;
                            {
                                if (nextEvent) {
                                }
                            }
                        }
                    }
                }
            }
            {
                X3dSFFloatSendEvent(&(self->ColorInterpolator1.set_fraction), self->TimeSensor1.fraction_changed);
                if (X3dColorInterpolator::processEventCallback != NULL) {
                    nextEvent = X3dColorInterpolator::processEventCallback(&self->ColorInterpolator1, "set_fraction", data);
                    if (nextEvent) {
                        {
                            X3dSFColorSendEvent(self->Material1.diffuseColor, self->ColorInterpolator1.value_changed);
                            if (X3dMaterial::processEventCallback != NULL) {
                                nextEvent = X3dMaterial::processEventCallback(&self->Material1, "diffuseColor", data);
                                if (nextEvent) {
                                }
                            }
                        }
                    }
                }
            }
            {
                X3dSFFloatSendEvent(&(self->PositionInterpolator1.set_fraction), self->TimeSensor1.fraction_changed);
                if (X3dPositionInterpolator::processEventCallback != NULL) {
                    nextEvent = X3dPositionInterpolator::processEventCallback(&self->PositionInterpolator1, "set_fraction", data);
                    if (nextEvent) {
                        {
                            X3dSFVec3fSendEvent(self->Transform1.translation, self->PositionInterpolator1.value_changed);
                            if (X3dTransform::processEventCallback != NULL) {
                                nextEvent = X3dTransform::processEventCallback(&self->Transform1, "translation", data);
                                if (nextEvent) {
                                }
                            }
                        }
                    }
                }
            }
            {
                X3dSFFloatSendEvent(&(self->CoordinateInterpolator_16.set_fraction), self->TimeSensor1.fraction_changed);
                if (X3dCoordinateInterpolator::processEventCallback != NULL) {
                    nextEvent = X3dCoordinateInterpolator::processEventCallback(&self->CoordinateInterpolator_16, "set_fraction", data);
                    if (nextEvent) {
                        {
                            X3dMFVec3fSendEvent(self->Coordinate_12.point, self->CoordinateInterpolator_16.value_changed, self->CoordinateInterpolator_16.value_changed_length);
                            if (X3dCoordinate::processEventCallback != NULL) {
                                nextEvent = X3dCoordinate::processEventCallback(&self->Coordinate_12, "point", data);
                                if (nextEvent) {
                                }
                            }
                        }
                        {
                            X3dMFVec3fSendEvent(self->Coordinate1.point, self->CoordinateInterpolator_16.value_changed, self->CoordinateInterpolator_16.value_changed_length);
                            if (X3dCoordinate::processEventCallback != NULL) {
                                nextEvent = X3dCoordinate::processEventCallback(&self->Coordinate1, "point", data);
                                if (nextEvent) {
                                }
                            }
                        }
                    }
                }
            }
            {
                X3dSFFloatSendEvent(&(self->NormalInterpolator_17.set_fraction), self->TimeSensor1.fraction_changed);
                if (X3dNormalInterpolator::processEventCallback != NULL) {
                    nextEvent = X3dNormalInterpolator::processEventCallback(&self->NormalInterpolator_17, "set_fraction", data);
                    if (nextEvent) {
                        {
                            X3dMFVec3fSendEvent(self->Normal3.vector, self->NormalInterpolator_17.value_changed, self->NormalInterpolator_17.value_changed_length);
                            if (X3dNormal::processEventCallback != NULL) {
                                nextEvent = X3dNormal::processEventCallback(&self->Normal3, "vector", data);
                                if (nextEvent) {
                                }
                            }
                        }
                        {
                            X3dMFVec3fSendEvent(self->Normal1.vector, self->NormalInterpolator_17.value_changed, self->NormalInterpolator_17.value_changed_length);
                            if (X3dNormal::processEventCallback != NULL) {
                                nextEvent = X3dNormal::processEventCallback(&self->Normal1, "vector", data);
                                if (nextEvent) {
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    reInitSensor(&(self->TimeSensor1));
}