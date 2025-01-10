#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define sort stable_sort
#define endl '\n'
const ll p=1000000007;
ll qpow(ll a,ll b,ll p)
{
	ll ans=1;
	while(b)
	{
		if(b&1)
		{
			ans=ans*a%p;
		}
		b>>=1;
		a=a*a%p;
	}
	return ans;
}
int main()
{
    freopen("assign.in","r",stdin);
    freopen("assign.out","w",stdout);
    ll t,n,m,v,c,d,ans=0,i,j;
	scanf("%lld",&t);
	for(j=1;j<=t;j++)
	{
		scanf("%lld%lld%lld",&n,&m,&v);
		for(i=1;i<=m;i++)
		{
			scanf("%lld%lld",&c,&d);
		}
		printf("%lld\n",qpow(v*(v-1)%p+1,n-1,p));
	}
    return 0;
}
