#include<bits/stdc++.h>
using namespace std;

const int M=1e5+5,N=1e9,mod=1e9+7;
int n,m,v,c[M],d[M],x[20],a[20],b[20],flag;
bool book[20];
long long ans;

bool check(){
	for(int i=1;i<=n-1;i++){
		if(x[i]==a[i]) if(x[i+1]!=b[i]) return 0;
	}
	return 1;
}

void dfs_x(int now){
	if(now>n){
		if(check()) ans++,ans%=mod,flag=1;
		return;
	}
	if(!book[now]){
		x[now]=1;
		dfs_x(now+1);
		if(flag)return;
		x[now]=2;
		dfs_x(now+1);
		if(flag)return;
	}
	else dfs_x(now+1);
	if(flag)return;
}

void dfs_b(int now){
	if(now>n-1){
		flag=0;
		dfs_x(1);
		return;
	}
	b[now]=1;
	dfs_b(now+1);
	b[now]=2;
	dfs_b(now+1);
}

void dfs_a(int now){
	if(now>n-1){
		dfs_b(1);
		return;
	}
	a[now]=1;
	dfs_a(now+1);
	a[now]=2;
	dfs_a(now+1);
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("assign.in","r",stdin);
	freopen("assign.out","w",stdout);
	
	int _;
	cin>>_;
	while(_--){
		cin>>n>>m>>v;
		ans=0;memset(book,0,sizeof(book));
		for(int i=1;i<=m;i++) {
			cin>>c[i]>>d[i];
			book[c[i]]=1;
			x[c[i]]=d[i];
		}
		if(v<=2){
			dfs_a(1);
			cout<<ans<<'\n';
			continue;
		}
		if(m<=1){
			if(m==0){
				
			}
			if(m==1){
				
			}
		}
	}
	return 0;
}
