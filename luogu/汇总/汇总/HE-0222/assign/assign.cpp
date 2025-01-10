#include<bits/stdc++.h>
using namespace std;
#define int long long
const int mod = 1e9 + 7;
int c[110000],d[110000];
map<int,int> mp;
int a[20],b[20],now[20];
int n,m,v;
signed main()
{
	freopen("assign.in","r",stdin);
	freopen("assign.out","w",stdout);
	int T;
	cin >> T;
	while(T--)
	{
		mp.clear();
		bool f = 1,vis = 0;
		cin >> n >> m >> v;
		for(int i = 1;i <= m;i++)
		{
			cin >> c[i] >> d[i];
			if(mp[c[i]] && mp[c[i]] != d[i])
			{
				vis = 1;
			}
			if(c[i] != i)
			{
				f = 0;
			}
			mp[c[i]] = d[i];
		}
		if(vis)
		{
			cout << 0 << endl;
			continue;
		}
		if(f && m == n)
		{
			int sum = 1;
			for(int i = 1;i <= n - 1;i++)
			{
				sum *= (v * (v - 1) + 1);
				sum %= mod;
			}
			cout << sum << endl;
			continue;
		}
		if(m == 1)
		{
			int ans = 1;
			for(int i = 1;i <= n - 1;i++)
			{
				ans *= v * v;
				ans %= mod;
			}
			cout << ans << endl;
			continue;
		}
	}
	return 0;
}
