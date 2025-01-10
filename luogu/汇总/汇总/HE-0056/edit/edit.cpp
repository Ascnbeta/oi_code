#include <bits/stdc++.h>
using namespace std;
const int N=1e5+7;
int T,n;
string s1,s2,t1,t2;
void solve()
{
	cin>>n>>s1>>s2>>t1>>t2;
	int cnt=1;
	for(int i=0;i<n;++i)
	{
		if(s1[i]==s1[i-1]) ++cnt;
	}
	if(cnt==n) 
	{
		cnt=0;
		for(int i=0;i<n;++i)
		{
			if(s1[i]==s2[i]) ++cnt;
		}
		printf("%d\n",cnt);
		return ;
	}
	int cnt1=0,cnt2=0;//起点终点
	cnt=0;//个数
	s1='#'+s1;
	s2='#'+s2;
	t1='#'+t1;
	t2='#'+t2;
	for(int i=1;i<=n;++i)
	{
		if(t1[i]='1' && (t1[i-1]=='0' || t1[i-1]=='#')) cnt1=i,cnt=1;
		else if(t1[i+1]=='0' && cnt>=2 && t1[i]=='1')
		{
			cnt2=i;
			int res1=0,res2=0;
			for(int j=cnt1;j<cnt2;++j)
			{
				if(s1[j]=='1') ++res1;
				if(s1[j]=='0') ++res2;
			}
			if(res1==0 || res2==0) continue;
			else 
			{
				for(int j=cnt1,p=1,q=1;j<cnt2;++j)
				{
//					if(s1[j]==s2[j] && s1[j]=='1') ++p;
//					else if(s1[j]==s2[j] && s1[j]=='0') ++q;
					if(s2[j]=='1' && p<=res1) s1[j]='1',++p;//1
					else if(s2[j]=='1' && p>res1) s1[j]='0',++q;//0
					else if(s2[j]=='0' && q<=res2) s1[j]='0',++q;//0
					else if(s2[j]=='0' && q>res2) s1[j]='1',++p;//1
				}
			}
		}
		else if(t1[i]=='1') ++cnt;
		else if(t1[i]=='0') cnt=0;
	}
	
	for(int i=1;i<=n;++i)
	{
		if(t2[i]='1' && (t2[i-1]=='0' || t2[i-1]=='#')) cnt1=i,cnt=1;
		else if(t2[i+1]=='0' && cnt>=2 && t2[i]=='1')
		{
			cnt2=i;
			int res1=0,res2=0;
			for(int j=cnt1;j<cnt2;++j)
			{
				if(s2[j]=='1') ++res1;
				if(s2[j]=='0') ++res2;
			}
			if(res1==0 || res2==0) continue;
			else 
			{
				for(int j=cnt1,p=1,q=1;j<cnt2;++j)
				{
//					if(s1[j]==s2[j] && s1[j]=='1') ++p;
//					else if(s1[j]==s2[j] && s1[j]=='0') ++q;
					if(s1[j]=='1' && p<=res1) s2[j]='1',++p;
					else if(s1[j]=='1' && p>res1) s2[j]='0',++q;
					else if(s1[j]=='0' && q<=res2) s2[j]='0',++q;
					else if(s1[j]=='0' && q>res2) s2[j]='1',++p;
				}
			}
		}
		else if(t2[i]=='1') ++cnt;
		else if(t2[i]='0') cnt=0;
	}
	int ans=0;
	for(int i=1;i<=n;++i)
	{
		if(s1[i]==s2[i]) ++ans;
	}
	printf("%d\n",ans);
}
signed main()
{
	freopen("edit.in","r",stdin);
	freopen("edit.out","w",stdout);
	cin>>T;
	while(T--)
	solve();
	return 0;
}
