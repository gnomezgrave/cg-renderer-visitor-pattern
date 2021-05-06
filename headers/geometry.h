#ifndef GEO_H
#define GEO_H

#include "node.h"
#include "color.h"
#include "material.h"
#include "texture.h"
#include <vr/Vec2.h>
#include <vr/Vec3.h>

class Geometry :  public Node {
public:
    Geometry();
    ~Geometry();
    string getNodeType();
	
	void addVertex(vr::Vec3 v);
	vr::Vec3 getVertex(int i);
	
	void addNormal(vr::Vec3 v);
	vr::Vec3 getNormal(int i);
	
	void addTextureCoords(vr::Vec2 v);
	vr::Vec2 getTextureCoords(int i);
	
	void addMaterial(Material m);
	Material getMaterial(int i);
	
	void setTranslation(vr::Vec3 t);
	vr::Vec3 getTranslation();
	
	void setTexture(const vr::Image* i);
	vr::Image* getTexture();
	
	void accept(class Visitor* visitor);
private:
    vector<vr::Vec3> vertices;
    vector<vr::Vec3> normals;
	vector<vr::Vec2> textures;
    vector<Material> materials;
	vr::Vec3 translation;
	Texture texture;
};

#endif