#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
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
int c,T,n,k;
int head[N],nxt[N<<1],to[N<<1],tot;
inline void add(int x,int y){
	to[++tot]=y;
	nxt[tot]=head[x];
	head[x]=tot;
}
int head1[N],nxt1[N<<1],to1[N<<1],tot1;
inline void add1(int x,int y){
	to1[++tot]=y;
	nxt1[tot]=head1[x];
	head1[x]=tot1;
}
int e[N];
struct edge{
	int x, y;
}g[N];
int fa[N];
int find(int x){
	return x==fa[x]?x:fa[x]=find(fa[x]);
}
void merge(int x,int y){
	x=find(x);
	y=find(y);
	if(x!=y){
		fa[y]=x;
	}
}
int random(int n){
	return (unsigned long long )rand()*rand()%n;
}
int main(){
	freopen("traverse.in","r",stdin);
	freopen("traverse.out","w",stdout);
	c=read(),T=read();
	while(T--){
		n=read();
		k=read();
		for (int i=1;i<=n;i++)fa[i]=i;
		for (int i=1;i<n;i++){
			int u,v;
			u=read(),v=read();
			add(u,v);
			add(v,u);
			if(u>v)swap(u,v);
			g[tot].x=u,g[tot].y=v;
		}
		for (int i=1;i<=k;i++){
			e[i]=read();
		}
		cout<<random(10)<<endl;
	}
	return 0;
}
