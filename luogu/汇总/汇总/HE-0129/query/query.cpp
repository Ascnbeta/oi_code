#include<bits/stdc++.h>
using namespace std;
const int maxn=5e5+3;
int n;
int first[maxn],nxt[maxn<<1],to[maxn<<1],tot=0;
void add(int x,int y){
	nxt[++tot]=first[x];first[x]=tot;to[tot]=y;
}
int dep[maxn],vis[maxn];
void dfs(int u){
	if(vis[u])return;
	vis[u]=1;
	for(int i=first[u];i;i=nxt[i]){
		int v=to[i];
		dep[v]=dep[u]+1;
		dfs(v);
	}
}
int t[maxn<<4];
void pushup(int u){
	t[u]=max(t[u<<1],t[u<<1|1]);
}
void build(int u,int l,int r){
	if(l==r){
		t[u]=dep[l];return;
	}
	int mid=l+r>>1;
	build(u<<1,l,mid);
	build(u<<1|1,mid+1,r);
	pushup(u);
}
int findl(int u,int l,int r,int x,int y){
	int res=0;
	if(x<=l&&y>=r){
		return t[u];
	}
	int mid=l+r>>1;
	if(x<=mid)res=max(res,findl(u<<1,l,mid,x,y));
	if(y>mid)res=max(res,findl(u<<1|1,mid+1,r,x,y));
	return res;
}
int main(){
	freopen("query.in","r",stdin);
	freopen("query.out","w",stdout);
	cin>>n;
	for(int i=1;i<n;i++){
		int x,y;cin>>x>>y;
		add(x,y);add(y,x);
	}
	dfs(1);
	build(1,1,n);
	int q;cin>>q;
	for(int i=1;i<=q;i++){
		int l,r,k;cin>>l>>r>>k;
		cout<<findl(1,1,n,l,r)<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
