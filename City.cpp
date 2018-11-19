#include <iostream>
using namespace std;

#include "City.h"

City::City(int i, string n) {
    id = i;
    name = n;
    // state = 0;
    // distance = 999999;
    // discoveryT = 999999;
    // finishT = 999999;
    // predecessor = nullptr;
}

ostream& operator<<(ostream &out, City other) {
    out << other.name;
    return out;
}
