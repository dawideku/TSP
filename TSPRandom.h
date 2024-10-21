#ifndef TSPRANDOM_H
#define TSPRANDOM_H

#include <vector>
#include <utility>

using namespace std;

class TSPRandom {
private:
    vector<vector<int>> dist;  // Distance matrix
    int attempts;              // Number of random attempts (default 10000)

public:
    // Constructor to initialize the distance matrix and number of attempts
    TSPRandom(const vector<vector<int>>& distanceMatrix, int attempts = 10000);

    // Method to calculate the total distance for a given route
    int calculateDistance(const vector<int>& route);

    // Method to find the best random route and minimum distance
    pair<int, vector<int>> findBestRandomRoute();
};

#endif // TSPRANDOM_H
