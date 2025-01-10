#include<bits/stdc++.h>
using namespace std;
int u[11451400],v[11451400];
int shen[11451400];
int n;
int o[11451400];
int son(int i)
{
	for(int j=1;j<n;j++)
	{
		if(shen[u[j]])
		{
			if(u[j]==i&&shen[v[j]]==0)
			{
				shen[v[j]]=shen[u[j]]+1;
				son(v[j]);
				return 0;
			}
		}
		if(shen[v[j]])
		{
			if(v[j]==i&&shen[u[j]]==0)
			{
				shen[u[j]]=shen[v[j]]+1;
				son(u[j]);
				return 0;
			}
		}
	}
}
int main()
{
	freopen("query.in","r",stdin);
	freopen("query.out","w",stdout);
	shen[1]=1;
	cin>>n;
	for(int i=1;i<n;i++)
	{
		cin>>u[i]>>v[i];
	}
	son(1);
	int q;
	cin>>q;
	while(q--)
	{
		int l,r,k;
		cin>>l>>r>>k;
		for(int i=l,j=1;i<=r;i++,j++)o[j]=shen[i];
		sort(o+1,o+r+1);
		cout<<o[r-k+1]<<endl;
		for(int i=1;i<=r+1;i++)o[i]=0;
	}
}
