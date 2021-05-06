#ifndef COLOR_H
#define COLOR_H

using namespace std;

#include <stdio.h>
#include <vector>


class Color
{
public:
    Color();
	Color(int red,int green,int blue,int alpha);
    ~Color();
    
    vector<int> getColors();
    void setColors(int red,int green,int blue,int alpha);
	void setColors(unsigned int color);
    
    int getRed();
    void setRed(int red);
    
    int getBlue();
    void setBlue(int blue);
    
    int getGreen();
    void setGreen(int green);
    
    int getAlpha();
    void setAlpha(int alpha);
private:
  int color;
};

#endif
