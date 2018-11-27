#include <iostream>
#include <vector>
#include <queue>
#include <list>
using namespace std;

#include "City.h"

class Map {
    public:
        Map();
        void insertCity(int cityID, string cityName);
        void insertEdge(int departID, int destID, string departCity, string destCity, string dTime, string aTime, float c);
        void printGraph();
        bool contains(string cityName);
        int find(string cityName);
        
        void breadthFirstSearch(int srcCityID);
        void depthFirstSearch();
        void dfsVisit(int cityID);
        void initSingleSource(int srcCityID);
        void relax(Flight &flight);
        void dijkstrasAlgorithm();

        void findItinerary(string departCity, string destCity, string dTime, string dRetTime, string custObj);

    private:
        vector<City> cities;
        int t;
};
