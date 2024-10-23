#ifndef TSPRANDOM_H
#define TSPRANDOM_H

#include <vector>
#include <utility>

using namespace std;

class TSPRandom {
private:
    vector<vector<int>> dist;
    int attempts;

public:
    TSPRandom(const vector<vector<int>>& distanceMatrix, int attempts = 10000);
    int calculateDistance(const vector<int>& route);
    pair<int, vector<int>> findBestRandomRoute();
};

#endif
