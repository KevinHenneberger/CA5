#include <iostream>
using namespace std;

#include "Flight.h"

Flight::Flight(int id, string destCity, string dTime, string aTime, float c) {
    destinationCityID = id;
    destinationCity = destCity;
    departureTime = dTime;
    arrivalTime = aTime; 
    cost = c;
}

float Flight::convertTime(string t) {
    string hh = t.substr(0, 2);
    string mm = t.substr(3, 2);
    string mer = t.substr(5);
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

ostream& operator<<(ostream &out, Flight other) {
    out << other.destinationCity << " " << other.departureTime << " " << other.arrivalTime << " $" << other.cost;
    return out;
}
