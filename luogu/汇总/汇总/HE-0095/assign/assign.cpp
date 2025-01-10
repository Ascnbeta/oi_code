#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
const long long mod=1e9+7;
long long n,m,T,v;
long long c[N],d[N];
int main(){
	freopen("assign.in","r",stdin);
	freopen("assign.out","w",stdout);
	scanf("%lld",&T);
	while(T--){
		scanf("%lld%lld%lld",&n,&m,&v);
		long long ans=1;
		for(int i=1;i<n;i++){
			ans=(((((ans*v)%mod)*v)%mod)-v+1)%mod;
		}
		printf("%lld\n",ans);
	}
	return 0;
}
