#include "../headers/transform.h"
#include <vr/Matrix.h>

Transform::Transform()
{
  translateM = new vr::Matrix();
}
Transform::~Transform()
{
  
}
vr::Matrix* Transform::getTranslateMatrix(){
  return translateM;
}

void Transform::setTranslateMatrix(vr::Matrix* translateM){
  this->translateM = translateM;
}

vr::Matrix* Transform::getRotateMatrix(){
  return rotateM;
}

void Transform::setRotateMatrix(vr::Matrix* rotateM){
  this->rotateM = rotateM;
}

vr::Matrix* Transform::getScaleMatrix(){
  return rotateM;
}

void Transform::setScaleMatrix(vr::Matrix* scaleM){
  this->scaleM = scaleM;
}

string Transform::getNodeType(){
  return "Transform";
}

void Transform::accept(class Visitor* visitor){
	
}
