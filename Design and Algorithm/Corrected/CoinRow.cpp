#include <iostream>
#include <algorithm>
using namespace std;

int maxCoins(int coins[], int n) {
    if (n == 0) return 0;
    if (n == 1) return coins[0];

    int dp[n];
    bool selected[n]; // Array to keep track of selected items

    dp[0] = coins[0];
    selected[0] = true; // First coin is selected by default

    if (coins[1] > coins[0]) {
        dp[1] = coins[1];
        selected[1] = true;
        selected[0] = false;
    } else {
        dp[1] = coins[0];
        selected[1] = false;
    }

    for (int i = 2; i < n; i++) {
        if (dp[i - 1] > dp[i - 2] + coins[i]) {
            dp[i] = dp[i - 1];
            selected[i] = false; // Do not pick the current coin
        } else {
            dp[i] = dp[i - 2] + coins[i];
            selected[i] = true; // Pick the current coin
        }
    }

    // Output the maximum coins collected
    cout << "Maximum coins collected: " << dp[n - 1] << endl;

    // Backtracking to find which coins were selected
    cout << "Coins collected: ";
    int i = n - 1;
    while (i >= 0) {
        if (selected[i]) {
            cout << coins[i] << " ";
            i -= 2; // Move back two positions if the coin was selected
        } else {
            i--; // Move back one position if the coin was not selected
        }
    }
    cout << endl;

    return dp[n - 1];
}

int main() {
    int coins[] = {5, 3, 4, 11, 2};
    int n = sizeof(coins) / sizeof(coins[0]);
    maxCoins(coins, n);
    return 0;
}
