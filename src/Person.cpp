#include "Person.h"

Person::Person(string name, int NIF, int localID){
	this->name = name;
	this->NIF = NIF;
	this->localID = localID;
}

string Person::getName() const{
	return name;
}

int Person::getlocalID() const {
	return localID;
}

int Person::getNIF() const {
	return NIF;
}
