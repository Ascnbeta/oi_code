#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int T,n;
string s1,s2,t1,t2;


int main(){
	freopen("edit.in","r",stdin);
	freopen("edit.out","w",stdout);
	cin>>T;
	while(T--){
		int cnt1=0,cnt2=0,p1=0,p2=0;
		cin>>n;
		cin>>s1>>s2>>t1>>t2;
		int A=1,B=0,C=0;
		for(int i=1;i<n;i++) {
			if(s1[i]!=s1[i-1]) {
				A=0;
			}
		}
		for(int i=0;i<n;i++) {
			if(t1[i]=='0') cnt1++,p1=i;
			if(t2[i]=='0') cnt2++,p2=i;
		}
		if(t1==t2) B=1;
		if(cnt1==1&&cnt2==1) C=1;
		if(A) {
			if(s1[0]=='0') cout<<count(s2.begin(),s2.end(),'0')<<endl;
			else cout<<count(s2.begin(),s2.end(),'1')<<endl;
		}
		if(B){
			t1.push_back('0');
			int cnt=0;
			string tmp1,tmp2;
			for(int i=0;i<=n;i++){
				if(t1[i]=='1') tmp1.push_back(s1[i]),tmp2.push_back(s2[i]);
				else {
					if(i<n) if(s1[i]==s2[i]) cnt++;
					if(tmp1.size()){
						int s11=count(tmp1.begin(),tmp1.end(),'1');
						int s10=count(tmp1.begin(),tmp1.end(),'0');
						int s21=count(tmp2.begin(),tmp2.end(),'1');
						int s20=count(tmp2.begin(),tmp2.end(),'0');
						tmp1.clear();tmp2.clear();
						cnt+=min(s11,s21)+min(s10,s20);
					}
				}
			}
			cout<<cnt<<endl;
		}
		if(C){
			if(p1<p2){
				if(s1[p1]!=s2[p1]){
					for(int i=0;i<p2-1;i++){
						if(s2[i]==s1[p1]) {
							swap(s2[i],s2[p1]);
							break;
						}
					}
				}
				if(s1[p2]!=s2[p2]){
					for(int i=p1;i<n;i++){
						if(s1[i]==s2[p2]) {
							swap(s1[i],s1[p2]);
							break;
						}
					}
				}
				t1.push_back('0');
				t2.push_back('0');
				int cnt=0;
				string tmp1,tmp2;
				for(int i=0;i<=n;i++){
					if(t1[i]=='1'&&t2[i]=='1') tmp1.push_back(s1[i]),tmp2.push_back(s2[i]);
					else {
						if(i<n) if(s1[i]==s2[i]) cnt++;
						if(tmp1.size()){
							int s11=count(tmp1.begin(),tmp1.end(),'1');
							int s10=count(tmp1.begin(),tmp1.end(),'0');
							int s21=count(tmp2.begin(),tmp2.end(),'1');
							int s20=count(tmp2.begin(),tmp2.end(),'0');
							tmp1.clear();tmp2.clear();
							cnt+=min(s11,s21)+min(s10,s20);
						}
					}
				}
				cout<<cnt<<endl;
			} else if(p1>p2){
				if(s2[p2]!=s1[p2]){
					for(int i=0;i<p1-1;i++){
						if(s1[i]==s2[p2]) {
							swap(s1[i],s1[p2]);
							break;
						}
					}
				}
				if(s2[p1]!=s1[p1]){
					for(int i=p2;i<n;i++){
						if(s2[i]==s1[p1]) {
							swap(s2[i],s2[p1]);
							break;
						}
					}
				}
				t1.push_back('0');
				t2.push_back('0');
				int cnt=0;
				string tmp1,tmp2;
				for(int i=0;i<=n;i++){
					if(t1[i]=='1'&&t2[i]=='1') tmp1.push_back(s1[i]),tmp2.push_back(s2[i]);
					else {
						if(i<n) if(s1[i]==s2[i]) cnt++;
						if(tmp1.size()){
							int s11=count(tmp1.begin(),tmp1.end(),'1');
							int s10=count(tmp1.begin(),tmp1.end(),'0');
							int s21=count(tmp2.begin(),tmp2.end(),'1');
							int s20=count(tmp2.begin(),tmp2.end(),'0');
							tmp1.clear();tmp2.clear();
							cnt+=min(s11,s21)+min(s10,s20);
						}
					}
				}
				cout<<cnt<<endl;
			}
		}
	}
	
	return 0;
}
