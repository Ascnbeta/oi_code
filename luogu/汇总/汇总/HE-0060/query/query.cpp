#include<bits/stdc++.h>
#define ll p<<1
#define lr p<<1|1
using namespace std;
const int N=5e5+10;
int n,m,a[N],q,head[N],cnt;
bool vis[N];
vector<int>e[N];
struct node{
	int l,r,num;
}tr[N<<2];
inline int read()
{
	int s=0,x=1;char ch=getchar();
	while(!isdigit(ch)){if(ch=='-')x=-1;ch=getchar();}
	while(isdigit(ch)){s=(s<<3)+(s<<1)+(ch^48),ch=getchar();}
	return s*x;
}
void build(int l,int r,int p)
{
	tr[p].l=l;tr[p].r=r;
	if(l>=r)
	{
		tr[p].num=a[l];
		return ;
	}
	int mid=(l+r)>>1;
	build(l,mid,ll);build(mid+1,r,lr);
	tr[p].num=max(tr[ll].num,tr[lr].num);
}
int query(int l,int r,int p)
{
	int ans=0;
	if(tr[p].l>=l&&tr[p].r<=r)
	{
		ans=max(ans,tr[p].num);
		return ans;
	}
	ans=max(ans,max(query(l,r,lr),query(l,r,ll)));
	return ans;
}
int main()
{
	freopen("query.in","r",stdin);
	freopen("query.out","w",stdout);
//	scanf("%d",&n);
	n=read();
	for(int i=1;i<=n;++i)
	{
//		int u,v;scanf("%d %d",&u,&v);
		int u=read(),v=read();
		e[u].push_back(v);
		e[v].push_back(u);
	}
	a[1]=1;vis[1]=true;
	int o=1;
	for(int i=0;i<e[o].size();++i)
	{
		if(vis[e[o][i]])continue;
		a[e[o][i]]=a[o]+1;vis[o]=true;
		o=e[o][i];
	}
	build(1,n,1);
//	scanf("%d",&q);
	q=read();
	while(q--)
	{
//		int x,y,k;scanf("%d %d %d",&x,&y,&k);
		int x=read(),y=read(),k=read();
		printf("%d\n",query(x,y,1));
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
