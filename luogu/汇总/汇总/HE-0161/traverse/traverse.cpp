#include<bits/stdc++.h>
#define I return
#define love 0
#define DLY ;
using namespace std;
const int maxn=1e5+10;
const int MOd=1e9+9;
/*
struct Egde
{
	int cnt=0,to;
	Edge (int a,int b)
	{
		cnt=a,to=b;
	}
};
*/
vector<int> g[maxn];
int n,k;
bool v[maxn];
int ans=0;int ccf=0;int Ans;
void dfs (int x)
{
	if (ccf>1) ans=ans+ccf-1;
	ccf=0;
	v[x]=1;
	for (int i=0;i<g[x].size();++i)
	{
		int y=g[x][i];
		if (v[y]==0)
		{
			dfs(y);
			ccf++;
		}
	}
}
int main()
{
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	//freopen("traverse.in","r",stdin);
	//freopen("traverse.out","w",stdout);
	int c,t;
	cin>>c>>t;
	while (t--)
	{
		cin>>n>>k;
		for (int i=1;i<n;++i)
		{
			int u,v;
			cin>>u>>v;
			g[u].push_back(v);
			g[v].push_back(u);
		}
		for (int i=1;i<=k;++i)
		{
			int e;
			cin>>e;
			dfs(e);
			Ans+=ans; 
		}
	}
	cout<<ans<<' '<<Ans;
	I love DLY
}
/*
7 1
5 2
1 2
1 3
2 4
2 5
1 3
*/
