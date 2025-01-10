#include<bits/stdc++.h>
using namespace std;
const int N=1e5+3;
long long T,n,zs,ks,sum1[N],sum2[N];
char s1[N],s2[N],t1[N],t2[N];
int main()
{
	freopen("edit.in","r",stdin);
	freopen("edit.out","w",stdout);
	cin>>T;
	while(T--)
	{
		zs=0,ks=1;
		bool c=0;
		cin>>n;
		memset(s1,'0',n+1);
		memset(s2,'0',n+1);
		cin>>s1+1>>s2+1>>t1+1>>t2+1;		
		sum1[0]=0,sum2[0]=0,s1[n+1]='3',s2[n+1]='4';
		t2[0]='0',t1[0]='0',t1[n+1]='0',t2[n+1]='0';
		for(int i=1;i<=n;i++)
		{
			if(t1[i-1]=='0'&&t1[i+1]=='0')
				t1[i]='0';
			if(t2[i-1]=='0'&&t2[i+1]=='0')
				t2[i]='0';
		}
		for(int i=1;i<=n;i++)
		{
			sum1[i]=sum1[i-1]+(s1[i]-'0');
			sum2[i]=sum2[i-1]+(s2[i]-'0');
		}
		for(int i=1;i<=n;i++)
		{
			if(t1[i]=='0'&&t2[i]=='0')
				continue;
			else
				t1[i]='1',t2[i]='1';
		}
		for(int i=1;i<=n+1;i++)
		{
			if(t1[i-1]=='0'&&t1[i]=='1')
				ks=i,c=0;
			if(t1[i]=='0')
			{
				if(s1[i]==s2[i])
					zs++;
				if(c!=1)
				{
					c=1;
					zs+=i-ks+min(sum1[i-1]-sum1[ks-1],sum2[i-1]-sum2[ks-1])-max(sum1[i-1]-sum1[ks-1],sum2[i-1]-sum2[ks-1]);
				}	
			}
		}
		cout<<zs<<endl;
	}
	return 0;
}
