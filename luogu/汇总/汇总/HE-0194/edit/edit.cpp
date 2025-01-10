#include <bits/stdc++.h>
using namespace std;

const int N = 1e5+5;
string a,b,x,y;
int v[N][2];
int be[N];
int he[N];
int n;
int zt=0;
int ans=0;

bool special(){
	char s = a[0];
	for(int c1=1;c1<n;c1++){
		if(a[c1]!=s) return 0;
	}
	return 1;
}

int main(){
	freopen("edit.in","r",stdin);
	freopen("edit.out","w",stdout);
	int t;
	scanf("%d",&t);
	for(int i=0;i<t;i++){//主循环 
		scanf("%d",&n);//长度
		cin>>a>>b>>x>>y;
		if(special()){
			for(int c2=0;c2<n;c2++){
				if(b[c2]==a[0]) ans++;
			}
			cout<<ans;
			continue;
		}
		int team=0;//组别 
		for(int k=0;k<n;k++){
			if(y[k]=='0'){
				if(b[k]=='1') he[k] = 1;
				else he[k] = 0;
				b[k] = '-';
			}
			if(x[k] == '0'){
				if(k!=0) team ++;
				a[k] = '-';
				be[k] = -1;
			}
			else{
				if(a[k] == '0') v[team][0]++;
				else v[team][1]++;
				be[k] = team;
			}
		}
		
		//遍历b
		for(int j=0;j<n;j++){
			if(a[j]!='-'){
				if(b[j]=='1' && v[be[j]][1]>0){
					ans++;
					v[be[j]][1]--;
				}
				else if(b[j]=='0' && v[be[j]][0]>0){
					ans++;
					v[be[j]][0]--;
				}
			}
			
			else if(b[j+1]!='-' && a[j+1]!='-'){
				if(b[j]=='1' && v[be[j+1]][1]>0){
					ans++;
					v[be[j+1]][1]--;
				}
				else if(b[j]=='0' && v[be[j+1]][0]>0){
					ans++;
					v[be[j+1]][0]--;
				}
			}
			else{
				if(he[j]==1&&v[be[j]][1]>0){
					ans++;
					v[be[j]][1]--;
				}
				else if(he[j]==0 && v[be[j+1]][0]>0){
					ans++;
					v[be[j]][0]--;
				}
			}
		}
		printf("%d",ans);
	}
}
