#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e5+100,mod =1e9+7;
int n,m,v;
struct qes
{
	int x,y;
	inline bool operator<(const qes z)const
	{
		return x<z.x;
	}
}a[N];
inline int qpow(int x,int y)
{
	int res=1;
	while(y)
	{
		if(y&1)res=res*x%mod;
		x=x*x%mod;
		y>>=1;
	}
	return res;
}
signed main()
{
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	// cerr<<(qpow(954048,74580*2)*qpow(954048,(529220-74582)*2)%mod*(954048-1)%mod)
	freopen("assign.in","r",stdin);
	freopen("assign.out","w",stdout);
	int tt,x,y;
	cin>>tt;
	while(tt--)
	{
		cin>>n>>m>>v;
		// cerr<<n<<' '<<m<<' '<<v<<'\n';
		for(int i=1;i<=m;i++)
		{
			cin>>x>>y;
			a[i]={x,y};
		}
		sort(a+1,a+1+m);
		int ans=qpow(v,2*a[1].x-2);
		int tmp,all;
		for(int i=2;i<=m;i++)
		{
			if(a[i].x==a[i-1].x)
			{
				if(a[i].y==a[i-1].y)continue;
				ans=0;
				break;
			}
			tmp=1;
			// cerr<<i<<' '<<a[i].x<<' '<<a[i-1].x<<'\n';
			tmp=qpow(v,(a[i].x-a[i-1].x-1))*(v-1)%mod;
			all=qpow(v,2*(a[i].x-a[i-1].x));
			// cerr<<tmp<<' '<<all<<'\n';
			all=((all-tmp)%mod+mod)%mod;
			ans=(ans*all)%mod;
			// cerr<<i<<' '<<tmp<<' '<<all<<'\n';
		}
		// cerr<<ans<<'\n';
		ans=(ans*qpow(v,2*(n-a[m].x)))%mod;
		cout<<ans<<'\n';
	}
	return 0;
}