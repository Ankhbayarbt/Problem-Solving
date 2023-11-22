#include <iostream>
#include <vector>
#define N 200001
#define mod 1000000007
#define ll long long

using namespace std;

int main() {
    ll n, sum;
    cin >> n;
    sum = n * (n+1) / 2;
    if ( sum % 2 == 1 ) {
        cout << 0 << endl;
        return 0;
    }
    sum /= 2;
    vector<ll> v(sum + 1, 0);
    v[0] = v[1] = 1;
    for (int i = 2; i < n; i++) {
        for (int j = sum; j >= 0; j--) {
            if ( j >= i ) {
                v[j] += v[j - i];
                v[j] = v[j] % mod;
            }
        }
    }
    cout << v[sum];
    // for (int i = 0; i <= sum; i++) {
    //     cout << v[i] << " " ;
    // }
    cout << endl;
}

/*

*/