#include <iostream>
#include <algorithm>
using namespace std;

int lcs(char* X, char* Y, int m, int n) {
    int dp[m + 1][n + 1];

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
    return dp[m][n];
}

int main() {
    char X[] = "AGGTAB";
    char Y[] = "GXTXAYB";
    int m = sizeof(X) / sizeof(X[0]) - 1;
    int n = sizeof(Y) / sizeof(Y[0]) - 1;
    cout << "Length of LCS: " << lcs(X, Y, m, n) << endl;
    return 0;
}
