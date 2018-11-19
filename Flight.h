#include <iostream>
#include <sstream>
using namespace std;

class Flight {
    public: 
        int destinationCityID;
        string destinationCity;
        string departureTime;
        string arrivalTime; 
        float cost;

        Flight(int id, string destCity, string dTime, string aTime, float c);
        float convertTime(string t);
        friend ostream& operator<<(ostream &out, Flight other);
};
