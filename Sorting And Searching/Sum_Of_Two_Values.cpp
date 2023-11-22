#include <iostream>
#include <set>
#include <algorithm>
#define N 200001

using namespace std;

int main() {
    multiset<int> set;
    int n, x, a[N], ans, e = 0;
    cin >> n >> x;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        set.insert(a[i]);
    }
    for (int i = 1; i <= n; i++) {
        auto it = set.find(x - a[i]);
        if (it != set.end() && *it != a[i]) {
            e = 1;
            ans = *it;
            cout << i << " ";
            break;
        }
    }
    if ( e == 1 ) {
        for (int i = 1; i <= n; i++) 
            if ( a[i] == ans ) {
                cout << i << endl;
                break;
            }
    } 
    else 
        cout << "IMPOSSIBLE" << endl;
}




/*
#include <iostream>
#include <cmath>
#include <algorithm>
#define N 200001

using namespace std;

int main() {
    int n, x, a[N], b[N], i, ans1, ans2, e = 0, m;
    cin >> n >> x;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        b[i] = a[i];
    }
    sort (a, a + n);
    i = 0; 
    m = n - 1;
    while ( m > i ) {
        if ( a[i] + a[m] > x ) m--;
        else if ( a[i] + a[m] < x ) i++;
        else {
            ans1 = a[i];
            ans2 = a[m];
            e = 1;
            break;
        }
    }
    if ( e == 1 ) {
        for (int i = 0; i < n; i++) {
            if ( b[i] == ans1 ) {
                cout << i + 1 << " ";
                break;
            }
        }
        for (int i = n - 1; i >= 0; i--) {
            if ( b[i] == ans2 ) {
                cout << i + 1 << endl;
                break;
            }
        }
    }
    else 
        cout << "IMPOSSIBLE" << endl;
}
*/