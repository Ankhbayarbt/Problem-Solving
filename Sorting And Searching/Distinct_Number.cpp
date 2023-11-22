#include <iostream>
#include <algorithm>
 
using namespace std;
 
int main() {
    long long n, a[200001], count = 1;
    cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i];
    sort (a, a + n);
    for (int i = 1; i < n; i++ ) {
        if ( a[i] != a[i - 1] ) {
            count ++;
        }
    }
    cout << count << endl;
}
