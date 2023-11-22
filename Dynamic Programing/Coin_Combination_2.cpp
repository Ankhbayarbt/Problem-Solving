#include <iostream>
#include <vector>
#include <algorithm>
#define ll long long

using namespace std;

int main() {
    ll n, x, a[101], b = 1000000007;
    cin >> n >> x;
    vector <int> v(x);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int i = 0; i <= x; i++) 
        v[i] = 0;
    sort (a, a+n);
    v[0] = 1;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= x; j++ ) {
            if ( a[i] <= j ) {
                v[j] += v[j - a[i]];
            }
            v[j] %= b;
        }
    }
    // for (int i = 0; i <= x; i++) {
    //     cout << v[i] << " ";
    // }
    cout << v[x];
    cout << endl;

    
}

/*
3 9
2 3 5
*/