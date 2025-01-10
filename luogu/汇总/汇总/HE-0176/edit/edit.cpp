#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 7;
int n;
string s1, s2;
bool a[N], b[N];
void putin(){
	for(int i = 1; i <= n; i++){
		char ch;
		cin >> ch;
		a[i] = ch - '0';
	}
	for(int i = 1; i <= n; i++){
		char ch;
		cin >> ch;
		b[i] = ch - '0';
	}
}
int ans; 
int main(){
	freopen("edit.in","r",stdin);
	freopen("edit.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0); 
	int T;
	cin >> T;
	while(T--){
		cin >> n;
		for(int i = 1; i <= n; i++)
			a[i] = b[i] = false;
		cin >> s1 >> s2;
		putin();
		ans = 0;
		int s10 = 0, s20 = 0, s11 = 0, s21 = 0;
		for(int i = 1, j = 0; i <= n; i++){
			if((a[i] && a[i - 1]) || (b[i] && b[i - 1]) || (s1[i - 1] == s2[i - 1]) || (a[i] == b[i] && (a[i - 1] || b[i - 1])))j++;
			else {
				ans += min(s10, s20) + min(s11, s21);
				j = 0, s10 = 0, s20 = 0, s11 = 0, s21 = 0;
				continue;
			}
			if(s1[i - 1] == '0')s10++;else s11++;
			if(s2[i - 1] == '0')s20++;else s21++;
			if(i == n)ans += min(s10, s20) + min(s11, s21);
		} 
		cout << ans << '\n';
	}
	return 0;
} 
