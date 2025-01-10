#include<bits/stdc++.h>
using namespace std;
const int N = 5e5+100;

int n,m;
int dfn[N],dep[N],f[N],top[N],siz[N],son[N];
int st[22][N];
vector<int> a[N];

namespace lian
{
	namespace sg
	{
		struct dat
		{
			int len,mxq,mxh,mx;
			dat(){len=mxq=mxh=mx=0;}
			inline void m(const dat &x,const dat &y)
			{
				len=x.len+y.len;
				if(x.mx==x.len)
					mxq=x.mx+y.mxq;
				else
					mxq=x.mxq;
				if(y.mx==y.len)
					mxh=x.mxh+y.mx;
				else
					mxh=y.mxh;
				mx=max({mxq,mxh,x.mx,y.mx,x.mxh+y.mxq});
				return;
			}
		};
		dat t[N*4];
		#define mid ((l+r)>>1)
		#define ll (x<<1)
		#define rr (x<<1|1)
		inline void build(int l,int r,int x)
		{
			if(l==r){t[x]=dat();t[x].len=1;return;}
			build(l,mid,ll),build(mid+1,r,rr);
			t[x].m(t[ll],t[rr]);
		}
		inline void insert(int pos,int l,int r,int x)
		{
			if(l==r){t[x].len=t[x].mxq=t[x].mxh=t[x].mx=1;return;}
			if(pos<=mid)insert(pos,l,mid,ll);
			else insert(pos,mid+1,r,rr);
			t[x].m(t[ll],t[rr]);
		}
		inline dat get(int l1,int r1,int l,int r,int x)
		{
			if(l>=l1&&r<=r1)return t[x];
			if(l1<=mid&&r1>mid)
			{
				dat res;
				res.m(get(l1,r1,l,mid,ll),get(l1,r1,mid+1,r,rr));
				return res;
			}
			if(l1<=mid)return get(l1,r1,l,mid,ll);
			return get(l1,r1,mid+1,r,rr);
		}
		#undef mid
		#undef ll
		#undef rr
	}
	using namespace sg;
	struct qes
	{
		int l,r,k,pos,ll,rr;
	};
	vector<qes> q[N],tmp[N];
	vector<int> d[N];
	int dep[N],mxdep;
	int ans[N];
	inline void dfs(int x,int fa)
	{
		d[dep[x]].push_back(x);
		mxdep=max(mxdep,dep[x]);
		for(auto i:a[x])
		{
			if(i==fa)continue;
			dep[i]=dep[x]+1;
			dfs(i,x);
		}
	}
	void work()
	{
		int x,y,z;
		dep[1]=1;
		dfs(1,0);
		cin>>m;
		for(int i=1;i<=m;i++)
		{
			cin>>x>>y>>z;
			q[(1+mxdep)>>1].push_back({x,y,z,i,1,mxdep});
		}
		for(int kkk=__lg(mxdep)+2;kkk;kkk--)
		{
			build(1,n,1);
			for(int j=mxdep;j;j--)
			{
				for(auto p:d[j])
					insert(p,1,n,1);
				for(auto i:q[j])
				{
					// cerr<<j<<' '<<i.l<<' '<<i.r<<' '<<i.k<<' '<<get(i.l,i.r,1,n,1).mx<<'\n';
					if(get(i.l,i.r,1,n,1).mx>=i.k)
					{
						ans[i.pos]=j;
						i.ll=j+1;
					}
					else i.rr=j-1;
					if(i.ll<=i.rr)tmp[(i.ll+i.rr)>>1].push_back(i);
				}
				q[j].clear();
			}
			for(int j=mxdep;j;j--)
			{
				for(auto i:tmp[j])q[j].push_back(i);
				tmp[j].clear();
			}
		}
		for(int i=1;i<=m;i++)cout<<ans[i]<<'\n';
	}
}
inline void dfs(int x,int fa)
{
	f[x]=fa;
	siz[x]=1;
	st[0][x]=x;
	for(auto i:a[x])
	{
		if(i==fa)continue;
		dep[i]=dep[x]+1;
		dfs(i,x);
		siz[x]+=siz[i];
		if(siz[i]>siz[son[x]])son[x]=i;
	}
}
inline void dfs1(int x)
{
	if(!son[x])return;
	top[son[x]]=top[x];
	dfs1(son[x]);
	for(auto i:a[x])
	{
		if(i==f[x]||i==son[x])continue;
		top[i]=i;
		dfs1(i);
	}
}
inline int lca(int x,int y)
{
	// cerr<<x<<' '<<y<<'\n';
	while(top[x]!=top[y])
	{
		if(dep[top[x]]<dep[top[y]])swap(x,y);
		x=f[top[x]];
	}
	return dep[x]>dep[y]?y:x;
}
inline int get(int l,int r)
{
	int lg=__lg(r-l+1);
	return dep[lca(st[lg][l],st[lg][r-(1<<lg)+1])];
}
int lg;
namespace _1
{
	inline void work()
	{
		int l,r,k;
		int ans=1;
		while(m--)
		{
			cin>>l>>r>>k;
			ans=1;
			for(int j=l;j+k-1<=r;j++)
			{
				ans=max(ans,get(j,j+k-1));
			}
			cout<<ans<<'\n';
		}
	}
}
signed main()
{
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	freopen("query.in","r",stdin);
	freopen("query.out","w",stdout);
	cin>>n;
	int x,y;
	for(int i=1;i<n;i++)
	{
		cin>>x>>y;
		a[x].push_back(y);
		a[y].push_back(x);
	}
	dep[1]=1;
	dfs(1,1);
	for(int i=1;i<=n;i++)
	{
		if(dep[i]==n)
		{
			lian::work();
			return 0;
		}
	}
	top[1]=1;
	dfs1(1);
	lg=__lg(n)+1;
	for(int i=1;i<=lg;i++)
	{
		for(int j=1;j+(1<<(i))-1<=n;j++)
		{
			st[i][j]=lca(st[i-1][j],st[i-1][j+(1<<(i-1))]);
		}
	}
	// cerr<<"OK";
	cin>>m;
	_1::work();
	return 0;
}