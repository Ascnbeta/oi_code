#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
const int mo=1e9+7;
int T,c,n,k,v[N];
inline int read()
{
	int x=0,f=1;
	char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-') f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-48;ch=getchar();}
	return x*f;
}
void traverse(int x)
{
	v[x]=1;
}
int main()
{
	freopen("traverse.in","r",stdin);
	freopen("traverse.out","w",stdout);
	c=read();
	T=read();
	while(T--)
	{
		int ans=0;
		n=read();
		k=read();
		int u[N],v[N],e;
		for(int i=1;i<n;i++)
		{
			u[i]=read();
			v[i]=read();
		}
		for(int i=0;i<k;i++)
		{
			e=read();
			memset(v,0,sizeof(v));
			traverse(e);
		}
		ans%=mo;
		printf("%d\n",&ans);
	}
	return 0;
}
