#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<vector>
#define ll long long
using namespace std;
const int MAXN=5e5+10;
int n,q,dep[MAXN],d[5010][5010],f[5010][5010];
vector <int> v[MAXN],s[MAXN];
void dfs(int x,int fa=0)
{
	d[x][x]=dep[x]=dep[fa]+1;
	s[x].push_back(x);
	for(int y:v[x])
	{
		if(y==fa) continue;dfs(y,x);
		for(int i:s[x]) for(int j:s[y])
			d[i][j]=d[j][i]=dep[x];
		for(int j:s[y]) s[x].push_back(j);
	}
}
namespace BOLI
{
	inline void work()
	{
		for(int i=1,x,y;i<n;++i)
		cin>>x>>y,
		v[x].push_back(y),
		v[y].push_back(x);
		dfs(1);
		for(int i=1;i<=n;++i)
			for(int j=i+1;j<=n;++j)
				d[i][j]=min(d[i][j],d[i][j-1]);
		for(int j=1;j<=n;++j)
		{
			f[j][j]=dep[j];
			for(int i=j-1;i;--i)
				f[i][j]=min(f[i+1][j],d[i][j]);
		}
		cin>>q;
		for(int i=1,l,r,k;i<=q;++i)
		{
			cin>>l>>r>>k;int ans=0;
			for(int j=l;j+k-1<=r;++j)
				ans=max(ans,f[j][j+k-1]);
			cout<<ans<<'\n';
		}
		exit(0);
	}
}
int pos[MAXN],tot;
void F_dfs(int x,int fa=0)
{
	pos[++tot]=x;
	for(int y:v[x])
		if(y!=fa) F_dfs(y,x);
}
namespace SGT
{
	int R[MAXN],cnt;
	struct node{int lenl,lenr,len;bool f;};
	struct tree{node num;int ls,rs;}t[MAXN<<5];
	inline node merge(node x,node y)
	{
		int lenl=0,lenr=0,len=0;bool f=0;
		lenl=x.lenl;if(x.f) lenl=x.len+y.lenl;
		lenr=y.lenr;if(y.f) lenr=y.len+x.lenr;
		len=max({x.len,y.len,x.lenr+y.lenl});
		f=x.f&&y.f;return {lenl,lenr,len,f};
	}
	void insert(int l,int r,int p,int q,int x)
	{
		t[p]=t[q];if(l==r){t[p].num={1,1,1,1};return ;}
		int mid=(l+r)>>1;
		if(x<=mid) insert(l,mid,t[p].ls=++cnt,t[q].ls,x);
		else insert(mid+1,r,t[p].rs=++cnt,t[q].rs,x);
		t[p].num=merge(t[t[p].ls].num,t[t[p].rs].num);
	}
	node query(int l,int r,int p,int x,int y)
	{
		if(x<=l&&y>=r) return t[p].num;
		int mid=(l+r)>>1;
		if(y<=mid) return query(l,mid,t[p].ls,x,y);
		if(x>mid) return query(mid+1,r,t[p].rs,x,y);
		return merge(query(l,mid,t[p].ls,x,y),query(mid+1,r,t[p].rs,x,y));
	}
}using namespace SGT;
signed main()
{
	freopen("query.in","r",stdin);
	freopen("query.out","w",stdout);
	cin.tie(0),cout.tie(0);
	ios::sync_with_stdio(0);
	cin>>n;
	if(n<=5000) BOLI::work();
	for(int i=1,x,y;i<n;++i)
		cin>>x>>y,
		v[x].push_back(y),
		v[y].push_back(x);
	F_dfs(1);
	for(int i=1;i<=n;++i)
		insert(1,n,R[i]=++cnt,R[i-1],pos[n+1-i]);
	cin>>q;
	for(int l,r,k;q;--q)
	{
		cin>>l>>r>>k;
		int L=0,R=n;
		while(L<R)
		{
			int mid=(L+R+1)>>1;
			node now=query(1,n,SGT::R[mid],l,r);
			(now.len<k)?R=mid+1:L=mid;
		}
		cout<<L<<'\n';
	}
	return 0;
}
