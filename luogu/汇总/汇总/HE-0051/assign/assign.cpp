#include <bits/stdc++.h>
#define ll long long
#define ts cout<<"*************"<<endl;
#define pb push_back
#define file(x) freopen(x".in","r",stdin),freopen(x".out","w",stdout);
using namespace std;
const int N =2e5+5,mod=1e9+7;
inline ll read(){
	ll x=0,f=1;char ch=getchar();
	for(;ch<'0'||ch>'9';ch=getchar())if(ch=='-')f=-f;
	for(;ch>='0'&&ch<='9';ch=getchar())x=(x<<3)+(x<<1)+(ch^48);
	return x*f;
}
inline void write(ll x){
	if(x<0)putchar('-'),x=-x;
	if(x>9)write(x/10);
	putchar((x%10)|48);
}
inline void write(ll x,char p){
	write(x);putchar(p);
}
bool Mbe;
ll n,m,v,jie[N],inv[N];
inline ll qpow(ll a,ll b){
	ll ans=1;
	while(b){
		if(b&1)ans=ans*a%mod;
		a=a*a%mod;b>>=1;
	}
	return ans;
}
inline ll C(int n,int m){
	return jie[n]*inv[m]%mod*inv[n-m]%mod;
}
ll dp[105][105][105];
map <int,int> mp;
inline void solve(){
	n=read();m=read();v=read();
	bool il=1;mp.clear();
	int has=0;
	for(int i=1;i<=m;i++){
		int x=read(),y=read();
		if(mp.find(x)!=mp.end()&&mp[x]!=y)il=0;
		if(mp.find(x)==mp.end())has++;
		mp[x]=y;
	}
	if(!il){
		write(0,'\n');return;
	}
	if(m<=1){
		write(qpow(v*v%mod,n-1),'\n');
		return;
	}
	// cout<<m<<" "<<has<<endl;
	if(m==n&&has==n){
		// ts;
		// ll ans=qpow((v-1)*(v-1)%mod,n-1);
		// // write(qpow(v*v%mod,n-1),'\n');
		// jie[0]=1;inv[0]=1;
		// for(int i=1;i<=n;i++)jie[i]=jie[i-1]*i%mod;
		// inv[n]=qpow(jie[n],mod-2);
		// for(int i=n-1;i>=1;i--)inv[i]=inv[i+1]*(i+1)%mod;
		// for(ll i=1;i<n;i++){
		// 	ans+=qpow((v-1)*(v-1),i)*C(n,i)%mod;
		// 	ans%=mod;
		// 	// ans=(ans+mod)%mod;
		// }
		// write(ans,'\n');
		// return;
	}
	ll ans=0,sum=0;
	memset(dp,0,sizeof dp);
	if(mp[1]&&mp[2]){
		dp[1][mp[1]][mp[2]]=1;sum++;
		for(int a=1;a<=v;a++){
			if(a==mp[1])continue;
			for(int b=1;b<=v;b++){
				dp[1][a][b]=1;sum++;
			}
		}	
	}else{
		for(int a=1;a<=v;a++){
			for(int b=1;b<=v;b++){
				dp[1][a][b]=1;sum++;
			}
		}		
	}
	for(int i=2;i<=n-1;i++){
		if(mp[i]&&mp[i+1]){
			for(int b=1;b<=v;b++){
				dp[i][mp[i]][mp[i+1]]+=dp[i-1][b][mp[i]];
				// for(int a=1;a<=v;a++){
					// dp[i][mp[i]][mp[i+1]]+=dp[i-2][a][mp[i]];
				// for(int b=1;b<=v;b++){
				// 	dp[i][mp[i]][mp[i+1]]+=dp[i-2][a][b];
				// }
				// }
			}

			for(int a=1;a<=v;a++){
				if(a==mp[i])continue;
				for(int b=1;b<=v;b++){
					dp[i][a][b]+=sum;
					dp[i][a][b]%=mod;
				}
			}
		}else{
			for(int a=1;a<=v;a++){
				for(int b=1;b<=v;b++){
					dp[i][a][b]+=sum;
					dp[i][a][b]%=mod;
				}
			}
		}
		sum=0;
		for(int a=1;a<=v;a++){
			for(int b=1;b<=v;b++){
				sum+=dp[i][a][b];sum%=mod;
			}
		}		
	}
	write(sum,'\n');
}	
bool Med;
int main(){
	file("assign");
	int T=read();
	// T=2;
	while(T--)
		solve();
	cerr<<(&Mbe-&Med)/1024.0/1024.0<<"MB "<<" "<<(double)clock()/CLOCKS_PER_SEC<<"ms\n";
	return 0;
}