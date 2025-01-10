#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,q;
int ST[500005][25];
int l,r,k;
int u,v;
int f[500005];
int tot;
__int128 jcc[25];
int logn[500005];
int dep[500005];
int ans;
int flag[500005];
queue<pair<int,int> > wait;
struct edge{
	int v,nxt;
}e[1000006];
void adde(int u,int v)
{
	tot++;
	e[tot].nxt = f[u];
	e[tot].v = v;
	f[u] = tot;
}
void dfs(int p,int fa)
{
	if (flag[p]) return;
	flag[p] = 1;
	for (int i = f[p];i;i = e[i].nxt )
	{
		if (e[i].v == fa) continue;
		dep[e[i].v ] = dep[p] + 1;
		wait.push({e[i].v ,p});
	}
}
void init(int n)
{
	jcc[0] = 1;
	int tt = 1;
	for (int i=2;i<=n;i++)
	{
		logn[i] = logn[i >> 1] + 1;
	}
	for (int i = 1;i<=20;i++)
	{
		tt <<= 1;
		jcc[i] = tt;
//		cout<<jc[i]<<"\n";
	}
	for (int i = 1;i <= n;i++)
	{
		ST[i][0] = dep[i];
	}
	for (int k = 1;k<=20;k++)
	{
		for (int i = 1;i<=n;i++)
		{
			ST[i][k] = max(ST[i][k - 1],ST[i + jcc[k - 1]][k - 1]);
		}
	}
}
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("query.in","r",stdin);
	freopen("query.out","w",stdout);
	cin>>n;
	for (int i = 1;i<=n;i++)
	{
		cin>>u>>v;
		adde(u,v);
		adde(v,u);
	}
	dep[1] = 1;
	dfs(1,0);
	while(!wait.empty())
	{
		dfs(wait.front().first,wait.front().second);
//		cout<<wait.size()<<"\n";
		wait.pop();
	}
//	init(n);
	cin>>q;
	while(q--)
	{
		ans = 0;
		cin>>l>>r>>k;
		for (int i=l;i<=r - k + 1;i++)
		{
			ans = max(ans,max(ST[i][logn[k]],ST[i + k - logn[k] - 1][logn[k]]));
		}
		cout<<ans<<"\n";
	}
	return 0;
}
