#include <iostream>
#include <vector>
// #define N 200001
#define mod 1000000007
#define ll long long
#define f first
#define s second

using namespace std;

int n, x, N;

pair<int, int> merge(int weight, pair<int, int> dp) {
    pair<int, int> ans;
    if ( dp.s + weight <= x ) {
        ans.f = dp.f;
        ans.s =  dp.s + weight;
    }
    else {
        ans.f = dp.f + 1;
        ans.s = weight;
    }
    return ans;
}

int main() {
    cin >> n >> x;
    N = (1<<n);
    vector <int> p(n);   // weight of each person
    for (int i = 0; i < n; i++) {
        cin >> p[i];
    }
    vector<pair<int, int> > dp(N);
    for (int i = 0; i < N; i++) {
        dp[i].f = n;
        dp[i].s = x;
    }
    dp[0].f = 1;
    dp[0].s = 0;
    for (int i = 1; i < N; i++) {
        for (int j = 0; j < n;  j++) {
            if ( ((1<<j) & i) > 0 ) {
                pair <int, int> m;
                m = merge(p[j], dp[i ^ (1<<j)]);
                dp[i] = min(dp[i], m);
            } 
        }
    }
    cout << dp[N - 1].f; 
    // for (int i = 0; i < N; i++) {
    //     cout << dp[i].f << " ";
    // }
    cout << endl;
}

/*
4 10
4 8 6 1
*/