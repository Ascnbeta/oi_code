#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
const int INF=1e7;
int n,m;
int cnt;
struct Edge { int to,next; } edge[N<<1];
int head[N];
int L,R,k;
int fa[N],dep[N];
int F[N][21],pw[N],g[N][21];
int ans;

void add(int u,int v){
	cnt++;
	edge[cnt].to=v;
	edge[cnt].next=head[u];
	head[u]=cnt;
}

void DFS(int u){
	dep[u]=dep[fa[u]]+1;
	for(int i=head[u];i;i=edge[i].next){
		int v=edge[i].to;
		if(v==fa[u]) continue;
		fa[v]=u; F[v][0]=u;
		DFS(v);
	}
}

int LCA(int u,int v){
	if(dep[u]<dep[v]) swap(u,v);
	int d=dep[u]-dep[v];
	for(int i=0;d;i++,d>>=1){
		if(d&1) u=F[u][i];
	}
	if(u==v) return u;
	for(int i=20;i>=0;i--){
		if(F[u][i]!=F[v][i]){
			u=F[u][i]; v=F[v][i];
		}
	} 
	return fa[u];
}

int Q(int l,int r){
	int len=__lg(r-l+1);
	return LCA(g[l][len],g[r-pw[len]+1][len]);
}

void Solve(){
	ans=0;
	scanf("%d%d%d",&L,&R,&k);
	for(int i=R;i>=L;i--){
		int x=i-k+1;
		if(x<L) break;
		ans=max(ans,dep[Q(x,i)]);
	}
	printf("%d\n",ans);
}

int main(){
	freopen("query.in","r",stdin);
	freopen("query.out","w",stdout);
	scanf("%d",&n);
	int u,v;
	for(int i=1;i<n;i++){
		scanf("%d%d",&u,&v);
		add(u,v); add(v,u);
	}	
	DFS(1);
	for(int j=1;j<=20;j++){
		for(int i=1;i<=n;i++) F[i][j]=F[F[i][j-1]][j-1];
	}
	for(int i=1;i<=n;i++) g[i][0]=i;
	int len=__lg(n);
	pw[0]=1;
	for(int i=1;i<=len;i++) pw[i]=pw[i-1]*2;
	for(int j=1;j<=len;j++){
		for(int i=1;i+pw[j]-1<=n;i++) g[i][j]=LCA(g[i][j-1],g[i+pw[j-1]][j-1]);
	}
	scanf("%d",&m);
	for(int i=1;i<=m;i++) Solve();
	return 0;
}
