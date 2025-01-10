#include<bits/stdc++.h>
using namespace std;
#define N 500005
int n,m,dfn[N],idf[N],tim,st[N][21],mn[N][21],mx[N][21],lg[N],ans,dep[N];
vector<int>G[N];
void dfs(int u,int fa){
	dep[u]=dep[fa]+1;
	for(int i=1;st[st[u][i-1]][i-1];++i)
		st[u][i]=st[st[u][i-1]][i-1];
	dfn[u]=++tim;
	idf[tim]=u;
	for(auto v:G[u]){
		if(v==fa)continue;
		st[v][0]=u;
		dfs(v,u);
	}
}
int get1(int l,int r){
	int k=lg[r-l+1];
	return min(mn[l][k],mn[r-(1<<k)+1][k]);
}
int get2(int l,int r){
	int k=lg[r-l+1];
	return max(mx[l][k],mx[r-(1<<k)+1][k]);
}
int LCA(int u,int v){
	if(dep[u]<dep[v])swap(u,v);
	for(int i=20;dep[u]>dep[v];--i)
		if(dep[st[u][i]]>=dep[v])
			u=st[u][i];
	if(u==v)return u;
	for(int i=20;~i;--i)
		if(st[u][i]!=st[v][i])
			u=st[u][i],v=st[v][i];
	return st[u][0];
}
int main(){
	freopen("query.in","r",stdin);
	freopen("query.out","w",stdout);
	int u,v,l,r,k;
	scanf("%d",&n);
	for(int i=1;i<n;++i){
		scanf("%d%d",&u,&v);
		G[u].push_back(v);
		G[v].push_back(u);
	}
	dfs(1,0);
	lg[0]=-1;
	for(int i=1;i<=n;++i)mn[i][0]=mx[i][0]=dfn[i],lg[i]=lg[i>>1]+1;
	for(int j=1;(1<<j)<=n;++j)
		for(int i=1;i+(1<<j)-1<=n;++i)
			mn[i][j]=min(mn[i][j-1],mn[i+(1<<j-1)][j-1]),
			mx[i][j]=max(mx[i][j-1],mx[i+(1<<j-1)][j-1]);
	scanf("%d",&m);
	for(int i=1;i<=m;++i){
		scanf("%d%d%d",&l,&r,&k);
		ans=0;
		for(int i=l;i<=r-k+1;++i){
			ans=max(ans,dep[LCA(idf[get1(i,i+k-1)],idf[get2(i,i+k-1)])]);
		}
		printf("%d\n",ans);
	}
	return 0;
}
