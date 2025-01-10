#include <bits/stdc++.h>
using namespace std;
const int p=1e9+7;
int T;
int n,m,v;
int cnt;
map<int,int> mp;
vector<int> q;
int qks(int a,int b)
{
	int res=1;
	for(;b;b>>=1)
	{
		if(b) res=((long long)(res*a)%p+p)%p;
		a=((long long)(a*a)%p+p)%p;
	}
	return res;
}
int main(){
	freopen("assign.in","r",stdin);
	freopen("assign.out","w",stdout);
	cin>>T;
	while(T--)
	{   cnt=0;
	    q.clear();
		mp.clear();
	    bool f=1;
		cin>>n>>m>>v;
		for(int i=1;i<=m;i++)
		  { int a,b;
		  	cin>>a>>b;   
		  	if(mp[a]&&mp[a]!=b)
		  	{
		  		f=0;
			}
		  	mp[a]=b;
		  	q.push_back(a);
		  }
		if(f==0)
		{
			cout<<0<<'\n';
			continue;
		}
		if(v==1)                                                                                                     
		{
			cout<<1<<'\n';
			continue;
		}
		if(m==1)
		{  
		   int ans=((long long)(v*v)%p+p)%p;
		   cout<<qks(ans,n-1)<<'\n';
		   continue;	
		}
		if(n==m)
		{
		   int ans=((long long)((v-1)*v+1)%p+p)%p;
		   cout<<qks(ans,n-1)<<'\n';
		   continue;
		}
		for(int i=0;i+1<q.size();i++)
		{
			 int j=q[i];
			 if(q[i]==q[i+1]) cnt++;
		}
		int t1=((long long)((v-1)*v+1)%p+p)%p;
		int t2=((long long)(v*v)%p+p)%p;
	    cout<<((long long)(qks(t1,cnt)*qks(t2,n-1-cnt))%p+p)%p<<'\n';
	}
	return 0;
}
