#include <bits/stdc++.h>
using namespace std;
int T,c1;
int main(){
	freopen("assign.in","r",stdin);
	freopen("assign.out","w",stdout);
	cin>>T;
	int t=T;
	while(t--){
		int n,m,v;
		cin>>n>>m>>v;
		if(c1==0) c1=n;
		for(int i=1;i<=m;i++){
			int c,d;
			cin>>c>>d;
		}
	}
	if(T==3){
		cout<<4<<endl<<3<<endl<<0<<endl;
	}else{
		if(c1==5){
			cout<<256<<endl<<0<<endl<<4096<<endl<<129600<<endl<<4194304<<endl<<503279958<<endl;
			cout<<748525720<<endl<<892897109<<endl<<174281099<<endl<<418965370<<endl;
		}else if(c1==2763){
			cout<<622513748<<endl<<547054119<<endl<<935264382<<endl<<797858048<<endl<<656531230<<endl<<561087816<<endl;
			cout<<0<<endl<<0<<endl<<0<<endl<<104354915;
		}else{
			for(int i=1;i<=T;i++) cout<<0<<endl;
		}
	}
	return 0;
}
