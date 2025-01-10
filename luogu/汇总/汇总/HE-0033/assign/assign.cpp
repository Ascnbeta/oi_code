#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll read(){
	ll x=0,f=1;char ch=getchar();
	while(ch>'9'||ch<'0') {
		if(ch=='-') f=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9') x=x*10+ch-'0',ch=getchar();
	return x*f;
}

const int MOD=1e9+7;
ll kmi(ll a,ll b){
	ll res=1;
	while(b){
		if(b&1) res=res*a%MOD;
		b>>=1;
		a=a*a%MOD;
	}
	return res%MOD;
}

int main(){
	freopen("assign.in","r",stdin);
	freopen("assign.out","w",stdout);
	int T=read();
	while(T--){
		ll n=read(),m=read(),v=read();
		for(ll i=1;i<=m;i++){
			ll a=read(),b=read();
		}
		cout<<(kmi((v-1)*v+1,n-1))%MOD<<endl;
	}
	return 0;
}
