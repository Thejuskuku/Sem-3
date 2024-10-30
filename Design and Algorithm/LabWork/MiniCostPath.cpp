#include <iostream>
#include <algorithm>
using namespace std;

int minCostPath(int cost[][3], int m, int n) {
    int dp[m][n];
    dp[0][0] = cost[0][0];

    for (int i = 1; i < m; i++) dp[i][0] = dp[i - 1][0] + cost[i][0];
    for (int j = 1; j < n; j++) dp[0][j] = dp[0][j - 1] + cost[0][j];

    for (int i = 1; i < m; i++) {
        for (int j = 1; j < n; j++) {
            dp[i][j] = min(dp[i - 1][j], dp[i][j - 1]) + cost[i][j];
        }
    }
    return dp[m - 1][n - 1];
}

int main() {
    int cost[3][3] = {{1, 3, 5}, {2, 1, 2}, {4, 3, 1}};
    cout << "Minimum cost path: " << minCostPath(cost, 3, 3) << endl;
    return 0;
}
