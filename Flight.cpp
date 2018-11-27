#include <iostream>
using namespace std;

#include "Flight.h"

Flight::Flight(int departID, int destID, string departCity, string destCity, string dTime, string aTime, float c) {
    departureCityID = departID;
    destinationCityID = destID;
    departureCity = departCity;
    destinationCity = destCity;
    departureTime = dTime;
    arrivalTime = aTime; 
    cost = c;
}

float Flight::convertTime(string t) {
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

ostream& operator<<(ostream &out, Flight other) {
    out << other.departureCity << " " <<other.destinationCity << " " << other.departureTime << " " << other.arrivalTime << " $" << other.cost;
    return out;
}
