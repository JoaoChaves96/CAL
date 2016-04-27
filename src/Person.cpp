#include "Person.h"

Person::Person(){
	this->name = "";
	this->NIF = 0;
}

/**
 * Person constructor
 */
Person::Person(string name, int NIF){
	this->name = name;
	this->NIF = NIF;
}

string Person::getName() const{
	return name;
}

int Person::getNIF() const {
	return NIF;
}
