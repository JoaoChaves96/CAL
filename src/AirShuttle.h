#ifndef AIRSHUTTLE_H_
#define AIRSHUTTLE_H_

#include <vector>
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include "Reservation.h"
#include "Van.h"
#include "Graph.h"
#include "Road.h"
#include "Node.h"
#include "graphviewer.h"
#include "readFiles.h"
#include <string>
#include <algorithm>
#include "Utilities.h"

using namespace std;

class AirShuttle{
	vector<Reservation> reservations;
	vector<Van> vans;
	vector<string> hotels;

public:
	AirShuttle();
	Graph<Node, Road> g;
	GraphViewer *gv;
	vector<Reservation> getReservations();
	vector<Van> getVans();
	void addReservation(Reservation r);
	void addVan(Van v1);
	void loadGraph();
	void showNodeID();
	void loadReservations();
	void loadVans();
	void transportClient();
	void showPath();
};

#endif
