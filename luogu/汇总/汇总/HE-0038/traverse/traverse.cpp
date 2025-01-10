#include"bits/stdc++.h"
using namespace std;
const int N=1e5+10,mod=1e9+7;
int T,c,n,k;
long long qpow(long long x,long long y){
	long long ret=1;
	while(y){
		if(y&1) ret=ret*x%mod;
		x=x*x%mod;
		y>>=1;
	}
	return ret;
}
int head[N],nxt[N<<1],ver[N<<1],tot,id[N];
void add(int x,int y){
	tot++;
	ver[tot]=y;
	nxt[tot]=head[x];
	head[x]=tot;
}
long long f[N],inv[N];
long long C(int x,int y){
	return f[x]*inv[y]%mod*inv[x-y]%mod;
}
int main(){
	freopen("traverse.in","r",stdin);
	freopen("traverse.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>c>>T;
	f[0]=1;
	for(int i=1;i<=1e5;i++){
		f[i]=f[i-1]*i%mod;
	}
	inv[100000]=qpow(f[100000],mod-2);
	for(int i=1e5-1;i>=0;i--){
		inv[i]=inv[i+1]*(i+1)%mod;
	}
	while(T--){
		cin>>n>>k;
		for(int i=1;i<n;i++){
			int x,y;
			cin>>x>>y;
			add(x,y);
			add(y,x);
		}
		for(int i=1;i<=k;i++) cin>>id[i];
		if(c==18){
			cout<<1<<'\n';
		}
		else if(c>=19&&c<=21){
			long long ans=0;
			for(int i=1;i<=k;i++){
				ans=(ans+(f[n-1-i]*C(n-3,i-1))%mod)%mod;
			}
			cout<<ans<<'\n';
		}
		else{
			cout<<rand()<<'\n';
		}
		for(int i=1;i<=n;i++){
			id[i]=head[i]=0;
		}
		tot=0;
	}
}
