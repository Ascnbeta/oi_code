#include <bits/stdc++.h>
using namespace std;
long long T,n,ljq=0,ljq2=0,ljq3=0,ljq12=0;
char s[100005],s2[100005],t[100005],t2[100005]; 
int main()
{
	freopen("edit.in","r",stdin);
	freopen("edit.out","w",stdout);	
	cin>>T;
	while(T--)
	{
		cin>>n;//>>s>>s2>>t>>t2;
		scanf("%s",&s);
		scanf("%s",&s2);
		scanf("%s",&t);
		scanf("%s",&t2);
		ljq=0,ljq2=0,ljq3=0,ljq12=0;
		for(int i=0;i<n;i++)
		{
			if(t2[i]=='0')
			{
				t[i]='0';	
			}
		}
		for(int i=0;i<n;i++)
		{
			if(t[i]=='0')
			{
				ljq=ljq+s[i]-'0';
				ljq2=ljq2+s2[i]-'0';
				ljq12++;
			}else{
				if(s[i]==s2[i])
				{
					ljq3++;
				}
			}
		}
		long long a=ljq3+ljq12-abs(ljq-ljq2);
		cout<<a<<endl;
	}
	return 0;
}
