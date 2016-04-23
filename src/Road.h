#ifndef ROAD_H_
#define  ROAD_H_

#include <string>

using namespace std;

class Road{
	unsigned long ID;
	string name;
	bool two_way;
	bool acessible;
public:
	Road(unsigned long ID, string name, bool two_way);
	unsigned long getID() const;
	string getName() const;
	void block();
	bool getState() const;
};


#endif
