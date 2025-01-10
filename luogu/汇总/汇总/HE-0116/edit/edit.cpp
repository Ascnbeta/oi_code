#include<bits/stdc++.h>
using namespace std;
const int inf=1e5+10;
inline int read(){
	int x=0,f=1;
	char ch=getchar();
	while(ch<'0' || ch>'9'){
		if(ch=='-') f=-1;
		ch=getchar();
	}
	while(ch>='0' && ch<='9'){
		x=x*10+ch-'0';
		ch=getchar();
	}
	return x*f;
}
inline void write(int x){
	if(x<0) {
		cout<<'-';
		x=-x;
	}
	if(x>9) write(x/10);
	putchar(x%10+'0');
}
int t,n,ans;
char s1[inf],s2[inf];
char t1[inf],t2[inf];
signed main(){
	freopen("edit.in","r",stdin);
	freopen("edit.out","w",stdout);
	cin>>t;
	for(int k=1;k<=t;k++){
		cin>>n;
		for(int i=1;i<=n;i++)cin>>s1[i];
		for(int i=1;i<=n;i++)cin>>s2[i];
		for(int i=1;i<=n;i++)cin>>t1[i];
    	for(int i=1;i<=n;i++)cin>>t2[i];
    	int r1,r2;
		ans=0;
        bool flag=false;
    //    cout<<endl;
    	for(int i=1;i<=n;i++){
    	//	cout<<"i="<<i<<endl;
    		if(s1[i]!=s2[i]){
 			    r1=i+1;
 			    flag=false;
 			    while(t1[r1]-'0'==1 && r1<=n){
 			    	if(s1[r1]==s2[i]){
 			    		break;
					}
					r1++;
				}
				if(s1[r1]==s2[i] && t1[i]-'0'==1 && t1[r1]-'0'==1){
					ans++;
					swap(s1[i],s1[r1]);
					flag=true;
				}
				if(!flag){
					r2=i+1;	
					while(t2[r2]-'0'==1 && r2<=n){
 			         	if(s2[r2]==s1[i]){
 			        		break;
			    		}
			    		r2++;
		    		}
      				if(s2[r2]==s1[i] && t2[i]-'0'==1 && t2[r2]-'0'==1){
	    				ans++;
	    				swap(s2[i],s2[r2]);
		    			flag=true;
		    		}	
				}
    		}
			else ans++;
		//	cout<<r1<<" "<<r2<<endl;
    	//	for(int j=1;j<=n;j++) cout<<s1[j];
    	//	cout<<endl;
    	//	for(int j=1;j<=n;j++) cout<<s2[j];
    	//	cout<<endl<<endl;	
    	}
    	cout<<ans<<endl;
	}
     	
	
	return 0;
}
