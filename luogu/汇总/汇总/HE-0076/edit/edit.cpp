#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<climits>
using namespace std;
template <typename T>
inline void read(T&x){
	int w = 0;x = 0;
	char ch = getchar();
	while(ch<'0' || ch>'9'){
		if(ch=='-') w = 1;
		ch = getchar();
	}
	while(ch>='0' && ch<='9'){
		x = (x<<1)+(x<<3)+(ch^48);
		ch = getchar();
	}
	if(w) x = -x; 
}
template <typename T,typename...Args>
inline void read(T&t,Args&...args){
	read(t);read(args...);
}
const int N = 1e5+10;
int s1[N],s2[N],t1[N],t2[N];
int n;
int fa,ansA,fb;
int b1[N]={0},b2[N]={0},idx1,idx2;
inline void Init(){
	read(n);
	fb = fa = 1;ansA = idx1 = idx2 = 0;
	int f1 = 0;
	for(int i=1;i<=n;++i){
		scanf("%1d",&s1[i]);
		if(i==1) f1 = s1[i];
		else{
			if(s1[i]!=f1) fa = 0;
		}
	}
	for(int i=1;i<=n;++i){
		scanf("%1d",&s2[i]);
		if(s2[i]==f1) ++ansA;
	} 
	for(int i=1;i<=n;++i){
		scanf("%1d",&t1[i]);
		if(t1[i]==0) b1[++idx1] = i;
	}
	for(int i=1;i<=n;++i){
		scanf("%1d",&t2[i]);
		if(t2[i]==0) b2[++idx2] = i;
		if(t2[i]!=t1[i]) fb = 0;
	}
	b1[idx1+1]  =b2[idx2+1]  =n+1;
}
inline void solveB(){//t1=t2
	int ans = 0,num10,num20,num11,num21;
	for(int i=0;i<=idx1;++i){
		num10 = num20 = num11  = num21 = 0;
		for(int l=b1[i]+1;l<b1[i+1];++l){
			num11 += s1[l]; num10 += !s1[l];
			num21 += s2[l]; num20 += !s2[l];
		}
		ans += min(num11,num21)+min(num10,num20);
		if(s1[b1[i+1]]==s2[b1[i+1]]) ++ans;
	}
	printf("%d\n",ans);
}
int tmp1[N],tmp2[N];
inline void solve0(){
	int ans = 0;
	for(int s=0;s<(1<<(n-1));++s){
		for(int t=0;t<(1<<(n-1));++t){
			int num = 0;
			for(int i=1;i<=n;++i) tmp1[i] = s1[i],tmp2[i] = s2[i];
			for(int i=1;i<n;++i){
				if((s>>(i-1))&1 && t1[i]==1 && t1[i+1]==1){
					swap(tmp1[i],tmp1[i+1]);
				}
				if((t>>(i-1))&1 && t2[i]==1 && t2[i+1]==1){
					swap(tmp2[i],tmp2[i+1]);
				}
			}
			for(int i=1;i<=n;++i) if(tmp1[i]==tmp2[i]) ++num;
			ans = max(ans,num);
		}
	}
	printf("%d\n",ans);
}
//inline void debug(){
//	cout << endl;
//	for(int i=1;i<=n;++i) cout << s1[i];
//	cout << endl;
//	for(int i=1;i<=n;++i) cout << s2[i];
//	cout << endl;
//}

int main(){
	freopen("edit.in","r",stdin);
	freopen("edit.out","w",stdout);

	int T;read(T);
	while(T--){
		Init();
		
//		debug();
		
		if(fa){
			printf("%d\n",ansA);
			continue;
		}
		if(fb){
			solveB();
			continue;
		}
		if(n<=10){
			solve0();
			continue;
		}
		for(int i=1;i<=idx1;++i){
//			cout << b1[i] << " ";
			if(b1[i-1]+1==b1[i]) continue;
			sort(s1+b1[i-1]+1,s1+b1[i]+1);
		}
		if(b1[idx1]!=n && b1[idx1]!=n-1) sort(s1+b1[idx1]+1,s1+n+1);
		for(int i=1;i<=idx2;++i){
//			cout << b2[i] << " ";
			if(b2[i-1]+1==b2[i]) continue;
			sort(s2+b2[i-1]+1,s2+b2[i]+1);
		}
		if(b2[idx2]!=n && b2[idx2]!=n-1) sort(s2+b2[idx2]+1,s2+n+1);
		int ans = 0;
		for(int i=1;i<=n;++i) if(s1[i]==s2[i]) ++ans;
		printf("%d\n",ans);
		
//		debug();
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
