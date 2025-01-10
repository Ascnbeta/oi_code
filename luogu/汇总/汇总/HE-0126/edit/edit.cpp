#include<bits/stdc++.h>
#define int long long
using namespace std;
int t,n,cnt,ans=0;
string a,b,aa,bb;
int suma0[100005],sumb0[100005];
int suma1[100005],sumb1[100005];
bool A=1,B=0,C=1;
signed main()
{
	freopen("edit.in","r",stdin);
	freopen("edit.out","w",stdout);
	cin>>t;
	while(t--)
	{
		A=1,B=0,C=1;
		ans=0;
		for(int i=1;i<=n;i++) suma0[i]=sumb0[i]=suma1[i]=sumb1[i]=0;
		cin>>n;
		cin>>a;
		cin>>b;
		a='*'+a;
		b='*'+b;
		for(int i=1;i<n;i++) if(a[i]!=a[i+1]) A=0;
		for(int i=1;i<=n;i++) suma1[i]=suma1[i-1]+(a[i]=='1');
		for(int i=1;i<=n;i++) suma0[i]=suma0[i-1]+(a[i]=='0');
		for(int i=1;i<=n;i++) sumb0[i]=sumb0[i-1]+(b[i]=='0');
		for(int i=1;i<=n;i++) sumb1[i]=sumb1[i-1]+(b[i]=='1');
		cin>>aa;
		cin>>bb;
		aa='*'+aa;
		bb='*'+bb;
		if(aa==bb) B=1;
		int cntt=0,cnttt=0;
		for(int i=1;i<=n;i++)
		{
			if(aa[i]=='0') cntt++;
			if(cntt>1) C=0;
		}
		if(A)
		{
			for(int i=1;i<=n;i++) if(a[i]==b[i]) ans++;
			cout<<ans<<"\n";
			continue;
		}
		else if(B)
		{
			int cnt=0;
			for(int i=1;i<=n;i++)
			{
				if(aa[i]=='1'&&bb[i]=='1') cnt++;
				else
				{
					if(cnt>=2)
					{
						ans+=min(suma0[i-1]-suma0[i-cnt-1],sumb0[i-1]-sumb0[i-cnt-1]);
						ans+=min(suma1[i-1]-suma1[i-cnt-1],sumb1[i-1]-sumb1[i-cnt-1]);
					} 
					if(cnt==1) if(a[i-1]==b[i-1]) ans++;
					if(a[i]==b[i]) ans++;
					cnt=0;
				}
			}
			if(cnt>=2)
			{
				ans+=min(suma0[n]-suma0[n-cnt],sumb0[n]-sumb0[n-cnt]);
				ans+=min(suma1[n]-suma1[n-cnt],sumb1[n]-sumb1[n-cnt]);
			} 
			if(cnt==1) if(a[n-1]==b[n-1]) ans++;
			cnt=0;
			cout<<ans<<"\n";
			continue;
		}
		else
		{
			ans+=min(suma0[n]-suma0[0],sumb0[n]-sumb0[0]);
			ans+=min(suma1[n]-suma1[0],sumb1[n]-sumb1[0]);
			cout<<ans<<"\n";
			continue;
		}
	}
}//大败而归，明年再战了 
