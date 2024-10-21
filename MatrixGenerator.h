#ifndef MATRIXGENERATOR_H
#define MATRIXGENERATOR_H

#include <vector>

using namespace std;

class MatrixGenerator {
public:
    // Method to generate a random asymmetric distance matrix of size n x n
    vector<vector<int>> generateMatrixAsym(int n);

    // Method to generate a random symmetric distance matrix of size n x n
    vector<vector<int>> generateMatrixSym(int n);

    // Method to display the distance matrix
    void showMatrix(const vector<vector<int>>& dist);
};

#endif // MATRIXGENERATOR_H
