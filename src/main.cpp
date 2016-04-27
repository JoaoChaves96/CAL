#include "AirShuttle.h"
#include "Person.h"
#include "readFiles.h"
#include <iostream>



using namespace std;

int mainMenu(AirShuttle a1){

	/*int option;

	cout << "#################" << endl;
	cout << "#               #" << endl;
	cout << "#  AIR SHUTTLE  #" << endl;
	cout << "#               #" << endl;
	cout << "#################" << endl;

	cout << endl << endl << "1 - Reservations" << endl;
	cout << "2 - Vans" << endl;
	cout << "3 - Transport passengers" << endl;
	cout << "4 - Exit" << endl;
	cin >> option;
	switch (option){
	case 1:
		ReservationsMenu();
	}

*/
}

int main(){
	AirShuttle a1;
	a1.loadGraph();

	a1.loadReservations();
	a1.loadVans();

	a1.transportClient();
	//getHotels();
	getchar();

	return 0;
}
