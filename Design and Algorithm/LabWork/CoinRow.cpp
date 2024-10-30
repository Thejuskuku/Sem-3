#include <iostream>
#include <algorithm>
using namespace std;

int maxCoins(int coins[], int n) {
    if (n == 0) return 0;
    if (n == 1) return coins[0];

    int dp[n];
    dp[0] = coins[0];
    dp[1] = max(coins[0], coins[1]);

    for (int i = 2; i < n; i++) {
        dp[i] = max(dp[i - 1], dp[i - 2] + coins[i]);
    }
    return dp[n - 1];
}

int main() {
    int coins[] = {5, 3, 4, 11, 2};
    int n = sizeof(coins) / sizeof(coins[0]);
    cout << "Maximum coins collected: " << maxCoins(coins, n) << endl;
    return 0;
}
