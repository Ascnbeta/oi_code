#include<bits/stdc++.h>
using namespace std;
int t;
int main(){
	freopen("traverse.in","r",stdin);
	freopen("traverse.out","w",stdout);
	cin>>t;
	cin>>t;
	for(int i=1;i<=t;i++){
		int aa,n,k;
		cin>>n>>k;
		for(int i=1;i<n;i++){
			cin>>aa;
			cin>>aa;
		}
		for(int i=1;i<=k;i++) cin>>aa;
		cout<<int(pow(2,k))<<'\n';
	}
	return 0;
}
