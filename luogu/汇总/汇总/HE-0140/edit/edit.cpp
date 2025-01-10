#include<iostream>
#include<string.h>
#include<algorithm>
using namespace std;
#define endl '\n'
#define m(a) memset(a , 0 , sizeof(a))

const int N = 1e5 + 5;
typedef long long ll;

struct Node{
	ll val , f;
}a[N] , b[N];

struct Nod{
	ll l , r , num;
	ll f;
}c[N] , c1[N] , c2[N];

struct H{
	ll l , r;
}ans[N] , ad[N];

ll T , n;
ll as1[N] , as0[N] , bs1[N] , bs0[N];

inline bool cmp(Nod x , Nod y){
	if(x.l == y.l)
		return x.r < y.r;
	else
		return x.l < y.l;
}

int main(){
	freopen("edit.in" , "r" , stdin);
	freopen("edit.out" , "w" , stdout);
	cin >> T;
	while(T --){
		cin >> n;
		getchar();
		for(int i = 1 ;i <= n; i ++){
			a[i].val = getchar() - '0';
			if(a[i].val == 1)
				as1[i] = as1[i - 1] + 1; 
			else
				as1[i] = as1[i - 1];
		}
		getchar();
		for(int i = 1 ;i <= n; i++){
			b[i].val = getchar() - '0';
			if(b[i].val == 1)
				bs1[i] = bs1[i - 1] + 1; 
			else
				bs1[i] = bs1[i - 1]; 
		}
		
		for(int i = 1 ;i <= n; i ++){
			as0[i] = i - as1[i] , bs0[i] = i - bs1[i];
		}
		
		getchar();
		for(int i = 1 ;i <= n; i ++){
			a[i].f = getchar() - '0';
		}
		getchar();
		for(int i = 1 ;i <= n; i++){
			b[i].f = getchar() - '0';
		}
		
		m(a) , m(b) , m(c) , m(c1) , m(c2) , m(ans) , m(ad) , m(as1) , m(as0) , m(bs1) , m(bs0);
		
		ll id = 1;
		c1[1].l = 1;
		for(int i = 1 ; i <= n; i ++){//get a[] qvjian
			if(a[i].f == 0){
				if(i - 1 > c1[id].l){
					c1[id].r = i - 1;
					c1[++ id].l = i + 1;
				}
				c1[id].l = i + 1;
			}
			if(i == n && i - c1[id].l >= 1){
				c1[id].r = i;
				break;
			}
		}
		if(c1[id].l > c1[id].r){
			c1[0].num = id - 1;
		}
		else{
			c1[0].num = id;
		}
		
		id = 1;
		c2[1].l = 1;
		for(int i = 1 ; i <= n; i ++){//get b[] qvjian
			if(b[i].f == 0){
				if(i - 1 > c2[id].l){
					c2[id].r = i - 1;
					c2[++ id].l = i + 1;
				}
				c2[id].l = i + 1;
			}
			if(i == n && i - c2[id].l >= 1){
				c2[id].r = i;
				break;
			}
		}
		if(c2[id].l > c2[id].r){
			c2[0].num = id - 1;
		}
		else{
			c2[0].num = id;
		}
		
		for(int i = 1 ;i <= c1[0].num ; i ++){
			c[i].l = c1[i].l , c[i].r = c1[i].r;
		}
		ll idx = 0;
		for(int i = c1[0].num + 1 ; i <= c1[0].num + c2[0].num ; i ++){
			c[i].l = c2[++ idx].l , c[i].r = c2[idx].r;
		}
		sort(c + 1 , c + c1[0].num + c2[0].num + 1 , cmp);
		ll le = c[1].l , ri = c[1].r , t = 0;
		for(int i = 2 ; i <= c1[0].num + c2[0].num + 1;i ++){
			if(ri >= c[i].l && le <= c[i].l){
				ri = max(c[i].r , ri);
				if(ri == n){
					ans[++ t].l = le , ans[t].r = ri;
					break;
				}
			}
			else{
				ans[++ t].l = le , ans[t].r = ri;
				le = c[i].l , ri = c[i].r;
			}
		}
		ll ix = 1;
		ad[1].l = 1; 
		for(int i = 1 ;i <= t + 1; i ++){
			ad[ix].r = ans[i].l - 1;
			if(i > t){
				ad[ix].r = n;
				break;
			}
			if(ad[ix].r < 1){
				ix --;
			}
			ad[++ ix].l = ans[i].r + 1;
			if(ad[ix].l > n){
				ix --;
				break;
			}
		}
		ll an = 0;
		for(int i = 1 ;i <= t ; i ++){
			an += min(as1[ans[i].r] - as1[ans[i].l - 1] , bs1[ans[i].r] - bs1[ans[i].l - 1]) + min(as0[ans[i].r] - as0[ans[i].l - 1] , bs0[ans[i].r] - bs0[ans[i].l - 1]);
		}
		for(int i = 1 ;i <= ix ; i ++){
			for(int j = ad[i].l ; j <= ad[i].r ; j ++){
				if(a[j].val == b[j].val)
					an ++;
			}
		}
		cout << an << endl;
	} 
	return 0;
}
