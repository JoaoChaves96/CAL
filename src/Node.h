#ifndef NODE_H_
#define NODE_H_

class Node{
	int ID;
	double lat_deg;
	double lon_deg;
	double lat_rad;
	double lon_rad;

public:
	Node(int ID, double lat_deg, double lon_deg, double lat_rad, double lon_rad);
	int getId() const;
	double getLatDeg() const;
	double getLatRad() const;
	double getLonDeg() const;
	double getLonRad() const;
};

#endif
