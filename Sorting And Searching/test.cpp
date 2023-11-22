#include <iostream>
#include <set>

using namespace std; 

int main() {
    int a;
    multiset<int> s;
    for (int i = 0; i < 5; i++) {
        cin >> a;
        s.insert(a);
    }
    s.erase(4);
    for (auto it = s.begin(); it != s.end(); it++) {
        cout << *it << " ";
    }
}