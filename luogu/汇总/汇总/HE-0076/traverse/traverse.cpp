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
const int N = 1e5+10,mod = 1e9+7;
int n,m;
struct{
	int to,nex;
}edge[N<<1];
int head[N],edge_num = 1,ind[N];
inline void add(int x,int y,int i){
	edge[++edge_num].to = y;
	edge[edge_num].nex = head[x];
	head[x] = edge_num;
	++ind[y];
	//pos = edge_num>>1
}
inline void dfs(int now,int fu){
//	cout << now << " " << fu << endl;
	for(int i=head[now];i;i=edge[i].nex){
		int tto = edge[i].to;
		if(tto==fu) continue;
		dfs(tto,now);
	}
}
int num = 0;
int vis[N];
inline void dfs2(int now,int fu){
	for(int i=head[now];i;i=edge[i].nex){
		int tto  = edge[i].to;
		if(tto==fu) continue;
		if(ind[tto]>1) num *= ind[tto]-1; 
		dfs2(tto,now);
	}
}
inline void Init(){
	edge_num = 0;
	memset(head,0,sizeof(head));
}
int main(){
	freopen("traverse.in","r",stdin);
	freopen("traverse.out","w",stdout);

	int C,T;read(C,T);
	while(T--){
		Init();
		read(n,m);
		for(int i=1,u,v;i<n;++i){
			read(u,v);
			add(u,v,i);add(v,u,i);
		}
		dfs(1,0);
		int ans = 0;
		for(int i=1,u;i<=m;++i){
			read(u);
			num = 1;
			if(ind[edge[(u<<1)-1].to]<=ind[edge[u<<1].to]){
				if(ind[edge[(u<<1)-1].to]>1) num = ind[edge[(u<<1)-1].to]-1;
				dfs2(edge[(u<<1)-1].to,0);
			}
			else{
				if(ind[edge[(u<<1)].to]>1) num = ind[edge[(u<<1)].to]-1;
				dfs2(edge[(u<<1)].to,0);
			}
			ans += num;
		}
		printf("%d\n",ans);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
