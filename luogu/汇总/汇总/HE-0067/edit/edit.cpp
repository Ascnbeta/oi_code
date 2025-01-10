#include<iostream>
#include<string>
#include<cstdio>
#include<cstring>
using namespace std;
string s1,s2,t1,t2;
int len,t;
int main(){
	freopen("edit.in","r",stdin);
	freopen("edit.out","w",stdout);
	cin.tie(0),cout.tie(0);
	cin>>t;
	for(int u=0;u<t;u++){
		cin>>len;
		cin>>s1>>s2>>t1>>t2;
		bool if_=true;
		for(int i=1;i<len;i++){
			if(s1[i]!=s1[i-1]){
				if_=false;
			}
		}
		int ans1=0,ans2=0,sum=0;
		if(if_==true){
			for(int i=0;i<len;i++){
				if(s1[i]==s2[i]){
					ans1++;
				}
			}
			cout<<ans1<<endl;
			continue;
		}
		if(t1==t2){
			int s10=0,s11=0,s21=0,s20=0;
			for(int i=0;i<len;i++){
				if(t1[i]=='0'){
					if(s1[i]==s2[i]){
						ans1++;
					}
					ans1=ans1+min(s10,s20);
					ans1=ans1+min(s11,s21);
					s10=0;s20=0;s11=0;s21=0;
					continue;
				}
				if(s1[i]=='0'){
					s10++;
				}else{
					s11++;
				}
				if(s2[i]=='0'){
					s20++;
				}else{
					s21++;
				}
			}
			ans1=ans1+min(s10,s20);
			ans1=ans1+min(s11,s21);
			cout<<ans1<<endl;
			continue;
		}
		for(int i=0;i<len;i++){
			if(s1[i]==s2[i]){
				ans1++;
				continue;
			}
			if(s1[i+1]==s2[i]&&t1[i]=='1'&&t1[i+1]=='1'){
				s1[i+1]=s1[i];
				ans1++;
				continue;
			}
			if(s2[i+1]==s1[i]&&t2[i]=='1'&&t2[i+1]=='1'){
				s2[i+1]=s2[i];
				ans1++;
				continue;
			}
		}
		for(int i=0;i<len;i++){
			if(s1[i]==s2[i]){
				ans2++;
				continue;
			}
			if(s2[i+1]==s1[i]&&t2[i]=='1'&&t2[i+1]=='1'){
				s2[i+1]=s2[i];
				ans2++;
				continue;
			}
			if(s1[i+1]==s2[i]&&t1[i]=='1'&&t1[i+1]=='1'){
				s1[i+1]=s1[i];
				ans2++;
				continue;
			}
		}
		cout<<max(ans1,ans2)<<endl;
		
	}
}
