#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
using namespace std;

int T, n, ans, num0[100005][2];
char s1[100005], s2[100005], t1[100005], t2[100005];
bool _0, _1;

int main(){
	freopen("edit.in", "r", stdin);
	freopen("edit.out", "w", stdout);
	cin >> T;
	while(T--){
		_0 = _1 = 1;
		ans = 0;
		scanf("%d %s %s %s %s", &n, s1 + 1, s2 + 1, t1 + 1, t2 + 1);
		if(t1 == t2){
			int last = 1;
			for(int i = 1; i <= n; i++){
				num0[i][0] = num0[i - 1][0] + (s1[i] == '0');
				num0[i][1] = num0[i - 1][1] + (s2[i] == '0');
				if(t1[i] == '0')ans += (s1[i] == s2[i]);
				if(t1[i] == '0' && t1[i - 1] == '1'){
					ans += min(num0[i - 1][0] - num0[last - 1][0], num0[i - 1][1] - num0[last - 1][1]) + min(i - last - num0[i - 1][0] + num0[last - 1][0], i - last - num0[i - 1][1] + num0[last - 1][1]);
				}
				if(t1[i] == '1' && t1[i - 1] == '0')last = i;
			}
			printf("%d\n", ans);
			continue;
		}
		for(int i = 1; i <= n; i++){
			if(s1[i] == '0')_1 = 0;
			else _0 = 0;
		}
		if(_1 || _0){
			for(int i = 1; i <= n; i++){
				if(_1)ans += s2[i] == '1';
				else ans += s2[i] == '0';
			}
			printf("%d\n", ans);
			continue;
		}
		for(int i = 1; i <= n; i++){
			if(t1[i - 1] == '0' && t1[i + 1] == '0')t1[i] = '0';
			if(t2[i - 1] == '0' && t2[i + 1] == '0')t2[i] = '0';
		}
		for(int i = 1; i <= n; i++){
			if(s1[i] == s2[i]){
				ans++;
				continue;
			}
			if(t1[i] == '0' && t2[i] == '0')continue;
			if(t1[i] == '1'){
				for(int j = i + 1; t1[j] == '1'; j++){
					if(s1[j] == s2[i]){
						swap(s1[i], s1[j]);
						break;
					}
				}
				if(s1[i] == s2[i]){
					ans++;
					continue;
				}
			}
			if(t2[i] == '1'){
				for(int j = i + 1; t2[j] == '1'; j++){
					if(s1[i] == s2[j]){
						swap(s2[i], s2[j]);
						break;
					}
				}
				if(s1[i] == s2[i])ans++;
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}
