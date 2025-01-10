#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pii;
const ll N=1e5+5;
const ll mod=1e9+7;
inline ll qp(ll a,ll b,ll mod=mod){
	a%=mod;
	ll ans=1;
	while(b){
		if(b&1)ans=ans*a%mod;
		b>>=1;
		a=a*a%mod;
	}
	return ans;
}
ll T;
ll n,m,v;
pii a[N];
map<ll,ll> mp;
ll ans;
int main(){
	freopen("assign.in","r",stdin);
	freopen("assign.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>T;
	while(T--){
		ans=1;
		mp.clear();
		cin>>n>>m>>v;
		for(int i=1;i<=m;i++){
			cin>>a[i].first>>a[i].second;
			if(mp.count(a[i].first)&&mp[a[i].first]!=a[i].second)ans=-1;
			mp[a[i].first]=a[i].second;
		}
		if(ans==-1){
			cout<<"0\n";
			continue;
		}
		ll lst=0;
		for(auto &i:mp){
			if(lst){
				ll len=i.first-lst;
				ans=ans*(qp(v*v%mod,len)-qp(v,len-1)*(v-1)%mod+mod)%mod;
			}
			else{
				ans=ans*qp(v*v%mod,i.first-1)%mod;
			}
			lst=i.first;
		}
		if(lst!=n)ans=ans*qp(v*v%mod,n-lst)%mod;
		cout<<ans<<"\n";
	}
	return 0;
}
/*
1
4 3 2
1 2
3 2
4 2
*/
