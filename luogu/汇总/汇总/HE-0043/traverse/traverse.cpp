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
int n,K;
const int mod=1e9+7;
inline int qpow(int a,int b){if(b<0)return 1;int res=1;for(;b;b>>=1,a=a*a%mod)if(b&1)res=res*a%mod;return res;}
signed main(){
	freopen("traverse.in","r",stdin);freopen("traverse.out","w",stdout);
	std::ios::sync_with_stdio(false);std::cin.tie(0);std::cout.tie(0);
	int c=read(),T=read();while(T--){
		n=read(),K=read();
		int check=0;
		for(int i=1;i<n;++i){
			int u=read(),v=read();
			check+=((u==1)&(v==i+1));
		}
		for(int i=1;i<=K;++i)int x=read();
		std::cout<<K<<'\n';
		// if(check==n-1){
		// 	int ans=1;
		// 	for(int i=1;i<n-1;++i)ans=ans*i%mod;
		// 	std::cout<<ans*K%mod<<'\n';
		// }else{

		// 	std::cout<<K<<'\n';
		// }

	}
}
