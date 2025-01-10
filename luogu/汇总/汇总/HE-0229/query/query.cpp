#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
using namespace std;

int n, head[500005], cnt, q, f[500005][20], l, r, k, dep[500005];

struct node{
	int to, nxt;
}e[1000005];

void add(int u, int v){
	e[++cnt] = node{v, head[u]};
	head[u] = cnt;
	return;
}

void dfs(int u, int fa){
	f[u][0] = fa;
	dep[u] = dep[fa] + 1;
	for(int i = head[u]; i > 0; i = e[i].nxt){
		int to = e[i].to;
		if(to == fa)continue;
		dfs(to, u);
	}
	return;
}

int lca(int x, int y){
	if(dep[x] < dep[y])swap(x, y);
	int t = log2(dep[x] - dep[y]);
	for(int i = t; i >= 0; i--)if(dep[f[x][i]] >= dep[y])x = f[x][i];
	if(x == y)return x;
	t = log2(dep[y]);
	for(int i = t; i >= 0; i--){
		if(f[x][i] != f[y][i]){
			x = f[x][i];
			y = f[y][i];
		}
	}
	return f[x][0];
}

int main(){
	freopen("query.in", "r", stdin);
	freopen("query.out", "w", stdout);
	scanf("%d", &n);
	for(int i = 1; i < n; i++){
		int u, v;
		scanf("%d %d", &u, &v);
		add(u, v);
		add(v, u);
	}
	dfs(1, 0);
	for(int j = 1; j <= 19; j++){
		for(int i = 1; i <= n; i++){
			f[i][j] = f[f[i][j - 1]][j - 1];
		}
	}
	scanf("%d", &q);
	while(q--){
		scanf("%d %d %d", &l, &r, &k);
		int ans = 0;
		if(k == 1){
			for(int i = l; i <= r; i++)ans = max(ans, dep[i]);
			printf("%d\n", ans);
			continue;
		}
		for(int i = l; i + k - 1 <= r; i++){
			int u = i;
			for(int j = i + 1; j <= i + k - 1; j++){
				u = lca(u, j);
				if(dep[u] < ans)break;
			}
			ans = max(ans, dep[u]);
		}
		printf("%d\n", ans);
	}
	return 0;
}
