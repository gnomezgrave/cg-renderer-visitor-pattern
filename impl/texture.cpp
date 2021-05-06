/*
 *
 */

#include "../headers/texture.h"

Texture::Texture() {

}

Texture::Texture(const vr::Image* i) {
	this->setImage(i);
}

Texture::~Texture() {

}

void Texture::setImage(const vr::Image* i){
	this->texture->setImage(i->width(),i->height(),i->depth(),i->format(),(unsigned char*)i->data());
}

vr::Image* Texture::getImage(){
	
}
