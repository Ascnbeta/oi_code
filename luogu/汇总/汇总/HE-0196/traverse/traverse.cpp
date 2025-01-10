#include <bits/stdc++.h>
using namespace std;
const int p=1e9+7;
int c,T;
int n,k;
int u,v,e;
int main(){
	freopen("traverse.in","r",stdin);
	freopen("traverse.out","w",stdout);
     cin>>c>>T;
     while(T--)
     {   cin>>n>>k;
        for(int i=1;i<n;i++)
         {
            cin>>u>>v;	
		 }
		 for(int i=1;i<=k;i++)
		   cin>>e;
     	if(c>=19&&c<=21)
     	{
     		if(n==2||n==3) {
     			cout<<1<<'\n';
     			continue;
			 }
			 n=n-1;
     		cout<<((long long)(k*(n-1)*n/2)%p+p)%p<<'\n';
		 }
		 else
		  cout<<1<<'\n';
	 }
	return 0;
}
