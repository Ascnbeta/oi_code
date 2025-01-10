#include<bits/stdc++.h>
using namespace std;
#define il inline
#define ri register int
#define inf 0x3f3f3f3f
int a,b,ans,cnt1,cnt2;
char c[111111],d[111111],ci[111111],di[111111];
struct node
{
	int left,right;
	pair<int,int> num;
}n1[111111],n2[111111];
int main()
{
//	freopen("edit2.in","r",stdin);
//	freopen("myedit2.ans","w",stdout);
	freopen("edit.in","r",stdin);
	freopen("edit.out","w",stdout);
	scanf("%d",&a);
	while(a--)
	{
		scanf("%d%s%s%s%s",&b,c+1,d+1,ci+1,di+1);
		if(c==d)
		{
			printf("%d\n",b);
			continue;
		}
		ans=cnt1=cnt2=0;
		ri now=0;
		ci[b+1]='0';
		di[b+1]='0';
		for(ri i=1;i<=b;i++)
		{
			if(ci[i]=='0')
			{
				now=0;
				cnt1++;
				n1[cnt1]={i,i,{0,0}};
				if(c[i]=='0')
				{
					n1[cnt1].num.first++;
				}
				else
				{
					n1[cnt1].num.second++;
				}
			}
			else
			{
				if(!now)
				{
					cnt1++;
					now=i;
					n1[cnt1]={i,i,{0,0}};
				}
				if(c[i]=='0')
				{
					n1[cnt1].num.first++;
				}
				else
				{
					n1[cnt1].num.second++;
				}
				if(ci[i+1]=='0')
				{
					n1[cnt1].left=now;
					n1[cnt1].right=i;
				}
			}
		}
		now=0;
		for(ri i=1;i<=b;i++)
		{
			if(di[i]=='0')
			{
				now=0;
				cnt2++;
				n2[cnt2]={i,i,{0,0}};
				if(d[i]=='0')
				{
					n2[cnt2].num.first++;
				}
				else
				{
					n2[cnt2].num.second++;
				}
			}
			else
			{
				if(!now)
				{
					cnt2++;
					now=i;
					n2[cnt2]={i,i,{0,0}};
				}
				if(d[i]=='0')
				{
					n2[cnt2].num.first++;
				}
				else
				{
					n2[cnt2].num.second++;
				}
				if(di[i+1]=='0')
				{
					n2[cnt2].left=now;
					n2[cnt2].right=i;
				}
			}
		}
//		for(ri i=1;i<=cnt1;i++)
//		{
//			printf("%d %d %d %d\n",n1[i].left,n1[i].right,n1[i].num.first,n1[i].num.second);
//		}
//		for(ri i=1;i<=cnt2;i++)
//		{
//			printf("%d %d %d %d\n",n2[i].left,n2[i].right,n2[i].num.first,n2[i].num.second);
//		}
		n1[cnt1+1]={0,0,{0,0}};
		n2[cnt2+1]={0,0,{0,0}};
		cnt1=cnt2=1;
		now=1;
		while(1)
		{
			while(n1[cnt1].right>0&&n1[cnt1].right<now)
			{
				cnt1++;
			}
			if(!n1[cnt1].right)
			{
				break;
			}
			while(n2[cnt2].right>0&&n2[cnt2].right<now)
			{
				cnt2++;
			}
			if(!n2[cnt2].right)
			{
				break;
			}
			if(n1[cnt1].right<n2[cnt2].right)
			{
				ans+=min(n1[cnt1].num.first,n2[cnt2].num.first);
				ans+=min(n1[cnt1].num.second,n2[cnt2].num.second);
				if(n2[cnt2].num.first>=n1[cnt1].num.first&&n2[cnt2].num.second>=n1[cnt1].num.second)
				{
					n2[cnt2].num.first-=n1[cnt1].num.first;
					n2[cnt2].num.second-=n1[cnt1].num.second;
				}
				else if(n2[cnt2].num.first>=n1[cnt1].num.first)
				{
					n2[cnt2].num.first-=n1[cnt1].num.first;
					n2[cnt2].num.first-=n1[cnt1].num.second-n2[cnt2].num.second;
					n2[cnt2].num.second=0;
				}
				else
				{
					n2[cnt2].num.second-=n1[cnt1].num.second;
					n2[cnt2].num.second-=n1[cnt1].num.first-n2[cnt2].num.first;
					n2[cnt2].num.first=0;
				}
				now=n1[cnt1].right+1;
			}
			else
			{
				ans+=min(n1[cnt1].num.first,n2[cnt2].num.first);
				ans+=min(n1[cnt1].num.second,n2[cnt2].num.second);
				if(n1[cnt1].num.first>=n2[cnt2].num.first&&n1[cnt1].num.second>=n2[cnt2].num.second)
				{
					n1[cnt1].num.first-=n2[cnt2].num.first;
					n1[cnt1].num.second-=n2[cnt2].num.second;
				}
				else if(n1[cnt1].num.first>=n2[cnt2].num.first)
				{
					n1[cnt1].num.first-=n2[cnt2].num.first;
					n1[cnt1].num.first-=n2[cnt2].num.second-n1[cnt1].num.second;
					n1[cnt1].num.second=0;
				}
				else
				{
					n1[cnt1].num.second-=n2[cnt2].num.second;
					n1[cnt1].num.second-=n2[cnt2].num.first-n1[cnt1].num.first;
					n1[cnt1].num.first=0;
				}
				now=n2[cnt2].right+1;
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}
/*
1
6
011101
111010
111010
101101

1
10
0110111100
1111111100
1110000100
0110111011

1
9
101111111
100111000
110111011
011111111

*/

