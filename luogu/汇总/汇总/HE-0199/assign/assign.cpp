#include<bits/stdc++.h>
using namespace std;
#define int long long
bool comp(int a,int b);

int T,n,sum,k;


signed main(){
	freopen("assign.in","r",stdin);
	freopen("assign.out","w",stdout);
	cin>>T;
	int a,s=635, d=151, f=484891 ,g=48941 ,h=494165 ,j ,k ;
	for(int i=0;i<T;i++){
		cout<<((s%(1000000007)*d%(1000000007)*f%(1000000007))%(1000000007)*j)%(1000000007)*
		g%(1000000007)<<endl;
		cin>>a>>s>>f>>g;
	a=a*s*d;
	s=a*s*f*g;
	d=s*d*g*f*a;
	f=a*d*f*g*f*g;
	g=d*d*d*d*d*d*d;
	}
	
	return 0;
//	fclose(stdin);
//	fclose(stdout);
}




