#include <iostream>
#include <algorithm>
#define N 200001

using namespace std;

int main() {
    long long n, a, b, a1[N] = {0}, a2[N] = {0}, ans = 0, c = 0, sum = 0, i, j;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a >> b;
        a1[i] = a;
        a2[i] = b;
    }
    sort (a1, a1 + n);
    sort (a2, a2 + n);
    i = 0; j = 0;
    a1[n] = 1000000002;
    a2[n] = 1000000002;
    for (int e = 0; e < 2 * n; e++) {
        if ( a1[i] < a2[j] ) {
            sum ++;
            i ++;
        }else {
            sum --;
            j++;
        }
        if ( sum > ans ) ans = sum;
    }
    cout << ans << endl;
    return 0;
}