#include <iostream>
#include <string>

using namespace std;

int main() {
    string st;
    int n, answer = 1, check = 1;
    cin >> st;
    n = st.size();
    for (int i = 0; i < n; i++) {
        if ( st[i] == st[i + 1] ) 
            check++;
        else {
            answer = max ( answer, check );
            check = 1;
        }
    }
    cout << answer << endl;
}