#include <bits/stdc++.h>
using namespace std;
int t;
int c[10001],d[10001];
int main() 
{
	freopen("assign.in","r",stdin);
	freopen("assifn.out","w",stdout);
	cin>>t;
	while(t--)
	{
		int n,m,v,cnt=0,p[10080];
		cin>>n>>m>>v;
		for(int i=1;i<=m;i++)
		{
			cin>>c[i]>>d[i];
		}
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=m;j++)
			{
				if(c[j]==v-i+1) cnt++;
				if(d[j]==v+j+1&&i+j==c[j]) cnt--;
				else continue;
			}
		}
		cout<<cnt;
	}
	string s1,s2,t1,t2;
	bool flag=true;
	int cnt=0;
	for(int i=0;i<s1.size();i++)
	{
		if(s1[i]!=s1[i+1])
			flag=false;
	}
	if(flag) 
	{
		for(int i=0;i<s1.size();i++) 
		{
			if(s2[i]==s1[0]) cnt++;
		}
		cout<<cnt;
	}
	if(t1==t2)
	{
		int cnt1=0,cnt2=0;
		int k=0;
		for(int i=0;i<s1.size();i++)
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
			}
			if(s1[i]==0) cnt1++;
			if(s2[i]==0) cnt2++;
		}
	}
	fclose(stdout);
	fclose(stdout);
	return 0;
}
