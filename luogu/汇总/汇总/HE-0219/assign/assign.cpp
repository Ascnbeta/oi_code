#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m,V,K1,K2,a[100010],dp[100010];
const int mod=1e9+7;
map<int,int> mp;
int q_pow(int x,int y){
	if(!y) return 1;
	int z=q_pow(x,y>>1);
	if(y&1) return z*z%mod*x%mod;
	else return z*z%mod;
}
signed main(){
	freopen("assign.in","r",stdin);
	freopen("assign.out","w",stdout);
	int T;
	cin>>T;
	while(T--){
		mp.clear();
		memset(dp,0,sizeof(dp));
		memset(a,0,sizeof(a));
		int x,y,f=0,tot=0;
		cin>>n>>m>>V;
		for(int i=1;i<=m;i++){
			cin>>x>>y;
			if(mp[x] && mp[x]!=y){
				f=1;
				continue;
			}
			if(!mp[x]) a[++tot]=x;
			mp[x]=y;
		}
		if(f){
			cout<<0<<endl;
			continue;
		}
		sort(a+1,a+tot+1);
		K1=(V*(V-1)+1)%mod;
		K2=V*V%mod;
		dp[1]=q_pow(K2,a[1]-1);
		for(int i=2;i<=tot;i++){
			if(a[i-1]==a[i]-1) dp[i]=dp[i-1]*K1%mod;
			else{
				int k=a[i]-a[i-1]-2;
				int x=(q_pow(V,2*k+1)-q_pow(V,k)+mod)*q_pow(V-1,mod-2)%mod;
				dp[i]=dp[i-1]*(x*(K1-1)%mod*K2%mod+K1*q_pow(V,k+1)%mod)%mod;
			}
		}
		if(a[tot]==n) cout<<dp[tot]<<endl;
		else{
			int k=n-a[tot]-1; 
			int x=(q_pow(V,2*k+1)-q_pow(V,k)+mod)*q_pow(V-1,mod-2)%mod;
			cout<<dp[tot]*(x*(K1-1)%mod+q_pow(V,k+1)%mod)%mod<<endl;
		}
	}
	return 0;
} 
