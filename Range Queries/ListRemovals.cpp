#include <iostream>
#include <cmath>
#include <vector>
#include <string>
#include <set>
#define ll long long
#define N 200001
#define f first 
#define s second

using namespace std;

vector <ll> a;
vector <pair<ll, ll> > s;
int n;

void build(int id, int l, int r) {
    if ( l == r ) {
        s[id].f = a[l];
        s[id].s = 1;
        return;
    }
    int m = l + (r - l) / 2, x = 2 * id + 1, y = x + 1;
    build(x, l, m);
    build(y, m + 1, r);
    s[id].s = s[x].s + s[y].s;
}

ll query(int id, int L, int R, int r) {
    if ( L == R ) {
        s[id].s = 0;
        return s[id].f;
    }
    int M = L + (R - L) / 2, x = 2 * id + 1, y = x + 1, ans;
    if ( r <= s[x].s ) ans = query(x, L, M, r);
    else ans = query(y, M + 1, R, r - s[x].s);

    s[id].s = s[x].s + s[y].s;
    return ans;
}

int main() {
    cin >> n;
    a.resize(n);
    s.resize(4*n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    build(0, 0, n - 1);
    for (int i = 0; i < n; i++) {
        int p; cin >> p;
        cout << query(0, 0, n - 1, p) << " ";
    }
    cout << endl;

}

/*
5
2 6 1 4 2
3 1 3 1 1
*/