#include<iostream>
#include<cstring>
#include<cstdio>
#include<cmath>
using namespace std;
int arr[100500];
int main(){
	freopen("assign.in","r",stdin);
	freopen("assign.out","w",stdout);
	cin.tie(0),cout.tie(0); 
	int t;
	cin>>t;
	for(int u=0;u<t;u++){
		int n,m,v;
		cin>>n>>m>>v;
		memset(arr,-1,sizeof(arr));
		bool if_=false;
		for(int i=0;i<m;i++){
			int x,y;
			cin>>x>>y;
			if(arr[x]!=-1&&arr[x]!=y){
				if_=true;
			}
			arr[x]=y;
		}
		if(m==1){
			long long ans=pow(v,2*n-2);
			cout<<ans%1000000007<<endl;
			continue;
		}
		if(if_==true){
			cout<<0<<endl;
			continue;
		}
		long long sum=1;
		for(int i=1;i<n;i++){
			if(arr[i]!=-1&&arr[i+1]!=-1){
				sum*=(v*v-v+1);
			}else{
				sum*=(v*v);
			}
		}
		cout<<sum%1000000007<<endl;
	}
}
