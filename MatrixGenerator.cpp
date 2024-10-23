#include "MatrixGenerator.h"
#include <cstdlib>
#include <ctime>
#include <iostream>

using namespace std;

// Metoda generująca asymetryczną macierz
vector<vector<int>> MatrixGenerator::generateMatrixAsym(int n) {
    vector<vector<int>> dist(n, vector<int>(n, -1)); // Wypełnienie macierzy wartościami -1

    // Ziarno do generatora
    srand(static_cast<unsigned>(time(0)));

    // Wypełnienie macierzy losowymi wartosciami
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i != j) {
                int randomDistance = rand() % 100 + 1;
                dist[i][j] = randomDistance;

                // Zapewnienie własności asymetryczności
                int asymmetricDistance = rand() % 100 + 1;
                dist[j][i] = (dist[j][i] == -1) ? asymmetricDistance : dist[j][i];
            }
        }
    }

    return dist;
}

// Metoda tworząca symetryczną macierz
vector<vector<int>> MatrixGenerator::generateMatrixSym(int n) {
    vector<vector<int>> dist(n, vector<int>(n, -1)); // Wypełnienie macierzy wartościami -1

    // Ziarno dla generatora
    srand(static_cast<unsigned>(time(0)));

    // Wypełnienie macierzy losowymi wartościami
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) { // Wypełnienie tylko górnego "trójkąta"
            int randomDistance = rand() % 100 + 1;
            dist[i][j] = randomDistance;
            dist[j][i] = randomDistance; // Zapewnienie symetryczności
        }
    }

    return dist;
}

// Metoda wyświetlająca macierz
void MatrixGenerator::showMatrix(const vector<vector<int>>& dist) {
    cout << "Generated Distance Matrix:" << endl;
    for (const auto& row : dist) {
        for (int val : row) {
            cout << val << "\t";
        }
        cout << endl;
    }
}
