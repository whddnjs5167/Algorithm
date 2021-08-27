#include<bits/stdc++.h>
#define FASTio ios_base :: sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#define endl '\n'

using namespace std;

int n,max_cnt,minn=1111111111;

void rec(vector<pair<int,int>>& v, vector<bool>& c, int pos, int to_s, int to_b, int cnt)
{
    if(cnt==max_cnt) return;
    
    for(int i=pos; i<n; i++)
    {
        if(!c[i])
        {
            c[i] = true;
            minn = min(minn,abs(to_s*v[i].first-(to_b+v[i].second)));
            rec(v,c,i,to_s*v[i].first,to_b+v[i].second,cnt+1);
            c[i] = false;
        }
    }

    return;
}

int main()
{
    FASTio;

    vector<pair<int,int>> v;

    cin >> n;

    vector<bool> c(n,false);

    for(int i=0; i<n; i++)
    {
        int s,b;
        cin >> s >> b;
        v.push_back({s,b});
    }

    for(int i=0; i<n; i++)
    {
        max_cnt = i+1;
        rec(v,c,0,1,0,0);
    }
    cout << minn << endl;

    return 0;
}
