#ifndef RENDERVISITOR_H
#define RENDERVISITOR_H

#include "visitor.h"

class RenderVisitor :  public Visitor
{
public:
    RenderVisitor();
    ~RenderVisitor();
	
	void visit(Node* node) = 0;

	void visit(Geometry* node) = 0;
	void visit(Transform* node) = 0;

};

#endif // RENDERVISITOR_H
