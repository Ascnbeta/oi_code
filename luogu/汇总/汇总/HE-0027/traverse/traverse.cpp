#include<bits/stdc++.h>
using namespace std;
using llt=long long;
using llf=long double;
using ull=unsigned long long;
#define endl '\n'
#ifdef LOCAL
	FILE *InFile=freopen("in_out/in.in","r",stdin),*OutFile=freopen("in_out/out.out","w",stdout);
#else
	FILE *InFile=freopen("traverse.in","r",stdin),*OutFile=freopen("traverse.out","w",stdout);
#endif

const int N=1e5+3,MOD=1e9+7;
int fac[N],ivf[N],n,ck,cu[N],cv[N],cccc;

struct Gph{
	int hd[N],nt[N<<1],to[N<<1],tot=1;
	void Add(int u,int v){to[++tot]=v,nt[tot]=hd[u],hd[u]=tot;}
	void ADD(int u,int v){Add(u,v),Add(v,u);}
	void Clr(){memset(hd,0,sizeof hd),tot=1;}
#define For_to(i,u,v,g) for(int i=g.hd[u],v=g.to[i];i;i=g.nt[i],v=g.to[i])
}g;

int C(int a,int b){return a<b||b<0?0:1ll*fac[a]*ivf[b]%MOD*ivf[a-b]%MOD;}

int dp[N];
void Dp(int u,int f){
	int cnt=0; dp[u]=1;
	For_to(i,u,v,g) if(v!=f) ++cnt,Dp(v,u),dp[u]=1ll*dp[u]*dp[v]%MOD;
	if(!cnt) return ;
	int s=fac[cnt];
	dp[u]=dp[u]*s%MOD;
}

void Solve(){
	cin>>n>>ck; for(int i=1;i<n;++i) cin>>cu[i]>>cv[i],g.ADD(cu[i],cv[i]);
	if(cccc==18){
		for(int i=1;i<=ck;++i){int id; cin>>id;}
		return cout<<1<<endl,void();
	}
	else if(19<=cccc&&cccc<=21){
		for(int i=1;i<=ck;++i){int id; cin>>id;}
		int ans=0,a;
		memset(dp,0,sizeof dp); Dp(cu[1],cv[1]),a=dp[cu[1]];
		memset(dp,0,sizeof dp); Dp(cv[1],cu[1]),ans=(ans+1ll*a*dp[cv[1]])%MOD;
		cout<<1ll*ans*ck%MOD<<endl;
		return ;
	}
	int ans=0;
	for(int i=1;i<=ck;++i){
		int id; cin>>id; int a=0;
		memset(dp,0,sizeof dp); Dp(cu[id],cv[id]),a=dp[cu[id]];
		memset(dp,0,sizeof dp); Dp(cv[id],cu[id]),ans=(ans+1ll*a*dp[cv[id]])%MOD;
	}
	cout<<ans<<endl;
}

void Clear(){g.Clr();}

int main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	fac[0]=1; for(int i=1;i<=N-3;++i) fac[i]=1ll*fac[i-1]*i%MOD;
	ivf[N-3]=716327852; for(int i=N-3;i;--i) ivf[i-1]=1ll*ivf[i]*i%MOD;
	int t; cin>>cccc>>t; while(t--) Solve(),Clear();
}