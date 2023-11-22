#include <iostream>
#include <algorithm>
#define N 200001

using namespace std; 

int main() {
    long long n, m, k, a[N], b[N], ans = 0, s;
    cin >> n >> m >> k;
    for (int i = 0; i < n; i ++) cin >> a[i];
    for (int i = 0; i < m; i ++) cin >> b[i];
    sort (a, a + n);
    sort (b, b + m);
    s = 0;
    for (int i = 0; i < n; i++) {
        for (int j = s; j < m; j++) {
            if ( a[i] + k < b[j] ) {
                s = j;
                break;
            }
            if ( a[i] - k <= b[j] && a[i] + k >= b[j] ) {
                ans ++;
                s = j + 1;
                break;
            }
        }
    }
    cout << ans << endl;
}