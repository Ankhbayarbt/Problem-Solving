#include <iostream>
#include <cmath>
#define N 200001

using namespace std;

int main() {
    long long n, a[N], ans, k = 0;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    ans = a[0];
    for (int i = 0; i < n; i++) {
        k += a[i];
        if ( k > ans ) ans = k;
        if ( k < 0 ) k = 0;
    }
    
    cout << ans << endl;
    return 0;
}

/*
8
-1 3 -2 5 3 -5 2 2
*/