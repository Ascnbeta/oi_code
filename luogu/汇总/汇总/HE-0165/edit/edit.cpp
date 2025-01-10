#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
string a,b;
string ssa,ssb;
int T,n;
int main(){
	freopen("edit.in","r",stdin);
	freopen("edit.out","w",stdout);
	cin>>T;
	while(T--){
		cin>>n;
		cin>>ssa>>ssb>>a>>b;
		char p=ssa[0];
		int sum=0;	
		for(int i=0;i<n;i++){
			if(ssb[i]==p)sum++;
		}
		cout<<sum<<endl;
	} 
	return 0;
}
