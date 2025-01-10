#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
const int N=1e5+10;
int T, n;
string s1,s2,t1,t2;
int a[N],b[N],va[N],vb[N];
signed main()
{
	freopen("edit.in","r",stdin);
	freopen("edit.out","w",stdout);
	ios::sync_with_stdio(0);
	cin>>T;
	while(T--)
	{
		cin>>n>>s1>>s2>>t1>>t2;
		for(int i=1;i<=n;++i)
		{
			a[i]=s1[i-1]-'0',b[i]=s2[i-1]-'0';
			va[i]=t1[i-1]-'0',vb[i]=t2[i-1]-'0';
		}
		int cl[2]={0,0},cr[2]={0,0},L=0,R=0,ans=0;
		do
		{
			++L;
			cl[a[L]]++;
		}while(va[L]==1);
		while(1)
		{	
			if(L>R)
			{
				do
				{
					++R;
					++cr[b[R]];
				}while(vb[R]==1&&R<n);
			}
			else if(L<R)
			{
				do	
				{
					++L;
					++cl[a[L]];
				}while(va[L]==1&&L<n);
			}
			else
			{
				if(L==n)
					break;
				do
				{
					++R;
					++cr[b[R]];
				}while(vb[R]==1&&R<n);
				do	
				{
					++L;
					++cl[a[L]];
				}while(va[L]==1&&L<n);
			}
			if(L>R)
			{
				if(va[L]==0)
					cl[a[L]]--;
				ans+=min(cl[0],cr[0])+min(cl[1],cr[1]);
				if(cl[0]>=cr[0])
					cl[0]-=cr[0],cr[0]=0;
				else 
					cl[1]-=cr[0]-cl[0],cl[0]=cr[0]=0;
				if(cl[1]>=cr[1])
					cl[1]-=cr[1],cr[1]=0;
				else
					cl[0]-=cr[1]-cl[1],cl[1]=cr[1]=0;
				if(va[L]==0)
					cl[a[L]]++;
			}
			else if(L<R)
			{
				if(vb[R]==0)
					cr[b[R]]--;
				ans+=min(cl[0],cr[0])+min(cl[1],cr[1]);
				if(cl[0]<=cr[0])
					cr[0]-=cl[0],cl[0]=0;
				else
					cr[1]-=cl[0]-cr[0],cl[0]=cr[0]=0;
				if(cl[1]<=cr[1])	
					cr[1]-=cl[1],cl[1]=0;
				else
					cr[0]-=cl[1]-cr[1],cl[1]=cr[1]=0;
				if(vb[R]==0)
					cr[b[R]]++;
			}	
			else
			{
				int pos1=-1,pos2=-2;
				if(va[L]==0)
					cl[a[L]]--,pos1=a[L];
				if(vb[R]==0)
					cr[b[R]]--,pos2=b[R];
				ans+=min(cl[0],cr[0])+min(cl[1],cr[1]);
				if(cl[0]<=cr[0])
					cr[0]-=cl[0],cl[0]=0;
				else
					cr[1]-=cl[0]-cr[0],cl[0]=cr[0]=0;
				if(cl[1]<=cr[1])	
					cr[1]-=cl[1],cl[1]=0;
				else
					cr[0]-=cl[1]-cr[1],cl[1]=cr[1]=0;
				if(pos1<0)
					if(pos2>=0)
						if(cl[pos2])
							++ans,cl[pos2]--;
				if(pos2<0)
					if(pos1>=0)
						if(cr[pos1])
							++ans,cr[pos1]--;
				if(pos1>=0&&pos2>=0)
					ans+=pos1==pos2;
			}
		}
		cout<<ans<<endl;	
	}
	return 0;
}
