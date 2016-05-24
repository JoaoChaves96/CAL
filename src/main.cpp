#include "AirShuttle.h"
#include "Person.h"
#include "readFiles.h"
#include <iostream>
#include <conio.h>
#include <iomanip>


using namespace std;


int mainMenu(AirShuttle a1);

/**
 * Menu of the vans
 */
int VansMenu(AirShuttle a1){
	system("cls");

	cout << "List of Vans:" << endl;

	a1.transportClient();
	getchar();

	mainMenu(a1);
	return 0;
}

/**
 * Menu of the reservations
 */
int ReservationsMenu(AirShuttle a1){
	system("cls");
	vector<string> hotels = getHotels();

	cout << setw(8) << "Name" << setw(15) << "NIF" << setw(20) << "ArrivalDate" << setw(30) << "Destination" << endl << endl;


	for (int i = 0; i < a1.getReservations().size(); i++){
		cout << setw(10) << a1.getReservations().at(i).getResponsible().getName();
		cout << setw(18) << a1.getReservations().at(i).getResponsible().getNIF();
		cout << setw(12) << a1.getReservations().at(i).getArrivalDate().getHour() << ":" << a1.getReservations().at(i).getArrivalDate().getMin() <<
				"h";
		cout << setw(35) << hotels.at(a1.getReservations().at(i).getDestination() - 1) << endl;
	}

	getchar();
	mainMenu(a1);

	return 0;
}

/**
 * Main menu
 */
int mainMenu(AirShuttle a1){

	int option;

	cout << "#################" << endl;
	cout << "#               #" << endl;
	cout << "#  AIR SHUTTLE  #" << endl;
	cout << "#               #" << endl;
	cout << "#################" << endl;

	cout << endl << endl << "1 - Reservations" << endl;
	cout << "2 - Vans" << endl;
	cout << "3 - Transport passengers" << endl;
	cout << "4 - Pesquisa Carrinha Exata" << endl;
	cout << "5 - Pesquisa Carrinha Aproximada" << endl;
	cout << "6 - Pesquisa Cliente Exata" << endl;
	cout << "7 - Pesquisa Cliente Aproximada" << endl;
	cout << "8 - Exit" << endl;
	cin >> option;
	switch (option){
	case 1:
		ReservationsMenu(a1);
		break;
	case 2:
		VansMenu(a1);
		break;
	case 3:
		getchar();
		a1.showPath();
		mainMenu(a1);
		break;
	case 4:

		mainMenu(a1);
		break;
	case 5:

		mainMenu(a1);
		break;
	case 6:

		mainMenu(a1);
		break;
	case 7:

		mainMenu(a1);
		break;
	case 8:
		exit(0);
		break;
	}
}

int main(){
	AirShuttle a1;
	a1.loadGraph();

	a1.loadReservations();
	a1.loadVans();

	mainMenu(a1);


	return 0;
}
