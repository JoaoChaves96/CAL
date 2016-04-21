/*
 * Subroad.h
 *
 *  Created on: 20/04/2016
 *      Author: Joao
 */

#ifndef SUBROAD_H_
#define SUBROAD_H_

#include "Road.h"
#include "Node.h"
#include "Math.h"

using namespace std;

class Node;

class Subroad{
	Node *dest;
	Road *road;
	float weight;

public:
	Subroad();
	Subroad(Road *road);
	Road getRoad() const;
	Node setDestination(Node *from, Node *to);
	Node getDest() const;
	float setWeight(Node *from, Node *to);

};



#endif /* EDGE_H_ */
