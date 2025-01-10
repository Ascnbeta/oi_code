#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
int n,u,v,dep[N],st[N][20],lg[N];
int tot,head[N];
struct edge{
	int to,nex;
}e[N<<1];
void dfs(int u,int f){
	for(int i=head[u];i;i=e[i].nex){
		int v=e[i].to;
		if(v==f) continue;
		dep[v]=dep[u]+1;
		dfs(v,u);
	}
}
void add(int u,int v){
	e[++tot].to=v;
	e[tot].nex=head[u];
	head[u]=tot;
}
signed main() {
	freopen("query.in","r",stdin);
	freopen("query.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<n;i++) {
		int u,v;
		scanf("%d%d",&u,&v);
		add(u,v);add(v,u);
	}
	dep[1]=1;
	dfs(1,1);
	for(int i=1;i<=n;i++) st[i][0]=dep[i];
	lg[1]=0;lg[2]=1;
	int t=4;
	for(int i=3;i<=n;i++) {
		if(i<t) lg[i]=lg[i-1];
		if(i==t) {
			lg[i]=lg[i-1]+1;
			t=t*2;
		}
	}
	for(int k=1;k<=lg[n];k++) {
		for(int i=1;i+(1<<k)-1<=n;i++) {
			st[i][k]=max(st[i][k-1],st[i+(1<<(k-1))][k-1]);
		}
	}
	int Q,l,r,k;
	scanf("%d",&Q);
	while(Q--) {
		scanf("%d%d%d",&l,&r,&k);
		int op=r-l+1;
		int ans=max(st[l][lg[op]],st[r-(1<<lg[op])+1][lg[op]]);
		cout<<ans<<endl;
	}
	return 0;
}
