#include <iostream>
#include <vector>
#include <fstream>   // For file I/O
#include <chrono>
#include <climits>   // For INT_MAX
#include "TSPBrute.h"           // Include the TSPBrute class
#include "TSPNearestNeighbor.h"  // Include the TSPNearestNeighbor class
#include "TSPRandom.h"           // Include the TSPRandom class
#include "MatrixGenerator.h"     // Include the MatrixGenerator class

using namespace std;

// Function to read matrix from a file and store it in dist
vector<vector<int>> readMatrixFromFile(const string& filename) {
    ifstream infile(filename);
    if (!infile.is_open()) {
        cerr << "Error: Unable to open file!" << endl;
        return {};
    }

    int n;
    infile >> n;  // Read the first line (number of cities)
    vector<vector<int>> matrix(n, vector<int>(n));

    // Read the matrix values from the file
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            infile >> matrix[i][j];
        }
    }

    infile.close();
    return matrix;
}

// Function to display the menu
void displayMenu() {
    cout << "Menu Options:" << endl;
    cout << "1. Generate New Asymmetric Distance Matrix" << endl;
    cout << "2. Generate New Symmetric Distance Matrix" << endl;
    cout << "3. Display Current Distance Matrix" << endl;
    cout << "4. Run TSP Algorithm (Brute Force)" << endl;
    cout << "5. Run TSP Algorithm (Nearest Neighbor)" << endl;
    cout << "6. Run TSP Algorithm (Random Search)" << endl;
    cout << "7. Read Matrix from File" << endl; // Add option to read matrix from file
    cout << "8. Exit" << endl;  // Updated exit number
}

int main() {
    MatrixGenerator generator;
    vector<vector<int>> dist;
    TSPBrute bruteCalculator(dist);           // Initializing with an empty matrix
    TSPNearestNeighbor nnCalculator(dist);    // Initializing with an empty matrix
    TSPRandom randomCalculator(dist);         // Initializing with an empty matrix
    int choice;

    while (true) {
        displayMenu();
        cout << "Select an option (1-8): ";  // Updated the selection range
        cin >> choice;

        switch (choice) {
            case 1: { // Generate Asymmetric Matrix
                int n;
                cout << "Enter the number of cities: ";
                cin >> n;
                dist = generator.generateMatrixAsym(n);    // Generate the random asymmetric distance matrix
                bruteCalculator = TSPBrute(dist);          // Initialize TSPBrute with the new matrix
                nnCalculator = TSPNearestNeighbor(dist);   // Initialize TSPNearestNeighbor with the new matrix
                randomCalculator = TSPRandom(dist);        // Initialize TSPRandom with the new matrix
                cout << "New asymmetric distance matrix generated." << endl;
                break;
            }
            case 2: { // Generate Symmetric Matrix
                int n;
                cout << "Enter the number of cities: ";
                cin >> n;
                dist = generator.generateMatrixSym(n);     // Generate the random symmetric distance matrix
                bruteCalculator = TSPBrute(dist);          // Initialize TSPBrute with the new matrix
                nnCalculator = TSPNearestNeighbor(dist);   // Initialize TSPNearestNeighbor with the new matrix
                randomCalculator = TSPRandom(dist);        // Initialize TSPRandom with the new matrix
                cout << "New symmetric distance matrix generated." << endl;
                break;
            }
            case 3: { // Display Matrix
                if (dist.empty()) {
                    cout << "No matrix generated yet!" << endl;
                } else {
                    generator.showMatrix(dist);            // Display the generated matrix
                }
                break;
            }
            case 4: { // Run Brute Force TSP Algorithm
                if (dist.empty()) {
                    cout << "No matrix generated yet! Please generate one first." << endl;
                } else {
                    auto start = chrono::steady_clock::now();
                    auto [minDistance, bestRoute] = bruteCalculator.findBestRoute();
                    auto end = chrono::steady_clock::now();
                    auto czas_wykonania = chrono::duration_cast<chrono::milliseconds>(end - start).count();
                    cout << "Czas wykonania funkcji: " << czas_wykonania << " ms" << endl;
                    cout << "Minimum Distance (Brute Force): " << minDistance << endl;
                    cout << "Best Route: ";
                    for (int city : bestRoute) {
                        cout << city << " ";
                    }
                    cout << bestRoute[0] << endl; // Return to the starting city
                }
                break;
            }
            case 5: { // Run Nearest Neighbor TSP Algorithm
                if (dist.empty()) {
                    cout << "No matrix generated yet! Please generate one first." << endl;
                } else {
                    auto [minDistance, bestRoute] = nnCalculator.findNearestNeighborRoute();
                    cout << "Minimum Distance (Nearest Neighbor): " << minDistance << endl;
                    cout << "Best Route: ";
                    for (int city : bestRoute) {
                        cout << city << " ";
                    }
                    cout << endl;
                }
                break;
            }
            case 6: { // Run Random TSP Algorithm
                if (dist.empty()) {
                    cout << "No matrix generated yet! Please generate one first." << endl;
                } else {
                    auto [minDistance, bestRoute] = randomCalculator.findBestRandomRoute();  // Random TSP call
                    cout << "Minimum Distance (Random Search): " << minDistance << endl;
                    cout << "Best Route: ";
                    for (int city : bestRoute) {
                        cout << city << " ";
                    }
                    cout << bestRoute[0] << endl; // Return to the starting city
                }
                break;
            }
            case 7: { // Read Matrix from File
                string filename;
                cout << "Enter the filename to read the matrix from: ";
                cin >> filename;
                dist = readMatrixFromFile(filename);
                if (!dist.empty()) {
                    bruteCalculator = TSPBrute(dist);          // Initialize TSPBrute with the new matrix
                    nnCalculator = TSPNearestNeighbor(dist);   // Initialize TSPNearestNeighbor with the new matrix
                    randomCalculator = TSPRandom(dist);        // Initialize TSPRandom with the new matrix
                    cout << "Matrix loaded from file successfully!" << endl;
                } else {
                    cout << "Failed to load matrix from file." << endl;
                }
                break;
            }
            case 8: { // Exit
                cout << "Exiting program." << endl;
                return 0; // Exit the program
            }
            default:
                cout << "Invalid option. Please select between 1-8." << endl;
        }
        cout << endl; // For better readability
    }

    return 0;
}
