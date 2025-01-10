#include<bits/stdc++.h>
using namespace std;
#define int long long 
#define itn long long 
constexpr itn oo = 100005;
constexpr int mod = 1e9+7;
int t;int n,m,v;
int qpow(int a,int b){
	int res = 1;
	while (b){
		if (b&1) (res*=a)%=mod;
		 b>>=1;
		(a*=a)%=mod;
	}return res;
}
struct nod{int first,second;
}st[oo];
bool cmp(nod a,nod b){return a.first==b.first?a.second<b.second:a.first<b.first;}
signed main(void){
	freopen("assign.in","r",stdin);
	freopen("assign.out","w",stdout);
	cin.tie(0)->sync_with_stdio(0);
	cin >> t;
	int out = 1;
	while (t--){
		out = 1;
		cin >> n >> m >> v;
		for (itn i=1;i<=m;++i) cin >> st[i].first >> st[i].second;
		sort(st+1,st+m+1,cmp);
		int p = v*v%mod;
		int q = ((v*(v-1))%mod);
		for (int i=1;i<m;++i){
			if (st[i].first==st[i+1].first&&st[i].second!=st[i+1].second){ out = 0; break; }
			if (st[i].first==st[i+1].first-1){(out*=q)%=mod;}
			else {(out*=qpow(p,st[i+1].first-st[i].first))%=mod;}
			if (i==1){(out*=qpow(p,st[i].first-1))%=mod;}
		}
		if (m==1){
			out *= qpow(p,n-1);
			cout << out << '\n';
			continue;
		}
		(out *= qpow(p,n-st[m].first))%=mod;
		cout << out << '\n';
	}
	exit(0);
}
