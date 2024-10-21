#include "TSPRandom.h"
#include <algorithm> // For shuffle
#include <climits>   // For INT_MAX
#include <cstdlib>   // For rand and srand
#include <ctime>     // For time
#include <random>

// Constructor to initialize the distance matrix and number of attempts
TSPRandom::TSPRandom(const vector<vector<int>>& distanceMatrix, int numAttempts) {
    dist = distanceMatrix;
    attempts = numAttempts;
    srand(static_cast<unsigned>(time(0))); // Seed for random number generation
}

// Method to calculate the total distance for a given route
int TSPRandom::calculateDistance(const vector<int>& route) {
    int totalDistance = 0;
    int n = route.size();

    // Calculate the distance for the route
    for (int i = 0; i < n - 1; i++) {
        int from = route[i];
        int to = route[i + 1];
        if (dist[from][to] == -1) return INT_MAX; // Handle invalid paths
        totalDistance += dist[from][to];
    }

    // Add the distance to return to the starting city
    int start = route[0];
    int end = route[n - 1];
    if (dist[end][start] == -1) return INT_MAX; // Handle invalid paths
    totalDistance += dist[end][start];

    return totalDistance;
}

// Method to find the best random route and minimum distance
pair<int, vector<int>> TSPRandom::findBestRandomRoute() {
    int n = dist.size();
    vector<int> cities(n);

    // Initialize the cities vector (e.g., {0, 1, 2, ..., n-1})
    for (int i = 0; i < n; i++) {
        cities[i] = i;
    }

    int bestDistance = INT_MAX;
    vector<int> bestRoute;

    // Try 'attempts' number of random routes
    for (int attempt = 0; attempt < attempts; attempt++) {
        // Shuffle the cities to create a random route
        shuffle(cities.begin() + 1, cities.end(), std::mt19937(std::random_device()())); // Keep the first city fixed

        // Calculate the distance for the current random route
        int currentDistance = calculateDistance(cities);

        // Check if the current route is the best one so far
        if (currentDistance < bestDistance) {
            bestDistance = currentDistance;
            bestRoute = cities;
        }
    }

    return {bestDistance, bestRoute};
}
