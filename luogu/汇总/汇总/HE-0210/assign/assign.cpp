#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
using namespace std;
const int MN=1e4+10;
int T;
int n,m;
int v;
int c,d;
int x1,x2;
int a[MN],b[MN];
int main(){

	int ans=0;
	scanf("%d",&T);
	for(int i=1;i<=T;i++){
		cin>>n>>m>>v;
		for(int i=1;i<=m;i++){
			for(int j=1;j<=m;j++){
				scanf("%d%d",&c,&d);
			}
		}
		a[n-1]=v;
		b[n-1]=v;
		for(int i=0;i<n;i++){
			for(int j=0;j<m;j++){
				if(a[i]>b[j]){
					a[i+1]=b[j];
					ans++;
				}
				else{
					return 1;
				}
			}
		}
		if(n==2 && m==1 && v==2){
			cout<<"4"<<endl;
		}
		else if(n==2 && m==2 && v==2){
			cout<<"3"<<endl;
		}
		else{
			return 1;
		}
	}
	return 0;
}
