#include<bits/stdc++.h>
using namespace std;
int n,q,d[500010],fa[500010][21],ans[5010][5010],a[2000010];
vector<int> v[500010];
void solve1(int l,int r,int k){
	int anss=0;
	for(int i=l;i+k-1<=r;i++) anss=max(anss,d[ans[i][i+k-1]]);
	cout<<anss<<'\n';
}
int lca(int x,int y){
	if(d[x]<d[y]) swap(x,y);
	for(int i=20;i>=0;i--) if(d[fa[x][i]]>=d[y]) x=fa[x][i];
	if(x==y) return x;
	for(int i=20;i>=0;i--) if(fa[x][i]!=fa[y][i]) x=fa[x][i],y=fa[y][i];
	return fa[x][0];
}
void dfs(int x,int faa){
	d[x]=d[faa]+1;
	for(int i=0;i<v[x].size();i++){
		int y=v[x][i];
		if(y==faa) continue;
		fa[y][0]=x;
		dfs(y,x);
	}
}
void build(int x,int l,int r){
	if(l==r){
		a[x]=l;
		return;
	}
	int mid=(l+r)>>1;
	build(x<<1,l,mid);
	build((x<<1)|1,mid+1,r);
	a[x]=lca(a[x<<1],a[(x<<1)|1]);
}
int query(int x,int l,int r,int fl,int fr){
	if(fl<=l && r<=fr) return a[x];
	int mid=(l+r)>>1;
	if(fr<=mid) return query(x<<1,l,mid,fl,fr);
	if(fl>mid) return query((x<<1)|1,mid+1,r,fl,fr);
	return lca(query(x<<1,l,mid,fl,fr),query((x<<1)|1,mid+1,r,fl,fr));
}
int main(){
	freopen("query.in","r",stdin);
	freopen("query.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int x,y,z;
	cin>>n;
	for(int i=1;i<n;i++){
		cin>>x>>y;
		v[x].push_back(y);
		v[y].push_back(x);
	}
	dfs(1,0);
	for(int i=1;i<=20;i++){
		for(int j=1;j<=n;j++){
			fa[j][i]=fa[fa[j][i-1]][i-1];
		}
	}
	
	if(n<=5000){
		for(int i=1;i<=n;i++){
			ans[i][i]=i;
			for(int j=i+1;j<=n;j++){
				ans[i][j]=lca(ans[i][j-1],j);
			}
		}
	}else build(1,1,n);
	cin>>q;
	while(q--){
		cin>>x>>y>>z;
		if(n<=5000) solve1(x,y,z);
		else cout<<d[query(1,1,n,x,y)]<<'\n';
	}
	return 0;
}
