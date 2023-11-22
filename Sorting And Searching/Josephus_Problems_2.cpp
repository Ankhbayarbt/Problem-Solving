#include <iostream>
#include <algorithm>
#include <set>
#include <vector>
#define N 200001
#define ll long long

using namespace std;

vector<ll> s;

void build(ll id,ll L,ll R) {
    if ( L == R ) {
        s[id] = 1;
        return;
    }
    ll M = L + (R - L) / 2, x = 2 * id + 1, y = x + 1;
    build(x, L, M);
    build(y, M + 1, R);
    s[id] = s[x] + s[y];
}

ll query(ll id, ll L, ll R, ll k) {
    if ( L == R ) {
        s[id] = 0;
        return L;
    }
    ll M = L + (R - L) / 2, x = 2 * id + 1, y = x + 1, ans;
    if ( s[x] > k ) {
         ans = query(x, L, M, k);
         s[id] = s[x] + s[y];
    }
    else {
        ans = query(y, M + 1, R, k - s[x]);
        s[id] = s[x] + s[y];
    }
    return ans;
        
}

int main() {
    ll n, k, skip, child, m;
    cin >> n >> k;
    m = n;
    s.resize(4*N);
    build(0, 0, n - 1);
    skip = k;
    child = n;
    skip = skip % child;
    n--;
    while ( n-- ) {
        cout << query(0, 0, m - 1, skip) + 1 << " ";
        skip += k;
        child --;
        skip = skip % child;
    }
    cout << query(0, 0, m - 1, skip) + 1 << " ";
}

