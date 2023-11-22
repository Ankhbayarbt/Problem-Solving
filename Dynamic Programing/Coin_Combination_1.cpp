#include <iostream>
#include <vector>
#include <algorithm>
#define ll long long

using namespace std;

int main() {
    ll n, x, a[101], b = 1000000007;
    cin >> n >> x;
    vector <int> v(x);
    for (int i = 0; i <= x; i++) 
        v[i] = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort (a, a+n);
    if ( x >= a[0] )
        v[a[0]] = 1;
    for (int i = a[0] + 1; i <= x; i++) {
        for (int j = 0; j < n; j++) {
            if ( i > a[j] ) 
                v[i] += v[i - a[j]];
            else if ( i == a[j] ) 
                v[i]++;
            else 
                break;
            v[i] = v[i] % b;
        }
    }
    cout << v[x] << endl;

    
}

/*
3 9
2 3 5
*/