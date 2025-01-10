#include<bits/stdc++.h>
#define int long long
using namespace std;
const int MOD=1e9+7;
int T,n,m,V,c[107000],d[107000],x[1070000],f[1070000],a[107000],b[107000],ans,y[107000];
int Pow(int x,int t) {
	int sum=1,p=1;t=t%MOD;x=x%MOD;
	while(t){
		if(t&1) sum=(sum*x)%MOD;
		x=x*x%MOD;
		t>>=1;
	}
	return sum;
}
void dfs(int id) {
	if(id==n) {
		bool ok=1;
		for(int i=1;i<=n;i++) x[i]=y[i];
		for(int i=1;i<n;i++) {
			if(x[i]!=a[i]||x[i]==-1) {
				;
			}
			else if(x[i]==a[i]) {
				if(x[i+1]==-1) x[i+1]=b[i];
				else if(x[i+1]!=b[i]) ok=0; 
			}
		}
		ans=ans+ok;
		return;
	}
	for(int i=1;i<=V;i++) {
		for(int j=1;j<=V;j++) {
			a[id]=i;
			b[id]=j;
			dfs(id+1);
		}
	}
	return ;
}
signed main() {
	freopen("assign.in","r",stdin);
	freopen("assign.out","w",stdout);
	scanf("%lld",&T);
	while(T--) {
		ans=0;
		scanf("%lld%lld%lld",&n,&m,&V);
		for(int i=1;i<=m;i++) {
			scanf("%lld%lld",&c[i],&d[i]);
		}
		if(m==1) {
			printf("%lld\n",Pow(V,2*n-2));
			continue;
		}
		for(int i=1;i<=n;i++) y[i]=-1;
		bool flag=1;
		for(int i=1;i<=m;i++) {
			if(y[c[i]]==-1) y[c[i]]=d[i];
			else if(y[c[i]]!=d[i]) flag=0;
		}
		if(!flag) {
			printf("0\n");
			continue;
		}
		dfs(1);
		cout<<ans<<endl;
		continue;
	}
	return 0;
}
/*
3 2 1 2 1 1 2 2 2 1 1 2 2 2 2 2 1 1 1 2
*/
