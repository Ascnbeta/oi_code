#include<bits/stdc++.h>
using namespace std;
const long long p=1000000007;
inline long long qpow(long long x,long long y){
	long long rtr=1;
	for(;y;y>>=1){
		if(y&1){
			rtr=rtr*x%p;
		}
		x=x*x%p;
	}
	return rtr;
}
struct node{
	long long pos,data;
	friend bool operator < (node x,node y){
		return x.pos<y.pos;
	}
}ask[100100];
int cases;
long long n,m,v,dp[4][100100],ans;
map<long long,long long> mp;
int main(){
	freopen("assign.in","r",stdin);
	freopen("assign.out","w",stdout);
	scanf("%d",&cases);
	for(;cases;--cases){
		memset(dp,0,sizeof(dp));
		mp.clear();
		scanf("%lld%lld%lld",&n,&m,&v);
		bool tb=0;
		for(int i=1;i<=m;++i){
			scanf("%lld%lld",&ask[i].pos,&ask[i].data);
			long long tem=mp[ask[i].pos];
			if(!tem){
				mp[ask[i].pos]=ask[i].data;
			}else{
				if(tem^ask[i].data){
					tb=1;
				}else{
					--i;
					--m;
				}
			}
		}
		if(tb){
			printf("0\n");
			continue;
		}
		sort(ask+1,ask+m+1);
		tb=0;
		ask[m+1].pos=0;
		if(ask[m].pos==n){
			--m;
			tb=1;
		}
		// cout<<tb<<endl;
		dp[0][0]=1;
		// cout<<m<<endl;
		// int tcnt=0;
		for(int i=1;i<=m;++i){
			long long tem=ask[i].pos-ask[i-1].pos-1;
			long long tpow=qpow(v,tem<<1|1),pp=v,tpw;
			if(ask[i].pos+1==ask[i+1].pos){
				tpw=qpow(v,tem<<1);
				pp=1;
			}else{
				tpw=tpow;
			}
			dp[0][i]=(dp[0][i-1]*tpow%p*(v-1)%p+dp[1][i-1]*tpow%p*(v-1)%p)%p;
			dp[1][i]=(dp[0][i-1]*tpw%p+dp[1][i-1]*tpw)%p;
			if(tem){
				// ++tcnt;
				dp[0][i]=(dp[0][i]-dp[1][i-1]*qpow(v,tem-1)%p*(v-1)%p*(v-1)%p*v%p)%p;
				dp[1][i]=(dp[1][i]-dp[1][i-1]*qpow(v,tem-1)%p*(v-1)%p*pp%p);
			}
			// cout<<dp[0][i]<<" "<<dp[1][i]<<" "<<tpow<<endl;
		}
		// cout<<tcnt<<" "<<m<<endl;
		long long ttem=n-ask[m].pos-1;
		long long ttpow=qpow(v,ttem<<1);
		ans=(dp[0][m]*ttpow%p+dp[1][m]*ttpow%p)%p;
		if(tb&&ttem){
			ans=(ans-dp[1][m]*qpow(v,ttem-1)*(v-1)%p)%p;
		}
		ans=(ans+p)%p;
		printf("%lld\n",ans);
	}
	return 0;
}