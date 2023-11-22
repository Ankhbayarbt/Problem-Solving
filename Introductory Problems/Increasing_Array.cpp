#include <iostream> 

using namespace std;

int main() {
    long long n, a[200001], ans = 0;
    cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < n - 1; i++) {
        if ( a[i] > a[i + 1] ) {
            ans = ans + (a[i] - a[i + 1]);
            a[i + 1] = a[i];
        }
    }
    cout << ans << endl;
    return 0;
}