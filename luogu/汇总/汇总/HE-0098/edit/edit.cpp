#include<bits/stdc++.h>
using namespace std;
string s1,s2,t1,t2;
int sum1[100100],sum2[100100];
int main(){
	freopen("edit.in","r",stdin);
	freopen("edit.out","w",stdout);
	int T;
	scanf("%d",&T);
	while(T--){
		int n;cin>>n;
		memset(sum1,0,sizeof sum1);
		memset(sum2,0,sizeof sum2);
		cin>>s1>>s2>>t1>>t2;
		bool A=1,B=1,C=1;
		int a1_0=0,a1_1=0,a2_0=0,a2_1=0;
		int all1,all2;
		all1=all2=0;
		for(int i=0;i<n;i++){
			if(t1[i]=='0')all1++;
			if(t2[i]=='0')all2++;
			if(i!=0){
				if(s1[i]!=s1[i-1])A=0;
				if(t1[i]=='1'&&t1[i-1]=='0'&&(t1[i+1]=='0'||i+1==n))t1[i]='0';
				if(t2[i]=='1'&&t2[i-1]=='0'&&(t2[i+1]=='0'||i+1==n))t2[i]='0';
				
			}
			else {
				if(t1[i]=='1'&&t1[i+1]=='0')t1[i]='0';
				if(t2[i]=='1'&&t2[i+1]=='0')t2[i]='0';
			}
			if(t1[i]!=t2[i])B=0;
			
			if(s1[i]=='0')a1_0++,sum1[i]++;
			else a1_1++;
			if(s2[i]=='0')a2_0++,sum2[i]++;
			else a2_1++;
			sum1[i]+=sum1[i-1];
			sum2[i]+=sum2[i-1];
//			if(al_0>1)C=0;
		}
		if(A){
//			cout<<"A";
			if(s1[0]=='1')
			printf("%d\n",a2_1);
			else
			printf("%d\n",a2_0);
		}
		else if(B){
//			cout<<"B";
			int wei=0;
			int ans=0;
			t1+='0';
			for(int i=0;i<=n;i++){
				if(t1[i]=='0' ){
					if(i!=0){
					int v1,v2;
					if(wei==0){
						v1=sum1[i-1];
						v2=sum2[i-1];
					}
					else{
						v1=sum1[i-1]-sum1[wei-1];
						v2=sum2[i-1]-sum2[wei-1];
					}
//					ans+=max(min(v1,v2),min(i-wei-v1,i-wei-v2));
					ans+=i-wei-abs(v1-v2);
					}
					if(s1[i]==s2[i]&&i!=n)ans++;
					wei=i+1;
				}
			}
			cout<<ans<<'\n';
		}
		else if(all1==1&&all2==1&&n<=1000){
			int ans=0;
			int t=0;
			int wei1,wei2;
			for(int i=0;i<n;i++){
				if(t==0){
					if(t1[i]=='0'){
						t=1;wei1=i;
					}
					if(t2[i]=='0'){
						t=2;wei1=i;
					}
					
				}
				else{
					if(t1[i]=='0'||t2[i]=='0')wei2=i;
				}
			}
//			if(t==1){
				ans+=wei2-abs(sum1[wei2-1]-sum2[wei2-1]);
//				cout<<ans<<endl;
				ans+=n-wei2-abs(sum1[n-1]-sum2[n-1]-sum1[wei2-1]+sum2[wei2-1]);
//			}
			cout<<ans<<endl;
		}
		else{
			int wei=0;
			int ans=0;int all=0;
			t1+='0';
//			for(int i=n-1;i>=0;i--){
//				if(t1[i]=='0'&&t2[i]=='0')t1[i]=t2[i]='0';
//				else t1[i]=t2[i]='1';
//			}
			for(int i=0;i<=n;i++){
				if(t1[i]=='0'&&t2[i]=='0'||i==n){
//					all++;
//					if(all==1)continue;
					if(i!=0){
					int v1,v2;
					if(wei==0){
						v1=sum1[i-1];
						v2=sum2[i-1];
					}
					else{
						v1=sum1[i-1]-sum1[wei-1];
						v2=sum2[i-1]-sum2[wei-1];
					}
//					ans+=max(min(v1,v2),min(i-wei-v1,i-wei-v2));
					ans+=i-wei-abs(v1-v2);
					}
					if(s1[i]==s2[i]&&i!=n)ans++;
					wei=i+1;
//					cout<<wei<<" "<<ans<<endl;
				}
				

			}
			cout<<ans<<'\n';
		}
	}
	return 0;
}
