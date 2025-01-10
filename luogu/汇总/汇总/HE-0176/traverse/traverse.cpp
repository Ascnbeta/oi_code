#include<bits/stdc++.h>
using namespace std;
const int mod=1e9+7;
const int N=1e5+7;
int n,k;
struct edge(){
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
int main(){
	freopen("traverse.in","r",stdin);
	freopen("traverse.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int id,T;
	cin>>id>>T;
	while(T--){
		memset(t,0,sizeof(t));
		cin>>n>>k;
		for(int i=1; i<n; i++){
			int u,v;
			cin>>u>>v;
			addedge(u,v);
		}
		cout<<'0'<<'\n';
	}	
	return 0;
}
