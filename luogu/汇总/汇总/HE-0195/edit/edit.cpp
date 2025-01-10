#include<bits/stdc++.h>
using namespace std;
/*
1
6
011101
111010
111010
101101

*/
int T,n,su;
char s1[10005];
char s2[10005];
char t1[10005];
char t2[10005];
bool ca;
void ck(char b[10005],int i){
	
	if(i==2&&b[2]=='0') b[1] = '0';
	if(i==n&&b[n-1]=='0') b[n] = '0';
	if(i>2&&i<=n){
		if(b[i] == '0'&&b[i-2] == '0') b[i-1] = '0';
	}
	
	return ;
}
void ex(char a[10005],int i){
	char k = a[i+1];
	a[i+1] = a[i];
	a[i] = k;
}
void cok(char t1[10005],char t2[10005],char s1[10005],char s2[10005]){
	for(int i = 1;i<=n;i++){
		if(t1[i]=='1'){
			if(s1[i]==s2[i]){
				su++;
				t1[i] == '0';
			}else{
				if(t1[i+1]=='1'&& s1[i+1]==s2[i]){
					su++;
					t1[i] == '0';
				}
				ex(s1,i);
			}
		}
				
	}
}
int main(){
	freopen("edit.in","r",stdin);
	freopen("edit.out","w",stdout);
	cin>>T;
	while(T){
		T--;
		su = 0;
		ca = true;
		cin>>n;
		for(int i = 1;i<=n;i++){
			cin>>s1[i];
			if(i>1&&s1[i]!=s1[i-1]) ca = false;
		}
		for(int i = 1;i<=n;i++){
			cin>>s2[i];
			if(ca&&s2[i]==s1[1]) su++;
		}
		for(int i = 1;i<=n;i++){
			cin>>t1[i];
			if(ca==0){
				ck(t1,i);
			}
			//cout<<t1[i];
		}
		//cout<<endl;
		for(int i = 1;i<=n;i++){
			cin>>t2[i];
			if(ca==0){
				ck(t2,i);
			}
		}
		if(!ca){
			/*
			for(int i = 1;i<=n;i++){
				if(t1[i]=='0'&&t2[i]=='0'){
					if(s1[i]==s2[i]) su++;
				}else if(t1[i]=='1'){
					if(s1[i]==s2[i]){
						su++;
						t1[i] == '0';
					}else{
						if(t1[i+1]=='1'&& s1[i+1]==s2[i]){
							su++;
							t1[i] == '0';
						}
						ex(s1,i);
					}
				}
				
			}
			*/
			for(int i = 1;i<=n;i++){
				if(t1[i]=='0'&&t2[i]=='0'){
					if(s1[i]==s2[i]) su++;
				} 
			}
			cok(t1,t2,s1,s2);
			cok(t2,t1,s2,s1);
			
		}
		cout<<su<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
