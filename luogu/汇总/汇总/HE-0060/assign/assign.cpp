#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=1e5+10;
const ll mod=1e9+7;
int n,T,m;
int c[N],d[N],x[N],vis[N];
ll ans,v,f[N];
int ta[N],tb[N];
bool A,B;
void dfs(int nw,int f1,int f2)
{
	ta[nw]=f1;tb[nw]=f2;
	if(nw==n-1)
	{
		for(int i=1;i<n;++i)
		{
			if(x[i])
			{
				if(x[i]==ta[i]&&x[i+1]&&x[i+1]!=tb[i])return ;
				else if(x[i]==ta[i])x[i+1]=tb[i];
			}
		}
		for(int i=1;i<=n;++i)x[i]=vis[i];
		ans++;
		return ;
	}
	dfs(nw+1,1,1);
	if(v==2)dfs(nw+1,1,2),dfs(nw+1,2,1),dfs(nw+1,2,2);
}
int main()
{
	freopen("assign.in","r",stdin);
	freopen("assign.out","w",stdout);
	scanf("%d",&T);
	while(T--)
	{
		bool flg=true;A=true;
		ans=0;
		scanf("%d %d %lld",&n,&m,&v);
		for(int i=1;i<=100000;++i)x[i]=vis[i]=0;
		for(int i=1;i<=m;++i)
		{
			scanf("%d %d",&c[i],&d[i]);
			if(c[i]>1e5)continue;
			if(x[c[i]]&&x[c[i]]!=d[i])
			{
				flg=false;
				puts("0");
				break;
			}
			if(c[i]!=i)A=false;
			x[c[i]]=d[i];
			vis[c[i]]=d[i];
		}
		if(!flg)continue;
		if(v<=2)
		{
			dfs(1,1,1);
			if(v==2)dfs(1,2,1),dfs(1,1,2),dfs(1,2,2);
			printf("%lld\n",ans);
		}
		else if((A&&m==n))
		{
			ans=1;
			for(int i=1;i<n;++i)ans=ans*(((v-1)*v+1)%mod)%mod;
			printf("%lld\n",ans);
			continue;
		}
		else puts("0");
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
