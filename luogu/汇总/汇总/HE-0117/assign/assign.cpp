#include<bits/stdc++.h>
using namespace std;
const int maxm=1e5+9;
const int mod=1e9+7;
int T,n,m,v,jc[maxm],ny[maxm];
pair<int,int> pr[maxm];
inline int ksm(int a,int b){
	int res=1;
	for(;b;b>>=1,a=1ll*a*a%mod) if(b&1) res=1ll*res*a%mod;
	return res;
}
inline int C(int n,int m){return 1ll*jc[n]*ny[m]%mod*ny[n-m]%mod;}
int main(){
	freopen("assign.in","r",stdin);
	freopen("assign.out","w",stdout);
	scanf("%d",&T);jc[0]=1;
	for(int i=1;i<maxm;i++) jc[i]=1ll*jc[i-1]*i%mod;
	ny[maxm-1]=ksm(jc[maxm-1],mod-2);
	for(int i=maxm-1;i;i--) ny[i-1]=1ll*ny[i]*i%mod;
	while(T--){
		scanf("%d%d%d",&n,&m,&v);
		for(int i=1;i<=m;i++) scanf("%d%d",&pr[i].first,&pr[i].second);
		sort(pr+1,pr+m+1);
		int ans=ksm(v,(n-1)<<1),delta=0;
		for(int i=2;i<=m;i++){
			if(pr[i].first==pr[i-1].first&&pr[i].second^pr[i-1].second){
				ans=delta=0;
				break;
			}
			if(pr[i].first==pr[i-1].first+1){
				(ans-=1ll*(v-1)*ksm(v,(n-2)<<1)%mod-mod)%=mod;
				delta++;
			}
		}
		for(int i=2;i<=delta;i++){
			(ans+=1ll*(delta-1)*C(delta,i)%mod*ksm(v-1,i)%mod*ksm(v,(n-1-i)<<1)%mod)%=mod;
		}
		printf("%d\n",ans);
	}
	return 0;
}
