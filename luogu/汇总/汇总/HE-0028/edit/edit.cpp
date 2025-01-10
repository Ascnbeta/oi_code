#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define sort stable_sort
#define endl '\n'
int pos0[3][100010],pos1[3][100010],sum[3][100010][2];
char s[3][100010],t[3][100010];
int ask(int n,int l)
{
	int ans=l,flag1=0,flag2=0;
	if(t[1][l]=='0'&&t[2][l]=='0')
	{
		for(;ans+1<=n&&t[1][ans+1]=='0'&&t[2][ans+1]=='0';ans++);
	}
	else
	{
		for(;ans+1<=n;ans++)
		{
			if(t[1][ans+1]=='0'&&t[2][ans+1]=='0')
			{
				break;
			}
			if(t[1][ans+1]=='0'&&t[2][ans+1]=='1')
			{
				flag1=1;
				if(flag2==1||(t[1][ans]=='1'&&t[2][ans]=='0'))
				{
					break;
				}
			}
			if(t[1][ans+1]=='1'&&t[2][ans+1]=='0')
			{
				flag2=1;
				if(flag1==1||(t[1][ans]=='0'&&t[2][ans]=='1'))
				{
					break;
				}
			}
			if(t[1][ans+1]=='1'&&t[2][ans+1]=='1')
			{
				if(flag1==1||flag2==1)
				{
					break;
				}
			}
		}
	}
	return ans;
}
int work(int &sum10,int &sum11,int &sum20,int &sum21,int r1,int r2)
{
	int ans=0;
	if(r1<=r2)
	{
		if(sum[1][r2][0]-sum[1][r1][0]<=sum20)
		{
			sum20-=sum[1][r2][0]-sum[1][r1][0];
			ans+=sum[1][r2][0]-sum[1][r1][0];
		}
		else
		{
			ans+=sum20;
			sum20=0;
		}
		if(sum[1][r2][1]-sum[1][r1][1]<=sum21)
		{
			sum21-=sum[1][r2][1]-sum[1][r1][1];
			ans+=sum[1][r2][1]-sum[1][r1][1];
		}
		else
		{
			ans+=sum21;
			sum21=0;
		}
	}
	else
	{
		if(sum[2][r1][0]-sum[2][r2][0]<=sum10)
		{
			sum10-=sum[2][r1][0]-sum[2][r2][0];
			ans+=sum[2][r1][0]-sum[2][r2][0];
		}
		else
		{
			ans+=sum10;
			sum10=0;
		}
		if(sum[2][r1][1]-sum[2][r2][1]<=sum11)
		{
			sum11-=sum[2][r1][1]-sum[2][r2][1];
			ans+=sum[2][r1][1]-sum[2][r2][1];
		}
		else
		{
			ans+=sum11;
			sum11=0;
		}
	}
	return ans;
}
int solve(int st,int ed)
{
	int ans=0,l1,l2,r1,r2,sum10,sum11,sum21,sum20;
	if(t[1][st]=='0'&&t[2][st]=='0')
	{
		for(int i=st;i<=ed;i++)	
		{
			ans+=(s[1][i]==s[2][i]);
		}
	}
	else
	{
		l1=(t[1][st]=='1')?st:pos1[1][st];
		r1=min(pos0[1][l1]-1,ed);
		l2=(t[2][st]=='1')?st:pos1[2][st];
		r2=min(pos0[2][l2]-1,ed);
		if(l1<=ed&&l2<=ed)
		{
			sum10=sum[1][r1][0]-sum[1][l1-1][0];
			sum11=sum[1][r1][1]-sum[1][l1-1][1];
			sum20=sum[2][r2][0]-sum[2][l2-1][0];
			sum21=sum[2][r2][1]-sum[2][l2-1][1];
			ans+=work(sum10,sum11,sum20,sum21,l1-1,l2-1);//l ->  max(l1,l2)-1
			ans+=work(sum10,sum11,sum20,sum21,r1,r2);//min(r1,r2)+1 -> r
			// cout<<ans<<endl;
			ans+=min(sum10,sum20)+min(sum11,sum21);
		}
		else
		{
			
			if(l1>ed)
			{
				l1=l2=st;
				r1=ed;
				r2=pos0[2][l2]-1;	
			}
			else
			{
				l1=l2=st;
				r1=pos0[1][l1]-1;	
				r2=ed;	
			}
			sum10=sum[1][r1][0]-sum[1][l1-1][0];
			sum11=sum[1][r1][1]-sum[1][l1-1][1];
			sum20=sum[2][r2][0]-sum[2][l2-1][0];
			sum21=sum[2][r2][1]-sum[2][l2-1][1];
			ans+=min(sum10,sum20)+min(sum11,sum21);
		}
	}
	// cout<<st<<" "<<ed<<" "<<ans<<endl;
	return ans;
}
int main()
{
    freopen("edit.in","r",stdin);
    freopen("edit.out","w",stdout);
    int testcase,n,ans=0,flag,i,j,k;
    scanf("%d",&testcase);
    for(k=1;k<=testcase;k++)
    {
		ans=0;
		scanf("%d",&n);
		scanf("%s",s[1]+1);
		scanf("%s",s[2]+1);
		scanf("%s",t[1]+1);
		scanf("%s",t[2]+1);
		for(i=1;i<=n;i++)
		{
			sum[1][i][0]=sum[1][i-1][0]+(s[1][i]=='0');
			sum[1][i][1]=sum[1][i-1][1]+(s[1][i]=='1');
		}
		for(i=1;i<=n;i++)
		{
			sum[2][i][0]=sum[2][i-1][0]+(s[2][i]=='0');
			sum[2][i][1]=sum[2][i-1][1]+(s[2][i]=='1');
		}
		pos0[1][n]=pos1[1][n]=pos0[2][n]=pos1[2][n]=n+1;
		for(i=n-1;i>=1;i--)
		{
			pos0[1][i]=(t[1][i+1]=='0')?i+1:pos0[1][i+1];
			pos0[2][i]=(t[2][i+1]=='0')?i+1:pos0[2][i+1];
			pos1[1][i]=(t[1][i+1]=='1')?i+1:pos1[1][i+1];
			pos1[2][i]=(t[2][i+1]=='1')?i+1:pos1[2][i+1];
		}
		if(sum[1][n][0]==0||sum[1][n][1]==0)
		{
			for(i=1;i<=n;i++)	
			{
				ans+=(s[1][i]==s[2][i]);
			}
		}
		else
		{
			for(i=1;i<=n;i=j+1)
			{
				j=ask(n,i);
				ans+=solve(i,j);
			}
		}
		printf("%d\n",ans);
	}
    return 0;
}
