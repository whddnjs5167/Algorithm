#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;


int main()
{
    queue<pair<int,int>> q;
    vector<int> v;
    int n,f_pos,t;
    
    cin >> t;
    while(t--)
    {   
        int cnt=0,pos=0;
        cin >> n >> f_pos;

        for(int i=0; i<n; i++)
        {   
            int tmp;
            cin >> tmp;
            q.push({i,tmp});
            v.push_back(tmp);
        }

        sort(v.rbegin(),v.rend());

        while(!q.empty())
        {
            pair<int,int> target = q.front();

            if(v[pos]==target.second && f_pos==target.first)
            {
                cnt++;
                q.pop();
                break;
            }
            else if(v[pos]==target.second)
            {
                cnt++;
                q.pop();
                pos++;
                continue;
            }
            q.push(target);
            q.pop();
        }

        while(!q.empty())
            q.pop();

        v.clear();

        cout << cnt << endl;
    }

    return 0;
}
