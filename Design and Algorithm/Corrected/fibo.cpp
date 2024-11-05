#include <iostream>
using namespace std;

void fibonacci(int n) {
    if (n <= 0) {
        cout << "Please enter a positive integer." << endl;
        return;
    }

    int series[n];
    series[0] = 0;
    if (n > 1) {
        series[1] = 1;
    }

    // Generate the Fibonacci series and store it in the array
    for (int i = 2; i < n; i++) {
        series[i] = series[i - 1] + series[i - 2];
    }

    // Output the series in normal order
    cout << "Fibonacci Series: ";
    for (int i = 0; i < n; i++) {
        cout << series[i] << " ";
    }
    cout << endl;

    // Output the series in reverse order
    cout << "Fibonacci Series in reverse order: ";
    for (int i = n - 1; i >= 0; i--) {
        cout << series[i] << " ";
    }
    cout << endl;
}

int main() {
    int n;
    cout << "Enter the number of terms: ";
    cin >> n;
    fibonacci(n);
    return 0;
}
