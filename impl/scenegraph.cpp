/*
 *
 */

#include "../headers/scenegraph.h"
#include "../headers/group.h"

SceneGraph::SceneGraph() {
    root = new Group("Root");
}

SceneGraph::~SceneGraph() {

}

Node* SceneGraph::getRoot() {
    return root;
}

void SceneGraph::addNode(Node* parent, Node* child) {
    parent->addChildNode(child);
}

void SceneGraph::addNode(Node* child) {
    root->addChildNode(child);
}

void SceneGraph::removeNode(Node* child) {
    
}

