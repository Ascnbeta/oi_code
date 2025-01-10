#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int n,T,C1,C2;
char s1[N],s2[N],t1[N],t2[N];
bool B;
int main()
{
	freopen("edit.in","r",stdin);
	freopen("edit.out","w",stdout);
	scanf("%d",&T);
	while(T--)
	{
		int tot=0;C1=C2=0;B=false;
		scanf("%d",&n);
		scanf("%s %s %s %s",s1+1,s2+1,t1+1,t2+1);
		for(int i=1;i<=n;++i)
		{
			if(t1[i]!=t2[i])
			{
				B=true;
				break;
			}
			if(t1[i]=='0')C1++;
			if(t2[i]=='0')C2++;
		}
		if(!B)
		{
			for(int i=1;i<=n;++i)
			{
				if(t1[i]!='1'||t1[i+1]!='1')
				{
					if(s2[i]==s1[i])tot++;
					continue;
				}
				int a1=0,a2=0,b1=0,b2=0;
				while(t1[i]=='1'&&i<=n)
				{
					if(s1[i]=='1')a2++;
					if(s1[i]=='0')a1++;
					if(s2[i]=='0')b1++;
					if(s2[i]=='1')b2++;
					i++;
				}
				i--;
				tot=tot+min(a1,b1)+min(a2,b2);
			}
			printf("%d\n",tot);
			continue;
		}
		for(int i=1;i<n;++i)
		{
			int j=i+1;
			if(t1[i]=='1'&&t1[j]=='1')
			{
				if(s1[j]==s2[i])swap(s1[j],s1[i]);
			}
			if(t2[i]=='1'&&t2[j]=='1')
			{
				if(s2[j]==s1[i])swap(s2[j],s2[i]);
			}
		}
		for(int i=n;i>1;--i)
		{
			int j=i-1;
			if(t1[i]=='1'&&t1[j]=='1')
				if(s1[j]==s2[i])swap(s1[j],s1[i]);
			if(t2[i]=='1'&&t2[j]=='1')
				if(s2[j]==s1[i])swap(s2[i],s2[j]);
		}
		for(int i=1;i<=n;++i)
			if(s1[i]==s2[i])tot++;
		printf("%d\n",tot);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
