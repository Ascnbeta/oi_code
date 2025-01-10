#include<bits/stdc++.h>
using namespace std;
#define N 100005
#define mod 1000000007
typedef long long ll;
int c,t,n,k,d[N],a[N],x[N],y[N],root;
ll jc[N],ans;
vector<int>G[N];
ll fpow(ll a,ll b){
	ll r=1;
	while(b){
		if(b&1)r=r*a%mod;
		a=a*a%mod;
		b=b>>1;
	}
	return r;
}
namespace sub1{
	void solve(){
		for(int i=1;i<=n;++i)--d[i];
		ans=1;
		for(int i=1;i<=n;++i)ans=ans*jc[d[i]]%mod;
		printf("%lld\n",ans);
	}
}
namespace sub2{
	void solve(){
		printf("1\n");
	}
}
namespace sub3{
	void solve(){
		ll ans=0;
		for(int i=1;i<=k;++i){
			ans=(ans+(i&1?1:-1)*jc[n-i-1]*jc[k]%mod*fpow(jc[k-i],mod-2)%mod*fpow(jc[i],mod-2)%mod+mod)%mod;
		}
		printf("%lld\n",ans);
	}
}
int main(){
	freopen("traverse.in","r",stdin);
	freopen("traverse.out","w",stdout);
	jc[0]=1;
	for(int i=1;i<N;++i)jc[i]=jc[i-1]*i%mod;
	int u,v;
	scanf("%d%d",&c,&t);
	while(t--){
		scanf("%d%d",&n,&k);
		for(int i=1;i<n;++i){
			scanf("%d%d",&u,&v);
			++d[u];++d[v];
			G[u].push_back(v);
			G[v].push_back(u);
			x[i]=u;y[i]=v;
		}
		for(int i=1;i<=k;++i)scanf("%d",&a[i]);
		if(c<=6)sub1::solve();
		else if(c==18)sub2::solve();
		else if(c>=19&&c<=21)sub3::solve();
		for(int i=1;i<=n;++i){
			d[i]=0;
			G[i].clear();
		}
	}
	return 0;
}
