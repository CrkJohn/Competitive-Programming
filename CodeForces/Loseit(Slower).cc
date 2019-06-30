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


using namespace std;

typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<pii> vpi;
typedef vector<vi> vvi;
typedef long long i64;
typedef vector<i64> vi64;
typedef vector<vi64> vvi64;
typedef pair<i64, i64> pi64;
typedef double ld;

set<string> st;
int n,k;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.precision(10);
    cout << fixed;
#ifdef LOCAL
    in();
#endif

    int n; 
    cin >> n;
    vi numbers(n);
    queue<int> fours;
    int vis[n];
    memset(vis,0,sizeof vis);
    //vi fours;
    int count1 = 0 , count2 = 0 , count3 = 0 , count4 = 0 , count5 = 0 , count6 = 0;
    forn(i,n){
        cin >> numbers[i];
        if(numbers[i]==4)fours.push(i);
        if(numbers[i]==8)count2++;
        if(numbers[i]==15)count3++;
        if(numbers[i]==16)count4++;
        if(numbers[i]==23)count5++;
        if(numbers[i]==42)count6++; 
	
    }
    cout << " HOla " << endl;
    int cnt = 0;
    if(n<6 || fours.empty()){
        cout << n << endl;
    }else{
        int goodArray[] = {8,15,16,23,42};
        while(!fours.empty() && count2>0 && count3>0 &&  count4>0 && count5>0 &&  count6 >0){
            int iGood = 0;
	    cout << " : ) " << endl;
            int index = fours.front();fours.pop();
            vi tempVis;
            fore(i,index,n-1){
                if(goodArray[iGood] == numbers[i] && vis[i]!=1){
                    iGood++;
                    tempVis.pb(i);
                }
                if(iGood==5)break;
            }
            if(iGood == 5){
                for(int indx : tempVis){
                    vis[indx] = 1;
                }
                count2--;
                count3--;
                count4--;
                count5--;
                count6--;     
                cnt+=6;
            }else{
                break;
            }
        
        }
        
        cout << n-cnt << endl;
    }

    
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
    return 0;

} 


