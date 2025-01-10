#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N = 200005;
const int mod = 1e9 + 7;
map<int,int> used;

class node{
	public:
		int pos;
		int val;
		
		inline void get(){
			cin>>pos>>val;
		}
}op[N];

inline int qpow(int base,int times){
	if(!times) return 1;
	int ans = 1;
	while(times){
		if(times & 1) ans = ans * base % mod;
		base = base * base % mod;
		times >>= 1;
	}
	return ans;
}

inline int trans(int x){
	return (x % mod + mod) % mod;
}

signed main(){
	freopen("assign.in","r",stdin);
	freopen("assign.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int T;
	cin>>T;
	while(T --){
		// clear
		used.clear();
		int n,m,v;
		cin>>n>>m>>v;
		bool flag = true;
		for(int i = 1;i <= m;++ i){
			op[i].get();
			if(used.find(op[i].pos) != used.end() && used[op[i].pos] != op[i].val) flag = false;
			used[op[i].pos] = op[i].val;
		}
		if(!flag){
			cout<<0<<"\n";
			continue;
		}
		sort(op + 1,op + m + 1,[](const node& A,const node& B) -> bool const { return A.pos < B.pos; });
		int f = v - 1,g = 1;
		for(int i = 1;i <= m;++ i){
			if(op[i].pos == n){
				flag = false;
				break;
			}
			if(op[i].pos == op[i - 1].pos) continue;
			if(i == 1 && op[i].pos != 1){
				int tf = qpow(v,(op[i].pos - 1) * 2);
				f = tf * (v - 1) % mod;
				g = tf;
				continue;
			}
			else if(i == 1) continue;
			else{
				if(op[i].pos == op[i - 1].pos + 1){
					int tf = f * (v - 1) % mod * v % mod + g * (v - 1) % mod;
					int tg = f * v % mod + g;
					f = tf,g = tg;
				}
				else{
					int delta = op[i].pos - op[i - 1].pos - 1;
					int tf = f * (qpow(v,delta * 2)) % mod + (g) * trans(qpow(v,delta * 2) - qpow(v,delta)) % mod;
					int tg = g * (qpow(v,delta) % mod) % mod;
					f = tf * (v - 1) % mod * v % mod + tg * (v - 1) % mod;
					g = tf * v % mod + tg;
				}
			}
			f %= mod;
			g %= mod;
		}
		if(!flag) cout<<(g + v * f) % mod<<"\n";
		else{
			int delta = n - op[m].pos;
			cout<<(f + g) % mod * (qpow(v,delta * 2 - 1)) % mod<<"\n";
		}
	}
	return 0;
}
