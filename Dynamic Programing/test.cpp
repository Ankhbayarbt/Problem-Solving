#include <iostream>
#include <cmath>
#include <algorithm>
int ih(int a, int b) {
    if ( a > b) return a;
    else return b;
}

using namespace std;
int main() {
    string ug;
    cin >> ug;
    sort( ug.begin(), ug.end());
    cout << ug << endl;
    return 0;
}