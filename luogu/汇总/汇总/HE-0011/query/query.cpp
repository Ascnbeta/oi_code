#include<bits/stdc++.h>
using namespace std;

#define pb push_back
#define U(x) ((int)x.size())
#define ar(x) array<int,x>
const int N=5e5+100,B=19,_N=(1<<20);
char *_l,*_r,buf[_N];
//#define gc getchar()
#define gc (_l==_r&&(_r=(_l=buf)+fread(buf,1,_N,stdin)),_l!=_r?*_l++:EOF)
#define rd read()
inline int read(){
	int x=0,f=0; char c=gc;
	for(;c<'0'||c>'9';c=gc) f|=(c=='-');
	for(;c>='0'&&c<='9';c=gc) x=(x<<1)+(x<<3)+(c^48);
	return f?-x:x;
}

int n,m,dfn[N],d_c=0,dep[N],fdep[N],st[N][B+2],mn[N][B+2],mx[N][B+2];
vector<int> G[N];
inline int get(int x,int y){ return dfn[x]<dfn[y]?x:y; }
inline int gmn(int x,int y){ return dfn[x]<dfn[y]?x:y; }
inline int gmx(int x,int y){ return dfn[x]>dfn[y]?x:y; }

void dfs0(int u,int fu){
	st[dfn[u]=++d_c][0]=fu,dep[u]=dep[fu]+1,fdep[dep[u]]=u;
	for(int v:G[u]) if(v!=fu) dfs0(v,u);
}
inline void init(){
	for(int i=1;i<=n;++i) mn[i][0]=mx[i][0]=i;
	for(int k=1;k<=B;++k) for(int i=1;i+(1<<k)-1<=n;++i){
		mn[i][k]=gmn(mn[i][k-1],mn[i+(1<<(k-1))][k-1]);
		mx[i][k]=gmx(mx[i][k-1],mx[i+(1<<(k-1))][k-1]);
		st[i][k]=get(st[i][k-1],st[i+(1<<(k-1))][k-1]);
	}	
}
inline int flca(int x,int y){ if(x==y) return x; if((x=dfn[x])>(y=dfn[y])) swap(x,y); int k=__lg(y-(++x)+1); return get(st[x][k],st[y+1-(1<<k)][k]); }
inline int ask_mn(int l,int r){ int k=__lg(r-l+1); return gmn(mn[l][k],mn[r+1-(1<<k)][k]); }
inline int ask_mx(int l,int r){ int k=__lg(r-l+1); return gmx(mx[l][k],mx[r+1-(1<<k)][k]); }

inline int is(){
	if(U(G[1])!=1) return 0; int cnt=0;
	for(int i=2;i<=n;++i){
		if(U(G[i])==1) ++cnt;
		else if(U(G[i])!=2) return 0;
	}
	return cnt==1;
}

struct ADJ{ int mx,lm,rm,f; void init(int v){ mx=lm=rm=f=v; } };
inline ADJ operator+(const ADJ &x,const ADJ &y){
	ADJ res;
	res.mx=max({x.mx,y.mx,x.rm+y.lm});
	res.lm=x.lm; if(x.f) res.lm+=y.lm;
	res.rm=y.rm; if(y.f) res.rm+=x.rm;
	res.f=x.f&y.f;
	return res;
}
struct SMT{
	#define lc (id<<1)
	#define rc (id<<1|1)
	#define mid (l+r>>1)
	ADJ t[N<<2];
	void psu(int id){ t[id]=t[lc]+t[rc]; }
	void chg(int id,int l,int r,int ql,int v){
		if(l==r) return t[id].init(v),void();
		ql<=mid?chg(lc,l,mid,ql,v):chg(rc,mid+1,r,ql,v); psu(id);
	}
	ADJ ask(int id,int l,int r,int ql,int qr){
		if(ql<=l&&r<=qr) return t[id];
		if(qr<=mid) return ask(lc,l,mid,ql,qr);
		if(ql>=mid+1) return ask(rc,mid+1,r,ql,qr);
		ADJ a=ask(lc,l,mid,ql,qr),b=ask(rc,mid+1,r,ql,qr);
		return a+b;
	} 
	#undef lc
	#undef rc
	#undef mid
}S;

struct QUE{ int l,r,k,id; }que[N],_que[N]; int ans[N];

int pt;
inline void mov(int x){
	for(;pt<x;++pt) S.chg(1,1,n,fdep[pt],0);
	for(;pt>x;--pt) S.chg(1,1,n,fdep[pt-1],1);
}

int cnt=0;

void sol(int l,int r,int ql,int qr){
	if(l==r){ for(int i=ql;i<=qr;++i) ans[que[i].id]=l; }
	if(l>=r||ql>qr) return;
	int mid=l+r+1>>1,_ql=ql-1,_qr=qr+1; mov(mid);
	for(int i=ql;i<=qr;++i){
		if(S.ask(1,1,n,que[i].l,que[i].r).mx>=que[i].k) _que[--_qr]=que[i];
		else _que[++_ql]=que[i];
	}
	for(int i=ql;i<=qr;++i) que[i]=_que[i];
	sol(l,mid-1,ql,_ql),sol(mid,r,_qr,qr);
}

void sol1(){
	m=rd,pt=n+1; for(int i=1;i<=m;++i) que[i]={rd,rd,rd,i};
	
	sol(1,n,1,m);
	
	for(int i=1;i<=m;++i) printf("%d\n", ans[i]);
}
inline int ask(int l,int r,int k){
	int res=0;
	for(int i=l,j;(j=i+k-1)<=r;++i) res=max(res,dep[flca(ask_mn(i,j),ask_mx(i,j))]);
	return res;
}
void sol2(){
	init(),m=rd;
	for(int i=1,l,r,k;i<=m;++i){
		l=rd,r=rd,k=rd;
		printf("%d\n", ask(l,r,k));
	}
}

int main(){

	freopen("query.in","r",stdin);
	freopen("query.out","w",stdout);

	n=rd; for(int i=1,x,y;i<n;++i) x=rd,y=rd,G[x].pb(y),G[y].pb(x);
	
	dfs0(1,0);
	
	if(is()) sol1();
	else sol2();
	
	cerr<<clock()<<"ms\n";
	
	return 0;
}
/*
6
5 6
6 1
6 2
2 3
2 4
3
2 5 2
1 4 1
1 6 3

*/
