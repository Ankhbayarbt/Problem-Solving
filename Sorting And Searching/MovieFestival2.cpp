#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <set>
#define f first 
#define s second
 
using namespace std;
 
int main() {
    int n, a, b, end, ans = 0, member;
    cin >> n >> member;
    vector<pair <pair <int, int>, bool> > v(n); // end start bool
    multiset <int> ms;
    for (int i = 0; i < n; i++ ) {
        cin >> v[i].f.s >> v[i].f.f;
        v[i].s = 0;
    }
    sort(v.begin(), v.end());
    ms.insert(-v[0].f.f);
    v[0].s = true;
    member--;
    for (int i = 1; i < n; i++) {
        auto it = ms.lower_bound( -v[i].f.s);
        if ( it != ms.end() ) {
            ms.erase(it);
            member++;
        }
        // while ( ms.begin() != ms.end() && *(ms.begin()) <= v[i].f.s ) {
        //     auto it = ms.begin();
        //     ms.erase(it);
        //     member++;
        // }
        if ( member > 0 ) {
            member--;
            v[i].s = true;
            ms.insert(-v[i].f.f);
        }

    }
    // cout << endl;
    // cout << endl;
    // for (int i = 0; i < n; i++) {
    //     cout << v[i].f.f << " " << v[i].f.s << " " << v[i].s << endl;
    // }
    // cout << endl;
    // cout << endl;
    for (int i = 0; i < n; i++) {
        if ( v[i].s ) 
            ans++;
    }

    cout << ans << endl;
 
    
}
/*
10 2
62 83
38 87
99 100
37 74
17 86
40 44
70 81
65 97
11 85
92 95
*/