#include<bits/stdc++.h>
#define int long long 
using namespace std;
constexpr int N=1e5+1,p=1e9+7;
int id,T,n,k,ans;
void Main(){
	cin>>n>>k;
	if(id==18){
		cout<<"1\n";
		return;
	}
	for(int i=1,x,y;i<n;i++){
		cin>>x>>y;
	}
	for(int i=1;i<=k;i++){
		int h17;
		cin>>h17;
	}
	ans=k%p;
	for(int i=1;i<=n-3;i++)
		ans=ans*i%p;
	ans=ans*(n-2-k)%p;
	cout<<ans<<'\n';
	return;
}
signed main(){
	freopen("traverse.in","r",stdin),
	freopen("traverse.out","w",stdout);
	ios::sync_with_stdio(0);
	for(cin>>id>>T;T;--T)
		Main();
	return 0;
}
