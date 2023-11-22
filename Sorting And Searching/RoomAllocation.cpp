#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <cmath>
#define N 200001
#define f first
#define s second
#define int long long
 
using namespace std;
 
int32_t main() {
    int n, a, b;
    cin >> n;
    vector<int> ans(n);                            // hariu
    vector<pair<pair<int, int>, int> > start(n);   // start end index
    multiset<pair<int, int> > ms;                  // end roomNumber
    set<int> s;
    for (int i = 2; i <= N; i++) {
        s.insert(i);                               // Rooms
    }
    for (int i = 0; i < n; i++) {
        cin >> a >> b;
        start[i].f.f  = a;
        start[i].f.s = b;
        start[i].s = i;
    }
    sort(start.begin(), start.end());
 
    int index = 1, i = 1, j = 0, ih = 0;
    pair<int, int> p;
    p = make_pair(start[0].f.s, 1);
    ans[start[0].s] = 1;
    ms.insert(p);
    while ( i < n ) {
        if (ms.size() == 0 || start[i].f.f <= (*ms.begin()).f ) {
            auto it = s.begin();                        // roomNumber
            p = make_pair( start[i].f.s, *it);          // end, roomNumber
            ih = max(ih, p.s);                          // max roomNumber
            ms.insert(p);
            ans[start[i].s] = p.s;
            s.erase(it);                                // roomNumber 
            i++;
        }else {
            auto it = ms.begin();                       // end
            s.insert((*it).s);                          // roomNumber
            ms.erase(it);                               // end
        }
    }  
    
    
    // for (auto it = ms.begin(); it != ms.end(); it++) {
    //     cout << (*it).f << " " << (*it).s << endl;
    // }
    cout << ih << endl;
    for (int i = 0; i < n; i++) {
        cout << ans[i] << " ";
    }
    cout << endl;
    
}
 
/* 
10
1 3   
1 4     
2 2     
4 5     
4 8     
5 7     
5 8     
6 8     
8 8     
8 9  
 
10
8 8
5 8
8 9
1 4
1 3
5 7
4 8
2 2
4 5
6 8
*/