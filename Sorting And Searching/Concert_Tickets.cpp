#include <set>
#include <iostream>

using namespace std;

int main() {
    int n, m;
    multiset<int> s;
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        int a; cin >> a;
        s.insert(-a);
    }
    while (m--) {
        int a; cin >> a;
        auto it = s.lower_bound(-a);
        if (it == s.end()) {
            cout << -1 << endl;
        } else {
            cout << -1 *(*it) << endl;
            s.erase(it);
        }
    }
    return 0;
}