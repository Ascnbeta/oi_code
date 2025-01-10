#include<bits/stdc++.h>
using namespace std;

int main(){
	freopen("edit.in","r",stdin);
	freopen("edit.out","w",stdout);
	int T;
	cin>>T;
	while(T--){
		int n;
		cin>>n;
		string s1,s2,t1,t2;
		cin>>s1>>s2>>t1>>t2;
		bool fA=true;
		char c=s1[0];
		for(int i=0;i<n;i++){
			if(s1[i]!=c){
				fA=false;
				break;
			}
		}
		bool fB=true;
		if(t1!=t2){
			fB=false;
		}
		bool fC=true;
		int t10=0,t20=0;
		for(int i=0;i<n;i++){
			if(t1[i]=='0'){
				t10++;
			}
			if(t2[i]=='0'){
				t20++;
			}
			if(t10>1 || t20>1){
				fC=false;
				break;
			}
		}
		int cnt=0;
		if(fA){
			for(int i=0;i<n;i++){
				if(s1[i]==s2[i]){
					cnt++;
				}
			}
		}else if(fB){
			int s1_1=0,s1_0=0,s2_1=0,s2_0=0;
			for(int i=0;i<n;i++){
				if(t1[i]=='1'){
					if(s1[i]=='1'){
						s1_1++;
					}else{
						s1_0++;
					}
					if(s2[i]=='1'){
						s2_1++;
					}else{
						s2_0++;
					}
				}else{
					if(s1[i]==s2[i]){
						cnt++;
					}
					cnt+=min(s1_1,s2_1);
					cnt+=min(s1_0,s2_0);
					s1_1=0,s1_0=0,s2_1=0,s2_0=0;
				}
			}
			cnt+=min(s1_1,s2_1);
			cnt+=min(s1_0,s2_0);
		}else if(fC){
			int s1_1=0,s1_0=0,s2_1=0,s2_0=0;
			for(int i=0;i<n;i++){
				if(s1[i]=='1'){
					s1_1++;
				}else{
					s1_0++;
				}
				if(s2[i]=='1'){
					s2_1++;
				}else{
					s2_0++;
				}
				if(t1[i]=='0'){
					cnt+=min(s1_1,s2_1);
					cnt+=min(s1_0,s2_0);
					s2_1-=min(s1_1,s2_1);
					s2_0-=min(s1_0,s2_0);
					s1_1=0,s1_0=0;
				}
				if(t2[i]=='0'){
					cnt+=min(s1_1,s2_1);
					cnt+=min(s1_0,s2_0);
					s1_1-=min(s1_1,s2_1);
					s1_0-=min(s1_0,s2_0);
					s2_1=0,s2_0=0;
				}
			}
			cnt+=min(s1_1,s2_1);
			cnt+=min(s1_0,s2_0);
		}else{
			int s1_1=0,s1_0=0,s2_1=0,s2_0=0;
			for(int i=0;i<n;i++){
				if(s1[i]=='1'){
					s1_1++;
				}else{
					s1_0++;
				}
				if(s2[i]=='1'){
					s2_1++;
				}else{
					s2_0++;
				}
				if(t1[i]=='0'){
					cnt+=min(s1_1,s2_1);
					cnt+=min(s1_0,s2_0);
					s2_1-=min(s1_1,s2_1);
					s2_0-=min(s1_0,s2_0);
					s1_1=0,s1_0=0;
				}
				if(t2[i]=='0'){
					cnt+=min(s1_1,s2_1);
					cnt+=min(s1_0,s2_0);
					s1_1-=min(s1_1,s2_1);
					s1_0-=min(s1_0,s2_0);
					s2_1=0,s2_0=0;
				}
			}
			cnt+=min(s1_1,s2_1);
			cnt+=min(s1_0,s2_0);
		}
		cout<<cnt<<endl;
	}
	
	return 0;
}
