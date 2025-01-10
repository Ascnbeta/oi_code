#include<bits/stdc++.h>
using namespace std;
long long t,n,ans;
bool s1[100005],s2[100005],t1[100005],t2[100005];
long long flag1,flag2;
struct ex1{
	long long start,last,num[2];
}ss1[100005];
struct ex2{
	long long start,last,num[2];
}ss2[100005];
int main(){
	freopen("edit.in","r",stdin);
	freopen("edit.out","w",stdout);
	cin>>t;
	while(t--){
		ans=0,flag1=0,flag2=0;
		cin>>n;
		for(int i=1;i<=n;i++){
			char ch;
			cin>>ch;
			s1[i]=ch-'0';
		}
		for(int i=1;i<=n;i++){
			char ch;
			cin>>ch;
			s2[i]=ch-'0';
		}
		for(int i=1;i<=n;i++){
			char ch;
			cin>>ch;
			t1[i]=ch-'0';
		}
		for(int i=1;i<=n;i++){
			char ch;
			cin>>ch;
			t2[i]=ch-'0';
		}
//		for(int i=1;i<=n;i++) cout<<s1[i];
//		cout<<'\n';
//		for(int i=1;i<=n;i++) cout<<s2[i];
//		cout<<'\n';
//		for(int i=1;i<=n;i++) cout<<t1[i];
//		cout<<'\n';
//		for(int i=1;i<=n;i++) cout<<t2[i];
//		cout<<'\n';
		for(int i=1;i<=n;i++){
			if(t2[i]&&!t2[i+1]&&!t2[i-1]) t2[i]=0;
			if(t1[i]&&!t1[i+1]&&!t1[i-1]) t1[i]=0;
		}
		for(int i=1;i<=n;i++){
			if(i==1){
				if(t1[i]){
					flag1++;
					ss1[flag1].start=1;
					ss1[flag1].num[1]=0;
					ss1[flag1].num[0]=0;
					ss1[flag1].num[s1[i]]++;
				}
				if(t2[i]){
					flag2++;
					ss2[flag2].start=1;
					ss2[flag2].num[1]=0; 
					ss2[flag2].num[0]=0;
					ss2[flag2].num[s2[i]]++;
				}
			}else{
				if(t1[i]&&t1[i-1]) ss1[flag1].num[s1[i]]++;
				else if(t1[i]){
					flag1++;
					ss1[flag1].start=i;
					ss1[flag1].num[1]=0;
					ss1[flag1].num[0]=0;
					ss1[flag1].num[s1[i]]++;
				}
				if(!t1[i]&&t1[i-1]) ss1[flag1].last=i-1;
				if(t2[i]&&t2[i-1]) ss2[flag2].num[s2[i]]++;
				else if(t2[i]){
					flag2++;
					ss2[flag2].start=i;
					ss2[flag2].num[1]=0;
					ss2[flag2].num[0]=0;
					ss2[flag2].num[s2[i]]++;
				}
				if(!t2[i]&&t2[i-1]) ss2[flag2].last=i-1;
			}
			if(i==n){
				if(flag1&&t1[i]) ss1[flag1].last=n;
				if(flag2&&t2[i]) ss2[flag2].last=n;
			}
		}
		int flag11=1,flag22=1;
		for(int i=1;i<=n;i++){
			if(i>ss1[flag11].last) flag11++;
			if(i>ss2[flag22].last) flag22++;
			if(!t2[i]&&!t1[i]&&s1[i]==s2[i]) ans++;
			if(t1[i]&&t2[i]){
				if(ss1[flag11].num[0]&&ss2[flag22].num[0]){
					ans++;
					ss1[flag11].num[0]--;
					ss2[flag22].num[0]--;
				}else if(ss1[flag11].num[1]&&ss2[flag22].num[1]){
					ans++;
					ss1[flag11].num[1]--;
					ss2[flag22].num[1]--;
				}
			}else if(t1[i]){
				if(ss1[flag11].num[s2[i]]){
					ans++;
					ss1[flag11].num[s2[i]]--;
				}
			}else if(t2[i]){
				if(ss2[flag22].num[s1[i]]){
					ans++;
					ss2[flag22].num[s1[i]]--;
				}
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
}
