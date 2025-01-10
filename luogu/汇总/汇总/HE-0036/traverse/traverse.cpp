#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int c,T,n,k,ans,col[N],tot,head[N];
struct edge{
	int to,nex;
}e[N<<1];
vector<int>E[N];
int dfs(int u,int f,int &sum) {
	if(sum==n-1){return 1;}
	int s=0;
	for(int i=head[u];i;i=e[i].nex) {
		int v=e[i].to;
		if(v==f||col[v]) continue;
		col[v]=1;sum++;
		s=s+dfs(v,u,sum);
	}
	return s;
}
void add(int u,int v){
	e[++tot].to=v;
	e[tot].nex=head[u];
	head[u]=tot;
}
signed main() {
	freopen("traverse.in","r",stdin);
	freopen("traverse.out","w",stdout);
	scanf("%d%d",&c,&T);
	while(T--) {
		scanf("%d%d",&n,&k);
		for(int i=1;i<n;i++) {
			int u,v;
			scanf("%d%d",&u,&v);
			E[u].push_back(i);
			E[v].push_back(i);
		}
		ans=0;
		for(int u=1;u<=n;u++) {
			int len=E[u].size();
			for(int i=0;i<len;i++) {
				for(int j=0;j<i;j++) {
					add(E[u][i],E[u][j]);
					add(E[u][j],E[u][i]);
				}
			}
			E[u].clear();
		}
		for(int i=1;i<=k;i++) {
			int rt;
			scanf("%d",&rt);
			col[rt]=1;int op=1;
			ans=ans+dfs(rt,-1,op);
			for(int j=1;j<=n-1;j++) col[j]=0;
		}
		printf("%d\n",ans);
		tot=0;for(int i=1;i<=n;i++) head[i]=0;
	}
	return 0;
}
