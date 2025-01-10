#include<bits/stdc++.h>
using namespace std;
char s1[100005],s2[100005],t1[100005],t2[100005];
int t,n,ans,cnt1[100005][2],cnt2[100005][2],ids[100005],idt[100005],ccnt;
int main(){
	freopen("edit.in","r",stdin);
	freopen("edit.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>t;
	while(t--){
		cin>>n;
		cin>>s1+1;
		cin>>t1+1;
		cin>>s2+1;
		cin>>t2+1;
		ccnt=0;
		for(int i=1;i<=n;i++){
			if(s2[i]=='1'){
				ccnt++;
				ids[i]=ccnt;
				while(i+1<=n && s2[i+1]=='1') i++,ids[i]=ccnt;
			}
		}
		ccnt=0;
		for(int i=1;i<=n;i++){
			if(t2[i]=='1'){
				ccnt++;
				idt[i]=ccnt;
				while(i+1<=n && t2[i+1]=='1') i++,idt[i]=ccnt;
			}
		}
		for(int i=1;i<=n;i++){
			if(s2[i]=='1') cnt1[ids[i]][s1[i]-'0']++;
			if(t2[i]=='1') cnt2[idt[i]][t1[i]-'0']++;
		}
		for(int i=1;i<=n;i++){
			if(s2[i]=='0' && t2[i]=='0'){
				if(s1[i]==t1[i]) ans++;
			}
		}
		for(int i=1;i<=n;i++){
			if(s2[i]=='1' && t2[i]=='0'){
				if(cnt1[ids[i]][t1[i]-'0']){
					ans++;
					cnt1[ids[i]][t1[i]-'0']--;
				}
			}
			if(s2[i]=='0' && t2[i]=='1'){
				if(cnt2[idt[i]][s1[i]-'0']){
					ans++;
					cnt2[idt[i]][s1[i]-'0']--;
				}
			}
		}
		for(int i=1;i<=n;i++){
			if(s2[i]=='1' && t2[i]=='1'){
				if(cnt1[ids[i]][0] && cnt2[idt[i]][0]){
					cnt1[ids[i]][0]--;
					cnt2[idt[i]][0]--;
					ans++; 
				}else if(cnt1[ids[i]][1] && cnt2[idt[i]][1]){
					cnt1[ids[i]][1]--;
					cnt2[idt[i]][1]--;
					ans++;
				}
			}
		}
		cout<<ans<<'\n';
		ans=ccnt=0;
		memset(cnt1,0,sizeof(cnt1));
		memset(cnt2,0,sizeof(cnt2));
		memset(ids,0,sizeof(ids));
		memset(idt,0,sizeof(idt));
	}
	return 0;
}
