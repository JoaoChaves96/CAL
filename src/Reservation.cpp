#include "Reservation.h"

Reservation::Reservation(Person responsible, string arrivalDate, int numPassengers, string destination){
	this->responsible = responsible;
	this->arrivalDate = arrivalDate;
	this->numPassengers = numPassengers;
	this->destination = destination;
}

Person Reservation::getResponsible() const{
	return responsible;
}

string Reservation::getArrivalDate() const{
	return arrivalDate;
}

int Reservation::getnumPassengers() const{
	return numPassengers;
}

string Reservation::getDestination() const{
	return destination;
}

void Reservation::setArrivalDate(string date){
	this->arrivalDate = date;
}

void Reservation::setnumPassengers(int num){
	this->numPassengers = num;
}

void Reservation::setDestination(string destination){
	this->destination = destination;
}
