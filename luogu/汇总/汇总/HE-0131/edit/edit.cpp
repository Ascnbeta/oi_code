#include<bits/stdc++.h>
using namespace std;
const int MAXN=1e5+10;
int str1[MAXN];
int str2[MAXN];
int chstr1[MAXN];
int chstr2[MAXN];
int T,n;
int ans=0;
int check;
string num1;
string num2;
string num3;
string num4;
int cont(){
	int res=0;
	for(int i=0;i<n;i++){
		if(num1[i]==num2[i]){
			res++;
		}
	}
	return res;
}
void change1(){
	for(int i=0;i<n;i++){
		if(num1[i]!=num2[i]&&num3[i]=='1'&&num3[i+1]=='1'&&num1[i+1]==num2[i]&&i+1<n){
			char cnt=num1[i];
			char cnt2=num1[i+1];
			num1[i]=cnt2;
			num1[i+1]=cnt;
		}
		//for(int j=0;j<n;j++){
		//	cout<<num1[j]<<" ";
		//}
		//cout<<endl;
	}
}
void change2(){
	for(int i=0;i<n;i++){
		if(num2[i]!=num1[i]&&num2[i+1]==num1[i]&&num4[i]=='1'&&num4[i+1]=='1'&&i+1<n){
			char cnt=num2[i];
			char cnt2=num2[i+1];
			num2[i]=cnt2;
			num2[i+1]=cnt;
		}
		//for(int j=0;j<n;j++){
		//	cout<<num2[j]<<" ";
		//}
		//cout<<endl;
	}
}
int main(){
	freopen("edit.in","r",stdin);
	freopen("edit.out","w",stdout);
	cin>>T;
	for(int ch=0;ch<T;ch++){
		cin>>n;
		cin>>num1;
		cin>>num2;
		cin>>num3;
		cin>>num4;
		change1();
		change2();
		ans=cont();
		cout<<ans;
	}
	return 0;
}
