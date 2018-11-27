#include <iostream>
#include <sstream>
using namespace std;

class Flight {
    public: 
        int departureCityID;
        int destinationCityID;
        string departureCity;
        string destinationCity;
        string departureTime;
        string arrivalTime; 
        float cost;

        Flight(int departID, int destID, string departCity, string destCity, string dTime, string aTime, float c);
        float convertTime(string t);
        friend ostream& operator<<(ostream &out, Flight other);
};
