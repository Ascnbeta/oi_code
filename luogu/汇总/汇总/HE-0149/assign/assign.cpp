#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll num=1e9+7;
ll t;
ll n,m,v,c,d;
int main()
{
	freopen("assign.in","r",stdin);
	freopen("assign.out","w",stdout);
	cin>>t;
	while(t--)
	{
		cin>>n>>m>>v;
		for(int i=1;i<=m;i++)
		cin>>c>>d;
		if(m==1)
		{int ans=v*pow(v*v,n-2)*2;
			cout<<ans%num<<"\n";
		}
		else cout<<0<<"\n";
	} 
	return 0;
}
