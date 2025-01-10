#include <bits/stdc++.h>
#define ll long long
#define ts cout<<"*************"<<endl;
#define pb push_back
#define file(x) freopen(x".in","r",stdin),freopen(x".out","w",stdout);
using namespace std;
const int N =5e5+5;
inline ll read(){
	ll x=0,f=1;char ch=getchar();
	for(;ch<'0'||ch>'9';ch=getchar())if(ch=='-')f=-f;
	for(;ch>='0'&&ch<='9';ch=getchar())x=(x<<3)+(x<<1)+(ch^48);
	return x*f;
}
inline void write(ll x){
	if(x<0)putchar('-'),x=-x;
	if(x>9)write(x/10);
	putchar((x%10)|48);
}
inline void write(ll x,char p){
	write(x);putchar(p);
}
bool Mbe;
int n,q;std::vector<int> edge[N];
int dfn[N],top[N],dep[N],fa[N],sz[N],dfstot,son[N];
int mx=0;
inline void dfs(int u,int F){
	dep[u]=dep[F]+1;fa[u]=F;sz[u]=1;
	mx=max(mx,dep[u]);
	for(auto to:edge[u]){
		if(to==F)continue;
		dfs(to,u);
		if(sz[son[u]]<sz[to])son[u]=to;
		sz[u]+=sz[to];
	}
}
inline void conn(int u,int ans){
	dfn[u]=++dfstot;top[u]=ans;
	if(son[u])conn(son[u],ans);
	for(auto to:edge[u]){
		if(to==fa[u]||to==son[u])continue;
		conn(to,to);
	}
}	
inline int lca(int u,int v){
	while(top[u]!=top[v]){
		if(dep[top[u]]<dep[top[v]])swap(u,v);
		u=fa[top[u]];
	}
	if(dep[u]>dep[v])swap(u,v);
	return u;
}
int st[N][21];

inline int qr(int l,int r){
	int k=__lg(r-l+1);
	return lca(st[l][k],st[r-(1<<k)+1][k]);
}
inline void baoli(){
	for(int i=1;i<=n;i++)st[i][0]=i;
	for(int j=1;j<=20;j++){
		for(int i=1;i+(1<<j)-1<=n;i++){
			st[i][j]=lca(st[i][j-1],st[i+(1<<j-1)][j-1]);
		}
	}
	int l,r,k;
	while(q--){
		l=read();r=read();k=read();
		int ans=0;
		for(int i=l;i<=r-k+1;i++){
			ans=max(ans,dep[qr(i,i+k-1)]);
		}
		write(ans,'\n');
	}
}

inline void solve2(){
	int l,r,k;
	while(q--){
		l=read();r=read();k=read();
		int ans=0;
		for(int i=l;i<=r-k+1;i++){
			int val=1e9;
			for(int j=l;j<=l+k-1;j++){
				val=min(val,dep[j]);
			}
			if(val==1e9)continue;
			ans=max(ans,val);
		}
		write(ans,'\n');
	}
}
struct Query
{
	int l,r,k,id;
}qq[N];
inline void solve1(){
	for(int i=1;i<=n;i++)st[i][0]=i;
	for(int j=1;j<=20;j++){
		for(int i=1;i+(1<<j)-1<=n;i++){
			st[i][j]=lca(st[i][j-1],st[i+(1<<j-1)][j-1]);
		}
	}
	for(int i=1;i<=q;i++){
		int l=qq[i].l,r=qq[i].r;
		write(dep[qr(l,r)],'\n');
	}
}

inline void solve(){
	n=read();
	bool sp1=0,sp2=0;
	for(int i=1,u,v;i<=n-1;i++){
		u=read();v=read();
		edge[u].pb(v);edge[v].pb(u);
	}
	q=read();
	dfs(1,0);conn(1,0);
	if(n<=5000)baoli();
	else{
		if(mx==n){
			return baoli(),void(0);
		}
		for(int i=1;i<=q;i++){
			qq[i]={read(),read(),read(),i};
			if(qq[i].r-qq[i].l+1!=qq[i].k)sp2=0;
			// if(sp1==1)
		}
		if(sp2){
			solve1();
			return;
		}
		baoli();
	}
}	
bool Med;
int main(){
	file("query");
	solve();
	cerr<<(&Mbe-&Med)/1024.0/1024.0<<"MB "<<" "<<(double)clock()/CLOCKS_PER_SEC<<"ms\n";
	return 0;
}