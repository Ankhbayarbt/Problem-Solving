#include <iostream>
#include <algorithm>
#define ll long long
#define N 200001

using namespace std;

int main() {
    ll n, k, a[N], sum = 0, heseg, ih = 0, s = 0, ans = 0, lo, hi, m;
    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        sum += a[i];
        ih = max(ih, a[i]);
    }
    lo = ih;
    hi = sum;
    while ( lo + 1 < hi ) {
        m = lo + (hi - lo) / 2;
        ans = 1;
        s = 0;
        for (int i = 0; i < n; i++) {
            if ( s + a[i] <= m ) {
                s += a[i];
            }else {
                s = a[i];
                ans++;
            }
        }
        if ( ans <= k ) {
            hi = m;
        }else {
            lo = m;
        }
    }
    ans = 1;
    s = 0;
    for (int i = 0; i < n; i++) {
        if ( s + a[i] <= lo )
            s += a[i];
        else {
            s = a[i];
            ans++;
        }
    }
    if ( ans <= k ) 
        cout << lo << endl;
    else 
        cout << hi << endl;

}