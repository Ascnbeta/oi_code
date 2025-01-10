#include<bits/stdc++.h>
#define I return 
#define love 0
#define DLY ;
using namespace std;
const int maxn=1e5+10;
int n,q;
vector<int> g[maxn];
int v[maxn],dep[maxn],cnt;
void dfs (int x)
{
	cnt++;
	dep[x]=cnt;
	v[x]=1;
	for (int i=0;i<g[x].size();++i)
	{
		int y=g[x][i];
		if (v[y]==0)
		{
			dfs(y);
			cnt--;
		}
	}
}
int MIN (int l,int r,int k)
{
	int ans=0;
	for (int i=1;i<=l-r+1;++i)
	{
		if (dep[i]>k) dep[i]=0;
	}
	for (int i=1;i<=l-r+1;++i)
	{
		ans=max(ans,dep[i]);
	}	
	return ans;
}
int main()
{
	//freopen("query.in","r",stdin);
	//freopen("query.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n;
	for (int i=1;i<=n;++i)
	{
		int u,v;
		cin>>u>>v;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	cin>>q;
	for (int i=1;i<=q;++i)
	{
		int l,r,k;
		cin>>l>>r>>k;
		dfs(l);
		cout<<k;
	}
	I love DLY
}
