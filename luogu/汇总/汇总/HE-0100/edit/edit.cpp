#include <bits/stdc++.h>
using namespace std;

int main(){
	freopen("edit.in","r",stdin);
	freopen("edit.out","w",stdout);
	int t;
	cin >> t;
	while(t--){
		int n,ans=0;
		string s1,s2,s3,s4;
		cin >> n;
		cin >> s1 >> s2 >> s3 >> s4;
		if (s1.find('1') == string::npos||s1.find('0') == string::npos){
			for (int i = 0;i<s2.size();i++){
				if (s2[i]==s1[0]) ans++;//gai
			}
		}
		else if (s3==s4){
			int a[3]={0,0},b[3]={0,0};
			for (int i = 0;i<s1.size();i++){
				if (s3[i]=='0'){
					ans += min(a[0],b[0]);
					ans += min(a[1],b[1]);
					if(s2[i]==s1[i]) ans++;
					a[0] = a[1] = b[0] = b[1] = 0;
				} else{
					a[(s1[i]-'0')]++;
					b[(s2[i]-'0')]++;
				}
			}
			ans += min(a[0],b[0]);
			ans += min(a[1],b[1]);
		}
		else{
			int a[3]={0,0},b[3]={0,0};
			int sl[3],xl[3],ans2=0;
			
			for (int i = s1.size()-1;i>=0;i--){
				a[(s1[i]-'0')]++;
				b[(s2[i]-'0')]++;
				if (s3[i]=='0'||s4[i]=='0'){
					ans2 += min(a[0],b[0]);
					ans2 += min(a[1],b[1]);
					a[0] = a[1] = b[0] = b[1] = 0;
				}
			}
			ans2 += min(a[0],b[0]);
			ans2 += min(a[1],b[1]);
			a[0] = a[1] = b[0] = b[1] = 0;
			
			for (int i = s1.size()-1;i>=0;i--){
				a[(s1[i]-'0')]++;
				sl[(s1[i]-'0')] = i;
				b[(s2[i]-'0')]++;
				xl[(s2[i]-'0')] = i;
				if ((s3[i]=='0'||s4[i]=='0')&&!(s3[i]=='0'&&s4[i]=='0')&&(s1[i]!=s2[i])){
					if (s3[i]=='0'&&b[s1[i]-'0']!=0){
						swap(s2[i],s2[xl[s1[i]-'0']]);//a 
						s4[i] = '0';
						a[0] = a[1] = b[0] = b[1] = 0;
					}
					
				}
			}
			a[0] = a[1] = b[0] = b[1] = 0;
			for (int i = 0;i<s1.size();i++){
				a[(s1[i]-'0')]++;
				b[(s2[i]-'0')]++;
				if (s3[i]=='0'||s4[i]=='0'){//2key
					ans += min(a[0],b[0]);
					ans += min(a[1],b[1]);
					a[0] = a[1] = b[0] = b[1] = 0;
				}
			}
			ans += min(a[0],b[0]);
			ans += min(a[1],b[1]);
			ans = max(ans,ans2);
		}
		cout << ans << endl;
	}
	return 0;
} 
