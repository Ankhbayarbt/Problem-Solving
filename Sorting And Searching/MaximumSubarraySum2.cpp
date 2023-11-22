#include <iostream>
#include <algorithm>
#include <set>
#include <map>
#define N 200001
#define ll long long
using namespace std;

int main(){
	int n, a, b, ind = 0;
	cin >> n >> a >> b;
	long long s = 0, submax = 0, l = a, arrmax;
	int arr[n];
	for(int i = 0;i < n;i++){
		cin >> arr[i];
		if(i < a){
			s += arr[i];
		}
	}
	arrmax = s;
	if(b == a) {
		for(int i = a;i < n;i++){
			s += arr[i];
			s-= arr[i-a];
			if(s > arrmax) arrmax = s;
		}
		cout << arrmax;
		return 0;
	}
	for(int i = a; i < n; i++){
		// cout << s << " " << submax << " " << l << " " << ind << endl;
        arrmax = max(arrmax, s);
		if ( l == b ) {
            submax = submax - arr[ind];
            s = s - arr[ind];
            ind++;
            l--;
            if ( submax < 0 ) {
                s = s - submax;
                submax = 0;
                ind = i - a;
                l = a;
            }
            s = s + arr[i];
            l++;
            submax = submax + arr[i - a];
            if ( submax < 0 ) {
                s = s - submax;
                submax = 0;
                ind = i - a + 1;
                l = a;
            }
        }else {
            s = s + arr[i];
            submax = submax + arr[i - a];
            if ( submax < 0 ) {
                s = s - submax;
                submax = 0;
                ind = i - a + 1;
                l = a;
            }else {
                l++;
            }
        }

        while ( arr[ind] <= 0 && l > a) {
            s = s - arr[ind];
            arrmax = max(arrmax, s);
            submax = submax - arr[ind];
            ind++;
            l--;
        }
	} 
    cout << endl;
    while ( l > a ) {
        // cout << s << " " << submax << " " << l << " " << ind << endl;
        arrmax = max(arrmax, s);
        s = s - arr[ind];
        submax = submax - arr[ind];
        ind++;
        l--;
    }
	// cout << arrmax;
    // cout << s << " " << submax << " " << l << " " << ind << endl;
    arrmax = max(arrmax, s);
    cout << arrmax << endl;
}



/*
12 2 4
-1 3 -2 5 3 1 -5 2 2 -2 5 7
*/