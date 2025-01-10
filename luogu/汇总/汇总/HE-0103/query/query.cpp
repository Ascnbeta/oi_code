#include<bits/stdc++.h>
#define mp make_pair
#define int long long
using namespace std;
const int N=5e5+5;
int n,q,dep[N],dfn[N],top[N],siz[N],bson[N],dn,fa[N];
vector<int> G[N];
map<pair<int,int>,int>lca;
void dfs1(int u,int f){
	siz[u]=1;dep[u]=dep[f]+1;fa[u]=f;
	for(auto v : G[u]){
		if(v==f) continue;
		dfs1(v,u);
		siz[u]+=siz[v];
		if(siz[v]>siz[bson[u]]) bson[u]=v;
	}
}
void dfs2(int u,int t){
	top[u]=t;
	dfn[u]=++dn;
	if(bson[u]) dfs2(bson[u],t);
	for(auto v : G[u]){
		if(v==bson[u]||v==fa[u]) continue;
		dfs2(v,v);
	}
}
int LCA(int x,int y){
	while(top[x]!=top[y]){
		if(dep[top[x]]<dep[top[y]]) swap(x,y);
		x=fa[top[x]];
	}
	if(dep[x]<dep[y]) swap(x,y);
	return y;
}

#undef int
int main(){
#define int long long
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	freopen("query.in","r",stdin);
	freopen("query.out","w",stdout);
	cin>>n;
	for(int i=1;i<n;i++){
		int u,v;cin>>u>>v;
		G[u].push_back(v);G[v].push_back(u);
	}
	dfs1(1,0);dfs2(1,1);
//	lg[1]=0;
//	for(int i=1;i<=n;i++) {
//		st[i][0]=dep[i];
//		if(i>1) lg[i]=lg[i>>1]+1;
//	}
//	int t=lg[n]+1;
//	for(int j=1;j<t;j++){
//		for(int i=1;i<=n-(1<<j)+1;i++){
//			st[i][j]=min(st[i][j-1],st[i+(1<<(j-1))][j-1]);
//		}
//	}
	for(int i=1;i<=n;i++) lca[mp(i,i)]=i;
	for(int len=2;len<=n;len++){
		for(int i=1;i<=n-len+1;i++){
			int j=i+len-1;
			lca[mp(i,j)]=LCA(lca[mp(i,j-1)],j);
		}
	}
	cin>>q;
	while(q--){
		int l,r,k;
		cin>>l>>r>>k;
		int ans=0;
		for(int i=l;i<=r-k+1;i++){
			int j=i+k-1;
			ans=max(ans,dep[lca[mp(i,j)]]);
		}
		cout<<ans<<endl;
	}
	return 0;
}
