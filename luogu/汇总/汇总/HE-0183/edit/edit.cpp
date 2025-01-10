#include<bits/stdc++.h>
using namespace std;

int T,n;
char c;
bool s1[100010],s2[100010],ta[100010],tb[100010];
int ans,j,jj;

int main(){
	freopen("edit.in","r",stdin);
	freopen("edit.out","w",stdout);
	
	cin>>T;
	for(int k=1;k<=T;k++){
		memset(s1,0,sizeof(s1));
		memset(s2,0,sizeof(s2));
		memset(ta,0,sizeof(ta));
		memset(tb,0,sizeof(tb));
		ans=0;
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>c;
			if(c=='1'){
				s1[i]=1;
			}
		}
		for(int i=1;i<=n;i++){
			cin>>c;
			if(c=='1'){
				s2[i]=1;
			}
		}
		for(int i=1;i<=n;i++){
			cin>>c;
			if(c=='1'){
				ta[i]=1;
			}
		}
		for(int i=1;i<=n;i++){
			cin>>c;
			if(c=='1'){
				tb[i]=1;
			}
		}
		
		for(int i=1;i<=n;i++){
			if(s1[i]!=s2[i]){
				j=1;
				while(ta[i]==1 && ta[i+j]==1){
					if(s1[i]!=s1[i+j]){
						int temp=s1[i];
						s1[i]=s1[i+j];
						s1[i+j]=temp;
						break;
					}
					j++;
				}
			}
			if(s1[i]!=s2[i]){
				jj=1;
				while(tb[i]==1 && tb[i+jj]==1){
					if(s2[i]!=s2[i+jj]){
						int temp=s2[i];
						s2[i]=s2[i+jj];
						s2[i+jj]=temp;
						break;
					}
					jj++;
				}
			}
		}
		
		for(int i=1;i<=n;i++){
			if(s1[i]==s2[i]){
				ans++;
			}
		}
		cout<<ans<<endl;
	
	}
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
