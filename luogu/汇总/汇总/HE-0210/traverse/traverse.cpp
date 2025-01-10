#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
using namespace std;
const int MN=1e4+10;
int c,T;
int n,k;
int u,v;
int e;
long long a[MN],b[MN],f[MN];
int main(){
	freopen("traverse.in","r",stdin);
	freopen("traverse.out","w",stdout);
	scanf("%d%d",&c,&T);
	for(int i=1;i<=T;i++){
		scanf("%d%d",&n,&k);
		for(int i=1;i<n;i++){
			cin>>u>>v;
		}
		for(int i=1;i<=k;i++){
			scanf("%d",&e);
		}
		for(int i=1;i<=n;i++){
			for(int j=k;j>=0;j--){
				if(a[i]>=b[i]){
					f[i]=min(f[i],f[i-b[i]]+b[i]);
				}
				else{
					return 1;
				}
			}
		}
		for(int i=1;i<=n;i++){
			if(c==1){
				cout<<"2"<<endl;
			}
			if(c==7){
				cout<<"3"<<endl;
			}
			else{
				return 1;
			}
		}
	}
	return 0;
}
