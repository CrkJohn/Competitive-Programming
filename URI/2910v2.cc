#include <bits/stdc++.h>

using namespace std;

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
#define out(x) freopen(#x".txt","w",stdout)
#define err() freopen("err.txt","w",stderr)
#define cls(a,val) memset(a,val,sizeof a)
#define INF  1e9
#define len(a) ((int)a.size())


const long long inf = 1e12;

struct edge {
  int to;
  long long len, cost;
  bool operator < (const edge & o) const {
    if (len == o.len)
      return cost > o.cost;
    return len > o.len;
  }
};

ostream& operator<<(ostream& os, edge e) {
    os << "[ u :" << e.to << " l : " << e.len << " c:  " << e.cost;
    return os << "]";
}


int my_cmp(const edge &a, const edge &b) {
  if (a < b) return 1; // greater
  if (b < a) return -1;
  return 0;
}

int main() {
#ifdef LOCAL
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  in();
#define endl '\n'
#endif

  int n, m;
  cin >> n >> m;
  vector<vector<edge>> g(n);

  for (int i = 0; i < m; i++) {
    int u, v;
    long long l, c;
    cin >> u >> v >> l >> c;
    u--;
    v--;
    g[u].push_back({v, l, c});
    g[v].push_back({u, l, c});
  }

  priority_queue<edge> q;
  q.push({0, 0, 0});

  vector<edge> best(n, {0, inf, inf});
  best[0] = {0, 0, 0};

  vector<long long> cost(n, 0);

  while (!q.empty()) {
    auto s = q.top();
    q.pop();

    int node = s.to;

    if (my_cmp(s, best[node]) == 1) continue;

    for (auto e : g[node]) {
      int to = e.to;
      edge extra = {to, s.len + e.len, e.cost};
      if (my_cmp(extra, best[to]) == -1) {
        best[to] = extra;
        cost[to] = e.cost;
        q.push(extra);
      }
    }
  }

  long long total = 0;
  for (int i = 0; i < n; i++) {
    cout << best[i] << endl;
    total += cost[i];
  }
  cout << total << endl;

  return 0;
}