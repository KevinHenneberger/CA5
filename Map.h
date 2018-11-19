#include <iostream>
#include <vector>
#include <list>
#include <queue>
using namespace std;

#include "City.h"

class Map {
    public:
        void insertCity(int cityID, string cityName);
        void insertEdge(int cityID1, int cityID2, string destCity, string dTime, string aTime, float c);
        // void breadthFirstSearch(int cityID);
        // void depthFirstSearch();
        // void dfsVisit(int cityID);
        void printGraph();
        bool contains(string cityName);
        int find(string cityName);

    private:
        vector<City> cities;
        int t;
};
