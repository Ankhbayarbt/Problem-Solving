#include <iostream>
#include <algorithm>
#include <set>
#include <map>
#define N 200001
#define ll long long
 
using namespace std;
 
int main() {
    ll ans = 0, s = 0, a, n, s1 = 0;
    map <ll, ll> m;
    cin >> n;
    m[0] = 1;
    for (int i = 0; i < n; i++) {
        cin >> a;
        s1 = (s1 + a) % n ;
        s = (s1 + n) % n;
        auto it = m.find(s);
        if ( it != m.end() )
            ans += it->second;
        m[s]++;
    }
    cout << ans << endl;
}