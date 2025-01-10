#include<bits/stdc++.h>
using namespace std;
int T,mod=1e9+7;
long long n,m,v,c,d,zs=1;
int main()
{
	cin>>T;
	while(T--)
	{
		cin>>n>>m>>v;
		for(int i=1;i<=n;i++)
			cin>>c>>d;
		while(v--)
		{
			zs=zs*(n-1)%mod;
		}
		cout<<zs<<endl;
	}
	return 0;
}
