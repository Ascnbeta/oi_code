#include<bits/stdc++.h>
using namespace std;
int n;
int t;
int ans;
char s;
bool p;
int cs,ds,ck,dk;
char a[100003],b[100003];
char c[100003],d[100003];
int main(){
	freopen("edit.in","r",stdin);
	freopen("edit.out","w",stdout);
	cin>>t;
	for(int i=1;i<=t;i++){
		cin>>n;
		ans=0;
		cs=0;
		ds=0;
		for(int j=1;j<=n;j++){
			cin>>a[j];
			if(j==1)s=a[j];
			else{
				if(a[j]!=s)p=1;
				else continue;
			}
		}
		for(int j=1;j<=n;j++){
			cin>>b[j];
			if(p!=1&&b[j]==s){
				ans++;
			}
		} 
		for(int j=1;j<=n;j++){
			cin>>c[j];
			
		}
		for(int j=1;j<=n;j++){
			cin>>d[j];
			
		}
		if(ans!=0){
			cout<<ans<<endl;
			continue;
		}
		for(int j=1;j<=n;j++){
			if(a[j]!=b[j]&&c[j]=='1'&&j!=n&&c[j+1]=='1'){
				swap(a[j],a[j+1]);
			}
			else if(a[j]==b[j]){
				continue;
			}
			else{
				if(d[j]=='1'&&j!=n&&d[j+1]=='1'){
					swap(b[j],b[j+1]);
				}
			}
		}
		for(int j=1;j<=n;j++){
			if(a[j]==b[j]){
				ans++;
			}
		}
		cout<<ans<<endl;
	}
	
	return  0;
} 
