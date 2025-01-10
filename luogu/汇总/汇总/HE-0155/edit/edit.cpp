#include<bits/stdc++.h>
using namespace std;
int T;
int n;
string s1,s2,t1,t2;
int km;
int main()
{
	freopen("edit.in","r",stdin);
	freopen("edit.out","w",stdout);
	cin>>T;
	for(int kpp=1;kpp<=T;kpp++)
	{
		cin>>n;
        cin>>s1>>s2>>t1>>t2;
        
		for(int i=0;i<n;i++)
        {
    	    if(s1[i]!=s2[i]&&t1[i]=='1')
    	    {
    	    	for(int j=i+1;j<n;j++)
        	    {
        		    if(s1[j]==s2[i]&&t1[j]=='1')
        		    {
        			    swap(s1[i],s1[j]);
        			    continue;
			        }
		        }
			}
        	    
	    }
        for(int i=0;i<n;i++)
	    {
		    if(s2[i]!=s1[i]&&t2[i]=='1')
		    {
			    for(int j=i;j<n;j++)
        	    {
        		    if(s2[j]==s1[i]&&t2[j]=='1')
        		    {
        			    swap(s2[i],s2[j]);
        			    continue;
				    }
			    }
		    }
	    }
	    for(int i=0;i<n;i++)
	    {
		    if(s1[i]==s2[i])
		    km++;
	    }
	    cout<<km<<endl;
	    km=0;
	}
    return 0;
}
 
