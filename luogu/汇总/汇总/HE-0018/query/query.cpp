#include<bits/stdc++.h>

using namespace std;

const int N = 5e5 + 10;
int n , d[N] , st[N][40] , g[N];
vector<int> q[N];
void dfs(int x , int fa) {
	d[x] = d[fa] + 1;
	for(int i = 0;i < q[x].size();i ++) {
		if(q[x][i] != fa) dfs(q[x][i] , x);
	}
//	d[x] --;
}

int main() {
	freopen("query.in","r",stdin);
	freopen("query.out","w",stdout);
	cin >> n;
	for(int i = 1 , u , v;i < n;i ++) {
		scanf("%d%d",&u,&v);
		q[u].push_back(v); q[v].push_back(u);
	}
	dfs(1 , 0);
	for(int i = 1;i <= n;i ++) st[i][0] = d[i];
//	for(int i = 1;i <= n;i ++) cout << d[i] << " ";
	for(int i = 2;i <= n;i ++) {
		g[i] = g[i / 2] + 1;
	}
	for(int i = 1;i <= g[n];i ++) {
		for(int j = 1;j + pow(2 , i) - 1 <= n;j ++) {
			st[j][i] = max(st[j][i - 1] , st[j + (1 << (i - 1))][i - 1]);
		}
	}
	int q; cin >> q; int l , r , k;
	while(q --) {
		scanf("%d%d%d",&l,&r,&k);
		int u = g[r - l + 1];
		printf("%d\n",max(st[l][u] , st[r - (1 << u) + 1][u]));
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
/*
6 
5 6 6 1 6 2 2 3 2 4 
3 2 5 2 1 4 1 1 6 3
*/
