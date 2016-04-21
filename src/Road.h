#ifndef ROAD_H_
#define  ROAD_H_

#include <string>

using namespace std;

class Road{
	int ID;
	string name;
	bool two_way;
public:
	Road(int ID, string name, bool two_way);
	int getID() const;
};


#endif
