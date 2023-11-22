#include <iostream>
#include <string>
#include <cmath>

using namespace std;

long long a[100000][100];

void check(int n) {
    if ( n == 1 ) {
        a[1][1] = 0;
        a[2][1] = 1;
    }else {
        check (n - 1);
        long long k = pow(2, n - 1);
        for (int i = 1; i <= k; i++) {
            for (int j = 1; j <= n-1; j++) {
                a[ k * 2 - i + 1][j] = a[i][j]; 
            }
            a[ k + i][n] = 1;
            a[i][n] = 0;
        }
    }


}

int main() {
    int n, k;
    cin >> n;
    check(n);
    k = pow(2, n);
    for (int i = 1; i <= k; i++) {
        for (int j = n; j >= 1; j--) {
            cout << a[i][j];
        }
        cout << endl;
    }
    
}