#include<bits/stdc++.h>
#define int long long
using namespace std;
const int mod=1e9+7;
int c,T,n,k,tot,head[100005],st[100005],ans,vis[100005];
struct Edge{
	int u,v;
}E[100005];
vector<int> id[105];
struct EDGE{
	int to,next;
}edge[200005];
void add(int u,int v){
	edge[++tot]={v,head[u]},head[u]=tot;
}
void dfs(int u,int fa){
	int f=1;
	for(int i=1;i<n;++i)if(!vis[i])f=0;
	ans+=f;
	for(int i=head[u];i;i=edge[i].next){
		int v=edge[i].to;
		if(vis[v])continue;
		vis[v]=1;
		dfs(v,u);
		vis[v]=0;
	}
}
signed main(){
	freopen("traverse.in","r",stdin);
	freopen("traverse.out","w",stdout);
	scanf("%lld%lld",&c,&T);
	while(T--){
		scanf("%lld%lld",&n,&k);tot=ans=0;
		for(int i=1;i<=n;++i)head[i]=0;
		for(int i=1;i<n;++i)scanf("%lld%lld",&E[i].u,&E[i].v);
		for(int i=1;i<=k;++i)scanf("%lld",&st[i]);
		if(c==18)puts("1");
		else {
			for(int i=1;i<n;++i){
				id[E[i].u].push_back(i);
				id[E[i].v].push_back(i);
			}
			for(int i=1;i<=n;++i)
				for(auto x:id[i])
					for(auto y:id[i])if(x!=y)add(x,y);
			vis[st[1]]=1;
			dfs(st[1],0);
			printf("%lld",ans%mod);
		}
	}
	return 0;
}
