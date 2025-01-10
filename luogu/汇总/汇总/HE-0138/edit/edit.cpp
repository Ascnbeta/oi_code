#include<bits/stdc++.h>
using namespace std;
int a,s,d[6][1000100],f[4][3],h,g[4];
char z[100010];
int main()
{
	freopen("edit.in","r",stdin); 
	freopen("edit.out","w",stdout);
	cin>>a;
	for(int iiii=1;iiii<=a;iiii++)
	{
		memset(d,0,sizeof(d));
		memset(f,0,sizeof(f));
		h=0;
		g[1]=0;
		g[2]=0;
		cin>>s;
		for(int i=1;i<=4;i++)
		{
			cin>>z;
			
			for(int ii=0;ii<s;ii++)
			{
				d[i][ii+1]=z[ii]-'0';
			}
		}
		for(int i=1;i<=s;i++)
		{
			if(d[3][i]==0)
			{
				if(d[3][i]==d[4][i])
				{
					if(f[1][1]>=f[2][1]) h+=f[1][0]+f[2][1];
					else h+=f[2][0]+f[1][1];
					f[1][1]=0;
					f[2][1]=0;
					f[1][0]=0;
					f[2][0]=0;
					if(d[1][i]==d[2][i]) 
					{
						h++;
					}
				}
				else 
				{
					if(g[2]<i)g[2]=i;
					while(d[4][g[2]]==1)
					{
						f[2][d[2][g[2]]]++;
						g[2]++;
					}
					if(f[2][d[1][i]]>=1)
					{
						h++;
						f[2][d[1][i]]--;
					}
					else
					{
						f[2][1-d[1][i]]--;
					}
					if(f[1][1]>=f[2][1]) 
					{
						h+=f[2][1];
						f[2][1]=0;
					}
					else 
					{
						h+=f[1][1];
						f[2][1]=f[2][1]-f[1][1];
					}
					if(f[1][0]>=f[2][0]) 
					{
						h+=f[2][0];
						f[2][0]=0;
					}
					else 
					{
						h+=f[1][0];
						f[2][0]=f[2][0]-f[1][0];
					}
					f[1][1]=0;
					f[1][0]=0;
				}
			}
			else if(d[4][i]==0)
			{
				if(g[1]<i)g[1]=i;
				while(d[3][g[1]]==1)
				{
					f[1][d[1][g[1]]]++;
					g[1]++;
				}
				if(f[1][d[2][i]]>=1)
				{
					h++;
					f[1][d[2][i]]--;
				}
				else 
				{
					f[1][1-d[2][i]]--;
				}
				if(f[1][1]<f[2][1]) 
				{
					h+=f[1][1];
					f[1][1]=0;
				}
				else 
				{
					h+=f[2][1];
					f[1][1]=f[1][1]-f[2][1];
				}
				if(f[1][0]<f[2][0]) 
				{
					h+=f[1][0];
					f[1][0]=0;
				}
				else 
				{
					h+=f[2][0];
					f[1][0]=f[1][0]-f[2][0];
				}
				f[2][0]=0;
				f[2][1]=0;
			}
			else if(d[4][i]==1)
			{
				if(g[1]<i) f[1][d[1][i]]++;
				if(g[2]<i) f[2][d[2][i]]++;
			}
		}
			if(f[1][1]<f[2][1]) 
			{
				h+=f[1][1];
				f[1][1]=0;
			}
			else 
			{
				h+=f[2][1];
			}
			if(f[1][0]<f[2][0]) 
			{
				h+=f[1][0];
			}
			else 
			{
				h+=f[2][0];
			}
		cout<<h<<endl;
	}
} 
//			
