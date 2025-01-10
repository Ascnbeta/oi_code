#include<bits/stdc++.h>
using namespace std;
int T;
long long sum=0;
int n;
int compare(string a,string t,int b){
		if(b>=n-1){
			return 0;
		}
		if(t[b]=='0'||t[b+1]=='0'){
			return 0;
		}
		else if(a[b]==a[b+1]){
			return compare(a,t,b+1);
		}
		else if(a[b]!=a[b+1]){
			return b+1;
		}
}
int main(){
	freopen("edit.in","r",stdin);
	freopen("edit.out","w",stdout);
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		sum=0;
		string sa;
		string sb;
		string ta;
		string tb;
		cin>>sa>>sb>>ta>>tb;
		for(int i=0;i<n;i++){
			if(sa[i]==sb[i]){
				sum+=1;
			}
			else{
				int q,p;
				q=compare(sa,ta,i);
				if(q!=0){
					int x;
					x=sa[i];
					sa[i]=sa[q];
					sa[q]=x;
					sum+=1;
				}
				else{
					p=compare(sb,tb,i);
					if(p!=0){
					int x;
					x=sb[i];
					sb[i]=sb[p];
					sb[p]=x;
					sum+=1;
					}		
				}
			}
		}
		printf("%d \n",sum);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
