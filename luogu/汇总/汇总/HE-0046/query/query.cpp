#include<bits/stdc++.h>
using namespace std;

int n,shen[510000],f[510000][32];
vector<int> dian[510000];
void chuli(int x,int fa)
{
	f[x][0]=fa;
	shen[x]=shen[fa]+1;
	for(int i=1;i<=30;i++) f[x][i]=f[f[x][i-1]][i-1];
	int chang=dian[x].size();
	for(int i=0;i<chang;i++)
	{
		int v=dian[x][i];
		if(v==fa) continue;
		chuli(v,x);
	}
}
int lca(int a,int b)
{
	if(shen[a]<shen[b]) swap(a,b);
	for(int i=30;i>=0;i--)
		if(shen[f[a][i]]>=shen[b]) a=f[a][i];
	if(a==b) return a;
	for(int i=30;i>=0;i--)
		if(f[a][i]!=f[b][i]) a=f[a][i],b=f[b][i];
	return f[a][0];
}
int main()
{
	freopen("query.in","r",stdin);
	freopen("query.out","w",stdout);
	cin>>n;
	for(int i=1,u,v;i<n;i++) cin>>u>>v,dian[u].push_back(v),dian[v].push_back(u);
	chuli(1,0);
	int q;
	cin>>q;
	for(int i1=1;i1<=q;i1++)
	{
		int l,r,k,da=0;
		cin>>l>>r>>k;
		if(k==r-l+1) da=shen[lca(l,r)];
		else
		{
			for(int i=l;i<=r;i++)
			{
				for(int c=k;c<=n;c++)
				{
					int j=i+c-1;
					if(j>r) break;
					da=max(da,shen[lca(i,j)]);
				}
			}
		}
		cout<<da<<'\n';
	}
	
	
	fclose(stdin);
	fclose(stdout);
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





*/

