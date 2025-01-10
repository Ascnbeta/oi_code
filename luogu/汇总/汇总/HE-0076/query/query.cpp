#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<climits>
#include<unordered_map>
using namespace std;
template <typename T>
inline void read(T&x){
	int w = 0;x = 0;
	char ch = getchar();
	while(ch<'0' || ch>'9'){
		if(ch=='-') w = 1;
		ch = getchar();
	}
	while(ch>='0' && ch<='9'){
		x = (x<<1)+(x<<3)+(ch^48);
		ch = getchar();
	}
	if(w) x = -x; 
}
template <typename T,typename...Args>
inline void read(T&t,Args&...args){
	read(t);read(args...);
}
const int N = 5e5+10;
int n,m;
struct{
	int to,nex;
}edge[N<<1];
int head[N],edge_num,ind[N];
inline void add(int x,int y){
	edge[++edge_num].to = y;
	edge[edge_num].nex = head[x];
	head[x] = edge_num;
	++ind[y];
}
int dep[N],fa[21][N];
inline void dfs(int now,int fu){
	dep[now] = dep[fu]+1;
	fa[0][now] = fu;
	for(int i=1;(1<<i)<=dep[now];++i) fa[i][now] = fa[i-1][fa[i-1][now]];
	for(int i=head[now];i;i=edge[i].nex){
		int tto = edge[i].to;
		if(tto==fu) continue;
		dfs(tto,now);
	}
}
inline int lca(int x,int y){
	if(dep[x]>dep[y]) swap(x,y);
	for(int i=20;i>=0;--i){
		if(dep[fa[i][y]]>=dep[x]) y = fa[i][y];
	}
	if(x==y) return x;
	for(int i=20;i>=0;--i){
		if(fa[i][y]!=fa[i][x]){
			y = fa[i][y];
			x = fa[i][x];
		}
	}
	return fa[0][x];
}
int main(){
	freopen("query.in","r",stdin);
	freopen("query.out","w",stdout);
	
	read(n);
	for(int i=1,u,v;i<n;++i){
		read(u,v);
		add(u,v);add(v,u);
	}
	dfs(1,0);
	read(m);
	for(int i=1,l,r,k;i<=m;++i){
		read(l,r,k);
		int ans = 0;
		for(int i=l;i+k-1<=r;++i){
			int j = i+k-1;
			int t = i;
			for(int p=i+1;p<=j;++p){
				t = lca(t,p);
			}
//			cout << t << endl;
			if(dep[t]>ans) ans = dep[t];
		}
		printf("%d\n",ans);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
