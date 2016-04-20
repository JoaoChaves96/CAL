#include <iostream>
#include <string>

using namespace std;

class Person{
	string name;
	int NIF;
public:
	Person(string name, int NIF);
	string getName() const;
	int getNIF() const;
};
