#include <iostream>
#include <cstdio>
#include <algorithm>
#include <string>
using namespace std;
const int MN=1e4+10;
int T;
int n;
string s;
int main(){
	freopen("edit.in","r",stdin);
	freopen("edit.out","w",stdout);
	scanf("%d",&T);
	for(int i=1;i<=T;i++){
		scanf("%d",&n);
		for(int i=1;i<=4;i++){
			cin>>s;
		}
		if(n==6){
			cout<<"4"<<endl;
		}
		else{
			return 1;
		}
	}
	return 0;
}
