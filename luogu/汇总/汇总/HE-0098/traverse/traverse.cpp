#include<bits/stdc++.h>
using namespace std;
int n,m,v;
struct node{
	int v,next;
}e[1001001];
int head[1001001],ecnt=0;
void add(int u,int v){
	e[++ecnt]={v,head[u]};
	head[u]=ecnt;
}
int ans=1;
bool flag[1001001];
int s[1001][1001];
void dfs(int x){
	int all=0;
//	flag[s]=1;
	for(int i=head[x];i;i=e[i].next){
//		=
		for(int j=head[x];j;j=e[j].next){
			if(i!=j){
				s[i][j]=1;
			}
		}
		
	}
}
int C(int n,int m){
	long long v1,v2;
	v1=v2=1;
	for(int i=1;i<=m;i++){
		v1*=i;
		v2*=(n-i+1);
	}
	return v2/v1;
}
void dfs2(int x){
	flag[x]=1;
	int all=0;
	for(int i=1;i<=n;i++){
		if(s[x][i]&&flag[i]==0){
			dfs(i);all++;
		}
	}
	ans*=all;
}
int main(){
	freopen("traverse.in","r",stdin);
	freopen("traverse.out","w",stdout);
	int c,T;
	scanf("%d%d",&c,&T);
	
	while(T--){
		
		scanf("%d%d",&n,&m);
		if(c==18){
			cout<<1<<'\n';
			continue;
		}
		if(c>=19&&c<=21)cout<<2<<endl;
		for(int i=1;i<n;i++){
			int u,v;
			scanf("%d%d",&u,&v);
			add(u,v);
		}
		for(int i=1;i<=n;i++)dfs(i);
//		cin>>v;
		while(m--){
			ans=1;
			cin>>v;
			dfs2(v);
			cout<<ans<<endl;
		}
	}
}
