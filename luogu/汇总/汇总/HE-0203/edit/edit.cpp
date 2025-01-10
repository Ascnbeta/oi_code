#include<bits/stdc++.h>
using namespace std;
long long T,n,ans;
long long s1[9999999],s2[9999999],t1[9999999],t2[9999999];
int main()
{
	freopen("edit.in","r",stdin);
	freopen("edit.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>T;
		long long d1,d2,sum;
		ans=0;
		int flaga=1,flagb=1;
		for(int j=1;j<=T;j++)
		{
			cin>>s1[j];
			if(s1[j]!=s1[j-1]&&j>=2)flaga=0;
			if(s1[j]==0)d1=j;
		}
		for(int j=1;j<=T;j++)
		{
			cin>>s2[j];
			if(s2[j]==0)d2=j;
		}
		for(int j=1;j<=T;j++)
		{
			cin>>t1[j];
			if(t1[i]==0)sum++;
		}
		for(int j=1;j<=T;j++)cin>>t2[j];
		if(flaga)//符合A 
		{
			for(int j=1;j<=T;j++)
			{
				if(s2[j]==s1[j])
				{
					ans++;
				}
			}
			cout<<ans<<endl;
			continue;
		}
		else //不符合A 符合C 
		{
			cout<<T-2<<endl; 
			continue;
		}
		for(int j=1;j<=T;j++)
		{
			if(t1[j]!=t2[j])
			{
				flagb=0;
				break;
			}
		}
		if(flagb)//符合B
		{
			long long s=0,t=T;
			for(int j=1;j<=sum;j++)
			{
				for(int k=s+1;k<=T;k++)
				{
					if(t1[k]==0)t=k;
					else t=T;
				}
				int sum0=0,sum1=0;
				for(int k=s;k<t;k++)
				{
					if(s1[k]==0)sum0++;
					if(s1[k]==1)sum1++;
				}
				ans+=max(sum0,sum1);
				if(s1[t]==s2[t]&&t1[t]==0)ans++;
			}
			cout<<ans<<endl;
		}
	}
	return 0;
}
