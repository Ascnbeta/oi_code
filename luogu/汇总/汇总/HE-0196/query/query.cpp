#include <bits/stdc++.h>
using namespace std;
const int N=5e5+10,M=1e6+10;
int h[N],e[M],ne[M],idx;
int n,q;
int dep[N],f[N];
int x[N];
void add(int a,int b)
{
	e[idx]=b,ne[idx]=h[a],h[a]=idx++;
}
void dfs(int u,int fa)
{   f[u]=fa;
	dep[u]=dep[fa]+1;
	for(int i=h[u];~i;i=ne[i])
	{
		int j=e[i];
		if(j==fa) continue;
		dfs(j,u);
	}
	return;
}
int lca(int a,int b)
{
	if(dep[a]<=dep[b]) swap(a,b);
	while(dep[f[b]]<=dep[a])
	  {
	  	   b=f[b];	   
	  }
	while(f[b]!=f[a])
	{
		b=f[b];
		a=f[a];
	}
	return f[b];
}
bool cmp(int a,int b)
{
	return dep[a]>dep[b];
}
int main(){
	freopen("query.in","r",stdin);
	freopen("query.out","w",stdout);
	memset(h,-1,sizeof h);
    cin>>n;
    for(int i=1;i<n;i++)
    {  int u,v;
    	cin>>u>>v;
    	add(u,v);
    	add(v,u);
	}
	for(int i=1;i<=n;i++) x[i]=i;
	dfs(1,0);
	sort(x+1,x+1+n,cmp);
	cin>>q;                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                              
	while(q--)
	{   int l,r,k;
		cin>>l>>r>>k;
		if(k==r-l+1)
		{
			cout<<dep[lca(l,r)]<<'\n';
		}
	    cout<<l+r/2<<'\n';
	}
	return 0;
}
