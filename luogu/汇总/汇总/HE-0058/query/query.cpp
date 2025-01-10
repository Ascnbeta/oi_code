#include<bits/stdc++.h>
using namespace std;
const int MAXN=5e5+25;
int n;
struct Edge{
	int v,nxt;
}edge[MAXN];
int cnt,head[MAXN];
void add(int u,int v){
	edge[++cnt]={v,head[u]};
	head[u]=cnt;
}
int deep[MAXN],anc[MAXN][20];
void dfs(int u,int la){
	deep[u]=deep[la]+1;
	anc[u][0]=la;
	for(int i=1;i<=19;i++) anc[u][i]=anc[anc[u][i-1]][i-1];
	for(int i=head[u];i;i=edge[i].nxt){
		int v=edge[i].v;
		if(v==la) continue;
		dfs(v,u);
	}
}
int LCA(int a,int b){
	if(deep[a]<deep[b]) swap(a,b);
	for(int i=19;i>=0;i--){
		if(deep[anc[a][i]]>=deep[b]){
			a=anc[a][i];
		}
		if(a==b) return a;
	}
	for(int i=19;i>=0;i--){
		if(anc[a][i] != anc[b][i]){
			a=anc[a][i];
			b=anc[b][i];
		}
	}
	return anc[a][0];
}
int l[MAXN][20];
int main(){
	freopen("query.in","r",stdin);
	freopen("query.out","w",stdout);
	
	
	scanf("%d",&n);
	for(int i=1;i<=n-1;i++){
		int u,v;scanf("%d%d",&u,&v);
		add(u,v);
		add(v,u);
	}
	dfs(1,0);
	
	
	for(int i=1;i<=n;i++) l[i][0]=i;
	for(int i=1;i<=19;i++){
		int wei=(1<<i);
		for(int j=1;j+wei-1<=n;j++){
			l[j][i]=LCA(l[j][i-1],l[j+(wei/2)][i-1]);
		}
	}
	
	
	
	
	int q;scanf("%d",&q);
	for(int i=1;i<=q;i++){
		int L,r,k;scanf("%d%d%d",&L,&r,&k);
		int ans=-1;
		for(int j=k;j<=r-L+1;j++){
			for(int g=L;g<=r-j+1;g++){
				int left=g;
				int right=left+j-1;
				int lg=log2(right-left+1);
				int lca=LCA(l[left][lg],l[right-(1<<lg)+1][lg]);
				ans=max(ans,deep[lca]);
			}
		}
		printf("%d\n",ans);
	}		

	
	return 0;
}
