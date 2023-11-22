#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#define N 200001
 
using namespace std;
 
struct range {
    int a, b, index;
    bool operator < (const range &other) const {
        if ( a == other.a ) 
            return b > other.b;
        return a < other.a; 
    }
};
 
int main() {
    long long n, b[N], m;
    cin >> n;
    vector <range> v(n);
    vector <int> v1(n), v2(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i].a >> v[i].b;
        v[i].index = i;
    }
    sort (v.begin(), v.end());
    m = 0;
    for (int i = 0; i < n; i++ ) {
        if ( m >= v[i].b ) 
            v1[v[i].index]++;
        if ( v[i].b > m ) 
            m = v[i].b;
    }
 
    m = 1e10;
    for (int i = n - 1; i >= 0; i-- ) {
        if ( m <= v[i].b ) 
            v2[v[i].index]++;
        if ( v[i].b < m ) 
            m = v[i].b;
    }
    for (int i = 0; i < n; i++) {
        cout << v2[i] << " ";
    }
    cout << endl;
    for (int i = 0; i < n; i++) {
        cout << v1[i] << " ";
    }
    cout << endl;
    
}