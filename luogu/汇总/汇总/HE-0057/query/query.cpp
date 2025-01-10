#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
const int N=1e6+10;
int n,q,dis[N],head[N],pos=0,fa[N][33];
bool vis[N];
struct mm{
	int to,next;
}e[N];
struct mmm{
	int l,r,pre;
}t[4*N];
void pushup(int p){
	t[p].pre=max(t[p*2].pre,t[p*2+1].pre);
}
void build(int p,int l,int r){
	t[p].l=l;
	t[p].r=r;
	if(l==r){
		t[p].pre=dis[l];
		return;
	}
	int mid=(l+r)>>1;
	build(p*2,l,mid);
	build(p*2+1,mid+1,r);
	pushup(p);
}
int query(int p,int l,int r){
	if(l<=t[p].l&&t[p].r<=r){
		return t[p].pre;
	}
	int mid=(t[p].l+t[p].r)>>1,ans=0;
	if(l<=mid)
	ans=max(ans,query(p*2,l,r));
	if(r>mid)
	ans=max(ans,query(p*2+1,l,r));
	return ans;
}
void add(int u,int v){
	pos++;
	e[pos].to=v;
	e[pos].next=head[u];
	head[u]=pos;
}
void dfs(int x,int f){
	fa[x][0]=f;
	vis[x]=1;
	dis[x]=dis[f]+1;
	for(int i=1;i<=30;i++)
	fa[x][i]=fa[fa[x][i-1]][i-1];
	for(int i=head[x];i;i=e[i].next){
		int to=e[i].to;
		if(to==f)
		continue;
		if(!vis[to])
		dfs(to,x);
	}
}
int LCA(int x,int y){
	if(x==y)
	return x;
	if(dis[x]<dis[y])
	swap(x,y);
	for(int i=20;i>=0;i--)
	if(dis[fa[x][i]]>=dis[y])
	x=fa[x][i];
	if(x==y)
	return x;
	for(int i=20;i>=0;i--)
	if(fa[x][i]!=fa[y][i])
	x=fa[x][i],y=fa[y][i];
	return fa[x][0];
}
int solve(int l,int r,int k){
	int anss=0;
	if(k==1){
		for(int i=l;i<=r;i++)
		anss=max(anss,dis[i]);
		return anss;
	}
	for(int i=l;i+k-1<=r;i++){
		int to=i+k-1,lca=LCA(i,i+1);
		for(int j=i+1;j<to;j++)
		lca=LCA(j,j+1);
		anss=max(anss,dis[lca]);
	}
	return anss;
}
int main(){
	freopen("query.in","r",stdin);
	freopen("query.out","w",stdout);
	cin>>n;
	for(int i=1;i<n;i++){
		int u,v;
		scanf("%d%d",&u,&v);
		add(u,v);
		add(v,u);
	}
	dfs(1,0);
	cin>>q;
	build(1,1,n);
	for(int i=1;i<=q;i++){
		int l,r,k;
		scanf("%d%d%d",&l,&r,&k);
		if(n<=500)
		cout<<solve(l,r,k)<<'\n';
		else{ 
			cout<<query(1,l,r)<<'\n';
		}
	}
	return 0;
} 
