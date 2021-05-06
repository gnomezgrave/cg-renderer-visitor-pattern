/*
 *
 */

#include "../headers/visitor.h"
#include "../headers/node.h"

Visitor::Visitor()
{

}

Visitor::~Visitor()
{

}

void Visitor::visit(Group* node){
	size_t size = node->getChildNodeCount();
	vector<Node*> children = node->getChildrenNodes();
	
	for(size_t i = 0; i<size ; size++){
		Node* n = children.at(i);
		n->accept(this);
	}
}
