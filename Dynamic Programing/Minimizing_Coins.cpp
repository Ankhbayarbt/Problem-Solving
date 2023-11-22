#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int n, x, a[101];
    cin >> n >> x;
    int b[1000001];
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    for (int i = 1; i <= x; i++)
        b[i] = 1000001;
    for (int i = 1; i <= n; i++) {
        b[a[i]] = 1;
    }
    for (int i = 1; i <= x; i++) {
        for (int j = 1; j <= n; j++) {
            if ( i - a[j] >= 0) {
                if ( b[i] > b[i-a[j]] ) 
                    b[i] = b[i-a[j]] + 1;
            }
        }
    }
    if ( b[x] < 1000001 ) 
        cout << b[x] << endl;
    else 
        cout << -1 << endl;
}