#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#define N 200001

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m, ans = 1;
    cin >> n >> m;
    vector<int> a(n+1);
    vector<int> b(n+1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        b[a[i]] = i;
    }
    for (int i = 1; i < n; i++) 
        ans += b[i] > b[i + 1];
    int l, r;
    set<pair<int, int>> s;
    while (m--) {
        cin >> l >> r;
        if ( a[l] + 1 <= n ) s.insert({a[l], a[l] + 1});
        if ( a[l] - 1 >= 1) s.insert({a[l] - 1, a[l]});
        if ( a[r] + 1 <= n ) s.insert({a[r], a[r] + 1});
        if ( a[r] - 1 >= 1) s.insert({a[r] - 1, a[r]});
        for (pair<int, int> i: s) {
            ans -= b[i.first] > b[i.second]; 
        }
        swap(a[l], a[r]);
        b[a[l]] = l;
        b[a[r]] = r;
        for (pair<int, int> i: s) {
            ans += b[i.first] > b[i.second];
        }
        cout << ans << endl;
        s.clear();
    }
    return 0;
}