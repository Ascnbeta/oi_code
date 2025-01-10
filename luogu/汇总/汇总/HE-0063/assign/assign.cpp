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
	fire("assign");
	
}
/*
完全不想写...没机会了，只会60分暴力，不想写暴力 

呜...考的很低啊... 

再见，NOIP2024

再也不在 HL 群里面说批话了，批话成真了 

破防。 

为了防止看起来太少在这里瞎写点吧 
*/

/*
蝉时雨，化作墨痕渲染暮色

渗透着，勾勒出足迹与车辙

欢笑声，与漂泊的水汽饱和

隔着窗，同城市一并模糊了

拨弄着，旧吉他，哼着四拍子的歌

回音中，一个人，仿佛颇悠然自得 

等凉雨，的温度，将不安燥热中和
 
寻觅着，风的波折 

我仍然在，无人问津的阴雨霉湿之地 

和着雨音，唱着没有人听的歌曲 
*/
