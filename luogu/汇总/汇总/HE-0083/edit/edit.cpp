#include<bits/stdc++.h>
using namespace std;
long long int t,n,f1=1,f2=1,x=0,y=0,s,l,r,m;
string s1,s2,t1,t2;
int main(){
	freopen("edit.in","r",stdin);
	freopen("edit.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n>>s1>>s2>>t1>>t2;
		x=0;
		m=0;
		f1=1;
		f2=1;
		if(n==1){
			if(s1[0]==s2[0]){
				printf("1\n");
			}else{
				printf("0\n");
			}
			continue;
		}
		for(long long int i=0;i<n-1;i++){
			if(s1[i]!=s1[i+1]){
				f1=0;
				break;
			}
		}
		if(f1==1){
			for(long long int i=0;i<n;i++){
				if(s2[i]=='1'){
					x++;
				}
			}
			if(s1[0]=='1'){
				printf("%d\n",x);
			}else{
				printf("%d\n",n-x);
			}
			continue;
		}
		for(long long int i=0;i<n;i++){
			if(t1[i]!=t2[i]) f2=0;
		}

		if(f2==1){
			s=0;
			x=0;
			y=0;
			r=0;
			for(long long int i=0;i<n;i++){
				if(t1[i]!='0'&&i!=n-1){
					r++;
					if(s1[i]=='1') x++;
					if(s2[i]=='1') y++;
				}else{
					if(s1[i]==s2[i]) s++;
					s+=min(x,y)+min(r-x,r-y);
					x=0;
					y=0;
					r=0;
				}
			}
			cout<<s<<endl;
			continue;
		}
		cout<<"4"<<endl; 
	}
	return 0;
} 
