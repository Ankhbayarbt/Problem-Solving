#include <iostream>

using namespace std;

long long b[10000001] = {0}, i;

void haha(int n,long long a[]) {
    if ( n == 1 ) {
        b[1] = a[1];
        b[2] = - a[1];
        return;
    }
    haha(n - 1, a);
    int m = (1 << n);
    for (int i = 1; i <= m/2; i++) {
        b[i + m/2] = b[i] - a[n];
    }
    for (int i = 1; i <= m/2; i++) {
        b[i] = b[i] + a[n];
    }

}

int main() {
    long long n, a[21], ans, k;
    cin >> n;
    for (int j = 1; j <= n; j++ ) cin >> a[j];
    haha(n, a);
    k = (1 << n);
    ans = b[1];
    for (int j = 1; j <= k/2; j++) {
        if ( ans > abs(b[j]) ) ans = abs(b[j]);
        if ( ans == 0 ) break;
    }
    cout << ans << endl;
}