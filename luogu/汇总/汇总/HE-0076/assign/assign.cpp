#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<climits>
#include<unordered_map>
using namespace std;
typedef long long ll;
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
const int N = 1e5+10;
const ll mod = 1e9+7;
ll n,m,v;
int f0;
struct node{
	int c,d;
	bool operator < (const node&G) const{
		if(c!=G.c) return c < G.c;
		return d < G.d;
	}
}g[N];
inline ll quick_pow(ll x,ll y){
	ll res = 1;
	while(y){
		if(y&1) res = res*x%mod;
		x = x*x%mod;
		y>>=1;
	}
	return res%mod;
}
int main(){
	freopen("assign.in","r",stdin);
	freopen("assign.out","w",stdout);
	
	int T;read(T);
	while(T--){
		read(n,m,v);
		f0 = 0;
		for(int i=1;i<=m;++i) read(g[i].c,g[i].d);
		sort(g+1,g+1+m);
		for(int i=1;i<=m;++i){
			if(g[i].c==g[i-1].c && g[i].d!=g[i-1].d){
				f0 = 1;
				break;
			}
		}
		if(f0){
			puts("0");
			continue;
		}
		if(v==1){
			puts("1");
			continue;
		}
		cout << (quick_pow(n,n)-1ll*(m-1)*(v-1)%mod+mod)%mod << endl;
		
	}
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
