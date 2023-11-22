#include <iostream>
#include <string>

using namespace std;

int main() {
    string st;
    int a[30] = {0}, n, count = 0;
    cin >> st;
    n = st.size();
    for (int i = 0; i < n; i++) {
        a[int(st[i]) - 64]++;
    }
    for (int i = 1; i < 27; i++ ) 
        if ( a[i] % 2 == 1 ) count++;
    if ( count > 1 ) cout << "NO SOLUTION" << endl;
    else {
        for (int i = 1; i < 27; i++ ) {
            if ( a[i] % 2 == 0 )
            for (int j = 0; j < a[i] / 2; j++) {
                cout << char(i + 64);
            }
        }
        for (int i = 1; i < 27; i++) {
            if ( a[i] % 2 == 1 ) {
                for (int j = 0; j < a[i]; j++) {
                    cout << char(i + 64);
                }
            }
        }
        for (int i = 26; i > 0; i-- ) {
            if ( a[i] % 2 == 0 )
            for (int j = 0; j < a[i] / 2; j++) {
                cout << char(i + 64);
            }
        }
    }
    cout << endl;
}