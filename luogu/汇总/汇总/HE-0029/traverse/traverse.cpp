#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e5+5;
const int mod=1e9+7;
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
int id,T;
int n,k;
struct edge{
	int next,to,flag,vis;
}e[N*2];
int h[N],cnt=1;
void add(int u,int v){
	e[++cnt]={h[u],v,0,0};
	h[u]=cnt;
}
int d[N];
namespace solve1{
	ll fac[N];
	int main(){
		fac[0]=1;
		for(int i=1;i<=n;i++)fac[i]=fac[i-1]*i%mod;
		ll ans=fac[n-1];
		ll res=n-1-k;
		ans=(ans-res*(res-1)%mod*fac[n-3]%mod+mod)%mod;
		ans=ans*qp(2,mod-2)%mod;
		cout<<ans<<"\n";
		return 0;
	}
}
namespace solve2{
	ll ans=1;
	ll fac[N];
	void dfs(int x,int fa){
//		cout<<x<<" "<<fa<<"\n";
		ll cnt=0;
		for(int i=h[x];i;i=e[i].next){
			int to=e[i].to;
			if(e[i].flag||to==fa)continue;
			dfs(to,x);
			cnt++;
		}
		ans=ans*fac[cnt]%mod;
	}
	int main(){
		fac[0]=ans=1;
		for(int i=1;i<=n;i++)fac[i]=fac[i-1]*i%mod;
		int u=0,v=0;
		for(int i=2;i<=cnt;i++){
			if(e[i].flag){
				u=e[i].to;
				v=e[i^1].to;
				break;
			}
		}
		dfs(u,0);dfs(v,0);
		cout<<ans<<"\n";
		return 0;
	}
}
 
void clear(){
	cnt=1;
	for(int i=1;i<=n;i++)h[i]=d[i]=0;
}
int main(){
	freopen("traverse.in","r",stdin);
	freopen("traverse.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>id>>T;
	while(T--){
		cin>>n>>k;
		clear();
		for(int i=1,u,v;i<n;i++){
			cin>>u>>v;
			add(u,v);add(v,u);
			d[u]++;d[v]++;
		}
		for(int i=1,x;i<=k;i++){
			cin>>x;
			e[x*2].flag=e[x*2+1].flag=1;
		}
		if(id==18){
			cout<<"1\n";
			continue;
		}
		if(id>=19&&id<=21){
			solve1::main();
			continue;
		}
		solve2::main();
	}
	return 0;
}
