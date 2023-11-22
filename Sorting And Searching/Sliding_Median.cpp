#include <iostream>
#include <set>
#include <algorithm>
#define N 200001

using namespace std;

int main() {
    int n, k, median, a[N], b[N];
    cin >> n >> k;
    multiset<int> baga;
    multiset<int> ih;
    for (int i = 0; i < n; i++) 
        cin >> a[i];
    for (int i = 0; i < k; i++) 
        b[i] = a[i];
    sort (b, b + k);
    if ( k == 2 ) {
        for (int i = 0; i < n - 1; i++) {
            cout << min(a[i], a[i + 1]) << " ";
        }
        cout << endl;
        return 0;
    }
    for (int i = 0; i < (k-1)/2; i++) 
        baga.insert(-b[i]);                // baga set ruu element hiih
    median = b[(k-1)/2];                      // goliin element 
    for (int i = (k-1)/2 + 1; i < k; i++) 
        ih.insert(b[i]);                  // ih set ruu element hiih
    
    int num = 0;
    while ( num < n - k) {
        cout << median << " ";

        
        if ( a[num] == median && a[num + k] > median ) {
            ih.insert(a[num + k]);
            median = *ih.begin();
            if ( k < 10 ) {
                for (auto it = ih.begin(); it != ih.end(); it++) {
                    if ( median == *it ) {
                        ih.erase(it);
                        break;
                    } 
                }
            }else {
                ih.erase(median);
            }
        }else if ( a[num] == median && a[num + k] < median ) {
            baga.insert(-a[num + k]);
            median = -(*baga.begin());
            baga.erase(-median);
        }else if ( a[num] > median && a[num + k] >= median ) {
            ih.insert(a[num + k]);
            if ( k < 10 ) {
                for (auto it = ih.begin(); it != ih.end(); it++) {
                    if ( a[num] == *it ) {
                        ih.erase(it);
                        break;
                    } 
                }
            }else {
                ih.erase(a[num]);
            }
        }else if ( a[num] > median && a[num + k] < median ) {
            ih.insert(median);
            ih.erase(a[num]);
            baga.insert(-a[num + k]);
            median = -(*baga.begin());
            baga.erase(-median);
        }else if ( a[num] < median && a[num + k] <= median ) {
            baga.insert( -a[num + k]);
            baga.erase(-a[num]);
        }else if ( a[num] < median && a[num + k] > median ) {
            baga.insert(-median);
            baga.erase(-a[num]);
            ih.insert(a[num + k]);
            median = *ih.begin();
            ih.erase(median);
        }
        num++;
    }
    cout << median << endl;
}

/*
10 5
4 6 10 4 3 8 8 10 8 9
*/