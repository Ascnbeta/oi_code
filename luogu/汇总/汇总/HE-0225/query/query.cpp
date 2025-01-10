#include <bits/stdc++.h>
using namespace std;
const int N = 5e5 + 10;

long long n, q, dep[N];
int tot, head[N];
long long L[N << 1][33], f[N << 1][33];// L[i][j] =: [i, i + 2 ^ j - 1] µÄ LCA 
struct node{
	int to, nxt;
}edge[N << 1];

long long cnt = 0;

void bfs(int s) {
	queue<int> q;
	q.push(1);
	dep[1] = 1;
	while(!q.empty()) {
		int u = q.front();
		q.pop();
		for(int i = head[u]; i; i = edge[i].nxt) {
			int v = edge[i].to;
			if(dep[v] || v == 1) continue;
			dep[v] = dep[u] + 1;
			f[v][0] = u;
			q.push(v);
		}
	}
	return;
}

int LCA(int a, int b) {
	if(dep[a] < dep[b]) swap(a, b);
	for(int i =30; i >= 0; i --) {
		if(dep[f[a][i]] >= dep[b]) {
			a = f[a][i];
			if(dep[a] == dep[b]) break;
		}
	}
	if(a == b) return a;
	for(int i = 30; i >= 0; i --) {
		if(f[a][i] != f[b][i]) {
			a = f[a][i], b = f[b][i];
		}
	}
	return f[a][0];
}

int reLCA(int l, int k) {
	int tmpl = l, tmpk = k;
	int d = l;
	for(int i = 14; i >= 0; i --) {
		if(k >= (1 << i)) {
			k -= (1 << i);
			l = LCA(l, L[d][i]);
			d = d + (1 << i);
		}
	}
	return dep[l];
}

int main() {
	
	freopen("query.in", "r", stdin);
	freopen("query.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n;
	for(int i = 1; i < n; i ++) {
		int u, v;
		cin >> u >> v;
		edge[++ tot] = (node){v, head[u]};
		head[u] = tot;
		edge[++ tot] = (node){u, head[v]};
		head[v] = tot;
	}
	bfs(1);
	for(int j = 1; j <= 20; j ++) {
		for(int i = 1; i <= n; i ++) {
			f[i][j] = f[f[i][j - 1]][j - 1];
		}
	}
	for(int i = 1; i <= n; i ++) {
		L[i][0] = i;
	}
	for(int j = 1; j <= 14; j ++) {
		for(int i = 1; i + (1 << (j - 1)) <= n; i ++) {
			L[i][j] = LCA(L[i][j - 1], L[i + (1 << (j - 1))][j - 1]);
		}
	}
	cin >> q;
	while(q --) {
		int l, r, k;
		cin >> l >> r >> k;
		int ans = -1;
		for(int i = l; i <= r - k + 1; i ++) {
			ans = max(ans, reLCA(i, k));
		}
		cout << ans << '\n';
	}
	return 0;
	
}
