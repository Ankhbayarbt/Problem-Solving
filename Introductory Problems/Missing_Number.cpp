#include <iostream>

using namespace std;

int main() {
    long long n, sum = 0, k;
    cin >> n;
    for (int i = 1; i < n; i++) {
        cin >> k;
        sum += k;
    }
    cout << n * ( n + 1 ) / 2 - sum << endl;
}