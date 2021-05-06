#ifndef TEXTURE_H
#define TEXTURE_H

#include <vr/AC3DLoader.h>

class Texture {
public:
	Texture();
	Texture(const vr::Image* i);
	~Texture();
	
	void setImage(const vr::Image* i);
	vr::Image* getImage();
private:
	vr::Image* texture;
};

#endif // TEXTURE_H
