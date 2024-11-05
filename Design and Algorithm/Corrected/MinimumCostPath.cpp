#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

int minCostPath(int cost[][10], int m, int n, char path[][20]) {
    int dp[m][n];
    dp[0][0] = cost[0][0];

    // Initialize the first row and first column
    for (int i = 1; i < m; i++) dp[i][0] = dp[i - 1][0] + cost[i][0];
    for (int j = 1; j < n; j++) dp[0][j] = dp[0][j - 1] + cost[0][j];

    // Fill the dp table
    for (int i = 1; i < m; i++) {
        for (int j = 1; j < n; j++) {
            dp[i][j] = min(dp[i - 1][j], dp[i][j - 1]) + cost[i][j];
        }
    }

    // Backtracking to find the path
    int i = m - 1, j = n - 1;
    int index = 0;

    while (i > 0 || j > 0) {
        // Store the current position in the path
        sprintf(path[index++], "(%d,%d)", i, j);
        if (i == 0) {
            j--; // Only can move left
        } else if (j == 0) {
            i--; // Only can move up
        } else if (dp[i - 1][j] < dp[i][j - 1]) {
            i--; // Move up
        } else {
            j--; // Move left
        }
    }
    sprintf(path[index++], "(0,0)"); // Add the starting position

    // Output the minimum cost path
    cout << "Minimum cost path: " << dp[m - 1][n - 1] << endl;
    cout << "Path taken: ";
    for (int k = index - 1; k >= 0; k--) { // Print path in reverse order
        cout << path[k] << " ";
    }
    cout << endl;

    return dp[m - 1][n - 1];
}

int main() {
    int m, n;

    cout << "Enter the number of rows: ";
    cin >> m;
    cout << "Enter the number of columns: ";
    cin >> n;

    // Use a maximum size for the cost array, 10x10 for demonstration
    int cost[10][10]; // Assuming a maximum grid size of 10x10
    cout << "Enter the cost matrix (" << m << "x" << n << "):" << endl;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cin >> cost[i][j];
        }
    }

    // Maximum path length can be m+n-1
    char path[m + n][20]; // Allocate path for positions (up to 20 characters each)
    minCostPath(cost, m, n, path);

    return 0;
}
