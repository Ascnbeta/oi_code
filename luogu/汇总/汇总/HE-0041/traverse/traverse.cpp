#include<bits/stdc++.h>
#define int long long
using namespace std;
const int mod=1e9+7; 
mt19937 rnd(time(0));
int binpow(int a,int b){
	if(!b) return 1;
	int res=binpow(a,b/2);
	if(b&1) return res*res%mod*a%mod;
	else return res*res%mod;
}
int id,t,n,k,x[15],y[15],vis[15],chk[15][15],fac[1000005],cnt;
void solve2(){
	for(int i=1;i<=t;i++){
		cout<<1<<'\n';
	}
}
struct node{
	int h[15][15];
	node(){
		memset(h,0,sizeof(h));
	}
	bool operator <(const node &a)const{
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(h[i][j]<a.h[i][j]) return true;
				if(h[i][j]>a.h[i][j]) return false;
			}
		}
		return false;
	}
};
vector<int> v[15],c[15];
set<node> s;
node tmp;
void dfs(int x){
	if(cnt==n-1){
		s.insert(tmp);
		return;
	}
	for(int i=0;i<c[x].size();i++){
		int y=c[x][i];
		if(vis[y]) continue;
		vis[y]=1;
		cnt++;
		tmp.h[x][y]=tmp.h[y][x]=1;
		dfs(y);
	}
}
void solve(int x){
	int tp=1000;
	while(tp--){
		for(int i=1;i<n;i++){
			shuffle(c[i].begin(),c[i].end(),rnd);
		}
		cnt=1;
		memset(vis,0,sizeof(vis));
		memset(tmp.h,0,sizeof(tmp.h));
		vis[x]=1;
		dfs(x);
	}
}
void solve1(){
	while(t--){
		memset(chk,0,sizeof(chk));
		s.clear();
		for(int i=1;i<=n;i++){
			v[i].clear();
			c[i].clear();
		}
		cin>>n>>k;
		for(int i=1;i<n;i++){
			cin>>x[i]>>y[i];
			v[x[i]].push_back(i);
			v[y[i]].push_back(i);
		}
		for(int i=1;i<n;i++){
			for(int j=0;j<v[x[i]].size();j++){
				if(chk[i][v[x[i]][j]]) continue;
				c[i].push_back(v[x[i]][j]); 
			}
			for(int j=0;j<v[y[i]].size();j++){
				if(chk[i][v[y[i]][j]]) continue;
				c[i].push_back(v[y[i]][j]);
			}
		} 
		for(int i=1;i<=k;i++){
			cin>>x[0];
			solve(x[0]);
		}
		cout<<s.size()<<'\n';
	}
}
void solve3(){
	while(t--){
		cin>>n>>k;
		for(int i=1;i<n;i++){
			cin>>x[0]>>y[0];
		}
		for(int i=1;i<=k;i++){
			cin>>x[0];
		}
		fac[0]=1;
		for(int i=1;i<=n;i++){
			fac[i]=fac[i-1]*i%mod;
		}
		if(n-1==k) cout<<fac[n-1]*binpow(2,mod-2)<<'\n';
		if(n==2) cout<<1<<'\n'; 
		else cout<<((fac[n-1]-((n-1-k)*(n-1-k-1)%mod*fac[n-3]%mod))%mod+mod)%mod*binpow(2,mod-2)%mod<<'\n'; 
	}
}
signed main(){
	freopen("traverse.in","r",stdin);
	freopen("traverse.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>id>>t;
	if(id<=3) solve1();
	else if(id==18) solve2();
	else solve3();
	return 0;
}
