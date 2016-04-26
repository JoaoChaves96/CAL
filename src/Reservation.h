#ifndef RESERVATION_H_
#define RESERVATION_H_

#include <string>
#include "Person.h"
#include "Date.h"

using namespace std;

class Reservation{
	Person responsible;
	Date arrivalDate;
	int destination;

public:
	Reservation(Person responsible, Date arrivalDate, int destination);
	Person getResponsible() const;
	Date getArrivalDate() const;
	int getDestination() const;
	bool operator <(const Reservation r1) const;
};

#endif
