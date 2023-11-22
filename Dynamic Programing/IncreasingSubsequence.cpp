#include <iostream>
#include <vector>
#define N 200001
#define mod 1000000007
#define ll long long

using namespace std;

int main() {
    int n, num;
    cin >> n;
    vector <int> v;
    for (int i = 0; i < n; i++) {
        cin >> num;
        auto it = lower_bound(v.begin(), v.end(), num);
        if ( it == v.end() ) v.push_back(num);
        else v[it - v.begin()] = num;
    }
    // auto it = v.begin();
    // while (it != v.end()) {
    //     cout << *it << " ";
    //     it++;
    // }
    cout << v.size() << endl;
}

/*

*/