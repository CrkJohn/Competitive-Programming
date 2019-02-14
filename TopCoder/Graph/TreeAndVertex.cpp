#include<bits/stdc++.h>

using namespace std;


class TreeAndVertex {
public:
	int maxn = 110;
	int on[120];
	int vis[120];
	vector<vector <int> > graph;
	int get(vector <int> tree) {
		int len = tree.size();
    graph.assign(len+5, vector<int>());
    for(int i = 0 ;  i < len; i++){
				graph[tree[i]].push_back(i+1);
				graph[i+1].push_back(tree[i]);
    }
//    for(int i = 0 ; i<graph.size(); i++){
//			cout << " Node i : " << i << " -> ";
//			for(int j = 0 ; j < graph[i].size(); j++){
//				cout << graph[i][j] << " ";
//			}
//			cout << endl;
//    }
    memset(on,1,sizeof on);
    int longest = -1e9;
    for(int i = 0 ; i<=len;i++){
				on[i] = 0;
				memset(vis,0,sizeof vis);
				int component = 0;
        for(int j  =  0 ; j<=len ; j++){
//							cerr <<"Node j : " << j << " vis : " << vis[j] << " on : " << on[j] << endl;
							if(i==j)continue;
							if(!vis[j] && on[j]){
									component++;
//									cerr << "Entre" << endl;
									dfs(j);
							}
        }
        on[i] = 1;
        longest = max(longest,component);
    }
		return longest;
	}

	void dfs(const int &u){
			vis[u] = 1;
			for(auto v : graph[u]){
					if(on[v] && !vis[v])dfs(v);

			}
	}

};

