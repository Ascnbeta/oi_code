#include<bits/stdc++.h>
using namespace std;
int T,n;
const int maxn=1e5+10;
char a[maxn],b[maxn],c[maxn],d[maxn];
int l1[maxn],r1[maxn],l2[maxn],r2[maxn];
int h1[maxn],h2[maxn];
int k1[maxn],k2[maxn];

int cnt,cnt1,cnt2;
int ans;

int main()
{
	freopen("edit","r",stdin);
	freopen("edit","w",stdin);
	cin>>T;
	while(T--)
	{
		cin>>n;
		memset(k2,0,sizeof(k2));
		memset(k1,0,sizeof(k1));
		memset(l1,0,sizeof(l1));
		memset(r1,0,sizeof(r1));
		memset(l2,0,sizeof(l2));
		memset(r2,0,sizeof(r2));
		int n;
		cnt1=0;
		cin>>n;
         scanf("%s",&a);
         scanf("%s",&b);
         scanf("%s",&c);
         scanf("%s",&d);		
		for(int i=1;i<=n;i++)
		{
			cnt++;
			if(c[i]=='0') k1[cnt]=i; 
		}
		if(k1[cnt]!=n)
		cnt1=cnt+1;
		else cnt1=cnt;
		k1[cnt1]=n;
		cnt=0;
		for(int i=1;i<=n;i++)
		{
			cnt++;
			if(d[i]=='0') k2[cnt]=i;
		}
		if(k2[cnt]!=n)
		cnt1=cnt+1;
		else cnt1=cnt;
		k2[cnt1]=n;
		cnt=1;
		for(int i=1;i<=n;i++)
		{
			if(a[i]=='1') l1[cnt]++;
			if(c[i]=='0') {
			if(a[i]=='1') r1[cnt]=l1[cnt]-1;
			else r1[cnt]=l1[cnt];
			h1[cnt]=k1[cnt]-k1[(cnt-1)]-1-r1[cnt];
			cnt++;}
		}
		cnt=1;
		for(int i=1;i<=n;i++)
		{
			if(b[i]=='1') l2[cnt]++;
			if(d[i]=='0') {
				if(b[i]=='1') r2[cnt]=l2[cnt]-1;
				else r2[cnt]=l2[cnt];
				h2[cnt]=k2[cnt]-k2[(cnt-1)]-1-r2[cnt];
				cnt++;
             }
		}
		int j=1;
        for(int i=1;i<=cnt1;i++)
        {
           if(k1[i]>=k2[j])
		   { 
		      if(r1[cnt]>l2[cnt]){
			   ans+=l2[cnt];
			   r1[cnt]-=l2[cnt];}
			else r1[cnt]=0;
			if(h1[cnt]>(k2[cnt]-k2[(cnt-1)]-1-l2[cnt]))
				ans+=k2[cnt]-k2[(cnt-1)]-1-l2[cnt];
			else h1[cnt]=0;
		   }	
		   else j++;
		}
	   cout<<ans<<endl;
   }
   return 0;
}
