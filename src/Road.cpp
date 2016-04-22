#include "Road.h"

Road::Road(unsigned long ID, string name, bool two_way){
	this->ID = ID;
	this->name = name;
	this->two_way = two_way;
}

unsigned long Road::getID() const{
	return ID;
}

string Road::getName() const{
	return name;
}
