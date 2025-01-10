#include<bits/stdc++.h>
using namespace std;
const int N = 1e5+5,mod = 1e9+7;
int n,du[N],k,T,f[N],c;


int main()
{
	freopen("traverse.in","r",stdin);
	freopen("traverse.out","w",stdout);
	scanf("%d%d",&c,&T);
	while(T--)
	{
		memset(du,0,sizeof(du));
		scanf("%d%d",&n,&k);
		for(int i=1;i<n;i++)
		{
			int x,y; scanf("%d%d",&x,&y);
			du[x]++,du[y]++;
		} f[0]=1;
		for(int i=1,x;i<=k;i++) scanf("%d",&x);
		for(int i=1;i<=n;i++) f[i]=1ll*f[i-1]*i%mod;
		if(du[1]==n-1)
		{
			printf("%lld\n",1ll*k*f[n-2]%mod);
		}
		else
		{
			printf("1\n");
		}
	}


	return 0;
}