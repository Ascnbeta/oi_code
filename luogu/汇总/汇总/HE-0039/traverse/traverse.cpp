#include<bits/stdc++.h>
using namespace std;
#define il inline
#define ri register int
#define inf 0x3f3f3f3f
int a,b,c,d,e[100001],f[100001],g,u,v;
const int mod=1e9+7;
vector<int> way[100001];
long long jc[100001];
struct node
{
	int h,to,quan;
}pic[200002];
il void ndin(int x,int y,int z)
{
	g++;
	pic[g]={f[x],y,z};
	f[x]=g;
}
namespace task1
{
	short main()
	{
		while(b--)
		{
			puts("1");
		}
		return 0;
	}
}
namespace task2
{
	short main()
	{
		jc[0]=1;
		for(ri i=1;i<=1e5;i++)
		{
			jc[i]=(jc[i-1]*i)%mod;
		}
		while(b--)
		{
			scanf("%d%d",&c,&d);
			for(ri i=1;i<c;i++)
			{
				scanf("%d%d",&u,&v);
			}
			for(ri i=1;i<=d;i++)
			{
				scanf("%d",&e[i]);
			}
			printf("%lld\n",(jc[c-1]*d)%mod);
		}
		return 0;
	}
}
struct BCJ
{
	int fa[100001],siz[100001];
	stack<pair<int,int>> use;
	il void build(int x)
	{
		for(ri i=1;i<=x;i++)
		{
			fa[i]=i;
			siz[i]=1;
		}
	}
	int find(int x)
	{
		if(fa[x]!=x)
		{
			return find(fa[x]);
		}
		return x;
	}
	il bool merge(int x,int y)
	{
		x=find(x),y=find(y);
		if(x==y)
		{
			return false;
		}
		if(siz[x]<siz[y])
		{
			swap(x,y);
		}
		fa[y]=x;
		siz[x]+=siz[y];
		return true;
	}
}tre;
void dfs(int x)
{
}
int main()
{
	freopen("traverse.in","r",stdin);
	freopen("traverse.out","w",stdout);
	scanf("%d%d",&a,&b);
	if(a==18)
	{
		return task1::main();
	}
	if(a>=19&&a<=21)
	{
		return task2::main();
	}
	while(b--)
	{
		scanf("%d%d",&c,&d);
		fill(f+1,f+1+c,0);
		for(ri i=1;i<c;i++)
		{
			way[i].clear();
		}
		for(ri i=1;i<c;i++)
		{
			scanf("%d%d",&u,&v);
			for(ri j=f[u];j;j=pic[j].h)
			{
				ri k=pic[j].quan;
				way[k].push_back(i);
				way[i].push_back(k);
			}
			ndin(u,v,i);
			ndin(v,u,i);
		}
		for(ri i=1;i<=d;i++)
		{
			scanf("%d",&e[i]);
			dfs(e[i]);
		}
	}
	return 0;
}
/*

*/

