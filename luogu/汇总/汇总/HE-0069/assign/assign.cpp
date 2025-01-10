#include<bits/stdc++.h>
using namespace std;
#define int long long
const int mod = 1000000007;
int T;
struct limt{
	int i,d;
}l[100005];
bool f;
unordered_map <int,int> Map;
int n,m,v;
__int128 ans;
int qpow(int a,int x)
{
	__int128 t = a;
	ans = 1;
	while(x)
	{
		if (x & 1)
		{
			ans *= t;
			ans %= mod;	
		}
		t *= t;
		t %= mod;
		x >>= 1;
	}
	return ans % mod;
}
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("assign.in","r",stdin);
	freopen("assign.out","w",stdout);
	cin>>T;
	while(T--)
	{
		Map.clear();
		f = 0;
		cin>>n>>m>>v;
		for (int i = 1;i<=m;i++)
		{
			cin>>l[i].i >>l[i].d ;
			if (Map[l[i].i ]) f = 1;
			Map[l[i].i ] = l[i].d ;
		}
		if (f)
		{
			cout<<0<<"\n";
			continue;
		}
		if (m == 1)
		{
			cout<<qpow(v,2 * (n - 1))<<"\n";
		}
	}
	return 0;
}
