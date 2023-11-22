#include <iostream>
#include <cmath>
#include <vector>
#include <string>
#include <set>
#define ll long long
#define N 200001
#define f first 
#define s second
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);

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
    
    if ( s[x] <= 0 && s[y] <= 0 ) s[id] = max(s[x], s[y]);
    else if ( s[x] <= 0 ) s[id] = s[y];
    else if ( s[y] <= 0 ) s[id] = s[x];
    else s[id] = s[x] + s[y];
}

void update(int id, int L, int R, int k, int t) {
    if ( L == R ) {
        s[id] = t;
        return;
    }
    int M = L + (R - L) / 2, x = 2 * id + 1, y = x + 1;
    if ( k <= M ) update(x, L, M, k, t);
    else update(y, M + 1, R, k, t);

    if ( s[x] <= 0 && s[y] <= 0 ) s[id] = max(s[x], s[y]);
    else if ( s[x] <= 0 ) s[id] = s[y];
    else if ( s[y] <= 0 ) s[id] = s[x];
    else s[id] = s[x] + s[y];
}

ll query(int id, int L, int R, int l, int r) {
    if ( L == R ) {
        return s[id];
    }
    int M = L + (R - L) / 2, x = 2 * id + 1, y = x + 1, ans = 0;
    if ( r <= M ) return query(x, L, M, l, r);
    else if ( M < l ) return query(y, M + 1, R, l, r);
    else return query(x, L, M, l, M) + query(y, M + 1, R, M + 1, r);
}

int main() {
    fastio
    int k, x, l, r, q;
    cin >> n >> q;
    a.resize(n);
    s.resize(4*n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    build(0, 0, n - 1);
    while (q--) {
        int ch; cin >> ch;
        if ( ch == 1 ) {
            cin >> k >> x;
            update(0, 0, n - 1, k - 1, x);
        }else {
            cin >> l >> r;
            cout << query(0, 0, n - 1, l, r) << endl;
        }
    }

}

/*
8 4
1 2 -1 3 1 -5 1 4
2 2 6
1 4 -2
2 2 6
2 3 4
*/