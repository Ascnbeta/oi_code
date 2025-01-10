#include<bits/stdc++.h>
using namespace std;
int t,n,ans;
string s1,s2,t1,t2;
void tj(int s,int t)
{
	int tj11=0,tj10=0,tj21=0,tj20=0;
	if(s==t)
	{
		if(s1[s]==s2[s])ans++;
		return;
	}
	for(int k=s;k<t;k++)
	{
		if(s1[k]=='1')tj11++;
		if(s1[k]=='0')tj10++;
		if(s2[k]=='1')tj21++;
		if(s2[k]=='0')tj20++;
	}
	if(s1[t]==s2[t])ans++;
	ans=ans+min(tj11,tj21)+min(tj10,tj20);
}
int main()
{
	freopen("edit.in","r",stdin);
	freopen("edit.out","w",stdout);
	scanf("%d",&t);
	for(int i=1;i<=t;i++)
	{
		ans=0;
		cin>>n>>s1>>s2>>t1>>t2;
		int cnt11=0,cnt10=0,cnt21=0,cnt20=0;
		if(s1==s2)
		{
			cout<<n<<endl;
			continue;
		}
		if(t1==t2)
		{
			int pre=0;
			if(t1[0]=='0')
			{
				if(s1[0]==s2[0])
				{
					ans++;
					pre=1;	
				}
			}
			for(int j=1;j<n;j++)
			{
				if(t1[j]=='0')
				{
					tj(pre,j);
					pre=j+1;
				}
			}
			if(pre<=n-1)tj(pre,n-1);
			cout<<ans<<endl;
			continue;
		}
		for(int j=0;j<n;j++)
		{
			if(s1[j]=='1')cnt11++;
			if(s1[j]=='0')cnt10++;
			if(s2[j]=='1')cnt21++;
			if(s2[j]=='0')cnt20++;
		}
		if(cnt11==n) 
		{
			cout<<cnt21<<endl;
			continue;
		}
		if(cnt10==n)
		{
			cout<<cnt20<<endl;
			continue;
		}
	}
	return 0;
}
