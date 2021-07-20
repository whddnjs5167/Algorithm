#include<bits/stdc++.h>
#define FASTio ios_base :: sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#define endl '\n'

using namespace std;

vector<bool> c(1000001,false);

void jud()
{
    int cnt = 0;

    for(int i=2; i<1000001; i++)
    {
        for(int j=2; j*j<=i; j++)
        {
            if(i%j==0)
            {
                c[i]=true;
                break;
            }
        }
    }
}

int main()
{
    FASTio;

    jud();

    int tmp;

    cin >> tmp;

    while(tmp)
    {
        bool flag = false;
        for(int i = 3; i < tmp/2+1; i+=2)
        {
            if(!c[i]&&!c[tmp-i])
            {
                cout << tmp << " = " << i << " + " << tmp-i << endl;
                flag = true;
                break;
            }
        }
        if(!flag)   cout << "Goldbach's conjecture is wrong." << endl;

        cin >> tmp;
    }

    return 0;
}
