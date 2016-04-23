#ifndef VAN_H_
#define VAN_H_

class Van{
	int capacity;
	int ID;
	int ocupation;
public:
	Van(int capacity);

	int getCapacity() const;

	int getId() const;

	int getOcupation() const;

	void incOcupation();

	void resetOcupation();
};

#endif
