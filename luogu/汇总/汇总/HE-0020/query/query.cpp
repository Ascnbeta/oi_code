#include<bits/stdc++.h>
using namespace std;
#define ull unsigned long long
mt19937 rd((ull)(new char)*(ull)(new char));
const int N=5e5+100;
const int inf=3e8;
int n,m,a,b,cnt,head[N],lef,rig,k,ans,d[N];
struct edge{
	int to,nxt;
}e[N<<1];
inline void add(int u,int v){
	cnt++;
	e[cnt].to=v;
	e[cnt].nxt=head[u];
	head[u]=cnt;
}
int depth[N],siz[N],son[N],top[N],fa[N],s[20][N],lg[N],t[20][N];
void dfs1(int u,int f){
	siz[u]=1;depth[u]=depth[f]+1;
	fa[u]=f;
	for(int i=head[u];i;i=e[i].nxt){
		int v=e[i].to;
		if(v==f)continue;
		dfs1(v,u);
		siz[u]+=siz[v];
		if(siz[v]>siz[son[u]])son[u]=v;
	}
}
void dfs2(int u,int t){
	top[u]=t;
	if(son[u]){
		dfs2(son[u],t);
	}
	for(int i=head[u];i;i=e[i].nxt){
		int v=e[i].to;
		if(v==fa[u]||v==son[u])continue;
		dfs2(v,v);
	}
}
int num=0;
int get(int x,int y){
	num=0;
	int fx=top[x],fy=top[y];
	while(fx!=fy){
		if(depth[fx]<depth[fy]){
			swap(x,y);
			swap(fx,fy);
		}
		x=fa[fx];
		fx=top[x];
	}
	if(depth[x]<depth[y])return x;
	else return y;
}
inline int LCA(int x,int y){
	int llg=lg[y-x+1];
	return get(s[llg][x],s[llg][y-(1<<llg)+1]);
}
bool check(){
	for(int i=1;i<=n;i++){
		if(d[i]>2)return 0;
	}
	return 1;
}
signed main()
{
	freopen("query.in","r",stdin);
	freopen("query.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<n;i++){
		scanf("%d%d",&a,&b);d[a]++;d[b]++;
		add(a,b);
		add(b,a);
	}
	dfs1(1,0);
	dfs2(1,1);
	for(int i=2;i<=n;i++)lg[i]=lg[i>>1]+1,s[0][i]=i,t[0][i]=depth[i];
	for(int i=1;i<n;i++){
		s[1][i]=get(i,i+1);
		t[1][i]=min(t[0][i],t[0][i+1]);
	}
	for(int i=2;i<=lg[n];i++){
		for(int j=1;j+(1<<i)-1<=n;j++){
			s[i][j]=get(s[i-1][j],s[i-1][j+(1<<(i-1))]);
			t[i][j]=min(t[i-1][j],t[i-1][j+(1<<(i-1))]);
		}
	}
	scanf("%d",&m);
	int q=m;
	while(m--){
		ans=1;
		scanf("%d%d%d",&lef,&rig,&k);
		if(1ll*(rig-lef+1-k)*15*q<=inf){
			for(int i=lef;i+k-1<=rig;i++){
				ans=max(ans,depth[LCA(i,i+k-1)]);
			}
		}
		else {
			for(int i=1;i<=inf/(q*15);i++){
				int j=rd()%(rig-lef-k+2)+lef;
				ans=max(ans,depth[LCA(j,j+k-1)]);
			}
		}
		printf("%d\n",ans);
	}
}
