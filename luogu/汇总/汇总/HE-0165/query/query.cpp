#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
int dep[N],f[N][30];
vector<int> g[N];
int n,q,l,r,k,maxn;
void dfs(int u,int fa){
	dep[u]=dep[fa]+1;
	f[u][0]=fa;
	for(int i=1;(1<<i)<=dep[u];i++){
		f[u][i]=f[f[u][i-1]][i-1];
	}
	for(int i=0;i<g[u].size();i++){
		int v=g[u][i];
		if(v==fa)continue;
		dfs(v,u);
	}
}
int read(){
	int k=0,f=1;
	char ch=getchar();
	while(ch<'0'||ch>'9'){
		if(ch=='-')f=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9'){
		k=k*10+ch-'0';
		ch=getchar();
	}
	return k*f;
}
int LCA(int x,int y){
	if(dep[x]>dep[y])swap(x,y);
	for(int i=20;i>=0;i--){
		if(dep[x]<=dep[y]-(1<<i)){
			y=f[y][i];
		}
	}
	if(x==y)return x;
	for(int i=20;i>=0;i--){
		if(f[x][i]==f[y][i])continue;
		x=f[x][i],y=f[y][i];
	}
	return f[x][0];
}
int main(){
	freopen("query.in","r",stdin);
	freopen("query.out","w",stdout);
	n=read();
	for(int i=1;i<n;i++){
		int u,v;
		u=read(),v=read();
		g[u].push_back(v);
		g[v].push_back(u);
	}
	dfs(1,0);
	cin>>q;
	for(int i=1;i<=q;i++){
		l=read(),r=read(),k=read();
		maxn=0;
		for(int j=l;j+k-1<=r;j++){
			int ff=LCA(j,j+k-1);
			maxn=max(maxn,dep[ff]);
		}
		cout<<maxn<<endl;
	}
	return 0;
}
