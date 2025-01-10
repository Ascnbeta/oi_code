#include"bits/stdc++.h"
#define re register
#define int long long
using namespace std;
const int maxn=1e5+10,mod=1e9+7;
int n,k,ans;
int id[maxn];
bitset<maxn> vis;
struct EDGE{
	int u,v;
}t[maxn];
inline void solve1(){cout<<1<<'\n';}
inline int qpow(int a,int b){
	int res=1;
	while(b){
		if(b&1) res=res*a%mod;
		b>>=1;
		a=a*a%mod;
	}
	return res;
}
inline int Inv(int x){return qpow(x,mod-2);}
inline void solve2(){
	int fac=1;
	for(re int i=1;i<=n-2;++i) fac=fac*i%mod;
	cout<<k*fac%mod<<'\n';
}
inline void dfs(int now,int num){
	if(num==n-1){
		++ans;
		if(ans>=mod) ans-=mod;
		return;
	}
	for(re int i=1;i<n;++i){
		if(vis[i]) continue;
		if(i==now) continue;
		if(t[now].u==t[i].u||t[now].u==t[i].v||t[now].v==t[i].u||t[now].v==t[i].v){
			vis[i]=1;
			dfs(i,num+1);
			vis[i]=0;
		}
	}
}
inline void solve3(){
	ans=0;
	for(re int i=1;i<n;++i) vis[i]=0;
	vis[id[k]]=1;
	dfs(id[k],1);
	cout<<ans<<'\n';
}
inline void solve(){
	cin>>n>>k;int tot1=0,tot2=0;
	for(re int i=1;i<n;++i){
		cin>>t[i].u>>t[i].v;
		if(t[i].u==i&&t[i].v==i+1) ++tot1;
		if(t[i].u==1&&t[i].v==i+1) ++tot2;
	}
	for(re int i=1;i<=k;++i) cin>>id[i];
	if(n<=5) solve3();
	else if(tot1==n-1) solve1();
	else if(tot2==n-1) solve2();
	else cout<<0<<'\n';
}
signed main(){
	freopen("traverse.in","r",stdin);
	freopen("traverse.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int T,type;cin>>type>>T;while(T--) solve();
	return 0;
}

