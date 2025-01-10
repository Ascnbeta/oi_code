#include <iostream>
#include <cstring>
#include <cstdio>
#include <vector>

const int N = 1e5 + 10;
int n, ans, cnt00, cnt01, cnt10, cnt11;
int vec1[N], vec2[N], cnt1, cnt2;
char s1[N], s2[N], t1[N], t2[N];

void work () {
	bool flag = false;
	if (cnt00 + cnt01 == cnt10 + cnt11) flag = true;
	
	if (cnt00 + cnt01 > cnt10 + cnt11) {
		int opt0 = std::min(cnt00, cnt10), opt1 = std::min(cnt01, cnt11);
		ans += opt0 + opt1;
		cnt00 -= opt0; cnt10 -= opt0;
		cnt01 -= opt1; cnt11 -= opt1;	
		cnt00 -= cnt11; cnt01 -= cnt10;
	} else {
		int opt0 = std::min(cnt00, cnt10), opt1 = std::min(cnt01, cnt11);
		ans += opt0 + opt1;
		cnt00 -= opt0; cnt10 -= opt0;
		cnt01 -= opt1; cnt11 -= opt1;
		cnt10 -= cnt01; cnt11 -= cnt00;
	}
	
	if (flag) cnt00 = cnt01 = cnt10 = cnt11 = 0;
}

void Main() {
	cnt1 = cnt2 = ans = 0;
	std::cin >> n;
	std::cin >> (s1 + 1) >> (s2 + 1) >> (t1 + 1) >> (t2 + 1);
	for (int i = 1; i <= n; i++) {
		if (t1[i] == '0') vec1[++cnt1] = i;
		if (t2[i] == '0') vec2[++cnt2] = i;
	}
	vec1[++cnt1] = n + 1; vec2[++cnt2] = n + 1; 
	cnt00 = cnt01 = cnt10 = cnt11 = 0;
	int now1 = 0, now2 = 0, h1 = 1, h2 = 1;
	while (now1 < n || now2 < n) {
		if (cnt00 + cnt01 == 0 && now1 == vec1[h1 - 1]) {
			while (now1 < vec1[h1] - 1) {
				now1++;
				if (s1[now1] == '0') cnt00++;
				else cnt01++;
			} h1++;
		}
		if (cnt10 + cnt11 == 0 && now2 == vec2[h2 - 1]) {
			while (now2 < vec2[h2] - 1) {
				now2++;
				if (s2[now2] == '0') cnt10++;
				else cnt11++;
			} h2++;
		}
		if (now1 > now2) {
			now2++;
			if (s2[now2] == '0') cnt10++;
			else cnt11++;
			work(); 
		} else if (now1 < now2) {
			now1++;
			if (s1[now1] == '0') cnt00++;
			else cnt01++;
			work(); 
		} else {
			work();
			now1++, now2++;
			if (now1 <= n) ans += (s1[now1] == s2[now2] ? 1 : 0);
		}
	}
	if (now1 == n && now2 != n) {
		while (now2 < n) {
			now2++;
			if (s2[now2] == '0') cnt10++;
			else cnt11++;
		}
		work();
	}
	if (now2 == n && now1 != n) {
		while (now1 < n) {
			if (s1[now1] == '0') cnt00++;
			else cnt01++;	
		}
		work();
	}
	std::cout << ans << '\n';
}

int main() {
	freopen("edit.in", "r", stdin);
	freopen("edit.out", "w", stdout);
	int T = 1;
	std::cin >> T; 
	while (T--) Main();
	return 0;
} 
