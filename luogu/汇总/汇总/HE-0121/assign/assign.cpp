#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
const int mod=1e9+7;
typedef long long ll;
const int MAXN=1e5+10;
inline int read(){
	int xx=0,ff=1;
	char ch=getchar();
	while(ch<'0'||ch>'9') {
		if(ch=='-') ff=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9'){
		xx=xx*10+ch-48;
		ch=getchar();
	}
	return xx*ff;
}
int n,m,cnt;
ll v;
ll f[2][2],fc[MAXN],inv[MAXN];
ll fpow(ll x,ll k){
	ll res=1;
	while(k){
		if(k&1) res=res*x%mod;
		x=x*x%mod;
		k>>=1;
	}
	return res;
}
int a[MAXN],b[MAXN];
struct Query
{
	int c,d;
	bool operator<(const Query &x)const{
		return c<x.c;
	}
}q[MAXN];
void init(){
	cnt=0;
	n=read(); m=read(); v=read();
	for(int i=1;i<=m;++i){
		q[i].c=read(); q[i].d=read();
		if(q[i].c==i) cnt++;
	}
}
ll ans,res;
ll C(int n,int m){
//	printf("%lld %lld %lld",fc[n],inv[m],inv[n-m]);
	return res=fc[n]*inv[m]*mod*inv[n-m]*mod;
}
void solve2(){
	ans=0;
//	printf("%lld\n",C(n-1,1));
	for(int i=0;i<=n-1;++i){
//		printf("%lld\n",res);
	   ans=(ans+C(n-1,i)*fpow(v-1,i)%mod*fpow(v,i)%mod)%mod;	
	}
	printf("%lld\n",ans);
}
void solve3(){
	sort(q+1,q+1+m);
}
int main(){
	freopen("assign.in","r",stdin);
	freopen("assign.out","w",stdout);
    int T; T=read();
    fc[0]=1;
    for(int i=1;i<=MAXN-5;++i) fc[i]=fc[i-1]*i%mod;
    inv[MAXN-5]=fpow(fc[MAXN-5],mod-2);
//    printf("%lld %lld\n",fc[MAXN-5],inv[MAXN-5]);
    for(int i=MAXN-6;i>=0;--i) inv[i]=inv[i+1]*(i+1)%mod;
    while(T--){
    	init(); 
    	if(cnt==n){
    		solve2();
		}
		else solve3();
	}
	return 0;
}
