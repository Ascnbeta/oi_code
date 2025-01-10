#include <bits/stdc++.h>
const int maxn = 1e6;
using namespace std;
int T , n;
char a[maxn],b[maxn],t1[maxn],t2[maxn];
int sum1[maxn] , sum2[maxn] , bo[maxn];
void solve1() {
	
}
void solve2() {
	int an = 0;
	for(int i=1;i<=n;++i) {
		if(bo[i] == 1) {
			int x = n; 
			for(int j=i+1;j<=n;++j) {
				if(bo[j] == 0) {
					x = j - 1;
					break;
				}
			}
			an += min(sum1[x]-sum1[i-1],sum2[x]-sum2[i-1]) + (x-i+1) - max(sum1[x]-sum1[i-1],sum2[x]-sum2[i-1]);
			i = x;
		}
		else {
			int x = n; 
			for(int j=i;j<=n;++j) {
				if(bo[j] == 1) {
					x = j - 1;
					break;
				}
				else if(bo[j] == 0) {
					if(a[j] == b[j]) an ++;
				}
			}
			i = x;
		}
	}
	cout << an << endl;
}
void solve3() {
	int tag1 = 0 ,tag2 = 0, an = 0;
	for(int i=1;i<=n;++i) {
		if(t1[i] == '0') tag1 = i;
		else tag2 = i;
	}
	if(tag1 == tag2) {
		an += min(sum1[tag1-1]-sum1[0],sum2[tag1-1]-sum2[0]) + tag1- 1 - max(sum1[tag1-1]-sum1[0],sum2[tag1-1]-sum2[0]);
		an += min(sum1[n]-sum1[tag1],sum2[n]-sum2[tag1]) + n - tag1 - max(sum1[n]-sum1[tag1],sum2[n]-sum2[tag1]);
		if(a[tag1] == b[tag1]) an ++;
	}
	else  {
		an += min(sum1[n]-sum1[0],sum2[n]-sum2[0]) + n - max(sum1[n]-sum1[0],sum2[n]-sum2[0]);
	}
	cout << an << endl;
}
int main()
{
	freopen("edit.in","r",stdin);
	freopen("edit.out","w",stdout);
	cin >> T;
	while(T --) {
		cin >> n;
		bool qp = 0 ,qb = 0;
		for(int i=1;i<=n;++i) {
			cin >> a[i];
			if(a[i] == '1') sum1[i] = sum1[i-1] + 1;
			else sum1[i] = sum1[i-1];
			if(a[i] == '0') qp = 1;
			else qb = 1;
		}
		for(int i=1;i<=n;++i) {
			cin >> b[i];
			if(b[i] == '1') sum2[i] = sum2[i-1] + 1;
			else sum2[i] = sum2[i-1];
		}
		int ana = 0 ,ans = 0;
		for(int i=1;i<=n;++i) {
			cin >> t1[i];
			bo[i] = t1[i] - '0';
			if(t1[i] == '0') ana ++;
		}
		bool w = 0;
		for(int i=1;i<=n;++i) {
			cin >>t2[i];
			if(t1[i] != t2[i]) w = 1;
			if(t2[i] == '0') ans ++;
		}
		if(qp == 0) {
			cout <<sum2[n] <<endl;
			continue;
		}
		if(qb == 0) {
			cout << n - sum2[n] << endl;
			continue;
		}
		if(w == 0) solve2();
		else if(ans == 1 and ana == 1) solve3();
		else solve2();
	}
}
