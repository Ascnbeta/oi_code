#include<bits/stdc++.h>
using namespace std;
int a[100005],aa[100005],b[100005],bb[100005],z[100005],zz[100005],q[100005],qq[100005];
int main(){
	freopen("edit.in","r",stdin);
	freopen("edit.out","w",stdout);
	int T;
	cin>>T;
	while(T--)
	{
		int n,m1=0,m2=0,ans=0;
		cin>>n;
		for(int i=0;i<n;i++)
		{
			a[i]=0,aa[i]=0,b[i]=0,bb[i]=0,z[i]=0,zz[i]=0;
		}
		string s,ss,t,tt;
		cin>>s>>ss>>t>>tt;
		if(t[0]=='0') m1++,z[0]=0;
		if(tt[0]=='0') m2++,zz[0]=0;
		if(s[0]=='0') a[0]++,aa[0]=0;
		else aa[0]++,a[0]=0;
		if(ss[0]=='0') b[0]++,bb[0]=0;
		else bb[0]++,b[0]=0; 
		if(t[1]=='0') t[0]='0';
		if(tt[1]=='0') tt[0]='0';
		
		
		for(int i=1;i<n-1;i++)
		{
			if(t[i]=='0') z[m1]=i,m1++;
			if(tt[i]=='0') zz[m2]=i,m2++;
			a[i]=a[i-1];
			aa[i]=aa[i-1];
			b[i]=b[i-1];
			bb[i]=bb[i-1];
			if(s[i]=='0') a[i]++,aa[i]=aa[i-1];
			else aa[i]++,a[i]=a[i-1];
			if(ss[i]=='0') b[i]++,bb[i]=bb[i-1];
			else bb[i]++,b[i]=b[i-1];
			if(t[i-1]=='0'&&t[i+1]=='0') t[i]='0';
			if(tt[i-1]=='0'&&tt[i+1]=='0') tt[i]='0';
			
		}
		if(t[n-1]=='0') z[m1]=n-1,m1++;
		if(tt[n-1]=='0') zz[m2]=n-1,m2++;
		if(s[n-1]=='0') a[n-1]=a[n-2]+1,aa[n-1]=aa[n-2];
		else aa[n-1]=aa[n-2]+1,a[n-1]=a[n-2];
		if(ss[n-1]=='0') b[n-1]=b[n-2]+1,bb[n-1]=bb[n-2];
		else bb[n-1]=bb[n-2]+1,b[n-1]=b[n-2];
		if(t[n-2]=='0') t[n-1]='0';
		if(tt[n-2]=='0') tt[n-1]='0';
		if(a[n-1]==n)
		{
			cout<<b[n-1]<<endl;
			continue;
		}
		if(aa[n-1]==n)
		{
			cout<<bb[n-1]<<endl;
			continue;
		}
		if(t==tt)
		{
			int x=0,y=0,xx=0,yy=0;
			for(int i=0;i<n;i++)
			{
				if(t[i]=='0')
				{
					ans+=max(min(a[i-1]-x,b[i-1]-y),0);
					ans+=max(min(aa[i-1]-xx,bb[i-1]-yy),0);
					if(s[i]==ss[i]) ans++;
					x=a[i],y=b[i];
					xx=aa[i],yy=bb[i];
				}
			}
			ans+=max(min(a[n-1]-x,b[n-1]-y),0);
			ans+=max(min(aa[n-1]-xx,bb[n-1]-yy),0);
			cout<<ans<<endl;
			continue;
		}
		if((m1==1&&m2==1)||m1==0||m2==0)
		{
			int zzz=0;
			for(int i=0;i<n;i++)
			{
				if(t[i]=='0'&&zzz)
				{
					ans+=min(a[i],b[i]);
					ans+=min(aa[i],bb[i]);
					ans+=min(a[n-1]-a[i],b[n-1]-b[i]);
					ans+=min(aa[n-1]-aa[i],bb[n-1]-bb[i]);
					break;
				}
				if(tt[i]=='0'&&zzz)
				{
					ans+=min(a[i-1],b[i-1]);
					ans+=min(aa[i-1],bb[i-1]);
					ans+=min(a[n-1]-a[i-1],b[n-1]-b[i-1]);
					ans+=min(aa[n-1]-aa[i-1],bb[n-1]-bb[i-1]);
					break;
				}
				if(t[i]=='0'||tt[i]=='0')
				{
					zzz++;
				}
			}
			cout<<ans<<endl;
			continue;
		}
		ans=0;
		int l=0,r=0;
		for(int i=0;i<n;i++)
		{
			if(t[i]=='0'&&tt[i]=='0')
			{
				if(i!=0) r=i-1;
				if(l!=r)
				{
					int aaa=0,bbb=0,aaaa=0,bbbb=0; 
					if(l==0) aaa=0;
					else aaa=a[l];
					if(l==0) bbb=0;
					else bbb=b[l];
					if(l==0) aaaa=0;
					else aaaa=aa[l];
					if(l==0) bbbb=0;
					else bbbb=bb[l];
					ans+=min(a[r]-aaa,b[r]-bbb);
					ans+=min(aa[r]-aaaa,bb[r]-bbbb);
				}
				l=i;
				r=i;
				if(s[i]==ss[i]) ans++;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
