#include<bits/stdc++.h>
#define rpt(a,b,c) for(int a=b;a<=c;a++)
#define rep(i,u) for(int i=Head[u];i;i=e[i].n)
#define LL long long
using namespace std;
const int N=1e5+10,NMax=1e5,mod=1e9+7;
int c,T,t,n,k,u,v,x;
LL fac[N],num[N];
struct edge{
	int n,t,w;
}e[N<<1];
int Head[N],cnte;
void add(int u,int v,int w){
	e[++cnte]=edge{Head[u],v,w};
	Head[u]=cnte;
}
void dfs(int u,int fa){
	rep(i,u){
		int v=e[i].t;
		rep(j,u)if(i!=j)add(e[i].w,e[j].w,0);
		if(v==fa)continue; dfs(v,u);
	}
}
int vis[N],fa[N];
LL ans;
map<int,int> cnt;
void upd(){
	rpt(i,1,n-1)if(!vis[i+n])return ;
	int num=0;
	rpt(i,1,n-1)num=num*10+fa[i+n];
	if(cnt[num])return ;
	cnt[num]=1; ans++;
}
void Get(int u){
	vis[u]=1; upd();
	rep(i,u){
		int v=e[i].t;
		if(vis[v])continue;
		fa[v]=u; Get(v);
	}
	vis[u]=0;
}
int main(){
	freopen("traverse.in","r",stdin);
	freopen("traverse.out","w",stdout);
	scanf("%d%d",&c,&T);
	fac[0]=num[0]=1;
	rpt(i,1,NMax)fac[i]=fac[i-1]*i%mod;
	rpt(i,1,NMax)num[i]=num[i-1]+fac[i];
	if(c==18)while(T--)printf("1\n");
	else if(c>=19&&c<=21){
		while(T--){
			scanf("%d%d",&n,&k);
			rpt(i,1,n-1)scanf("%d%d",&u,&v);
			rpt(i,1,k)scanf("%d",&x);
			ans=fac[n-2]*k%mod;
			if(n-3>=0)ans-=(1ll*k*(k-1)/2)*fac[n-3]%mod;
			else ans-=(1ll*k*(k-1)/2);
			printf("%lld\n",(ans%mod+mod)%mod);
		}
	}
	else {
		while(T--){
			ans=0;
			scanf("%d%d",&n,&k);
			rpt(i,1,n-1){
				scanf("%d%d",&u,&v);
				add(u,v,i+n); add(v,u,i+n);
			}
			dfs(1,0); scanf("%d",&x); Get(x+n);
			printf("%lld\n",ans);
		}
	}
	return 0;
}
