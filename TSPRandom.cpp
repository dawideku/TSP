#include "TSPRandom.h"
#include <algorithm>
#include <climits>
#include <cstdlib>
#include <ctime>
#include <random>

// Inicjalizacja klasy dla macierzy oraz liczby iteracji (10000)
TSPRandom::TSPRandom(const vector<vector<int>>& distanceMatrix, int numAttempts) {
    dist = distanceMatrix;
    attempts = numAttempts;
    srand(static_cast<unsigned>(time(0))); // Ziarno dla generatora
}

// Metoda obliczająca długość scieżki dla podanej ścieżki
int TSPRandom::calculateDistance(const vector<int>& route) {
    int totalDistance = 0;
    int n = route.size();

    // Calculate the distance for the route
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

// Metoda szukająca najlepszą ścieżkę i jej koszt
pair<int, vector<int>> TSPRandom::findBestRandomRoute() {
    int n = dist.size();
    vector<int> cities(n);

    // Inicjalizacja wektora miast (0,1,2,3,4,5..., n-1)
    for (int i = 0; i < n; i++) {
        cities[i] = i;
    }

    int bestDistance = INT_MAX;
    vector<int> bestRoute;

    // Wykonanie algorytmu n razy (w tym przypadku 10000)
    for (int attempt = 0; attempt < attempts; attempt++) {
        // Losowe mieszanie miast
        shuffle(cities.begin(), cities.end(), std::mt19937(std::random_device()())); // Keep the first city fixed

        // Obliczenie ścieżki
        int currentDistance = calculateDistance(cities);

        // Sprawdzenie czy ścieżka jest mniejsza i ewentualna podmiana
        if (currentDistance < bestDistance) {
            bestDistance = currentDistance;
            bestRoute = cities;
        }
    }

    return {bestDistance, bestRoute};
}
