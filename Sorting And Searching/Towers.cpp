#include <iostream> 
#include <set>
#include <algorithm>

using namespace std;

int main() {
    int n, a, ans = 1;
    multiset<int> s;
    cin >> n >> a;
    s.insert(a);
    for (int i = 0; i < n - 1; i++) {
        cin >> a;
        auto it = s.upper_bound(a);
        if ( it == s.end() ) {
            ans ++;
        }
        else {
            s.erase(it);
        }
        s.insert(a);
    }
    cout << ans << endl;

}