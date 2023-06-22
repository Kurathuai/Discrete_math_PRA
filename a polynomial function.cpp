#include <iostream>
#include <cmath>

using namespace std;


double evaluatePolynomial(const double coefficients[], int degree, double x) {
    double result = 0.0;


    for (int i = degree; i >= 0; --i) {
        result = (result * x) + coefficients[i];
    }

    return result;
}

int main() {
    int degree;

    cout << "Enter the degree of the polynomial: ";
    cin >> degree;

    double coefficients[degree + 1];

    cout << "Enter the coefficients of the polynomial (starting from the highest degree):\n";
    for (int i = degree; i >= 0; --i) {
        cout << "Coefficient of x^" << i << ": ";
        cin >> coefficients[i];
    }

    double x;

    cout << "Enter the value of x: ";
    cin >> x;

    double result = evaluatePolynomial(coefficients, degree, x);

    cout << "f(" << x << ") = " << result << endl;

    return 0;
}
