#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void generatePermutationsWithRepetition(const vector<int>& digits, int length, vector<int>& currentPermutation) {
    if (length == 0) {
        
        for (int digit : currentPermutation) {
            cout << digit << " ";
        }
        cout << endl;
        return;
    }

    for (int i = 0; i < digits.size(); ++i) {
        currentPermutation.push_back(digits[i]);
        generatePermutationsWithRepetition(digits, length - 1, currentPermutation);
        currentPermutation.pop_back();
    }
}


void generatePermutationsWithoutRepetition(vector<int>& digits, int currentIndex) {
    if (currentIndex == digits.size() - 1) {
        
        for (int digit : digits) {
            cout << digit << " ";
        }
        cout << endl;
        return;
    }

    for (int i = currentIndex; i < digits.size(); ++i) {
        swap(digits[currentIndex], digits[i]);
        generatePermutationsWithoutRepetition(digits, currentIndex + 1);
        swap(digits[currentIndex], digits[i]);
    }
}

int main() {
    int choice;
    cout << "Enter 1 to generate permutations with repetition or 2 to generate permutations without repetition: ";
    cin >> choice;

    int n;
    cout << "Enter the number of digits: ";
    cin >> n;

    vector<int> digits(n);
    cout << "Enter the digits: ";
    for (int i = 0; i < n; ++i) {
        cin >> digits[i];
    }

    cout << "Permutations:\n";
    if (choice == 1) {
        vector<int> currentPermutation;
        generatePermutationsWithRepetition(digits, n, currentPermutation);
    } else if (choice == 2) {
        generatePermutationsWithoutRepetition(digits, 0);
    } else {
        cout << "Invalid choice.";
    }

    return 0;
}
