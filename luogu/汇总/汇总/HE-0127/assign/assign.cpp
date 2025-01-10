//++RP++RP++RP++RP++RP
#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll maxn = 1e5+10;
//ll c[maxn],d[maxn];
struct X{
	ll c,d;
	bool operator <(const X x) const{
		return c < x.c;
	}
}c[maxn];
const ll mod = 1e9+7;
ll n, m, v;
inline ll qpow(ll x,ll y){
	if(y < 0) return 1;
	ll base = x % mod,ans = 1;
	while(y){
		if(y & 1){
			ans *= base;
			ans %= mod;
		}
		base *= base;
		base %= mod;
		y >>= 1;
	}
	return ans % mod;
}
ll ans;
int main(){
	freopen("assign.in","r",stdin);
	freopen("assign.out","w",stdout);
	ll T;
	cin>>T;
	while(T --> 0){
		cin>>n>>m>>v;
		for(ll i = 1;i <= m;i++){
			cin>>c[i].c>>c[i].d;
		}
		
		sort(c+1,c+m+1);
		bool flag = false;
		for(ll i = 1;i < m;i++){
			if(c[i].c == c[i+1].c && c[i].d != c[i+1].d){
				flag = true;
				break;
			}
		}
		if(flag){
			cout<<0<<endl;
			continue;
		}
		
		
		if(c[1].c == 1) ans = 1;
		else{
			ans = qpow(v * (v - 1) * v , c[1].c - 2) 
			* ((v + (v - 1) * v) % mod);
			ans %= mod;
		}
		
		for(ll i = 2;i <= m;i++){
			if(c[i].c - c[i-1].c == 1){
				ans *= 1 + (v - 1) * v;
				ans %= mod;
			} 
			else{
				ans *= ((v + (v - 1) * v) % mod)
				* qpow(v + (v - 1) * v , c[i].c - c[i - 1].c - 2)
				* ((v + (v - 1) * v) % mod);
				ans %= mod;
			}
		}
		
		if(n - c[m].c == 0){
			ans *= 1ll;
		}
		else{
			ans *= qpow(v + (v - 1) * v,n - c[m].c - 1ll)
			* ((v + (v - 1) * v) % mod);
		}
		
		cout<<ans % mod<<endl;
	}
}
