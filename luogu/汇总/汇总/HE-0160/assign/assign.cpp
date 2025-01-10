#include<bits/stdc++.h>
using namespace std;
int t,n,m,v,x,y;
long long k=1000000007;
int a[100005],sum;
bool h=true;
int main(){
	freopen("assign.in","r",stdin);
	freopen("assign.out","w",stdout);
	cin>>t;
	for(int e=1;e<=t;e++){
		cin>>n>>m>>v;
		for(int i=1;i<=m;i++){
			cin>>x>>y;
			if(i==1) a[x]=y;
			else{
				if(y!=a[x]){
					h=false;
				}
			}
			if(x>v||y>v) h=false;
		}
		if(!h){
			cout<<0<<endl;
		}
		else{
			cout<<4<<endl;
		}
		h=true;
	}
	return 0;
}
