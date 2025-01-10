#include<bits/stdc++.h>
using namespace std;
#define il inline
#define ri register int
#define inf 0x3f3f3f3f
int a,b,c,d,u[100001],v[100001],col[100001];
const int mod=1e9+7;
pair<int,int> tag[100001];
unordered_map<int,int> um;
long long num;
il long long qpow(long long x,long long y)
{
	register long long rn=1;
	while(y)
	{
		if(y&1)
		{
			rn=(rn*x)%mod;
		}
		x=(x*x)%mod;
		y>>=1;
	}
	return rn;
}
il void check()
{
	for(ri i=1;i<=b;i++)
	{
		col[i]=um[i];
	}
	for(ri i=1;i<b;i++)
	{
		if(col[i]==tag[i].first)
		{
			if(col[i+1]&&col[i+1]!=tag[i].second)
			{
				return;
			}
			col[i+1]=tag[i].second;
		}
	}
	num++;
	if(num==mod)
	{
		num=0;
	}
}
void dfs(int x)
{
	if(x==b)
	{
		check();
		return;
	}
	for(ri i=1;i<=d;i++)
	{
		for(ri j=1;j<=d;j++)
		{
			tag[x]={i,j};
			dfs(x+1);
		}
	}
}
int main()
{
//	freopen("assign2.in","r",stdin);
//	freopen("assign.out","w",stdout);
	freopen("assign.in","r",stdin);
	freopen("assign.out","w",stdout);
	scanf("%d",&a);
	while(a--)
	{
		scanf("%d%d%d",&b,&c,&d);
		um.clear();
		register bool ans=true;
		for(ri i=1;i<=c;i++)
		{
			scanf("%d%d",&u[i],&v[i]);
			if(um[u[i]]&&um[u[i]]!=v[i])
			{
				ans=false;
			}
			um[u[i]]=v[i];
		}
		if(c==1)
		{
			printf("%lld\n",qpow((d*d)%mod,b-1));
			continue;
		}
		if(!ans)
		{
			puts("0");
			continue;
		}
		num=0;
		dfs(1);
		printf("%lld\n",num);
	}
	return 0;
}
/*
3
2 1 2
1 1
2 2 2
1 1
2 2
2 2 2
1 1
1 2

4
3
0

1
10 11 2
10 2
7 2
7 2
2 2
3 2
4 2
10 2
7 2
10 2
3 2
3 2

*/

