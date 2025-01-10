//g++ -std=c++14 T1.cpp -o 11 -O2 -Wall

#include<bits/stdc++.h>
using namespace std;
#define endl '\n'

int n;
string s1, s2, t1, t2;
vector<pair<int, int> > a;
vector<pair<int, int> > b;

void init()
{
    a.clear();
    b.clear();
    int cnt = 0, l;

    for(int i = 0; i <= n; i++)
    {
        if(t1[i] == '1')
        {
            if(cnt == 0) l = i;
            cnt ++;
        }
        else
        {
            if(cnt >= 2)
                a.push_back({l, i - 1});
            cnt = 0;
        }
    }

    cnt = 0;
    for(int i = 0; i <= n; i++)
    {
        if(t2[i] == '1')
        {
            if(cnt == 0) l = i;
            cnt ++;
        }
        else
        {
            if(cnt >= 2)
                b.push_back({l, i - 1});
            cnt = 0;
        }
    }

}

void work()
{
    cin >> n;
    cin >> s1 >> s2 >> t1 >> t2;
    init();

    // for(auto ed : a)
    // {
    //     cout << ed.first << ' ' << ed.second << endl;
    // }
    // for(auto ed : b)
    // {
    //     cout << ed.first << ' ' << ed.second << endl;
    // }

    bool flaga = 1, flagb = 1;
    for(int i = 0; i < n - 1; i++)
    {
        if(s1[i] != s1[i + 1])
            flaga = 0;
        if(t1[i] != t2[i])
            flagb = 0;
    }

    int ans = 0;
    if(flaga == 1) // A
    {
        char c = s1[0];
        for(int i = 0; i < n; i++)
        {
            if(s2[i] == c)
                ans++;
        }
        cout << ans << endl;
        return ;

    }

    if(flagb == 1) // B
    {
        int cnt = 0, i = 0;

        while(i < n)
        {
            if(i == a[cnt].first)
            {
                int cnt1a = 0, cnt2a = 0, cnt1b = 0, cnt2b = 0;
                for(int j = i; j <= a[cnt].second; j++)
                {
                    if(s1[j] == '1') cnt1a++;
                        else cnt1b++;
                    
                    if(s2[j] == '1') cnt2a++;
                        else cnt2b++;
                }
                ans += (min(cnt1a, cnt2a) + min(cnt1b, cnt2b));
                
                i = a[cnt].second + 1;
                cnt++;
                // cnt++;
            }
            else
            {
                if(s1[i] == s2[i]) ans++;
                i++;
            }
        }
        cout << ans << endl;
        return;
    }
    
    cout << n / 2 << endl;
    

}



int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    freopen("edit.in", "r", stdin);
    freopen("edit.out", "w", stdout);
    int t;
    cin >> t;
    while(t--)
    {
        work();
    }
}