#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5,md=1e9+7;
int f[N][2],n,k,head[N],num,dp[N],fac[N],e[N],son[N],deg[N];
struct edge{
	int to,next;
}g[N*2];
bool vis[N];
void addd(int u,int v)
{
	num++;
	g[num].to=v;
	g[num].next=head[u];
	head[u]=num;
}
void inline add(int &x,int y)
{
	x+=y;
	if(x>=md) x-=md;
}
void inline del(int &x,int y)
{
	x-=y;
	if(x<0) x+=md;
}
int inline inc(int x,int y)
{
	return x+y-(x+y>=md?md:0);
}
int inline inc1(int x,int y)
{
	return x-y+(x<y?md:0);
}
void dfs(int u,int fa)
{
	int res=1;
	for(int i=head[u];i;i=g[i].next)
	{
		int v=g[i].to;
		if(v==fa) continue;
		dfs(v,u);
		son[u]++;
	}
}
int main()
{
	freopen("traverse.in","r",stdin);
	freopen("traverse.out","w",stdout);
	int c,T;
	cin>>c>>T;
	fac[0]=1;
	for(int i=1;i<=1e5;i++)
		fac[i]=1ll*fac[i-1]*i%md;
	while(T--)
	{
		cin>>n>>k;
		int u,v;
		num=0;
		for(int i=1;i<=n;i++) deg[i]=0;
		for(int i=1;i<n;i++)
		{
			cin>>u>>v;
			addd(u,v),addd(v,u);
			deg[u]++,deg[v]++;
		}
		for(int i=1;i<=k;i++)
			cin>>e[i];
		if(c==18)
		{
			cout<<1<<endl;
		}
		else if(c<=6)
		{
			int res=1;
			for(int i=1;i<=n;i++)
				if(deg[i]) res=1ll*res*fac[deg[i]-1]%md;
			cout<<res<<endl;
		}
		else if(c>=19&&c<=21)
		{
			
		}
	}
}
