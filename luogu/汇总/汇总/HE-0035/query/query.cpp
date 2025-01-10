#include<bits/stdc++.h>
//#define int long long
using namespace std;
const int P=1e9+7; 

int n,q,l,r,k;
int dep[500500],siz[5005][5005];

int head[500500],tot;
vector<int > v[500500];

void dfs(int p,int f) {
	siz[p][p]++;dep[p]=dep[f]+1;
	for(int k:v[p]) {
		if(k==f) continue;
		dfs(k,p);
		for(int i=1;i<=n;i++) siz[p][i]+=siz[k][i];
	}
}


signed main() {
	freopen("query.in","r",stdin);
	freopen("query.out","w",stdout);
	cin>>n;
	for(int i=1,u,e;i<n;i++) {
		scanf("%d %d",&u,&e);
		v[u].push_back(e),v[e].push_back(u);
	}
	dfs(1,1);cin>>q;
	for(int i=1;i<=n;i++) 
		for(int j=1;j<=n;j++) siz[i][j]+=siz[i][j-1];
	for(int e=1;e<=q;e++) {
		scanf("%d %d %d",&l,&r,&k);
			int ans=0;
		for(int i=1;i<=n;i++) {
			for(int j=l;j+k-1<=r;j++)
			if(siz[i][j+k-1]-siz[i][j-1]==k) { ans=max(ans,dep[i]);break; }
		}
			printf("%d\n",ans);
	}
	return 0;
} 
