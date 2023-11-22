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
    string a, b;
    cin >> a >> b;
    int n = a.size(), m = b.size();
    int arr[n + 1][m + 1];

    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= m; j++) {
            arr[i][j] = 0;
        }
    }
    for (int i = 0; i <= n; i++) {
        arr[i][0] = i;
    }
    for (int i = 0; i <= m; i++) {
        arr[0][i] = i;
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            arr[i][j] = min( min(arr[i - 1][j], arr[i][j - 1]), arr[i - 1][j - 1] ) + 1;
            if ( a[i - 1] == b[j - 1] ) arr[i][j] = min(arr[i][j], arr[i - 1][j - 1] );
        }
    }
    cout << arr[n][m] << endl;


    // for (int i = 0; i <= n; i++) {
    //     for (int j = 0; j <= m; j++) {
    //         cout << arr[i][j] << " ";
    //     }
    //     cout << endl;
    // }
    
}

