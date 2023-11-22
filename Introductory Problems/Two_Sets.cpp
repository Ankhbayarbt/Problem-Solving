#include <iostream> 

using namespace std;
 
int main() {
    long long n, m, sum = 0, ans, k;
    cin >> n;
    k = n;
    m = n * (n + 1) / 2;
    if ( m % 2 == 1 ) cout << "NO" << endl;
    else {
        cout << "YES" << endl;
        m = m / 2;
        while ( sum < m ) {
            sum += k;
            k --;
        }
        if ( sum == m ) {
            cout << n - k << endl;
            for (int i = n; i > k; i -- ) {
                cout << i << " ";
            }
            cout << endl << k << endl;
            for (int i = 1; i < k + 1; i++) {
                cout << i << " ";
            }
        }
        else {
            ans = m - ( sum - (k + 1) );
            cout << n - k << endl;
            for (int i = n; i > k + 1; i -- ) {
                cout << i << " ";
            }
            cout << ans << endl << k << endl;
            for (int i = 1; i < k + 2; i++) {
                if ( i != ans ) cout << i << " ";
            }
        }
        cout << endl;
    }
}