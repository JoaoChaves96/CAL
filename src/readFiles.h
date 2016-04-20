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
#include "SubRoad.h"

using namespace std;

vector<Node> readNodes();
vector<Road> readRoads();
vector<SubRoad> readSubroads();

#endif
