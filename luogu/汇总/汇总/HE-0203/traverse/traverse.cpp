#include<bits/stdc++.h>
using namespace std;
long long c,T,n,k;
long long u[9999999],v[9999999],e[9999999];
int main()
{
	freopen("traverse.in","r",stdin);
	freopen("traverse.out","w",stdout);
	cin>>c>>T;
	for(long long i=1;i<=T;i++)
	{
		cin>>n>>k;
		for(long long j=1;j<=n-1;j++)
		{
			cin>>u[i]>>v[i];
		}
		for(long long j=1;j<=k;j++)
		{
			cin>>e[j];
		}
		cout<<(n+k)/2<<endl;
	}
	return 0;
}
