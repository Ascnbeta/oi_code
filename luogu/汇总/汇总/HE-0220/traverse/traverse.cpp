#include<bits/stdc++.h>
using namespace std;
#define ll long long 
const int N=2e5+10;
const int mod=1e9+7;
int ID,T;
int n,m;
ll jc[N];
int a[N];

void Solve1(){
	printf("1\n");
}

ll Fastpow(ll x,int k){
	ll ans=1;
	while(k){
		if(k&1) ans=ans*x%mod;
		x=x*x%mod;
		k>>=1;
	}
	return ans;
}

void Solve2(){
	ll ans=m*jc[n-2];
	ll g=(ll)m*(m-1)/2%mod*jc[n-3]%mod;
	ans=(ans-g+mod)%mod;
	printf("%lld\n",ans);
}

int main(){
	freopen("traverse.in","r",stdin);
	freopen("traverse.out","w",stdout);
	scanf("%d%d",&ID,&T);
	jc[0]=1;
	for(int i=1;i<=100000;i++) jc[i]=jc[i-1]*i%mod;
	while(T--){
		scanf("%d%d",&n,&m);
		//cerr<<n<<" "<<m<<endl;
		int u,v;
		for(int i=1;i<n;i++) scanf("%d%d",&u,&v);
		for(int i=1;i<=m;i++) scanf("%d",&a[i]);
		if(ID==18) Solve1();
		else if(ID>=19 && ID<=21) Solve2();
	}	
	return 0;
} 
