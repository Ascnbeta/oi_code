#include<bits/stdc++.h>
#define int long long
#define for_(i,a,b) for(int i=a;i<=b;i++)
#define _for(i,a,b) for(int i=a;i>=b;i--)
#define fireIN(data) freopen(data".in","r",stdin)
#define fireOUT(data) freopen(data".out","w",stdout)
#define fire(data) fireIN(data),fireOUT(data) 
using namespace std;

namespace IO{
	inline int read(){
		int f=1,s=0;
		char ch = getchar();
		while('0'>ch||ch>'9'){
			if(ch == '-'){
				f = -1;
			}
			ch = getchar();
		}
		while('0'<=ch&&ch<='9'){
			s = s * 10 + ch - '0';
			ch = getchar();
		}
		return s * f;
	}
	inline void write(int x){
		if(x < 0) {
			putchar ('-');
			x = -x;
		}
		if(x < 10) putchar (x + '0');
		else {
			write(x/10);
			putchar(x%10 + '0');
		}
	}
	inline void writeln(int x){
		write(x);
		puts("");
	}
}
using namespace IO;

const int N = 0x66CCFF;
const int inf = LLONG_MAX;

signed main(){
	fire("query");
	
}
/*
完全看不懂，会 8 分。 
 
开考的时候有多自信，摔得就有多惨

我的渴望转啊转啊，我的悔恨转啊转啊

我仍坚信我已坍塌，坍塌在她的废墟下
*/
