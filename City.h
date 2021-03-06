#include <iostream>
#include <list>
using namespace std;

#include "Flight.h"

class City {
    public:
        int id;
        string name;
        list<Flight> adjList;
        int state;
        int dist;
        Flight *pred;
        int discT;
        int finT;

        City(int i, string n);
        friend bool operator>(const City &c1, const City &c2);
        friend ostream& operator<<(ostream &out, City other);
};
