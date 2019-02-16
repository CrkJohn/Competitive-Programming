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

typedef pair<int,pair<int,int> > PIII;
int dx[]={0,0,1,-1};
int dy[]={1,-1,0,0};
int main()
{
		freopen("in.txt","r",stdin);
		out();
    int T,R,C,i,j,r,c;
    int ht[100][100];
    bool vis[100][100];
    int res;
    scanf("%d",&T);
    while (T--)
    {
        priority_queue<PIII,vector<PIII>,greater<PIII> > Q;
        scanf("%d %d",&R,&C);
        res=0;
        for (i=0; i<R; i++)
            for (j=0; j<C; j++)
            {
                scanf("%d",ht[i]+j);
                vis[i][j]=false;
                if (i==0||j==0||i+1==R||j+1==C)
                    Q.push(PIII(ht[i][j],make_pair(i,j)));
            }
        while (!Q.empty())
        {
            PIII P=Q.top();
            while (!Q.empty())
            {
                PIII P2=Q.top();
                if (P2.first>P.first) break;
                Q.pop();
                if (vis[P2.second.first][P2.second.second]++)
                    continue;
                res+=P.first-P2.first;
                for (i=0; i<4; i++)
                {
                    r=P2.second.first+dx[i];
                    c=P2.second.second+dy[i];
                    if (r>=0&&r<R&&c>=0&&c<C)
                        Q.push(PIII(ht[r][c],make_pair(r,c)));
                }
            }
        }
        //		fprintf(stderr,"%d %d\n",R,C);
        printf("%d\n",res);
    }
}
