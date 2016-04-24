#include "AirShuttle.h"
#include "Person.h"
#include "readFiles.h"
#include <iostream>



using namespace std;

int main(){
	AirShuttle a1;
	//a1.loadGraph();
	//a1.showNodeID();
	a1.loadReservations();
	a1.loadVans();

	a1.transportClient();

	return 0;
}
