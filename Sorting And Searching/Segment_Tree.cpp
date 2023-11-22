#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <string>
#define N 200001
#define ll long long

using namespace std;

int n;
int A[4*N], S[4*N];  

void update(int id, int  L, int  R, int  l, int r, int x) {
    if ( L == l && r == R ) {
        A[id] += x;
        return;
    }
    int M = L + (R - L) / 2;
    if ( r <= M ) update(2*id+1, L, M, l, r, x);
    else if ( M+1 <= l ) update(2*id+2, M+1, R, l, r, x);
    else {
        update(2*id+1, L, M, l, M, x);
        update(2*id+2, M+1, R, M+1, r, x);
    }
    S[id] += (r - l + 1) * x;
}

int query(int id, int L, int R, int l, int r) {
    if ( L == l && r == R ) {
        return S[id] + A[id] * (R - L + 1);
    }
    int M = L + (R - L) / 2;
    int k = (r - l + 1) * A[id];
    if ( r <= M ) return k + query(2*id+1, L, M, l, r);
    else if ( M+1 <= l ) return k + query(2*id+2, M+1, R, l, r);
    else return k + query(2*id+1, L, M, l, M) + query(2*id+2, M+1, R, M+1, r);
}


int main() {

}