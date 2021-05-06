#include "../headers/node.h"

Node::Node(){
  
}

Node::Node(string name){
  this->name = name;
}

Node::~Node(){
  
}
string Node::getName(){
  return name;
}

void Node::setName(string name){
  this->name = name;
}

void Node::addChildNode(Node* child){
	this->children.push_back(child);
}

vector<Node*> Node::getChildrenNodes(){
  return children;
}

Node* Node::getChildNodeAt(int i){
  return children.at(i);
}

size_t Node::getChildNodeCount(){
  return children.size();
}
