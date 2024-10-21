#include "MatrixGenerator.h"
#include <cstdlib> // For rand() and srand()
#include <ctime>   // For time()
#include <iostream> // For std::cout

using namespace std;

// Method to generate a random asymmetric distance matrix of size n x n
vector<vector<int>> MatrixGenerator::generateMatrixAsym(int n) {
    vector<vector<int>> dist(n, vector<int>(n, -1)); // Initialize matrix with -1

    // Seed random number generator
    srand(static_cast<unsigned>(time(0)));

    // Fill the matrix with random distances, ensuring asymmetry (dist[i][j] != dist[j][i])
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i != j) {
                int randomDistance = rand() % 100 + 1; // Random distance between 1 and 100
                dist[i][j] = randomDistance;

                // To make it asymmetric, ensure dist[j][i] is different
                int asymmetricDistance = rand() % 100 + 1;
                dist[j][i] = (dist[j][i] == -1) ? asymmetricDistance : dist[j][i];
            }
        }
    }

    return dist;
}

// Method to generate a random symmetric distance matrix of size n x n
vector<vector<int>> MatrixGenerator::generateMatrixSym(int n) {
    vector<vector<int>> dist(n, vector<int>(n, -1)); // Initialize matrix with -1

    // Seed random number generator
    srand(static_cast<unsigned>(time(0)));

    // Fill the matrix with random symmetric distances (dist[i][j] == dist[j][i])
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) { // Only fill upper triangle and mirror to lower triangle
            int randomDistance = rand() % 100 + 1; // Random distance between 1 and 100
            dist[i][j] = randomDistance;
            dist[j][i] = randomDistance; // Symmetric distance
        }
    }

    return dist;
}

// Method to display the distance matrix
void MatrixGenerator::showMatrix(const vector<vector<int>>& dist) {
    cout << "Generated Distance Matrix:" << endl;
    for (const auto& row : dist) {
        for (int val : row) {
            cout << val << "\t";
        }
        cout << endl;
    }
}
