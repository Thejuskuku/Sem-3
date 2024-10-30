#include <iostream>
#include <algorithm>
using namespace std;

int maxCoins(int grid[][4], int m, int n) {
    int dp[m][n];
    dp[0][0] = grid[0][0];

    for (int i = 1; i < m; i++) dp[i][0] = dp[i - 1][0] + grid[i][0];
    for (int j = 1; j < n; j++) dp[0][j] = dp[0][j - 1] + grid[0][j];

    for (int i = 1; i < m; i++) {
        for (int j = 1; j < n; j++) {
            dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]) + grid[i][j];
        }
    }
    return dp[m - 1][n - 1];
}

int main() {
    int grid[3][4] = {{0, 3, 1, 1}, {2, 0, 0, 4}, {1, 5, 3, 1}};
    cout << "Maximum coins collected: " << maxCoins(grid, 3, 4) << endl;
    return 0;
}