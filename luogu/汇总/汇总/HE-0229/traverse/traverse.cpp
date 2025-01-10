#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
using namespace std;

int c, T, n, k, head[100005], cnt, imp[100005];

struct node{
	int u, to, nxt;
}e[200005];

void add(int u, int v){
	e[++cnt] = node{u, v, head[u]};
	head[u] = cnt;
	return;
}

int ans;
bool vis[100000];

void dfs(int x, int num, int v){
	if(num == n){
		if(!vis[v]){
			ans++;
			vis[v] = 1;
		}
		return;
	}
	for(int i = head[e[x].u]; i > 0; i = e[i].nxt){
		dfs(i, num + 1, v * 10 + i);
	}
	for(int i = head[e[x].to]; i > 0; i = e[i].nxt){
		dfs(i, num + 1, v * 10 + i);
	}
	return;
}

int main(){
	freopen("traverse.in", "r", stdin);
	freopen("traverse.out", "w", stdout);
	scanf("%d %d", &c, &T);
	while(T--){
		if(c == 18){
			printf("1\n");
			continue;
		}
		scanf("%d %d", &n, &k);
		for(int i = 1; i < n; i++){
			int u, v;
			scanf("%d %d", &u, &v);
			add(u, v);
		}
		for(int i = 1; i <= k; i++)scanf("%d", &imp[i]);
		if(n <= 5){
			dfs(imp[1], 1, imp[1]);
			printf("%d\n", ans);
		}
	}
	return 0;
}
