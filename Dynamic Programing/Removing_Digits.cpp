#include <iostream>

using namespace std;

int main() {
    int n, ans = 0, ts = 0, b;
    cin >> n;
    while ( n > 9 ) {
        b = n;
        ts = 1;
        while ( b > 0 ) {
            ts = max(ts, b%10);
            b /= 10;
        }
        n -= ts;
        ans++;
    }
    cout << ans+1 << endl;
}