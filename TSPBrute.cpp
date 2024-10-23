#include "TSPBrute.h"
#include <climits>
#include <algorithm>

using namespace std;

//Inicjalizacja macierzy na której będzie wykonywany algorytm
TSPBrute::TSPBrute(const vector<vector<int>>& distanceMatrix) {
    dist = distanceMatrix;
}

// Metoda do obliczania dystansu na podstawie sciezki
int TSPBrute::calculateDistance(const vector<int>& route) {
    int totalDistance = 0;
    int n = route.size();

    // Obliczanie dystansu
    for (int i = 0; i < n - 1; i++) {
        int from = route[i];
        int to = route[i + 1];
        if (dist[from][to] == -1) return INT_MAX; // Obsługa wyjątku
        totalDistance += dist[from][to];
    }

    // Zapewnienie powrotu do miasta początkowego
    int start = route[0];
    int end = route[n - 1];
    if (dist[end][start] == -1) return INT_MAX; // Obsługa wyjątku
    totalDistance += dist[end][start];

    return totalDistance;
}

// Metoda znajdujaca najlepsza droge i najmniejszy dystans
pair<int, vector<int>> TSPBrute::findBestRoute() {
    int n = dist.size();
    vector<int> cities;

    for (int i = 0; i < n; i++) {
        cities.push_back(i);
    }

    int minDistance = INT_MAX;
    vector<int> bestRoute;

    // Sprawdzanie kazdej możliwości ułożenia miast
    do {
        int currentDistance = calculateDistance(cities); // Liczenie długości ścieżki z wcześniej deklarowej metody
        if (currentDistance < minDistance) {
            minDistance = currentDistance;
            bestRoute = cities; // Zapisywanie najlepszej ścieżki
        }
    } while (next_permutation(cities.begin(), cities.end())); // Za każdym razem startujemy od miasta 0

    return {minDistance, bestRoute};
}
