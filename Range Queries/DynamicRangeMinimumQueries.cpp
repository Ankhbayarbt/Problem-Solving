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
    int m = l + (r - l) / 2, x = 2*id + 1, y = x + 1;
    build(x, l, m);
    build(y, m + 1, r);
    s[id] = min(s[x], s[y]);
}

void update(int id, int L, int R, int i, int k) {
    if ( L == R ) {
        s[id] = k;
        return;
    }
    int M = L + (R - L) / 2, x = 2 * id + 1, y = x + 1;
    if ( i <= M ) update(x, L, M, i, k);
    else update(y, M + 1, R, i, k);

    s[id] = min(s[x], s[y]);
}

ll query(int id, int L, int R, int l, int r) {
    if ( L == l and r == R) {
        return s[id];
    }
    int M = L + (R - L) / 2, x = 2*id + 1, y = x + 1;
    if ( r <= M ) return query(x, L, M, l, r);
    if ( M < l ) return query(y, M + 1, R, l, r);
    return min(query(x, L, M, l, M), query(y, M + 1, R, M + 1, r));
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
        int a, b, c, i, k;
        cin >> c;
        if ( c == 1 ) {
            cin >> i >> k;
            update(0, 0, n - 1, i - 1, k);
        }
        else {
            cin >> a >> b;
            cout << query(0, 0, n - 1, a - 1, b - 1) << endl;
        }
    }
}

/*
8 4
3 2 4 5 1 1 5 3
2 1 4
2 5 6
1 3 1
2 1 4
*/