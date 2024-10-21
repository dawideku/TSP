#include "TSPNearestNeighbor.h"
#include <climits> // For INT_MAX
#include <vector>

using namespace std;

// Inicjalizacja macierzy
TSPNearestNeighbor::TSPNearestNeighbor(const vector<vector<int>>& distanceMatrix) {
    dist = distanceMatrix;
}

// Metoda do znajdowania najlepszej ścieżki
pair<int, vector<int>> TSPNearestNeighbor::findNearestNeighborRoute() {
    int n = dist.size();
    int bestDistance = INT_MAX;
    vector<int> bestRoute;

    // Sprawdzamy dla kazdego miasta startowego
    for (int startCity = 0; startCity < n; startCity++) {
        int currentCity = startCity;
        vector<int> visited(n, 0); // Ustawiamy wszystkie miasta jako nieodwiedzone
        vector<int> route;         // Aktualna scieżka
        int totalDistance = 0;     // Rozmiar aktualnej ścieżki
        route.push_back(currentCity);
        visited[currentCity] = 1;  // Ustawiamy aktualne miasto jako odwiedzone

        // W każdym kroku szukane jest nabliższe miasto
        for (int step = 1; step < n; step++) {
            int nearestCity = -1;
            int minDistance = INT_MAX;

            // Szukamy najbliższego nieodwiedzonego miasta
            for (int nextCity = 0; nextCity < n; nextCity++) {
                if (!visited[nextCity] && dist[currentCity][nextCity] != -1 && dist[currentCity][nextCity] < minDistance) {
                    nearestCity = nextCity;
                    minDistance = dist[currentCity][nextCity];
                }
            }

            // Jeżeli nabliższe dostępne miasto jest dostępne, przechodzimy do niego
            if (nearestCity != -1) {
                route.push_back(nearestCity);
                totalDistance += minDistance;
                visited[nearestCity] = 1;
                currentCity = nearestCity; // Zmieniamy aktualne miasto
            } else {
                totalDistance = INT_MAX; // Pomijamy w przypadku złej ścieżki
                break;
            }
        }

        // Wracamy do miasta startowego, żeby dokończyć cykl
        if (totalDistance != INT_MAX && dist[currentCity][startCity] != -1) {
            totalDistance += dist[currentCity][startCity]; // Dodawanie dystansu z powrotem do miasta startowego
            route.push_back(startCity);                   // Dokończenie cyklu przez wrócenie na początek
        } else {
            totalDistance = INT_MAX; // Invalid route
        }

        // Aktualizacja najlepszej ścieżki oraz dystansu
        if (totalDistance < bestDistance) {
            bestDistance = totalDistance;
            bestRoute = route;
        }
    }

    return {bestDistance, bestRoute};
}
