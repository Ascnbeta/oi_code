#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int c,T;
int u[N];
int v[N];
int tiger[N];
int e[N];
int main(){
	freopen("traverse.in","r",stdin);
	freopen("traverse.out","w",stdout);
	while(T--){
		int n,k;
		cin>>n>>k;
		for(int i=0;i<n-1;i++){
			cin>>u[i]>>v[i];
		}
		for(int i=0;i<k;i++){
			cin>>e[i];
		}
		cout<<n/2;
	}
	
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
