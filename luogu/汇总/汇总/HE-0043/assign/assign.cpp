#include<bits/stdc++.h>
#define int long long
#define fi first 
#define se second
#define eb emplace_back
#define pb push_back
#define pii std::pair<int,int>
typedef long long ll;
inline int read(){char ch=getchar();int x=0,f=1;for(;ch<'0'||ch>'9';ch=getchar())if(ch=='-')f=-1;for(;ch>='0'&&ch<='9';ch=getchar())x=x*10+(ch^48);return f*x;}
inline void Max(int &x,int y){x=std::max(x,y);}
inline void Min(int &x,int y){x=std::min(x,y);}
const int N=2e5+10,mod=1e9+7;
int n,m,V;
std::vector<int> v[N];
pii a[N];
int f[N];
inline int qpow(int a,int b){if(b<0)return 1;int res=1;for(;b;b>>=1,a=a*a%mod)if(b&1)res=res*a%mod;return res;}
signed main(){
	freopen("assign.in","r",stdin);freopen("assign.out","w",stdout);
	std::ios::sync_with_stdio(false);std::cin.tie(0);std::cout.tie(0);
	int T=read();while(T--){
		a[0].fi=-10;
		n=read(),m=read();V=read();for(int i=1;i<=m;++i){a[i].fi=read(),a[i].se=read();}
		std::sort(a+1,a+m+1);
		int tot=0,pd=0;
		for(int i=1;i<=m;++i)if(a[i].fi==a[i-1].fi&&a[i].se!=a[i-1].se){pd=1;break;}
		if(pd){std::cout<<0<<'\n';continue;}
		f[1]=qpow(V*V%mod,a[1].fi-1);
		int la=a[1].fi;
		for(int i=2;i<=m;++i){
			f[i]=f[i-1];
			if(a[i].fi==a[i-1].fi)continue;
			int len=a[i].fi-la;
			int _0=f[i];
			f[i]=_0*(qpow(V*V%mod,len)-qpow(V,len-1)*(V-1)%mod)%mod;
			la=a[i].fi;
		}
		// std::cout<<(f[m]%mod+mod)%mod<<'\n';
		if(la!=n)f[m]=f[m]*qpow(V*V%mod,(n-la))%mod;
		std::cout<<(f[m]%mod+mod)%mod<<'\n';
	}
}
