#include "../headers/geometry.h"

Geometry::Geometry()
{

}

Geometry::~Geometry()
{

}

string Geometry::getNodeType()
{
  return "Geometry";
}

void Geometry::addVertex(vr::Vec3 v){
	this->vertices.push_back(v);
}
vr::Vec3 Geometry::getVertex(int i){
	return this->vertices.at(i);
}

void Geometry::addNormal(vr::Vec3 v){
	this->normals.push_back(v);
}

vr::Vec3 Geometry::getNormal(int i){
	return this->normals.at(i);
}

void Geometry::addTextureCoords(vr::Vec2 v){
	this->textures.push_back(v);
}

vr::Vec2 Geometry::getTextureCoords(int i){
	return this->textures.at(i);
}

void Geometry::addMaterial(Material m){
	this->materials.push_back(m);
}

Material Geometry::getMaterial(int i){
	return this->materials.at(i);
}

void Geometry::setTranslation(vr::Vec3 t){
	this->translation = t;
}

vr::Vec3 Geometry::getTranslation(){
	return this->translation;
}

void Geometry::setTexture(const vr::Image* i){
	
	this->texture.setImage(i);
}

vr::Image* Geometry::getTexture(){
	return this->texture.getImage();
}

void Geometry::accept(class Visitor* visitor){
	
}

