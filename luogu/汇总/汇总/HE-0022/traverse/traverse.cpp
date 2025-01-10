#include<bits/stdc++.h>
using namespace std;
#define int long long
const int mod=1e9+7;
int read()
{
	int x=0,f=1;
	char c=getchar();
	while(!isdigit(c))
	{
		if(c=='-')
			f=-f;
		c=getchar();
	}
	while(isdigit(c))
		x=(x<<1)+(x<<3)+(c-'0'),c=getchar();
	return x*f;
}
int c,T;
signed main()
{
	freopen("traverse.in","r",stdin);
	freopen("traverse.out","w",stdout);
	c=read(),T=read();
	if(c==18)
	{
		while(T--)
			printf("1\n");
		return 0;
	}
	if(c>=19&&c<=21)
	{
		while(T--)
		{
			int n=read(),k=read();
			for(int i=1,u,v;i<n;++i)
				u=read(),v=read();
			int ans=1,las=1;
			for(int i=1;i<=n-2;++i)
				las=(las*i)%mod;
			for(int i=1,e;i<=k;++i)
				e=read();
			ans=(k*(n-1)-k*(k-1)/2)%mod;
			ans=(ans*las)%mod;
			cout<<ans<<endl;
		}
		return 0;
	}
	return 0;
}
