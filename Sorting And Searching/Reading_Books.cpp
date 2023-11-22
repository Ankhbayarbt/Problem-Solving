#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <string>
#define N 200001
#define ll long long

using namespace std;

int main() {
    ll n, a[N], s = 0, ih = 0;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        s += a[i];
        if ( ih < a[i] ) ih = a[i];
    }
    if ( ih > s - ih ) cout << 2 * ih << endl;
    else cout << s << endl;

}