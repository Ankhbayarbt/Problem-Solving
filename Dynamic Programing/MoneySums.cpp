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
    int n, a[101], s = 0, ans = 0;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        s += a[i];
    }
    vector < vector<int> > vec(n + 1, vector<int>(s + 1, 0));
    for (int i = 1; i <= n; i++) {
        for (int j = s; j >= 1; j--) {
            if ( (j >= a[i] && vec[i - 1][j - a[i]] == 1) || ( a[i] == j )) {
                vec[i][j] = 1;
            }else {
                vec[i][j] = vec[i - 1][j];
            }
        }
    }
    for (int i = 1; i <= s; i++) {
        ans += vec[n][i];
    }
    cout << ans << endl;

    for (int i = 1; i <= s; i++) {
        if ( vec[n][i] == 1 ) cout << i << " ";
    }
    cout << endl;
    
}

