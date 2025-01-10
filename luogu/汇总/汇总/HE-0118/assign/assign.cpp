#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e5+10,mod=1e9+7;
int T,n,m,v,ans;
struct node
{
	int p,w;
	bool operator < (node x)
		const{return p<x.p;}
}a[N];
inline int Pow(int x,int y)
{
	int res=1;
	while(y)
	{
		if(y&1)
			res=res*x%mod;
		x=x*x%mod;
		y>>=1;
	}
	return res;
}
signed main()
{
	freopen("assign.in","r",stdin);
	freopen("assign.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin>>T;
	while(T--)
	{
		cin>>n>>m>>v;
		for(int i=1,x,y;i<=m;i++)
			cin>>a[i].p>>a[i].w;
		sort(a+1,a+m+1);
		ans=Pow(v,2*(a[1].p-1+n-a[m].p));
		int fl=0;
		for(int i=2;i<=m;i++)
		{
			if(a[i-1].p==a[i].p)
			{
				fl|=(a[i-1].w!=a[i].w);
				continue;
			}
			ans=ans*((Pow(v,2*(a[i].p-a[i-1].p))+mod
					-Pow(v,a[i].p-a[i-1].p-1)*(v-1)%mod)%mod);
			ans%=mod;
		}
		cout<<(fl?0:ans)<<"\n";
	}
	return 0;
}
