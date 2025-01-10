#include<bits/stdc++.h>
using namespace std;
const int N=100010;
int T;
inline int read()
{
	int x=0,f=1;
	char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-') f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-48;ch=getchar();}
	return x*f;
}
int main()
{
	freopen("edit.in","r",stdin);
	freopen("edit.out","w",stdout);
	T=read();
	while(T--)
	{
		int n,s1[N],s2[N],t1[N],t2[N],ans=0;
		int c=1,b=1,c01=0,c11=0,c02=0,c12=0;
		n=read();
		s1[1]=read();
		for(int i=2;i<=n;i++)
		{
			s1[i]=read();
			if(s1[i]!=s1[i-1])
				b=0;
		}
		for(int i=1;i<=n;i++)
			s2[i]=read();
		for(int i=1;i<=n;i++)
		{
			t1[i]=read();
			if(t1[i])
			{
				if(s1[i])
					c11++;
				else
					c01++;
			}
		}
		for(int i=1;i<=n;i++)
		{
			t2[i]=read();
			if(t1[i]!=t2[i])
				c=0;
			if(t2[i])
			{
				if(s2[i])
					c12++;
				else
					c02++;
			}
		}
		if(c)
		{
			for(int i=1;i<=n;i++)
				if(!t1[i])
					if(s1[i]==s2[i])
						ans++;
			ans+=min(c11,c12)+min(c01,c02);	
		}
		else if(b)
		{
			for(int i=1;i<=n;i++)
				if(s1[i]==s2[i])
					ans++;
		}
		else
			ans+=min(c11,c12)+min(c01,c02);
		printf("%d\n",ans);
	}
	return 0;
}
