#include<bits/stdc++.h>
#define FASTio ios_base :: sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#define endl '\n'

using namespace std;

long long minn = 10000000;

void finder(long long n, long long target, long long cnt)
{
    if(n>target) return;
    if(n==target)
    {
        minn = min(minn,cnt+1);
        return;
    }
    
    finder(n<<1,target,cnt+1);
    finder(n*10+1,target,cnt+1);

    return;
}

int main()
{
    FASTio;

    long long n,target;

    cin >> n >> target;

    if(n==target)
    {
        cout << 0 << endl;
        return 0;
    }

    finder(n,target,0);

    if(minn == 10000000)    minn = -1;

    cout << minn << endl;

    return 0;
}
