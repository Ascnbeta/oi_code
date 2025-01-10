#include<bits/stdc++.h>
using namespace std;
struct node{
	int to,next;
}e[1000006];
int head[500005],cnt,n,q;
int siz[500005],dep[500005],top[500005],son[500005];
int fa[500005];
struct node1{
	int w;
}t[500005<<2];
void add(int f,int t)
{
	e[++cnt].to=t;
	e[cnt].next=head[f];
	head[f]=cnt;
}
void dfs1(int x,int faa){
	dep[x]=dep[faa]+1;
	siz[x]=1;
	fa[x]=faa;
	// cout<<x<<" "<<faa<<endl;
	for(int i=head[x];i;i=e[i].next)
	{
		int y=e[i].to;
		if(y==faa) continue;
		dfs1(y,x);
		siz[x]+=siz[y];
		if(siz[y]>siz[son[x]]) son[x]=y;
	}
}
void dfs2(int x,int faa,int tp)
{
	top[x]=tp;
	if(son[x]) dfs2(son[x],x,tp);
	// cout<<x<<" "<<faa<<' '<<tp<<endl;
	for(int i=head[x];i;i=e[i].next)
	{
		int y=e[i].to;
		if(y==faa||y==son[x]) continue;
		dfs2(y,x,y);
	}
}
int lca(int x,int y)
{
	while(top[x]!=top[y])
	{
		if(dep[top[x]]<dep[top[y]]) swap(x,y);
		x=fa[top[x]];
	}
	if(dep[x]>dep[y]) swap(x,y);
	return x;
}
void pushup(int rt )
{
	// cout<<t[rt<<1].w<<" "<<t[rt<<1|1].w<<endl;
	t[rt].w=lca(t[rt<<1].w,t[rt<<1|1].w);
}
void build(int rt,int l,int r)
{
	if(l==r){
		// cout<<l<<""<<endl;
		t[rt].w=l;
		return; 
	}
	int mid=(l+r)>>1;
	build(rt<<1,l,mid);
	build(rt<<1|1,mid+1,r);
	pushup(rt);
	// cout<<l<<" "<<r<<" "<<t[rt].w<<endl;
}
int query(int rt,int l,int r,int ql,int qr)
{
	if(ql<=l&&r<=qr){
		return t[rt].w;
	}
	int mid=(l+r)>>1,ans=0;
	if(ql<=mid)
	{
		int w=query(rt<<1,l,mid,ql,qr);
		if(!ans) ans=w;
	}
	if(qr>mid) 
	{
		int w=query(rt<<1|1,mid+1,r,ql,qr);
		if(!ans) ans=w;
		else ans=lca(ans,w);
	}
	return ans;
}
int main()
{
	freopen("query.in","r",stdin);
	freopen("query.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n;
	for(int i=1;i<n;i++){
		int x,y;
		cin>>x>>y;
		add(x,y);add(y,x);
	}
	dfs1(1,0);dfs2(1,0,1);
	// cout<<lca(3,4);
	// for(int i=1;i<=n;i++) cout<<dep[i]<<' ';
	// cout<<endl;
	// for(int i=1)
	// return 0;
	build(1,1,n);
	// cout<<query(1,1,n,3,4)<<endl;
	// for(int i=1;i<)
	cin>>q;
	for(int i=1;i<=q;i++)
	{
		int l,r,k;
		cin>>l>>r>>k;
		int now=0;
		for(int j=l;j+k-1<=r;j++)
		{
			int r=j+k-1;
			int zc=query(1,1,n,j,r);
			if(dep[zc]>dep[now]) now=zc;
		}
		cout<<dep[now]<<'\n';
	}
}
