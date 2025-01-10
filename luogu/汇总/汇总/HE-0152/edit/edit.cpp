#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=1e5+20;
int n;
int t;
char a[N];
char b[N];
char k1[N];
char k2[N];
inline int in(){
	int f=1;
	int ans=0;
	char c=getchar();
	while(c<'0'||c>'9'){
		if(c=='-'){
			f=-1;
		}
		c=getchar();
	}
	while('0'<=c&&c<='9'){
		ans=(ans<<3)+(ans<<1)+(c^48);
		c=getchar();
	}
	return ans*f;
}
signed main(){
	//9:10 期望得分 40pts 
	freopen("edit.in","r",stdin);
	freopen("edit.out","w",stdout);
//	ios::sync_with_stdio(false);
//	cin.tie(0);
	t=in();
	while(t--){
		n=in();
		cin>>a+1>>b+1;
		cin>>k1+1>>k2+1;
		int flag=1;//特殊性质 A 
		for(int i=1;i<n;i++){
			if(a[i]!=a[i+1]){
		//		cout<<i<<" ";
		//		cout<<a[i]<<" "<<a[i+1];
				flag=0;
				break;
			}
		}
	//	cout<<flag;
		if(flag==1){
			int cnt=0;
			for(int i=1;i<=n;i++){
				if(a[i]==b[i]){
					cnt++;
				}
			}
			cout<<cnt<<endl;
			continue;
		}
		//-------------------------
		int flag2=1;//特殊性质 B  
		for(int i=1;i<=n;i++){
			if(k1[i]!=k2[i]){
				flag2=0;
				break;
			}
		}
		if(flag2==1){
			int cnt=0;
			int m1=0,m2=0,g1=0,g2=0;
			for(int i=1;i<=n+1;i++){
				if(k1[i]=='0'||i==n+1){
					if(a[i]==b[i]&&i!=n+1) cnt++;
					cnt+=min(m1,m2)+min(g1,g2);
					m1=m2=g1=g2=0;
					continue;
				}else{
					if(a[i]=='1'){
						m1++;
					}else{
						g1++;
					}
					if(b[i]=='1'){
						m2++;
					}else{
						g2++;
					}
				}
			}
			cout<<cnt<<endl;
			continue;
		}
		//-------------------------
		//C 期望得分 60pts
		int cnt=0;
		int m1=0,m2=0,g1=0,g2=0;
		for(int i=1,j=1;i<=n+1,j<=n+1;i++,j++){
			if(k1[i]=='0'||i==n+1){
				
				while(k2[j]!='0'&&j<=n){
					if(b[j]=='1'){
						m2++;
					}else{
						g2++;
					}
					j++;
				}
				cnt+=min(m1,m2)+min(g1,g2);
				m2-=min(m1,m2);
				g2-=min(g1,g2);
				m1=g1=0;
				j--;
				if(a[i]=='1'){
					m1++;
				}else{
					g1++;
				}
				if(m2>0&&a[i]=='1'){
					cnt++;
					m2--;
				}
				if(g2>0&&a[i]=='0'){
					cnt++;
					g2--;
				}
			}else if(k2[j]=='0'||j==n+1){
				
				while(k1[i]!='0'&&i<=n){
					if(a[i]=='1'){
						m1++;
					}else{
						g1++;
					}
					i++;
				}
				cnt+=min(m1,m2)+min(g1,g2);
				m1-=min(m1,m2);
				g1-=min(g1,g2);
				m2=g2=0;
				i--;
				if(b[j]=='1'){
					m2++;
				}else{
					g2++;
				}
				if(m1>0&&b[j]=='1'){
					cnt++;
					m1--;
				}
				if(g1>0&&b[j]=='0'){
					cnt++;
					g1--;
				}
				
			}else{
				if(a[i]=='1'){
					m1++;
				}else{
					g1++;
				}
				if(b[i]=='1'){
					m2++;
				}else{
					g2++;
				}
			}
		}
		cout<<cnt<<endl;
	}
	
	
	
	
	return 0;
}
