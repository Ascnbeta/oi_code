#include<bits/stdc++.h>
#define int long long

using namespace std;
const int N = 5e5 + 10;
const int INF = 1e9 + 7;

inline int read(){
	int w = 0 , f = 1; char ch = getchar();
	while(ch < '0' || ch > '9'){if(ch == '-') f = -1; ch = getchar();}
	while(ch >= '0' && ch <= '9'){w = (w << 3) + (w << 1) - 48 + ch; ch = getchar();}
	return w * f;
}

inline void write(int x){
	if(x < 0) putchar('-') , x = -x;	
	if(x > 9) write(x / 10);
	putchar('0' + x % 10);
}

int T , n;
int h[N] , tot;
struct node{
	int to , nxt;
} e[N << 1];

inline void add(int u , int v){
	e[++tot].to = v;
	e[tot].nxt = h[u];
	h[u] = tot;	
}

int dep[N] , son[N] , sze[N] , fa[N];
inline void dfs(int u , int f){
	fa[u] = f , dep[u] = dep[f] + 1 , sze[u] = 1 , son[u] = 0;
	for (int i = h[u] ; i ; i = e[i].nxt){
		int y = e[i].to;
		if(y == f) continue;
		dfs(y , u);
		sze[u] += sze[y];
		if(sze[y] > sze[son[u]]) son[u] = y;
	}
}
int top[N];
inline void hld(int u , int topf){
	top[u] = topf;
	if(son[u]) hld(son[u] , topf);
	else return;	
	for (int i = h[u] ; i ; i = e[i].nxt){
		int y = e[i].to;
		if(y == fa[u] || y == son[u]) continue;
		hld(y , y);	
	}
}

inline int LCA(int x , int y){
	while(top[x] != top[y]){
		if(dep[top[x]] < dep[top[y]]) swap(x , y);
		x = fa[top[x]];
	}
	if(dep[x] < dep[y]) return x;
	return y;
}

signed main(){
freopen("query.in" , "r" , stdin) ; freopen("query.out" , "w" , stdout);
	T = read();
	while(T--){
		n = read();
		int t = 0;
		for (int i = 1 ; i < n ; i++){
			int u , v;
			u = read() , v = read();
			add(u , v);
			add(v , u);
		}
		dfs(1 , 0);
		hld(1 , 1);
		int q = 0;
		q = read();
		for (int i = 1 ; i <= q ; i++){
			int l , r , k;
			int ans = INF;
			l = read() , r = read() , k = read();
			for (int j = l ; j <= r - k + 1 ; j++){
				int v = j;
				for (int s = j + 1 ; s <= r ; s++ ){
					v = LCA(v , s);
					if(s - j + 1 >= k) ans = min(ans , dep[v]);
				}
			}
			cout << ans << "\n";
		}
	}
	return 0;
}
