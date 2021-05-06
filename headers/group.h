#include "node.h"
#ifndef GROUP_H
#define GROUP_H

class Group : public Node
{
  
public:
    Group();
    ~Group();
    Group(string name);
	
    string getNodeType();

	void accept(class Visitor* visitor);
	
private:
	
};

#endif