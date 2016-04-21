#include "Subroad.h"

Subroad::Subroad(){}

Subroad::Subroad(Road *road){
	this->road = road;
}

Road Subroad::getRoad() const{
	return *road;
}

Node Subroad::setDestination(Node *from, Node *to){
	this->dest = to;
	this->weight = setWeight(from, to);
}

Node Subroad::getDest() const{
	return *dest;
}

float Subroad::setWeight(Node *from, Node *to){
	int r = 6371; // raio da terra em kms
	float dLat = to->getLatRad()-from->getLatRad();
	float dLon = to->getLonRad()-from->getLonRad();
	float a = sin(dLat/2)*sin(dLat/2) + cos(from->getLatRad()) * cos(to->getLatRad())*sin(dLon/2)*sin(dLon/2);
	float c = 2 * atan2(sqrt(a), sqrt(1-a));
	float d = r * c;

	return d;
}
