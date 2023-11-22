#include <iostream>

using namespace std;

int main() {
    long long a[1000001], n, mod = 1000000007;
    cin >> n;
    a[0] = 1;
    a[1] = 1;
    a[2] = 2;
    a[3] = 4;
    a[4] = 8;
    a[5] = 16;
    for (int i = 6; i <= n; i++) {
        a[i] = a[i - 1] + a[i - 2] + a[i - 3] + a[i - 4] + a[i - 5] + a[i - 6];
        a[i] = a[i] % mod;
    }
    cout << a[n] << endl;
}