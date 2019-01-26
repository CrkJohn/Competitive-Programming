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
typedef long long i64;
typedef vector<i64> vi64;
typedef vector<vi64> vvi64;
typedef pair<i64, i64> pi64;
typedef double ld;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.precision(10);
    cout << fixed;
    //in();
    //out();
		while(1){
			 int  isStk = 1 , isQ = 1 , isPq  = 1;
			 stack<int> st;
			 queue<int> q;
			 priority_queue<int> pq;
       int n;
       cin >> n;
       if(cin.eof())break;
			 forn(i,n){
					int  op, num ;
					cin >> op  >> num;
					if(op==1){
							if(isStk)st.push(num);
							if(isQ)q.push(num);
							if(isPq)pq.push(num);
					}else{
						 if(isPq){
								 if(pq.empty() || pq.top()!= num )isPq = 0; else	pq.pop();
							}
             if(isQ){
							 if(q.empty() || q.front()!=num)isQ = 0; else  q.pop();
             }
             if(isStk){
								if(st.empty() || st.top()!=num)isStk = 0;else st.pop();
             }
					}
			 }
			 cerr << isStk <<" " <<  isQ << " " << isPq << endl;
			if (isStk && !isQ && !isPq)cout << "stack" << endl;
			else if (!isStk && isQ && !isPq)cout << "queue" << endl;
			else if (!isStk && !isQ && isPq )cout << "priority queue" << endl;
			else if (!isStk && !isQ && !isPq )cout << "impossible" << endl;
			else cout << "not sure" << endl;
		}

    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
    return 0;
}
