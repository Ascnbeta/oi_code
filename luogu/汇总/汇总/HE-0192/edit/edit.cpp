#include<bits/stdc++.h>
using namespace std;
int cnt1,cnt2;
char s1[114514],s2[114514],t1[114514],t2[114514];
int ss1[10],ss2[10];
priority_queue<int>q;
int main()
{
	freopen("edit.in","r",stdin);
	freopen("edit.out","w",stdout);
	int T;
	cin>>T;
	while(T--)
	{
		int n;
		cin>>n;
		cin>>s1;
		cin>>s2;
		cin>>t1;
		cin>>t2;
		int ans=0;
		int c1_0=0,c2_0=0;
		for(int i=0;i<n;i++)
		{
			if(s1[i]-'0'==1)ss1[1]++;
			else ss1[0]++;
			if(s2[i]-'0'==1)ss2[1]++;
			else ss2[0]++;
			if(t1[i]=='0')
			{
				ss1[s1[i]-'0']--;
				ans+=min(ss1[1],ss2[1]);
				ans+=min(ss1[0],ss2[0]);
				ss2[1]=max(ss2[1]-ss1[1],0);
				ss2[0]=max(ss2[0]-ss1[0],0);
				if(ss2[s1[i]-'0'])
				{
					ans++;
					ss2[s1[i]-'0']--;
				}
				ss1[1]=0,ss1[0]=0;
			}
			if(t2[i]=='0')
			{
				ss2[s2[i]-'0']--;
				ans+=min(ss1[1],ss2[1]);
				ans+=min(ss1[0],ss2[0]);
				ss1[1]=max(ss1[1]-ss2[1],0);
				ss1[0]=max(ss1[0]-ss2[0],0);
				if(ss1[s2[i]-'0'])
				{
					ans++;
					ss1[s2[i]-'0']--;
				}
				ss2[1]=0,ss2[0]=0;
			}
		}
		ans+=min(ss1[1],ss2[1]);
		ans+=min(ss1[0],ss2[0]);
		cout<<ans<<endl;
		ss1[1]=0;ss1[0]=0;ss2[1]=0;ss2[0]=0;
		}
}
