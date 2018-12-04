#include <iostream>
using namespace std;

#include "City.h"

City::City(int i, string n) {
    id = i;
    name = n;
    state = 0;
    dist = 999999;
    pred = nullptr;
    discT = 999999;
    finT = 999999;
}

bool operator>(const City &c1, const City &c2) {
    return c1.dist > c2.dist;
}

ostream& operator<<(ostream &out, City other) {
    out << other.name << " " << other.dist;
    return out;
}
