#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
#define fi first
#define se second
#define mk make_pair
#define ps push_back
#define mo(x,y) (x+=y,x>=mod?x-=mod:0)
const int N=1e6+10,inf=0x3f3f3f3f;
const ll linf=0x3f3f3f3f3f3f3f3f,mod=1e9+7;
inline ll read(){
	char c=getchar(); ll x=0;bool f=0;
	while(!isdigit(c))f=c=='-'?1:0,c=getchar();
	while(isdigit(c))x=(x<<1)+(x<<3)+(c^48),c=getchar();
	return f?-x:x;
}
int t,n,m,v;
ll st[60],stt[60];
unordered_map<int,int> ma;
inline ll ask(int k){
	if(k<0)return 0;
	ll ans=0,now=1;
	for(int i=0;i<32;++i){
		if((k>>i)&1)ans=(ans+(now*st[i]))%mod,now=now*stt[i]%mod;
	}
	return ans+1;
}
inline ll qpow(ll x,ll y){
	ll ans=1;
	while(y){
		if(y&1)ans=ans*x%mod;
		x=x*x%mod;y>>=1;
	}
	return ans;
}
ll f[N];
int main(){
	freopen("assign.in","r",stdin);
	freopen("assign.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	t=read();
	while(t--){
		n=read(),m=read(),v=read();
		ma.clear();
		bool ff=0;
		for(int i=1,x,y;i<=m;++i){
			x=read(),y=read();
			if(ma[x]&&ma[x]!=y){ff=1;break;}
			ma[x]=y;
		}
		if(ff){cout<<0<<'\n';continue;}
		st[0]=stt[0]=v;
		for(int i=1;i<40;++i){
			stt[i]=stt[i-1]*stt[i-1]%mod;
			st[i]=(st[i-1]+st[i-1]*stt[i-1])%mod;
		}
		vector<int> vv;
		for(auto i:ma)
			vv.ps(i.fi);
		sort(vv.begin(), vv.end());
		f[0]=1;
		for(int i=1;i<vv.size();++i){
			f[i]=f[i-1]*(((v-1)%mod*(ask(vv[i]-vv[i-1]-1))%mod*qpow(v,vv[i]-vv[i-1])%mod+qpow(v,vv[i]-vv[i-1]-1))%mod)%mod;
		}
		cout<<f[(int)vv.size()-1]*qpow(v,(n-vv.back()+vv[0]-1)*2)%mod<<'\n';
	}
}