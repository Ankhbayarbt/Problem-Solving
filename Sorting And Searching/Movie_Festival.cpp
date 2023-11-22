#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

int main() {
    int n, a, b, end, ans = 1;
    cin >> n;
    vector<pair <int, int> > v;
    for (int i = 0; i < n; i++ ) {
        cin >> a >> b;
        v.push_back(make_pair(b, a));
    }
    sort(v.begin(), v.end());
    end = v[0].first;
    for (int i = 1; i < n; i++) {
        if ( v[i].second >= end ) {
            end = v[i].first;
            ans++;
        }
    }
    cout << ans << endl; 

    
}
/*
3
5 3
8 5
9 4
*/