#include <bits/stdc++.h>

using namespace std;

struct Node{
	int l,r;
	int zn,on;
	int c;
};

bool canSwap(string x,int a,int b){
	return x[a]!='0'&&x[b]!='0';
}

bool cmp(Node x,Node y){
	return x.r < y.r;
}

// return shirnk Count
int shirnkToZe(int& x,int& y){
	if(x >0 && y >0){
		if(x>=y){
			int ou = y;
		x -= y;
		y = 0;
		return ou;
	}
		else {
			int ou = x;
		y -= x;
		x = 0;
		return ou;
	}
	}
	
	
	return 0;
	
}

void work(){
	int n;
	
	cin>>n;
	int smap1[n+1],smap2[n+1];
	memset(smap1,-1,sizeof(smap1));
	memset(smap2,-1,sizeof(smap2));
	string s1,s2,si,sj;
	cin>>s1>>s2>>si>>sj;
	vector<int> sf1,sf2;
	vector<Node> sn1,sn2;
	int st = 0;
	int tl = 0,tr = 0;
	int nnz = 0,nno = 0;
	for(int i = 0;i<n;i++){
		if(si[i]=='0'){
			if(nnz > 0 || nno > 0){
				Node n;
				n.l = tl;
				n.r = i - 1;
				n.zn = nnz;
				n.on = nno;
				n.c = 1;
				sn1.push_back(n);
				for(int j = n.l;j<=n.r;j++){
					smap1[j] = sn1.size()-1;
				}
			}
			nnz = 0;nno = 0;
			st = 1;
			tl = i + 1;
			sf1.push_back(i);
			continue;
		}
		if(s1[i]=='0'){
			nnz++;
		}
		else {
			nno++;
		}
		if(i == (n-1)){
			if(nnz > 0 || nno > 0){
				Node n;
				n.l = tl;
				n.r = i;
				n.zn = nnz;
				n.on = nno;
				n.c = 1;
				sn1.push_back(n);
				
				for(int j = n.l;j<=n.r;j++){
					smap1[j] = sn1.size()-1;
				}
			}
			
			//break;
		}
		
	}
	tl = 0;
	nnz = 0,nno = 0;
	for(int i = 0;i<n;i++){
		if(sj[i]=='0'){
			if(nnz > 0 || nno > 0){
				Node n;
				n.l = tl;
				n.r = i - 1;
				n.zn = nnz;
				n.on = nno;
				n.c = 2;
				sn2.push_back(n);
				for(int j = n.l;j<=n.r;j++){
					smap2[j] = sn2.size()-1;
				}
			}
			nnz = 0;nno = 0;
			st = 1;
			tl = i + 1;
	
			sf2.push_back(i);
			continue;
		}
		if(s2[i]=='0'){
			nnz++;
		}
		else {
			nno++;
		}
		if(i == (n-1)){
			if(nnz > 0 || nno > 0){
				Node n;
				n.l = tl;
				n.r = i;
				n.zn = nnz;
				n.on = nno;
				n.c = 2;
				sn2.push_back(n);
				for(int j = n.l;j<=n.r;j++){
					smap2[j] = sn2.size()-1;
				}
			}
			//break;
		}
		
	}
	long long ansz = 0,anso = 0;
	for(int i = 0;i<sf1.size();i++){
		int idx = sf1[i];
		if(smap2[idx]!=-1){
			if(s1[idx]=='0'){
				if(sn2[smap2[idx]].zn>0){
					//cout<<sn2[smap2[idx]].zn;
					sn2[smap2[idx]].zn--;
					ansz++;
				}
				
			}else{
				if(sn2[smap2[idx]].on>0){
					sn2[smap2[idx]].on--;
					//cout<<sn2[smap2[idx]].on;
					anso++;
				}
			}
		}
		else if(s2[idx] == s1[idx]){
			if(s2[idx] = '0')ansz++;
			else anso++;
			
		}
		
	}
	for(int i = 0;i<sf2.size();i++){
		int idx = sf2[i];
		if(smap1[idx]!=-1){
			if(s2[idx]=='0'){
				if(sn1[smap1[idx]].zn>0){
					//cout<<sn2[smap1[idx]].zn;
					sn1[smap1[idx]].zn--;
					ansz++;
				}
				
			}else{
				if(sn1[smap1[idx]].on>0){
					sn1[smap1[idx]].on--;
					//cout<<sn2[smap1[idx]].on;
					anso++;
				}
			}
		}
	}
	vector<Node> nt;
	for(int i = 0;i<sn1.size();i++){
		nt.push_back(sn1[i]);
	}
	for(int i = 0;i<sn2.size();i++){
		nt.push_back(sn2[i]);
	}
	sort(nt.begin(),nt.end(),cmp);
	//cout<<nt[4].l<<nt[4].r<<endl;
	for(int i = 0;i<nt.size() - 1;i++){
		if(nt[i].c == 1){
			int curIdx = -1;
			for(int j = i + 1;j<nt.size();j++){
				if(nt[j].c == 2){
					if(nt[j].l>nt[i].r)break;
					curIdx = j;
					break;
				}
			}
			if(curIdx!=-1){
				//cout<<i<<" "<<curIdx<<":"<<endl;
				//cout<<nt[i].zn<<" "<<nt[curIdx].zn<<endl;
				ansz += shirnkToZe(nt[i].zn,nt[curIdx].zn);
				anso += shirnkToZe(nt[i].on,nt[curIdx].on);
			}
		}
		if(nt[i].c == 2){
			
			int curIdx = -1;
			for(int j = i;j<nt.size();j++){
				if(nt[j].c == 1){
					if(nt[j].l>nt[i].r)break;
					curIdx = j;
					break;
				}
			}
			if(curIdx!=-1){
				ansz += shirnkToZe(nt[i].zn,nt[curIdx].zn);
				anso += shirnkToZe(nt[i].on,nt[curIdx].on);
			}
		}
	}                                 
	cout<<ansz+anso;
	
	
}

int main(){
	freopen("edit.in","r",stdin);
	freopen("edit.out","w",stdout);
	int T;
	cin>>T;
	for(int i = 1;i<=T;i++){
		work();
	}
}
