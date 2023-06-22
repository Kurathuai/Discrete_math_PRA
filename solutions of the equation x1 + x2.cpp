#include <iostream>
#include <vector>

using namespace std;

void findSolutions(int targetSum, int remainingNumbers, int currentSum, vector<int>& currentSolution) {
    if (remainingNumbers == 0) {
        
        if (currentSum == targetSum) {
            // Print the solution
            for (int i = 0; i < currentSolution.size(); ++i) {
                cout << currentSolution[i] << " ";
            }
            cout << endl;
        }
        return;
    }

    
    for (int i = 0; i <= targetSum - currentSum; ++i) {
        currentSolution.push_back(i);
        findSolutions(targetSum, remainingNumbers - 1, currentSum + i, currentSolution);
        currentSolution.pop_back();
    }
}

int main() {
    int n, targetSum;

    cout << "Enter the value of n: ";
    cin >> n;

    cout << "Enter the target sum (C): ";
    cin >> targetSum;

    vector<int> currentSolution;
    findSolutions(targetSum, n, 0, currentSolution);

    return 0;
}
