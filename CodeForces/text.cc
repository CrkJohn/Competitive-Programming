#include <cstdio>
#include <cstring>
#include <cmath>
#include <vector>
#include <queue>
#include <algorithm>
#include <iostream>
#include <string>
#include <sstream>
#include <functional>
#include <map>
#include <set>
#include <stack>
using namespace std;
#pragma warning(disable:4996)
const int INF = 1e9 + 1;
const int MOD = 1000000007;
typedef long long ll;
 
int a[300001], b[300001];
vector<int> p[300001];
int tree[1048577];
 
void update(int node, int start, int end, int index, int diff)
{
	if (start == end)
	{
		tree[node] = diff;
		return;
	}
	int mid = (start + end) >> 1;
	if (index <= mid)
		update(node * 2, start, mid, index, diff);
	else
		update(node * 2 + 1, mid + 1, end, index, diff);
	tree[node] = min(tree[node * 2], tree[node * 2 + 1]);
}
 
int find(int node, int start, int end, int left, int right)
{
	if (left > end || right < start)
		return INF;
	if (left <= start && end <= right)
		return tree[node];
	int mid = (start + end) >> 1;
	return min(find(node * 2, start, mid, left, right), find(node * 2 + 1, mid + 1, end, left, right));
}
 
int main()
{
    freopen("in.txt","r",stdin);
	int T;
	scanf("%d", &T);
	while (T--)
	{
		int N;
		scanf("%d", &N);
		for (int i = 0; i < N; i++)
			p[i].clear();
		for (int i = 0; i < N; i++)
		{
			scanf("%d", a + i);
			a[i]--;
			p[a[i]].push_back(i);
		}
		for (int i = 0; i < N; i++)
		{
			scanf("%d", b + i);
			b[i]--;
		}
		for (int i = 0; i < min(4 * N, 1048577); i++)
			tree[i] = INF;
		for (int i = 0; i < N; i++)
		{
			reverse(p[i].begin(), p[i].end());
			if (!p[i].empty())
				update(1, 0, N - 1, i, p[i].back());
		}
 
		bool ok = true;
		for (int i = 0; i < N; i++)
		{
			if (p[b[i]].empty())
			{
				ok = false;
				break;
			}
			int pos = p[b[i]].back();
			if (find(1, 0, N - 1, 0, b[i]) < pos)
			{
				ok = false;
				break;
			}
			p[b[i]].pop_back();
			update(1, 0, N - 1, b[i], p[b[i]].empty() ? INF : p[b[i]].back());
		}
		puts(ok ? "YES" : "NO");
	}
	return 0;
}
