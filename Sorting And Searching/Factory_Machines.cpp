#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;

int main() {
    long long n, t;
    cin >> n >> t;
    vector <int> machines(n);
    for (int i = 0; i < n; i++) {
        cin >> machines[i];
    }
    long long lo = 0, hi = 1e18, ans = 1e18;
    while ( lo <= hi ) {
        long long mid = (hi + lo) / 2;
        long long products = 0;
        for (int i = 0; i < n; i++) {
            if ( mid/machines[i] < 1e9 ) 
                products += mid/machines[i];
            else 
                products += 1e9;
        }
        if ( products >= t ) {
            if ( mid < ans ) 
                ans = mid;
            hi = mid - 1;
        }else {
            lo = mid + 1;
        }
    } 
    cout << ans << endl;
}