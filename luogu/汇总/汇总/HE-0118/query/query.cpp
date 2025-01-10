#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
int n,m,dis[N],dep[N];
int st[20][N],tot,ans[N];
vector<int>v[N];
struct node{int id,l,r;};
vector<node>q[N];
inline void dfs(int x,int fa)
{
	st[0][dis[x]=++tot]=fa;
	dep[x]=dep[fa]+1;
	for(auto y : v[x])
		if(y!=fa)
			dfs(y,x);
	return ;
}
inline int get(int x,int y)
{	return dis[x]<dis[y]?x:y;}
inline int lca(int x,int y)
{
	if(x==y)
		return x;
	if((x=dis[x])>(y=dis[y]))
		swap(x,y);
	int g=__lg(y-x++);
	return get(st[g][x],st[g][y-(1<<g)+1]);
}
int main()
{
	freopen("query.in","r",stdin);
	freopen("query.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin>>n;
	for(int i=2,x,y;i<=n;i++)
	{
		cin>>x>>y;
		v[x].push_back(y);
		v[y].push_back(x);
	}
	dfs(1,0);
	for(int i=1;i<=19;i++)
		for(int j=1;j+(1<<i)-1<=n;j++)
			st[i][j]=get(st[i-1][j],st[i-1][j+(1<<i-1)]);
	cin>>m;
	for(int i=1,l,r,k;i<=m;i++)
	{
		cin>>l>>r>>k;
		q[k].push_back({i,l,r});
	}
	for(int i=1;i<=n;i++)
		for(int j=i,g=i;j<=n;j++)
		{
			g=lca(g,j);
			for(auto it : q[j-i+1])
				if(it.l<=i&&j<=it.r)
					if(ans[it.id]<dep[g])
						ans[it.id]=dep[g];
		}
	for(int i=1;i<=m;i++)
		cout<<ans[i]<<"\n";
	return 0;
}
