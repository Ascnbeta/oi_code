#include<bits/stdc++.h>
using namespace std;
struct ccc{
	int to,nxt;
}e[(int)5e5+10000];
int tree[(int)2e6*20],ls[(int)2e6*20],rs[(int)2e6*30];
int head[(int)5e5+1000],cnt,dep[(int)5e5+10000],tot,rt[(int)1e6];
int copy(int i){
	tree[++tot]=tree[i];
	ls[tot]=ls[i];
	rs[tot]=rs[i];
	return tot;
}
int adt(int i,int l,int r,int x){
	i=copy(i);
	if(l==r){
		tree[i]++;
		return i;
	}
	int mid=(l+r)>>1;
	if(x<=mid)ls[i]=adt(ls[i],l,mid,x);
	else rs[i]=adt(rs[i],mid+1,r,x);
	tree[i]=tree[ls[i]]+tree[rs[i]]; 
}
int get(int bg,int ed,int l,int r,int k){
	if(l==r)return l;int mid=(l+r)>>1;
	int siz=tree[ed]-tree[bg];
	if(k<=siz)return get(ls[bg],ls[ed],l,mid,k);
	else return get(rs[bg],rs[ed],mid+1,r,k-siz);
}
void add(int u,int v){
	e[++cnt].to=v;
	e[cnt].nxt=head[u];
	head[u]=cnt;
}
void dfs(int nw,int d){
	dep[nw]=d;
	for(int i=head[nw];i;i=e[i].nxt){
		int v=e[i].to;
		dfs(v,d+1);
	}
}int n,q;
int main(){
	freopen("query.in","r",stdin);
	freopen("query.out","w",stdout);
	cin>>n;
	for(int i=1;i<n;i++){
		int u,v;
		cin>>u>>v;
		add(u,v);
	}
	cin>>q;
	dfs(1,1);
	for(int i=1;i<=n;i++)rt[i]=adt(rt[i-1],1,n,dep[i]);
	for(int i=1;i<=q;i++){
		int l,r,k;
		cin>>l>>r>>k;
		cout<<get(rt[l-1],rt[r],1,n,r-l+1-k)<<endl;
	}
	return 0;
}
