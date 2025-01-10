#include<bits/stdc++.h>
using namespace std;
using llt=long long;
using llf=long double;
using ull=unsigned long long;
#define endl '\n'
#ifdef LOCAL
	FILE *InFile=freopen("in_out/in.in","r",stdin),*OutFile=freopen("in_out/out.out","w",stdout);
#else
	FILE *InFile=freopen("query.in","r",stdin),*OutFile=freopen("query.out","w",stdout);
#endif

const int N=5e5+3;
int n,q,dep[N];

struct Gph{
	int hd[N],nt[N<<1],to[N<<1],tot=1;
	void Add(int u,int v){to[++tot]=v,nt[tot]=hd[u],hd[u]=tot;}
	void ADD(int u,int v){Add(u,v),Add(v,u);}
#define For_to(i,u,v,g) for(int i=g.hd[u],v=g.to[i];i;i=g.nt[i],v=g.to[i])
}g;

class LCA{
private:
	int dfn[N],fa[N],top[N],sz[N],son[N],tdn;
	void dfs1(int u,int d){dep[u]=d; For_to(i,u,v,g) if(!dep[v]) fa[v]=u,dfs1(v,d+1),sz[u]+=sz[v],sz[son[u]]<sz[v]&&(son[u]=v);}
	void dfs2(int u,int t){top[u]=t,dfn[u]=++tdn; if(son[u]) dfs2(son[u],t); For_to(i,u,v,g) if(!top[v]) dfs2(v,v);}
public:
	void In(){dfs1(1,1),dfs2(1,1);}
	int operator()(int u,int v){
		while(top[u]!=top[v]){
			if(dep[top[u]]<dep[top[v]]) swap(u,v);
			u=fa[top[u]];
		}
		if(dep[u]<dep[v]) swap(u,v); return v;
	}
}Lca;

class St{
private: int lc[23][N];
public:
	void In(){
		for(int i=1;i<=n;++i) lc[0][i]=i;
		for(int i=1;i<=20;++i) for(int j=1;j+(1<<i)-1<=n;++j) lc[i][j]=Lca(lc[i-1][j],lc[i-1][j+(1<<i-1)]);
	}
	int operator()(int l,int r){int k=__lg(r-l+1); return Lca(lc[k][l],lc[k][r-(1<<k)+1]);}
}st;

int main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n; for(int i=1;i<n;++i){int u,v; cin>>u>>v; g.ADD(u,v);} Lca.In(),st.In();
	cin>>q;
	for(int i=1;i<=q;++i){
		int l,r,k,ans=0; cin>>l>>r>>k; r=r-(--k);
		for(int j=l;j<=r;++j) ans=max(ans,dep[st(j,j+k)]);
		cout<<ans<<endl;
	}
}