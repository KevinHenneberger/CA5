#include <iostream>
using namespace std;

#include "Map.h"

Map::Map() {
    t = 0;
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

void Map::breadthFirstSearch(int srcCityID) {
    for (int c = 0; c < cities.size(); c++) {
        cities[c].state = 0;
        cities[c].dist = 999999; 
        cities[c].pred = -1;
    }

    cities[srcCityID].state = 1;
    cities[srcCityID].dist = 0;
    cities[srcCityID].pred = -1;

    queue<int> q;
    q.push(srcCityID);

    while (!q.empty()) {

        int d = q.front();
        q.pop();

        for (list<Flight>::iterator f = cities[d].adjList.begin(); f != cities[d].adjList.end(); f++) {
            if (cities[f->destinationCityID].state == 0) {
                cities[f->destinationCityID].state = 1;
                cities[f->destinationCityID].dist = cities[d].dist + 1;
                cities[f->destinationCityID].pred = d;
                q.push(f->destinationCityID);
            }
        }
        cities[d].state = 2; 
    }
}

void Map::depthFirstSearch() {
    for (int c = 0; c < cities.size(); c++) {
        cities[c].state = 0;
        cities[c].pred = -1;
    }

    t = 0;

    for (int c = 0; c < cities.size(); c++) {
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
            cities[f->destinationCityID].pred = cityID;
            dfsVisit(f->destinationCityID);
        }
    }

    cities[cityID].state = 2;
    t++;
    cities[cityID].finT = t;
}

void Map::initSingleSource(int srcCityID) {
    for (int c = 0; c < cities.size(); c++) {
        cities[c].dist = 999999;
        cities[c].pred = -1;
    }
    cities[srcCityID].dist = 0;
}

void Map::relax(Flight &flight) {
    if (cities[flight.destinationCityID].dist > cities[flight.departureCityID].dist + flight.cost) {
        cities[flight.destinationCityID].dist = cities[flight.departureCityID].dist + flight.cost;
        cities[flight.destinationCityID].pred = flight.departureCityID;
    }
}

void Map::dijkstrasAlgorithm() {

    initSingleSource(0);
    vector<int> s;
    priority_queue<int> q;

    for (int i = 0; i < cities.size(); i++) {
        q.push(i);
    }

    while (!q.empty()) {
        int u = q.top(); 
        q.pop(); 

        s.push_back(u);

        for (list<Flight>::iterator f = cities[u].adjList.begin(); f != cities[u].adjList.end(); f++) {
            if (cities[f->destinationCityID].dist > cities[f->departureCityID].dist + f->cost) {
                cities[f->destinationCityID].dist = cities[f->departureCityID].dist + f->cost;
                cities[f->destinationCityID].pred = f->departureCityID;
            }
        }
    }

    cout << cities[cities[find("Denver")].pred].name << " to Denver" << endl;
}

void findItinerary(string departCity, string destCity, string dTime, string dRetTime, string custObj) {

    if (custObj == "any") {

    } else if (custObj == "earliest") {
        
    } else if (custObj == "cheapest") {
        
    }

    cout << "Itinerary: " << endl;
}
