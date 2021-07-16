#include <iostream>
#include <vector>

using namespace std;

int rec(vector<int>& v,  vector<bool>& c, int pos , int sum, int n, int target)
{
    int ret = 0;

    if(pos==n)  return 0;

    for(int i=pos; i<n; i++)
    {   
        if(!c[i])
        {
            c[i]=true;
            sum+=v[i];
            if(sum==target) ret++;
            ret += rec(v,c,i,sum,n,target);
            c[i]=false;
            sum-=v[i];
        }
    }

    return ret;
}

int main()
{
    int n,s;

    cin >> n >> s;

    vector<int> v(n,0);
    vector<bool> c(n,false);


    for(int i=0; i<n; i++)
    {
        cin >> v[i];
    }

    int cnt=0;

    cnt=rec(v,c,0,0,n,s);

    cout << cnt << endl;    

    return 0;
}
