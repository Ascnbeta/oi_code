#include<bits/stdc++.h>
using namespace std;
int t,n,a[2][100010],b[2][100010],ans;
char s1[100010],s2[100010];
char v1[100010],v2[100010];
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("edit.in","r",stdin);
	freopen("edit.out","w",stdout);
	cin>>t;
	while(t--){
		ans=0;
		cin>>n;
		for(int i=1;i<=n;i++) cin>>s1[i];
		for(int i=1;i<=n;i++) cin>>s2[i];
		for(int i=1;i<=n;i++) cin>>v1[i];
		for(int i=1;i<=n;i++) cin>>v2[i];
		for(int i=1;i<=n;i++){
			a[s1[i]-'0'][i]=1;
			a[(s1[i]-'0'+1)%2][i]=0;
			if(v1[i]=='1'&&v1[i-1]=='1'){
				a[0][i]+=a[0][i-1];
				a[1][i]+=a[1][i-1];
			}
		}
		for(int i=1;i<=n;i++){
			b[s2[i]-'0'][i]=1;
			b[(s2[i]-'0'+1)%2][i]=0;
			if(v2[i]=='1'&&v2[i-1]=='1'){
				b[0][i]+=b[0][i-1];
				b[1][i]+=b[1][i-1];
			}
		}
		int l=1,r=1;
		while(l<=n||r<=n){
			if(v1[l]=='1') while(v1[l+1]!='0'&&l+1<=n) l++;
			if(v2[r]=='1') while(v2[r+1]!='0'&&r+1<=n) r++;
			int y=min(a[0][l],b[0][r]);
			int y1=min(a[1][l],b[1][r]);
			ans+=y;
			ans+=y1;
			if(l<r){
				b[0][r]-=y;
				b[1][r]-=y1;
				l++;
			}else if(l>r){
				a[0][l]-=y;
				a[1][l]-=y1;
				r++;
			}else if(l==r){
				l++;
				r++;
			}
		}
		cout<<ans<<'\n';
	}
}
