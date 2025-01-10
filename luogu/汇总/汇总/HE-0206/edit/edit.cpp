#include<bits/stdc++.h>
using namespace std;
#define N 100000+5
int n,t,ans;
char s1[N],s2[N];
int vis1[N],vis2[N];
bool flag = true;
int main(){
	freopen("edit.in","r",stdin);
	freopen("edit.out","w",stdout);
	cin>>t;
	while(t--){
		flag =true;
		ans = 0;
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>s1[i];
			if(s1[i]!=s1[i-1])flag=false;
		}
		for(int i=1;i<=n;i++){
			cin>>s2[i];
		}
		if(flag==true){
		
			for(int i=1;i<=n;i++){
				if(s1[i]==s2[i])ans++;
				cout<<ans<<endl;
			}
			continue;
		}
		
		for(int i=1;i<=n;i++){
			char opt;
			cin>>opt;
			if(opt=='0'){
				vis1[i]=1;
			}else{
				vis1[i]=0;
			}
		}
		for(int i=1;i<=n;i++){
			char opt;
			cin>>opt;
			if(opt=='0'){
				vis2[i]=1;
			}else{
				vis2[i]=0;
			}
		}
		
		vis1[0]=vis2[0]=vis1[n+1]=vis2[n+1]=1;
		for(int i=1;i<=n;i++){
			if(vis1[i-1]&&vis1[i+1]){
				vis1[i]=1;
			}
		}
		for(int i=1;i<=n;i++){
			if(vis2[i-1]&&vis2[i+1]){
				vis2[i]=1;
			}
		}
		
		for(int i=1;i<=n;i++){
			if(vis1[i]&&vis2[i]){
				if(s1[i]==s2[i])ans++;
			}else if(vis1[i]&&!vis2[i]){
				int j = i;
				while(!vis2[j]&&j<=n){
					if(s2[j]==s1[i]){
						swap(s2[j],s2[i]);
						vis2[i] = 1;
						ans++;
						break;
					}
					else j++;
				}
			}else if(!vis1[i]&&vis2[i]){
				int j = i;
				while(!vis1[j]&&j<=n){
					if(s1[j]==s2[i]){
						swap(s1[j],s1[i]);
						vis1[i] = 1;
						ans++;
						break;
					}
					else{
						j++;
					}
				}
			}else{
				int l=i,r=i;
				while(l<=n&&r<=n&&!vis1[l]&&!vis2[r]){
					if(s1[l]==s2[r]){
						swap(s1[i],s1[l]);
						swap(s2[i],s2[r]);
						vis1[i]=1;
						vis2[i]=1;
						ans++;
						break;
					}else{
						if(vis1[l+1]){
							r++;
						}else l++;
					}
				}
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}

