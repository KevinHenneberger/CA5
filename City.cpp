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

float City::convertTime(string t) const {
    int colon = t.find(":");
    string hh = t.substr(0, colon);
    string mm = t.substr(colon+1, 2);
    string mer = t.substr(colon+3);
    float hours;
    float minutes;

    stringstream hss(hh);
    hss >> hours;
    stringstream mss(mm);
    mss >> minutes;

    if (mer == "pm" && hours != 12) hours += 12;
    else if (mer == "am" && hours == 12) hours = 0;

    return hours + (minutes / 100);
}

ostream& operator<<(ostream &out, City other) {
    // out << other.name << "(" << other.id << ")";
    out << other.name << " " << other.dist;
    // out << other.name << " " << other.discT << "/" << other.finT;
    return out;
}

bool operator>(const City &c1, const City &c2) {
    return c1.dist > c2.dist;
}
