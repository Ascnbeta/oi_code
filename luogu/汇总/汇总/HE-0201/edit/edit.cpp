#include<bits/stdc++.h>
using namespace std;
int a,f;
string b,c,d,e;
int main(){
	freopen("edit.in","r",stdin);
	freopen("edit.out","w",stdout);
	//next(prev)_permutation
	cin>>a;
	while(a--){
		int ko[100010]={},lo[100010]={};
		cin>>f>>b>>c>>d>>e;
		ko[f]=-10;
		lo[f]=-10;
		for(int i=0;i<f;i++){
			ko[i]=b[i]-'0';
			lo[i]=c[i]-'0';
			if(d[i]=='0'){
				ko[i]=-1;
			}
			if(e[i]=='0'){
				lo[i]=-1;
			}
		}
		
	}
	
	return 0;
}
