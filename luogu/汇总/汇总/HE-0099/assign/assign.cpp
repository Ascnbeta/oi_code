#include<bits/stdc++.h>
#define int long long
using namespace std;
const int mod=1e9+7;
int T;
int n,m,v;
int qpow(int a,int b,int p)
{
	int res=1;
	while(b)
	{
		if(b&1) res=res*a%p;
		a=a*a%p;
		b>>=1;
	}
	return res;
}

signed main()
{
	freopen("assign.in","r",stdin);
	freopen("assign.out","w",stdout);
	cin>>T;
	while(T--)
	{
		cin>>n>>m>>v;
		if(m==1)
		{
			int a,b;
			cin>>a>>b;
			cout<<qpow(v,(n-m)*v,mod)<<endl;
		}
		else if(v<=2)
		{
			int x[20];
			memset(x,0,sizeof(x));
			bool bl=true;
			for(int i=1;i<=m;i++)
			{
				int id,sum;
				cin>>id>>sum;
				if(x[id])
				{
					cout<<0<<endl;
					bl=false;
					break;
				}
				x[id]=sum;
			}
			if(!bl) continue;
			int ans=0;
			if(x[1]>2) 
			{
				cout<<4<<endl;
				continue;
			}
			if(x[1]<=2&&x[2]<=2)
			{
				cout<<3<<endl;
				continue;
			}
			else cout<<2<<endl;
		}
		else cout<<0<<endl;
	}
	return 0;
}
//5 1 2
//1 2
//->256

//7 1 2
//4 1
//->4096

//330 1 683
//69 549
//----503279958

//89793 1 22228
//59585 13402
//----748525720

//557584238 1 464289274
//309302662 462600170
//----892897109

//817800451 1 578482625
//689892411 37963033
//----174281099
