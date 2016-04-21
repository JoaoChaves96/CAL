#include "Road.h"

Road::Road(int ID, string name, bool two_way){
	this->ID = ID;
	this->name = name;
	this->two_way = two_way;
}

int Road::getID() const{
	return ID;
}
