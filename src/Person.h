#include <iostream>
#include <string>

using namespace std;

class Person{
	string name;
	int NIF;
	int localID; //destination is accessed by an ID
public:
	Person(string name, int NIF, int localID);
	string getName() const;
	int getNIF() const;
	int getlocalID() const;
};
