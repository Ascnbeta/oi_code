#include<bits/stdc++.h>
using namespace std;
const int mod=1e9+7;
int c[114514000],d[114514000];
int main()
{
	freopen("assign.in","r",stdin);
	freopen("assign.out","w",stdout);
	int T;
	cin>>T;
	while(T--)
	{
		int n,m,v;
		cin>>n>>m>>v;
		long long ans=1,aa=0;
		for(int i=1;i<=m;i++)
		{
			cin>>c[i]>>d[i];
			if(d[i]==1)aa++;
		}
		for(int i=1;i<=n;i++)
		{
			ans*=v;
			ans%=mod;
		}
		if(n==m&&aa==m)cout<<ans<<endl;
		else cout<<0<<endl;
	}
	return 0;
}
