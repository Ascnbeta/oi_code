#include<bits/stdc++.h>
using namespace std;
const int maxn=10e5+1;
int s1[maxn][2],s2[maxn][2],flag[maxn],ans,n;
int main(){
	freopen("edit.in","r",stdin);
	freopen("edit.out","w",stdout);
	int t;
	cin>>t;
	while(t--){
		string a;
		ans=0;
		cin>>n;
		memset(flag,0,n);
		cin>>a;
		for(int i=0;i<n;i++)s1[i][0]=a[i]-48;
		cin>>a;
		for(int i=0;i<n;i++)s2[i][0]=a[i]-48;
		cin>>a;
		for(int i=0;i<n;i++){
			s1[i][1]=a[i]-48;
		}
		cin>>a;
		for(int i=0;i<n;i++){
			s2[i][1]=a[i]-48;
		}
		//
		for(int i=0;i<n;i++){
			if(s1[i][0]==s2[i][0])flag[i]=1,ans++;
			if(!((s1[i][1])||(s2[i][1]))){
					flag[i]=1;
					continue;
			}
		}
		int m=0,x=0;
		for(int i=0;i<n;i++){
			if(!(flag[i])){
				if(s2[i][1]){
					x=i;
					for(int j=m;j<n;j++){
						if((j>i)&&(!s2[j][1]))break;
						if(flag[j])continue;
						if(!s2[j][1])continue;
						if(s2[j][0]==s1[i][0]){
							int p=1;
							if(j<i){
								for(int k=min(i,j);k<=max(i,j);k++){
									if(!s2[k][1]){
										p=0;
										break;
									}
								}
							}
							if(p){
								ans+=2;
								flag[i]=1;flag[j]=1;
								break;
							}
						}
					}
					
				}
				if(s1[i][1]&&flag[i]){
					m=i;
					for(int j=x;j<n;j++){
						if((j>i)&&(!s1[j][1]))break;
						if(flag[j])continue;
						if(!s1[j][1])continue;
						if(s1[j][0]==s2[i][0]){
							int p=1;
							if(j<i){
								for(int k=min(i,j);k<=max(i,j);k++){
									if(!s1[k][1]){
										p=0;
										break;	
									}
								}
							}
							if(p){
								ans+=2;
								flag[i]=1;flag[j]=1;
								break;
							}
						}
					}
				}
				flag[i]=1;
			}
		}
		cout<<ans<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
