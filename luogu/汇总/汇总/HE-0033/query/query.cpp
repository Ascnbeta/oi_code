#include<bits/stdc++.h>
using namespace std;

int read(){
	int x=0,f=1;char ch=getchar();
	while(ch>'9'||ch<'0') {
		if(ch=='-') f=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9') x=x*10+ch-'0',ch=getchar();
	return x*f;
}

const int N=5e5+10;
int head[N],tot;
struct node{
	int to,nxt;
}e[N*2];
void add(int a,int b){
	tot++;
	e[tot].to=b;
	e[tot].nxt=head[a];
	head[a]=tot;
}
int dep[N];
int dfs(int x,int fa){
	dep[x]=dep[fa]+1;
	for(int i=head[x];i;i=e[i].nxt){
		int y=e[i].to;
		if(y==fa) continue;
		dfs(y,x);
	}
}
int maxn[N];
//struct node{
//	int l,r,maxn;
//	#define l(p) tr[p].l
//	#define r(p) tr[p].r
//	#define maxn(p) tr[p].maxn
//}tr[N*4];
//void pushup(int p){
//	maxn(p)=max(maxn(p<<1),maxn(p<<1)|1);
//}
//void build(int l,int r,int p){
//	l(p)=l,r(p)=r;
//	if(l==r) {
//		maxn(p)=dep[l];	
//		return;
//	}
//	int mid=(l+r)>>1;
//	build(l,mid,p<<1);
//	build(mid+1,r,p<<1|1);
//	pushup();
//}
//void query(int p,int l,int r){
//	if(l(p)>=l&&r(p)<=r){
//		return maxn(p);
//	}
//	int mid=(l(p)+r(p))>>1;
//}
int main(){
	freopen("query.in","r",stdin);
	freopen("query.out","w",stdout);
	int n=read();
	for(int i=1;i<n;i++){
		int a=read(),b=read();
		add(a,b),add(b,a);
	}
	dep[1]=1;
	dfs(1,0);
	int q=read();
	for(int i=1;i<=q;i++){
		int l=read(),r=read(),k=read();
		int ans=0;
		for(int i=l;i<=r;i++){
			ans=max(ans,dep[i]);
		}
		cout<<ans<<endl;
	}
	return 0;
}
