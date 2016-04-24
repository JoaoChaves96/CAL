#ifndef VAN_H_
#define VAN_H_

#include "Reservation.h"
#include <vector>

class Van{
	int capacity;
	int ID;
	int ocupation;
	bool isFull;
	vector<Reservation> res;
public:
	Van(int capacity);

	int getCapacity() const;

	int getId() const;

	int getOcupation() const;

	void incOcupation();

	void resetOcupation();

	vector<Reservation> getRes() const;

	void addRes(Reservation res);

	bool is_Full() const;
};

#endif
