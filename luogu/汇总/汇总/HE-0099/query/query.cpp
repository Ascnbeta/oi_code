#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+7;
int n,q;
int l,r,k;
int sum[N];
//bool vis[N];
int id[N];
int f[N];
//struct node
//{
//	int next,to;
//}e[N];
//int head[N],cnt=0;
//void add(int u,int v)
//{
//	cnt++;
//	e[cnt].to=v;
//	e[cnt].next=head[u];
//	head[u]=cnt;
//}
int find(int x)
{
	if(f[x]!=x) return f[x]=find(f[x]);
	return x;
}
signed main()
{
	freopen("query.in","r",stdin);
	freopen("query.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++) f[i]=i;
	for(int i=1;i<n;i++)
	{
		int u,v;
		cin>>u>>v;
		int fu=find(u),fv=find(v);
		f[fu]=fv;
	}
	for(int i=1;i<=n;i++)
	{
		if(f[i]==i)
		{
			sum[n]=i;
			break;
		}
	}
	for(int i=1;i<=n;i++) id[f[i]]=i;
	for(int i=1;i<=n-1;i++) sum[i]=id[n+1-i];
//	int v=1,cnt=1;
//	while(cnt<=n)
//	{
//		for(int i=head[v];i;i=e[i].next)
//		{
//			v=e[i].to;
//			if(vis[v]) continue;
//			cnt++;
//			sum[cnt]=e[i].to;
//		}
//	}
	cin>>q;
	while(q--)
	{
		cin>>l>>r>>k;
		cout<<(sum[l]+sum[r])/k<<endl;
	}
	return 0;
}
