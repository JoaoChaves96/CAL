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

void AirShuttle::loadGraph(){
	readNodes(g);
	readEdges(g);
}

void AirShuttle::showNodeID(){
	for (int i = 0; i< g.getVertexSet().size(); i++){
		if (g.getVertexSet().at(i)->getAdj().size() != 0)
		cout <<  g.getVertexSet().at(i)->getAdj().at(0).getWeight() << endl;
	}
}
