#ifndef RESERVATION_H_
#define RESERVATION_H_

#include <string>
#include "Person.h"

using namespace std;

class Reservation{
	Person responsible;
	string arrivalDate;
	int numPassengers;
	string destination;

public:
	Reservation(Person responsible, string arrivalDate, int numPassengers, string destination);
	Person getResponsible() const;
	string getArrivalDate() const;
	int getnumPassengers() const;
	string getDestination() const;
	void setArrivalDate(string date);
	void setnumPassengers(int num);
	void setDestination(string destination);
};

#endif
