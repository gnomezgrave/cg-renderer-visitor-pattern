#ifndef NODE_H
#define NODE_H

using namespace std;

#include <cstdio>
#include <string>
#include <vector>
#include "visitor.h"

class Node{
public:
  Node();
  virtual ~Node() = 0;
  Node(string name);
  
  string getName();
  void setName(string name);
  
  vector<Node*> getChildrenNodes();
  size_t getChildNodeCount();
  Node* getChildNodeAt(int i);
  void setChildernNodes(vector<Node*> children);
  
  void addChildNode(Node* child);
  
  virtual void accept(class Visitor* visitor) = 0;
  
  virtual string getNodeType()=0; // to make this class abstract
  
protected:
  string name;
  vector<Node*> children;
};
#endif

