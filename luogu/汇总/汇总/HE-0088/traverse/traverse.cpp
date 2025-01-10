#include<bits/stdc++.h>
using namespace std;
//#define int long long
#define psb push_back

const int N=1e7+10;
int c,T,n,k,res,ans=0,u[N],v[N],m[N];
vector<int> e[N],num[N];

int cnt=0,vis[N];
void dfs(int x,int fa){
	vis[x]=1;
	++cnt;
	
	if(cnt==n-1){
		++res;
		--cnt;
		vis[x]=0;
		return ;
	}
	for(auto to:e[x]){
		if(vis[to]) continue;
		dfs(to,x);
	}
	
	--cnt;
	vis[x]=0;
}

void work(){
	cin>>n>>k;
	bool flg=0;
	cnt=ans=0;
	for(int i=1;i<n;i++){
		cin>>u[i]>>v[i];
		if(u[i]+1!=v[i]){
			flg=1;
		}
	}
	if(!flg){
		cout<<1<<'\n';
		return ;
	}
	
	for(int i=1;i<n;i++){
		num[u[i]].psb(i);
		num[v[i]].psb(i);
	}
	
	for(int i=1;i<=k;i++){
		cin>>m[i];
	}
	
	for(int i=1;i<=n;i++){
		for(auto j:num[i]){
			for(auto k:num[i]){
				if(j==k) continue;
				e[j].psb(k);
				
			}
		}
	}
	
	for(int i=1;i<=k;i++){
		cnt=0;res=0;
		dfs(m[i],0);
		ans+=res;
	}
	
	cout<<ans<<'\n';
}

signed main(){
	freopen("traverse.in","r",stdin);
	freopen("traverse.out","w",stdout);
	
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	
	cin>>c>>T;
	while(T--) work();
	return 0;
}
