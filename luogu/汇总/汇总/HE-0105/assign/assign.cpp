#include<bits/stdc++.h>
using namespace std;
const int M=1e5+1;
long long mod=1e9+7;
int t;
int a[M];
int main()
{
	freopen("assign.in","r",stdin);
	freopen("assign.out","w",stdout);
	cin>>t;
	while(t--)
	{
		memset(a,0,sizeof(a));
		int n,m,v;int k=1;
		cin>>n>>m>>v;
		for(int i=1;i<=m;i++)
		{
			int x,y;
			cin>>x>>y;
			a[x]=y;
			if(x!=i)
			{
				k=0;
			}
		}
		if(k==1)
		{
			long long temp=1+(v-1)*v;
			//temp%=mod;
			long long ans=(v-1)*temp;
			//ans%=mod;
			cout<<ans%mod<<endl;
		}
		
	}
	return 0;
}
