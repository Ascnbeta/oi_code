#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
vector<int> e[N];
vector<int> c[N];
int dfn[N],tim;
//int Min(int x,int y){
//	return dep[x]<dep[y]? x: y;
//}
int st[20][N];
int ss[20][N],tt[20][N];
int n,m,k;
int dep[N];
int ind[N],cind[N];
void st_init(){
	for(int j=1;(1<<j)<=n;j++){
		for(int i=1;i+(1<<j)-1<=n;i++){
			st[j][i]=min(st[j-1][i],st[j-1][i+(1<<(j-1))]);
			ss[j][i]=min(ss[j-1][i],ss[j-1][i+(1<<(j-1))]); 
			tt[j][i]=max(tt[j-1][i],tt[j-1][i+(1<<(j-1))]); 
		}
	}
}
//int lca(int u,int v){
//	if(u==v) return dep[u];
//	u=dfn[u],v=dfn[v];
//	if(u>v) swap(u,v);
//	u++;
//	int k=__lg(v-u+1);
//	return min(st[k][u],st[k][v-(1<<k)+1])-1;
//}
int lca(int u,int v){
	if(u>v) return st[0][v]+1;
	int k=__lg(v-u+1);
	return min(st[k][u],st[k][v-(1<<k)+1]);
}
pair<int,int> query(int l,int r){
	int k=__lg(r-l+1);
	return {min(ss[k][l],ss[k][r-(1<<k)+1]),max(tt[k][l],tt[k][r-(1<<k)+1])};
}
void dfs1(int u,int ft){
	dep[u]=dep[ft]+1;dfn[u]=++tim;st[0][tim]=dep[u];ss[0][u]=tt[0][u]=dfn[u];
	c[dep[u]].push_back(u);
	for(auto v:e[u]){
		if(v==ft) continue;
		dfs1(v,u);
	}
}
const int S=1e7+5;
struct Seg{
	int lst;
	int now;
	int ls[S],rs[S],tot,rt[N];
	int L[S],R[S],f[S];
	inline void up(int u){
		L[u]=L[ls[u]]+(L[ls[u]]==R[ls[u]]? L[rs[u]]: 0);
		R[u]=R[rs[u]]+(R[rs[u]]==L[rs[u]]? R[ls[u]]: 0);
		f[u]=max({f[ls[u]],f[rs[u]],R[ls[u]]+L[rs[u]]});
	}
	void update(int s,int t,int &u1,int u2,int x){
		u1=++tot;ls[u1]=ls[u2];rs[u1]=rs[u2];
		if(s==t){L[u1]=R[u1]=1;return;}
		int mid=(s+t)>>1;
		if(x<=mid) update(s,mid,ls[u1],ls[u2],x);
		else update(mid+1,t,rs[u1],rs[u2],x);
		up(u1);
	}
	void query(int l,int r,int s,int t,int u){
		if(now>=k) return;
		if(l<=s&&t<=r){
			tot++;
			now=max({now,f[u],R[lst]+L[u]});
			L[tot]=L[lst]+(L[lst]==R[lst]? L[u]: 0);
			R[tot]=R[u]+(R[u]==L[u]? R[lst]: 0);
			lst=tot;
			return;
		}
		int mid=(s+t)>>1;
		if(l<=mid) query(l,r,s,mid,ls[u]);
		if(r>mid) query(l,r,mid+1,t,rs[u]);
	}
}seg; 
int search(int l,int r,int k){
	int low=1,high=n;
	int res=0;
	while(low<=high){
		int mid=(low+high)>>1;
		int lst_tot=seg.tot;
		seg.lst=0;seg.now=0;
		seg.query(l,r,1,n,seg.rt[mid]);
		if(seg.now>=k) res=mid,low=mid+1;
		else high=mid-1;
		seg.tot=lst_tot;
	}
	return res;
}
void baoli(){
	for(int i=1;i<=m;i++){
		int l,r;cin>>l>>r>>k;
		int res=1;
		
		for(int i=l+k-1;i<=r;i++){
			pair<int,int> p=query(i-k+1,i);
			res=max(res,lca(p.first+1,p.second)-1);
		}
		
		cout<<res<<'\n';
	}
}
void chain(){
	for(int i=n;i>=1;i--){
		int lst=seg.rt[i+1];
		for(auto x:c[i]){
			seg.update(1,n,seg.rt[i],lst,x);
			lst=seg.rt[i];
		}
	}
	for(int i=1;i<=m;i++){
		int l,r;cin>>l>>r>>k;
		cout<<search(l,r,k)<<'\n';
	}
//	cerr<<clock()*1.0/CLOCKS_PER_SEC;
}
signed main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	freopen("query.in","r",stdin);
	freopen("query.out","w",stdout);
	cin>>n;
//	cerr<<"n="<<n<<'\n';
	for(int i=1;i<n;i++){
		int u,v;cin>>u>>v;e[u].push_back(v);e[v].push_back(u);
		ind[u]++;ind[v]++;
	}
	for(int i=1;i<=n;i++) cind[ind[i]]++;
	dfs1(1,0);
	st_init();
	cin>>m;
	if(n<=5000) baoli();
	else if(cind[1]==2&&cind[2]==n-2) chain();
	else baoli();
	return 0;
}
