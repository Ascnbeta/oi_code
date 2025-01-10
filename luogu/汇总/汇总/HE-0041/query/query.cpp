#include<bits/stdc++.h>
using namespace std;
const int inf=1e9;
int n,m,l,r,k,x,y,vis[500005],flag,ans;
int head[500005],nxt[1000005],target[1000005],tot;
void add(int x,int y){
	tot++;
	nxt[tot]=head[x];
	head[x]=tot;
	target[tot]=y;
}
int size[500005],f[500005],dep[500005],top[500005],dfn[500005],rnk[500005],hson[500005],cnt;
void dfs1(int x,int fa){
	size[x]=1;
	for(int i=head[x];i;i=nxt[i]){
		int y=target[i];
		if(y==fa) continue;
		f[y]=x;
		dep[y]=dep[x]+1;
		dfs1(y,x);
		size[x]+=size[y];
		if(size[hson[x]]<size[y]) hson[x]=y; 
	}
}
void dfs2(int x,int t){
	top[x]=t;
	cnt++;
	dfn[x]=cnt;
	rnk[cnt]=x;
	if(!hson[x]) return;
	dfs2(hson[x],t);
	for(int i=head[x];i;i=nxt[i]){
		int y=target[i];
		if(y==f[x] || y==hson[x]) continue;
		dfs2(y,y);
	}
}
int lca(int x,int y){
	while(top[x]^top[y]){
		if(dep[top[x]]>dep[top[y]]) x=f[top[x]];
		else y=f[top[y]];
	}
	if(dfn[x]<dfn[y]) return x;
	else return y;
}
int lg[500005],g[500005][21];
void init_lca(){
	for(int i=2;i<=n;i++){
		lg[i]=lg[i>>1]+1;
	}
	for(int i=1;i<=n;i++){
		g[i][0]=i;
	}
	for(int j=1;j<=lg[n];j++){
		for(int i=1;i<=n;i++){
			g[i][j]=lca(g[i][j-1],g[min(n,i+(1<<(j-1)))][j-1]);
		}
	}
}
int query_lca(int l,int r){
	int d=lg[r-l+1];
	return lca(g[l][d],g[r-(1<<d)+1][d]);
}
void solve1(){
	init_lca();
	cin>>m;
	for(int i=1;i<=m;i++){
		cin>>l>>r>>k;
		ans=0;
		for(int j=l;j<=r-k+1;j++){
			ans=max(ans,dep[query_lca(j,j+k-1)]+1);
		}
		cout<<ans<<'\n';
	}
}
int main(){
	freopen("query.in","r",stdin);
	freopen("query.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	for(int i=1;i<n;i++){
		cin>>x>>y;
		add(x,y);
		add(y,x);
	}
	dfs1(1,0);
	dfs2(1,1);
	flag=true;
	solve1();
}
