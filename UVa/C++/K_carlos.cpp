#include <bits/stdc++.h>
#define loop(i,a,b) for(int i=a; i<b; i++)
#define rev(i,a,b) for(int i=a; i>=b; i--)
#define iter(x,a,type) for(type::iterator x=a.begin(); x!=a.end(); ++x)
#define setmem(m,x) memset(m,x,sizeof(m))
#define len(a) ((int) a.size())
#define append(x) push_back(x)
#define x first
#define y second
#define endl "\n" // speedup: avoid flushing on every print

using namespace std;
typedef long long large;
typedef pair<int,int> ii;
typedef vector<int> vi;

ostream& operator <<(ostream& o, ii a){
    o<<"("<<a.x<<","<<a.y<<")";
    return o;
}

template <typename T>
ostream& operator <<(ostream& o, vector<T> a){
    iter(x,a,typename vector<T>) o << (x==a.begin()? "" : " ") << *x;
    return o;
}

// --------------- Solution --------------------

const int inf=1e9;
char inp[100005];

struct team{
    string name;
    int points, goals_diff, goals, goals_vis;
    int id, place;
};

bool my_cmp_id(team a, team b){ return a.id<b.id; }
bool my_cmp_place(team a, team b){ return a.place<b.place; }
bool my_cmp_score(team a, team b){ // a better than b
    if(a.points > b.points) return 1;
    if(a.points < b.points) return 0;
    if(a.goals_diff > b.goals_diff) return 1;
    if(a.goals_diff < b.goals_diff) return 0;
    if(a.goals > b.goals) return 1;
    if(a.goals < b.goals) return 0;
    if(a.goals_vis > b.goals_vis) return 1;
    if(a.goals_vis < b.goals_vis) return 0;
    return strcmp(a.name.c_str(), b.name.c_str())==1;
}

int main(){
    freopen("K.txt","r",stdin);
    int m;
    while(scanf("%d",&m)==1){
        vector<team> v;
        vector<ii> hist;
        map<string,int> id;
        int n=0;
        while(m--){
            scanf(" %[^\n] ",inp);
            int k1 = string(inp).find(" vs. ");
            int k0=k1;
            while(inp[k0-1]==' ') --k0;
            while(isdigit(inp[k0-1])) --k0;
            int na; sscanf(inp+k0, "%d", &na);
            while(inp[k0-1]==' ') --k0;
            inp[k0]=0;
            string sa = inp;
            int nb; sscanf(inp+k1+4, "%d", &nb);
            int k2=k1+4;
            while(inp[k2]==' ') k2++;
            while(isdigit(inp[k2])) k2++;
            while(inp[k2]==' ') k2++;
            string sb = inp+k2;
            if(id.count(sa)==0){
                team ta={sa, 0, 0, 0, 0, n, 0};
                v.append(ta);
                id[sa] = n++;
            }
            if(id.count(sb)==0){
                team tb={sb, 0, 0, 0, 0, n, 0};
                v.append(tb);
                id[sb] = n++;
            }
            int a = id[sa];
            int b = id[sb];
            if(na>nb) hist.append(ii(a,b));
            if(na<nb) hist.append(ii(b,a));
            if(na>nb) v[a].points+=3;
            if(na<nb) v[b].points+=3;
            if(na==nb) v[a].points+=1, v[b].points+=1;
            v[a].goals += na;
            v[b].goals += nb;
            v[a].goals_diff += na-nb;
            v[b].goals_diff += nb-na;
            v[b].goals_vis +=nb;
            //printf("[%s] %d\n",sa.c_str(),na);
            //printf("[%s] %d\n",sb.c_str(),nb);
            //puts("");
        }
        loop(i,0,n) assert(v[i].id==i);
        sort(v.begin(), v.end(), my_cmp_score);
        loop(i,0,n) v[i].place = i;
        sort(v.begin(), v.end(), my_cmp_id);
        int ans=0;
        iter(m, hist, vector<ii>) if(v[m->x].place > v[m->y].place) ans++;
        printf("The paradox occurs %d time(s).\n",ans);
        sort(v.begin(), v.end(), my_cmp_place);
        loop(i,0,n) printf("%d. %s\n", i+1, v[i].name.c_str());
    }
    flush(cout);
    return 0;
}
