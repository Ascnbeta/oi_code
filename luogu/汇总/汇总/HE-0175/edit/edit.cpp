#include<bits/stdc++.h>
using namespace std;

char s1[100005];
char s2[100005];
char t1[100005];
char t2[100005];
int main(){
	int T,n;
	ios::sync_with_stdio(false);
	freopen("edit.in","r",stdin);
	freopen("edit.out","w",stdout);
	cin>>T;
	while(T--){
		cin>>n;
		cin>>s1>>s2>>t1>>t2;
		int ans=0,down_1=0,down_0=0,up_1=0,up_0=0;
		int s1_true=1;
		char true_num;
		for(int i=0;i<n-1;i++){
			if(s1[i]!=s1[i+1]){
				s1_true=0;
				break;
			}
		}
		if(s1_true==1){
			true_num=s1[0];
			for(int i=0;i<n;i++){
				if(s2[i]==true_num){
					ans++;
				}
			}
			cout<<ans<<endl;
			continue;
		}
		if(string(t1)==string(t2)){
			for(int i=0;i<n;i++){
				if(t1[i]=='1'){
					if(s1[i]=='0'){
						up_0++;
					}else{
						up_1++;
					}
					if(s2[i]=='0'){
						down_0++;
					}else{
						down_1++;
					}	
				}else{
					if(s1[i]==s2[i]){
						ans++;
					}
					ans+=(min(up_0,down_0)+min(up_1,down_1));
					down_1=0;down_0=0;up_1=0;up_0=0;
				}
			}
			cout<<ans<<endl;
			continue;
		}
	}
	return 0;
}
