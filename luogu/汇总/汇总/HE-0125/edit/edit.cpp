#include<iostream>
#include<algorithm>
#include<string>
#define ll long long
using namespace std;
int const N=100010;
string s1,s2,t1,t2;
int t,n;
ll bl()
{
	
}
long long ts1_allsame(string sx1,string sx2)
{
	ll ans=0;
	for(int i=0;i<n;i++)
	{
		if(sx2[i]==sx1[i]) ans++;
	}
	return ans;
}
ll ts2_t1equt2()
{
	int sameps[N],hmany=0;
	ll ans=0;
	int cszlen=0,s1otot=0,s1ztot=0,s2otot=0,s2ztot=0;
	for(int i=0;i<n;i++)
	{
		if(t1[i]=='0')
		{
			if(s1[i]==s2[i]) ans++;
			sameps[hmany]=i;
			hmany++;
			int anst1=min(s1ztot,s2ztot),anst2=min(s2otot,s1otot);
			ans+=anst1;
			ans+=anst2;
			s1otot=0;
			s1ztot=0;
			s2otot=0;
			s2ztot=0;
			continue;
		}
		if(s1[i]=='1') s1otot++;
		else s1ztot++;
		if(s2[i]=='1') s2otot++;
		else s2ztot++;
	}
	int anst1=min(s1ztot,s2ztot),anst2=min(s2otot,s1otot);
	ans+=anst1;
	ans+=anst2;
	return ans;
}
ll ts3_only1zero()
{
	
}
ll tsxzmgr()
{
	if(n<=10)
	{
		return bl();
	}
	
	char x=s1[0],y=s2[0];
	bool alls1=true,alls2=true;
	for(int i=0;i<n;i++)
	{
		if(s1[i]!=x) alls1=false;
		if(s2[i]!=y) alls2=false;
		if(!alls1&&!alls2) break;
	}
	if(alls1)
	{return ts1_allsame(s1,s2);}
	else if(alls2)
	{return ts1_allsame(s2,s1);}
	
	if(t1==t2)
	{
		return ts2_t1equt2();
	}
	
	int z0int1=0,z0int2=0;
	for(int i=0;i<n;i++)
	{
		if(t1[i]=='0') z0int1++;
		if(t2[i]=='0') z0int2++;
	}
	if(z0int1==z0int2&&z0int1==1)
	{
		return ts3_only1zero();
	}
}
int main()
{
	freopen("edit.in","r",stdin);
	freopen("edit.out","w",stdout);
	cin>>t;
	for(int j=0;j<t;j++)
	{
		cin>>n;
		cin>>s1>>s2>>t1>>t2;
		cout<<tsxzmgr()<<endl;
	}
	return 0;
}
