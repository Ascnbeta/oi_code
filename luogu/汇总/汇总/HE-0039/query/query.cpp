#include<bits/stdc++.h>
using namespace std;
#define il inline
#define ri register int
#define inf 0x3f3f3f3f
int a,b,u,v,w,f[500005],g,fa[500005],dep[500005],dfs[500005],rks[500005],cnt,ans,in[500005],pa[500005];
bool te;
struct node
{
	int h,to;
}pic[1000001];
il int dmin(int x,int y)
{
	return dep[x]<dep[y]?x:y;
}
il int dmax(int x,int y)
{
	return dep[x]>dep[y]?x:y;
}
il void ndin(int x,int y)
{
	g++;
	pic[g]={f[x],y};
	f[x]=g;
}
struct STB
{
	int num[22][500005],leg[500005];
	il void build(int x)
	{
		for(ri i=1;i<=x;i++)
		{
			num[0][i]=rks[i];
			leg[i]=__lg(i);
		}
		for(ri i=1;i<=leg[x];i++)
		{
			ri k=1<<(i-1);
			for(ri j=1;j+k<=x;j++)
			{
				num[i][j]=dmin(num[i-1][j],num[i-1][j+k]);
			}
		}
	}
	il int find(int x,int y)
	{
		if(x==y)
		{
			return x;
		}
		x=dfs[x],y=dfs[y];
		if(x>y)
		{
			swap(x,y);
		}
		ri z=leg[y-x];
		return fa[dmin(num[z][x+1],num[z][y-(1<<z)+1])];
	}
}st;
struct XDS
{
	int left[2000002],right[2000002],num[2000002];
	il int ls(int x)
	{
		return x<<1;
	}
	il int rs(int x)
	{
		return x<<1|1;
	}
	il void pu(int x)
	{
		num[x]=st.find(num[ls(x)],num[rs(x)]);
	}
	void build(int x,int lt,int rt)
	{
		left[x]=lt;
		right[x]=rt;
		if(lt==rt)
		{
			num[x]=lt;
			return;
		}
		ri me=(left[x]+right[x])>>1;
		build(ls(x),lt,me);
		build(rs(x),me+1,rt);
		pu(x);
	}
	int find(int x,int lt,int rt)
	{
		if(lt<=left[x]&&right[x]<=rt)
		{
			return num[x];
		}
		ri me=(left[x]+right[x])>>1,rn=0;
		if(lt<=me)
		{
			if(!rn)
			{
				rn=find(ls(x),lt,rt);
			}
			else
			{
				rn=st.find(find(ls(x),lt,rt),rn);
			}
		}
		if(rt>me)
		{
			if(!rn)
			{
				rn=find(rs(x),lt,rt);
			}
			else
			{
				rn=st.find(find(rs(x),lt,rt),rn);
			}
		}
		return rn;
	}
}tree;
void dfs0(int x)
{
	cnt++;
	dfs[x]=cnt;
	rks[cnt]=x;
	for(ri i=f[x];i;i=pic[i].h)
	{
		ri y=pic[i].to;
		if(y!=fa[x])
		{
			fa[y]=x;
			dep[y]=dep[x]+1;
			pa[dep[y]]=y;
			dfs0(y);
		}
	}
}
namespace task1
{
	int lt[500005],rt[500005];
	il bool check(int x)
	{
		return min(rt[pa[x]]-1,v)-max(lt[pa[x]]+1,u)+1>=w;
	}
	short main()
	{
		deque<int>que;
		for(ri i=1;i<=a;i++)
		{
			while(!que.empty()&&dep[que.back()]>dep[i])
			{
				que.pop_back();
			}
			if(que.empty())
			{
				lt[i]=0;
			}
			else
			{
				lt[i]=que.front();
			}
			que.push_back(i);
		}
		while(!que.empty())
		{
			que.pop_back();
		}
		for(ri i=a;i>=1;i--)
		{
			while(!que.empty()&&dep[que.back()]>dep[i])
			{
				que.pop_back();
			}
			if(que.empty())
			{
				rt[i]=a+1;
			}
			else
			{
				rt[i]=que.front();
			}
			que.push_back(i);
		}
		scanf("%d",&b);
		while(b--)
		{
			scanf("%d%d%d",&u,&v,&w);
			ans=0;
			ri m=1,n=a;
			while(n!=m)
			{
				ri l=(m+n+1)>>1;
				if(check(l))
				{
					m=l;
				}
				else
				{
					n=l-1;
				}
			}
			printf("%d\n",m);
		}
		return 0;
	}
}
int main()
{
//	freopen("query3.in","r",stdin);
//	freopen("myquery3.ans","w",stdout);
	freopen("query.in","r",stdin);
	freopen("query.out","w",stdout);
	scanf("%d",&a);
	te=true;
	for(ri i=1;i<a;i++)
	{
		scanf("%d%d",&u,&v);
		ndin(u,v);
		ndin(v,u);
		in[u]++;
		in[v]++;
		if(in[u]>2||in[v]>2)
		{
			te=false;
		}
	}
	dep[1]=1;
	dfs0(1);
	if(te&&a>=5000)
	{
		return task1::main();
	}
	st.build(a);
//	for(ri i=1;i<=a;i++)
//	{
//		for(ri j=1;j<=a;j++)
//		{
//			printf("%d ",st.find(i,j));
//		}
//		puts("");
//	}
	tree.build(1,1,a);
	dep[0]=-inf;
	scanf("%d",&b);
	while(b--)
	{
		scanf("%d%d%d",&u,&v,&w);
		ans=0;
		for(ri i=u;i+w-1<=v;i++)
		{
			ans=dmax(ans,tree.find(1,i,i+w-1));
		}
		printf("%d\n",dep[ans]);
	}
	return 0;
}
/*
6
5 6
6 1
6 2
2 3
2 4
3
2 5 2
1 4 1
1 6 3

3
4
3

5
1 2
2 5
5 4
4 3
114
2 4 2

*/

