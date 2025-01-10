#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<vector>
#define ll long long
using namespace std;
const int MAXN=1e5+10,mod=1e9+7;
int c,T,n,k;ll P[MAXN];
namespace K1
{
	int x[MAXN],y[MAXN],e,d[MAXN];
	inline void work()
	{
		cin>>n>>k;ll ans=1;
		for(int i=1;i<=n;++i) d[i]=0;
		for(int i=1;i<n;++i)
			cin>>x[i]>>y[i],++d[x[i]],++d[y[i]];
		cin>>e;for(int i=1;i<=n;++i)
			ans=ans*P[d[i]-1]%mod;
		cout<<ans<<'\n';return ;
	}
	inline void Main()
		{while(T--) work();exit(0);}
}
namespace A
{
	inline void Main()
		{while(T--) cout<<"1\n";exit(0);}
}
namespace B
{
	inline void work()
	{
		cin>>n>>k;ll ans=1;
		for(int i=1,x,y;i<n;++i) cin>>x>>y;
		for(int i=1,e;i<=k;++i) cin>>e;
		if(n==2){cout<<"1\n";return ;}
		for(int i=1;i<=n-3;++i) ans=ans*i%mod;
		ans=(1ll*k*(k-1)/2+1ll*k*(n-1-k))%mod*ans%mod;
		cout<<ans<<'\n';return ;
	}
	inline void Main()
		{while(T--) work();exit(0);}
}
namespace Z
{
	int x[MAXN],y[MAXN],dep[MAXN],siz[MAXN];
	vector <int> v[MAXN];ll ans;
	inline int F(int x,int y)
	{
		if(x==1) return 1;
		return (1ll*y*(y-1)/2+1ll*y*(x-y))%mod*P[x-2]%mod;
	}
	void dfs(int x,int fa=0)
	{
		dep[x]=dep[fa]+1;
		for(int y:v[x])
			if(y!=fa) dfs(y,x);
	}
	void dfs_2(int x,int fa=0)
	{
		int cnt=0,sum=0;
		for(int y:v[x])
		{
			if(y==fa) continue;
			dfs_2(y,x),sum+=siz[y];
			if(siz[y]) ++cnt;
		}
		cnt+=(sum!=k);
		ans=ans*F(v[x].size(),cnt)%mod;
		siz[x]+=sum;
	}
	inline void work()
	{
		cin>>n>>k,ans=1;
		for(int i=1;i<=n;++i)
			v[i].clear(),siz[i]=0;
		for(int i=1;i<n;++i)
			cin>>x[i]>>y[i],
			v[x[i]].push_back(y[i]),
			v[y[i]].push_back(x[i]);
		dfs(1);
		for(int i=1,e;i<=k;++i)
			cin>>e,++siz[dep[x[e]]>dep[y[e]]?x[e]:y[e]];
		dfs_2(1);
		cout<<ans<<'\n';return ;
	}
	inline void Main()
		{while(T--) work();exit(0);}
}
signed main()
{
	freopen("traverse.in","r",stdin);
	freopen("traverse.out","w",stdout);
	cin.tie(0),cout.tie(0);
	ios::sync_with_stdio(0);
	n=100000,P[0]=1;
	for(int i=1;i<=n;++i)
		P[i]=P[i-1]*i%mod;
	cin>>c>>T;
	if(c<=6) K1::Main();
	if(c==18) A::Main();
	if(c>=19&&c<=21) B::Main();
	Z::Main();
	return 0;
}