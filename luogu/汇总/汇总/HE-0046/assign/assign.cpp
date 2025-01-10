#include<bits/stdc++.h>
using namespace std;

int t,n,m,x[1100000],c[110000],d[110000];
long long v,da,mo=(1e9+7);
long long ksm(int o1,int o2)
{
	long long a=o1,da=1;
	while(o2)
	{
		if(o2%2) da*=a;
		a=a*a%mo;
		o2/=2;
	}
	return da;
}
int main()
{
	freopen("assign.in","r",stdin);
	freopen("assign.out","w",stdout);
	cin>>t;
	for(int i1=1;i1<=t;i1++)
	{
		cin>>n>>m>>v;da=0;
		bool wan=0;
		for(int i=1;i<=n;i++) x[i]=(-2e9);
		for(int i=1;i<=m;i++)
		{
			cin>>c[i]>>d[i];
			if(x[c[i]]!=-(2e9)&&x[c[i]]!=d[i]) {puts("0");wan=1;break;}
			x[c[i]]=d[i];
		}
		if(wan) continue;
		for(int i=1;i<n;i++)
		{
			if(x[i]==(-2e9)||x[i+1]==(-2e9)) da=(da+v*v)%mo;
			else da=(da+v*(v-1)+1)%mo;
		}
		cout<<ksm(2,da/2)<<'\n';
	}
	
	
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
/*

3
2 1 2
1 1
2 2 2
1 1
2 2
2 2 2
1 1
1 2




*/
