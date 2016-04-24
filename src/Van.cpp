#include "Van.h"

static int id = 0;

Van::Van(int capacity){
	this->capacity = capacity;
	this->ID = id++;
	this->ocupation = 0;
	this->isFull = false;
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

vector<Reservation> Van::getRes() const{
	return res;
}

void Van::addRes(Reservation res){
	this->res.push_back(res);
	if (getRes().size() == capacity){
		isFull = true;
	}
}

bool Van::is_Full() const{
	return isFull;
}
