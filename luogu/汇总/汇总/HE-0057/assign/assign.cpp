#include<iostream>
#include<cstdio>
using namespace std;
#define int long long
const int N=1e5+10,mod=1e9+7;
int t,n,m,v,c[N],d[N];
int poww(int x,int b){
	int anss=1;
	while(b){
		if(b&1)
		anss*=x,anss%=mod;
		b>>=1;
		x*=x;
		x%=mod;
	}
	return anss;
}
signed main(){
	freopen("assign.in","r",stdin);
	freopen("assign.out","w",stdout);
	scanf("%lld",&t);
	while(t--){
		scanf("%lld%lld%lld",&n,&m,&v);
		for(int i=1;i<=m;i++){
			scanf("%lld%lld",&c[i],&d[i]);
		}
		int ff=poww(v,2);
		cout<<poww(ff,n-1)<<'\n';
	} 
	return 0;
} 
