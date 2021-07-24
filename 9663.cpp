#include<bits/stdc++.h>
#define FASTio ios_base :: sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#define endl '\n'

using namespace std;

bool put(vector<int>& v, int row, int col, int n)
{
    for(int i=0; i<row; i++)
    {
        if((col-v[i])*(col-v[i])==(row-i)*(row-i))  return false;
        if(col==v[i]) return false;
    }

    return true;
}

int rec(vector<int>& v, int cnt, int row, int n)
{
    if(cnt==n)  return 1;

    int ret = 0;

    for(int i=0; i<n; i++)
    {
        if(put(v,row,i,n))
        {
            v[row] = i;
            ret+=rec(v,cnt+1,row+1,n);
            v[row] = -1;
        }           
    }
    return ret;
}

int main()
{
    FASTio;

    int n;

    cin >> n;

    vector<int> v(n,-1);

    cout << rec(v,0,0,n) << endl;

    return 0;
}
