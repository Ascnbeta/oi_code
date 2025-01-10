#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

const int Mod = 1e9 + 7;
const int N = 1e5 + 10;
const int M = N * 2;

ll n,k,ans;
ll e[N];
ll h[N],to[M],nxt[M],idx;

void Add(ll a,ll b)
{
	idx ++;
	to[idx] = b;
	nxt[idx] = h[a];
	h[a] = idx;
}

void dfs(ll u)
{
	ll tim = 0;
	for(ll i = h[u];i;i = nxt[i])
	{
		ll j = to[i];
		for(ll k = h[j];k;k = nxt[k])
		{
			ll l = to[k];
			if(l != u) ans ++;
		}
	}
}

int main()
{
	freopen("traverse.in","r",stdin);
	freopen("traverse.out","w",stdout);
	ll c,T;
	scanf("%lld%lld",&c,&T);
	while(T --)
	{
		scanf("%d%d",&n,&k);
		for(ll i = 1;i <= n - 1;i ++)
		{
			ll u,v;
			scanf("%lld%lld",&u,&v);
			Add(u,v),Add(v,u);
		}
		for(ll i = 1;i <= k;i ++)
			scanf("%lld",&e[i]);
		for(ll i = 1;i <= k;i ++)
			dfs(e[i]);
		printf("%lld\n",ans % Mod);
	}
	return 0;
}
/*
7 1
5 2
1 2
1 3
2 4
2 5
1 3
*/
