#include <iostream>
#include <vector>
#define N 200001
#define mod 1000000007
#define ll long long

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> value(n);
    for (int i = 0; i < n; i++) {
        cin >> value[i];
    }
    vector<vector<ll> > count(n, vector<ll>(m+1, 0));
    if ( value[0] != 0 ) count[0][value[0]] = 1;
    else {
        for (int i = 1; i <= m; i++) {
            count[0][i] = 1;
        }
    }

    for (int i = 1; i < n; i++) {
        if ( value[i] == 0 ) {
            for (int j = 1; j <= m; j++) {
                if ( j > 0 ) count[i][j] += count[i-1][j-1];
                count[i][j] += count[i-1][j];
                if ( j < m ) count[i][j] += count[i-1][j+1];
                count[i][j] = count[i][j] % mod;
            }
        }else {
            if ( value[i] > 0 ) count[i][value[i]] += count[i-1][value[i] - 1];
            count[i][value[i]] += count[i-1][value[i]];
            if ( value[i] < m ) count[i][value[i]] += count[i-1][value[i] + 1];
        }
    }
    ll ans = 0;
    for (int i = 0; i <= m; i++) {
        ans += count[n - 1][i];
        ans = ans % mod;
    }
    cout << ans << endl;
}

/*
3 5
2 0 2
*/