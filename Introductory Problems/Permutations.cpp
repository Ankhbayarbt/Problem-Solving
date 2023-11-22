#include <iostream>

using namespace std;

int main() {
    long long n, a;
    cin >> n;
    if ( n == 1 ) {
        cout << 1;
        return 0;
    }
    if ( n < 4 ) {
        cout << "NO SOLUTION" << endl;
        return 0;
    }
    if ( n % 2 == 0 ) {
        a = n;
        n--;
    }else a = n - 1;
    while ( n > 0 ) {
        cout << n << " ";
        n -= 2;
    } 
    while ( a > 0 ) {
        cout << a << " ";
        a -= 2;
    } 
    return 0;
}