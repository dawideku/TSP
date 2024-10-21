#ifndef TSPBRUTE_H
#define TSPBRUTE_H

#include <vector>

using namespace std;

class TSPBrute {
private:
    vector<vector<int>> dist;

public:
    TSPBrute(const vector<vector<int>>& distanceMatrix);
    int calculateDistance(const vector<int>& route);
    pair<int, vector<int>> findBestRoute();
};

#endif
