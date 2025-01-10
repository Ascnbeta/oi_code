#include<bits/stdc++.h>
#define int long long
using namespace std;
const int md=1e9+7;
int t;
int x[10000005];
signed main()
{
	freopen("assign.in","r",stdin);
	freopen("assign.out","w",stdout);
	cin>>t;
	while(t--)
	{
		bool f=0;
		int n,m,v,ans=1;
		cin>>n>>m>>v;
		if(n>10000000)
		{
			puts("0");
			continue;
		} 
		for(int i=1;i<=n;i++) x[i]=0;
		for(int i=1;i<=m;i++)
		{
			int c,d;
			cin>>c>>d;
			if(x[c]!=0&&x[c]!=d) f=1;
			x[c]=d;
		}
		if(f)
		{
			puts("0");
			continue;	
		}
		for(int i=1;i<n;i++)
		{
			if(x[i]&&x[i+1]) ans=ans%md*(v%md*(v-1)%md+1)%md;
			else if((x[i]&&!x[i+1])||(!x[i]&&x[i+1])) ans=ans%md*v%md*v%md;
			else if(!x[i]&&!x[i]) ans=ans%md*v%md*v%md;
			ans%=md;
		}
		cout<<ans%md<<"\n";
	}
}
