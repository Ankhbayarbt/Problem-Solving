#include <iostream>
#include <cmath>

using namespace std;

void haha(int n, int a, int b) {
    if ( n == 0 ) return;
    haha ( n - 1, a, 6 - a - b);
    cout << a << " " << b << endl;
    haha ( n - 1, 6 - a - b, b);    
}
int main() {
    int n;
    cin >> n;
    cout << (1 << n) - 1 << endl;
    haha(n, 1, 3);

    
}