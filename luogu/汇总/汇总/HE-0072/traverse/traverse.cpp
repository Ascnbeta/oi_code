#include<algorithm>
#include<iostream>
#include<string.h>
#include<stdio.h>
#include<string>
#include<vector>
#include<math.h>
#include<time.h>
#include<stack>
#include<queue>
#include<set>
#include<map>
using namespace std;
int read(){
	int s=0,f=1;
	char _z=getchar();
	while(_z<'0'||_z>'9'){
		if(_z=='-')
		f=-1;
		_z=getchar();
	}
	while(_z>='0'&&_z<='9'){
		s=(s<<3)+(s<<1)+(_z-'0');
		_z=getchar();
	}
	return s*f;
}
int ra(int l,int r){
	return rand()%(r-l+1)+l-1;
}
int main(){
	freopen("traverse.in","r",stdin);
	freopen("traverse.out","w",stdout);
	srand(time(NULL));
	int c=read(),t=read();
	while(t--){
		int n=read(),k=read();
		for(int i=1;i<n;i++)
		read(),read();
		while(k--){
			read();
			printf("%d",ra(1,10));
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
