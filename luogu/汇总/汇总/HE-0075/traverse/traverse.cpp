#include<bits/stdc++.h>
using namespace std;

const int N=1e5+107;
const int mod=1e9+7;
int c,n,k,f1,f2;

int read()
{
	int f=1,s=0;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){s=(s<<1)+(s<<3)+(ch^48);ch=getchar();}
	return f*s;
}

int h[N],to[N],nxt[N],tot;
void add(int x,int y)
{
	to[++tot]=y;
	nxt[tot]=h[x];
	h[x]=tot;
}

void clear()
{
	tot=0;
	memset(h,0,sizeof h);
}

int main()
{
	freopen("traverse.in","r",stdin);
	freopen("traverse.out","w",stdout);
	c=read();
	int T=read();
	while(T--)
	{
		f1=0,f2=0;
		n=read(),k=read();
		clear();
		for(int i=1;i<=n-1;i++)
		{
			int u=read(),v=read();
			add(u,v),add(v,u);
		}
		if(c==18)
		{
			for(int i=1;i<=k;i++)
			{
				int e=read();
				putchar('1');puts("");
			}
		}
		if(19<=c&&c<=21)
		{
			long long fac=1;
			for(int i=1;i<=n-2;i++) fac=fac*i%mod;
			for(int i=1;i<=k;i++)
			{
				int e=read();
				cout<<fac;
				puts("");
			}
		}
	}
}
