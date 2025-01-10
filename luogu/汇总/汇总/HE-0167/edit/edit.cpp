#include <bits/stdc++.h>
using namespace std;
int T;
int main()
{
	freopen("edit.in","r",stdin);
	freopen("edit.out","w",stdout);
	cin>>T;
	while(T--)
	{
		int n,cnt=0;
		cin>>n;
		string s1,s2,t1,t2;
		cin>>s1>>s2>>t1>>t2;
		bool flag=true;
		for(int i=0;i+1<n;i++)
		{
			if(s1[i]!=s1[i+1])
				flag=false;
		}
		if(flag) 
		{
			for(int i=0;i<n;i++) 
			{
				if(s2[i]==s1[0]) cnt++;
			}
			cout<<cnt;
			continue;
		}
		if(t1==t2)
		{
			int cnt1=0,cnt2=0;
			int k=0;
			for(int i=0;i<n;i++)
			{
				
				if(t1[i]==0)
				{
					k=i;
					int sum_0=min(cnt1,cnt2);
					int sum_1=min(i-k-1-cnt1,i-k-1-cnt2);
					int sum=sum_0+sum_1;
					cnt1=0,cnt2=0;
					if(s1[i]==s2[i]) sum++;
					cnt+=sum;
					continue;
				}
				if(s1[i]==0) cnt1++;
				if(s2[i]==0) cnt2++;
			}
			cout<<cnt;
			continue;
		}
	}
	fclose(stdin);
	fclsoe(stdout);
	return 0;
}
