#include <iostream>
#include <set>
#include <algorithm>
#include <vector>
#define ll long long
#define f first 
#define s second


using namespace std;

int main() {
    ll n, x, m;
    cin >> n >> x;
    m = n * ( n - 1 ) / 2;
    vector <ll> v(n);
    vector <pair<ll, pair <int, int> > > sum(0);   // sumOf2Value, index, index
    pair<int, int> p1;
    pair<ll, pair <int, int> > p2;
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }    
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            p1.f = i + 1;
            p1.s = j + 1;
            p2.f = v[i] + v[j];
            p2.s = p1;
            sum.push_back(p2);
        }
    }
    sort(sum.begin(), sum.end());
    int l = 0, r = m - 1, left = 0, right = 0;
    while ( l < r ) {
        if ( sum[l].f + sum[r].f == x ) {
            left = l;
            right = r;
            break;
        }else if ( sum[l].f + sum[r].f > x ) {
            r--;
        }else {
            l++;
        }
    }
    if ( left == 0 && right == 0 ) {
        cout << "IMPOSSIBLE" << endl;
        return 0;
    }
    int num1 = sum[left].f, num2 = sum[right].f;
    while ( sum[left].f == num1 ) {
        r = right;
        while ( sum[r].f == num2 ) {
            if ( sum[left].s.f != sum[r].s.f && sum[left].s.f != sum[r].s.s &&
                 sum[left].s.s != sum[r].s.f && sum[left].s.s != sum[r].s.s ) {
                    cout << sum[left].s.f << " " << sum[left].s.s << " " << sum[r].s.f << " " << sum[r].s.s << endl;
                    return 0;
                 }
            r--;
        } 
        left++;
    }
    cout << "IMPOSSIBLE" << endl;

}