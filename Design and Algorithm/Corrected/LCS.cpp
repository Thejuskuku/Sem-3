#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

int lcs(char* X, char* Y, int m, int n) {
    int dp[m + 1][n + 1];

    // Fill the dp array
    for (int i = 0; i <= m; i++) {
        for (int j = 0; j <= n; j++) {
            if (i == 0 || j == 0)
                dp[i][j] = 0;
            else if (X[i - 1] == Y[j - 1])
                dp[i][j] = dp[i - 1][j - 1] + 1;
            else
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
    }

    // Length of the LCS
    int lcs_length = dp[m][n];
    cout << "Length of LCS: " << lcs_length << endl;

    // Backtracking to find the LCS sequence
    char lcs_sequence[lcs_length + 1];  // Array to store the LCS
    lcs_sequence[lcs_length] = '\0';    // Null-terminate the character array

    int i = m, j = n;
    int index = lcs_length - 1;  // Index for placing characters in the lcs_sequence

    while (i > 0 && j > 0) {
        if (X[i - 1] == Y[j - 1]) {  // If characters match, they are part of the LCS
            lcs_sequence[index] = X[i - 1];
            index--;
            i--;
            j--;
        } else if (dp[i - 1][j] > dp[i][j - 1]) {
            i--;  // Move upwards in the table
        } else {
            j--;  // Move left in the table
        }
    }

    // Output the LCS sequence
    cout << "LCS sequence: " << lcs_sequence << endl;

    return dp[m][n];
}

int main() {
    string X, Y;
    cout << "Enter the first sequence: ";
    cin >> X;
    cout << "Enter the second sequence: ";
    cin >> Y;

    int m = X.length();
    int n = Y.length();

    // Convert strings to character arrays
    char X_arr[m + 1];
    char Y_arr[n + 1];
    strcpy(X_arr, X.c_str());
    strcpy(Y_arr, Y.c_str());

    lcs(X_arr, Y_arr, m, n);
    return 0;
}
