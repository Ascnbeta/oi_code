#include"bits/stdc++.h"
#define re register
#define int long long
using namespace std;
const int maxn=1e6+10,mod=1e9+7;
int n,m,V,ans;
int val[maxn];
int b[maxn];
bitset<maxn> vis;
map<int,int> vis1;
bool check;
struct node{
	int pos,v;
	inline bool operator < (const node &a)const{return pos<a.pos;}
}t[maxn];
struct limit{
	int a,b;
}a[maxn];
inline int qpow(int a,int b){
	int res=1;
	while(b){
		if(b&1) res=res*a%mod;
		b>>=1;
		a=a*a%mod;
	}
	return res;
}
inline void dfs1(int now){
	if(now==n+1){
		if(check) return;
		bool flag=1;
		for(re int i=1;i<n;++i){
			if(val[i]==a[i].a){
				if(val[i+1]!=a[i].b){
					flag=0;
					break;
				}
			}
		}
		if(flag){
			++ans;
			check=1;
		}
		if(ans>=mod) ans-=mod;
		return;
	}
	if(vis[now]) dfs1(now+1);
	else{
		for(re int i=1;i<=V;++i){
			val[now]=i;
			dfs1(now+1);
			if(check) return;
		}	
	}
}
inline void dfs(int now){
	if(now==n){
		check=0;
		dfs1(1);
		return;
	}
	for(re int i=1;i<=V;++i){
		a[now].a=i;
		for(re int j=1;j<=V;++j){
			a[now].b=j;
			dfs(now+1);
		}
	}
}
inline void solve1(){
	bool flag=1;
	for(re int i=1;i<=m;++i){
		cin>>t[i].pos>>t[i].v;
		if(vis[t[i].pos]){
			if(val[t[i].pos]!=t[i].v){
				flag=0;
			}
		}
		vis[t[i].pos]=1;
		val[t[i].pos]=t[i].v;
	}
	if(!flag){
		for(re int i=1;i<=m;++i) vis[t[i].pos]=0;
		cout<<0<<'\n';return;
	}
	ans=0;
	dfs(1);
	for(re int i=1;i<=m;++i) vis[t[i].pos]=0;
	cout<<ans<<'\n';
}
inline void solve2(){
	ans=1;
	for(re int i=1;i<=m;++i) cin>>t[i].pos>>t[i].v;
	for(re int i=1;i<n;++i){
		ans=ans*((V-1)*V+1)%mod;
	}
	cout<<ans<<'\n';
}
inline void solve3(){
	bool flag=1;
	for(re int i=1;i<=m;++i){
		cin>>t[i].pos>>t[i].v;
		if(vis1[t[i].pos]){
			if(vis1[t[i].pos]!=t[i].v){
				flag=0;
			}
		}
		vis1[t[i].pos]=t[i].v;
	}
	if(!flag){
		for(re int i=1;i<=m;++i) vis1[t[i].pos]=0;
		cout<<0<<'\n';return;
	}
	ans=qpow(V*V%mod,n-1);
	cout<<ans<<'\n';
}
inline void solve4(){
	for(re int i=1;i<=m;++i) b[i]=t[i].pos;
	sort(b+1,b+m+1);
	m=unique(b+1,b+m+1)-(b+1);
	ans=1;int lst=0;
	for(re int i=1;i<=m;++i){
		ans=ans*(qpow(V,b[i]-lst-1)+(V-1)*qpow(V,b[i]-lst)%mod+1)%mod;
		lst=b[i];
	}
	if(lst!=n) ans=ans*(qpow(V,n-lst-1)+(V-1)*qpow(V,n-lst)%mod+1);
	cout<<ans<<'\n';
}
inline void solve(){
	cin>>n>>m>>V;
	if(n==m) solve2();
	else if(m==1) solve3();
	else if(n<=12) solve1();
	else{
		int cnt=0;
		for(re int i=1;i<=m;++i){
			cin>>t[i].pos>>t[i].v;
			cnt+=(t[i].v==1);
		}
		if(cnt==m) solve4();
		else cout<<0<<'\n';
	}
}
signed main(){
	freopen("assign.in","r",stdin);
	freopen("assign.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int T;cin>>T;while(T--) solve();
	return 0;
}

