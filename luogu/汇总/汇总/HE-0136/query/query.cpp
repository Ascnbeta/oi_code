#include<bits/stdc++.h>
using namespace std;

int n,q;
int head[500005],to[1000006],nxt[1000006],cnt;
int f[500005][21],deep[500005];

void add(int u,int v)
{
	++cnt;
	nxt[cnt] = head[u];
	head[u] = cnt;;
	to[cnt] = v;
}

void dfs(int u,int fa,int dp)
{
	deep[u] = dp;
	for(int i = head[u];i;i = nxt[i])
	{
		if(to[i] != fa)
		{
			f[to[i]][0] = u;
			dfs(to[i],u,dp + 1);
		}
	}
}

int lca(int x,int y)
{
	if(x == 1 or y == 1) return 1;
	if(deep[y] > deep[x]) swap(x,y);
	for(int i = 20;i >= 1 and deep[x] != deep[y];i--)
	{
		if(deep[f[x][i]] <= deep[y] and deep[f[x][i - 1]] > deep[y])
			x = f[x][i - 1];
	}
	if(deep[f[x][0]] == deep[y]) x = f[x][0];
	if(x == y) return x;
	for(int i = 20;i >= 0;i--)
	{
		if(f[x][i] != f[y][i])
			x = f[x][i],
			y = f[y][i];
	}
	return f[x][0];
}

int query(int _l,int _r,int _k)
{
	int ast,rt;
	for(int i = _l,j = _l + _k - 1;j <= _r;i++,j++)
	{
		ast = i;
		for(int dick = i + 1;dick <= j;dick++)
		{
			ast = lca(dick,ast);
			if(deep[ast]<= rt)
				break;
		}
		//cout<<i<<' '<<j<<' '<<_k<<ans<<' '<<ast<<' '<<deep[ans]<<' '<<deep[ast]<<'\n';
		rt = max(rt,deep[ast]);
	}
	return rt;
}

signed main()
{
	freopen("query.in","r",stdin);
	freopen("query.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	for(int i = 1,u,v;i < n;i++)
	{
		cin>>u>>v;
		add(u,v);
		add(v,u);
	}
	dfs(1,0,1);
	for(int i = 1;i <= 20;i++)
		for(int j = 1;j <= n;j++)
			f[j][i] = f[f[j][i-1]][i-1];
	cin>>q;
	for(int i = 1,l,r,k;i <= q;i++)
	{
		cin>>l>>r>>k;
		cout<<query(l,r,k)<<'\n';
	}
	return 0;
}