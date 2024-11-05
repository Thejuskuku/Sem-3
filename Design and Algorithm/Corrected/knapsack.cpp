#include <iostream>
#include <algorithm>
using namespace std;

int knapsack(int W, int wt[], int val[], int n) {
    int dp[n + 1][W + 1];

    // Fill dp table
    for (int i = 0; i <= n; i++) {
        for (int w = 0; w <= W; w++) {
            if (i == 0 || w == 0)
                dp[i][w] = 0;
            else if (wt[i - 1] <= w)
                dp[i][w] = max(dp[i - 1][w], val[i - 1] + dp[i - 1][w - wt[i - 1]]);
            else
                dp[i][w] = dp[i - 1][w];
        }
    }

    // Backtracking to find the items included
    int res = dp[n][W];
    cout << "Maximum value in knapsack: " << res << endl;
    cout << "Items included: ";
    
    int w = W;
    int items[n]; // Array to store item indices
    int itemCount = 0; // Counter for the number of items included

    for (int i = n; i > 0 && res > 0; i--) {
        // If the item is included in the optimal subset
        if (res != dp[i - 1][w]) {
            items[itemCount++] = i - 1; // Store the item index
            res -= val[i - 1];
            w -= wt[i - 1];
        }
    }

    // Print the items in reverse order
    for (int i = itemCount - 1; i >= 0; i--) {
        cout << "Item " << items[i] << " ";
    }
    cout << endl;

    return dp[n][W];
}

int main() {
    int n;
    cout << "Enter the number of items: ";
    cin >> n;

    int wt[n], val[n];
    cout << "Enter the weights of the items: ";
    for (int i = 0; i < n; i++) {
        cin >> wt[i];
    }

    cout << "Enter the values of the items: ";
    for (int i = 0; i < n; i++) {
        cin >> val[i];
    }

    int W;
    cout << "Enter the maximum weight capacity of the knapsack: ";
    cin >> W;

    knapsack(W, wt, val, n);

    return 0;
}
