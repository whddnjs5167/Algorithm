#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool cmp()
{

}

int main()
{
    int n;

    cin >> n;

    vector<int> v(n);

    for(int i=0; i<n; i++)
    {
        cin >> v[i];
    }

    sort(v.begin(),v.end());

    int tmp=-100000;

    for(int i=0; i<n; i++)
    {
        if(tmp!=v[i])
        {
            tmp = v[i];
            cout << v[i] <<' ';
        }
    }

    return 0;
}
