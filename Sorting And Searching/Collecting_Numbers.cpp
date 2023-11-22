#include <iostream>
#include <algorithm>
#define N 200001

using namespace std;

int main() {
    int n, ans = 0;
    cin >> n;
    int a[N], b[N] = {0};
    for (int i = 1; i <= n; i++) 
        cin >> a[i];
    for (int i = 1; i <= n; i++) {
        if ( b[a[i] - 1] == 0 ) {
            ans ++;
        }
        b[a[i]] = 1;
    }
    cout << ans << endl;
    /*for (int i = 0; i <= n; i++) {
        cout << b[i] << " ";
    }
    cout << endl;
    */
    return 0;
}