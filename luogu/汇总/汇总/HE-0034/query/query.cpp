#include<bits/stdc++.h>
using namespace std;
const int maxn=5e5+5;
int n,q,head[maxn],tot;
struct Edge{
	int to,next;
}edge[maxn<<1];
void add(int u,int v){
	edge[++tot]={v,head[u]},head[u]=tot;
	edge[++tot]={u,head[v]},head[v]=tot;
}
int dep[maxn],fa[maxn];
void dfs(int u,int fath){
	dep[u]=dep[fath]+1;
	fa[u]=fath;
	for(int i=head[u];i;i=edge[i].next){
		int v=edge[i].to;
		dfs(v,u);
	}
}
signed main(){
	freopen("query.in","r",stdin);
	freopen("query.out","w",stdout);
	scanf("%d",&n);
	for(int i=1,u,v;i<n;++i){
		scanf("%d%d",&u,&v);
		add(u,v);
	}
	dfs(1,0);
	scanf("%d",&q);
	for(int i=1,l,r,k;i<=q;++i){
		scanf("%d%d%d",&l,&r,&k);
		
	}
	return 0;
}
/*
zhen de yao AFO le
thx to OI,thx to exeryone
zhu da jia RP++
*/
