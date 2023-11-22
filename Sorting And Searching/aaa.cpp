#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <string>
#include <map>
#define N 200001
#define ll long long

using namespace std;

int main() {
    map <ll, ll> m;
    m[3] = 33;
    m[4] = 44;
    m[2] = 22;
    m[1] = 11;
    auto it = m.begin();
    while (it != m.end()) {
        cout << it->first << " " << it->second << endl;
        it++;
    }
}