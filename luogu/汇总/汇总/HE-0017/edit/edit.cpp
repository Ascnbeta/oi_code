#include<cstdio>
#include<algorithm>
using namespace std;
const int N=1e5;
char s1[N+5],s2[N+5],t1[N+5],t2[N+5];
int st1[N+5][2],st2[N+5][2];
int main()
{
	freopen("edit.in","r",stdin);
	freopen("edit.out","w",stdout);
	int T;
	scanf("%d",&T);
	for(int o=1;o<=T;o++)
	{
		int n,sz1=0,sz2=0,ans=0,cnt1[2]={0,0},cnt2[2]={0,0};
		scanf("%d%s%s%s%s",&n,s1+1,s2+1,t1+1,t2+1);
		for(int i=1;i<=n;i++)
		{
			if(t1[i]=='0')
			{
				sz1++;
				st1[sz1][0]=cnt1[0];
				st1[sz1][1]=cnt1[1];
				cnt1[0]=cnt1[1]=0;
			}
			else
				cnt1[s1[i]-'0']++;
			if(t2[i]=='0')
			{
				sz2++;
				st2[sz2][0]=cnt2[0];
				st2[sz2][1]=cnt2[1];
				cnt2[0]=cnt2[1]=0;
			}
			else
				cnt2[s2[i]-'0']++;
		}
		sz1++;
		st1[sz1][0]=cnt1[0];
		st1[sz1][1]=cnt1[1];
		sz2++;
		st2[sz2][0]=cnt2[0];
		st2[sz2][1]=cnt2[1];
//		for(int i=1;i<=sz1;i++)
//		{
//			printf("%d %d\n",st1[i][0],st1[i][1]);
//		}
//		printf("\n");
//		for(int i=1;i<=sz2;i++)
//		{
//			printf("%d %d\n",st2[i][0],st2[i][1]);
//		}
		for(int i1=1,i2=1,p=0;p<=n;)
		{
			int t1=p+st1[i1][0]+st1[i1][1]+1;
			int t2=p+st2[i2][0]+st2[i2][1]+1;
			int a0=min(st1[i1][0],st2[i2][0]),a1=min(st1[i1][1],st2[i2][1]);
			ans+=a0+a1;
			st1[i1][0]-=a0;
			st1[i1][1]-=a1;
			st2[i2][0]-=a0;
			st2[i2][1]-=a1;
			if(t1>t2)
			{
				if(st1[i1][s2[t2]-'0']>0)
				{
					ans++;
					st1[i1][s2[t2]-'0']--;
				}
				else
					st1[i1][!(s2[t2]-'0')]--;
				st1[i1][0]-=st2[i2][1];
				st1[i1][1]-=st2[i2][0];
				p=t2;
				i2++;
			}
			else if(t1<t2)
			{
				if(st2[i2][s1[t1]-'0']>0)
				{
					ans++;
					st2[i2][s1[t1]-'0']--;
				}
				else
					st2[i2][!(s1[t1]-'0')]--;
				st2[i2][0]-=st1[i1][1];
				st2[i2][1]-=st1[i1][0];
				p=t1;
				i1++;
			}
			else
			{
				if(t1<=n&&s1[t1]==s2[t2])
					ans++;
				p=t1;
				i1++;
				i2++;
			}
//			printf("%d %d\n",ans,p);
		}
		printf("%d\n",ans);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
