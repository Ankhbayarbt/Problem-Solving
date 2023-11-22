#include <iostream>
#include <algorithm>
#include <set>
#include <vector>
#define N 200001

using namespace std;

void funct(int n, int a[]) {
    int b[n];
    if ( n == 1 ) {
        cout << a[1] << " ";
        return;
    }
    int j = 1;
    if ( n % 2 == 0 ) {
        for (int i = 1; i <= n; i++) {
            if ( i % 2 == 0 ) 
                cout << a[i] << " ";
            else {
                b[j] = a[i];
                j++;
            }
        }
        funct(n/2, b);
    }else {
        b[1] = a[n];
        j++;
        for (int i = 1; i < n; i++) {
            if ( i % 2 == 0 ) 
                cout << a[i] << " ";
            else {
                b[j] = a[i];
                j++;
            }
        }
        funct(n/2+1, b);
    }
}

int main() {
    int n, a[N];
    cin >> n;
    for (int i = 1; i <= n; i++) {
        a[i] = i;
    }
    funct(n, a);
}