#include<bits/stdc++.h>
using namespace std;
const long long mod=1000000007;
inline long long qpow(long long x,long long y){
	long long answ=1,res=x;
	while(y){
		if(y&1)(answ*=res)%=mod;
		(res*=res)%=mod;
		y>>=1;
	}
	return answ;
}
long long T,n,m,v,ans,c,d,a[100001];
map<long long,long long>ma;
map<long long,long long>::iterator it;
void solve(){
	scanf("%lld%lld%lld",&n,&m,&v);
	ma.clear();ans=1;
	bool if_0=false;
	while(m--){
		scanf("%lld%lld",&c,&d);
		if(ma[c]!=0&&ma[c]!=d)if_0=true;
		else ma[c]=d;
	}
	m=0;
	if(if_0==true){
		printf("0\n");
		return;
	}
	for(it=ma.begin();it!=ma.end();++it)a[++m]=(it->first);
	for(long long i=1,k;i<m;++i){
		k=qpow(v,a[i+1]-a[i]-1);
		k=((v*v%mod*k%mod*k%mod-v*k%mod+mod)%mod+k)%mod;
		(ans*=k)%=mod;
	}
	printf("%lld\n",ans*qpow(v,(n-a[m]+a[1]-1)<<1)%mod);
}
int main()
{
	freopen("assign.in","r",stdin);
	freopen("assign.out","w",stdout);
	scanf("%lld",&T);
	while(T--)solve();
	return 0;
}
