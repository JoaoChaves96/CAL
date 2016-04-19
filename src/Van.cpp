#include "Van.h"

Van::Van(int capacity, int ID){
	this->capacity = capacity;
	this->ID = ID;
	this->ocupation = 0;
}

int Van::getCapacity() const {
	return capacity;
}

int Van::getId() const {
	return ID;
}

int Van::getOcupation() const {
	return ocupation;
}

void Van::incOcupation(){
	ocupation++;
}

void Van::resetOcupation(){
	this->ocupation = 0;
}
