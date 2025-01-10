#include<bits/stdc++.h>
#define int long long

using namespace std;
const int N = 1e6 + 10;
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

int n , m , T , v;
int x[N];

inline int qmi(int a , int b){
	int res = 1;
	while(b){
		if(b & 1) res = res % mod * a % mod;
		a = a % mod * a % mod;
		b >>= 1;
	}
	return res;
}

signed main(){
freopen("assign.in" , "r", stdin);freopen("assign.out" , "w" , stdout);
	T = read();
	while(T--){
		n = read() , m = read() , v = read();
		int ans = 0;	
		bool t = true;
		for (int i = 1 ; i <= m ; i++){
			int c , d; 
			c = read() , d = read(); 
			if(n <= N - 10){
				if((x[c] != 0 && x[c] != d) && t) {writeln(0);t = false;}
				x[c] = d;
			}
		}
		if(!t) continue;
		else if(m == n){
			int g = ((v * v % mod - (v - 1)) % mod + mod) % mod; 
			ans = qmi(g , n - 1) % mod;
			writeln((ans % mod + mod) % mod);
		}
		else if(m == 1){
			int g = ((v * v % mod) + mod) % mod; 
			ans = qmi(g , n - 1) % mod;
			writeln((ans % mod + mod) % mod);				
		}
		else{
			int g1 = (v * v % mod) % mod;
			int g2 = (((v * v % mod - (v - 1)) % mod) + mod) % mod;
			if(n <= N - 10){
				for (int i = 1 ; i < n ; i++){					 
					if(x[i] && x[i + 1]) if(ans) ans = (ans * g2 % mod) % mod;else ans = (g2 % mod);
					else if(x[i]){
						if(!x[i + 2]) ans = ((ans + v * v % mod) % mod + (g2 - 1) % mod * g1 % mod) % mod , i++; 
						else ans = (ans + (g2 - 1) * g1 % mod + v % mod) % mod , i++;
					}
					else if(ans) ans = (ans * g1 % mod) % mod;else ans = (g1 % mod);
				}
			}
			writeln(ans);
		}
		if(n <= N - 10) for (int i = 1 ; i <= n ; i++) x[i] = 0;
	}
	return 0;	
}
