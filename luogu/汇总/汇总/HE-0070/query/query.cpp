#include<bits/stdc++.h>
using namespace std;
const int N=5e5+7;

int n,Q,t;
int head[N*2],to[N*2],nxt[N*2];
int cnt;
int f[N][22];
int dp[N];

void add(int u,int v){
	cnt++;
	to[cnt]=v;
	nxt[cnt]=head[u];
	head[u]=cnt;
}

void dfs(int x,int fa){
	for(int i=head[x];i;i=nxt[i]){
		int y=to[i];
		if(y!=fa){
			dp[y]=dp[x]+1;
			dfs(y,x);
			f[y][0]=x;
		}
	}
}

void init(){
	for(int k=1;k<=t;k++){
		for(int i=1;i<=n;i++){
			f[i][k]=f[f[i][k-1]][k-1];
		}
	}
}

int lca(int x,int y){
	if(dp[x]<dp[y]) swap(x,y);
	for(int k=t;k>=0;k--){
		if(dp[f[x][k]]>=dp[y]) x=f[x][k];
	}
	if(x==y) return x;
	for(int k=t;k>=0;k--){
		if(f[x][k]!=f[y][k]){
			x=f[x][k],y=f[y][k];
		}
	}
	return f[x][0];
}

int check(int l,int r,int k){
	int ans=0;
	for(int len=k;len<=r-l+1;len++){
		for(int i=l,j=l+len-1;j<=r;i++,j++){
			int lc=lca(i,j);
			ans=max(ans,dp[lc]);
		}
	}
	return ans;
}

int main(){
	freopen("query.in","r",stdin);
	freopen("query.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	t=log2(n)+1;
	for(int i=1;i<n;i++){
		int x,y;cin>>x>>y;
		add(x,y);add(y,x);
	}
	memset(dp,-1,sizeof(dp));
	dp[1]=1;
	dfs(1,0);init();
	cin>>Q;
	while(Q--){
		int x,y,k;cin>>x>>y>>k;
		cout<<check(x,y,k)<<'\n';
	}
	return 0;
}
