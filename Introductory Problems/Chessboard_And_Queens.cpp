#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int ans = 0, a[9][9], b[9];

void put(int n) {
    if ( n == 0 ) {
        ans ++;
        return;
    }
    for (int i = 1; i < 9; i++) {
        if ( a[n][i] == 0 ) {
            int e = 0;
            for (int j = n + 1; j < 9; j++) {
                if ( b[j] == i || abs(b[j] - i) == abs(j - n)) {
                    e = 1;
                    break;
                }
            }
            if ( e == 0) {
                b[n] = i;
                put(n - 1);
            }
        }
    }
}

int main() {
    string st;
    int n;
    for (int i = 0; i < 8; i++) {
        cin >> st;
        for (int j = 0; j < 8; j++) {
            if ( st[j] == '.' ) a[i+1][j+1] = 0;
            else a[i+1][j+1] = -1;
        }
    }
    put(8);
    cout << ans << endl;

}