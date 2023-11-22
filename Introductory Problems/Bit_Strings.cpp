#include <iostream>

using namespace std;

int main() {
    long long n, modul = 1000000007, s = 1;
    cin >> n;
    for (int i = 0; i < n; i++) {
        s = s * 2;
        s = s % modul;
    }
    cout << s << endl;
}