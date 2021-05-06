/*
 *
 */

#include "../headers/material.h"

Material::Material() {

}

Material::~Material() {

}

void Material::setValues(vr::AC3DLoader::Material m){
	diffuse = m.diffuse;
	ambient = m.ambient;
	emission = m.emission;
	specular = m.specular;
	shine = m.shine;
	trans = m.trans;
}