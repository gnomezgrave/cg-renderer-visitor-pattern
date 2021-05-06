#ifndef SCENEGRAPH_H
#define SCENEGRAPH_H

#include "node.h"

class SceneGraph
{
public:
    SceneGraph();
    ~SceneGraph();
	void addNode(Node* parent,Node* child);
	void addNode(Node* child);
	Node* getRoot();
	
	void removeNode(Node* node);
private:
	Node* root;
};

#endif
