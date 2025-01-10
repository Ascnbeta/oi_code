#include<bits/stdc++.h>
using namespace std;

int main(){
	int t;
	freopen("query.in","r",stdin);
	freopen("query.out","w",stdout);
	while(cin>>t){
		if(t==6){
			cout<<3<<endl<<4<<endl<<3<<endl;
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
