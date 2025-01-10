#include<bits/stdc++.h>
using namespace std;
#define int long long
const int mod=1e9+7;
int qpow(int a,int x){
	int sum=1;
	while(x){
		if(x&1) sum=sum*a%mod;
		a=a*a%mod;
		x>>=1;
	}return sum;
}
const int N=1e5+5;
int ans;
int n,m,V;
struct no{
	int x,y;
}a[N];
bool operator <(const no &n1,const no &n2){return n1.x==n2.x? n1.y<n2.y: n1.x<n2.x;}
void solve(){
	ans=1;
//	if(n==1){ans=0;return;}
	for(int i=2;i<=m;i++){
		if(a[i].x==a[i-1].x&&a[i].y!=a[i-1].y){ans=0;return;}
	}
	a[0]={1,0};
	a[m+1]={n,0};
	for(int i=1;i<=m+1;i++){
		int lst=a[i-1].x,now=a[i].x;
		if(lst==now) continue;
		int val=qpow(V*V%mod,now-lst);
		if(a[i].y&&a[i-1].y) val-=qpow(V,now-lst-1)*(V-1)%mod;
		val=(val%mod+mod)%mod;
		ans=ans*val%mod;
	}
} 
signed main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	freopen("assign.in","r",stdin);
	freopen("assign.out","w",stdout);
	int T;cin>>T;
	while(T--){
		cin>>n>>m>>V; 
		for(int i=1;i<=m;i++) cin>>a[i].x>>a[i].y;
		sort(a+1,a+1+m);
		solve();
		cout<<ans<<'\n';
	}
	return 0;
}
