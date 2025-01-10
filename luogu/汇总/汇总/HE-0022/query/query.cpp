#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
int n,q;
namespace edv
{
	struct node
	{
		int v,nex;
	}e[N<<1];
	int edcnt,ly[N];
	void add(int u,int v){e[++edcnt]={v,ly[u]};ly[u]=edcnt;}
}
using namespace edv;
namespace sollian
{
	int tot=0;
	int d[N],t[N<<5],ls[N<<5],rs[N<<5],rt[N];
	bool check()
	{
		for(int i=1;i<=n;++i)
		{
			for(int j=ly[i];j;j=e[j].nex)
				++d[i];
		}
		int fl=d[1]==1;
		for(int i=2;i<=n;++i)
			fl&=d[i]<=2;
		return fl;
	}
	void dfs(int u,int dp)
	{
		d[u]=dp;
		for(int i=ly[u];i;i=e[i].nex)
		{
			int v=e[i].v;
			if(d[v])
				continue;
			dfs(v,dp+1);
		}
	}
	void build(int &u,int l,int r)
	{
		if(!u)
			u=++tot;
		if(l==r)
			return;
		int mid=(l+r)>>1;
		build(ls[u],l,mid),build(rs[u],mid+1,r);
	}
	void upd(int &rt,int now,int l,int r,int pos)
	{
		if(!rt)
			rt=++tot;
		if(l==r)
		{
			t[rt]++;
			return;
		}
		int mid=(l+r)>>1;
		if(pos<=mid)
			upd(ls[rt],ls[now],l,mid,pos),rs[rt]=rs[now];
		else
			upd(rs[rt],rs[now],mid+1,r,pos),ls[rt]=ls[now];
		t[rt]=t[ls[rt]]+t[rs[rt]];
	}
	int query(int r1,int r2,int l,int r,int L,int R,int res=0)
	{
		if(l>=L&&r<=R)
			return t[r2]-t[r1];
		int mid=(l+r)>>1;
		if(L<=mid)
			res+=query(ls[r1],ls[r2],l,mid,L,R);
		if(R>mid)
			res+=query(rs[r1],rs[r2],mid+1,r,L,R);
		return res;
	}
	int main()
	{
		for(int i=1;i<=n;++i)
			d[i]=0;
		dfs(1,1);
		build(rt[0],1,n);
//		cout<<tot<<endl;
		for(int i=1;i<=n;++i)
			upd(rt[i],rt[i-1],1,n,d[i]);
		while(q--)
		{
			int l,r,k;
			cin>>l>>r>>k;
			int L=1,R=n,ans=1;
			while(L<=R)
			{
				int mid=(L+R)>>1;
				int res=query(rt[l-1],rt[r],1,n,mid,n);
				if(res<k)
					R=mid-1;
				else
					L=mid+1,ans=mid;
			}
			cout<<ans<<endl;
		}
		return 0;
	}
}
namespace sol1
{
	int dfnc=0;
	int dfn[N],son[N],tp[N],dep[N],fa[N],siz[N];
	int st[N][25],lg[N],pw[25];
	void dfs1(int u,int f)
	{
		fa[u]=f,dep[u]=dep[f]+1,siz[u]=1;
		for(int i=ly[u];i;i=e[i].nex)
		{
			int v=e[i].v;
			if(v==f)
				continue;
			dfs1(v,u),siz[u]+=siz[v];
			if(siz[v]>siz[son[u]])
				son[u]=v;
		}
	}
	void dfs2(int u,int tpn)
	{
		dfn[u]=++dfnc,tp[u]=tpn;
		if(son[u])
			dfs2(son[u],tpn);
		for(int i=ly[u];i;i=e[i].nex)
		{
			int v=e[i].v;
			if(v==fa[u]||v==son[u])
				continue;
			dfs2(v,v);
		}
	}
	int lca(int u,int v)
	{
		while(tp[u]!=tp[v])
		{
			if(dep[tp[u]]>dep[tp[v]])
				swap(u,v);
			v=fa[tp[v]];
		}
		if(dep[u]>dep[v])
			swap(u,v);
		return u;
	}
	void build()
	{
		lg[0]=-1,pw[0]=1;
		for(int i=1;i<=n;++i)
			st[i][0]=i,lg[i]=lg[i/2]+1;
		for(int i=1;i<=20;++i)
			pw[i]=pw[i-1]*2;
		for(int len=1;pw[len]<=n;++len)
			for(int i=1;i+len-1<=n;++i)
				st[i][len]=lca(st[i][len-1],st[i+pw[len-1]][len-1]);
	}
	int query(int l,int r)
	{
		int len=lg[r-l+1];
		return lca(st[l][len],st[r-pw[len]+1][len]);
	}
	int main()
	{
		dfs1(1,0),dfs2(1,1);
		build();
		while(q--)
		{
			int l,r,k,ans=0;
			cin>>l>>r>>k;
			for(int i=l;i+k-1<=r;++i)
			{
				int L=i,R=i+k-1;
				ans=max(ans,dep[query(L,R)]);
			}
			cout<<ans<<endl;
		}
		return 0;
	}
}
signed main()
{
	ios::sync_with_stdio(0);
	freopen("query.in","r",stdin);
	freopen("query.out","w",stdout);
	cin>>n;
	for(int i=1,u,v;i<n;++i)
		cin>>u>>v,add(u,v),add(v,u);
	cin>>q;
	if(sollian::check())
		return sollian::main();
	return sol1::main();
}
