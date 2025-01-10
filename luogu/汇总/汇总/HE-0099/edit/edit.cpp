#include<bits/stdc++.h>
using namespace std;
const int N=1e5+7;
int T;
int n;
string s1,s2;
string t1,t2;
void solve()
{
	scanf("%d",&n);
	cin>>s1>>s2>>t1>>t2;
	int cnt1_1=0,cnt1_0=0;
	int cnt2_1=0,cnt2_0=0;
	for(int i=0;i<n;i++)
	{
		if(t1[i]=='1')
		{
			if(s1[i]=='0') cnt1_0++;
			else if(s1[i]=='1') cnt1_1++;
		}
		if(t2[i]=='1')
		{
			if(s2[i]=='0') cnt2_0++;
			else if(s2[i]=='1') cnt2_1++;
		}
	}
	int ans=0,sum=0;
	int sum1_1=0,sum1_0=0,sum2_1=0,sum2_0=0;
	for(int i=0;i<n;i++)
	{
		if(s1[i]==s2[i])
		{
			ans++;
			if(s1[i]=='1')
			{
				cnt1_1--,cnt2_1--;
				if(t1[i]=='0') cnt1_1++;
				if(t2[i]=='0') cnt2_1++;
			}
			else
			{
				cnt1_0--,cnt2_0--;
				if(t1[i]=='0') cnt1_0++;
				if(t2[i]=='0') cnt2_0++;
			}
		}
		else
		{
			if(t1[i]=='1'&&t2[i]=='1') sum++;
			else if(t1[i]=='1'&&t2[i]=='0')
			{
				if(s2[i]=='1') sum1_1++;
				else if(s2[i]=='0') sum1_0++;
			}
			else if(t1[i]=='0'&&t2[i]=='1')
			{
				if(s1[i]=='1') sum2_1++;
				else if(s1[i]=='0') sum2_0++;
			}
			else
			{
				if(s1[i]==s2[i]) ans++;
			}
		}
	}
	if(cnt1_1<0) cnt1_1=0;
	if(cnt1_0<0) cnt1_0=0;
	if(cnt2_1<0) cnt2_1=0;
	if(cnt2_0<0) cnt2_0=0;
	
	ans+=min(sum1_1,cnt1_1);
	if(sum1_1>cnt1_1) sum1_1=cnt1_1;
	cnt1_1-=sum1_1;
	
	ans+=min(sum1_0,cnt1_0);
	if(sum1_0>cnt1_0) sum1_0=cnt1_0;
	cnt1_0-=sum1_0;
	
	ans+=min(sum2_1,cnt2_1);
	if(sum2_1>cnt2_1) sum2_1=cnt2_1;
	cnt2_1-=sum2_1;
	
	ans+=min(sum2_0,cnt2_0);
	if(sum2_0>cnt2_0) sum2_0=cnt2_0;
	cnt2_0-=sum2_0;
	
	if(sum)
	{
		int cnt1=min(cnt1_1,cnt2_1);
		int cnt0=min(cnt1_0,cnt2_0);
		ans+=min(cnt1+cnt0,sum);
	}
	
	cout<<ans<<endl;
}
signed main()
{
	freopen("edit.in","r",stdin);
	freopen("edit.out","w",stdout);
	scanf("%d",&T);
	while(T--)
	{
		solve();
	}
	return 0;
}
