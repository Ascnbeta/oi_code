#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
vector<int> e[N];
int n,q;
namespace Sub1
{
	const int M=5e3+10;
	int dfn[M],seq[M],sz[M],ts,dep[N];
	int lca[M][M];
	int Anc[M][M];
	void dfs(int u,int p)
	{
		dfn[u]=++ts,sz[u]=1,seq[ts]=u;
		dep[u]=dep[p]+1;
		lca[u][u]=u;
		for(auto v:e[u])
		{
			if(v==p) continue;
			dfs(v,u);
			for(int j=dfn[u];j<=dfn[u]+sz[u]-1;j++)
			{
				for(int k=dfn[v];k<=dfn[v]+sz[v]-1;k++)
				{
					int x=seq[j],y=seq[k];
					lca[y][x]=lca[x][y]=u;
				}
			}
			sz[u]+=sz[v];
		}
	}
	
	void solve()
	{
		dfs(1,0);
		for(int i=1;i<=n;i++)
		{
			Anc[i][i]=i;
			for(int j=i+1;j<=n;j++)
			{
				int x=Anc[i][j-1],y=j;
				Anc[i][j]=lca[x][y];
			}
		}
		while(q--)
		{
			int l,r,k;
			cin>>l>>r>>k;
			int mx=0;
			for(int i=l;i+k-1<=r;i++)
			{
				int p=Anc[i][i+k-1];
				mx=max(mx,dep[p]);
			}
			cout<<mx<<"\n";
		}
	}
}

namespace Sub2
{
	int dfn[N],seq[N],ts,sz[N],dep[N],fa[N],son[N],top[N];
	int Min[N][20],Max[N][20];
	void dfs(int u,int p)
	{
		sz[u]=1,fa[u]=p,dep[u]=dep[p]+1;
		for(auto v:e[u])
		{
			if(v==p) continue;
			dfs(v,u);
			sz[u]+=sz[v];
			if(sz[v]>sz[son[u]]) son[u]=v;
		}
	}
	void Dfs(int u,int t)
	{
		dfn[u]=++ts,seq[ts]=u,top[u]=t;
		if(son[u]) Dfs(son[u],t);
		for(auto v:e[u])
		{
			if(v==fa[u] || v==son[u]) continue;
			Dfs(v,v);
		}
	}
	int lca(int u,int v)
	{
		while(top[u]!=top[v])
		{
			if(dep[top[u]]<dep[top[v]]) swap(u,v);
			u=fa[top[u]];
		}
		if(dep[u]<dep[v]) swap(u,v);
		return v;
	}
	void build()
	{
		for(int i=1;i<=n;i++) Min[i][0]=Max[i][0]=dfn[i];
		for(int j=1;j<20;j++)
		{
			for(int i=1;i+(1<<j)-1<=n;i++)
			{
				Min[i][j]=min(Min[i][j-1],Min[i+(1<<(j-1))][j-1]);
				Max[i][j]=max(Max[i][j-1],Max[i+(1<<(j-1))][j-1]);
			}
		}
	}
	int Qmax(int l,int r)
	{
		int j=log2(r-l+1);
		return max(Max[l][j],Max[r-(1<<j)+1][j]);
	}
	int Qmin(int l,int r)
	{
		int j=log2(r-l+1);
		return min(Min[l][j],Min[r-(1<<j)+1][j]);
	}
	void solve()
	{
		dfs(1,0);
		Dfs(1,1);
		build();
		while(q--)
		{
			int l,r,k;
			cin>>l>>r>>k;
			int mx=0;
			for(int i=l;i+k-1<=r;i++)
			{
				int L=i,R=i+k-1;
				int x=Qmin(L,R),y=Qmax(L,R);
				x=seq[x],y=seq[y];
				int p=lca(x,y);
				mx=max(mx,dep[p]);
			}
			cout<<mx<<"\n";
		}
	}
}

namespace Link
{
	#define ls u*2
	#define rs u*2+1
	typedef pair<int,int> PII;
	int dep[N];
	int Min[N][20];
	vector<PII> vec[2][N];
	struct Data
	{
		int l,r,id;
	};
	vector<Data> Q[N];
	int ans[N];
	struct Seg
	{
		struct Tree
		{
			int l,r;
			int mx;
		}tr[N*4];	
		void pushup(int u)
		{
			tr[u].mx=max(tr[ls].mx,tr[rs].mx);
		}
		void build(int u,int l,int r)
		{
			tr[u]={l,r,0};
			if(l==r) return;
			int mid=l+r>>1;
			build(ls,l,mid),build(rs,mid+1,r);
		}
		void modify(int u,int x,int c)
		{
			if(tr[u].l==tr[u].r) tr[u].mx=max(tr[u].mx,c);
			else
			{
				int mid=tr[u].l+tr[u].r>>1;
				if(x<=mid) modify(ls,x,c);
				else modify(rs,x,c);
				pushup(u);
			}
		}
		int query(int u,int l,int r)
		{
			if(tr[u].l>=l && tr[u].r<=r) return tr[u].mx;
			else
			{
				int mid=tr[u].l+tr[u].r>>1,res=0;
				if(l<=mid) res=max(res,query(ls,l,r));
				if(r>mid) res=max(res,query(rs,l,r));
				return res;
			}
		}
	}T[2];
	
	void dfs(int u,int p)
	{
		dep[u]=dep[p]+1;
		for(auto v:e[u])
		{
			if(v==p) continue;
			dfs(v,u);
		}
	}
	int cmin(int x,int y)
	{
		if(dep[x]<dep[y]) return x;
		return y;
	}
	int Qmin(int l,int r)
	{
		int j=log2(r-l+1);
		return cmin(Min[l][j],Min[r-(1<<j)+1][j]);
	}
	void Dp(int l,int r)
	{
		if(l>r) return;
		int p=Qmin(l,r);
		int L=(p-l+1),R=(r-p+1),v=dep[p];
		if(L<=R)
		{
			for(int i=l;i<=p;i++) vec[0][r-i+1].push_back({i,v});
		}
		else
		{
			for(int i=r;i>=p;i--) vec[1][i-l+1].push_back({i,v});
		}
		Dp(l,p-1),Dp(p+1,r);
	}
	bool check()
	{
		dfs(1,0);
		int mx=0;
		for(int i=1;i<=n;i++)mx=max(mx,dep[i]);
		return mx==n;
	}
	void solve()
	{
		dfs(1,0);
		for(int i=1;i<=n;i++) Min[i][0]=i;
		for(int j=1;j<20;j++)
		{
			for(int i=1;i+(1<<j)-1<=n;i++)
			{
				Min[i][j]=cmin(Min[i][j-1],Min[i+(1<<(j-1))][j-1]);
			}
		}
		T[0].build(1,1,n);
		T[1].build(1,1,n);
		Dp(1,n);
		for(int i=1,l,r,k;i<=q;i++)
		{
			cin>>l>>r>>k;
			Q[k].push_back({l,r,i});
		}
		for(int i=n;i>=1;i--)
		{
			for(auto it:vec[0][i]) 
			{
				int x=it.first,v=it.second;
				T[0].modify(1,x,v);
			}
			for(auto it:vec[1][i])
			{
				int x=it.first,v=it.second;
				T[1].modify(1,x,v);
			}
			for(auto it:Q[i])
			{
				int l=it.l,r=it.r,id=it.id;
				ans[id]=max(T[0].query(1,l,r-i+1),T[1].query(1,l+i-1,r));
			}
		}
		for(int i=1;i<=q;i++) cout<<ans[i]<<"\n";
	}
}

signed main()
{
//	system("fc .out query3.ans"),exit(0);
	
//	freopen("query3.in","r",stdin);
//	freopen(".out","w",stdout);
	freopen("query.in","r",stdin);
	freopen("query.out","w",stdout);

	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);

	cin>>n;
	for(int i=1,a,b;i<n;i++)
	{
		cin>>a>>b;
		e[a].push_back(b);
		e[b].push_back(a);
	}
	cin>>q;
	
	if(n<=5000) Sub1::solve();
	else if(Link::check()) Link::solve();
	else Sub2::solve();
	
	return 0;
}
