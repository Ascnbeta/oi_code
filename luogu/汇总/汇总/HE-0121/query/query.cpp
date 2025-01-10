#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
const int MAXN=5e5+10;
inline int read(){
	int xx=0,ff=1;
	char ch=getchar();
	while(ch<'0'||ch>'9') {
		if(ch=='-') ff=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9'){
		xx=xx*10+ch-48;
		ch=getchar();
	}
	return xx*ff;
}
int n,q;
int depth[MAXN],dfn[MAXN],tim;
vector<int> G[MAXN];
void dfs(int u,int f){
	depth[u]=depth[f]+1; 
}
int main(){
	freopen("query.in","r",stdin);
	freopen("query.out","w",stdout);
	n=read();
	for(int i=1,u,v;i<=n-1;++i){
		u=read(); v=read(); G[u].push_back(v); G[v].push_back(u);
	}
	dfs(1,0);
	q=read();
	while(q--){
		
	}
	return 0;
}
