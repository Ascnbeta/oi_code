#include<bits/stdc++.h>
using namespace std;
const int maxn=5e5+9;
int n,q,l,r,k,tot,cnt;
int h[maxn],nxt[maxn<<1],to[maxn<<1];
int die[maxn],dep[maxn],siz[maxn];
int son[maxn],top[maxn],dfn[maxn];
void add(int x,int y){
	tot++;
	nxt[tot]=h[x];
	to[tot]=y;
	h[x]=tot;
}
void dfs1(int x,int fa){
	siz[x]=1,die[x]=fa,dep[x]=dep[fa]+1;
	for(int i=h[x];i;i=nxt[i]){
		int y=to[i];
		if(y==fa) continue;
		dfs1(y,x);siz[x]+=siz[y];
		if(siz[y]>siz[son[x]]) son[x]=y;
	}
}
void dfs2(int x,int tp){
	top[x]=tp,dfn[x]=++cnt;
	if(!son[x]) return;
	dfs2(son[x],tp);
	for(int i=h[x];i;i=nxt[i]){
		int y=to[i];
		if(y^die[x]&&y^son[x]) dfs2(y,y);
	}
}
int lca(int x,int y){
	while(top[x]^top[y]){
		if(dep[top[x]]<dep[top[y]]) swap(x,y);
		x=die[top[x]];
	}
	if(dep[x]>dep[y]) swap(x,y);
	return x;
}
int main(){
	freopen("query.in","r",stdin);
	freopen("query.out","w",stdout);
	scanf("%d",&n);
	for(int i=1,x,y;i<n;i++){
		scanf("%d%d",&x,&y);
		add(x,y),add(y,x);
	}
	dfs1(1,0),dfs2(1,1);
	scanf("%d",&q);
	while(q--){
		scanf("%d%d%d",&l,&r,&k);
		int ans=0;
		for(int L=l;L+k-1<=r;L++){
			int R=L+k-1,cp=L;
			for(int i=L+1;i<=R;i++) cp=lca(cp,i);
			ans=max(ans,dep[cp]);
		}
		printf("%d\n",ans);
	}
	return 0;
}
