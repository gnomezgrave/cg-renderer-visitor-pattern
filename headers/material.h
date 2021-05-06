#ifndef MAT_H
#define MAT_H

#include <vr/AC3DLoader.h>
#include <vr/Vec3.h>
#include <vr/Vec4.h>

class Material {
public:
    Material();
    ~Material();
	void setValues(vr::AC3DLoader::Material);
	
private:	
	vr::Vec4 ambient;
	vr::Vec4 diffuse;
	vr::Vec4 emission;
	vr::Vec4 specular;
	float shine;
	float trans;
};
#endif

