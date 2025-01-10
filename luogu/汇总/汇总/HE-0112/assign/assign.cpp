#include<bits/stdc++.h>
using namespace std;
#define ll unsigned long long
const ll mod=1e9+7;
ll T,n,m,v;
map<ll,ll> ma;
bool ss[1000000005];
ll qp(ll x,ll y){
//	ll res=1;
//	while(x){
//		if(x&1)
//			y=(y+y*res)%mod;
//		x>>=1;
//		res=res*2;
//	}
	return y*x;
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("assign.in","r",stdin);
	freopen("assign.out","w",stdout);
	cin>>T;
	while(T--){
		ll ans=1;
		bool f=0;
		cin>>n>>m>>v;
//		v=v%mod;
		memset(ss,0,sizeof(ss));
		for(int i=1;i<=m;i++){
			ll x,y;
			cin>>x>>y;
			if(ma[x]!=0&&ma[x]!=y){
				cout<<0<<"\n";
				f=1;
				break;
			}
			ss[x]=1;
			ma[x]=y;
		}
		if(f)
			continue;
		for(int i=1;i<n;i++){
			ll cnt=1;
			if(ss[i]&&ss[i+1])
				cnt=(qp(v,v-1)+1+mod)%mod;
			else
				cnt=(qp(v,v)+mod)%mod;
			ans=(qp(ans,cnt)+mod)%mod;
		}
		cout<<ans<<"\n";
	}
	return 0;
}
