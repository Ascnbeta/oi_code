#include<bits/stdc++.h>
using namespace std;
string zhuan_m(unsigned long long n,int m){
	int k[100],l=0;
    char c[100];
	for(unsigned long long a=n;a;a/=m){
		k[++l]=a%m;	
	} 
	for(int i=l;i>=1;i--){
		if(k[i]<=9) c[l-i]=k[i]+48;
		else c[l-i]=k[i]+55;
	}
	return c;
}
unsigned long long p(int x){
    long long r=1;
    for(int i=1;i<=x;i++) r*=10;
    return r;
}
unsigned long long sum[1200];
string ans[1200];
int main(){
	string s;
	cin>>s;
	int t=s.size(),l=0,m=1,u=1;
	for(int i=t-2;i+1;i--){
		if(s[i]!=','&&s[i]!='{') sum[m]+=(p(l++)*(s[i]-'0'));
		else {
			string p=zhuan_m(sum[m],16);
			string q="0x";
			string k=q+p; 
			if(k.size()<=l) ans[u++]=k;
			else {
                ans[u++]=zhuan_m(sum[m],10);
            }	
			l=0,m++;	
		}
	}
	cout<<"{";
    cout<<ans[u-1];
    for(int i=u-2;i;i--) cout<<","<<ans[i];
    cout<<"}";
	return 0;
}