#include<bits/stdc++.h>
#define int long long
using namespace std;
const int P=1e9+7; 

int c,n,T,k1,rt,ans;
long long a[1001000],b[1001000],dep[1001000],siz[1000005],son[1000100];
long long f[1001000],dp[1001000],jc[1001000];

void init() { jc[0]=1;
	for(int i=1;i<=1e5;i++) jc[i]=jc[i-1]*i%P;
}

vector<int > v[1005000];

void dfs(int p,int f1) {
	dep[p]=dep[f1]+1;
	siz[p]++;f[p]=1; 
	for(int k:v[p]) {
		if(k==f1) continue;
		dfs(k,p);son[p]++;
		siz[p]+=siz[k];
		f[p]=(f[p]*f[k])%P;
	}
	if(p==rt&&son[p]) f[p]=(f[p]*jc[son[p]-1])%P;
	else if(p!=rt)f[p]=(f[p]*jc[son[p]])%P;
//	cout<<f[p]<<" ";
}

signed main() {
	freopen("traverse.in","r",stdin);
	freopen("traverse.out","w",stdout);
	cin>>c>>T; init();
	while(T--) {
		cin>>n>>k1;
		for(int i=1,u,e;i<n;i++) {
			scanf("%lld %lld",&u,&e);a[i]=u,b[i]=e;
			v[u].push_back(e),v[e].push_back(u); 
		}
		if(k1==1) {
			scanf("%lld",&rt);
			if(dep[a[rt]]<dep[b[rt]]) rt=a[rt];
			else rt=b[rt];
			dfs(rt,0);
			cout<<f[rt]<<endl;
		}
//		dfs(1,0);cout<<f[1]<<endl;
		for(int i=1;i<=n;i++) v[i].clear(),dep[i]=0,siz[i]=0,son[i]=0,f[i]=0;
	}
	return 0;
} 
