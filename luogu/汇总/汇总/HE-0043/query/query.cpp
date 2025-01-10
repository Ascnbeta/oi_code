#include<bits/stdc++.h>
#define fi first 
#define se second
#define eb emplace_back
#define pb push_back
#define pii std::pair<int,int>
typedef long long ll;
inline int read(){char ch=getchar();int x=0,f=1;for(;ch<'0'||ch>'9';ch=getchar())if(ch=='-')f=-1;for(;ch>='0'&&ch<='9';ch=getchar())x=x*10+(ch^48);return f*x;}
inline void Max(int &x,int y){x=std::max(x,y);}
inline void Min(int &x,int y){x=std::min(x,y);}
const int N=5e5+10,LEN=350,inf=1e9;
int n,Q,len;
std::vector<int> e[N];
struct QU{
	int l,r,k;
}q[N];
int dn,dfn[N],st[20][N],dep[N],sta[20][N];
inline void dfs(int x,int fa){
	dep[x]=dep[fa]+1;
	st[0][dfn[x]=++dn]=fa;
	for(int v:e[x])if(v^fa)dfs(v,x);
}
inline int get(int x,int y){return dfn[x]<dfn[y]?x:y;}
inline int LCA(int u,int v){
	if(u==v)return u;
	if((u=dfn[u])>(v=dfn[v]))std::swap(u,v);
	int d=std::__lg(v-u++);
	return get(st[d][u],st[d][v-(1<<d)+1]);
}
inline int qu_LCA(int l,int r){
	if(l==r)return l;
	int d=std::__lg(r-l+1);
	return LCA(sta[d][l],sta[d][r-(1<<d)+1]);
}
inline int getA(int x,int y){return dep[x]>dep[y]?x:y;}
int f[LEN][N],mi[LEN][LEN];
inline int query(int l,int r,int k){
	int res=inf;
	int lid=(l-1)/len+1,rid=(r-1)/len+1;
	if(rid-lid<=1){
		for(int i=l;i<=r;++i)Min(res,f[k][i]);
	}else{
		for(int i=lid+1;i<rid;++i)Min(res,mi[k][i]);
		for(int i=l;(i-1)/len+1==lid;++i)Min(res,f[k][i]);
		for(int i=r;(i-1)/len+1==rid;--i)Min(res,f[k][i]);
	}
	return res;
}
inline void subA(){
	dfs(1,0);
	for(int i=1;i<=n;++i)st[0][i]=dep[i];
	for(int i=1;i<=std::__lg(n);++i)
		for(int j=1;j+(1<<i)-1<=n;++j)
			st[i][j]=std::min(st[i-1][j],st[i-1][j+(1<<i-1)]);
	len=std::sqrt(n);
	for(int i=1;i<=len;++i){
		for(int j=1;j+i-1<=n;++j){
			if(i==1)f[i][j]=dep[j];
			else{
				f[i][j]=std::min(dep[j+i-1],f[i-1][j]);
			}
			int id=(j-1)/len+1;
			if(!mi[i][id])mi[i][id]=f[i][j];
			Min(mi[i][id],f[i][j]);
		}
	}
	for(int i=1;i<=Q;++i){
		int l=q[i].l,r=q[i].r,k=q[i].k;
		if(k<=len){
			std::cout<<query(l,r-k+1,k)<<'\n';
		}else{
			for(int j=l;j+k-1<=r;j+=k){
				int l=j,r=j+k-1;
				int d=std::__lg(r-l+1);
				std::cout<<std::min(st[d][l],st[d][r-(1<<d)+1])<<'\n';
			}
		}
	}
	exit(0);
}
inline void subB(){
	dfs(1,0);
	for(int i=1;i<=std::__lg(n);++i)
		for(int j=1;j+(1<<i)-1<=n;++j)
			st[i][j]=get(st[i-1][j],st[i-1][j+(1<<i-1)]);
	for(int i=1;i<=n;++i)sta[0][i]=i;
	for(int i=1;i<=std::__lg(n);++i)
		for(int j=1;j+(1<<i)-1<=n;++j)
			sta[i][j]=LCA(sta[i-1][j],sta[i-1][j+(1<<i-1)]);
	for(int i=1;i<=Q;++i){
		int l=q[i].l,r=q[i].r;
		std::cout<<dep[qu_LCA(l,r)]<<'\n';
	}
	exit(0);
}
inline void subgen(){
	dfs(1,0);
	for(int i=1;i<=std::__lg(n);++i)
		for(int j=1;j+(1<<i)-1<=n;++j)
			st[i][j]=get(st[i-1][j],st[i-1][j+(1<<i-1)]);
	for(int i=1;i<=n;++i)sta[0][i]=i;
	for(int i=1;i<=std::__lg(n);++i)
		for(int j=1;j+(1<<i)-1<=n;++j)
			sta[i][j]=LCA(sta[i-1][j],sta[i-1][j+(1<<i-1)]);
	for(int i=1;i<=Q;++i){
		int l=q[i].l,r=q[i].r,k=q[i].k;
		int res=0;
		for(int j=l;j+k-1<=r;++j)Max(res,dep[qu_LCA(j,j+k-1)]);
		std::cout<<res<<'\n';
	}
}
signed main(){
	freopen("query.in","r",stdin);freopen("query.out","w",stdout);
	std::ios::sync_with_stdio(false);std::cin.tie(0);std::cout.tie(0);
	n=read();
	for(int i=1;i<n;++i){
		int u=read(),v=read();e[u].eb(v);e[v].eb(u);
	}
	Q=read();
	int check2=0,check1=0,checkB=0;
	for(int i=1;i<=n;++i){
		if(e[i].size()==1)check1++;
		else check2++;
	}
	for(int i=1;i<=Q;++i){
		int l=read(),r=read(),k=read();
		q[i]={l,r,k};
		checkB+=(k==r-l+1);
	}
	if(n<=5e3+10){
		subgen();exit(0);
	}
	if(check1==2&&check2==n-2){
		subA();exit(0);
	}
	if(checkB==Q){
		subB();exit(0);
	}
	subgen();
}
