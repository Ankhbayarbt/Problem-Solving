#include <iostream>

using namespace std;

int main() {
    long long t, y, x, ans;
    cin >> t;
    for (int e = 0; e < t; e++) {
        cin >> x >> y;
        if ( x > y ) {
            if ( x % 2 == 0 ) ans = x * x - y + 1;
            else ans = (x - 1) * (x - 1) + y;
        }else {
            if ( y % 2 == 1 ) ans = y * y - x + 1;
            else ans = (y - 1) * (y - 1) + x;
        }
        cout << ans << endl;
    }
}