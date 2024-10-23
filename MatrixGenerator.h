#ifndef MATRIXGENERATOR_H
#define MATRIXGENERATOR_H

#include <vector>

using namespace std;

class MatrixGenerator {
public:
    vector<vector<int>> generateMatrixAsym(int n);
    vector<vector<int>> generateMatrixSym(int n);
    void showMatrix(const vector<vector<int>>& dist);
};

#endif
