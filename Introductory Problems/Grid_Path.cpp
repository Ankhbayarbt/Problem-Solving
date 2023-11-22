#include <iostream>
#include <cmath>

using namespace std;

int a[9][9], ans = 0;
string st;

void countPaths(int x, int y, int pos) {
    if (a[x][y] == 0 ) return;
    if ( pos == 48 ) {
        ans += ( x == 7 && y == 1 );
        return;
    }
    if ( x == 7 && y == 1 ) {
        return;
    }

    int xx = a[x][y + 1] + a[x][y - 1];
    int yy = a[x + 1][y] + a[x - 1][y];

    if (xx * yy == 0 && xx + yy == 2) {
        return;
    }

    a[x][y] = 0;
    if ( st[pos] == '?' ) {
        countPaths(x, y+1, pos+1);
        countPaths(x, y-1, pos+1);
        countPaths(x+1, y, pos+1);
        countPaths(x-1, y, pos+1);
    }
    else if ( st[pos] == 'R' ) 
        countPaths(x, y+1, pos+1);
    else if ( st[pos] == 'L' ) 
        countPaths(x, y-1, pos+1);
    else if ( st[pos] == 'U' ) 
        countPaths(x-1, y, pos+1);
    else if ( st[pos] == 'D' ) 
        countPaths(x+1, y, pos+1);
    a[x][y] = 1;
}

int main() {

    for (int i = 1; i <= 7; i++) {
        for (int j = 1; j <= 7; j++) {
            a[i][j] = 1;
        }
    }

    cin >> st;
    countPaths(1, 1, 0);

    cout << ans << endl;
}








/*#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

#define isValid(a, b, c) (a >= b && a < c ? 1 : 0)
typedef long long ll;

int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};
int numberOfPaths = 0;

#define RIGHT 0
#define LEFT 1
#define DOWN 2
#define UP 3

string str;

int vis[7][7];

int countPaths(int x, int y, int pos) {
    if ( pos == (int)str.length() ) 
        return ( x == 6 && y == 0 );
    if ( x == 6 && y == 0 ) 
        return 0;
    if ( vis[x][y] == 1) 
        return 0;
    vector<bool> visited(4, -1);
    for (int k = 0; k < 4; k++ ) {
        if ( isValid(x + dx[k], 0, 7) && isValid(y + dy[k], 0, 7) ) 
            visited[k] = vis[x + dx[k]][y + dy[k]];
    }
    if ( !visited[DOWN] && !visited[UP] && visited[RIGHT] && visited[LEFT] )
        return 0;
    if ( visited[DOWN] && visited[UP] && !visited[RIGHT] && !visited[LEFT] )
        return 0;
    if ( isValid(x-1, 0, 7) && isValid(y+1, 0, 7) && vis[x-1][y+1] == 1)
        if (!visited[RIGHT] && !visited[UP] ) 
            return 0;
    
    if ( isValid(x+1, 0, 7) && isValid(y+1, 0, 7) && vis[x+1][y+1] == 1)
        if (!visited[RIGHT] && !visited[DOWN] ) 
            return 0;

    if ( isValid(x-1, 0, 7) && isValid(y-1, 0, 7) && vis[x-1][y-1] == 1)
        if (!visited[UP] && !visited[LEFT] ) 
            return 0;

    if ( isValid(x+1, 0, 7) && isValid(y-1, 0, 7) && vis[x+1][y-1] == 1)
        if (!visited[DOWN] && !visited[LEFT] ) 
            return 0;

    vis[x][y] = 1;
    if ( str[pos] == '?' ) {
        for (int k = 0; k < 4; k++) 
            if ( isValid(x+dx[k], 0, 7 ) && isValid(y+dy[k], 0, 7) ) 
                numberOfPaths += countPaths(x+dx[k], y+dy[k], pos + 1);
    }
    else if ( str[pos] == 'R' && y < 6) 
        numberOfPaths += countPaths(x, y+1, pos + 1);
    else if ( str[pos] == 'L' && y > 0 )
        numberOfPaths += countPaths(x, y-1, pos + 1);
    else if ( str[pos] == 'U' && x > 0)
        numberOfPaths += countPaths(x-1, y, pos + 1);
    else if ( str[pos] == 'D' && x < 6) 
        numberOfPaths += countPaths(x+1, y, pos + 1);
    vis[x][y] = 0;
    return numberOfPaths;
}

int main() {
    cin >> str;
    cout << countPaths(0, 0, 0) << endl;   
}
*/