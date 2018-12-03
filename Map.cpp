#include <iostream>
using namespace std;

#include "Map.h"

Map::Map(string dptCity, string dstCity, string eDTme, string eRetDTme, string cstObj) {
    t = 0;
    totalCost = 0;

    departCity = dptCity;
    destCity = dstCity;
    earliestDepartTime = eDTme;
    earliestReturnDepartTime = eRetDTme;
    custObj = cstObj;
}

void Map::insertCity(int cityID, string cityName) {
    City c(cityID, cityName);
    cities.push_back(c);
}   

void Map::insertEdge(int departID, int destID, string departCity, string destCity, string dTime, string aTime, float c) {
    Flight f(departID, destID, departCity, destCity, dTime, aTime, c);
    cities[departID].adjList.push_back(f);
}

void Map::printGraph() { 
    cout << "Cities = {" << endl;
    for (vector<City>::iterator c = cities.begin(); c != cities.end(); c++) {
        cout << "    " << *c << endl;
    }
    cout << "}" << endl;

    cout << "Flights = {" << endl;
    for (vector<City>::iterator c = cities.begin(); c != cities.end(); c++) {
        for (list<Flight>::iterator f = c->adjList.begin(); f != c->adjList.end(); f++) {
            cout << "    " << *f << endl;
        }
    }
    cout << "}" << endl;
}

bool Map::contains(string cityName) {
    for (vector<City>::iterator c = cities.begin(); c != cities.end(); c++) {
        if (cityName == c->name) return true;
    }
    return false;
}

int Map::find(string cityName) {
    int id = 0;
    for (vector<City>::iterator c = cities.begin(); c != cities.end(); c++) {
        if (cityName == c->name) return id;
        id++;
    }
    return -1;
}

float Map::convertTime(string t) {
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

bool Map::isConflict(const string &t1, const string &t2) {
    return convertTime(t1) > convertTime(t2);
}

void Map::depthFirstSearch(int cityID) {
    for (int c = 0; c < cities.size(); c++) {
        cities[c].state = 0;
        cities[c].pred = nullptr;
    }

    t = 0;

    for (int c = cityID; c < cities.size(); c++) {
        if (cities[c].state == 0) {
            dfsVisit(c);
        }
    }
}

void Map::dfsVisit(int cityID) {
    t++;
    cities[cityID].discT = t;
    cities[cityID].state = 1;

    for (list<Flight>::iterator f = cities[cityID].adjList.begin(); f != cities[cityID].adjList.end(); f++) {
        if (cities[f->destinationCityID].state == 0) {
            cities[f->destinationCityID].pred = &(*f);
            dfsVisit(f->destinationCityID);
        }
    }

    cities[cityID].state = 2;
    t++;
    cities[cityID].finT = t;
}

void Map::dijkstrasAlgorithm(int srcCityID, string earlstDepTme) {

    // init single source
    for (int c = 0; c < cities.size(); c++) {
        cities[c].dist = 999999;
        cities[c].pred = nullptr;
    }

    priority_queue<City, vector<City>, greater<City> > pq;

    cities[srcCityID].dist = 0;
    pq.push(cities[srcCityID]);

    while (!pq.empty()) {
        //extract min
        City u = pq.top(); 
        pq.pop();

        // loop through all adjacent edges
        for (list<Flight>::iterator f = cities[u.id].adjList.begin(); f != cities[u.id].adjList.end(); f++) {
            if (cities[u.id].pred != nullptr) {
                if (!isConflict(cities[u.id].pred->arrivalTime, f->departureTime)) {
                    if (!isConflict(earlstDepTme, f->departureTime)) {
                        // relax
                        if (cities[f->destinationCityID].dist > convertTime(f->arrivalTime)) {
                            cities[f->destinationCityID].dist = convertTime(f->arrivalTime);
                            cities[f->destinationCityID].pred = &(*f);
                            pq.push(cities[f->destinationCityID]);
                        }
                    }
                }
            } else {
                if (!isConflict(earlstDepTme, f->departureTime)) {
                    // relax
                    if (cities[f->destinationCityID].dist > convertTime(f->arrivalTime)) {
                        cities[f->destinationCityID].dist = convertTime(f->arrivalTime);
                        cities[f->destinationCityID].pred = &(*f);
                        pq.push(cities[f->destinationCityID]);
                    }
                }
            }
        }
    }
}   

void Map::findItinerary() {
    
    if (custObj == "any") {
        cout << "Any Itinerary: " << endl;
        cout << "===================="<< endl;
        cout << departCity << " to " << destCity << endl; 

        depthFirstSearch(find(departCity));

        vector<Flight*> itinerary1;

        int c1 = find(destCity);  
        while (cities[c1].pred != nullptr) {
            itinerary1.push_back(cities[c1].pred);
            totalCost += cities[c1].pred->cost;
            c1 = cities[c1].pred->departureCityID;
        }

        if (!itinerary1.empty()) {
            while (!itinerary1.empty()) {
                cout << *itinerary1.back() << endl;
                itinerary1.pop_back();
            }
        } else {
            cout << "No valid itinerary exists." << endl;
        }

        cout << "Total Cost: $" << totalCost << endl;
        cout << "===================="<< endl;

        totalCost = 0;
        cout << destCity << " to " << departCity << endl; 

        depthFirstSearch(find(destCity));

        vector<Flight*> itinerary2;

        int c2 = find(departCity);  
        while (cities[c2].pred != nullptr) {
            itinerary2.push_back(cities[c2].pred);
            totalCost += cities[c2].pred->cost;
            c2 = cities[c2].pred->departureCityID;
        }

        if (!itinerary2.empty()) {
            while (!itinerary2.empty()) {
                cout << *itinerary2.back() << endl;
                itinerary2.pop_back();
            }
        } else {
            cout << "No valid itinerary exists." << endl;
        }

        cout << "Total Cost: $" << totalCost << endl;
        cout << "===================="<< endl;

    } else if (custObj == "earliest") {
        cout << "Earliest Itinerary: " << endl;
        cout << "===================="<< endl;
        cout << departCity << " to " << destCity << endl; 

        dijkstrasAlgorithm(find(departCity), earliestDepartTime);

        vector<Flight*> itinerary1;

        int c1 = find(destCity);  
        while (cities[c1].pred != nullptr) {
            itinerary1.push_back(cities[c1].pred);
            totalCost += cities[c1].pred->cost;
            c1 = cities[c1].pred->departureCityID;
        }

        if (!itinerary1.empty()) {
            while (!itinerary1.empty()) {
                cout << *itinerary1.back() << endl;
                itinerary1.pop_back();
            }
        } else {
            cout << "No valid itinerary exists." << endl;
        }

        cout << "Total Cost: $" << totalCost << endl;
        cout << "===================="<< endl;

        totalCost = 0;
        cout << destCity << " to " << departCity << endl; 

        dijkstrasAlgorithm(find(destCity), earliestReturnDepartTime);

        vector<Flight*> itinerary2;

        int c2 = find(departCity);  
        while (cities[c2].pred != nullptr) {
            itinerary2.push_back(cities[c2].pred);
            totalCost += cities[c2].pred->cost;
            c2 = cities[c2].pred->departureCityID;
        }

        if (!itinerary2.empty()) {
            while (!itinerary2.empty()) {
                cout << *itinerary2.back() << endl;
                itinerary2.pop_back();
            }
        } else {
            cout << "No valid itinerary exists." << endl;
        }

        cout << "Total Cost: $" << totalCost << endl;
        cout << "===================="<< endl;
    } else if (custObj == "cheapest") { 
        cout << "Cheapest Itinerary: " << endl;
        cout << "===================="<< endl;
        cout << "Not implemented." << endl;
    }
}
