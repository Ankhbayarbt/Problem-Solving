#include <iostream>
#include <algorithm>
#define N 200001

using namespace std;

int main() {
    long long n, x, a[N], ans = 0, ih, baga;
    cin >> n >> x;
    for (int i = 0; i < n; i++) cin >> a[i];
    sort (a, a + n);
    ih = n - 1; baga = 0;
    while ( ih >= baga ) {
        if ( a[ih] + a[baga] <= x ) baga++;
        ih--;
        ans++;
    }
    cout << ans << endl;
}