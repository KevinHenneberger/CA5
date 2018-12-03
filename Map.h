#include <iostream>
#include <vector>
#include <queue>
#include <list>
using namespace std;

#include "City.h"

class Map {
    public:
        Map(string dptCity, string dstCity, string eDTme, string eRetDTme, string cstObj);
        void insertCity(int cityID, string cityName);
        void insertEdge(int departID, int destID, string departCity, string destCity, string dTime, string aTime, float c);
        void printGraph();
        bool contains(string cityName);
        int find(string cityName);
        float convertTime(string t);
        bool isConflict(const string &t1, const string &t2);

        void depthFirstSearch(int cityID);
        void dfsVisit(int cityID);

        void dijkstrasAlgorithm(int srcCityID, string earlstDepTme);

        void findItinerary();

    private:
        vector<City> cities;
        int t;
        float totalCost; 

        string departCity;
        string destCity;
        string earliestDepartTime;
        string earliestReturnDepartTime;
        string custObj;
};
