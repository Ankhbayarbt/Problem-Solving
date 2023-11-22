#include <iostream>
#include <algorithm>
#define N 200001

using namespace std;

int main() {
    long long a[N], n, mid, ans = 0;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort(a, a + n);
    mid = a[n/2];
    for (int i = 0; i < n; i++) {
        ans += abs(mid - a[i]);
    }
    cout << ans << endl;
    return 0;
}