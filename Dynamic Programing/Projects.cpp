#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#define ll long long
#define f first 
#define s second
#define N 200001

using namespace std;

int main() {
    ll n, ih = 0, j = 0, i, ans = 0;
    cin >> n;
    vector < pair < ll, pair < ll, ll > > > v(N);   // end day, start day, reward
    for (int i = 0; i < n; i++) {
        cin >> v[i].s.f >> v[i].f >> v[i].s.s;
        ih = max(ih, v[i].f);
    }
    sort (v.begin(), v.end());
    vector <ll> money(ih + 1);
    i = 1;
    while ( i <= ih ) {
        if ( i < v[j].f ) {
            money[i] = max(money[i-1], money[i]);
            i++;
        }
        else if ( i == v[j].f ) {
            money[i] = max(money[i], money[v[j].s.f - 1] + v[j].s.s);
            j++;
            if ( i == ih ) i++;
        }
        else j++;
    }

    for (int i = 0; i <= ih; i++) {
        ans = max(ans, money[i]);
    }
    cout << ans << endl;
}

/*
4
2 4 4
3 6 6
6 8 2
5 7 3
*/

/*
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#define ll long long
#define f first 
#define s second

using namespace std;

int main() {
    ll n, ih = 8, j = 0, i;
    //cin >> n;
    n = 4;
    vector < pair < ll, pair < ll, ll > > > v(n);   // end day, start day, reward
    // for (int i = 0; i < n; i++) {
    //     cin >> v[i].s.f >> v[i].f >> v[i].s.s;
    //     ih = max(ih, v[i].f);
    // }
    v[0].s.f = 2;
    v[0].f = 4;
    v[0].s.s = 4;

    v[1].s.f = 3;
    v[1].f = 6;
    v[1].s.s = 6;

    v[2].s.f = 6;
    v[2].f = 8;
    v[2].s.s = 2;

    v[3].s.f = 5;
    v[3].f = 7;
    v[3].s.s = 3;
    sort (v.begin(), v.end());
    for (ll int i = 0; i < n; i++) {
        cout << v[i].s.f << " " << v[i].f << " " << v[i].s.s << endl;
    }
    vector <ll> money(ih + 1);
    i = 1;
    while ( i <= ih ) {
        if ( i < v[j].f ) {
            money[i] = max(money[i-1], money[i]);
            i++;
        }
        else if ( i == v[j].f ) {
            money[i] = max(money[i], money[v[j].s.f - 1] + v[j].s.s);
            j++;
            if ( i == ih ) i++;
        }
        else j++;
    }

    for (int i = 0; i <= ih; i++) {
        cout << money[i] << " ";
    }
    cout << endl;
}

*/