#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
#define fi first
#define se second
#define mk make_pair
#define ps push_back
#define mo(x,y) (x+=y,x>=mod?x-=mod:0)
const int N=1e6+10,inf=0x3f3f3f3f,B=1200;
const ll linf=0x3f3f3f3f3f3f3f3f,mod=1e9+7;
inline ll read(){
	char c=getchar(); ll x=0;bool f=0;
	while(!isdigit(c))f=c=='-'?1:0,c=getchar();
	while(isdigit(c))x=(x<<1)+(x<<3)+(c^48),c=getchar();
	return f?-x:x;
}
struct jj{
	int to,next;
}bi[N];
int n,Q,cntp,hd[N];
inline void add(int x,int y){bi[++cntp]={y,hd[x]},hd[x]=cntp,bi[++cntp]={x,hd[y]},hd[y]=cntp;}
int zh[N],st[B],ed[B],cnt,tot,len,dep[N],stt[N][20],fa[N],dfn[N],man[N],dan[N],sst[N][20];
int ans[N];
inline void dfs(int x,int f){
	fa[x]=f,dep[x]=dep[f]+1,dfn[x]=++tot;stt[tot][0]=x;sst[x][0]=x;
	for(int i=hd[x];i;i=bi[i].next){
		int j=bi[i].to;
		if(j!=f)dfs(j,x);
	}
}
inline int lca(int x,int y){
	if(x==y)return x;
	x=dfn[x],y=dfn[y];
	if(x>y)swap(x,y);
	int k=log2(y-x);
	return fa[dep[stt[x+1][k]]<=dep[stt[y-(1<<k)+1][k]]?stt[x+1][k]:stt[y-(1<<k)+1][k]];
}
inline int ask(int l,int r){
	int k=log2(r-l+1);
	return lca(sst[l][k],sst[r-(1<<k)+1][k]);
}
inline int askk(int l,int r){
	int ans=0;
	if(zh[r]-zh[l]<=1){
		for(int j=l;j<=r;++j)
			ans=max(ans,dan[j]);
	}
	else{
		for(int j=l;j<=ed[zh[l]];++j)
			ans=max(ans,dan[j]);
		for(int j=zh[l]+1;j<zh[r];++j)
			ans=max(ans,man[j]);
		for(int j=st[zh[r]];j<=r;++j)
			ans=max(ans,dan[j]);
	}
	return ans;
}
struct ak{
	int id,l,r,k;
}q[N>>1];
int main(){
	// 4.cpp
	freopen("query.in","r",stdin);
	freopen("query.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	n=read();
	len=min(n,700),cnt=n/len;
	for(int i=1,x,y;i<n;++i){
		x=read(),y=read();
		add(x,y);
	}
	dfs(1,0);
	for(int i=1;i<20;++i){
		for(int j=1;j+(1<<i)<=n+1;++j){
			stt[j][i]=dep[stt[j][i-1]]<=dep[stt[j+(1<<i-1)][i-1]]?stt[j][i-1]:stt[j+(1<<i-1)][i-1];
		}
	}
	for(int i=1;i<20;++i){
		for(int j=1;j+(1<<i)<=n+1;++j){
			sst[j][i]=lca(sst[j][i-1],sst[j+(1<<i-1)][i-1]);
		}
	}
	for(int i=1;i<=cnt;++i){
		st[i]=ed[i-1]+1,ed[i]=ed[i-1]+len,ed[cnt]=n;
		for(int j=st[i];j<=ed[i];++j)
			zh[j]=i;
	}
	Q=read();
	// cout<<len<<endl;
	for(int i=1;i<=Q;++i){
		q[i].l=read(),q[i].r=read(),q[i].k=read(),q[i].id=i;
		if(q[i].k>=len){
			for(int j=q[i].l;j+q[i].k-1<=q[i].r;++j){
				ans[i]=max(ans[i],dep[ask(j,j+q[i].k-1)]);
			}
		}
	}
	// return 0;
	sort(q+1,q+1+Q,[](const ak&x,const ak&y){return x.k<y.k;});
	int j=1;
	for(int i=1;i<len;++i){
		for(int j=1;j<=cnt;++j){
			man[j]=0;
			for(int k=st[j];k<=ed[j];++k){
				if(k-i>=0)dan[k]=dep[ask(k-i+1,k)];
				else dan[k]=0;
				man[j]=max(man[j],dan[k]);
			}
		}
		while(j<=Q&&q[j].k==i){
			ans[q[j].id]=askk(q[j].l+q[j].k-1,q[j].r),++j;
		}
	}
	for(int i=1;i<=Q;++i)
		cout<<ans[i]<<'\n';
	// return 0;


}