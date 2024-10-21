#ifndef TSPNEARESTNEIGHBOR_H
#define TSPNEARESTNEIGHBOR_H

#include <vector>

using namespace std;

class TSPNearestNeighbor {
private:
    vector<vector<int>> dist;

public:
    TSPNearestNeighbor(const vector<vector<int>>& distanceMatrix);
    pair<int, vector<int>> findNearestNeighborRoute();
};

#endif
