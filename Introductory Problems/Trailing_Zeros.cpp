#include <iostream>

using namespace std;

int main() {
    long long n, k, ans = 0;
    cin >> n;
    for (int i = 5; i <= n; i += 5) {
        k = i;
        while ( k % 5 == 0 ) {
            k /= 5;
            ans++;
        }
    }
    cout << ans << endl;
}