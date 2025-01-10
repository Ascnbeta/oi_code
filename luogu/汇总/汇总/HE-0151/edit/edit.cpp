#include<bits/stdc++.h>
using namespace std;

int T;
int n;

int main(){
	freopen("edit.in","r",stdin);
	freopen("edit.out","w",stdout);

	cin>>T;
	while(T--){
		string s1,s2;
		string t1,t2;
		char a,b;
		int ans=0;
		cin>>n;
		cin>>s1;
		cin>>s2;
		cin>>t1;
		cin>>t2;
		
		for(int i=0;i<n;i++){
			if(t1[i]=='1' && t1[i+1]=='1' && s1[i]!=s2[i]){
					a=s1[i];
					s1[i]=s1[i+1];
					s1[i+1]=a;
			}
		}
		for(int i=0;i<n;i++){
			if(t2[i]=='1' && t2[i+1]=='1' && s2[i]!=s1[i]){
					b=s2[i];
					s2[i]=s2[i+1];
					s2[i+1]=b;
			}
		}
		    
		for(int i=0;i<n;i++){
			if(s1[i]==s2[i])	ans++;
		}
		cout<<ans<<endl;
		ans=0;
	}
	return 0;
}
