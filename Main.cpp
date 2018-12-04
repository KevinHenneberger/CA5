#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
using namespace std;

#include "Map.h"

int main() {
    string custDepartureCity;
    string custDestinationCity;
    string custDepartureTime;
    string custReturnDepartureTime;
    string custObjective;

    cout << "Departure City: ";
    cin >> custDepartureCity;  
    cout << "Destination City: ";
    cin >> custDestinationCity;  
    cout << "Departure Time: ";
    cin >> custDepartureTime; 
    cout << "Return Departure Time: ";
    cin >> custReturnDepartureTime;  
    cout << "Customer Objective [\"any\", \"earliest\", \"cheapest\"]: ";
    cin >> custObjective;  

    Map map(custDepartureCity, custDestinationCity, custDepartureTime, custReturnDepartureTime, custObjective);

    ifstream ddfsfile("DailyDirectFlightSchedule.txt");

    int i = 0;

    if (ddfsfile.good()) {
        string departureCity;
        string destinationCity;
        string departureTime;
        string arrivalTime;
        string c;
        float cost;

        while (getline(ddfsfile, departureCity, ' ')) {
            getline(ddfsfile, destinationCity, ' ');
            getline(ddfsfile, departureTime, ' ');
            getline(ddfsfile, arrivalTime, ' ');
            getline(ddfsfile, c);
            c = c.substr(1);
            stringstream myStream1(c);
            myStream1 >> cost;

            if (!map.contains(departureCity)) {
                map.insertCity(i, departureCity);
                i++;
            }
                
            if (!map.contains(destinationCity)) {
                map.insertCity(i, destinationCity);
                i++;
            }

            map.insertEdge(map.find(departureCity), map.find(destinationCity), departureCity, destinationCity, departureTime, arrivalTime, cost);
        }
        ddfsfile.close();
    }

    map.findItinerary();
}
