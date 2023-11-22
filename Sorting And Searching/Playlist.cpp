#include <iostream>
#include <map>
#include <algorithm>

#define N 200001

using namespace std;

int main() {
    int a[N], n;
    map<int, int> m;
    cin >> n;
    int l = 0, ans = 0;
    for (int r = 0; r < n; r++) {
        cin >> a[r];
        if (m.find(a[r]) == m.end()) {
            m[a[r]] = r;
        } else {
            int i = m[a[r]];
            for (; l <= i; l++) {
                m.erase(a[l]);
            }
            m[a[r]] = r;
        }
        ans = max(ans, (int)m.size());
    }
    cout << ans << endl;
    return 0;
}