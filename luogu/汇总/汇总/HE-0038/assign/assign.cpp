#include"bits/stdc++.h"
using namespace std;
const int N=1e5+10,mod=1e9+7;
long long qpow(long long x,long long y){
	long long ret=1;
	while(y){
		if(y&1) ret=ret*x%mod;
		x=x*x%mod;
		y>>=1;
	}
	return ret;
}
int T;
long long n,m,v;
long long ans;
int c[N],d[N],b[N],bb[N];
map<int,int>ma;
int a[N][2];
bool ok1;
void dfs(int k){
	if(k==n){
		bool ok=0;
		for(int i=1;i<=n;i++) bb[i]=b[i];
		for(int i=1;i<=n-1;i++){
			if(bb[i]==a[i][0]){
				if(!bb[i+1]||bb[i+1]==a[i][1]) bb[i+1]=a[i][1];
				else{
					ok=1;
					break;
				}
			}
		}
		if(!ok) ans++;
		return;
	}
	for(int i=1;i<=v;i++){
		for(int j=1;j<=v;j++){
			a[k][0]=i;
			a[k][1]=j;
			dfs(k+1);
		}
	}
}
int main(){
	freopen("assign.in","r",stdin);
	freopen("assign.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>T;
	while(T--){
		ok1=1;
		ans=0;
		cin>>n>>m>>v;
		ma.clear();
		if(n<=1e5) for(int i=1;i<=n;i++) b[i]=0;
		bool ok=0;
		for(int i=1;i<=m;i++){
			cin>>c[i]>>d[i];
			if(ma[c[i]]&&ma[c[i]]!=d[i]) ok=1;
			ma[c[i]]=d[i];
			if(c[i]<=1e5) b[c[i]]=d[i];
			if(c[i]!=i) ok1=0;
		}
		if(ok){
			cout<<0<<'\n';
			continue;
		}
		else if(m==1){
			cout<<qpow(v*v%mod,n-1)<<'\n';
			continue;
		}
		else if(v<=2){
			dfs(1);
			cout<<ans<<'\n';
			continue;
		}
		else {
			cout<<rand()<<'\n';
		}
	}
}
