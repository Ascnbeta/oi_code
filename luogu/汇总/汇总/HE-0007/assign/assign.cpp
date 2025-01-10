#include<bits/stdc++.h>
#define LL long long
using namespace std;
const int N=2e5+10,mod=1e9+7;
LL n,m,k;
struct a1{int i,t;}a[N];
bool a2(a1 a,a1 b){return a.i<b.i;}
LL Pow(LL a,int k){
	LL ans=1;
	while(k){
		if(k&1)ans=ans*a%mod;
		k>>=1;a=a*a%mod;
	}
	return ans;
}
int main(){
	freopen("assign.in","r",stdin);
	freopen("assign.out","w",stdout);	
	
	int T;cin>>T;
	while(T--){
		scanf("%lld%lld%lld",&n,&m,&k);
		for(int q=1;q<=m;q++)scanf("%d%d",&a[q].i,&a[q].t);
		sort(a+1,a+1+m,a2);
		LL ans=Pow(k,n-1)*Pow(k,n-1)%mod;
		for(int q=1;q<=m;q++){if(a[q].i==a[q-1].i&&a[q].t!=a[q-1].t)ans=0;}
		if(ans==0){
			cout<<"0\n";
			continue;
		}
		LL p=1;
		p=p*Pow(k*k%mod,a[1].i-1)%mod;
		for(int q=2;q<=m;q++){
			if(a[q].i==a[q-1].i)continue;
			if(a[q].i==a[q-1].i+1)p=p*((k-1)*k%mod+1)%mod;
			else p=p*((Pow(k*k%mod,a[q].i-a[q-1].i)-Pow(k,a[q].i-a[q-1].i-1)*(k-1)%mod+mod)%mod)%mod;
		}
		p=p*Pow(k*k%mod,n-a[m].i)%mod;
		cout<<p<<"\n";
	}
	return 0;
}
