#include<bits/stdc++.h>
using namespace std;
const int M=1e5+1;
int t;
int a[M],b[M],m1[M],m2[M],sa[M],sb[M];
int main()
{
	freopen("edit.in","r",stdin);
	freopen("edit.out","w",stdout);
	cin>>t;
	while(t--)
	{
		memset(a,0,sizeof(a));
		memset(b,0,sizeof(b));
		memset(m1,0,sizeof(m1));
		memset(m2,0,sizeof(m2));
		memset(sa,0,sizeof(sa));
		memset(sb,0,sizeof(sb));
		int n;cin>>n;
		string s1,s2;
		cin>>s1>>s2;
		for(int i=0;i<n;i++)
		{
			a[i+1]=s1[i]-'0';sa[i+1]=sa[i]+a[i+1];
			b[i+1]=s2[i]-'0';sb[i+1]=sb[i]+b[i+1];
			//cout<<sa[i+1]<<" ";
		}
		int k1=1;
		for(int i=2;i<=n;i++)
		{
			if(a[i]!=a[i-1])
			{
				k1=0;
			}
		}
		string t1,t2;cin>>t1>>t2;
		int cnt1=0,cnt2=0;
		int k2=1;
		for(int i=0;i<n-1;i++)
		{
			if(t1[i]!=t2[i])
			{
				k2=0;
			}
			if(t1[i]=='0')
			{
				m1[++cnt1]=i+1;
			}
			if(t2[i]=='0')
			{
				m2[++cnt2]=i+1;//cout<<m2[cnt2]<<" ";
			}
		}
		m1[++cnt1]=n;
		m2[++cnt2]=n;//cout<<m2[cnt2];
		int ans=0;
		if(k1==1)
		{
			int ansk1=max(sa[n],sb[n])-min(sa[n],sb[n]);
			cout<<n-ansk1<<endl;
		}
		else if(k2==1)
		{
			int ansk2=0;int temp=0;//cout<<cnt1<<" ";
			for(int i=1;i<=cnt1;i++)
			{
				int u=m1[i]-1;//cout<<u<<" "<<temp<<endl;
				if(u<1)
				{
					if(a[1]==b[1])
					{
						ansk2++;temp=1;//cout<<1<<" "<<ansk2<<" ";
					}
				}
				else
				{
					int tsa=sa[u]-sa[temp],tsb=sb[u]-sb[temp],tn=u-temp;
					//cout<<tsa<<" "<<tsb<<endl;
					ansk2+=(min(tsa,tsb)+min(tn-tsa,tn-tsb));
					if(a[u+1]==b[u+1])
					{
						ansk2++;
					}
					temp=u+1;
					//cout<<ansk2<<" ";
				}
			}
			cout<<ansk2<<endl;
		}
	}
	return 0;
}
