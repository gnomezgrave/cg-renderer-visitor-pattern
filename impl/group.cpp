#include "../headers/group.h"

Group::Group()
{

}
Group::Group(string name){
	setName(name);
}

Group::~Group()
{

}
string Group::getNodeType(){
  return "Group";
}

void Group::accept(class Visitor* visitor){
	
}
