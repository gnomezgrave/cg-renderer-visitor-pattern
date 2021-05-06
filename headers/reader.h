#ifndef READER_H
#define READER_H

#include <stdio.h>
#include <cstdio>
#include <iostream>
#include <vr/AC3DLoader.h>

#include "node.h"
#include "geometry.h"
#include "group.h"
#include "material.h"

class Reader {
public:
	Node* readFromFile(char* fileName);
private:
	vr::AC3DLoader ac;
};

#endif
