#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e5+100;
const ll mod=1e9+7;
int T,n,m,v;
ll ans;
struct node{
	int c,d;
}t[N];
ll qpow(ll x,ll y){
	ll res=1;
	while(y){
		if(y&1)res=res*x%mod;
		x=x*x%mod;
		y>>=1;
	}
	return res;
}
bool cmp(node fir,node sec){
	return fir.c<sec.c;
}
signed main()
{
	freopen("assign.in","r",stdin);
	freopen("assign.out","w",stdout);
	scanf("%d",&T);
	while(T--){
		scanf("%d%d%d",&n,&m,&v);
		for(int i=1;i<=m;i++){
			scanf("%d%d",&t[i].c,&t[i].d);
		}
		sort(t+1,t+m+1,cmp);
		bool flag=0;
		ans=qpow(v,(t[1].c-1)*2);
		for(int i=2;i<=m;i++){
			if(t[i].c==t[i-1].c){
				if(t[i].d==t[i-1].d)continue;
				else {
					flag=1;
					break;
				}
			}
			ans=((qpow(v,(t[i].c-t[i-1].c)*2)-qpow(v,t[i].c-t[i-1].c-1)*(v-1)%mod)%mod+mod)%mod*ans%mod;
		}
		if(flag){
			puts("0");
			continue;
		}
		
		ans=ans*qpow(v,(n-t[m].c)*2)%mod;
		printf("%lld\n",ans);
	}
}
