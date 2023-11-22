#include <iostream>
#include <algorithm>
#define N 200001

using namespace std;

int main() {
    long long n, x, a[N], b[N], l, r, ans = 0;
    cin >> n >> x;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        b[i+1] = b[i] + a[i];
    }
    l = 0;
    r = 1;
    while ( r <= n ) {
        if ( b[r] - b[l] < x ) 
            r++;
        else if ( b[r] - b[l] > x )
            l++;
        else {
            ans++;
            l++;
            r++;
        }
    }
    cout << ans << endl;


}