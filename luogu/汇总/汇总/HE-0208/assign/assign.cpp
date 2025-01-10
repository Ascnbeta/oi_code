#include<bits/stdc++.h>
using namespace std;
int t,n,m,v,i,j,k,sum;
double summl;
long long mod=1e9+7;
const long long N=1e5+10;
long long x[N],a[N],b[N],c[N],d[N];
int main()
{
	freopen("assign.in","r",stdin);
	freopen("assign.out","w",stdout);
	cin>>t;
	for(i=1;i<=t;i++)
	{
		cin>>n>>m>>v;
	}
	for(j=1;j<=m;j++)
	{
		cin>>c[i]>>d[i];
	}
	while(t--)
	{
		for(i=1;i<=n-1;i++)
		{
			for(j=1;j<=m;j++)
			{
				for(k=1;k<=v;k++)
				{
					if(c[j]>=k&&d[j]>=k)
					{
						a[i]=c[j];
						b[i]=c[j+1];
						sum++;
					}
				}
			}
		}
		summl=sum%mod;
		cout<<summl<<endl;	
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
