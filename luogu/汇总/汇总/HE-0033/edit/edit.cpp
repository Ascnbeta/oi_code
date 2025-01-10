#include<bits/stdc++.h>
using namespace std;

int read(){
	int x=0,f=1;char ch=getchar();
	while(ch>'9'||ch<'0') {
		if(ch=='-') f=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9') x=x*10+ch-'0',ch=getchar();
	return x*f;
}
const int N=1e5+10;
struct node{
	int len,val;
}d1[N],d2[N];
int id1[N],id2[N];

int s1[N],s2[N];
int vis1[N],vis2[N];
void init(){
	memset(d1,0,sizeof d1);
	memset(d2,0,sizeof d2);
	memset(id1,0,sizeof id1);
	memset(id2,0,sizeof id2);
}
int f[N];
int main(){
	freopen("edit.in","r",stdin);
	freopen("edit.out","w",stdout);
	int T=read();
	while(T--){
		init();
		int n=read();
		for(int i=1;i<=n;i++){
			scanf("%1d",&s1[i]);
		}
		for(int i=1;i<=n;i++){
			scanf("%1d",&s2[i]);
		}
		int cnt=1,num=0,len=0;
		for(int i=1;i<=n;i++){
			scanf("%1d",&vis1[i]);
			if(vis1[i]){
				num+=s1[i],len++;
				id1[i]=cnt;
			}
			if((!vis1[i]||i==n)&&len){
				d1[cnt].len=len,d1[cnt].val=num;
				len=0,num=0;
				cnt++;
			}
		}
		cnt=1,num=0,len=0;
		for(int i=1;i<=n;i++){
			scanf("%1d",&vis2[i]);
			if(vis2[i]){
				num+=s2[i],len++;
				id2[i]=cnt;
			}
			if((!vis2[i]||i==n)&&len){
				d2[cnt].len=len,d2[cnt].val=num;
				len=0,num=0;
				cnt++;
			}
		}
		for(int i=1;i<=n;i++){
			f[i]=f[i-1];
//			cout<<i<<" "<<d1[id1[i]].len<<endl;
			if(vis1[i]&&vis2[i]){
				if(d1[id1[i]].val>=1&&d2[id2[i]].val>=1){
					d1[id1[i]].val--,d2[id2[i]].val--;
					d1[id1[i]].len--,d2[id2[i]].len--;
					f[i]++;
				}else if(d1[id1[i]].val>=1&&d2[id2[i]].val==0){
//					puts("op0");
					if(d1[id1[i]].len>d1[id1[i]].val){
						d1[id1[i]].len--,d2[id2[i]].len--;
						f[i]++;
					}
					
				}else if(d1[id1[i]].val==0&&d2[id2[i]].val>=1){
//					puts("JKOL");
					if(d2[id2[i]].len>d2[id2[i]].val){
						d1[id1[i]].len--,d2[id2[i]].len--;
						f[i]++;
					}
				}else if(d1[id1[i]].val==0&&d2[id2[i]].val==0){
					d1[id1[i]].len--,d2[id2[i]].len--;
					f[i]++;
				}
			}else if(vis1[i]&&!vis2[i]){
				if(s2[i]==1){
					if(d1[id1[i]].val>=1){
						d1[id1[i]].val--;
						d1[id1[i]].len--;
						f[i]++;
					}
				}else{
					if(d1[id1[i]].len>d1[id1[i]].val){
						d1[id1[i]].len--;
						f[i]++;
					}
				}
				
			}else if(vis2[i]&&!vis1[i]){
				if(s1[i]==1){
					if(d2[id2[i]].val>=1){
						d2[id2[i]].val--;
						d2[id2[i]].len--;
						f[i]++;
					}
				}else{
//					cout<<"ppp:";
//					cout<<d2[id2[i]].len<<" "<<d2[id2[i]].val<<endl;
					if(d2[id2[i]].len>d2[id2[i]].val){
						d2[id2[i]].len--;
						f[i]++;
					}
				}
			}else{
				if(s1[i]==s2[i]) f[i]++;
			}
		}
//		for(int i=1;i<=n;i++){
//			printf("%lld\n",f[i]);
//		}
		printf("%d\n",f[n]);
	}
	return 0;
}
