#include <iostream>
#include <cmath>
#include <vector>
#include <string>
#include <set>
#define ll long long
#define N 200001

using namespace std;

int n, q;
vector<string> a(1001);
vector<vector<ll> > v( 1001, vector<ll> (1001, 0));

int main() {
    cin >> n >> q;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if ( a[i][j] == '*' ) v[i + 1][j + 1] = 1;
            v[i + 1][j + 1] += (v[i][j + 1] + v[i + 1][j] - v[i][j]); 
            // cout << v[i + 1][j + 1] << " ";
        }
    }
    while (q--) {
        int a, b, x, y;
        cin >> a >> b >> x >> y;
        cout << v[x][y] - v[x][b - 1] - v[a - 1][y] + v[a - 1][b - 1] << endl; 
    }
}

/*
4 3
.*..
*.**
**..
****
2 2 3 4
3 1 3 1
1 1 2 2
*/