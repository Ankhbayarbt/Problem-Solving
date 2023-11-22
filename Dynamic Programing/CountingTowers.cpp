#include <iostream>
#include <cmath>
using namespace std;

const int mod = 1e9 + 7;

int main() {
    int n;
    cin >> n;
    int dp[n + 1][2][2]; // dp table

    // Base case
    dp[1][0][0] = dp[1][0][1] = dp[1][1][0] = 1;
    dp[1][1][1] = 0;

    // Fill the dp table
    for (int i = 2; i <= n; i++) {
        dp[i][0][0] = (dp[i-1][0][0] + dp[i-1][0][1] + dp[i-1][1][0]) % mod;
        dp[i][0][1] = (dp[i-1][0][0] + dp[i-1][1][0]) % mod;
        dp[i][1][0] = (dp[i-1][0][0] + dp[i-1][0][1]) % mod;
        dp[i][1][1] = dp[i-1][1][0];
    }

    // Calculate the final answer
    int ans = (dp[n][0][0] + dp[n][0][1] + dp[n][1][0] + dp[n][1][1]) % mod;

    cout << ans << endl;
    return 0;
}
