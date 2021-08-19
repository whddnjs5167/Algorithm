#include<bits/stdc++.h>
#define FASTio ios_base :: sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#define endl '\n'

using namespace std;

int main()
{
    FASTio;

    int n,l;

    cin >> n >> l;

    vector<int> v(n,0);

    for(int i=0; i<n; i++)
        cin >> v[i];

    sort(v.begin(),v.end());

    int start=v[0], cnt=1;
    for(int i=1; i<n; i++)
    {
        if(v[i]-start<l)    continue;
        cnt++;
        start = v[i];
    }

    cout << cnt << endl;

    return 0;
}
