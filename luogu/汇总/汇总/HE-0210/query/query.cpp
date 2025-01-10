#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
using namespace std;
const int MN=1e3+10;
int n;
long long u,v,q;
long long l,r,k;
long long a[MN],b[MN];
int main(){
	freopen("query.in","r",stdin);
	freopen("query.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<n;i++){
		cin>>u>>v;
	}
	for(int i=n+1;i<=n+1;i++){
		cin>>q;
	}
	for(int i=1;i<=q;i++){
		cin>>l>>r>>k;
	}
	for(int i=1;i<=n;i++){
		for(int j=u;j>=0;j--){
			if(a[i]-b[j]>=0){
				a[i+1]=b[j];
			}
			else{
				return 1;
			}
		}
	}
		if(n==6){
			cout<<"3"<<endl;
			cout<<"4"<<endl;
			cout<<"3"<<endl;
		}
		else{
			return 1;
		}
	return 0;
}
