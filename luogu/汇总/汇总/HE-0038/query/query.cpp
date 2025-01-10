#include"bits/stdc++.h"
using namespace std;
const int N=5e5+10;
int n,q;
int lc[N][22];
int head[N],nxt[N<<1],ver[N<<1],tot;
void add(int x,int y){
	tot++;
	ver[tot]=y;
	nxt[tot]=head[x];
	head[x]=tot;
}
int fa[N],siz[N],de[N],top[N],son[N];
void dfs1(int x,int f){
	fa[x]=f;
	de[x]=de[fa[x]]+1;
	siz[x]=1;
	for(int i=head[x];i;i=nxt[i]){
		int y=ver[i];
		if(y==fa[x]) continue;
		dfs1(y,x);
		siz[x]+=siz[y];
		if(siz[son[x]]<siz[y]) son[x]=y;
	}
}
void dfs2(int x,int rt){
	top[x]=rt;
	if(son[x]) dfs2(son[x],rt);
	for(int i=head[x];i;i=nxt[i]){
		int y=ver[i];
		if(y==fa[x]||y==son[x]) continue;
		dfs2(y,y);
	}
}
int LCA(int x,int y){
	while(top[x]!=top[y]){
		if(de[fa[top[x]]]<de[fa[top[y]]]) swap(x,y);
		x=fa[top[x]];
	}
	return (de[x]<de[y]?x:y);
}
int Lca(int l,int r){
	int len=log2(r-l+1);
	return LCA(lc[l][len],lc[r-(1<<len)+1][len]);
}
int main(){
	freopen("query.in","r",stdin);
	freopen("query.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>n;
	for(int i=1;i<n;i++){
		int x,y;
		cin>>x>>y;
		add(x,y);
		add(y,x);
	}
	dfs1(1,0);
	dfs2(1,1);
	for(int i=1;i<=n;i++) lc[i][0]=i;
	for(int k=1;k<=20;k++){
		for(int i=1;i<=n-(1<<k)+1;i++){
			lc[i][k]=LCA(lc[i][k-1],lc[i+(1<<(k-1))][k-1]);
		}
	}
	cin>>q;
	for(int i=1;i<=q;i++){
		int l,r,k,maxn=0;
		cin>>l>>r>>k;
		for(int j=l;j<=r-k+1;j++){
			maxn=max(maxn,de[Lca(j,j+k-1)]);
		}
		cout<<maxn<<'\n';
	}
}
