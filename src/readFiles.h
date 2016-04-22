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

using namespace std;

void readNodes(Graph<Node,Road> & g);
Road readRoads(unsigned long roadID);
void readEdges(Graph<Node, Road> & g);
Node findNode(Graph<Node, Road> & g, unsigned long ID);
float calcWeight(Node from, Node to);

#endif
