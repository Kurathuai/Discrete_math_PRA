#include <iostream>
#include <vector>

using namespace std;

class RELATION {
private:
    vector<vector<int>> matrix;
    int size;

public:
    
    RELATION(const vector<vector<int>>& mat) {
        matrix = mat;
        size = matrix.size();
    }


    bool isReflexive() {
        for (int i = 0; i < size; ++i) {
            if (matrix[i][i] != 1) {
                return false;
            }
        }
        return true;
    }

    
    bool isSymmetric() {
        for (int i = 0; i < size; ++i) {
            for (int j = 0; j < size; ++j) {
                if (matrix[i][j] != matrix[j][i]) {
                    return false;
                }
            }
        }
        return true;
    }

    
    bool isAntiSymmetric() {
        for (int i = 0; i < size; ++i) {
            for (int j = 0; j < size; ++j) {
                if (matrix[i][j] == 1 && matrix[j][i] == 1 && i != j) {
                    return false;
                }
            }
        }
        return true;
    }

    
    bool isTransitive() {
        for (int i = 0; i < size; ++i) {
            for (int j = 0; j < size; ++j) {
                if (matrix[i][j] == 1) {
                    for (int k = 0; k < size; ++k) {
                        if (matrix[j][k] == 1 && matrix[i][k] != 1) {
                            return false;
                        }
                    }
                }
            }
        }
        return true;
    }

    
    void checkRelationType() {
        bool isEquivalence = isReflexive() && isSymmetric() && isTransitive();
        bool isPartialOrder = isReflexive() && isAntiSymmetric() && isTransitive();

        if (isEquivalence) {
            cout << "The relation is an Equivalence relation." << endl;
        } else if (isPartialOrder) {
            cout << "The relation is a Partial Order relation." << endl;
        } else {
            cout << "The relation is neither an Equivalence relation nor a Partial Order relation." << endl;
        }
    }
};

int main() {
    
    vector<vector<int>> relationMatrix = {{1, 0, 0}, {0, 1, 0}, {1, 1, 1}};

    RELATION relation(relationMatrix);
    relation.checkRelationType();

    return 0;
}
