#include<bits/stdc++.h>
typedef long long ll;
typedef unsigned long long ull;
#define pa pair<int,int>
#define qr qr()
#define ve vector
#define fi first
#define se second
#define ps push_back
#define lc rt<<1
#define rc rt<<1|1
using namespace std;
const int N=3e5+200;
inline int qr{
	int x=0;char ch=getchar();bool f=0;
	while(ch>57||ch<48)f=(ch=='-')?1:0,ch=getchar();
	while(ch<=57&&ch>=48)x=(x<<3)+(x<<1)+(ch^48),ch=getchar();
	return f?-x:x;
}
int n,m,a[N];
struct node{
	int t,nx;
}e[N<<1];
int tot,h[N],dep[N];
inline void add(int f,int t){
	e[++tot]={t,h[f]};h[f]=tot;
}
void dfs(int u,int f){
	dep[u]=dep[f]+1;
	for(int i=h[u];i;i=e[i].nx){
		int v=e[i].t;
		if(v==f)continue;
		dfs(v,u);
	}
}
int t[N<<2];
inline void up(int rt){
	t[rt]=min(t[lc],t[rc]);
}
void build(int rt,int l,int r){
	if(l==r)return t[rt]=dep[l],void(0);
	int md=l+r>>1;
	build(lc,l,md);build(rc,md+1,r);
	up(rt);
}
int ask(int rt,int L,int R,int l,int r){
	if(L>=l&&R<=r)return t[rt];
	int md=L+R>>1,ans=n;
	if(md>=l)ans=min(ans,ask(lc,L,md,l,r));
	if(md<r)ans=min(ans,ask(rc,md+1,R,l,r));
	return ans;
}
void init(){
	n=qr;
	for(int i=1,f,t;i<n;++i){
		f=qr;t=qr;
		add(f,t);add(t,f);
	}
	m=qr;dep[1]=1;
	dfs(1,0);
	build(1,1,n);
	for(int i=1,l,r,k;i<=m;++i){
		l=qr;r=qr;k=qr;
		cout<<ask(1,1,n,l,r)<<'\n';
	}
}
int main(){

	freopen("query.in","r",stdin);
	freopen("query.out","w",stdout);

	init();
	return 0;
}

