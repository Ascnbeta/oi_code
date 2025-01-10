#include<bits/stdc++.h>
using namespace std;
#define int long long
const int mod=1e9+7;
int qpow(int a,int x){
	int sum=1;
	while(x){
		if(x&1) sum=sum*a%mod;
		a=a*a%mod;
		x>>=1;
	}return sum;
}
const int N=1e5+5;
int fac[N];
int head[N],len;
struct E{
	int to,next,id;
}e[N*2];
void add(int u,int v,int id){e[++len]=E{v,head[u],id};head[u]=len;}
int f[N][2],g[N][3],gg[N][3];
int s[N];
int n,k;
int in[N],ind[N];
int sum,ans;
void dfs(int u,int id){
	s[u]=fac[ind[u]-1];
	memset(f[u],0,sizeof(f[u]));
	memset(g[u],0,sizeof(g[u]));
	g[u][0]=1;
	for(int i=head[u];i;i=e[i].next){
		int v=e[i].to;
		if(e[i].id==id) continue;
		dfs(v,e[i].id);
		memcpy(gg[u],g[u],sizeof(g[u]));
		memset(g[u],0,sizeof(g[u]));
		for(int i=0;i<=2;i++){
			for(int j=0;j<=1&&i+j<=2;j++){
				g[u][i+j]+=f[v][j]*gg[u][i];
			}
		}
		for(int j=0;j<=2;j++) g[u][j]%=mod;
		s[u]=s[u]*s[v]%mod;
	}
//	cerr<<"u="<<u<<'\n';
	int x=ind[u];
	int bs=sum*qpow(s[u],mod-2)%mod;
	if(1){
		f[u][0]+=g[u][0]*fac[x-1]%mod;
		if(x>=2)f[u][1]+=g[u][1]*fac[x-2]%mod;
		if(x>=2){
			ans+=g[u][2]*fac[x-2]%mod*bs%mod;
//			cerr<<g[u][2]*fac[x-2]*bs<<'\n'; 
		}
		
		if(in[id]){
//			cerr<<"FFFF"<<f[u][1]<<'\n';
			f[u][1]-=g[u][0]*fac[x-1]%mod;
			
			if(x>=2) ans-=g[u][1]*fac[x-2]%mod*bs%mod;
			ans-=g[u][0]*fac[x-1]%mod*bs%mod;
//			cerr<<g[u][0]*fac[x-1]%mod*bs<<'\n';
			if(x>=2) f[u][1]-=g[u][1]*fac[x-2]%mod;//cerr<<"g="<<g[u][1]<<' '<<fac[x-2]<<'\n';
//			ans-=g[u][1]*bs%mod;
		}	
	}
//	else{
//		if(x>=2) ans+=g[u][2]*fac[x-2]%mod,cerr<<g[u][2]*fac[x-2]<<'\n';
////		ans+=g[u][1]*fac[x-1]%mod,cerr<<g[u][1]*fac[x-1]<<'\n';
//	}
	for(int p1=0;p1<=1;p1++){
		f[u][p1]=(f[u][p1]%mod+mod)%mod;
	}
	
//	cerr<<"f="<<f[u][0]<<' '<<f[u][1]<<' '<<g[u][0]<<' '<<g[u][1]<<'\n';
//	cerr<<f[u][0][0]<<' '<<f[u][0][1]<<' '<<f[u][1][0]<<' '<<f[u][1][1]<<'\n';
}
void solve(){
	sum=1;ans=0;
	for(int i=1;i<=n;i++) sum=sum*fac[ind[i]-1]%mod;
//	ans=-sum*k%mod;
	dfs(1,0);
//	cerr<<ans<<'\n';
//	cerr<<"----\n";
	ans=-ans;
	cout<<(ans%mod+mod)%mod<<'\n';
}
signed main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	freopen("traverse.in","r",stdin);
	freopen("traverse.out","w",stdout);
	int _,T;cin>>_>>T;
	fac[0]=1;
	for(int i=1;i<N;i++) fac[i]=fac[i-1]*i%mod; 
	while(T--){
		for(int i=1;i<=n;i++) head[i]=in[i]=ind[i]=0;
		len=0;
		cin>>n>>k;
//		cerr<<"n="<<n<<' '<<"k="<<k<<'\n';
		for(int i=1;i<n;i++){
			int u,v;cin>>u>>v;add(u,v,i);add(v,u,i);
			ind[u]++;ind[v]++; 
		}
		for(int i=1;i<=k;i++){
			int x;cin>>x;in[x]=1;
		}
		solve();
	}
	return 0;
}
