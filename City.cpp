#include <iostream>
using namespace std;

#include "City.h"

City::City(int i, string n) {
    id = i;
    name = n;

    state = 0;
    dist = 999999;
    pred = -1;

    discT = 999999;
    finT = 999999;
}

ostream& operator<<(ostream &out, City other) {
    // out << other.name;
    out << other.name << " " << other.dist;
    // out << other.name << " " << other.discT << "/" << other.finT;
    return out;
}
