#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#define ll long long
#define f first 
#define s second
#define N 200001

using namespace std;

int main() {
    int a, b, l, r;
    cin >> a >> b;
    vector <vector<int> > v(a + 1, vector<int>(b + 1, 99999));
    for (int i = 1; i <= a; i++) v[i][1] = i - 1;
    for (int i = 1; i <= b; i++) v[1][i] = i - 1;
    for (int i = 1; i <= min(a, b); i++) {
        v[i][i] = 0;
    }

    for (int i = 2; i <= a; i++) {
        for (int j = 2; j <= b; j++) {
            l = 1;
            r = j - 1;
            while ( r >= l ) {
                v[i][j] = min(v[i][j], v[i][l] + v[i][r] + 1);
                r--;
                l++;
            }
            l = 1; 
            r = i - 1;
            while ( r >= l ) {
                v[i][j] = min(v[i][j], v[l][j] + v[r][j] + 1);
                l++;
                r--;
            } 
        }
    }
    cout << v[a][b] << endl;

    // for (int i = 1; i <= a; i++) {
    //     for (int j = 1; j <= b; j++) {
    //         cout << v[i][j] << " ";
    //     }
    //     cout << endl;
    // }
    
    
}

