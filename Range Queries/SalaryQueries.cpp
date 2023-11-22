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
vector <pair<ll, ll> > range;
int n;
 
void build(int id, int l, int r) {
    if ( l == r ) {
        s[id] = range[id].f = range[id].s = a[l];
        return;
    }
    int m = l + (r - l) / 2, x = 2 * id + 1, y = x + 1;
    build(x, l, m);
    build(y, m + 1, r);
    range[id].f = min(range[x].f, range[y].f);
    range[id].s = max(range[x].s, range[y].s);
}
 
void update(int id, int L, int R, int k, int t) {
    if ( L == R ) {
        s[id] = range[id].f = range[id].s = t;
        return;
    }
    int M = L + (R - L) / 2, x = 2 * id + 1, y = x + 1;
    if ( k <= M ) update(x, L, M, k, t);
    else update(y, M + 1, R, k, t);
 
    range[id].f = min(range[x].f, range[y].f);
    range[id].s = max(range[x].s, range[y].s);
}
 
ll query(int id, int L, int R, int l, int r) {
    if ( L == R ) {
        if ( l <= s[id] && s[id] <= r ) return 1;
        return 0;
    }
    int M = L + (R - L) / 2, x = 2 * id + 1, y = x + 1, ans = 0;
    if ( range[x].f <= r && range[x].s >= l ) {
        ans += query(x, L, M, l, r);
    }
    if ( range[y].f <= r && range[y].s >= l ) {
        ans += query(y, M + 1, R, l, r);
    }
    return ans;
}
 
int main() {
    fastio
    int k, x, l, r, q;
    cin >> n >> q;
    a.resize(n);
    s.resize(4*n);
    range.resize(4*n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    build(0, 0, n - 1);
    while (q--) {
        char ch; cin >> ch;
        if ( ch == '!' ) {
            cin >> k >> x;
            update(0, 0, n - 1, k - 1, x);
        }else {
            cin >> l >> r;
            cout << query(0, 0, n - 1, l, r) << endl;
        }
    }
 
}
 
/*
5 3
3 7 2 2 5
? 2 3
! 3 6
? 2 3
*/