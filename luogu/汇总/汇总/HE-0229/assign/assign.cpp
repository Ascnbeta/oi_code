#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>
using namespace std;

int mod = 1000000007;
int T, n, m, v, a[1000005], b[1000005];
long long ans;

void dfs(int step){
	if(step == n){
		ans++;
		return;
	}
	for(int i = 1; i <= v; i++){
		for(int j = 1; j <= v; j++){
			if((a[step] == i || b[step] == i)&& a[step + 1] != 0 && a[step + 1] != j)continue;
			if(a[step] == i || b[step] == i)b[step + 1] = j;
			dfs(step + 1);
			if(a[step] == i || b[step] == i)b[step + 1] = 0;
		}
	}
	return;
}

bool A;

int main(){
	freopen("assign.in", "r", stdin);
	freopen("assign.out", "w", stdout);
	scanf("%d", &T);
	while(T--){
		ans = 0;
		bool f = 0;
		A = 1;
		memset(a, 0, sizeof a);
		scanf("%d %d %d", &n, &m, &v);
		if(m != n)A = 0;
		for(int i = 1; i <= m; i++){
			int c, d;
			scanf("%d %d", &c, &d);
			if(c != i)A = 0;
			if(a[c] != 0 && a[c] != d)f = 1;
			a[c] = d;
		}	
		if(f){
			printf("0\n");
			continue;
		}
		if(n <= 12 && v <= 2){
			dfs(1);
			printf("%lld\n", ans);
			continue;
		}
		if(A){
			
			continue;
		}
	}
	return 0;
}
