#include<bits/stdc++.h>
using namespace std;
int dfn[1001001];
struct node{
	int v,next;
}e[1001001];
int head[1001001],ecnt=0;
void add(int u,int v){
	e[++ecnt]={v,head[u]};
	head[u]=ecnt;
}
void dfs(int s,int rot){
	dfn[s]=rot;
	for(int i=head[s];i;i=e[i].next){
		int v=e[i].v;
		if(dfn[v]==0){
			dfs(v,rot+1);
		}
	}
}
int LCA(int a,int b){
	
}
int main(){
	freopen("query.in","r",stdin);
	freopen("query.out","w",stdout);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		int u,v;
		scanf("%d%d",&u,&v);
		add(u,v);add(v,u);
	}
	int q;
	cin>>q;
	while(q--){
		int l,r,k;
		scanf("%d%d%d",l,r,k);
		for(int i=l;i<=r-k;i++){
			for(int j=i;j<=i+k;j++){
				
			}
		}
	}
}
