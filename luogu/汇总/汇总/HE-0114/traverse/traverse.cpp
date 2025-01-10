#include<bits/stdc++.h>
using namespace std;
int c,T;
int n,k;
int ans;
int main(){
	freopen("traverse.in","r",stdin);
	freopen("traverse.out","w",stdout);
	cin>>c>>T;
	while(T--){
		cin>>n>>k;
		for(int i=1;i<=k;i++){
			ans=i*ans;
		}
		cout<<ans<<endl;
	}
	return 0;
}
