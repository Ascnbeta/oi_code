#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
int top[N],fa[N],dfn[N],dfntot,son[N],siz[N];
int n,q,dep[N],st[N][21];
vector<int>g[N];
struct sta{
	int l,r,k;
}que[N];
void dfs1(int x){
	siz[x]=1;
	for(int y:g[x]){
		if(!dep[y]){
			dep[y]=dep[x]+1;
			fa[y]=x;
			dfs1(y);
			siz[x]+=siz[y];
			if(siz[x]>siz[son[x]])son[x]=y;
		}
	}	
}
void dfs2(int x,int t){
	top[x]=t;
	dfn[x]=++dfntot;
	if(!son[x])return;
	dfs2(son[x],t);
	for(int y:g[x]){
		if((y^fa[x])&&(y^son[x]))dfs2(y,y);
	}
}
inline int lca(int x,int y){
	while(top[x]^top[y]){
		if(dep[top[x]]<dep[top[y]])swap(x,y);
		x=fa[top[x]];
	}
	return dep[x]<dep[y]?x:y;
}
void init(){
	for(int i=1;i<=n;i++)st[i][0]=i;
	for(int d=1;d<=20;d++){
		for(int i=1;i+(1<<d)-1<=n;i++){
			st[i][d]=lca(st[i][d-1],st[i+(1<<d-1)][d-1]);
		}
	}
}
inline get(int l,int r){
	int op=log2(r-l+1);
	return dep[lca(st[l][op],st[r-(1<<op)+1][op])];
}
int main(){
	freopen("query.in","r",stdin);
	freopen("query.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>n;
	for(int i=1;i<n;i++){
		int x,y;
		cin>>x>>y;
		g[x].push_back(y);
		g[y].push_back(x);
	}
	cin>>q;
	dep[1]=1;dfs1(1);dfs2(1,1);
	init();
	while(q--){
		int l,r,k;
		cin>>l>>r>>k;
		int op=0;
		for(int i=l;i+k-1<=r;i++){
			op=max(op,get(i,i+k-1));
		}
		cout<<op<<"\n";
	}
}
