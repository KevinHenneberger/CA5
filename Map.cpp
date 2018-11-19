#include <iostream>
using namespace std;

#include "Map.h"

void Map::insertCity(int cityID, string cityName) {
    City c(cityID, cityName);
    cities.push_back(c);
}   

void Map::insertEdge(int cityID1, int cityID2, string destCity, string dTime, string aTime, float c) {
    Flight f(cityID2, destCity, dTime, aTime, c);
    cities[cityID1].adjList.push_back(f);
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
            cout << "    " << *c << " -> " << *f << endl;
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

// void Map::breadthFirstSearch(int cityID) {
    // for (vector<City>::iterator u = cities.begin(); u != cities.end(); u++) {
    //     cities[u->id].state = 0;
    //     cities[u->id].dist = 9999999; 
    //     cities[u->id].pred = nullptr;
    // }

    // cities[s.id].state = 1;
    // cities[s.id].dist = 0;
    // cities[s.id].pred = nullptr;

    // queue<City> q;
    // q.push(s);

    // while (!q.empty()) {

    //     City u = q.front();
    //     q.pop();

    //     for (list<City>::iterator v = cities[u.id].adjList.begin(); v != cities[u.id].adjList.end(); v++) {
    //         if (cities[v->id].state == 0) {
    //             cities[v->id].state = 1;
    //             cities[v->id].dist = cities[u.id].dist + 1;
    //             cities[v->id].pred = &cities[u.id];
    //             q.push(cities[v->id]);
    //         }
    //     }
    //     u.state = 2; 
    // }
// }

// void Map::depthFirstSearch() {
    // for (vector<City>::iterator u = cities.begin(); u != cities.end(); u++) {
    //     cities[u->id].state = 0;
    //     cities[u->id].pred = nullptr;
    // }

    // t = 0;

    // for (vector<City>::iterator u = cities.begin(); u != cities.end(); u++) {
    //     if (cities[u->id].state == 0) {
    //         dfsVisit(u);
    //     }
    // }
// }

// void Map::dfsVisit(int cityID) {
    // t++;
    // u.discT = t;
    // u.state = 1;

    // for (list<City>::iterator v = u.adjList.begin(); v != u.adjList.end(); v++) {
    //     if (v.state == 0) {
    //         v.pred = &u;
    //         dfsVisit(v);
    //     }
    // }
    // u.color = black;
    // t++;
    // u.finT = t;
// }
