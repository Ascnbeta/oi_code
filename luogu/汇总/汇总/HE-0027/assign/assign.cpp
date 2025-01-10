#include<bits/stdc++.h>
using namespace std;
using llt=long long;
using llf=long double;
using ull=unsigned long long;
#define endl '\n'
#ifdef LOCAL
	FILE *InFile=freopen("in_out/in.in","r",stdin),*OutFile=freopen("in_out/out.out","w",stdout);
#else
	FILE *InFile=freopen("assign.in","r",stdin),*OutFile=freopen("assign.out","w",stdout);
#endif

const int N=1e5+3,MOD=1e9+7;
int v,n,m; int p[N];
map<int,int> cp;

template<int I,int J> struct Mtx{
	int o[I+1][J+1]={0};
	int *operator[](int p){return o[p];}
	void E(){for(int i=1;i<=I;++i) o[i][i]=1;}
	template<int K> Mtx<I,K> operator*(const Mtx<J,K> &b){
		Mtx<I,K> c;
		for(int i=1;i<=I;++i) for(int j=1;j<=J;++j) for(int k=1;k<=K;++k) c[i][k]=(c[i][k]+1ll*o[i][j]*b.o[j][k])%MOD;
		return c;
	}
	Mtx operator^(int b){
		Mtx<I,J> ans,a=*this; ans.E();
		assert(b>=0);
		while(b){
			if(b&1) ans=ans*a;
			a=a*a,b>>=1;
		}
		return ans;
	}
};

Mtx<2,2> to; Mtx<1,2> dp;
void Solve(){
	cin>>n>>m>>v;
	for(int i=1;i<=m;++i){
		int b; cin>>p[i]>>b;
		if(cp.count(p[i])&&cp[p[i]]!=b) return cout<<0<<endl,void();
		cp[p[i]]=b;
	} sort(p+1,p+m+1);
	to[1][1]=1ll*v*v%MOD,to[1][2]=0,to[2][1]=1ll*(v-1)*v%MOD,to[2][2]=v;
	dp[1][1]=dp[1][2]=0,dp[1][bool(p[1]==1)+1]=1; int la=1;
	for(int i=1;i<=m;++i) if(p[i]!=la){
		dp=dp*(to^(p[i]-la-1));
		dp[1][2]=(dp[1][2]+1ll*dp[1][2]*(v-1)%MOD*v%MOD+1ll*dp[1][1]*v%MOD*v%MOD)%MOD;
		dp[1][1]=0;
		la=p[i];
	}
	dp=dp*(to^(n-la));
	cout<<(dp[1][1]+dp[1][2])%MOD<<endl;
}
void Clear(){cp.clear();}

int main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int t; cin>>t; while(t--) Solve(),Clear();
}

/*
#include<bits/stdc++.h>
using namespace std;
using llt=long long;
using llf=long double;
using ull=unsigned long long;
#define endl '\n'
#ifdef LOCAL
	FILE *InFile=freopen("in_out/in.in","r",stdin),*OutFile=freopen("in_out/ans.ans","w",stdout);
#else
	FILE *InFile=freopen("file.in","r",stdin),*OutFile=freopen("file.out","w",stdout);
#endif

const int N=1e5+3,MOD=1e9+7;
int v,dp[N][2],n,m; int p[N];

void Solve(){
	cin>>n>>m>>v;
	for(int i=1;i<=m;++i){
		int a,b; cin>>a>>b; 
		if(n>N) continue;
		if(p[a]&&p[a]!=b) return cout<<0<<endl,void(); p[a]=b;
	}
	if(n>N) return cout<<"E"<<endl,void();
	dp[1][bool(p[1])]=1;
	for(int i=2;i<=n;++i){
		if(p[i]){
			dp[i][1]=(dp[i-1][1]+1ll*dp[i-1][1]*(v-1)%MOD*v%MOD+1ll*dp[i-1][0]*v%MOD*v%MOD)%MOD;
		}else{
			dp[i][0]=(1ll*dp[i-1][1]*(v-1)%MOD*v%MOD+1ll*dp[i-1][0]*v%MOD*v%MOD)%MOD;
			dp[i][1]=1ll*dp[i-1][1]*v%MOD;
		}
	}
	cout<<dp[n][0]<<' '<<dp[n][1]<<endl;
}
void Clear(){memset(dp,0,sizeof dp),memset(p,0,sizeof p);}

int main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int t; cin>>t; while(t--) Solve(),Clear();
}
*/