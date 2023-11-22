#include <iostream>
#include <set>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    long long x, n, pos, ih, baga, k, i;
    cin >> x >> n;
    multiset <long long> ms;
    set <long long> s;
    set <long long> sm;
    ms.insert(-x);
    s.insert(0);
    s.insert(x);
    sm.insert(0);
    sm.insert(-x);
    
    for (i = 0; i < n; i++) {
        cin >> pos;
        s.insert(pos);
        sm.insert(-pos);
        baga = abs(*(sm.upper_bound(-pos)));
        ih = *(s.upper_bound(pos));
        ms.erase(ms.find(baga - ih));
        ms.insert(pos - ih);
        ms.insert(baga - pos);
        cout << abs(*ms.begin()) << " ";
   }
   cout << endl;
   
   return 0;
    
    
    
}