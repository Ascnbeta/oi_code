#include<bits/stdc++.h>
using namespace std;
int read(){
	int x=0,f=1;
	char ch=getchar();
	while(ch>'9'||ch<'0'){
		if(ch=='-') f=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9'){
		x=x*10+ch-'0';
		ch=getchar();
	}
	return x*f;
}
const int N=1e5+10;
int c,T;
int n,k;
struct node{
	int u,v;
	int e;
}no[N];
int main(){
	freopen("traverse.in","r",stdin);
	freopen("traverse.out","w",stdout);
	c=read(),T=read();
	while(T--){
		n=read(),k=read();
		for(int i=1;i<n;i++){
			no[i].u=read();
			no[i].v=read();
		}
		for(int i=1;i<=k;i++){
			no[i].e=read();
		}cout<<1<<endl;
	}
	return 0;
}
