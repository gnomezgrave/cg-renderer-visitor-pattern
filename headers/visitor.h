#ifndef VISITOR_H
#define VISITOR_H

#include "transform.h"
#include "geometry.h"
//#include "node.h"

class Node;

class Visitor
{
public:
    Visitor();
    virtual ~Visitor() = 0;
	
	virtual void visit(Node* node) = 0;
	virtual void visit(Group* node) = 0;
	virtual void visit(Geometry* node) = 0;
	virtual void visit(Transform* node) = 0;

};

#endif // VISITOR_H
