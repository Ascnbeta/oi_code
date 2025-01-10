#include<bits/stdc++.h>
using namespace std;

const int N=1e4+107;
const int mod=1e9+7;

int read()
{
	int f=1,s=0;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){s=(s<<1)+(s<<3)+(ch^48);ch=getchar();}
	return f*s;
}

int h[N<<1],to[N<<1],nxt[N<<1],tot;
void add(int x,int y)
{
	to[++tot]=y;
	nxt[tot]=h[x];
	h[x]=tot;
}

int dep[N],f[N][21];
void dfs(int u,int fa)
{
	dep[u]=dep[fa]+1;
	f[u][0]=fa;
	for(int i=1;i<=20;i++) f[u][i]=f[f[u][i-1]][i-1];
	for(int i=h[u];i;i=nxt[i])
	{
		int v=to[i];
		if(v==fa) continue;
		dfs(v,u);
	}
}

int lca(int x,int y)
{
	if(dep[x]<dep[y]) swap(x,y);
	for(int i=20;i>=0;i--)
	{
		if(dep[f[x][i]]>=dep[y]) x=f[x][i];
	}
	if(x==y) return x;
	for(int i=20;i>=0;i--)
	{
		if(f[x][i]!=f[y][i]) x=f[x][i],y=f[y][i];
	}
	return f[x][0];
}

int s[5010][5010];

int main()
{
	freopen("query.in","r",stdin);
	freopen("query.out","w",stdout);
	n=read();
	for(int i=1;i<=n-1;i++)
	{
		int u=read(),v=read();
		add(u,v),add(v,u);
	}
	dfs(1,1);
	for(int l=1;l<=n;l++)
	{
		int fa=l;
		for(int r=l;r<=n;r++)
		{
			s[l][r]=dep[lca(fa,r)];
		}
	}
	m=read();
	for(int i=1;i<=m;i++)
	{
		int li=read(),ri=read(),k=read();
		int ans=0;
		for(int len=k;len<=ri-li;len++)
		{
			for(int l=li;l+len-1<=ri;l++)
			{
				int r=l+len-1;
				ans=max(ans,s[l][r]);
			}
		}
		printf("%d\n",ans);
	}
}
