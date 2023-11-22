#include <iostream>
#include <cmath>
#include <vector>
#include <string>
#include <set>
#define ll long long
#define N 200001

using namespace std;

vector <ll> a, s;
int n;

void build(int id, int l, int r) {
    if ( l == r ) {
        s[id] = a[l];
        return;
    }
    int m = l + (r - l) / 2, x = 2 * id + 1, y = x + 1;
    build(x, l, m);
    build(y, m + 1, r);
    s[id] = max(s[x], s[y]);
}

ll query(int id, int L, int R, int r) {
    if ( L == R ) {
        s[id] -= r;
        return L;
    }
    int M = L + (R - L) / 2, x = 2 * id + 1, y = x + 1, ans;
    if ( r <= s[x] ) ans = query(x, L, M, r);
    else ans = query(y, M + 1, R, r);

    s[id] = max(s[x], s[y]);
    return ans;
}

int main() {
    int q;
    cin >> n >> q;
    a.resize(n);
    s.resize(4*n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    build(0, 0, n - 1);
    while (q--) {
        int r;
        cin >> r;
        if ( s[0] < r ) cout << 0 << endl;
        else cout << query(0, 0, n - 1, r) + 1 << endl;
    }
}

/*
8 5
3 2 4 1 5 5 2 6
4 4 7 1 1
*/