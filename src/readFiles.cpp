#include "readFiles.h"
#include "Node.h"
#include "Road.h"
#include "Graph.h"
#include "Subroad.h"

Node * findNode(vector<Node * > nodes, int ID){
	for (int i = 0; i< nodes.size(); i++){
		if (nodes[i]->getId() == ID)
			return nodes[i];
	}
}

void readNodes(Graph<Node, Road> & g) {
	ifstream inFile;

	//vector<Vertex *> ret;

	//Ler o ficheiro nos.txt
	inFile.open("nos.txt");

	if (!inFile) {
		cerr << "Unable to open file datafile.txt";
		exit(1);
	}

	std::string line;

	int idNo = 0;
	double lat_deg, lon_deg, lat_rad, lon_rad;

	while (std::getline(inFile, line)) {
		std::stringstream linestream(line);
		std::string data;

		linestream >> idNo;

		std::getline(linestream, data, ';'); // read up-to the first ; (discard ;).
		linestream >> lat_deg;
		std::getline(linestream, data, ';'); // read up-to the first ; (discard ;).
		linestream >> lon_deg;
		std::getline(linestream, data, ';'); // read up-to the first ; (discard ;).
		linestream >> lat_rad;
		std::getline(linestream, data, ';'); // read up-to the first ; (discard ;).
		linestream >> lon_rad;
		Node n(idNo, lat_deg, lon_deg, lat_rad, lon_rad);
		g.addVertex(n);
		//ret.push_back(&n);

	}

	inFile.close();

}

void readEdges(vector<Node *> nodes, vector<Road *> roads) {
	ifstream inFile;

	//Ler o ficheiro subroads.txt
	inFile.open("subroads.txt");

	if (!inFile) {
		cerr << "Unable to open file datafile.txt";
		exit(1);   // call system to stop
	}

	std::string line;

	int roadID;
	int node1ID, node2ID;

	while (std::getline(inFile, line)) {
		std::stringstream linestream(line);
		std::string data;

		linestream >> roadID;

		std::getline(linestream, data, ';'); // read up-to the first ; (discard ;).
		linestream >> node1ID;
		std::getline(linestream, data, ';'); // read up-to the first ; (discard ;).
		linestream >> node2ID;

		for (int i = 0; i < roads.size(); i++) {
			if (roads[i]->getID() == roadID) {
				//criar edge...
			}
		}

	}

	inFile.close();

}

vector<Road *> readRoads() {
	ifstream inFile;

	vector<Road *> ret;

	//Ler o ficheiro nos.txt
	inFile.open("roads.txt");

	if (!inFile) {
		cerr << "Unable to open file datafile.txt";
		exit(1);
	}

	std::string line;

	int idNo = 0;
	string name;
	string two_way;

	while (std::getline(inFile, line)) {
		std::stringstream linestream(line);
		std::string data;

		linestream >> idNo;

		std::getline(linestream, data, ';'); // read up-to the first ; (discard ;).
		linestream >> name;
		std::getline(linestream, data, ';'); // read up-to the first ; (discard ;).
		linestream >> two_way;

		if (two_way == "FALSE"){
			Road r(idNo, name, false);
			ret.push_back(&r);
		}
		else{
			Road r(idNo, name, true);
			ret.push_back(&r);
		}

	}

	inFile.close();

	return ret;
}

