#include<bits/stdc++.h>
#define int long long
using namespace std;
string s1,s2;
string flag[3];
int n,T;
char c;
int f=0,ans,cnt1[5],cnt2[5],num1,num2,ma;
signed main(){
	freopen("edit.in","r",stdin);
	freopen("edit.out","w",stdout);
	cin>>T;
	while(T--){
		cin>>n>>s1>>s2;
		cin>>flag[1]>>flag[2];
 		c=s1[0];
 		for(int i=0;i<n;i++){
 			if(c!=s1[i]){
 				f=1;
 				break;
			}
		}
		/**********性质A**/
		if(f==0){
		 	for(int i=0;i<n;i++){
		 		if(s2[i]==c){
		 			ans++;
				 }
			}
			cout<<ans<<endl;
			ans=0;
			f=0;
			continue;
		}else if(flag[1]==flag[2]){/*****************性质B****/
		 	for(int i=0;i<n;i++){
		 		if(flag[1][i]=='1'){
		 			cnt1[s1[i]-'0']++;
		 			cnt2[s2[i]='0']++;
				}else if(flag[1][i]=='0'){
					if(s1[i]==s2[i]){
						ans++;
					}
					ans+=min(cnt1[0],cnt2[0])+min(cnt1[1],cnt2[1]);
					cnt1[1]=cnt1[0]=cnt2[1]=cnt2[0]=0;
				}
			}
			cout<<ans<<endl;
			ans=0;
			f=0;
			continue;
		}
		for(int i=0;i<n;i++){
			if(flag[1][i]=='1'){
				cnt1[s1[i]-'0']++;
			}
			if(flag[2][i]=='1'){
				cnt2[s2[i]-'0']++;
			} 
		}
		ans+=max(cnt1[0],cnt2[0])+max(cnt1[1],cnt2[1]);
		cout<<ans<<endl;
		ans=0;
	}

	return 0;
} 

