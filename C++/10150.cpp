#include<bits/stdc++.h>
#define se second
#define fi first
#define len(str) (int)(str.length())
#define pb push_back
#define FOR(i,b) for(int i = 0 ; i<b;i++)
#define loop(i,a,b) for(int i = a ; i<b;i++)

using namespace std;
typedef vector<string> vs;
typedef map<string,vs>  G;
typedef map<string,string> father;

using namespace std;

map<string,int> vis;
G graph;
father p;
string src,tgt;

int f(string a, string b){
    int diff=0;
    for (int i=0; i<a.length(); i++)
        if (a[i] != b[i] && ++diff > 1) return 0;
    return 1;
}


void adjG(vs entries){
    FOR(i,entries.size()){
        loop(j,i+1,entries.size()){
            if(f(entries[i],entries[j])){
                graph[entries[i]].pb(entries[j]);
                graph[entries[j]].pb(entries[i]);
            }
        }
    }
}


void bfs(){
    //cout << src << ' ' << tgt << '\n';
    queue<string> q;
    q.push(src);
    bool isPosible = false;
    while(!q.empty()){
        string u = q.front();
        q.pop();
        if(u==tgt){
            isPosible= true;
            break;
        }
        vis[u] = 1;
        for(int i = 0 ; i< graph[u].size();i++){
            string node = graph[u][i];
            if(!vis[node]){
                q.push(node);
                if(p[node]==node)p[node] = u;
            }
        }
    }
    vector<string> recuperacionCamino;
    if(isPosible){
        recuperacionCamino.pb(tgt);
        recuperacionCamino.pb(p[tgt]);
        string padre = p[tgt];
        while(padre != p[padre]){
            padre = p[padre];
            recuperacionCamino.pb(padre);
        }
        reverse(recuperacionCamino.begin(),recuperacionCamino.end());
        for(int i = 0 ; i< recuperacionCamino.size();i++){
            cout << recuperacionCamino[i] << '\n';
        }
    }else{
        cout << "No solution.\n";
    }
}


int main(){
    //freopen("in.txt","r",stdin);
    ios::sync_with_stdio(false);
	cin.tie(0);
	cout.precision(5);
	cout << fixed;
    bool haveAdj[50] = {false};
    vector<string> nodes[50];
    string lec,str;
	stringstream ss;
	while(getline(cin,lec)){
            if(lec=="")break;
            nodes[len(lec)].pb(lec);
            graph[lec] = vs();
            p[lec] = lec;
            vis[lec] = 0;
	}
    int flang = 0;
    while(getline(cin,lec)){
        ss.clear();
        flang++;
        if(flang>1)cout <<'\n';
        ss << lec;
        ss >> src >> tgt;
        if(len(src)!=len(tgt)) cout << "No solution.\n";
        else{
            if (!haveAdj[len(src)]){
                haveAdj[len(src)] = true;
                adjG(nodes[len(src)]);
            }
            bfs();
        }

    }
    return 0;
}
