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

ostream& operator<<(ostream &out, Flight other) {
    out << other.departureCity << " " <<other.destinationCity << " " << other.departureTime << " " << other.arrivalTime << " $" << other.cost;
    return out;
}
