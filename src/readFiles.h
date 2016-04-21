#ifndef READFILES_H_
#define READFILES_H_

#include <vector>
#include <iostream>
#include <string>
#include <fstream>
#include <stdlib.h>
#include <sstream>
#include "Node.h"
#include "Road.h"
#include "Graph.h"
#include "Subroad.h"

using namespace std;

void readNodes(Graph<Node,Road> & g);
vector<Road *> readRoads();
void readEdges();
Node * findNode(vector<Node * > nodes, int ID);

#endif
