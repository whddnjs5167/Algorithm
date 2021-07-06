#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int n,m;

    cin >> n;

    vector<int> n_array;

    for(int i=0; i<n; i++)
    {
        int tmp;
        cin >> tmp;
        n_array.push_back(tmp);
    }

    cin >> m;

    vector<int> m_array;

    for(int i=0; i<m; i++)
    {
        int tmp;
        cin >> tmp;
        m_array.push_back(tmp);
    }

    sort(n_array.begin(),n_array.end());

    for(int i=0; i<m; i++)
    {
        int find = m_array[i];

        auto it_u = upper_bound(n_array.begin(),n_array.end(),find);
        auto it_l = lower_bound(n_array.begin(),n_array.end(),find);
        
        cout << it_u-it_l << ' ';
    }

    cout << endl;

    return 0;
}
