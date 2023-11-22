#include <iostream>
#include <algorithm>
#define N 200001

using namespace std;

int main() {
    long long n, a[N], sum = 0;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    sort(a + 1, a + n + 1);
    if ( a[1] != 1 ) {
        cout << 1 << endl;
        return 0;
    }
    sum = a[1];
    for (int i = 2; i <= n; i++) {
        if ( a[i] > sum + 1 ) {
            cout << sum + 1 << endl;
            return 0;
        }
        sum += a[i];
    }
    cout << sum + 1 << endl;
    return 0;

}