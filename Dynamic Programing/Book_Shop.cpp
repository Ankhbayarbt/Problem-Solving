#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int main() {
    int n, x, a[200001];
    cin >> n >> x;
    vector<int> pages(n), price(n);
    for (int i = 0; i < n; i++) cin >> price[i];
    for (int i = 0; i < n; i++) cin >> pages[i];

    for (int j = 0; j < n; j++) {
        for (int i = x; i >= price[j]; i--) {
            a[i] = max(a[i], a[i - price[j]] + pages[j]);
        }
    }
    // for (int i = 0; i <= x; i++) {
    //     cout << a[i] << " ";
    // }
    cout << a[x];
    cout << endl;
}

/*
10 10
1 2 10 6 5 1 7 4 10 4
6 3 8  1 7 3 8 6 5  6

10 10
1 1 2 4 4 5 6 7 10 10 
3 6 3 6 6 7 1 8 5  8 

4 10
4 8 5 3
5 12 8 1
*/