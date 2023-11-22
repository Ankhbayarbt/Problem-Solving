#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    long long a, d, time = 0, n, ans = 0;
    cin >> n;
    vector <pair<int, int> > v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i].first >> v[i].second;
    }
    sort (v.begin(), v.end());
    for (int i = 0; i < n; i++) {
        time += v[i].first;
        ans += v[i].second - time;
    }
    cout << ans << endl;
}