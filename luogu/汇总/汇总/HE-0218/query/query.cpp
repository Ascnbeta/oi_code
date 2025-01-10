#include<bits/stdc++.h>
#define mid ((l+r)>>1)
#define lc (p<<1)
#define rc (p<<1|1)
using namespace std;
const int N=5e5+5;
int ans[5005][5005],dep[N],son[N],tp[N],siz[N],fa[N],n,head[N],num,tr[N*4],m;
struct edge{
	int to,next;
}g[N*2];
void addd(int u,int v)
{
	num++;
	g[num].to=v;
	g[num].next=head[u];
	head[u]=num;
}
void dfs(int u)
{
	for(int i=head[u];i;i=g[i].next)
	{
		int v=g[i].to;
		if(v==fa[u]) continue;
		fa[v]=u;
		dep[v]=dep[u]+1;
		dfs(v);
		siz[u]+=siz[v];
		if(siz[son[u]]<siz[v]) son[u]=v;
	}
}
void dfs1(int u)
{
	if(fa[son[u]]==u) tp[u]=tp[fa[u]];
	else tp[u]=u;
	for(int i=head[u];i;i=g[i].next)
	{
		int v=g[i].to;
		if(v==fa[u]) continue;
		dfs1(v);
	}
}
int lca(int u,int v)
{
	if(u==0||v==0) return u+v;
	while(tp[u]!=tp[v])
	{
		if(dep[tp[u]]>dep[tp[v]]) swap(u,v);
		v=fa[tp[v]];
	}
	if(dep[u]>dep[v]) swap(u,v);
	return u;
}
void pushup(int p)
{
	tr[p]=lca(tr[lc],tr[rc]);
}

void build(int l,int r,int p)
{
	if(l==r)
	{
		tr[p]=l;
		return;
	}
	build(l,mid,lc),build(mid+1,r,rc);
	pushup(p);
}
int query(int l,int r,int ul,int ur,int p)
{
	if(l>=ul&&r<=ur) return tr[p];
	int ans=0;
	if(mid>=ul) ans=lca(ans,query(l,mid,ul,ur,lc));
	if(mid<ur) ans=lca(ans,query(mid+1,r,ul,ur,rc));
	return ans;
}
int main()
{
	freopen("query.in","r",stdin);
	freopen("query.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	int n;
	cin>>n;
	int u,v;
	for(int i=1;i<n;i++)
	{
		cin>>u>>v;
		addd(u,v),addd(v,u);
	}
	dep[1]=1;
	dfs(1),dfs1(1);
	if(n<=5000)
	{
		for(int i=1;i<=n;i++)
		{
			ans[i][i]=i;
			for(int j=i+1;j<=n;j++)
				ans[i][j]=lca(ans[i][j-1],j);
		}
		cin>>m;
		while(m--)
		{
			int l,r,k;
			cin>>l>>r>>k;
			int res=-1e9;
			for(int i=l;i+k-1<=r;i++) res=max(res,dep[ans[i][i+k-1]]);
			cout<<res<<'\n';
		}
	}
	else
	{
		build(1,n,1);
		cin>>m;
		while(m--)
		{
			int l,r,k;
			cin>>l>>r>>k;
			cout<<dep[query(1,n,l,r,1)]<<'\n';
		}
	}
}
