#include<bits/stdc++.h>
using namespace std;
const long long h=1e9+7;
int a,b;
struct p{
	long long n;
	long long k;
	long long x[3][100005];
	long long y[100005];
}w[12];
int main(){
	freopen("traverse.in","r",stdin);
	freopen("traverse.out","w",stdout);
	cin>>a>>b;
	for(int i=1;i<=b;i++){
		cin>>w[i].n>>w[i].k;
		for(int j=1;j<w[i].n;j++){
			cin>>w[i].x[1][j]>>w[i].x[2][j];
		}
		for(int j=1;j<=w[i].k;j++){
			cin>>w[i].y[j];
		}
		int u=rand()%h;
		cout<<u<<endl;
	}
	return 0;
}
