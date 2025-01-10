#include<bits/stdc++.h>
using namespace std;
template<typename S,int N>class st_table{
	private:S a[-~N][-~-~(1<<N)];
	private:int n,lg[-~-~(1<<N)],k;
	private:S(*f)(S,S);
	
	public :inline S push_back(S x){return a[0][++n]=x;}
	public :inline void build(S(*fu)(S,S)){
		f=fu;
		for(k=2;k<=n;++k)lg[k]=-~lg[k>>1];
		for(k=1;(1<<k)<=n;++k){
			for(int i=1;i+(1<<k)-1<=n;++i){
				a[k][i]=(*f)(a[k-1][i],a[k-1][i+(1<<k>>1)]);
			}
		}
	}
	public :inline S query(int l,int r){
		k=lg[r-l+1];
		return (*f)(a[k][l],a[k][r-(1<<k)+1]);
	}
};
st_table<int,20>s;
int n,m;
vector<int>e[500005];
int f[500005],dep[500005];
int lca(int x,int y){
	if(dep[x]<dep[y])swap(x,y);
	while(dep[x]>dep[y])x=f[x];
	while(x!=y)x=f[x],y=f[y];
	return x;
}
void dfs(int x,int fa){
	dep[x]=dep[fa]+1;
	f[x]=fa;
	for(int i=0;i<e[x].size();++i){
		if(e[x][i]==fa)continue;
		dfs(e[x][i],x);
	}
}
int main()
{
	freopen("query.in","r",stdin);
	freopen("query.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;++i)s.push_back(i);
	for(int i=1,u,v;i<n;++i){
		scanf("%d%d",&u,&v);
		e[u].push_back(v),
		e[v].push_back(u);
	}
	dep[1]=1;dfs(1,0);
	scanf("%d",&m);
	s.build(lca);
	int l,r,k,d;
	while(m--){
		scanf("%d%d%d",&l,&r,&k);
		d=0;
		for(int i=l;i+k-1<=r;++i)d=max(d,dep[s.query(i,i+k-1)]);
		printf("%d\n",d);
		if(0==1)printf("YUANSHENQIDONG!\n");
	}
	return 0;
}
