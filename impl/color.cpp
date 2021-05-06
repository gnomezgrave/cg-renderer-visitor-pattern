/*
 *
 */

#include "../headers/color.h"

Color::Color()
{
  color=0x000000FF;
}
Color::Color(int red,int green,int blue,int alpha)
{
  setColors( red, green, blue, alpha);
}
Color::~Color()
{

}

void Color::setColors(int red,int green,int blue,int alpha){
  red = red & 0xFF;
  green = green & 0xFF;
  blue = blue & 0xFF;
  alpha = alpha & 0xFF;
  
  color= (red<<24) | (green << 16) | (blue << 8) | alpha;
}
void Color::setColors(unsigned int color){
  int red = (color >>24);
  int green = (color>>16) & 0xFF;
  int blue = (color>>8) & 0xFF;
  int alpha = color & 0xFF;
  
  this->color= (red<<24) | (green << 16) | (blue << 8) | alpha;
}

vector<int> Color::getColors(){
  vector<int> v;
  v.push_back(getRed());
  v.push_back(getBlue());
  v.push_back(getGreen());
  v.push_back(getAlpha());
  return v;
}

int Color::getRed(){
  return (color&0xFF000000)>>24;
}

void Color::setRed(int red){
  red = red & 0xFF;
  color = (color & 0x00FFFFFF) | (red<<24);
}

int Color::getGreen(){
  return (color&0xFF0000)>>16;
}

void Color::setGreen(int green){
  green = green & 0xFF;
  color = (color & 0xFF00FFFF) | (green<<16);
}

int Color::getBlue(){
  return (color&0xFF00)>>8;
}

void Color::setBlue(int blue){
  blue = blue & 0xFF;
  color = (color & 0xFFFF00FF) | (blue<<8);
}


int Color::getAlpha(){
  return (color&0xFF);
}

void Color::setAlpha(int alpha){
  alpha = alpha & 0xFF;
  color = (color & 0xFFFFFF00) | alpha;
}
