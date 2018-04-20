#include<bits/stdc++.h>
#define se second
#define fi first
#define len(str) (int)(str.length())
#define pb push_back
using namespace std;
typedef vector<string> vs;
typedef map<string,vs>  G;
typedef map<string,string> father;

map<string,int> vis;
G graph;
father p;
string src,tgt;

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
	//ios::sync_with_stdio(false);
	//cin.tie(0);
	//cout.precision(5);
	//cout << fixed;
	set<string> nodes;
	string lec,str;
	stringstream ss;
	while(getline(cin,lec)){
            if(lec=="")break;
            nodes.insert(lec);
            graph[lec] = vs();
            p[lec] = lec;
            vis[lec] = 0;
	}



    for(set<string>::iterator it2 = nodes.begin(); it2!=nodes.end();it2++){
        string nodoFi = *it2;
        for(set<string>::iterator it  = nodes.begin() ; it!=nodes.end();it++){
            string nodoSe = *it;
            if(len(nodoFi)!= len(nodoSe) || nodoFi==nodoSe)continue;

            int fail = 0,lon = len(nodoFi);
            for(int l = 0 ; l < lon ; l++){
                if(fail>1)break;
                if(nodoFi[l] != nodoSe[l])fail++;
            }
            if(fail==1){
                graph[nodoFi].pb(nodoSe);
                graph[nodoSe].pb(nodoFi);
            }
        }
    }
    bool flang = 0;
    /*
    while(getline(cin,lec)){
        ss.clear();
        if(flang && len(lec)>0)cout <<'\n';
        flang = 1;
        ss << lec;
        ss >> src >> tgt;
        bfs();
    }
    */


	return 0;
}
