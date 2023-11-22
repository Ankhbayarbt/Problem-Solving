#include <iostream>
#include <cmath>
#include <vector>
#include <set>
#include <algorithm>
#include <string>

using namespace std;

long long prefix[5001];
long long dp[5001][5001];
bool check[5001][5001];
int n;

long long myFunc(int l, int r) {
    if ( check[l][r] ) return dp[l][r];
    if ( l == r ) return dp[l][r];
    check[l][r] = true;
    dp[l][r] = prefix[r] - prefix[l - 1] - min(myFunc(l, r - 1), myFunc(l + 1, r));
    return  dp[l][r];

}

int main() {
    cin >> n;
    prefix[0] = 0;
    for (int i = 1; i <= n; i++) {
        int x; cin >> x;
        dp[i][i] = x;
        prefix[i] = prefix[i - 1] + x;
    }
    cout << myFunc(1, n) << endl;
}

/*
4 
4 5 1 3
*/