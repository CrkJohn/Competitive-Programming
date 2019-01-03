#include <bits/stdc++.h>
#define loop(i,a,b) for(i=a;i<b;i++)
#define rev(i,a,b)  for(i=a;i>=b;i--)
#define itloop(i,a) for(i=a.begin();i!=a.end();i++)
#define ms(a,c)    memset(a,c,sizeof(a))
#define READ(file)  freopen(file, "r", stdin)
#define WRITE(file) freopen(file, "w", stdout)
#define append(a)    push_back(a)
#define pf(a)    push_front(a)
#define tup(a,b) make_pair(a,b)
#define popb()   pop_back()
#define popf()   pop_front()
#define X        first
#define Y        second
#define LIM      100
#define INF      1000000010
#define SZ       1000005
#define upA(a)   a*a
#define base     10000
#define EPS      1e-9
#define LSOne(i) (i&(-i))
#define len(a)   a.size()

using namespace std;
typedef long long large;
typedef pair<int,int> ii;
typedef deque<int> di;
typedef deque<ii> dii;
typedef di::iterator dit;
typedef vector<int> vi;
typedef set<int> si;
typedef set<large> sl;
typedef complex<double> im;
typedef vector<char*> vs;
typedef vector<large> bigint;

vi lis_log(vi t){ // n log n
  vi b, bi, lis, prev(t.size()),lisAt(t.size());
  int i;
  loop(i,0,len(t)){
    int j = lower_bound(b.begin(),b.end(),t[i])-b.begin();
    if(j==len(b)) bi.append(i), b.append(t[i]);
    else b[j]=t[i], bi[j] = i;
    prev[i] = j==0?-1:bi[j-1];
    // optional calculus for length of a lis ending at i:
    lisAt[i] = j+1;
  }
  for(int i=bi[len(b)-1]; i!=-1; i=prev[i]){
      // optionally append(i) to get the indices
      lis.append(t[i]);
  }
  reverse(lis.begin(), lis.end());
  return lisAt;
}


int main(){
    int n,N,i;
    vi lis;
    while ((scanf("%d",&n))==1){
        lis.clear();
        loop(i,0,n){
            scanf("%d",&N);lis.append(N);
        }
        vi LIS = lis_log(lis);
        reverse(lis.begin(),lis.end());
        vi LDS = lis_log(lis);
        reverse(LDS.begin(),LDS.end());

        /*loop(i,0,n)printf("%d ",LIS[i]);
        puts("");
        loop(i,0,n)printf("%d ",LDS[i]);
        */int maxi = 0;
        loop(i,0,n){
            maxi = max(maxi,min(LIS[i],LDS[i])*2-1);
        }
        printf("%d\n",maxi);
    }
    return 0;
}
