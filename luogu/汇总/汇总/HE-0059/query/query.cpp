#include<bits/stdc++.h>
using namespace std;
#define ls w*2
#define rs w*2+1
const int N=5e6+10;
int n,q;
int dfn[N],bk[N],num;
int st[N][25],dep[N];
struct edge{
	int nxt,to;
}a[N];
struct tree{
	int mx,mn;
}t[N];
int head[N],tot;
void add(int u,int v) {
	a[++tot].nxt=head[u];
	a[tot].to=v;
	head[u]=tot;
}
void dfs(int x,int fa) {
	dfn[x]=++num;
//	cout<<x<<' '<<num<<' '<<fa<<'\n';
//	cout<<num<<'\n';
	bk[num]=x;
	dep[x]=dep[fa]+1;
	st[x][0]=fa;
	for(int i=1;i<=20;i++) st[x][i]=st[st[x][i-1]][i-1];
	for(int i=head[x];i;i=a[i].nxt) {
		int to=a[i].to;
//		cout<<to<<'\n';
		if(dfn[to]) continue;
		dfs(to,x);
	}
}
int lca(int x,int y) {
	if(dep[x]<dep[y]) swap(x,y);
	for(int i=20;i>=0;i--) {
		if(dep[st[x][i]]>=dep[y]) x=st[x][i];
	}
	for(int i=20;i>=0;i--) {
		if(st[x][i]!=st[y][i]) x=st[x][i],y=st[y][i];	
	}
	if(x==y) return x;
	return st[x][0];
}
void up(int w) {
	t[w].mx=max(t[ls].mx,t[rs].mx);
	t[w].mn=min(t[ls].mn,t[rs].mn);
}
void build(int w,int l,int r) {
	if(l==r) {
		t[w].mx=dfn[l];
		t[w].mn=dfn[l];
		return;
	}
	int mid=(l+r)/2;
	build(ls,l,mid);
	build(rs,mid+1,r);
	up(w);
}
int qmx(int w,int l,int r,int x,int y) {
	if(x<=l&&r<=y) return t[w].mx;
	int mid=(l+r)/2,res=0;
	if(x<=mid) res=max(res,qmx(ls,l,mid,x,y));
	if(y>mid) res=max(res,qmx(rs,mid+1,r,x,y));
	return res;
}
int qmn(int w,int l,int r,int x,int y) {
	if(x<=l&&r<=y) return t[w].mn;
	int mid=(l+r)/2,res=2e9;
	if(x<=mid) res=min(res,qmn(ls,l,mid,x,y));
	if(y>mid) res=min(res,qmn(rs,mid+1,r,x,y));
	return res;
}
int main() {
	freopen("query.in","r",stdin);
	freopen("query.out","w",stdout);
	cin>>n;
	for(int i=1;i<n;i++) {
		int u,v;
		cin>>u>>v;
		add(u,v),add(v,u);
	}
	dfs(1,0);
	build(1,1,n);
	cin>>q;
	while(q--) {
		int l,r,k,ans=0;
		cin>>l>>r>>k;
		if(k==1) {
			for(int i=l;i<=r;i++) ans=max(ans,dep[i]);
			cout<<ans<<'\n';
			continue;
		}
		for(int i=l+k-1;i<=r;i++) {
			int mx=qmx(1,1,n,i-k+1,i),mn=qmn(1,1,n,i-k+1,i);
//			cout<<":"<<mx<<' '<<mn<<'\n';
			int anc=lca(bk[mx],bk[mn]);
			ans=max(ans,dep[anc]);
		}
		cout<<ans<<'\n';
	}
	return 0;
}
