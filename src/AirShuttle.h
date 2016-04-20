#ifndef AIRSHUTTLE_H_
#define AIRSHUTTLE_H_

#include <vector>
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include "Reservation.h"
#include "Van.h"


using namespace std;

class AirShuttle{
	vector<Reservation> reservations;
	vector<Van> vans;

public:
	AirShuttle();
	vector<Reservation> getReservations();
	vector<Van> getVans();
	void addReservation(Reservation r);
	void addVan(Van v1);

};

#endif
