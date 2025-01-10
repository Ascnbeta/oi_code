#include<bits/stdc++.h>
using namespace std;
const int N=3e5+7;
int n,q;
struct edge{
	int to,nxt;
}t[N<<1];
int tot,head[N];
void addedge(int u,int v){
	t[++tot].nxt=head[u];
	t[head[u]=tot].to=v;
	t[++tot].nxt=head[v];
	t[head[v]=tot].to=u;
	return ;
}
int pre[N][24],dis[N];
void dfs(int u,int fa){
	for(int i=head[u]; i; i=t[i].nxt){
		if(t[i].to==u)continue;
		dis[t[i].to]=dis[u]+1;
		pre[t[i].to][0]=t[i].to;
		dfs(t[i].to,u);
	}
	return ;
}
void init(){
	for(int i=1; i<=n; i++){
		for(int j=1; j<=22; j++){
			pre[i][j]=pre[pre[i][j-1]][j-1];
		}
	}
}
int LCA(int u,int v) {
	if(dis[u]<dis[v])swap(u,v);
	for(int i=22; i>=0; i--)
		if(dis[pre[u][i]]>=dis[v])
			u=pre[u][i];
	if(u==v)return u;
	for(int i=22; i>=0; i--)
		if(pre[u][i]!=pre[v][i])
			u=pre[u][i],v=pre[v][i];
	return pre[u][0];
}
int main(){
	freopen("query.in","r",stdin);
	freopen("query.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	for(int i=1; i<n; i++){
		int u,v;
		cin>>u>>v;
		addedge(u,v);
	}	
	dfs(1,0);
	init();
	cin>>q;
	while(q--){
		int l,r,k;
		cin>>l>>r>>k;
		int ans=0;
		int g=l,h=l+k-1;
		while(h<=r){
			int cm=0;
			for(int a=g; a<=h; a++){
				for(int b=g; b<=h; b++){
					if(a==b)continue;
					int tmp=LCA(a,b);
					if(dis[tmp]>dis[cm])
						cm=tmp;
				}
			}
			if(dis[cm]>dis[ans])
				ans=cm;
			g++,h++;
		}	
		cout<<dis[ans]<<'\n';
	}
	return 0;
}
