#include <iostream>
#include <cmath>
#define ll long long
using namespace std;

int q;
ll k;

int solve(ll N){
    if(N < 9)   return (int) N+1;

    int len = 1;
    while(9 * pow(10, len-1) * len < N) {
        N -= 9 * pow(10, len-1) * len;
        len++;
    }
    string S = to_string(pow(10, len-1) + N/len);
    return (int) (S[N%len] - '0');
}

int main(){
    cin >> q;
    while ( q-- ) {
        cin >> k;
        cout << solve(k-1) << endl;
    }
}