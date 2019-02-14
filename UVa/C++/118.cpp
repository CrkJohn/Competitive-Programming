#include <bits/stdc++.h>

#define mp make_pair
#define mt make_tuple
#define fi first
#define se second
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
#define for1(i, n) for (int i = 1; i <= (int)(n); ++i)
#define ford(i, n) for (int i = (int)(n) - 1; i >= 0; --i)
#define fore(i, a, b) for (int i = (int)(a); i <= (int)(b); ++i)
#define in() freopen("in.txt","r",stdin)
#define out() freopen("out.txt","w",stdout)
#define err() freopen("err.txt","w",stderr)
#define si(a) ((int)a.size())

using namespace std;

typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<pii> vpi;
typedef vector<vi> vvi;
typedef long long ll;
typedef vector<ll> vll;
typedef vector<vll> vvll;
typedef pair<ll,ll> pi64;
typedef double ld;

char directions[] = {'N', 'E', 'S', 'W'};
int xChange[] = {0, 1, 0, -1};
int yChange[] = {1, 0, -1, 0};


int main(){
    int xSize, ySize;
    cin >> xSize >> ySize;
    vector<vector<bool> > scent(ySize + 1, vector<bool> (xSize + 1, false));
    int x, y;
    char startDirection;
    string orders;
    while (cin >> x >> y >> startDirection >> orders){
        int direction;
        for (int i = 0; i < 4; ++i)
            if (startDirection == directions[i])
                direction = i;
        bool died = false;
        for (int i = 0; i < orders.size(); ++i){
            if (orders[i] == 'R')
                direction = (direction + 1) % 4;
            else if (orders[i] == 'L')
                direction = (direction + 3) % 4;
            else{
                if (x + xChange[direction] == -1 || x + xChange[direction] == xSize + 1 || y + yChange[direction] == -1 || y + yChange[direction] == ySize + 1)                {
                    if (!scent[y][x]){
                        scent[y][x] = died = true;
                        break;
                    }
                }
                else{
                    x += xChange[direction];
                    y += yChange[direction];
                }
            }
				}
        cout << x << ' ' << y << ' ' << directions[direction] << (died ? " LOST" : "") << '\n';
    }
}
