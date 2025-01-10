#include<bits/stdc++.h>

using namespace std;

const int MM = 25;
const int N = 5e5 + 10; 
const int M = N * 2;

int n,q;
int fa[MM][MM],dep[N];
int h[N],to[M],nxt[M],idx;

void Add(int a,int b)
{
	idx ++;
	to[idx] = b;
	nxt[idx] = h[a];
	h[a] = idx;
}

void bfs(int u,int ffa)
{
	for(int i = h[u];i;i = nxt[i])
	{
		int j = to[i];
		if(j == ffa) continue;
		dep[j] = dep[u] + 1;
		bfs(j,u);
		for(int k = 0;k <= 20;k ++)
			fa[j][k] = fa[fa[j][k - 1]][k - 1];
	}
}

int lca(int a,int b)
{
	if(a > b) swap(a,b);
	for(int k = 20;k >= 0;k --)
		if(dep[fa[a][k]] > dep[b]) a = fa[a][k];
	if(a == b) return a;
	for(int k = 20;k >= 0;k --)
	{
		if(fa[a][k] != fa[b][k])
		{
			a = fa[a][k];
			b = fa[b][k];
		}
	}
	return fa[a][0];
}

int main()
{
	freopen("query.in","r",stdin);
	freopen("query.out","w",stdout);
	scanf("%d",&n);
	for(int i = 1;i <= n - 1;i ++)
	{
		int u,v;
		scanf("%d%d",&u,&v);
		Add(u,v),Add(v,u);
	}
	scanf("%d",&q);
	dep[1] = 0;
	bfs(1,1);
	while(q --)
	{
		int Max = -1;
		int l,r,k;
		scanf("%d%d%d",&l,&r,&k);
		for(int i = l;i <= r;i ++)
		{
			for(int j = l;j <= r;j ++)
			{
				if(j - l < k) continue;
				Max = max(Max,lca(i,j));
			}
		}
		printf("%d\n",Max);
	}
	return 0;
}
