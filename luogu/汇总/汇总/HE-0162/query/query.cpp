#include<bits/stdc++.h> 
using namespace std;
const int N=5e5+10;
int n,q;
inline read(){
	int f=1,x=0;
	char ch=getchar();
	while(ch<'0'||ch>'9'){
		if(ch=='-')f=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9'){
		x=x*10+ch-'0';
		ch=getchar();
	}
	return x*f;
}
int head[N],to[N<<1],nxt[N<<1],tot,cnt[N];
void add(int x,int y){
	to[++tot]=y;
	nxt[tot]=head[x];
	head[x]=tot;
}
int dep[N],f[N][21];
bool v[N];
int dep_max=-1;
void dfs(int x){
	for (int i=head[x];i;i=nxt[i]){
		int y=to[i];
		if(v[y])continue;
		v[y]=1;
		dep[y]=dep[x]+1;
		f[y][0]=x;
		dfs(y);
	}
}
int lca(int u,int v){
	if(dep[u]<dep[v])swap(u,v);
	for(int i=21;i>=0;i--){
		if(dep[f[u][i]]>=dep[v]){
			u=f[u][i];
		}
	}
	if(u==v)return u;
	for (int i=21;i>=0;i--){
		if(f[u][i]!=f[v][i]){
			u=f[u][i],v=f[v][i];
		}
	}
	return f[u][0];
}
int main(){
	freopen("query.in","r",stdin);
	freopen("query.out","w",stdout);
	n=read();
	for (int i=1,u,v;i<n;i++){
		u=read();
		v=read();
		add(u,v);
		add(v,u);
	}
	dep[1]=1;
	dfs(1);
	for (int i=1;i<=n;i++)dep_max=max(dep_max,dep[i]);
	q=read();
	int l,r,k;
	while(q--){
		l=read(),r=read(),k=read();
		if(dep_max==n){
			priority_queue<int>pq;
			for(int len=k;len<=r-l+1;len++){
				for (int i=l;i+len-1<=r;i++){
					int j=i+len-1;
					int d=0x3f3f3f;
					for (int t=i;t<=j;t++){
						d=min(d,dep[t]);
					}
					pq.push(d);
				}
			}
			printf("%d\n",pq.top());
			continue;
		}	
		priority_queue<int>pq;
		for(int len=k;len<=r-l+1;len++){
			for (int i=l;i+len-1<=r;i++){
				int j=i+len-1;
				int res=lca(i,j);
				pq.push(dep[res]);
			}
		}
		printf("%d\n",pq.top());
	}
	return 0;
}
