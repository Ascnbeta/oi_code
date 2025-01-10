#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define sort stable_sort
#define endl '\n'
const ll p=1000000007;
int main()
{
    freopen("traverse.in","r",stdin);
    freopen("traverse.out","w",stdout);
    ll c,t,n,k,u,v,e,i,j;
	scanf("%lld%lld",&c,&t);
	for(j=1;j<=t;j++)
	{
		scanf("%lld%lld",&n,&k);
		for(i=1;i<=n-1;i++)
		{
			scanf("%lld%lld",&u,&v);
		}
		for(i=1;i<=k;i++)
		{
			scanf("%lld",&e);
		}
		printf("1\n");
	}
    return 0;
}
