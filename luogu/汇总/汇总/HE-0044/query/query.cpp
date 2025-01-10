#include<bits/stdc++.h>
#define rpt(a,b,c) for(int a=b;a<=c;a++)
#define tpr(a,b,c) for(int a=b;a>=c;a--)
#define rep(i,u) for(int i=Head[u];i;i=e[i].n)
using namespace std;
const int N=5e5+10;
struct edge{
	int n,t;
}e[N<<1];
int Head[N],cnte;
void add(int u,int v){
	e[++cnte]=edge{Head[u],v};
	Head[u]=cnte;
}
int fa[N][30],dfn[N],dep[N],cnt,id[N];
void dfs(int u){
	dfn[u]=++cnt; id[cnt]=u; dep[u]=dep[fa[u][0]]+1;
	rpt(i,1,25)fa[u][i]=fa[fa[u][i-1]][i-1];
	rep(i,u){
		int v=e[i].t;
		if(v==fa[u][0])continue;
		fa[v][0]=u; dfs(v);
	}
}
int LCA(int u,int v){
	if(dep[u]<dep[v])swap(u,v);
	tpr(i,25,0)if(dep[fa[u][i]]>=dep[v])u=fa[u][i];
	if(u==v)return dep[u];
	tpr(i,25,0)if(fa[u][i]!=fa[v][i])u=fa[u][i],v=fa[v][i];
	return dep[fa[u][0]];
}
struct node{
	node *ls,*rs;
	int l,r,Max,Min;
	void pushup(){
		Max=max(ls->Max,rs->Max);
		Min=min(ls->Min,rs->Min);
	}
	int getmin(int L,int R){
		if(R>=r&&l>=L)return Min;
		if(ls->r>=R)return ls->getmin(L,R);
		if(rs->l<=L)return rs->getmin(L,R);
		return min(ls->getmin(L,R),rs->getmin(L,R));
	}
	int getmax(int L,int R){
		if(R>=r&&l>=L)return Max;
		if(ls->r>=R)return ls->getmax(L,R);
		if(rs->l<=L)return rs->getmax(L,R);
		return max(ls->getmax(L,R),rs->getmax(L,R));
	}
}*rt;
node *build(int L,int R){
	node *p=new node; p->l=L; p->r=R;
	p->ls=p->rs=NULL;
	if(L==R){p->Max=p->Min=dfn[L]; return p;}
	int mid=L+R>>1; p->ls=build(L,mid);
	p->rs=build(mid+1,R); p->pushup();
	return p;
}
int n,q,u,v,l,r,k;
int main(){
	freopen("query.in","r",stdin);
	freopen("query.out","w",stdout);
	scanf("%d",&n);
	rpt(i,1,n-1){
		scanf("%d%d",&u,&v);
		add(u,v); add(v,u);
	}
	
	dfs(1); rt=build(1,n);
	scanf("%d",&q);
	while(q--){
		scanf("%d%d%d",&l,&r,&k);
		int ans=0;
		rpt(i,l,r-k+1){
			ans=max(ans,LCA(id[rt->getmin(i,i+k-1)],id[rt->getmax(i,i+k-1)]));
		}
		printf("%d\n",ans);
	}
	return 0;
}
