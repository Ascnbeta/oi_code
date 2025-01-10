#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
int n,m,a[N];
int x,y,z,k,t,l,r;
#define ls rt<<1
#define rs rt<<1|1
struct pp{
	int l,r,dep,lca;
}tr[N<<2];
int f[N][20],dep[N];
int h[N],tot;
struct bp{
	int nxt,to;
}e[N<<1];
void add(int x,int y){
	e[++tot]={h[x],y};
	h[x]=tot;
}
void dfs(int x,int fa){
	dep[x]=dep[fa]+1;
	f[x][0]=fa;
	for(int i=1;i<=19;i++)f[x][i]=f[f[x][i-1]][i-1];
	for(int i=h[x];i;i=e[i].nxt){
		int y=e[i].to;
		if(y==fa)continue;
		dfs(y,x);
	}
}
int lca(int x,int y){
	if(dep[x]<dep[y])swap(x,y);
	for(int i=19;i>=0;i--)if(dep[f[x][i]]>=dep[y])x=f[x][i];
	if(x==y)return x;
	for(int i=19;i>=0;i--)if(f[x][i]!=f[y][i])x=f[x][i],y=f[y][i];
	return f[x][0];
}
void build(int rt,int l,int r){
	tr[rt].l=l;tr[rt].r=r;
	if(l==r)return tr[rt].lca=l,void();
	int mid=(l+r)>>1;
	build(ls,l,mid);build(rs,mid+1,r);
	tr[rt].lca=lca(tr[ls].lca,tr[rs].lca);
}
int query(int rt,int l,int r){
	// cout<<l<<' '<<r<<' '<<tr[rt].l<<' '<<tr[rt].r<<endl;
	if(l<=tr[rt].l&&tr[rt].r<=r)return tr[rt].lca;
	int mid=(tr[rt].l+tr[rt].r)>>1;
	if(l<=mid&&r>mid)return lca(query(ls,l,r),query(rs,l,r));
	if(l<=mid)return query(ls,l,r);
	return query(rs,l,r);
}
int main(){
	freopen("query.in","r",stdin);
	freopen("query.out","w",stdout);
	cin>>n;
	for(int i=1;i<n;i++){
		cin>>x>>y;
		add(x,y);add(y,x);
	}
	dfs(1,0);
	build(1,1,n);
	cin>>m;
	while(m--){
		cin>>l>>r>>k;
		int ans=0;
		for(int i=l;i+k-1<=r;i++){
			// cout<<i<<' '<<i+k-1<<endl<<' '<<query(1,i,i+k-1)<<endl;
			ans=max(ans,dep[query(1,i,i+k-1)]);
		}cout<<ans<<'\n';
	}
	return 0;
}
