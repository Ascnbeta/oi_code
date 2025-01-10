#include<bits/stdc++.h>
using namespace std;
const int maxn = 1e5+10;
struct edge{
	int to,next;
}e[maxn];
int head[maxn],cnt;
void addedge(int u,int v){
	e[++cnt].to = v;
	e[cnt].next = head[u];
	head[u] = cnt;
}
int fa[maxn][20],dep[maxn];
void dfs(int x,int f,int deep){
	dep[x] = deep;
	fa[x][1] = f;
	for(int i = 2;i < 20;i++){
		fa[x][i] = fa[fa[x][i-1]][i-1];
	}
	for(int i = head[x];i;i = e[i].next){
		int y = e[i].to;
		if(y != f){
			dfs(y,x,deep+1);
		}
	}
}
int lca(int x,int y){
	if(dep[x] < dep[y]) swap(x,y);
	
	int temp = dep[x] - dep[y],lg = 1;
	while(temp){
		if(temp & 1){
			x = fa[x][lg];
		}
		lg--;
		temp >>= 1;
	}
	
	if(x == y) return dep[x];
	lg = 19;
	while(fa[x][1] != fa[y][1]){
		if(fa[x][lg] != fa[y][lg]){
			x = fa[x][lg],y = fa[y][lg];
		}
		lg--;
		
	}
	return dep[fa[x][1]];
}
int minlca(int l,int r){
	if(r - l <= 1) return lca(l,r);
	int mid = (l + r) >> 1;
	return min(lca(l,mid),lca(mid+1,r));
}
int n, q;
int main(){
	freopen("query.in","r",stdin);
	freopen("query.out","w",stdout);
	cin>>n;
	for(int i = 1;i < n;i++){
		int u,v;
		cin>>u>>v;
		addedge(u,v),addedge(v,u);
	}
	dfs(1,0,1);
	cin>>q;
	while(q--){
		int l,r,k;
		cin>>l>>r>>k;
		int ans = -1;
		for(int i = l,j = l + k - 1;j <= r;i++,j++){
			ans = max(ans,minlca(i,j));
		}
		cout<<ans<<endl;
		
	}
	fclose(stdin);
	return 0;
}
