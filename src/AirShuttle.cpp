#include "AirShuttle.h"

AirShuttle::AirShuttle() {}

vector<Reservation> AirShuttle::getReservations(){
	return reservations;
}
vector<Van> AirShuttle::getVans(){
	return vans;
}

void AirShuttle::addReservation(Reservation r){
	reservations.push_back(r);
}

void AirShuttle::addVan(Van v){
	vans.push_back(v);
}
