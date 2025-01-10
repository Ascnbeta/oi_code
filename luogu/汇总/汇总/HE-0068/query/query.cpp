#include"bits/stdc++.h"
#define re register
#define int long long
#define ls(p) tr[p].ls
#define rs(p) tr[p].rs
using namespace std;
const int maxn=5e5+10;
int n,m,cnt,rt,segcnt;
int head[maxn];
int in[maxn];
struct node{
	int fa,siz,top,hson,dep;
}t[maxn];
struct edge{
	int to,nxt;
}e[maxn<<1];
struct tree{
	int ls,rs;
	int Lca;
}tr[maxn<<1];
struct Query{
	int l,r,k;
}q[maxn];
inline void add(int u,int v){
	e[++cnt]={v,head[u]};
	head[u]=cnt;
}
inline void dfs1(int u,int fa){
	t[u].fa=fa;t[u].siz=1;t[u].dep=t[fa].dep+1;
	for(re int i=head[u];i;i=e[i].nxt){
		int v=e[i].to;
		if(v==fa) continue;
		dfs1(v,u);
		t[u].siz+=t[v].siz;
		if(!t[u].hson||t[v].siz>t[t[u].hson].siz) t[u].hson=v;
	}
}
inline void dfs2(int u,int top){
	t[u].top=top;
	if(!t[u].hson) return;
	dfs2(t[u].hson,top);
	for(re int i=head[u];i;i=e[i].nxt){
		int v=e[i].to;
		if(v==t[u].fa||v==t[u].hson) continue;
		dfs2(v,v);
	}
}
inline int lca(int u,int v){
	while(t[u].top!=t[v].top){
		if(t[t[u].top].dep<t[t[v].top].dep) swap(u,v);
		u=t[t[u].top].fa;
	}
	return t[u].dep<t[v].dep?u:v;
}
inline void up(int p){tr[p].Lca=lca(tr[ls(p)].Lca,tr[rs(p)].Lca);}
inline void build(int l,int r,int &p){
	p=++segcnt;
	if(l==r){tr[p].Lca=l;return;}
	int mid=(l+r)>>1;
	build(l,mid,ls(p)),build(mid+1,r,rs(p));
	up(p);
}
inline int query(int l,int r,int L,int R,int p){
	if(l>=L&&r<=R) return tr[p].Lca;
	int mid=(l+r)>>1;
	if(R<=mid) return query(l,mid,L,R,ls(p));
	if(L>mid) return query(mid+1,r,L,R,rs(p));
	return lca(query(l,mid,L,R,ls(p)),query(mid+1,r,L,R,rs(p))); 
}
inline void dfs(int u,int fa){
	t[u].dep=t[fa].dep+1;
	for(re int i=head[u];i;i=e[i].nxt){
		int v=e[i].to;
		if(v==fa) continue;
		dfs(v,u);
	}
}
inline void solve1(){
	for(re int i=1,u,v;i<n;++i) cin>>u>>v,add(u,v),add(v,u);
	dfs1(1,0),dfs2(1,1);build(1,n,rt);
	cin>>m;
	for(re int i=1,l,r,k;i<=m;++i){
		cin>>l>>r>>k;int ans=0;
		for(re int j=l;j+k-1<=r;++j){
			ans=max(ans,t[query(1,n,j,j+k-1,rt)].dep);
		}
		cout<<ans<<'\n';
	}
}
int mn[21][maxn],Lg[maxn];
inline void init(){
	for(re int i=1;i<=n;++i) mn[0][i]=t[i].dep,Lg[i]=__lg(i);
	for(re int j=1;j<=20;++j){
		for(re int i=1;i<=n-(1<<j)+1;++i){
			mn[j][i]=min(mn[j-1][i],mn[j-1][i+(1<<(j-1))]);
		}
	}
}
inline int query(int l,int r){
	int k=Lg[r-l+1];
	return min(mn[k][l],mn[k][r-(1<<k)+1]);
}
inline void solve2(){
	dfs(1,0);init();
	cin>>m;
	for(re int i=1,l,r,k;i<=m;++i){
		cin>>l>>r>>k;int ans=0;
		for(re int j=l;j+k-1<=r;++j){
			ans=max(ans,query(j,j+k-1));
		}
		cout<<ans<<'\n';
	}
}
inline void solve3(){
	dfs1(1,0),dfs2(1,1);build(1,n,rt);
	for(re int i=1;i<=m;++i) cout<<t[query(1,n,q[i].l,q[i].r,rt)].dep<<'\n';
}
inline void solve4(){
	dfs1(1,0),dfs2(1,1);build(1,n,rt);
	for(re int i=1;i<=m;++i){
		int ans=0;
		for(re int j=q[i].l;j+q[i].k-1<=q[i].r;++j){
			ans=max(ans,t[query(1,n,j,j+q[i].k-1,rt)].dep);
		}
		cout<<ans<<'\n';
	}
}
signed main(){
	freopen("query.in","r",stdin);
	freopen("query.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n;
	if(n<=5000) solve1();
	else{
		for(re int i=1,u,v;i<n;++i){
			cin>>u>>v,add(u,v),add(v,u);
			++in[u],++in[v];
		}
		int tot1=0,tot2=0;
		for(re int i=1;i<=n;++i) tot1+=(in[i]==1),tot2+=(in[i]==2);
		if(tot1==2&&tot2==n-2) solve2();
		else{
			int tot=0;
			cin>>m;
			for(re int i=1;i<=m;++i){
				cin>>q[i].l>>q[i].r>>q[i].k;
				tot+=(q[i].k==q[i].r-q[i].l+1);
			}
			if(tot==m) solve3();
			else solve4();
		}
	}
	return 0;
}

