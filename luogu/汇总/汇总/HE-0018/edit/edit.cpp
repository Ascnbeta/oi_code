#include<bits/stdc++.h>

using namespace std;

const int N = 1e5 + 10;
int n , ans;
int c[4][N]; string s[4];
int sum[2][2];
int J(int x , int i) {
	if(c[x + 2][i]) 
		while(i <= n && c[x + 2][i]) {
			sum[x][c[x][i]] ++; i ++;
		}
	else {
		sum[x][c[x][i]] ++; i ++;
	}
	return i;
}
void solve() {
	ans = 0;
	int i = 0 , j = 0 , ii = 1 , jj = 1; 
	sum[0][0] = sum[0][1] = sum[1][0] = sum[1][1] = 0;
	while(ii <= n || jj <= n) {
		if(ii == jj) {
			sum[0][0] = sum[0][1] = 0; sum[1][0] = sum[1][1] = 0;
			i = ii; ii = J(0 , ii); j = jj; jj = J(1 , jj);
		}
		else if(ii < jj) {
			sum[0][0] = sum[0][1] = 0;
			i = ii; ii = J(0 , ii);
		}
		else {
			sum[1][0] = sum[1][1] = 0;
			j = jj; jj = J(1 , jj);
		}
		int Ma = min(ii , jj) - max(i , j);
		int Mi = min(sum[0][0] , sum[1][0]);
		if(Mi > Ma) {
			ans += Ma; sum[0][0] -= Ma; sum[1][0] -= Ma;
			continue;
		}
		ans += Mi; sum[0][0] -= Mi; sum[1][0] -= Mi;
		Mi = min(sum[0][1] , sum[1][1]);
		if(Mi > Ma) {
			ans += Ma; sum[0][1] -= Ma; sum[1][1] -= Ma;
			continue;
		}
		ans += Mi; sum[0][1] -= Mi; sum[1][1] -= Mi;
	}
	printf("%d\n",ans);
}
void cl(int x) {
	for(int i = 1;i <= n;i ++) c[x][i] = s[x][i - 1] - '0';
}

int main() {
	freopen("edit.in","r",stdin);
	freopen("edit.out","w",stdout);
	int t; cin >> t;
	while(t --) {
		scanf("%d",&n);
		cin >> s[0] >> s[1] >> s[2] >> s[3];
		cl(0); cl(1); cl(2); cl(3);
		solve();
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
/*
1 6 011101
111010
111010
101101

1 4
0011 
1110
0011
1110
*/
