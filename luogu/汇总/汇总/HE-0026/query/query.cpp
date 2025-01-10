#include<bits/stdc++.h>
using namespace std;
#define mi(x,y) (dfn[x]<dfn[y]?x:y)
const int N = 5e5+5;
int n,du[N],q;
int head[N],tot,st[40][N],lg[N],s[40][N];
struct E {int u,v;} e[N<<1];
inline void add(int u,int v) {e[++tot]={head[u],v}; head[u]=tot;}
int dep[N],dfn[N],num;
void dfs(int u,int f)
{
	dep[u]=dep[f]+1; dfn[u]=++num; st[0][num]=f;
	for(int i=head[u];i;i=e[i].u)
	{
		int v=e[i].v; if(v==f) continue;
		dfs(v,u);
	}
}

inline int get(int x,int y)
{
	if(x==y) return x;
	if((x=dfn[x])>(y=dfn[y])) swap(x,y); x++;
	int k=lg[y-x+1];
	return mi(st[k][x],st[k][y-(1<<k)+1]);
}
inline int work(int x,int y)
{
	int k=lg[y-x+1];
	return get(s[k][x],s[k][y-(1<<k)+1]);
}

int main()
{
	freopen("query.in","r",stdin);
	freopen("query.out","w",stdout);
	scanf("%d",&n); lg[0]=-1;
	for(int i=1;i<=n;i++) lg[i]=lg[i>>1]+1;
	for(int i=1;i<n;i++)
	{
		int x,y; scanf("%d%d",&x,&y);
		add(x,y); add(y,x); du[x]++; du[y]++;
	}
	dfs(1,0);
	for(int i=1;i<=30;i++) for(int j=1;j+(1<<i)-1<=n;j++) st[i][j]=mi(st[i-1][j],st[i-1][j+(1<<(i-1))]);
	for(int i=1;i<=n;i++) s[0][i]=i;
	for(int i=1;i<=30;i++) for(int j=1;j+(1<<i)-1<=n;j++) s[i][j]=get(s[i-1][j],s[i-1][j+(1<<(i-1))]);
	scanf("%d",&q);
	while(q--)
	{
		int l,r,k,res=0; scanf("%d%d%d",&l,&r,&k);
		for(int i=l,j=i+k-1;j<=r;i++,j++)
		{
			res=max(res,dep[work(i,j)]);
		}
		printf("%d\n",res);
	}
	return 0;
}