#include <iostream>
#include <algorithm>
#include <set>
#include <map>
#define N 200001
#define ll long long

using namespace std;

int main() {
    int n;
    ll ans = 0, s = 0, a, x;
    map <ll, int> m;
    scanf("%d%lld", &n, &x);
    m[0] = 1;
    for (int i = 0; i < n; i++) {
        scanf("%lld", &a);
        s += a;
        auto it = m.find(s-x);
        if ( it != m.end() )
            ans += it->second;
        m[s]++;
    }
    printf("%lld", ans);
}

/*
5 7
2 -1 3 5 -2
*/