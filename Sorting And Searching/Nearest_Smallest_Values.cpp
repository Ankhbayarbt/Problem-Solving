#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
    int n, b[200001], j;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++) 
        cin >> v[i];
    for (int i = 1; i < n; i++) {
        j = i - 1;
        if ( v[i] > v[j] ) 
            b[i] = j + 1;
        else {
            while ( 1 ) {
                if ( b[j] == 0 ) {
                    b[i] = 0; 
                    break;
                }
                j = b[j] - 1;
                if ( v[i] > v[j] ) {
                    b[i] = j + 1;
                    break;
                }
            }
        }
    }
    for (int i = 0; i < n; i++) {
        cout << b[i] << " ";
    }
    cout << endl;
}

/*
8
2 5 1 4 8 3 2 5
*/