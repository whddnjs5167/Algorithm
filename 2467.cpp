#include<bits/stdc++.h>
#define FASTio ios_base :: sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#define endl '\n'

using namespace std;

int main()
{
    FASTio;

    int n,minN=2100000000,tmp;
    pair<int,int> a;

    cin >> n;

    int l=0, r=n-1;

    vector<int> v(n,0);

    for(int i=0; i<n; i++)
        cin >> v[i];

    while(l<r)
    {
        tmp = v[l]+v[r];

        if(minN>=abs(tmp))
        {
            minN=abs(tmp);
            a = {v[l],v[r]};
        }

        if(tmp>0) r--;
        else    l++;
    }
    

    cout << a.first << ' ' << a.second << endl;

    return 0;
}
