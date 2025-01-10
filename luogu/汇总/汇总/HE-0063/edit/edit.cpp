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

char s1[N],s2[N],t1[N],t2[N];
 
signed main(){
	fire("edit");
	int T = read();
	while(T --){
		int s1_cnt1 = 0,s1_cnt2 = 0,s2_cnt1 = 0,s2_cnt2 = 0;
		int	cnt1_s1 = 0,cnt2_s1 = 0,cnt1_s2 = 0,cnt2_s2 = 0;
		int n = read(),ans = 0;
		 
		cin >> s1 >> s2 >> t1 >> t2;	
		
		for_(i,0,n-1){
			if(t1[i] == '0' && t2[i] == '0'){
				if(s1[i] == s2[i]) {
					ans ++; 
				}	
				if(i > 0){
					if(t1[i-1] != '0'){
						if(cnt2_s2 && s1_cnt2) {
							ans += min(cnt2_s2,s1_cnt2);
							s1_cnt2 -= min(cnt2_s2,s1_cnt2);
							cnt2_s2 = 0;
						} 
						if(cnt1_s2 && s1_cnt1) {
							ans += min(cnt1_s2,s1_cnt1);
							s1_cnt1 -= min(cnt1_s2,s1_cnt1);
							cnt1_s2 = 0;
						}
						if(s1_cnt1 && s2_cnt1) {
							int Min = min(s1_cnt1,s2_cnt1);
							ans += Min;
							s1_cnt1 -= Min;
							s2_cnt1 -= Min;
						}
						if(s1_cnt2 && s2_cnt2) {
							int Min = min(s1_cnt2,s2_cnt2);
							ans += Min;
							s1_cnt2 -= Min;
							s2_cnt2 -= Min;
						}
						s1_cnt1 = 0;
						s1_cnt2 = 0;
					}
					
					if(t2[i-1] != '0'){
						if(cnt2_s1 && s2_cnt2) {
							ans += min(cnt2_s1,s2_cnt2);
							s2_cnt2 -= min(cnt2_s1,s2_cnt2);
							cnt2_s1 = 0;
						} 
						if(cnt1_s1 && s2_cnt1) {
							ans += min(cnt1_s1,s2_cnt1);
							s2_cnt2 -= min(cnt2_s1,s2_cnt2);
							cnt1_s1 = 0;
						}
						if(s1_cnt1 && s2_cnt1) {
							int Min = min(s1_cnt1,s2_cnt1);
							ans += Min;
							s1_cnt1 -= Min;
							s2_cnt1 -= Min;
						}
						if(s1_cnt2 && s2_cnt2) {
							int Min = min(s1_cnt2,s2_cnt2);
							ans += Min;
							s1_cnt2 -= Min;
							s2_cnt2 -= Min;
						}
						s2_cnt1 = 0;
						s2_cnt2 = 0;
					}
				}
			}
			else if(t1[i] == '1' && t2[i] == '1'){ 
				if(s1[i] == s2[i]) {
					ans ++;
				}
				else {
					if(s1[i] == '0') s1_cnt1 ++;
					if(s1[i] == '1') s1_cnt2 ++;
					if(s2[i] == '0') s2_cnt1 ++;
					if(s2[i] == '1') s2_cnt2 ++;		
				}
				
				if(s1_cnt1 && s2_cnt1) {
					int Min = min(s1_cnt1,s2_cnt1);
					ans += Min;
					s1_cnt1 -= Min;
					s2_cnt1 -= Min;
				}
				if(s1_cnt2 && s2_cnt2) {
					int Min = min(s1_cnt2,s2_cnt2);
					ans += Min;
					s1_cnt2 -= Min;
					s2_cnt2 -= Min;
				}
			}
			
			else {
				if(t1[i] == '0'){
					if(s1[i] == s2[i]) ans ++;
					else{
						if(s1[i] == '1'){
							cnt2_s1 ++;
						}
						if(s1[i] == '0'){
							cnt1_s1 ++;
						}
						if(s2[i] == '0'){
							s2_cnt1 ++; 
						}  
						if(s2[i] == '1'){
							s2_cnt2 ++; 
						}
					} 
					
					if(i > 0){
						if(t1[i-1] != '0'){
							if(cnt2_s2 && s1_cnt2) {
								ans += min(cnt2_s2,s1_cnt2);
								s1_cnt2 -= min(cnt2_s2,s1_cnt2);
								cnt2_s2 = 0;
							} 
							if(cnt1_s2 && s1_cnt1) {
								ans += min(cnt1_s2,s1_cnt1);
								s1_cnt1 -= min(cnt1_s2,s1_cnt1);
								cnt1_s2 = 0;
							}
							if(s1_cnt1 && s2_cnt1) {
								int Min = min(s1_cnt1,s2_cnt1);
								ans += Min;
								s1_cnt1 -= Min;
								s2_cnt1 -= Min;
							}
							if(s1_cnt2 && s2_cnt2) {
								int Min = min(s1_cnt2,s2_cnt2);
								ans += Min;
								s1_cnt2 -= Min;
								s2_cnt2 -= Min;
							}
							s1_cnt1 = 0;
							s1_cnt2 = 0;
						}
					}
				}
				if(t2[i] == '0'){
					if(s1[i] == s2[i]) ans ++;
					else{
						if(s2[i] == '1'){
							cnt2_s2 ++;
						}
						if(s2[i] == '0'){
							cnt1_s2 ++;
						}
						if(s1[i] == '0'){
							s1_cnt1 ++; 
						}  
						if(s1[i] == '1'){
							s1_cnt2 ++; 
						}
					}
						 
					if(i > 0){
						if(t2[i-1] != '0'){
							if(cnt2_s1 && s2_cnt2) {
								ans += min(cnt2_s1,s2_cnt2);
								s2_cnt2 -= min(cnt2_s1,s2_cnt2);
								cnt2_s1 = 0;
							} 
							if(cnt1_s1 && s2_cnt1) {
								ans += min(cnt1_s1,s2_cnt1);
								s2_cnt1 -= min(cnt1_s1,s2_cnt1);
								cnt1_s1 = 0;
							}
							if(s1_cnt1 && s2_cnt1) {
								int Min = min(s1_cnt1,s2_cnt1);
								ans += Min;
								s1_cnt1 -= Min;
								s2_cnt1 -= Min;
							}
							if(s1_cnt2 && s2_cnt2) {
								int Min = min(s1_cnt2,s2_cnt2);
								ans += Min;
								s1_cnt2 -= Min;
								s2_cnt2 -= Min;
							}
							s2_cnt1 = 0;
							s2_cnt2 = 0;
						}
					}
				}
			}
		}
		writeln(ans);
	}
	
}

/*

这题肯定要挂分了，查不出来哪里挂分。 
 
破防。 

我到底学了点啥？

模拟赛最低的时候也没这么低过。

破防。 

明年再战。 

OI 是这样的，明明感觉 T2 T3 都差一点就会正解了，但是就是那一点完全想不出来，就这一点能害死我 

不想打暴力，分不可能够 

省队肯定进不了，我对我自己实力还是清楚的，我不可能翻进队里，那场 NOIP 打碎了我的省队梦（？

T2 T3 想不出来正解，T1 甚至也会随机挂分

没救了。

明年再战吧。

我明年真的还在 HE 吗？

不对，我还有明年吗？  

哦，我高一啊，那确实还有明年。

但是我还是不理解为什么考这么烂 

WC 肯定去不了，THUWC 和 PKUWC 更别想了，什么国赛再见，哈哈，明年再见吧

我到底怎么敢和他们说国赛再见的？ 
 
那我这个赛季结束了？省选没机会了 

破防。 

我还是不理解，我能在难度明显高于这场的模拟赛拿到高分，为什么不能在 NOIP 拿到高分。 

还是太菜了。 

明年再战。但是明年我就要去 TJOI 了，HEOI，再见。

最后一次在 HE 考试，画上的还是不圆满的句号啊...

再见，NOIP2024。

我会记住 NOIP2024 的。

算是一个很惨痛的教训吧。 

嗯哼，有史以来在正式比赛获得的最低分。

不对，体验名额打的也比这个高。

那应该说，有史以来最低分...

也算是罪有应得了？ 再颓废的话，或许明年会更差吧

Bad End 还是出现了...

可我的 HE 在哪里，HE 难道不应该给我一个 Happy End 吗

哎...

还是太菜了，还是太菜了啊... 
*/

