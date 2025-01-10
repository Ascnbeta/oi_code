#include<algorithm>
#include<iostream>
#include<string.h>
#include<stdio.h>
#include<string>
#include<vector>
#include<math.h>
#include<stack>
#include<queue>
#include<set>
#include<map>
using namespace std;
int read(){
	int s=0,f=1;
	char _z=getchar();
	while(_z<'0'||_z>'9'){
		if(_z=='-')
		f=-1;
		_z=getchar();
	}
	while(_z>='0'&&_z<='9'){
		s=(s<<3)+(s<<1)+(_z-'0');
		_z=getchar();
	}
	return s*f;
}
const int N=5e5+10;
struct no{
	int v,to;
}node[N*2];
int head[N],idx=0;
void add(int u,int v){
	idx++;
	node[idx].v=v;
	node[idx].to=head[u];
	head[u]=idx;
	return;
}
int lg[N];
int dep[N],fa[N][20],st[N][20];
void dfs(int u,int father){
	dep[u]=dep[father]+1;
	fa[u][0]=father;
	for(int i=head[u];i;i=node[i].to){
		int v=node[i].v;
		if(v!=father){
			dfs(v,u);
		}
	}
	return;
}
int LCA(int u,int v){
	if(dep[v]>dep[u])
	swap(u,v);
	for(int i=19;i>=0;i--){
		if(dep[fa[u][i]]>=dep[v])
		u=fa[u][i];
	}
	if(u==v)
	return u;
	for(int i=19;i>=0;i--){
		if(fa[u][i]!=fa[v][i])
		u=fa[u][i],v=fa[v][i];
	}
	return fa[u][0];
}
int main(){
	freopen("query.in","r",stdin);
	freopen("query.out","w",stdout);
	int n=read();
	for(int i=2;i<=n;i++)
	lg[i]=lg[i/2]+1;
	for(int i=1;i<n;i++){
		int u=read(),v=read();
		add(u,v);add(v,u);
	}
	dfs(1,0);
	for(int i=1;i<20;i++)
	for(int u=1;u<=n;u++)
	fa[u][i]=fa[fa[u][i-1]][i-1];
	for(int u=1;u<=n;u++)
	st[u][0]=u;
	for(int i=1;i<20;i++)
	for(int u=1;u<=n-(1<<(i-1));u++)
	st[u][i]=LCA(st[u][i-1],st[u+(1<<(i-1))][i-1]);
	int q=read();
	while(q--){
		int L=read(),R=read(),k=read(),ans=-1;
		for(int l=L;l<=R-k+1;l++){
			int r=l+k-1;
			int lca=LCA(st[l][lg[k]],st[r-(1<<lg[k])+1][lg[k]]);
			ans=max(ans,dep[lca]);
		}
		printf("%d\n",ans);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
