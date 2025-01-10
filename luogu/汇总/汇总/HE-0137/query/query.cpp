#include<bits/stdc++.h>
using namespace std;
const int mx = 5e5+10;
int cnt,head[mx*2],to[mx*2],nxt[mx*2];
void add(int u,int v) {
	++cnt;
	nxt[cnt]=head[u];
	head[u]=cnt;
	to[cnt]=v;
}
int f[mx][25];
int n;
int dep[mx];
void dfs(int u,int fa) {
	dep[u]=dep[fa]+1;
	f[u][0]=fa;
	for(int i=head[u]; i; i=nxt[i]) {
		int v=to[i];
		if(v==fa) continue;
		dfs(v,u);
	}
}
void init(){
	for(int i=1;i<=20;i++){
		for(int j=1;j<=n;j++){
			f[j][i]=f[f[j][i-1]][i-1];
		}
	}
}
int getlca(int x,int y){
	if(dep[x]<=dep[y]) swap(x,y);
	for(int i=20;i>=0;i--){
		if(dep[f[x][i]]>=dep[y]) x=f[x][i];
	}
	if(x==y) return x;
	for(int i=20;i>=0;i--){
		if(f[x][i]!=f[y][i]){
			x = f[x][i];
			y = f[y][i];
		}
	}
	return f[x][0];
}
int getl(int l,int r,int k){
	int mx = -1;
	for(int i=l;i<=r-k+1;i++){
		int h = i;
		for(int j=i+1;j<=i+k-1;j++){
			h = getlca(h,j);
		}
		mx = max(dep[h],mx);
	}
	return mx;
}
signed main() {
	freopen("query.in","r",stdin);
	freopen("query.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> n;
	for(int i=1; i<n; i++) {
		int u,v;
		cin >> u >> v;
		add(u,v);
		add(v,u);
	}
	dfs(1,0);
	init();
	int q;
	cin >> q;
	while(q--){
		int l,r,k;
		cin >> l >> r >> k;
		cout << getl(l,r,k) << '\n';
	} 
	return 0;
}
