#include <iostream>
#include <vector>

using namespace std;

void rec(vector<int>& v, vector<bool>& c, int pos, int cnt, int n)
{
    if(cnt==6)
    {
        for(int i=0; i < n; i++)
        {
            if(c[i])    cout << v[i] << ' ';
        }
        cout << endl;
        return;
    }

    for(int i=pos; i<n; i++)
    {
        if(!c[i])
        {
            c[i]=true;
            rec(v,c,i,cnt+1,n);
            c[i]=false;
        }
    }

    return;
}

int main()
{
    while(true)
    {
        int n,tmp;
        
        cin >> n;

        if(n==0)    return 0;
        
        vector<int> v(n,0);
        vector<bool> c(n,false);

        for(int i=0; i<n; i++)
            cin >> v[i];

        rec(v,c,0,0,n);

        v.clear();
        c.clear();

        cout << endl;
    }

    return 0;
}

