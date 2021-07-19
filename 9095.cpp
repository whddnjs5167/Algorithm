#include<bits/stdc++.h>
#define FASTio ios_base :: sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#define endl '\n'

using namespace std;

int rec(int n)
{
    if(n<0) return 0;
    if(n==0)    return 1;

    int ret = 0;

    ret+=rec(n-1);
    ret+=rec(n-2);
    ret+=rec(n-3);

    return ret;
}


int main()
{
    FASTio;

    int t;

    cin >> t;

    while(t--)
    {
        int n;

        cin >> n;

        cout << rec(n) << endl;        
    }

    return 0;
}
