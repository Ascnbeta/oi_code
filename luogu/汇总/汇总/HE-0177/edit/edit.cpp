#include<iostream>
#include<vector>
using namespace std;
vector<int> g1,g2;
int main(){
	freopen("edit.in","r",stdin);
	freopen("sdit.out","w",stdout);
	int at,bt,a[2],b[2],ans=0,s1[100001],s2[100001],t1[100001],t2[100001],a1=0,a0=0,b1=0,b0=0;
	int T,n;
	string sa,sb;
	cin>>T;
	for(int o=1;o<=T;o++)
	{
        n=0;
		cin>>n;
		t1[n+1]=1;
		t1[0]=1;
		t2[n+1]=1;
		t2[0]=1;
			cin>>sa;
			cin>>sb;
		for(int i=0;i<n;i++) s1[i+1]=sa[i]-'0';
		for(int i=0;i<n;i++) s2[i+1]=sb[i]-'0';
		cin>>sa;
		cin>>sb;
		for(int i=1;i<=n;i++)
		{
			t1[i]=sa[i-1]-'0';
		}
		for(int i=1;i<=n;i++)
		{
			t2[i]=sb[i-1]-'0';
			if(t2[i]!=1&&t1[i+1]!=1)
			{
				g2.push_back(i);
			}
			if(t1[i-1]!=1&&t2[i]!=1)
			{
				g1.push_back(i-1);
			}
		}
		for(int i=1;i<=n;i++)
		{
			if(t1[i-1]==0)
			{
				int p=s1[i-1];
				if(p==0&&a0>0/*||p==0&&t1[i]==0*/)
				{
					int j=i;
					while(t2[j]!=0)
					{
						if(p==s2[j])
						{
							ans++;
							b0--;
							break;
						}
						j++;
					}
				}
				if(p==1&&a1>0/*||p==0&&t1[i]==0*/)
				{
					int j=i;
					while(t2[j]!=0)
					{
						if(p==s2[j])
						{
							ans++;
							b1--;
							break;
						}
						j++;
					}
				}
				a1=0;
				a0=0;
			}
			if(t2[i-1]==0)
			{
				int p=s2[i-1];
				if(p==0&&b0>0/*||p==0&&t2[i]==0*/)
				{
					int j=i;
					while(t1[j]!=0)
					{
						if(p==s1[j])
						{
							ans++;
							a0--;
							break;
						}
						j++;
					}
				}
				if(p==1&&b1>0/*||p==0&&t2[i]==0*/)
				{
					int j=i;
					while(t1[j]!=0)
					{
						if(p==s1[j])
						{
							ans++;
							a1--;
							break;
						}
						j++;
					}
				}
				b1=0;
				b0=0;
			}
			if(s1[i]==1) {
				a1++;
				if(a1>0&&b1>0)
				{
					if(t1[i-1]==0&&t2[i]==0) break;
					a1--;
					b1--;
					ans++;
				}
			}
			
			if(s1[i]==0) {
			    a0++;
			    if(a0>0&&b0>0)
			    {
			    	if(t1[i-1]==0&&t2[i]==0) break;
				    a0--;
			    	b0--;
			    	ans++;
				}
			    
			}
			if(s2[i]==1) {
			    b1++;
			    if(a1>0&&b1>0)
				{
					if(t2[i-1]==0&&t1[i]==0) break;
					a1--;
					b1--;
					ans++;
				}
			}
			if(s2[i]==0) {
			    b0++;
			    if(a0>0&&b0>0)
			    {
			    	if(t2[i-1]==0&&t1[i]==0) break;
				    a0--;
			    	b0--;
			    	ans++;
				}
			}
			
		}
		
		cout<<ans;
	}
/*
6
0 1 1 1 0 1
1 1 1 0 1 0
1 1 1 0 1 0
1 0 1 1 0 1
*/ 
    return 0;
}
