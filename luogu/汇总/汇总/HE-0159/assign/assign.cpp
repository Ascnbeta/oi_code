#include<bits/stdc++.h>
using namespace std;
const int N=1e9+10;
const int M=1e5+10;
const int mo=1e9+7;
int T,n,m,v,ans;
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
	freopen("assign.in","r",stdin);
	freopen("assign.out","w",stdout);
	T=read();
	while(T--)
	{
		n=read();
		m=read();
		v=read();
		ans=0;
		int c[M],d[M],x[N],a[N],b[N];
		memset(x,0,sizeof(x));
		for(int i=1;i<=m;i++)
		{
			c[i]=read();
			d[i]=read();
			x[c[i]]=d[i];
		}
		for(int i=1;i<=n;i++)
		{
			if(!x[i])
			{
				for(int j=1;j<=v;j++)
				{
					a[i]=i;
					b[i+1]=j;
					for(int p=1;p<=v;p++)
					{
						for(int q=1;q<=v;q++)
						{
							if(p==a[q]&&x[p]==b[q])
								ans++;
						}
					}
				}
			}
		}
		ans%=mo;
		printf("%d\n",&ans);
	}
	return 0;
}
