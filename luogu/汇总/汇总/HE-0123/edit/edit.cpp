#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int T,n;
int a[100010];
int b[100010];
int t1[100010];
int t2[100010];

void pta(){
  for(int i=1;i<=n;i++){cout<<a[i]<<" ";}
  cout<<endl;
}
void ptb(){
  for(int i=1;i<=n;i++){cout<<b[i]<<" ";}
  cout<<endl;
}
void pt1(){
  for(int i=1;i<=n;i++){cout<<t1[i]<<" ";}
  cout<<endl;
}
void pt2(){
  for(int i=1;i<=n;i++){cout<<t2[i]<<" ";}
  cout<<endl;
}

void work(){
  
bool flag1=0;//s1 A
bool flag2=0;//t1 t2 B
bool flag3=0;//0  0 C

  int t10;
  int t20;
  scanf("%d",&n);
  int temp;
  char tc;
  tc=getchar();
  for(int i=1;i<=n;i++){
  	char c;
  	c=getchar();
	a[i]=c-'0';
	if(i>1&&a[i]!=temp){flag1=1;}//判断特殊性质A 
	temp=a[i];
  }
  tc=getchar();
  for(int i=1;i<=n;i++){
  	char c;
  	c=getchar();
    b[i]=c-'0';
  }
  
  tc=getchar();
  temp=0;
  for(int i=1;i<=n;i++){
  	char c;
  	c=getchar();
  	t1[i]=c-'0';
    if(t1[i]==0){temp++;
    t10=i;}
  }
  if(temp!=1)flag3=1;//判断特殊性质C
  
  tc=getchar();
  temp=0;
  for(int i=1;i<=n;i++){
    char c;
  	c=getchar();
  	t2[i]=c-'0';
    if(t2[i]==0){temp++;
    t20=i;}
  }
  if(temp!=1)flag3=1;//判断特殊性质C
  
  for(int i=1;i<=n;i++){
    if(t1[i]!=t2[i]){flag2=1;}//判断特殊性质B
  }
  /*
  pta();
  ptb();
  pt1();
  pt2();
  cout<<"t10:"<<t10<<endl;
  cout<<"t20:"<<t20<<endl;
  */
  
  if(flag1==0){
    int ans=0;
	for(int i=1;i<=n;i++){
	  if(b[i]==a[1])ans++;
	}
	cout<<ans<<endl;  
  }
  else if(flag2==0){
  	int temp1=1;
    for(int i=1;i<=n;i++){
      int temp2=i;
	  if(t1[i]!=1){
	  	if(temp2>temp1){
	      sort(a+temp1,a+temp2);
	      sort(b+temp1,b+temp2);
	    }
	  temp1=i+1;
	  }
	}
	int ans=0;
	for(int i=1;i<=n;i++){
	  if(a[i]==b[i])ans++;
	}
	cout<<ans<<endl;
  }
  else if(flag3==0){
  	int a1l=0,a0l=0,a1r=0,a0r=0;
  	int b1l=0,b0l=0,b1r=0,b0r=0;
    for(int i=1;i<t10;i++){if(a[i]==1)a1l++;if(a[i]==0)a0l++;}
    for(int i=t10+1;i<=n;i++){if(a[i]==1)a1r++;if(a[i]==0)a0r++;}
    for(int i=1;i<t20;i++){if(b[i]==1)b1l++;if(b[i]==0)b0l++;}
    for(int i=t20+1;i<=n;i++){if(b[i]==1)b1r++;if(b[i]==0)b0r++;}
    int a1m=0,a0m=0;
    int b1m=0,b0m=0;
    int ans=0;
    if(t10<t20){
	  if(b1l>=a1l){b1m=b1l-a1l;ans+=a1l;}
	  if(b0l>=a0l){b0m=b0l-a0l;ans+=a0l;}
	  if(a1r>=b1r){a1m=a1r-b1r;ans+=b1r;}
	  if(a0r>=b0r){a0m=a0r-b0r;ans+=b0r;}
	}
	if(t10>t20){
	  if(a1l>=b1l){a1m=a1l-b1l;ans+=b1l;}
	  if(a0l>=b0l){a0m=a0l-b0l;ans+=b0l;}
	  if(b1r>=a1r){b1m=b1r-a1r;ans+=a1r;}
	  if(b0r>=a0r){a0m=b0r-a0r;ans+=a0r;}
	}
	//cout<<t10<<" "<<t20<<endl;
	//cout<<"a1l:"<<a1l<<" a1r:"<<a1r<<" b1l:"<<b1l<<" b1r:"<<b1r<<endl;
	//cout<<"a0l:"<<a0l<<" a0r:"<<a0r<<" b0l:"<<b0l<<" b0r:"<<b0r<<endl;
	//cout<<ans<<endl;
	int ans1=0;
	if(a[t10]==1){a1m++;}else{a0m++;}	  
	if(b[t20]==1){b1m++;}else{b0m++;}
	if(a1m>b1m){ans1+=b1m;}else{ans1+=a1m;}
	if(a0m>b0m){ans1+=b0m;}else{ans1+=a0m;}
	if(ans1>(t20-t10))ans1=t20-t10+2;
	ans+=ans1;
    cout<<ans<<endl;
  }
  //cout<<endl<<flag1<<endl<<flag2<<endl<<flag3;
return;
}

int main(){
  freopen("edit.in","r",stdin);
  freopen("edit.out","w",stdout);
  scanf("%d",&T);
  for(int i=1;i<=T;i++){
    work();
  }
return 0;
}
