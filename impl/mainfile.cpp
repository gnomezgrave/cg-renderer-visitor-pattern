#include <cstdio>
#include <stdio.h>
#include <iostream>

#include "../headers/node.h"

int main(){
	
	SceneGraph sg;
	Geometry g1;
	Group g2;
	
	sg.addNode(&g1);
	sg.addNode(&g2);
	
	return 0;
}