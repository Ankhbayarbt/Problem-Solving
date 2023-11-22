#include <iostream>
#include <string>

using namespace std;

int main() {
    string st[1000];
    int n, a[1001][1001], mod = 1000000007;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> st[i];
    }
    for (int i = 0; i < n; i++) 
        for (int j = 0; j < n; j++) 
            a[i][j] = 0;
    int s1 = 1, s2 = 1;
    for (int i = 0; i < n; i++) {
        if ( st[0][i] == '*' ) 
            s1 = 0;
        if ( st[i][0] == '*' )
            s2 = 0;
        a[0][i] = s1;
        a[i][0] = s2;
    }
    for (int i = 1; i < n; i++ ) {
        for (int j = 1; j < n; j++) {
            if ( st[i][j] == '*' ) 
                a[i][j] = 0;
            else 
                a[i][j] = a[i-1][j] + a[i][j-1];
            a[i][j] = a[i][j] % mod;
        }
    }
    cout << a[n-1][n-1] << endl;
    /*for (int i = 0; i < n; i++ ) {
        for (int j = 0; j < n; j++) {
            cout << a[i][j] << " ";
        }
        cout << endl;
    }*/
    

}

/*
4
....
.*..
...*
*...
*/