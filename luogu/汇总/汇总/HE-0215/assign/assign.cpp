#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=1e5+5,p=1e9+7;
int n,m,A[N],B[N];
int x,y,z,l,r,k,t,ans,b[N];
map<int,int>a;
inline int quickpow(int a,int b){
	int res=1;
	while(b){
		if(b&1)res=res*a%p;
		b>>=1;a=a*a%p;
	}return res;
}
void dfs(int x){
	if(x==n){
		int need=0;
		for(int i=1;i<=n;i++)b[i]=a[i];
		for(int i=1;i<=n;i++){
			if(need!=0&&b[i]!=need&&b[i]!=0)return;
			if(b[i]==0)b[i]=need;
			if(b[i]==A[i])need=B[i];
			else need=0;
		}ans++;
		return ;
	}
	for(int i=1;i<=k;i++){
		for(int j=1;j<=k;j++){
			A[x]=i;B[x]=j;
			dfs(x+1);
		}
	}
}
void solve(){
	a.clear();
	cin>>n>>m>>k;
	bool vis=0;
	for(int i=1;i<=m;i++){
		cin>>x>>y;
		if(a[x]==0||a[x]==y)a[x]=y;
		else vis=1;
	}
	if(vis)return cout<<0<<'\n',void();
	if(m==1){
		cout<<quickpow(k,n*2-2)<<'\n';
		return;
	}
	ans=0;
	if(n<=20)dfs(1);
	else ans=quickpow(k*k,n-1);
	cout<<ans<<endl;

}	
signed main(){
	freopen("assign.in","r",stdin);
	freopen("assign.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>t;
	while(t--)solve();
	return 0;
}
