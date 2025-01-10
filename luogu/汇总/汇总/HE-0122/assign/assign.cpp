#include <bits/stdc++.h>
#define ll long long 
using namespace std;
const int maxm = 1e5+10;
const long long mod = 1e9+7;
ll p(ll a,ll b)
{
	if(b==0) return 1;
	if(b==1) return a;
	if(b%2==1) return p(a,b-1) * a % mod;
	else {
		ll f = p(a,b/2) % mod;
		return f*f % mod;
	}
}
ll n,m,v;
ll c[maxm],d[maxm];
ll st[maxm],tp;

void work()
{
	ll ans = 1;
	memset(st,0,sizeof(st));
	tp = 0;
	cin >> n >> m >> v;
	int flagA = (n == m);
	int flagC = 0;
	map<int, int> mp;
	int cnt = 0;
	for(int i =1;i<=m;i++)
	{
		cin >> c[i] >> d[i];
		if (mp.count(c[i]) and mp[c[i]] != d[i]) flagC = 1;
		if (mp[c[i]] == d[i]) cnt ++;
		else st[++tp] = c[i];
		mp[c[i]] = d[i];
		if(c[i] != i) flagA = 0;
	}
	//flog
	if(flagC == 1)
	{
		cout << 0 << endl;
		return ;
	}
	//20pts
	if(m-cnt == 1)
	{
		
		ll tmp = v*v % mod;
		
		ans = p(tmp,n-1)%mod;
		cout << ans << endl;
		return ;	
	}
	// 20 pts;
	//flagA = 1;
	if(flagA)
	{
		ll tmp = (v*(v-1) + 1)% mod ;
		ans = p(tmp,n-1) % mod;
		cout << ans << endl;
		return ;
	}
	sort(st+1,st+tp+1);
	for(int i = 1;i<tp;i++)
	{
		//cout << " " << (st[i+1]-st[i])*2-1 << endl;
		ll tmp = (p(v,(st[i+1]-st[i]+1))-1)% mod;

		tmp *= p(v,st[i+1]-st[i]-1) ;
		tmp = tmp % mod;
		//cout << tmp << endl;
		ans = ans * tmp % mod;
	}
	ans *= p(v*v % mod,st[1]-1) % mod ;
	ans = ans % mod;
	ans *= p(v*v % mod,n- st[tp]);
	ans = ans % mod;
	cout << ans << endl;
	return;
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("assign.in","r",stdin);
	freopen("assign.out","w",stdout);
	//cout << p(2,31) << endl;
	int tt;
	cin >> tt;
	while(tt --)
	{
		work();
	}
	return 0;
}
