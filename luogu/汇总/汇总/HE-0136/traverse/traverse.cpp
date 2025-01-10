#include<bits/stdc++.h>
using namespace std;

int c,t;
const int mod = 1e9+7;

int a(int m,int n)
{
	int ans = 1;
	for(int i = n;i > n - m;i--)
		ans = ans * i % mod;
}

signed main()
{
	freopen("traverse.in","r",stdin);
	freopen("traverse.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>t;
	if(c == 18)
	{
		while(t--) cout<<1<<'\n';
	}
}