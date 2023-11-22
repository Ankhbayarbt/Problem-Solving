#include <iostream> 

using namespace std;

int main() {
    long long t, a, b, m, n;
    cin >> t;
    for (int i = 0; i < t; i++) {
        cin >> a >> b;
        m = max(a, b);
        n = min(a, b);
        if ( (m + n) % 3 == 0 && m <= 2 * n) {
            cout << "YES" << endl;
        }
        else cout << "NO" << endl;
    }
}
