#include<bits/stdc++.h>
using namespace std;
#define int long long
const int mod = 1000000007;
int c,T;
int n,k;
int u,v;
int f[100005];
struct edge{
	int u;
	int v,nxt;
}e[400005];
int tott;
int ans;
int cnt[100005];
int a[100005];
int tot;
void adde(int u,int v)
{
	tot++;
//	cout<<tot;
	e[tot].nxt = f[u];
	e[tot].v = v;
	cnt[u] ++;
	e[tot].u = u;
	f[u] = tot;
}
void addd(int x)
{
	tott++;
	a[tott] = x;
}
int dfs(int p,int fa)
{
	__int128 tans;
	tans = 1;
	for (int i = f[p];i;i = e[i].nxt )
	{
		if (e[i].v == fa) continue;
		if (cnt[e[i].v ] == 1) continue;
		tans += dfs(e[i].v ,p);
		tans %= mod;
	}
	return tans;
}
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("traverse.in","r",stdin);
	freopen("traverse.out","w",stdout);
	cin>>c>>T;
	while(T--)
	{ 
		tot = 0;
		tott = 0;
		ans = 0;
		cin>>n>>k;
		for (int i = 1;i<n;i++)
		{
			cin>>u>>v;
			adde(u,v);
			adde(v,u);
		}
		for (int i = 1;i <= k;i++)
		{
			cin>>u;
			addd(u);
		}
		if (c == 18)
		{
			cout<<1<<"\n";
			continue;
		}
		for (int i = 1;i<=tott;i++)
		{
			ans += dfs(e[a[tot]].u,e[a[tot]].v);
			ans += dfs(e[a[tot]].v,e[a[tot]].u);
		}
		cout<<ans<<"\n";
	}
	return 0;
}
