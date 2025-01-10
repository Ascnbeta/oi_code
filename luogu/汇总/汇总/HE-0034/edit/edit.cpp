#include<bits/stdc++.h>
using namespace std;
int T,n,ans;
string s1,s2,t1,t2;
struct Line{
	int l,r,cnt1,cnt0;
};
vector<Line> l1,l2;
signed main(){
	freopen("edit.in","r",stdin);
	freopen("edit.out","w",stdout);
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		ans=0;l1.clear(),l2.clear();
		cin>>s1>>s2>>t1>>t2;
		s1='#'+s1+'0',s2='#'+s2+'0';
		t1='#'+t1+'0',t2='#'+t2+'0';
		int l=1,r=0,s11=0,s10=0,s21=0,s20=0;
		for(int i=1;i<=n;++i)
			if(t1[i]=='0'&&t2[i]=='0'&&s1[i]==s2[i])ans++;
		for(int i=1;i<=n;){
			if(t1[i]=='1'){
				l=r=i;
				while(r<=n&&t1[r]=='1'){
					s11+=(s1[r]=='1'),s10+=(s1[r]=='0');
					s21+=(s2[r]=='1'&&t2[r]=='0');
					s20+=(s2[r]=='0'&&t2[r]=='0');
					r++;
				}
				r--;
//				cout<<l<<" "<<r<<" "<<s11<<" "<<s10<<" "<<s21<<" "<<s20<<"\n";
				int match1=min(s21,s11),match0=min(s20,s10);
				ans+=match1+match0;
				s11-=match1,s10-=match0,s21-=match1,s20-=match0;
				if(s21)s10-=s21,s21=0;
				if(s20)s11-=s20,s20=0;
				l1.push_back({l,r,s11,s10});
//				cout<<l<<" "<<r<<" "<<s11<<" "<<s10<<" "<<s21<<" "<<s20<<"\n";
//				cout<<ans<<"\n";
				i=r+1,s11=s10=s21=s20=0;
			}else i++;
		}
		l=1,r=s11=s10=s21=s20=0;
		for(int i=1;i<=n;){
			if(t2[i]=='1'){
				l=r=i;
				while(r<=n&&t2[r]=='1'){
					s21+=(s2[r]=='1'),s20+=(s2[r]=='0');
					s11+=(s1[r]=='1'&&t1[r]=='0');
					s10+=(s1[r]=='0'&&t1[r]=='0');
					r++;
				}
				r--;
//				cout<<l<<" "<<r<<" "<<s11<<" "<<s10<<" "<<s21<<" "<<s20<<"\n";
				int match1=min(s21,s11),match0=min(s20,s10);
				ans+=match1+match0;
				s11-=match1,s10-=match0,s21-=match1,s20-=match0;
				if(s11)s20-=s11,s11=0;
				if(s10)s21-=s10,s10=0;
				l2.push_back({l,r,s21,s20});
//				cout<<l<<" "<<r<<" "<<s11<<" "<<s10<<" "<<s21<<" "<<s20<<"\n";
//				cout<<ans<<"\n";
				i=r+1,s11=s10=s21=s20=0;
			}else i++;
		}
//		for(auto x:l1)cout<<x.l<<" "<<x.r<<" "<<x.cnt1<<" "<<x.cnt0<<"\n";
//		for(auto x:l2)cout<<x.l<<" "<<x.r<<" "<<x.cnt1<<" "<<x.cnt0<<"\n";
		unsigned top1=0,top2=0;
		while(top1<l1.size()&&top2<l2.size()){
			while(top1<l1.size()&&l1[top1].r<l2[top2].l)top1++;
			while(top2<l2.size()&&l1[top1].l>l2[top2].r)top2++;
			int match1=min(l1[top1].cnt1,l2[top2].cnt1),match0=min(l1[top1].cnt0,l2[top2].cnt0);
			ans+=match1+match0;
//			cout<<top1<<"  "<<top2<<"  "<<l1[top1].cnt1<<"  "<<l1[top1].cnt0<<"  "<<l2[top2].cnt1<<"  "<<l2[top2].cnt0<<"\n";
			l1[top1].cnt1-=match1;l2[top2].cnt1-=match1; 
			l1[top1].cnt0-=match0;l2[top2].cnt0-=match0;
			if(l1[top1].r<l2[top2].r){
				if(l2[top2].cnt1)l2[top2].cnt1-=max(l1[top1].cnt1,l1[top1].cnt0);
				if(l2[top2].cnt0)l2[top2].cnt0-=max(l1[top1].cnt1,l1[top1].cnt0);
				top1++;
			}
			else if(l1[top1].r>l2[top2].r){
				if(l1[top1].cnt1)l1[top1].cnt1-=max(l2[top2].cnt1,l2[top2].cnt0);
				if(l1[top1].cnt0)l1[top1].cnt0-=max(l2[top2].cnt1,l2[top2].cnt0);
				top2++;
			}
			else top1++,top2++;
		}
		printf("%d\n",ans);
	}
	return 0;
}
/*
10:30 get : 3k shi shan
rp++
AFO after NOIP2024
*/
