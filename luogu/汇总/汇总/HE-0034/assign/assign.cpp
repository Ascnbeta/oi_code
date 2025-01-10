#include<bits/stdc++.h>
#define int long long
using namespace std;
const int mod=1e9+7;
int T,n,m,v,ans,a[20],b[20],s[20];
map<int,int> val;
int c[100005],d[100005];
int qpow(int a,int k){
	int res=1;
	while(k){
		if(k&1)res=res*a%mod;
		a=a*a%mod;
		k>>=1;
	}
	return res%mod;
}
void dfs(int dep){
	if(dep==n){
		int f=1;
		for(int i=1;i<=n;++i)s[i]=val[i];
		for(int i=1;i<n;++i){
			if(s[i]&&s[i]==a[i]){
				if(!s[i+1])s[i+1]=b[i];
				else if(s[i+1]&&s[i+1]!=b[i])f=0;
			}
		}
		ans+=f;
//		for(int i=1;i<n;++i)cout<<a[i]<<" "<<b[i]<<"     ";
//		cout<<f<<"   ";
//		for(int i=1;i<=n;++i)cout<<s[i]<<" ";
//		cout<<"\n";
		return ;
	}
	a[dep]=1,b[dep]=1,dfs(dep+1);
	a[dep]=2,b[dep]=1,dfs(dep+1);
	a[dep]=1,b[dep]=2,dfs(dep+1);
	a[dep]=2,b[dep]=2,dfs(dep+1);
}
signed main(){
	freopen("assign.in","r",stdin);
	freopen("assign.out","w",stdout);
	scanf("%lld",&T);
	while(T--){
		ans=0;val.clear();
		for(int i=1;i<=15;++i)a[i]=b[i]=0;
		scanf("%lld%lld%lld",&n,&m,&v);
		int f=1,can=1;
		if(m!=n)f=0;
		for(int i=1;i<=m;++i){
			scanf("%lld%lld",&c[i],&d[i]);
			if(val[c[i]]&&val[c[i]]!=d[i])can=0;
			val[c[i]]=d[i];
		}
		for(int i=1;i<=m;++i)if(c[i]!=i)f=0;
		if(!can){
			puts("0");
			continue;
		}
		else if(val.size()<=1){
			ans=qpow(v*v%mod,n-1);
			printf("%lld\n",ans);
		}
		else if(f){
			ans=qpow((v*(v-1)+1)%mod,n-1);
			printf("%lld\n",ans);
		}
		else if(n<=12){
			dfs(1);
			printf("%lld\n",ans);
		}
	}
	return 0;
}
