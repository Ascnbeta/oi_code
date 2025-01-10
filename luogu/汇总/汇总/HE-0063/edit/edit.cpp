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

����϶�Ҫ�ҷ��ˣ��鲻��������ҷ֡� 
 
�Ʒ��� 

�ҵ���ѧ�˵�ɶ��

ģ������͵�ʱ��Ҳû��ô�͹���

�Ʒ��� 

������ս�� 

OI �������ģ������о� T2 T3 ����һ��ͻ������ˣ����Ǿ�����һ����ȫ�벻����������һ���ܺ����� 

����������ֲ����ܹ� 

ʡ�ӿ϶������ˣ��Ҷ����Լ�ʵ����������ģ��Ҳ����ܷ�������ǳ� NOIP �������ҵ�ʡ���Σ���

T2 T3 �벻�������⣬T1 ����Ҳ������ҷ�

û���ˡ�

������ս�ɡ�

��������Ļ��� HE ��

���ԣ��һ���������  

Ŷ���Ҹ�һ������ȷʵ�������ꡣ

�����һ��ǲ����Ϊʲô����ô�� 

WC �϶�ȥ���ˣ�THUWC �� PKUWC �������ˣ�ʲô�����ټ��������������ټ���

�ҵ�����ô�Һ�����˵�����ټ��ģ� 
 
����������������ˣ�ʡѡû������ 

�Ʒ��� 

�һ��ǲ���⣬�������Ѷ����Ը����ⳡ��ģ�����õ��߷֣�Ϊʲô������ NOIP �õ��߷֡� 

����̫���ˡ� 

������ս�����������Ҿ�Ҫȥ TJOI �ˣ�HEOI���ټ���

���һ���� HE ���ԣ����ϵĻ��ǲ�Բ���ľ�Ű�...

�ټ���NOIP2024��

�һ��ס NOIP2024 �ġ�

����һ���ܲ�ʹ�Ľ�ѵ�ɡ� 

�źߣ���ʷ��������ʽ������õ���ͷ֡�

���ԣ�����������Ҳ������ߡ�

��Ӧ��˵����ʷ������ͷ�...

Ҳ��������Ӧ���ˣ� ���ǷϵĻ����������������

Bad End ���ǳ�����...

���ҵ� HE �����HE �ѵ���Ӧ�ø���һ�� Happy End ��

��...

����̫���ˣ�����̫���˰�... 
*/

