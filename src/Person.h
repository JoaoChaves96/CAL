#ifndef PERSON_H_
#define PERSON_H_

#include <iostream>
#include <string>

using namespace std;

class Person{
	string name;
	int NIF;
public:
	Person();
	Person(string name, int NIF);
	string getName() const;
	int getNIF() const;
};

#endif
