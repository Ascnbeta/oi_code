#include<bits/stdc++.h>
using namespace std;
const int N = 1e5+5;
int T,n;
char s1[N],s2[N],c1[N],c2[N];
int cnt1[2],cnt2[2];


int main()
{
	freopen("edit.in","r",stdin);
	freopen("edit.out","w",stdout);
	scanf("%d",&T);
	while(T--)
	{
		memset(cnt1,0,sizeof(cnt1));
		memset(cnt2,0,sizeof(cnt2));
		int ans=0;
		scanf("%d",&n);
		scanf("%s%s%s%s",s1+1,s2+1,c1+1,c2+1);
		for(int i=1,j=1,l=1;(i<=n||j<=n)&&l<=n;)
		{
			while(c1[i]=='1') cnt1[s1[i]-'0']++,i++;
			while(c2[j]=='1') cnt2[s2[j]-'0']++,j++;
			if(i==j)
			{
				ans+=min(cnt1[1],cnt2[1])+min(cnt1[0],cnt2[0])+(s1[i]==s2[j]&&i!=n+1);
				cnt1[1]=cnt1[0]=cnt2[1]=cnt2[0]=0;
				i++; j++; l=i;
			}
			else if(i>j)
			{
				cnt2[s2[j]-'0']++;
				int t1=min(cnt1[1],cnt2[1]),t0=min(cnt1[0],cnt2[0]);
				ans+=t1+t0; cnt1[0]-=t0; cnt1[1]-=t1; cnt2[0]-=t0; cnt2[1]-=t1;
				if(cnt2[0]) cnt1[1]-=cnt2[0],cnt2[0]=0;
				if(cnt2[1]) cnt1[0]-=cnt2[1],cnt2[1]=0;
				j++; l=j;
			}
			else if(j>i)
			{
				cnt1[s1[i]-'0']++;
				int t1=min(cnt1[1],cnt2[1]),t0=min(cnt1[0],cnt2[0]);
				ans+=t1+t0; cnt2[0]-=t0; cnt2[1]-=t1; cnt1[0]-=t0; cnt1[1]-=t1;
				if(cnt1[0]) cnt2[1]-=cnt1[0],cnt1[0]=0;
				if(cnt1[1]) cnt2[0]-=cnt1[1],cnt1[1]=0;
				i++; l=i;
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}