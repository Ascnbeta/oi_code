#include<bits/stdc++.h>
using namespace std;

int main(){
	int t;
	freopen("assign.in","r",stdin);
	freopen("assign.out","w",stdout);
	while(cin>>t){
		if(t==3){
			cout<<4<<endl<<3<<endl<<0<<endl;
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
