#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=5e5+10,p=1e9+7;
int t,n,k;
int qum(int a,int b){
	int ans=1;
	while(b){
		(b&1)&&(ans=ans*a%p);
		a=a*a%p;b>>=1;
	}return ans;
}
signed main(){
	freopen("traverse.in","r",stdin);
	freopen("traverse.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>t;
	while(t--){
		cin>>n>>k;
		for(int i=1,x,y;i<n;i++)cin>>x>>y;
		for(int i=1,z;i<=k;i++)cin>>z;
		cout<<qum(k,n)<<'\n';
	}
}
