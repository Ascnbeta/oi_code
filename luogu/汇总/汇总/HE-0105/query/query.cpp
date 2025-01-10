#include<bits/stdc++.h>
using namespace std;
const int M=1e7+1;
int n,q;
int first[M],nxt[M],to[M],tot=0,s[M];
void add(int x,int y)
{
	nxt[++tot]=first[x];first[x]=tot;to[tot]=y;
}
int fa[M][21],deep[M];
void dfs(int u,int f)
{
	deep[u]=deep[f]+1;
	for(int i=1;i<=20;i++)
	{
		fa[u][i]=fa[fa[u][i-1]][i-1];
	}
	for(int i=first[u];i;i=nxt[i])
	{
		int v=to[i];
		if(v==f) continue;
		fa[v][0]=u;
		dfs(v,u);
	}
}
int lca(int x,int y)
{
	if(deep[x]<deep[y])
	{
		swap(x,y);
	}
	for(int i=20;i>=0;i--)
	{
		if(deep[fa[x][i]]>=deep[y])
		{
			x=fa[x][i];
		}
	}
	if(x==y) return x;
	for(int i=20;i>=0;i--)
	{
		if(fa[x][i]!=fa[y][i])
		{
			x=fa[x][i];
			y=fa[y][i];
		}
	}
	return fa[x][0];
}
void build(int k,int le,int ri)
{
	if(le==ri)
	{
		s[le]=deep[le];return;
	}
	int mid=(le+ri)/2;
	build(k<<1,le,mid);build(k<<1|1,mid+1,ri);
	s[k]=min(s[k<<1],s[k<<1|1]);
}
int find(int k,int le,int ri,int x,int y)
{
	int res=1e9;
	if(x<=le&&y>=ri)
	{
		return s[k];
	}
	int mid=(le+ri)/2;
	if(x<=mid) res=min(res,find(k<<1,le,mid,x,y));
	if(y>mid) res=min(res,find(k<<1|1,mid+1,ri,x,y));
	return res;
}
int main()
{
	freopen("query.in","r",stdin);
	freopen("query.out","w",stdout);
	for(int i=1;i<=1e7;i++)
	{
		s[i]=1e7;
	}
	cin>>n>>q;
	for(int i=1;i<n;i++)
	{
		int x,y;
		cin>>x>>y;
		add(x,y);add(y,x);
	}
	dfs(1,0);
	build(1,1,n);
	//cout<<s[6]<<" "<<deep[1];
	for(int i=1;i<=q;i++)
	{
		int ans=1e7;
		int l,r,k;
		cin>>l>>r>>k;
		//cout<<find(1,1,n,l,r)<<endl;
		for(int i=l;i<=r;i++)
		{
			ans=min(deep[i],ans);
		}
		cout<<ans<<endl;
	}
	
	return 0;
}
