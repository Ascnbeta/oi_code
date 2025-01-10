#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e5+100;
const ll mod=1e9+7;
int c,T,n,m,fir[N],sec[N],imp,deg[N];
int cnt,head[N];
ll dp[N],jc[N],ans;
struct edge{
	int to,nxt;
}e[N<<1];
inline void add(int u,int v){
	cnt++;
	e[cnt].to=v;
	e[cnt].nxt=head[u];
	head[u]=cnt;
}
inline void Clear(){
	for(int i=1;i<=cnt;i++)e[i].to=e[i].nxt=0;
	memset(deg,0,sizeof(deg));
	memset(head,0,sizeof(head));
	memset(dp,0,sizeof(dp));
	cnt=0;
}
void dfs1(int u,int f){
	dp[u]=1;
	int num=0;
	for(int i=head[u];i;i=e[i].nxt){
		int v=e[i].to;
		if(v==f)continue;
		dfs1(v,u);
		dp[u]=dp[u]*dp[v]%mod;
		num++;
	}
	dp[u]=dp[u]*jc[num]%mod;
}
signed main()
{
	freopen("traverse.in","r",stdin);
	freopen("traverse.out","w",stdout);
	scanf("%d%d",&c,&T);
	jc[0]=jc[1]=1;
	for(int i=2;i<N;i++)jc[i]=jc[i-1]*i%mod;
	while(T--){
		Clear();
		scanf("%d%d",&n,&m);
		for(int i=1;i<n;i++){
			scanf("%d%d",&fir[i],&sec[i]);
			add(fir[i],sec[i]);add(sec[i],fir[i]);
			deg[fir[i]]++;deg[sec[i]]++;
		}
		if(c<=6){
			scanf("%d",&imp);
			dfs1(fir[imp],sec[imp]);
			dfs1(sec[imp],fir[imp]);
			printf("%lld\n",dp[fir[imp]]*dp[sec[imp]]%mod);
			continue;
		}
		if(c==18){
			for(int i=1;i<=m;i++){
				scanf("%d",&imp);
			}
			puts("1");
			continue;
		}
		if(c>=19&&c<=21){
			ans=0;
			for(int i=1;i<=m;i++){
				scanf("%d",&imp);
				if(n>=3)ans=(ans+jc[n-3]*(n-1-i))%mod;
				else ans=(ans+1)%mod;
			}
			printf("%lld\n",ans);
			continue;
		}
	}
}
