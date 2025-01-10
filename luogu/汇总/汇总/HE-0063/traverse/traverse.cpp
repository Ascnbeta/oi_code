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
	fire("traverse");
	
}
/*
不想回归文化课

但是没机会了 

只会 64 分暴力，不想写暴力。

这题说不定还会卡常，说不定 64 都没有

不写了，破防。 
*/
