#include "AirShuttle.h"
#include "Person.h"
#include "readFiles.h"
#include <iostream>



using namespace std;

int main(){
	AirShuttle a1;
	a1.loadGraph();
	a1.showNodeID();

	return 0;
}
