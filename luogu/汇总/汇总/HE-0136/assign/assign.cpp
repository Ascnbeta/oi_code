#include<bits/stdc++.h>
using namespace std;

int t;
int n,m,v;
int c[100005];
bool flg1;
const int mod = 1e9 + 7;
/*
int qpow(long long a,long long b)
{
	long long ans = 1;
	while(b)
	{
		if(b & 1) ans = ans * a % mod;
		a = a * a % mod;
		b /= 2;
	}
	return (int)ans;
}
*/
signed main()
{
	freopen("assign.in","r",stdin);
	freopen("assign.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>t;
	while(t--)
	{
		flg1 = true;
		cin>>n>>m>>v;
		for(int i = 1;i <= m;i++)
		{
			cin>>c[i];
			if(c[i] != i) flg1 = false;
		}
		if(flg1)
		{
			cout<<1ll * (n-1) * ( (v * (v-1) % mod) + 1 % mod ) % mod<<'\n';
		}

	}
}
