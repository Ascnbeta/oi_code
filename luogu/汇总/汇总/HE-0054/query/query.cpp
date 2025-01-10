#include<bits/stdc++.h>
//#define int long long
using namespace std;
const int N=5e5+10;
int kuaidu(){
	int r=0,f=1;
	char ch=getchar();
	while(ch<'0'||ch>'9'){
		if(ch=='-')f=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9'){
		r=(r<<3)+(r<<1)+(ch-'0');
		ch=getchar();
	}
	return r*f;
}
int n,q;
vector<int>v[N];
int f[N][21],dep[N];
void dfs(int s,int fa){
	f[s][0]=fa,dep[s]=dep[fa]+1;
	for(int i=1;i<=20&&f[s][i-1];i++){
		f[s][i]=f[f[s][i-1]][i-1];
	}
	for(int i=0;i<v[s].size();i++){
		int y=v[s][i];
		if(y==fa)continue;
		dfs(y,s);
	}
}
int lca(int x,int y){
	if(x==0)return y;
	if(y==0)return x;
	if(dep[x]<dep[y])swap(x,y);
	for(int i=20;i>=0;i--){
		if(dep[f[x][i]]>=dep[y])x=f[x][i];
	}
	if(x==y)return x;
	for(int i=20;i>=0;i--){
		if(f[x][i]!=f[y][i])x=f[x][i],y=f[y][i];
	}
	return f[x][0];
}
int ans;
int xds[N*4];
void build(int l,int r,int p){
	if(l==r){
		xds[p]=l;
		return;
	}
	int mid=(l+r)>>1;
	build(l,mid,2*p);
	build(mid+1,r,2*p+1);
	xds[p]=lca(xds[2*p],xds[2*p+1]);
}
int sum(int p,int l,int r,int L,int R){
	if(L<=l&&r<=R){
		return xds[p];
	}
	int mid=(l+r)>>1,res=0;
	if(L<=mid)res=lca(res,sum(2*p,l,mid,L,R));
	if(R>mid)res=lca(res,sum(2*p+1,mid+1,r,L,R));
	return res;
}
void ssolve(int x,int y,int z){
	for(int i=z;i<=z;i++){
		for(int j=x;j+i-1<=y;j++){
			int rr=j+i-1;
			ans=max(ans,dep[sum(1,1,n,j,rr)]);
		}
	}
}
signed main(){
	freopen("query.in","r",stdin);
	freopen("query.out","w",stdout);
	n=kuaidu();
	for(int i=1;i<n;i++){
		int x,y;
		x=kuaidu(),y=kuaidu();
		v[x].push_back(y);
		v[y].push_back(x);
	}
	dfs(1,0);
	build(1,n,1);
	q=kuaidu();
	while(q--){
		ans=0;
		int l,r,k;
		l=kuaidu(),r=kuaidu(),k=kuaidu();
		ssolve(l,r,k);
		cout<<ans<<'\n';
	}
	return 0;
}
