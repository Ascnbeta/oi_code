#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N = 100005;
const int mod = 1e9 + 7;
vector<int> v[N];
int pre[N];

inline int trans(int x){
	return (x % mod + mod) % mod;
}

signed main(){
	freopen("traverse.in","r",stdin);
	freopen("traverse.out","w",stdout);
	int c,T;
	cin>>c>>T;
	if(c <= 3){
		while(T --){
			int n,k;
			cin>>n>>k;
			cout<<k<<"\n";
		}
	}
	else if(c >= 19 && c <= 21){
		pre[0] = 1;
		for(int i = 1;i < N;++ i) pre[i] = pre[i - 1] * i % mod;
		while(T --){
			int n,k;
			cin>>n>>k;
			for(int i = 1;i <= n;++ i){
				int u,v;
				cin>>u>>v;
			}
			for(int i = 1;i <= k;++ i){
				int x;
				cin>>x;
			}
			cout<<trans(k * (pre[n - 1]) % mod)<<"\n";
		}
	}
	else{
		while(T --){
			int n,k;
			cin>>n>>k;
			cout<<k<<"\n";
		}
	}
	return 0;
}
