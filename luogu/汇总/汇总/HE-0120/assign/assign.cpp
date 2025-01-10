#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=1e5+5;
const ll mod=1e9+7;
ll n,m;
ll v;
ll ans=1;
ll c[N],d[N];
inline ll qpow(ll a,ll b){
	ll res=1ll;
	while(b){
		if(b&1) res=(res*a)%mod;
		a=(a*a)%mod;
		b>>=1;
	}
	return res;
}
map<ll,ll> mp;
int vis[15]={};
int a[15],b[15];
inline void dfs(int node){
	if(node>=n){
		ans=(ans+1)%mod;
		return;
	}
	for(int i=1;i<=2;i++){
		for(int j=1;j<=2;j++){
			if(vis[node]==i){
				if(vis[node+1]!=j) continue;
				int t=vis[node+1];
				vis[node+1]=j;
				dfs(node+1);
				vis[node+1]=t;
			}else{
				dfs(node+1);
			}
		}
	}
}

inline void solve(){
	int flag=0;
	mp.clear();
	for(int i=1;i<=12;i++) vis[i]=0;
	scanf("%lld%lld%lld",&n,&m,&v);
	for(ll i=1;i<=m;i++){
		scanf("%lld%lld",&c[i],&d[i]);
		if(n<=12){
			vis[c[i]]=d[i];
		}
		if(mp[c[i]]!=0&&mp[c[i]]!=d[i]){
			puts("0");
			return;
		}
		mp[c[i]]=d[i];
		if(c[i]!=i) flag=1;
	}
	if(m==1){
		ans=qpow(v*v%mod,n-1);
		printf("%lld\n",ans);
		return;
	}else if(!flag){
		for(int i=1;i<n;i++){
			ans=(ans*1)%mod;
		}
		printf("%lld\n",ans);
		return;
	}else if(v==2&&n<=12){
		dfs(1);
		cout<<ans<<endl;
	}
}

int main(){
	freopen("assign.in","r",stdin);
	freopen("assign.out","w",stdout);
	int _;
	scanf("%d",&_);
	while(_--) solve();
	return 0;
}
