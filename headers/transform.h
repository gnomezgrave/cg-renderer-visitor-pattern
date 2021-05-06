#ifndef TRANSFORM_H
#define TRANSFORM_H

#include "group.h"
#include <vr/Matrix.h>

class Transform :  public Group
{
public:
    Transform();
    ~Transform();

    vr::Matrix* getTranslateMatrix();
    void setTranslateMatrix(vr::Matrix* translateM);
    
    vr::Matrix* getRotateMatrix();
    void setRotateMatrix(vr::Matrix* rotateM);
    
    vr::Matrix* getScaleMatrix();
    void setScaleMatrix(vr::Matrix* scaleM);

    string getNodeType();
	
	void accept(class Visitor* visitor);
    
private:
    vr::Matrix* translateM;
    vr::Matrix* rotateM;
    vr::Matrix* scaleM;
};

#endif