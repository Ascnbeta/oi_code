#include<bits/stdc++.h>
#define int long long
using namespace std;
const int mod=1e9+7;
const int N=1e5+10;
int head[N],is[N],to[N],nxt[N],cnt,id[N],vis[N];
int fact[N],ins[N];
void add(int u,int v,int cur){
	is[++cnt]=u;
	to[cnt]=v;
	nxt[cnt]=head[u];
	head[u]=cnt;
	id[cnt]=cur;
}
int c,T,n,k,ans;
int read(){
	int k=0,f=1;
	char ch=getchar();
	while(ch<'0'||ch>'9'){
		if(ch=='-')f=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9'){
		k=k*10+ch-'0';
		ch=getchar();
	}
	return k*f;
}
int dfs(int p,int cur){
	int num=0;
	for(int i=head[p];i;i=nxt[i]){
		num++;
		int y=to[i];
		if(vis[y])continue;
		vis[y]=1;
		int p=dfs(y,cur);
		cur=p%mod;
	}
	if(num==1)return cur;
	return cur*(num-1);
}
signed main(){
	freopen("traverse.in","r",stdin);
	freopen("traverse.out","w",stdout);
	fact[0]=1;
	for(int i=1;i<=N-10;i++)fact[i]=fact[i-1]*i%mod;
	c=read(),T=read();
	while(T--){
		cnt=0,ans=0;
		cin>>n>>k;
		for(int i=1;i<n;i++){
			int u,v;
			u=read(),v=read();
			ins[u]++;
			ins[v]++;
			add(u,v,i);
			add(v,u,i);
		}
		bool flag=true;
		for(int i=1;i<=n;i++)if(ins[i]==n-1)flag=false;
		if(!flag){
			cout<<fact[n-1]<<endl;
			continue;
		}
		for(int i=1;i<=k;i++){
			int p;
			p=read();
			for(int j=1;j<=cnt;j++){
				if(id[j]==p){
					ans+=dfs(is[cnt],1);
					break;
				}
			}
			for(int i=1;i<=n;i++)vis[i]=0;
		}
		cout<<ans<<endl;
		for(int i=1;i<=n;i++)head[i]=vis[i]=ins[i]=0;
		for(int i=1;i<=cnt;i++)nxt[i]=id[i]=to[i]=0;
	}
	return 0;
}
