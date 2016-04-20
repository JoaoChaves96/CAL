#include "readFiles.h"
#include "Node.h"
#include "Road.h"
#include "SubRoad.h"

vector<Node> readNodes(){
	ifstream inFile;

	vector<Node> ret;

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
		ret.push_back(n);


	}

	inFile.close();

	return ret;
}

vector<Road> readRoads(){
	ifstream inFile;

	//Ler o ficheiro roads.txt
	inFile.open("roads.txt");

	vector<Road> ret;

	if (!inFile) {
		cerr << "Unable to open file datafile.txt";
		exit(1);   // call system to stop
	}

	std::string line;

	int ID = 0;
	string name;
	string two_way;

	while (std::getline(inFile, line)) {
		std::stringstream linestream(line);
		std::string data;

		linestream >> ID;

		std::getline(linestream, data, ';'); // read up-to the first ; (discard ;).
		linestream >> name;
		std::getline(linestream, data, ';'); // read up-to the first ; (discard ;).
		linestream >> two_way;

		if (two_way == "FALSE"){
			Road r(ID, name, false);
			ret.push_back(r);
		}
		else{
			Road r(ID, name, true);
			ret.push_back(r);
		}



	}

	inFile.close();

	return ret;
}

vector<SubRoad> readSubRoads(){
	ifstream inFile;

	vector<SubRoad> ret;

	//Ler o ficheiro subroads.txt
		inFile.open("subroads.txt");

		if (!inFile) {
			cerr << "Unable to open file datafile.txt";
			exit(1);
		}

		std::string line;

		int roadID = 0;
		int node1ID = 0;
		int node2ID = 0;

		while (std::getline(inFile, line)) {
			std::stringstream linestream(line);
			std::string data;

			linestream >> roadID;

			std::getline(linestream, data, ';'); // read up-to the first ; (discard ;).
			linestream >> node1ID;
			std::getline(linestream, data, ';'); // read up-to the first ; (discard ;).
			linestream >> node2ID;
			SubRoad s(roadID, node1ID, node2ID);
			ret.push_back(s);
		}

		inFile.close();

		return ret;
}
