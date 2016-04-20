#include <string>

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
