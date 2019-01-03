#include <bits/stdc++.h>
#define loop(i,a,b) for(i=a;i<b;i++)
#define rev(i,a,b)  for(i=a;i>=b;i--)
#define itloop(i,a) for(i=a.begin();i!=a.end();i++)
#define READ(file)  freopen(file, "r", stdin)
#define WRITE(file) freopen(file, "w", stdout)
#define pb(a)    push_back(a)
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
int gap,len,pos[SZ],tmp[SZ],sa[SZ],lcp[SZ];

bool gapcmp(int i, int j){
	if(pos[i]!=pos[j]) return pos[i]<pos[j];
  i+=gap, j+=gap;
  return (i<len && j<len)? pos[i]<pos[j] : i>j;
}

void suffixArray(char* t,int* sa, int tsz){
	int i,j,k=0;
	if(tsz<=1){ sa[0]=lcp[0]=0; return; }
	loop(i,0,tsz) sa[i]=i,pos[i]=t[i];
	len=tsz, gap=1, tmp[tsz-1]=tmp[0]=1;
	while(tmp[tsz-1]<tsz){
		sort(sa,sa+tsz,gapcmp);
		loop(i,1,tsz) tmp[i]=tmp[i-1]+ gapcmp(sa[i-1],sa[i]);
		loop(i,0,tsz) pos[sa[i]]=tmp[i];
		gap<<=1;
	}
	loop(i,0,tsz) if (pos[i]!=tsz){
		j=sa[pos[i]];
		while(t[i+k] == t[j+k])	++k;
		lcp[pos[i]-1] = k;
		if(k)--k;
	}
}

int main(){
    int cases,i;
    scanf("%d",&cases);
    getchar();
    while (cases--){
        char str[5100];
        gets(str);
        //int gap,len,pos[SZ],tmp[SZ],sa[SZ],lcp[SZ];
        lcp[strlen(str)];sa[strlen(str)];tmp[strlen(str)];
        memset(pos,0,sizeof pos); memset (tmp,0,sizeof tmp);memset(sa,0, sizeof sa);memset(lcp,0,sizeof lcp);
        suffixArray(str,sa,strlen(str));
        int ma = 0;
        loop(i,0,strlen(str)){
            ma= max(lcp[i],ma);
        }
        printf("%d\n",ma);
    }
    return 0;
}

