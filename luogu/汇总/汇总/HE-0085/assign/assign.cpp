#include<bits/stdc++.h>
using namespace std;
#define int long long
const int mod=1e9+7;
int n,m,v;
int qp(int a,int b)
{
	// cout<<a<<' '<<b<<endl;
	int res=1;
	while(b){
		if(b&1)res=res*a%mod;
		b>>=1;a=a*a%mod;
	}
	return res;
}
signed main()
{
	freopen("assign.in","r",stdin);
	freopen("assign.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T;
	cin>>T;
	int cnt=0;
	while(T--)
	{
		// cnt++;
		cin>>n>>m>>v;

		bool Fa=1;
		for(int i=1;i<=m;i++)
		{
			int a,b;
			// cin>>q[i].c>>q[i].d;
			// if(q[i].c!=i) Fa=0;
			cin>>a>>b;
		}
		if(m==1)
		{
			// cout<<n<<' '<<m<<' '<<v<<endl;
			cout<<qp(v%mod,2*(n-1+mod)%mod)%mod<<endl;;
		}
		else if(m==n)
		{
			// cout<<qp(v,2*(n-1)%mod)-(qp((v-1)%mod,(n-1))+mod)%mod+mod<<endl;
			cout<<qp((v-1)*(v+1)%mod,(n-1))<<endl;
		}
		else
		{
			cout<<0<<endl;
		}
	}	
}
