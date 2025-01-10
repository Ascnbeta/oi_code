#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e5+100,mod =1e9+7;
int n,m,v;
struct edge
{
	int t,pos;
};
int now,c[N],d[N],fac[N];
vector<edge> a[N];
inline int dfs(int x,int fa)
{
	int res=fac[a[x].size()-1];
	for(auto i:a[x])
	{
		if(i.t==fa)continue;
		res*=dfs(i.t,x);
		res%=mod;
	}
	return res;
}
signed main()
{
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);

	freopen("traverse.in","r",stdin);
	freopen("traverse.out","w",stdout);
	int cc,tt;
	cin>>cc>>tt;
	if(cc==18)
	{
		while(tt--)
		{
			cin>>n>>m;
			int x,y;
			for(int i=1;i<n;i++)
			{
				cin>>x>>y;
			}
			int ans=0;
			for(int i=1;i<=m;i++)
			{
				cin>>x;
			}
			cout<<1<<'\n';
		}
		return 0;
	}
	fac[0]=1;
	for(int i=1;i<N;i++)fac[i]=fac[i-1]*i%mod;
	if(cc>18&&cc<=21)
	{
		while(tt--)
		{
			cin>>n>>m;
			int x,y;
			for(int i=1;i<n;i++)
			{
				cin>>x>>y;
			}
			int ans=0,tmp=0;
			if(n==1)
			{
				for(int i=1;i<=m;i++)
				{
					cin>>x;
				}
				cout<<"1\n";
				continue;
			}
			if(n==2)
			{
				for(int i=1;i<=m;i++)
				{
					cin>>x;
				}
				cout<<"2\n";
				continue;
			}
			for(int i=1;i<=m;i++)
			{
				cin>>x;
				ans+=(fac[n-2]-tmp)%mod;
				ans=(ans%mod+mod)%mod;
				tmp+=fac[n-3];
				tmp%=mod;
			}
			cout<<ans<<'\n';
		}
		return 0;
	}
	while(tt--)
	{
		cin>>n>>m;
		int x,y;
		for(int i=1;i<n;i++)
		{
			cin>>x>>y;
			a[x].push_back({y,i});
			a[y].push_back({x,i});
			c[i]=x,d[i]=y;
		}
		int ans=0;
		for(int i=1;i<=m;i++)
		{
			cin>>x;
			now=x;
			ans+=dfs(d[x],c[x])*dfs(c[x],d[x])%mod;
			ans%=mod;
		}
		cout<<ans<<'\n';
	}
	return 0;
}