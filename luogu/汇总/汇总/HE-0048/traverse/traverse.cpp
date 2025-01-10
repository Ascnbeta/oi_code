#include<bits/stdc++.h>
#define int long long

using namespace std;
const int N = 1e5 + 10;
const int mod = 1e9 + 7;

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
inline void writeln(int x){write(x);puts("");}

int T , n , id , pos[N] , k;
int h[N] , tot;
struct node{
	int to , nxt;
} e[N << 1];

inline void add(int u , int v){
	e[++tot].to = v;
	e[tot].nxt = h[u];
	h[u] = tot;	
}

signed main(){
freopen("traverse.in" , "r" , stdin);freopen("traverse.out" , "w" , stdout);
	id = read() ; T = read();
	while(T--){
		n = read(); k = read();
		pos[0] = 1;
		int ans = 1;
		for (int i = 1 ; i <= n ; i++){
			pos[i] = pos[i - 1] * i % mod;	
		}
		for (int i = 1 ; i < n ; i++){
			int u , v;
			u = read() ; v = read();	
		}
		
		writeln(pos[n] % mod);
	}
	
	return 0;	
}
