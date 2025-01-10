#include <bits/stdc++.h>
using namespace std;
int T,n;
int main(){
	freopen("edit.in","r",stdin);
	freopen("edit.out","w",stdout);
	cin>>T;
	while(T--){
		cin>>n;
		int ans=0;
		string s1,s2,t1,t2;
		cin>>s1>>s2>>t1>>t2;
		for(int i=0;i<n;i++){
			if(i==n-1){
				if(s1[i]==s2[i]){
					ans++;
				}
				break;
			}
			
			if(s1[i]==s2[i]){
				ans++;
			}else{
				if(s1[i+1]==s2[i]&&t1[i]=='1'&&t1[i+1]=='1'){
					swap(s1[i],s1[i+1]);
					ans++;
					continue;
				}
				if(s1[i]==s2[i+1]&&t2[i]=='1'&&t2[i+1]=='1'){
					swap(s2[i],s2[i+1]);
					ans++;
					continue;
				}
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
