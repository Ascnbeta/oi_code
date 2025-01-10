#include<bits/stdc++.h>
using namespace std;
int t,n,i,j,k,p,q,sum;
const long long N=1e5+10;
char s1[N],s2[N],t1[N],t2[N];
int main()
{
	freopen("edit.in","r",stdin);
	freopen("edit.out","w",stdout);
	cin>>t>>n;
	while(t--)
	{
		for(i=1;i<=n;i++)
		{
			cin>>s1[i]>>s2[i]>>t1[i]>>t2[i];                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                      
			for(j=1;j<=n;j++)
			{
				if(t1[j]=='1'&&t1[j+1]=='1')
				{
					p=s1[j];                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                             
					s1[j+1]=p;
					s1[j]=s1[j+1];
				}
			}
			for(k=1;k<=n;k++)
			{
				if(t2[k]=='1'&&t2[k+1]=='1')
				{
					q=s1[k];
					s1[k+1]=q;
					s1[k]=s1[k+1];
				}
			}
			if(s1[i]==s2[i])	sum++;
		}
		cout<<sum<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
