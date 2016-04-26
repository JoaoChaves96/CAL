#include "AirShuttle.h"

AirShuttle::AirShuttle() {
}

vector<Reservation> AirShuttle::getReservations() {
	return reservations;
}
vector<Van> AirShuttle::getVans() {
	return vans;
}

void AirShuttle::addReservation(Reservation r) {
	reservations.push_back(r);
}

void AirShuttle::addVan(Van v) {
	vans.push_back(v);
}

void AirShuttle::loadGraph() {
	readNodes(g);
	readEdges(g);
}

void AirShuttle::showNodeID() {
	for (int i = 0; i < g.getVertexSet().size(); i++) {
		if (g.getVertexSet().at(i)->getAdj().size() != 0)
			cout << g.getVertexSet().at(i)->getAdj().at(0).getWeight() << endl;
	}
}

void AirShuttle::loadReservations() {
	ifstream inFile;

	//Ler o ficheiro nos.txt
	inFile.open("reservas.txt");

	if (!inFile) {
		cerr << "Unable to open file datafile.txt";
		exit(1);
	}

	std::string line;

	unsigned long nif = 0;
	string name;
	string dateh;
	string datem;
	int dest;

	while (std::getline(inFile, line)) {
		std::stringstream linestream(line);
		std::string data;
		int hour, min;

		std::stringstream s(line);
		std::getline(linestream, name, ';'); // read up-to the first ; (discard ;).

		std::getline(s, data, ';');
		s >> nif;
		std::getline(linestream, data, ';');
		linestream >> hour;
		std::getline(linestream, data, ';'); // read up-to the first ; (discard ;).
		linestream >> min;
		std::getline(linestream, data, ';'); // read up-to the first ; (discard ;).
		linestream >> dest;

		Person p1(name, nif);
		Date d(hour, min);
		Reservation r(p1, d, dest);
		reservations.push_back(r);

	}

	sort(reservations.begin(), reservations.end());

	inFile.close();
}

void AirShuttle::loadVans() {
	ifstream inFile;

	//Ler o ficheiro nos.txt
	inFile.open("vans.txt");

	if (!inFile) {
		cerr << "Unable to open file datafile.txt";
		exit(1);
	}

	int cap;
	std::string line;

	while (std::getline(inFile, line)) {
		std::stringstream linestream(line);

		linestream >> cap;

		Van v(cap);
		vans.push_back(v);
	}

	inFile.close();
}

void AirShuttle::transportClient() {

	int l = 0;
	while (!reservations.empty() && l < vans.size()) {
		int i = 0;
		while (i < vans.at(l).getCapacity() && !reservations.empty()) {
			int j = 0;
			for (int k = 0; k < vans.at(l).getRes().size(); k++) {
				if (exceedsTime(vans.at(l).getRes().at(k),
						reservations.at(0))) {
					j++;
				}
			}
			if (j == 0) {
				vans.at(l).addRes(reservations.at(0));
				reservations.erase(reservations.begin());
				i++;
			} else
				break;
		}
			l++;
	}

	//Date out = reservations.at(reservations.size() - 1).getArrivalDate();


	/*for (int i = 0; i < this->vans.size(); i++) {
		if (vans.at(i).getRes().size() == 0)
			break;
		Date out = vans.at(i).getRes().at( vans.at(i).getRes().size() - 1).getArrivalDate();
		cout << endl << endl << "Carrinha " << vans.at(i).getId() << ": Hora de partida: " << out.getHour() << ":" << out.getMin() << "h" << endl;
		cout  << endl << "Clientes transportados:" << endl;
			for (int j = 0; j < vans.at(i).getRes().size(); j++) {
				cout << endl << vans.at(i).getRes().at(j).getResponsible().getName() << "   ---------->   "  << vans.at(i).getRes().at(j).getDestination();
			}
	}*/
	vans.at(0).getPath(g);

}
