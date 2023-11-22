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
}

void update(int id, int L, int R, int l, int r, int u) {
    if ( L == l && r == R ) {
        s[id] += u;
        return;
    }
    int M = L + (R - L) / 2, x = 2 * id + 1, y = x + 1;
    if ( r <= M ) update(x, L, M, l, r, u);
    else if ( M < l ) update(y, M + 1, R, l, r, u);
    else {
        update(x, L, M, l, M, u);
        update(y, M + 1, R, M + 1, r, u);
    }
}

ll query(int id, int L, int R, int i) {
    if ( L == R ) {
        return s[id];
    }
    int M = L + (R - L) / 2, x = 2 * id + 1, y = x + 1;
    if ( i <= M ) return s[id] + query(x, L, M, i);
    else return s[id] + query(y, M+1, R, i);
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
        int a, b, c, u, k;
        cin >> c;
        if ( c == 1 ) {
            cin >> a >> b >> u;
            update(0, 0, n - 1, a - 1, b - 1, u);
        }else {
            cin >> k;
            cout << query(0, 0, n - 1, k - 1) << endl;
        }
    }
}

/*
8 3
3 2 4 5 1 1 5 3
2 4
1 2 5 1
2 4
*/