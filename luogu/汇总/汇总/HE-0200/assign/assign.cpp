#include<bits/stdc++.h>
using namespace std;
const int mod=1e9+7,N=1e2+3;
int T;
long long a[N],n,m,v,c,d,zs=1;
int main()
{
	freopen("assign.in","r",stdin);
	freopen("assign.out","w",stdout);
	cin>>T;
	while(T--)
	{
		bool x=0;
		cin>>n>>m>>v;
		memset(a,0,n+1);
		zs=1;
		for(int i=1;i<=m;i++)
		{
			cin>>c>>d;
			if(a[c]!=0)
			{
				cout<<0<<endl;
				x=1;
				break;
			}
			else
				a[c]=d;
		}
		if(x)
			continue;
		for(int i=1;i<n;i++)
		{
			if(a[i+1]==0)
				zs=zs*v*v%mod;
			else if(a[i+1]=0&&a[i]!=0)
					zs=zs*v%mod;
		}
		cout<<zs%mod<<endl;
	}
	return 0;
}
