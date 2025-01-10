#include<bits/stdc++.h>
using namespace std;
const int N=1e6+10;
int T;

int arr[N];

long long n,m,v;

int main(){
	freopen("assign.in","r",stdin);
	freopen("assign.out","w",stdout);
	cin>>T;
	
	while(T--){
		
		int t=0;
		scanf("%d %d %d",&n,&m,&v);
		
		for(int i=0;i<m;i++){
			int x,y;
			cin>>x>>y;
			if(arr[x-1]==0){
				arr[x-1]=y;
			}
			else if(y!=arr[x-1]){
				cout<<"0"<<endl;
				t+=1;
				break;
			}
		}
		if(t==0){
			long long sum=v*v;
			for(int i=0;i<n;i++){
				for(int a=1;a<=v;a++){
					if(arr[i]==a){
						for(int b=1;b<=v;b++){
							if(arr[i+1]!=b&&arr[i+1]!=0){
								sum=sum-1;
							}
						}
					}
				}
			}
			long long ret=sum%1000007;
			if(ret<0){
				cout<<"0"<<endl;
			}
			else{
				cout<<ret<<endl;
			}
			
			sum=0;
		}
		for(int i=0;i<n;i++){
			arr[i]=0;
		}
		
		
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
