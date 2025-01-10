#include<bits/stdc++.h>
using namespace std;
char s[100005],t[100005],s1[100005],t1[100005];
int bls[100005],blt[100005],szs0[100005],szs1[100005],szt0[100005],szt1[100005];
int n;
int main()
{
	freopen("edit.in","r",stdin);
	freopen("edit.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	int T;
	cin>>T;
	while(T--)
	{
		cin>>n;
		for(int i=1;i<=n+1;i++) szs0[i]=szs1[i]=szt0[i]=szt1[i]=bls[i]=blt[i]=0;
		int cnts=1,cntt=1;
		cin>>(s+1)>>(t+1)>>(s1+1)>>(t1+1);
		int sum=0;
		s1[0]='0',t1[0]='0';
		for(int i=1;i<=n;i++)
		{
			if(s1[i]=='0') cnts++;
			else bls[i]=cnts;
			if(t1[i]=='0') cntt++;
			else blt[i]=cntt;
			if(s1[i]=='1')
			{
				if(s[i]=='0') szs0[bls[i]]++;
				else szs1[bls[i]]++;
			}
			if(t1[i]=='1')
			{
				if(t[i]=='0') szt0[blt[i]]++;
				else szt1[blt[i]]++;
			}
		}
//		if(T==3)
//		{
//			cout<<cnts<<' '<<cntt<<endl;
//			cout<<lsts<<' '<<lstt<<endl;
//			cout<<s[lsts]<<' '<<t[lstt]<<endl;
//			cout<<szs0[1]<<' '<<szs1[1]<<endl;
//			cout<<szs0[2]<<' '<<szs1[2]<<endl;
//			cout<<szt0[1]<<' '<<szt1[1]<<endl;
//			cout<<szt0[2]<<' '<<szt1[2]<<endl;
//		}
//		for(int i=1;i<=n;i++)
//			cout<<bls[i];
//		cout<<endl;
//		for(int i=1;i<=n;i++)
//			cout<<blt[i];
//		cout<<endl;
		int lst=0;
		s1[n+1]=t1[n+1]='0';
		for(int i=1;i<=n;i++)
		{
			if(s1[i]=='0'&&t1[i]=='0')
			{
				sum+=s[i]==t[i];
				lst=i;
			}
			else if(s1[i]=='0')
			{
				if(s[i]=='0'&&szt0[blt[i]])
					sum++,szt0[blt[i]]--;
				else if(s[i]=='1'&&szt1[blt[i]])
					sum++,szt1[blt[i]]--;
				lst=i;
			}
			else if(t1[i]=='0')
			{
				if(t[i]=='0'&&szs0[bls[i]])
					sum++,szs0[bls[i]]--;
				else if(t[i]=='1'&&szs1[bls[i]])
					sum++,szs1[bls[i]]--;
				lst=i;
			}
			else if(s1[i+1]=='0'&&t1[i+1]=='0')
			{
				int v1=min(szs0[bls[i]],szt0[blt[i]]),v2=min(szs1[bls[i]],szt1[blt[i]]);
				v1=min(v1,i-lst),v2=min(v2,i-lst);
				sum+=v1+v2;
				szs0[bls[i]]=szs1[bls[i]]=szt0[blt[i]]=szt1[blt[i]]=0;
			}
			else if(s1[i+1]=='0')
			{
				int v1=min(szs0[bls[i]],szt0[blt[i]]),v2=min(szs1[bls[i]],szt1[blt[i]]);
				v1=min(v1,i-lst),v2=min(v2,i-lst);
				sum+=v1+v2;
				szs0[bls[i]]=szs1[bls[i]]=0;
				szt0[blt[i]]-=v1,szt1[blt[i]]-=v2;
			}
			else if(t1[i+1]=='0')
			{
				int v1=min(szs0[bls[i]],szt0[blt[i]]),v2=min(szs1[bls[i]],szt1[blt[i]]);
				v1=min(v1,i-lst),v2=min(v2,i-lst);
				sum+=v1+v2;
				szt0[blt[i]]=szt1[blt[i]]=0;
				szs0[bls[i]]-=v1,szs1[bls[i]]-=v2;
			}
		}
		cout<<sum<<endl;
		
	}
}
