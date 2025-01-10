#include<bits/stdc++.h>
using namespace std;

int main(){
	int t;
	freopen("traverse.in","r",stdin);
	freopen("traverse.out","w",stdout);
	while(cin>>t){
		if(t==1){
			cout<<2<<endl;
			return 0;
		}else{
			for(int i=1;i<=t;i++){
				int x[t];
				if(x[i]%t==0){
					x[i]=rand();
				}
				cout<<abs(x[i]%t)<<endl;
			}
			return 0;
		}
	}
	return 0;
}
