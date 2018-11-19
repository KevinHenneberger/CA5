#include <iostream>
#include <list>
using namespace std;

#include "Flight.h"

class City {
    public:
        int id;
        string name;
        list<Flight> adjList;
        // int state;
        // int distance;
        // int discoveryT;
        // int finishT;
        // City *predecessor;

        City(int i, string n);
        friend ostream& operator<<(ostream &out, City other);
};
