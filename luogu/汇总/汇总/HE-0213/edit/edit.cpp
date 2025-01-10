#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,T;
char ch1[100005];
char ch2[100005];
char b1[100005];
char b2[100005];
int ans;
signed main(){
	freopen("edit.in","r",stdin);
	freopen("edit.out","w",stdout);
	ios::sync_with_stdio(false);
	cin>>T;
	while(T--){
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>ch1[i];
		}
		for(int i=1;i<=n;i++){
			cin>>ch2[i];
		}
		for(int i=1;i<=n;i++){
			cin>>b1[i];
		}
		for(int i=1;i<=n;i++){
			cin>>b2[i];
 	}
	 	for(int i=1;i<=n;i++){
			  if(ch1[i]==ch2[i+1]&&b1[i]=='1'&&b2[i+1]=='1'){
			 	swap(ch1[i],ch1[i+1]);
			 	continue;
			 }
			else if(ch2[i]==ch1[i+1]&&b2[i]=='1'&&b1[i+1]=='1'){
				swap(ch2[i],ch2[i+1]);
				continue;
			}			
			 else{
			 	continue;
			 }
		 }
		 for(int i=1;i<=n;i++){
		 	if(ch1[i]==ch2[i]){
		 		ans++;
			 }
		 }
		 cout<<ans<<endl;
		 ans=0; 
 }
 return 0;
}
