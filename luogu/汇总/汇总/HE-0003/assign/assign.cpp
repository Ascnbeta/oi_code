#include <cstdio>
#include <utility>
#include <algorithm>
#define M 1000000007
#define ll long long
using namespace std;
ll P(ll x, ll y)
{
	ll q = 1;
	for(;y;y >>= 1, x = x * x % M)
		if(y & 1)
			q = q * x % M;
	return q;
}
ll T, n, m, v;
pair<ll, ll> a[1000050];
int main()
{
	freopen("assign.in", "r", stdin);
	freopen("assign.out", "w", stdout);
	scanf("%lld", &T);
	while(T--)
	{
		scanf("%lld%lld%lld", &n, &m, &v);
		for(ll i = 1;i <= m;++i)
			scanf("%lld%lld", &a[i].first, &a[i].second);
		sort(a + 1, a + m + 1);
		ll z = P(v, 2 * (a[1].first - 1)) * P(v, 2 * (n - a[m].first)) % M;
		for(ll i = 2;i <= m;++i)
		{
			if(a[i].first == a[i - 1].first)
			{
				if(a[i].second == a[i - 1].second)
					continue;
				else
				{
					z = 0;
					break;
				}
			}
			else
			{
				ll d = a[i].first - a[i - 1].first;
				z = z * (P(v, 2 * d) + M - (v - 1) * P(v, d - 1) % M) % M; 
			}
		}
		printf("%lld\n", z);
	}
	return 0;
}
