#include<bits/stdc++.h>
#define FASTio ios_base :: sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#define endl '\n'

using namespace std;

int maxx=0;

void rec(vector<int>& hp, vector<int>& get, int now_hp, int n, int pos, int now_get)
{
    if(now_hp<=0) return;
    else    maxx=max(maxx,now_get);
    
    for(int i=pos; i<n; i++)
    {
        rec(hp,get,now_hp-hp[i],n,i+1,now_get+get[i]);
    }
    
    return;
}


int main()
{
    FASTio;

    int n;
    
    cin >> n;
    
    vector<int> hp(n,0);
    vector<int> get(n,0);
    
    for(int i=0; i<n; i++)
        cin >> hp[i];
        
    for(int i=0; i<n; i++)
        cin >> get[i];
        
    rec(hp,get,100, n, 0, 0);
    
    cout << maxx << endl;
    
    return 0;
}
