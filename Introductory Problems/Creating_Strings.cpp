#include <iostream>
#include <string>

using namespace std;

int main() {
    string st;
    char c;
    long long n, erembe, a = 1, count = 1, e = 1, urjver = 2, ans = 0;
    cin >> st;
    n = st.size();
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if ( st[i] > st[j] ) {
                c = st[j];
                st[j] = st[i];
                st[i] = c;
            }
        }
    }
    for (int i = 1; i <= n; i++) a = a * i;
    for (int i = 1; i < n; i++) {
        if ( st[i] != st[i-1] ) {
            a = a / count;
            count = 1;
            urjver = 2;
        }else {
            count = count * urjver;
            urjver ++;
        }
    }
    a = a / count;

    cout << a << endl;
    while ( e > 0 ) {
        cout << st << endl;
        e = 0;
        for (int j = n - 2; j >= 0; j--) {
            for (int i = n - 1; i > j; i--) {   
                if ( st[i] > st[j] ) {
                    erembe = j;
                    c = st[i];
                    st[i] = st[j];
                    st[j] = c;
                    e = 1;
                    break;
                }
            }
            if ( e == 1 ) break;
        }
        for (int i = erembe + 1; i < n - 1; i++) {
            for (int j = i + 1; j < n; j++) {
                if ( st[i] > st[j] ) {
                    c = st[j];
                    st[j] = st[i];
                    st[i] = c;
                }
            }
        }
    } 
}