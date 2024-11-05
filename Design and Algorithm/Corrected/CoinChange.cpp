#include <iostream>
using namespace std;

int minCoin(int coin[], int n, int amount, int coinsUsed[])
{
    int dp[amount + 1];
    dp[0] = 0; // Base case: no coins are needed to make amount 0

    // Initialize dp array and coinsUsed array
    for (int i = 1; i <= amount; i++) {
        dp[i] = 1000; // 1000 as a large number for "infinity"
        coinsUsed[i] = -1; // To indicate no coin has been used yet
    }

    // Compute the minimum coins required for each amount from 1 to amount
    for (int i = 1; i <= amount; i++) {
        for (int j = 0; j < n; j++) {
            if (coin[j] <= i && dp[i - coin[j]] != 1000) {
                if (dp[i] > 1 + dp[i - coin[j]]) {
                    dp[i] = 1 + dp[i - coin[j]];
                    coinsUsed[i] = coin[j]; // Track the coin used
                }
            }
        }
    }
    
    return dp[amount] == 1000 ? -1 : dp[amount];
}

void printCoinsUsed(int amount, int coinsUsed[])
{
    if (coinsUsed[amount] == -1) {
        cout << "Not Possible" << endl;
        return;
    }

    cout << "Coins used to make the amount: ";
    while (amount > 0) {
        cout << coinsUsed[amount] << " ";
        amount -= coinsUsed[amount];
    }
    cout << endl;
}

int main()
{
    int n;
    cout << "Enter the number of coin denominations: ";
    cin >> n;

    int coin[n];
    cout << "Enter the coin denominations: ";
    for (int i = 0; i < n; i++) {
        cin >> coin[i];
    }

    int amount;
    cout << "Enter the amount: ";
    cin >> amount;

    int coinsUsed[amount + 1];

    int result = minCoin(coin, n, amount, coinsUsed);
    if (result == -1) {
        cout << "Not Possible" << endl;
    } else {
        cout << "Minimum number of coins required is " << result << endl;
        printCoinsUsed(amount, coinsUsed);
    }
    return 0;
}
