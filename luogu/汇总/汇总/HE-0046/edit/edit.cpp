#include<bits/stdc++.h>
using namespace std;
int t,n;
bool o1[110000],o2[110000],ke[6][110000];
int f[110000][2][2],ma[110000],shang[110000][2][2],xia[110000][2][2],tong[110000][2][2],qz[110000];
char sr;
int main()
{
	freopen("edit.in","r",stdin);
	freopen("edit.out","w",stdout);
	srand(19491001);
	cin>>t;
	for(int ttt=1;ttt<=t;ttt++)
	{
		cin>>n;
		if(n>1000)
		{
			for(int i=0;i<=n;i++)
			for(int j=0;j<=1;j++)
				for(int k=0;k<=1;k++)
					f[i][j][k]=-(2e9),shang[i][j][k]=-(2e9),xia[i][j][k]=-(2e9),tong[i][j][k]=-(2e9);
			for(int i=1;i<=n;i++)  cin>>sr,o1[i]=sr-'0',ma[i]=-(2e9);
			for(int i=1;i<=n;i++)  cin>>sr,o2[i]=sr-'0',qz[i]=qz[i-1]+(o1[i]==o2[i]);
			for(int i=1;i<=n;i++)  cin>>sr,ke[1][i]=sr-'0';
			for(int i=1;i<=n;i++)  cin>>sr,ke[2][i]=sr-'0';
			for(int i=1;i<=n;i++)
			{
				if(o1[i]==0&&o2[i]==0)
				{
					f[i][0][0]=ma[i-1]+1;
					if(ke[1][i])
					{
						f[i][1][0]=max(f[i][1][0],shang[i-1][1][0]+1);
						f[i][1][0]=max(f[i][1][0],shang[i-1][1][1]-1);
					}
					if(ke[2][i])
					{
						f[i][0][1]=max(f[i][0][1],xia[i-1][0][1]+1);
						f[i][0][1]=max(f[i][0][1],xia[i-1][1][1]-1);
					}
					if(ke[1][i]&&ke[2][i])
					{
						f[i][1][1]=tong[i-1][0][0]+1;
					}
				}
				else if(o1[i]==1&&o2[i]==1)
				{
					f[i][1][1]=ma[i-1]+1;
					if(ke[1][i])
					{
						f[i][0][1]=max(f[i][0][1],shang[i-1][0][0]-1);
						f[i][0][1]=max(f[i][0][1],shang[i-1][0][1]+1);
					}
					if(ke[2][i])
					{
						f[i][1][0]=max(f[i][1][0],xia[i-1][0][0]-1);
						f[i][1][0]=max(f[i][1][0],xia[i-1][1][0]+1);
					}
					if(ke[1][i]&&ke[2][i])
					{
						f[i][0][0]=tong[i-1][0][0]+1;
					}
				}
				else if(o1[i]==0&&o2[i]==1)
				{
					f[i][0][1]=ma[i-1];
					if(ke[1][i])
					{
						f[i][1][1]=max(f[i][1][1],shang[i-1][1][0]+2);
						f[i][1][1]=max(f[i][1][1],shang[i-1][1][1]);
					}
					if(ke[2][i])
					{
						f[i][0][0]=max(f[i][0][0],xia[i-1][0][0]);
						f[i][0][0]=max(f[i][0][0],xia[i-1][0][1]+2);
					}
					if(ke[1][i]&&ke[2][i])
					{
						f[i][1][0]=tong[i-1][1][0];
					}
				}
				else if(o1[i]==1&&o2[i]==0)
				{
					f[i][1][0]=ma[i-1];
					if(ke[1][i])
					{
						f[i][0][0]=max(f[i][0][0],shang[i-1][0][0]);
						f[i][0][0]=max(f[i][0][0],shang[i-1][0][1]+2);
					}
					if(ke[2][i])
					{
						f[i][1][1]=max(f[i][1][1],xia[i-1][0][1]+2);
						f[i][1][1]=max(f[i][1][1],xia[i-1][1][1]);
					}
					if(ke[1][i]&&ke[2][i])
					{
						f[i][0][1]=tong[i-1][0][1];
					}
				}
				if(ke[1][i])
					for(int j=0;j<=1;j++)
						for(int k=0;k<=1;k++)
							shang[i][j][k]=max(shang[i-1][j][k],f[i][j][k]);
				if(ke[2][i])
					for(int j=0;j<=1;j++)
						for(int k=0;k<=1;k++)
							xia[i][j][k]=max(xia[i-1][j][k],f[i][j][k]);
				if(ke[1][i]&&ke[2][i])
					for(int j=0;j<=1;j++)
						for(int k=0;k<=1;k++)
							tong[i][j][k]=max(tong[i-1][j][k],f[i][j][k]);
				
				for(int j=0;j<=1;j++)
					for(int k=0;k<=1;k++)
						ma[i]=max(ma[i],f[i][j][k]);
		}
		}
		else
		{
			for(int i=1;i<=n;i++)  cin>>sr,o1[i]=sr-'0';
			for(int i=1;i<=n;i++)  cin>>sr,o2[i]=sr-'0';
			for(int i=1;i<=n;i++)  cin>>sr,ke[1][i]=sr-'0';
			for(int i=1;i<=n;i++)  cin>>sr,ke[2][i]=sr-'0';
			int da=0;
			for(int ci=1;ci<=(3e7)/(t*n);ci++)
			{
				int shang=1,s2=1;
				for(int i=1;i<=n;i++)
				{
					if(ke[1][i]==0) random_shuffle(o1+shang,o1+i),shang=i+1;
				}
				random_shuffle(o1+shang,o1+n+1);
				int ans=0;
					int a1=0,a0=0;
				for(int i=1;i<=n;i++)
				{
					if(o2[i]==0) a0++;
					else a1++;
					if(ke[2][i]==0)
					{
						int cab=0;
						random_shuffle(o2+s2,o2+i),ans+=(o1[i]==o2[i]);
						for(int j=s2;j<=i-1;j++) if(o1[j]==o2[j]) cab++;
						for(int j=0;j<=20&&cab<min(a0,a1)-2;j++,ci++)
						{
							cab=0;
	//						cout<<"!";
							random_shuffle(o2+s2,o2+i);
							for(int k=s2;k<=i-1;k++)
								if(o1[k]==o2[k]) cab++;
						}
						a0=a1=0;s2=i+1;
						ans+=cab;
					}
				}
				random_shuffle(o2+s2,o2+n+1);
				for(int j=s2;j<=n;j++) if(o1[j]==o2[j]) ans++;
	//			for(int i=1;i<=n;i++) if(o1[i]==o2[i]) ans++;
				da=max(da,ans);
			}
			cout<<da<<'\n';
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
/*


#include<bits/stdc++.h>
using namespace std;
bool o1[110000],o2[110000],ke[6][110000];
char sr;
int t,n,f[110000][2][2],ma[110000],shang[110000][2][2],xia[110000][2][2],tong[110000][2][2],qz[110000];
int main()
{
//	freopen("edit2.in","r",stdin);
//	freopen("edit.out","w",stdout);
	cin>>t;
	for(int ttt=1;ttt<=t;ttt++)
	{
		cin>>n;
		for(int i=0;i<=n;i++)
			for(int j=0;j<=1;j++)
				for(int k=0;k<=1;k++)
					f[i][j][k]=-(2e9),shang[i][j][k]=-(2e9),xia[i][j][k]=-(2e9),tong[i][j][k]=-(2e9);
		for(int i=1;i<=n;i++)  cin>>sr,o1[i]=sr-'0',ma[i]=-(2e9);
		for(int i=1;i<=n;i++)  cin>>sr,o2[i]=sr-'0',qz[i]=qz[i-1]+(o1[i]==o2[i]);
		for(int i=1;i<=n;i++)  cin>>sr,ke[1][i]=sr-'0';
		for(int i=1;i<=n;i++)  cin>>sr,ke[2][i]=sr-'0';
		for(int i=1;i<=n;i++)
		{
			if(o1[i]==0&&o2[i]==0)
			{
				f[i][0][0]=ma[i-1]+1;
				if(ke[1][i])
				{
					f[i][1][0]=max(f[i][1][0],shang[i-1][1][0]+1);
					f[i][1][0]=max(f[i][1][0],shang[i-1][1][1]-1);
				}
				if(ke[2][i])
				{
					f[i][0][1]=max(f[i][0][1],xia[i-1][0][1]+1);
					f[i][0][1]=max(f[i][0][1],xia[i-1][1][1]-1);
				}
				if(ke[1][i]&&ke[2][i])
				{
					f[i][1][1]=tong[i-1][0][0]+1;
				}
			}
			else if(o1[i]==1&&o2[i]==1)
			{
				f[i][1][1]=ma[i-1]+1;
				if(ke[1][i])
				{
					f[i][0][1]=max(f[i][0][1],shang[i-1][0][0]-1);
					f[i][0][1]=max(f[i][0][1],shang[i-1][0][1]+1);
				}
				if(ke[2][i])
				{
					f[i][1][0]=max(f[i][1][0],xia[i-1][0][0]-1);
					f[i][1][0]=max(f[i][1][0],xia[i-1][1][0]+1);
				}
				if(ke[1][i]&&ke[2][i])
				{
					f[i][0][0]=tong[i-1][0][0]+1;
				}
			}
			else if(o1[i]==0&&o2[i]==1)
			{
				f[i][0][1]=ma[i-1];
				if(ke[1][i])
				{
					f[i][1][1]=max(f[i][1][1],shang[i-1][1][0]+2);
					f[i][1][1]=max(f[i][1][1],shang[i-1][1][1]);
				}
				if(ke[2][i])
				{
					f[i][0][0]=max(f[i][0][0],xia[i-1][0][0]);
					f[i][0][0]=max(f[i][0][0],xia[i-1][0][1]+2);
				}
				if(ke[1][i]&&ke[2][i])
				{
					f[i][1][0]=tong[i-1][1][0];
				}
			}
			else if(o1[i]==1&&o2[i]==0)
			{
				f[i][1][0]=ma[i-1];
				if(ke[1][i])
				{
					f[i][0][0]=max(f[i][0][0],shang[i-1][0][0]);
					f[i][0][0]=max(f[i][0][0],shang[i-1][0][1]+2);
				}
				if(ke[2][i])
				{
					f[i][1][1]=max(f[i][1][1],xia[i-1][0][1]+2);
					f[i][1][1]=max(f[i][1][1],xia[i-1][1][1]);
				}
				if(ke[1][i]&&ke[2][i])
				{
					f[i][0][1]=tong[i-1][0][1];
				}
			}
			if(ke[1][i])
				for(int j=0;j<=1;j++)
					for(int k=0;k<=1;k++)
						shang[i][j][k]=max(shang[i-1][j][k],f[i][j][k]);
			if(ke[2][i])
				for(int j=0;j<=1;j++)
					for(int k=0;k<=1;k++)
						xia[i][j][k]=max(xia[i-1][j][k],f[i][j][k]);
			if(ke[1][i]&&ke[2][i])
				for(int j=0;j<=1;j++)
					for(int k=0;k<=1;k++)
						tong[i][j][k]=max(tong[i-1][j][k],f[i][j][k]);
			for(int j=0;j<=1;j++)
				for(int k=0;k<=1;k++)
					ma[i]=max(ma[i],f[i][j][k]);
			cout<<ma[i]<<" ";
		}
		cout<<ma[n]<<'\n';
//		<<f[4][0][1];
	}
	
	
//	fclose(stdin);
//	fclose(stdout);
	return 0;
}

*/
