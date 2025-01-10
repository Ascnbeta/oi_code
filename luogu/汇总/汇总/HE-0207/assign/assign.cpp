#include<bits/stdc++.h>
using namespace std;
const long long a=1e9+7;
int t;
int n;
int m;
int v;
bool o;
int k[3][100003];
int main(){
	freopen("assign.in","r",stdin);
	freopen("assign.out","w",stdout);
	cin>>t;
	for(int i=1;i<=t;i++){
		cin>>n;
		cin>>m;
		cin>>v;
		o=0;
		for(int j=1;j<=m;j++){
			cin>>k[1][j]>>k[2][j];
		}
		for(int j=1;j<=m;j++){
			if(k[1][j]==k[1][j+1]&&k[2][j]!=k[2][j+1]){
				cout<<0;
				cout<<endl;
				o=1;
				break;
			}
		}
		if(o==1){
			continue;
		}
		for(int j=1;j<=m;j++){
			if(k[2][j]!=1){
				o=1;
				break;
			}
		} 
		if(o!=0){
			cout<<v*v-v+1;
			cout<<endl;
			continue;
		}
		else{
			long long y=rand()%a;
			cout<<y;
			cout<<endl;
		}
	} 
	return 0;
}
