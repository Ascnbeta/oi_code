#include<bits/stdc++.h>
using namespace std;
struct node
{
	int x,z,o,y;
} box1[110000],box2[110000];
int cur1,cur2;
int ans;
int main()
{
	freopen("edit.in","r",stdin);
	freopen("edit.out","w",stdout);
	int T;
	cin >> T;
	while(T--)
	{
		box1[0].x = -1,box2[0].x = -1;
		int n;
		cin >> n;
		string a,b,s,t;
		cin >> a;
		cin >> b;
		cin >> s;
		cin >> t;
		cur1 = 0,cur2 = 0;
		int cntz = 0,cnto = 0;
		for(int i = 0;i < n;i++)
		{
			if(s[i] == '0')
			{
				cur1++;
				box1[cur1].x = i;
				box1[cur1].z = cntz;
				box1[cur1].o = cnto;
				cntz = 0,cnto = 0;
				box1[cur1].y = box1[cur1 - 1].x;
			}
			else
			{
				if(a[i] == '1')
				{
					cnto++;
				}
				else
				{
					cntz++;
				}
			}
		}
		a += 's',b += 'b';
		cur1++;
		box1[cur1].x = n;
		box1[cur1].z = cntz;
		box1[cur1].o = cnto;
		cntz = 0,cnto = 0;
		box1[cur1].y = box1[cur1 - 1].x;
		for(int i = 0;i < n;i++)
		{
			if(t[i] == '0')
			{
				cur2++;
				box2[cur2].x = i;
				box2[cur2].z = cntz;
				box2[cur2].o = cnto;
				cntz = 0,cnto = 0;
				box2[cur2].y = box2[cur2 - 1].x;
			}
			else
			{
				if(b[i] == '1')
				{
					cnto++;
				}
				else
				{
					cntz++;
				}
			}
		}
		cur2++;
		box2[cur2].x = n;
		box2[cur2].z = cntz;
		box2[cur2].o = cnto;
		box2[cur2].y = box2[cur2 - 1].x;
		int l = 1,r = 1;
		ans = 0;
		while(l <= cur1 || r <= cur2)
		{
			int sum = min(box1[l].x,box2[r].x) - max(box1[l].y,box2[r].y) - 1;
			if(box1[l].x == box2[r].x)
			{
				ans += min(sum,(min(box1[l].z,box2[r].z) + min(box1[l].o,box2[r].o))) + (a[box1[l].x] == b[box2[r].x]);
				l++;
				r++;
				//cout << ans << " 1" << endl;
				continue;
			}
			if(box1[l].x < box2[r].x)
			{
				int cnt = min(sum,min(box1[l].z,box2[r].z));
				cnt = max(cnt,0);
				sum -= cnt;
				ans += cnt;
				box2[r].z -= cnt;
				cnt = min(sum,min(box1[l].o,box2[r].o));
				cnt = max(cnt,0);
				sum -= cnt;
				ans += cnt;
				box2[r].o -= cnt;
				if(a[box1[l].x] == '1')
				{
					if(box2[r].o)
					{
						++ans;
						box2[r].o--;
					}
				}
				else
				{
					if(box2[r].z)
					{
						++ans;
						box2[r].z--;
					}
				}
				l++;
				//cout << ans << " 2" << endl;
				continue;
			}
			if(box1[l].x > box2[r].x)
			{
				int cnt = min(sum,min(box1[l].z,box2[r].z));
				//cout << cnt << endl;
				cnt = max(cnt,0);
				sum -= cnt;
				ans += cnt;
				box1[l].z -= cnt;
				cnt = min(sum,min(box1[l].o,box2[r].o));
				cnt = max(cnt,0);
				sum -= cnt;
				ans += cnt;
				box1[l].o -= cnt;
				if(b[box2[r].x] == '1')
				{
					if(box1[l].o)
					{
						ans++;
						box1[l].o--;
					}
				}
				else
				{
					if(box1[l].z > 0)
					{
						ans++;
						box1[l].z--;
					}
				}
				r++;
				//cout << ans << " 3" << endl;
				continue;
			}
		}
		cout << ans << endl;
	}
	return 0;
}
