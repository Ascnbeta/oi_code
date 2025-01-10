#include<bits/stdc++.h>
#define rpt(a,b,c) for(int a=b;a<=c;a++)
#define LL long long
using namespace std;
const int mod=1e9+7;
int T,n,m,v;
LL Pow(LL a,LL b){
	if(b<0)return 0;
	LL ans=1;
	while(b){
		if(b&1)ans=ans*a%mod;
		a=a*a%mod; b>>=1;
	}
	return ans;
}
int main(){
	freopen("assign.in","r",stdin);
	freopen("assign.out","w",stdout);
	scanf("%d",&T);
	while(T--){
		scanf("%d%d%d",&n,&m,&v);
		printf("%lld\n",Pow(v,n*2-2));
	}
	return 0;
}
