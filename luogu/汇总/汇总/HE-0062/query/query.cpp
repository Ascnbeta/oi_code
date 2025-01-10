#include<bits/stdc++.h>
using namespace std;
#define rd read()
#define gc getchar()
#define dg(ch) isdigit(ch)
#define _mul(x) ((x<<3)+(x<<1))
#define ll long long
#define il inline
#define FOR(i,j,k) for(int i=j;i<=k;i++)
#define ROF(i,j,k) for(int i=j;i>=k;i--)
il int read(){int x=0,f=1;char ch=gc;while(!dg(ch)){if(ch=='-')f=-1;ch=gc;}while(dg(ch))x=_mul(x)+(ch^48),ch=gc;return x*f;}
const int N=5e5+10;
int n,q,head[N],tot,dep[N];
struct node{int to,nxt;}edge[N<<1];
void add(int x,int y){edge[++tot]=(node){y,head[x]},head[x]=tot;}

namespace LCA{
	int son[N],dfn[N],idx,sz[N],top[N],fa[N];
	void dfs1(int x,int fat){
		sz[x]=1,dep[x]=dep[fat]+1,fa[x]=fat;
		for(int i=head[x];i;i=edge[i].nxt){
			int y=edge[i].to;if(y==fat) continue;
			dfs1(y,x),sz[x]+=sz[y];
			if(sz[son[x]]<sz[y]) son[x]=y;
		}
	}
	void dfs2(int x,int t){
		top[x]=t,dfn[x]=++idx;
		if(!son[x]) return;dfs2(son[x],t);
		for(int i=head[x];i;i=edge[i].nxt){
			int y=edge[i].to;if(y==fa[x]||y==son[x]) continue;
			dfs2(y,y);
		}
	}
	int lca(int x,int y){
		int fx=top[x],fy=top[y];
		while(fx!=fy){
			if(dfn[fx]>=dfn[fy]) x=fa[fx];
			else y=fa[fy];
			fx=top[x],fy=top[y];
		}
		if(dep[x]<dep[y]) return x;
		return y;
	}
}
using namespace LCA;

int main(){
	
	freopen("query.in","r",stdin);
	freopen("query.out","w",stdout);
	
	n=rd;FOR(i,1,n-1){int x=rd,y=rd;add(x,y),add(y,x);}
	LCA::dfs1(1,0),LCA::dfs2(1,1);
	q=rd;
	while(q--){
		int l=rd,r=rd,k=rd,ans=0;set<int> s;
		FOR(i,l,r-k+1){
			int j=i+k-1,tmp=i;
			FOR(t,i+1,j) tmp=LCA::lca(tmp,t);
			ans=max(ans,dep[tmp]);
		}
		printf("%d\n",ans);
	}
	
	return 0;
}
