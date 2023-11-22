#include <iostream> 

using namespace std;

int main() {
    long long n, m, ans;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        if ( i == 1 ) {
            cout << 0 << endl;
            continue;
        }
        if ( i == 2 ) {
            cout << 6 << endl;
            continue;
        }
        if ( i == 3 ) {
            cout << 28 << endl;
            continue;
        }
        ans = 0;
        m = i * i - 1;
        ans = ans + 4 * (m - 2); // 4n bulan
        ans = ans + 8 * (m - 3); // bulangiin hajuu irmeg
        ans = ans + (4 + (i - 4) * 4 ) * ( m - 4 ); // irmeg + 2r bulan
        ans = ans + 4 * ( i - 4 ) * ( m - 6 ); // 2r irmeg
        ans = ans + ( i - 4 ) * ( i - 4 ) * ( m - 8 ); // gol heseg
        cout << ans / 2 << endl;

    }
}