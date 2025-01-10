#include<bits/stdc++.h>
using namespace std;
int t,n;
char s1[100005],s2[100005],t1[100005],t2[100005];
int a[100005];
int sum;
int aa0,aa1,bb0,bb1;
int main(){
	freopen("edit.in","r",stdin);
	freopen("edit.out","w",stdout);
	scanf("%d",&t);
	for(int e=1;e<=t;e++){
			scanf("%d",&n);
			cin>>s1>>s2>>t1>>t2;		
			for(int i=1;i<=n-2;i++){
				if(t1[i-1]=='0'&&t1[i+1]=='0') t1[i]='0';
				if(t2[i-1]=='0'&&t2[i+1]=='0') t2[i]='0';
			}	
			if(t1[1]=='0')     t1[0]='0';
			if(t1[n-2]=='0')   t1[n-1]='0';
			if(t2[1]=='0')     t2[0]='0';
			if(t2[n-2]=='0')   t2[n-1]='0';
			
			for(int i=0;i<=n-1;i++){
				if(t1[i]=='1'||t2[i]=='1'){
					a[i]=1;
				}else if(t1[i]=='0'&&t2[i]=='0'){
					if(s1[i]==s2[i]) sum++;
				}
			}
			for(int i=0;i<=n;i++){
				if(a[i]==1){
					if(s1[i]=='0') aa0++;
					if(s1[i]=='1') aa1++;
					if(s2[i]=='0') bb0++;
					if(s2[i]=='1') bb1++;
					a[i]=0;
				}
				else if(a[i]==0){
					sum+=min(aa0,bb0);
					sum+=min(aa1,bb1);
					aa0=0;bb0=0;aa1=0;bb1=0;
				}
			}
			printf("%d\n",sum);
			sum=0;
	}
	return 0;
}
