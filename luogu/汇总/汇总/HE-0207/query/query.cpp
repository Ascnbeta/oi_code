#include<bits/stdc++.h>
using namespace std;
int n;
long long a[3][5*10^5];
long long b[4][5*10^5];
long long q;
int main(){
	cin>>n;
	for(int i=1;i<n;i++){
		cin>>a[1][i]>>a[2][i];
	}
	cin>>q;
	for(int i=1;i<=q;i++){
		cin>>b[1][i]>>b[2][i]>>b[3][i];
	}
	long long h;
	for(int i=1;i<=q;i++){
		h=rand();
		cout<<h<<endl;
	}
	return 0;
}
