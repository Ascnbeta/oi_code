#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define sort stable_sort
#define endl '\n'
struct quality
{
	int l,id;
};
struct node
{
	int nxt,to;
}e[1000010];
int head[1000010],siz[1000010],fa[1000010],top[1000010],dep[1000010],son[1000010],ans[1000010],info[1000010],cnt=0;
vector<quality>q[1000010];
void add(int u,int v)
{
	cnt++;
	e[cnt].nxt=head[u];
	e[cnt].to=v;
	head[u]=cnt; 	
}
void dfs1(int x,int father)
{
	siz[x]=1;
	fa[x]=father;
	dep[x]=dep[father]+1;
	for(int i=head[x];i!=0;i=e[i].nxt)
	{
		if(e[i].to!=fa[x])
		{
			dfs1(e[i].to,x);
			siz[x]+=siz[e[i].to];
			son[x]=(siz[e[i].to]>siz[son[x]])?e[i].to:son[x];
		}
	}
}
void dfs2(int x,int id)
{
	top[x]=id;
	if(son[x]!=0)
	{
		dfs2(son[x],id);
		for(int i=head[x];i!=0;i=e[i].nxt)
		{
			if(e[i].to!=fa[x]&&e[i].to!=son[x])
			{
				dfs2(e[i].to,e[i].to);
			}
		}
	}
}
int lca(int u,int v)
{
	while(top[u]!=top[v])
	{
		if(dep[top[u]]>dep[top[v]])
		{
			u=fa[top[u]];
		}
		else
		{
			v=fa[top[v]];
		}
	}
	return dep[u]<dep[v]?u:v;
}
void solve(int l,int r)
{
	if(l==r)
	{
		for(int i=0;i<q[l].size();i++)
		{
			if(q[l][i].l==l)
			{
				ans[q[l][i].id]=max(ans[q[l][i].id],dep[l]);
			}
		}
		return;
	}
	int mid=(l+r)/2;
	solve(l,mid);
	solve(mid+1,r);
	info[mid]=mid;
	for(int i=mid-1;i>=l;i--)
	{
		info[i]=lca(info[i+1],i);
	}
	info[mid+1]=mid+1;
	for(int i=mid+2;i<=r;i++)
	{
		info[i]=lca(info[i-1],i);
	}
	for(int i=mid+1;i<=r;i++)
	{
		for(int j=0;j<q[i].size();j++)
		{
			if(l<=q[i][j].l&&q[i][j].l<=mid)
			{
				ans[q[i][j].id]=max(ans[q[i][j].id],dep[lca(info[q[i][j].l],info[i])]);
			}
		}
	}
}
int main()
{
    freopen("query.in","r",stdin);
    freopen("query.out","w",stdout);
    int n,m,u,v,l,r,k,i,j;
	scanf("%d",&n);
	for(i=1;i<=n-1;i++)
	{
		scanf("%d%d",&u,&v);
		add(u,v);
		add(v,u);
	}
	dfs1(1,0);
	dfs2(1,1);
	scanf("%d",&m);
	for(i=1;i<=m;i++)
	{
		scanf("%d%d%d",&l,&r,&k);
		for(j=l;j+k-1<=r;j++)
		{
			q[j+k-1].push_back((quality){j,i});
		}
	}
	solve(1,n);
	for(i=1;i<=m;i++)
	{
		printf("%d\n",ans[i]);
	}
    return 0;
}
