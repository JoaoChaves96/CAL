#include "Reservation.h"

Reservation::Reservation(Person responsible, Date arrivalDate, string destination){
	this->responsible = responsible;
	this->arrivalDate = arrivalDate;
	this->destination = destination;
}

Person Reservation::getResponsible() const{
	return responsible;
}

Date Reservation::getArrivalDate() const{
	return arrivalDate;
}

string Reservation::getDestination() const{
	return destination;
}

bool Reservation::operator <(const Reservation r1) const{
	return arrivalDate < r1.getArrivalDate();
}
