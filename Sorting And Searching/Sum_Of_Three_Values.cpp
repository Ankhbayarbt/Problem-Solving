#include <iostream>
#include <set>
#include <algorithm>

using namespace std;

int main() {
    long long n, x, s, l, r, ans1, ans2;
    cin >> n >> x;
    int a[n], b[n];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        b[i] = a[i];
    }
    if ( n < 3 ) {
        cout << "IMPOSSIBLE" << endl;
        return 0;
    }
    sort(a, a + n);
    for (int i = 0; i < n; i++) {
        s = x - a[i];
        l = 0; 
        r = n - 1;
        while ( r > l ) {
            if ( r == i ) 
                r--;
            if ( l == i ) 
                l++;
            if ( a[r] + a[l] > s ) {
                r--;
            }else if ( a[r] + a[l] < s ) 
                l++;
            else {
                for (int j = 0; j < n; j++) {
                    if ( b[j] == a[i] ) {
                        cout << j + 1 << " ";
                        ans1 = j;
                        break;
                    }
                }
                for (int j = 0; j < n; j++) {
                    if ( b[j] == a[l] && j != ans1) {
                        cout << j + 1 << " ";
                        ans2 = j;
                        break;
                    }
                }
                for (int j = 0; j < n; j++) {
                    if ( b[j] == a[r] && j != ans1 && j != ans2) {
                        cout << j + 1 << " ";
                        break;
                    }
                }
                cout << endl;
                return 0;
            }
        }
    }
    cout << "IMPOSSIBLE" << endl;
}