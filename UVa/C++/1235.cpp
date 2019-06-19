#include<bits/stdc++.h>
#define forn(i,n) for(int i  = 0 ; i < n ; i++)
#define fore(i,a,n) for(int i  = a ; i < n ; i++)
#define pb push_back
#define all(x) x.begin(),x.end()

using namespace std;


struct node{
    int u , v , w;
    node(int U , int V , int W){
        u = U;
        v = V;
        w = W;
    }

    bool operator < (const node other){
        return other.w > w;
    }
};

typedef vector<int> vi;
typedef pair<int,int> pii;
typedef vector<pii> vpi;
typedef vector<vpi> vvpi;



vector<node> graph;


int getVal(string u , string v){
    int w = 0;
    //cout << u.length() << " " << v.length();
    int cant = 4-v.length();
    forn(i,cant){
        //cout << " : " << (4-v.length()) <<  ": "; 
        v = '0' + v;
        //cout << " v : " << v << " : v ";
    }
    cant = 4-u.length();
    forn(i,cant)u = '0' + u;
    //cout <<" "<< u << " " << v ;
    forn(i,4){
        int lowest = min(u[i]-'0', v[i]-'0');
        int highest = max(u[i]-'0', v[i]-'0');
        
        w += min(highest - lowest, lowest + 10 - highest);
        //w += abs( (u[i]-'0') - (v[i]-'0'));       
        //w+= 
    }
    //cout << " " << w << endl;
    return w;
}

const int maxn = 550;

int p[maxn], r[maxn];

void makeUF(int N){
    forn(i,N){
        p[i] = i;
        r[i] = 0;
    }
}

int findP(int u){
    if(p[u] != u) p[u]  = findP(p[u]);
    return p[u];
}


void unionF(int x, int y){
     int xRaiz = findP(x);
     int yRaiz = findP(y);
     if (r[xRaiz]< r[yRaiz]){
        p[xRaiz] = yRaiz;
     }else if (r[xRaiz]> r[yRaiz]){
        p[yRaiz] = xRaiz;
     }else{
        p[yRaiz] = xRaiz;
        r[xRaiz] = r[xRaiz] + 1;
    }
}



void makeGraph(vector<string> g){

    graph.clear();
    forn(i,(int)g.size()){
        for(int j = i+1;j < g.size(); j++){
            if(i == j)continue;
            //cerr << g[i] << " " << g[j];
            int w = getVal(g[i] , g[j]);
            //cerr << " " <<  w << endl;
            graph.pb(node(i,j,w));
        }
    }
    int mst = 0;
    sort(all(graph));
    /*for(auto node : graph){
        cout << node.u << " " << node.v  << " " << node.w << endl;
    }
    */
    bool vis0 = false;
    makeUF(g.size()+3);
    for(auto n : graph){
        //cerr << n.u << " " << n.v << " " << n.w << endl;
        if((n.u == 0 || n.v == 0)  && vis0 == true)continue;
        if(findP(n.u) != findP(n.v)){
            //cout << " :) " << endl;
            mst+=n.w;
            unionF(n.u,n.v);
            if(n.u == 0 || n.v == 0)vis0 = true;

        }
        
    }
    cout << mst << endl;
}


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    /* 
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    */
    int ntc;
    cin >> ntc;
    forn(ctn ,ntc){
        int n; cin >> n;
        vector<string> nodes;
        nodes.pb("0000");
        forn(i,n){
            int num;cin >> num;
            nodes.pb(to_string(num));
        }
        makeGraph(nodes);


   }
    return 0;
}
