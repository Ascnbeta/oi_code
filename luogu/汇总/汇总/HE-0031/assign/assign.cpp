#include<bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define N 100005
typedef long long ll;
ll fpow(ll a,ll b){
	ll r=1;
	while(b){
		if(b&1)r=r*a%mod;
		a=a*a%mod;
		b=b>>1;
	}
	return r;
}
int t,n,m,v,inv;
struct node{
	ll x,y;
}a[N];
ll ans,len;
bool cmp(node i,node j){
	return i.x<j.x;
}
int main(){
	freopen("assign.in","r",stdin);
	freopen("assign.out","w",stdout);
	scanf("%d",&t);
	while(t--){
		scanf("%d%d%d",&n,&m,&v);inv=fpow(v,mod-2);
		for(int i=1;i<=m;++i)scanf("%lld%lld",&a[i].x,&a[i].y);
		sort(a+1,a+m+1,cmp);
		ans=fpow(v,(a[1].x-1)*2);
		for(int i=2;i<=m;++i){
			len=a[i].x-a[i-1].x;
			if(!len&&a[i].y!=a[i-1].y){ans=0;break;}
			if(!len)continue;
			ans=ans*(fpow(v,2*len-1)*(v-1)%mod*(mod+1-fpow(inv,len))%mod*fpow(mod+1-inv,mod-2)%mod+fpow(v,len-1))%mod;
		}
		ans=ans*fpow(v,(n-a[m].x)*2)%mod;
		printf("%lld\n",ans);
	}
	return 0;
}
