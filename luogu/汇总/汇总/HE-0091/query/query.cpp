#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10,mod=1e9+7;
int read(){
	int x=0,f=1;char c=getchar();
	while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
	while(c>='0'&&c<='9'){x=x*10+c-'0';c=getchar();}
	return x*f;
}
int n,q,ans=0;
struct edge{int v,nxt;}e[N<<1];
int fir[N],tot=0;
void add_edge(int u,int v){e[++tot].v=v;e[tot].nxt=fir[u];fir[u]=tot;}
int dep[N],siz[N],fa[N],son[N];
void dfs(int u,int f){
	fa[u]=f;son[u]=0;dep[u]=dep[f]+1;siz[u]=1;
	for(int i=fir[u];i;i=e[i].nxt){
		int v=e[i].v;if(v==f)continue;
		dfs(v,u);siz[u]+=siz[v];
		if(siz[son[u]]<siz[v])son[u]=v;
	}
}
int dfn[N],id[N],top[N],times=0;
void hld(int u,int topf){
	top[u]=topf;
	if(!son[u])return;
	hld(son[u],topf);
	for(int i=fir[u];i;i=e[i].nxt){
		int v=e[i].v;if(v==fa[u]||v==son[u])continue;hld(v,v);
	}
}
int lca(int u,int v){
	while(top[u]!=top[v]){
		if(dep[top[u]]<dep[top[v]])swap(u,v);
		u=fa[top[u]];
	}
	if(dep[u]<dep[v])swap(u,v);return v;
}
//namespace BIT{
//	int tree[N];
//	void add(int x,int c){while(x<=n){tree[x]+=c;x+=lowbit(x);}}
//	int ask(int x){int ans=1e9;while(x){ans=min(ans,tree[x]);x-=lowbit(x);}return ans;}
//}
//using namespace BIT;
int main(){
	freopen("query1.in","r",stdin);freopen("query.out","w",stdout);
	n=read();
	for(int i=1;i<=n-1;i++){int u=read(),v=read();add_edge(u,v);add_edge(v,u);}
	dfs(1,0);hld(1,1);
//	for(int i=1;i<=n;i++)add(i,dep[i]);
	q=read();
	for(int i=1;i<=q;i++){
		int l=read(),r=read(),k=read();ans=0;
		for(int j=l;j<=r;j++){
			for(int k=l;k<j;k++)ans=max(ans,dep[lca(j,k)]);
		}
//		cout<<dep[lca(u,v)]<<'\n';
		cout<<ans<<'\n';
	}
	return 0;
}
