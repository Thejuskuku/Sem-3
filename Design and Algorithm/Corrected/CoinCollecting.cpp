#include <iostream>
#include <algorithm>
using namespace std;

int maxCoins(int** grid, int m, int n, int path[][2]) {
    int dp[m][n];
    dp[0][0] = grid[0][0];

    // Initialize the first row and first column
    for (int i = 1; i < m; i++) dp[i][0] = dp[i - 1][0] + grid[i][0];
    for (int j = 1; j < n; j++) dp[0][j] = dp[0][j - 1] + grid[0][j];

    // Fill the dp array
    for (int i = 1; i < m; i++) {
        for (int j = 1; j < n; j++) {
            dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]) + grid[i][j];
        }
    }

    // Backtracking to find the path
    int i = m - 1, j = n - 1;
    int index = 0; // Index to store path
    while (i > 0 || j > 0) {
        path[index][0] = i;
        path[index][1] = j;
        index++;

        // Move to the cell that led to the current cell
        if (i == 0) {
            j--;
        } else if (j == 0) {
            i--;
        } else if (dp[i - 1][j] > dp[i][j - 1]) {
            i--;
        } else {
            j--;
        }
    }
    // Add the starting cell
    path[index][0] = 0;
    path[index][1] = 0;
    index++;

    // Print the path in the correct order
    cout << "Path to collect maximum coins: ";
    for (int k = index - 1; k >= 0; k--) {
        cout << "(" << path[k][0] << ", " << path[k][1] << ")";
        if (k != 0) cout << " -> ";
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

    // Dynamically allocate the grid
    int** grid = new int*[m];
    for (int i = 0; i < m; i++) {
        grid[i] = new int[n];
    }

    // Input grid values
    cout << "Enter the grid values:" << endl;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cin >> grid[i][j];
        }
    }

    // Maximum possible path length is m + n - 1
    int path[100][2]; // Adjust size if needed

    int maxCoinsCollected = maxCoins(grid, m, n, path);
    cout << "Maximum coins collected: " << maxCoinsCollected << endl;

    // Free allocated memory
    for (int i = 0; i < m; i++) {
        delete[] grid[i];
    }
    delete[] grid;

    return 0;
}
