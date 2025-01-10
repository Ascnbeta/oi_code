#include<bits/stdc++.h>
typedef long long ll;
typedef unsigned long long ull;
#define pa pair<int,int>
#define qr qr()
#define ve vector
#define fi first
#define se second
#define ps push_back
using namespace std;
const int N=3e5+200,mod=1e9+7;
inline int qr{
	int x=0;char ch=getchar();bool f=0;
	while(ch>57||ch<48)f=(ch=='-')?1:0,ch=getchar();
	while(ch<=57&&ch>=48)x=(x<<3)+(x<<1)+(ch^48),ch=getchar();
	return f?-x:x;
}
int n,m,up,a[N],p[N],v[N];
pa mp[N];
inline ll qp(ll x,int p){
	ll ans=1;
	while(p){
		if(p&1)ans=ans*x%mod;
		x=x*x%mod;
		p>>=1;
	}return ans;
}
inline int MO(int x){
	if(x<0)return x+mod;else if(x>mod)return x-mod;else return x;
}
void init(){
	n=qr;m=qr;up=qr;
	bool f=0;
	for(int i=1;i<=m;++i){
		p[i]=qr,v[i]=qr;
		mp[i]={p[i],v[i]};
	}sort(mp+1,mp+m+1);
	int ans=1;
	if(!m){
		cout<<qp(up,2*(n-1))<<'\n';
		return;
	}
	for(int i=1;i<m;++i){
		if(mp[i+1].fi==mp[i].fi){
			if(mp[i].se!=mp[i+1].se){cout<<"0\n";return;}
		}else{
			int res=qp(up,2*(mp[i+1].fi-mp[i].fi));
			res=MO(res-qp(up,mp[i+1].fi-mp[i].fi-1)*(up-1)%mod);
			ans=1ll*ans*res%mod;
		}
	}
	ans=ans*qp(up,2ll*(mp[1].fi-1))%mod*qp(up,2*(n-mp[m].fi))%mod;
	cout<<ans<<'\n';
}
int main(){

	freopen("assign.in","r",stdin);
	freopen("assign.out","w",stdout);
	
	int t=qr;
	while(t--)
		init();
	return 0;
}

