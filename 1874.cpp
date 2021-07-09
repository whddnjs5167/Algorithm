#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int main()
{
    int n;

    vector<int> input;
    stack<int> s;
    vector<char> pm;

    cin >> n;

    for(int i=0; i<n; i++)
    {
        int tmp;

        cin >> tmp;
        
        input.push_back(tmp);
    }

    int pos = 0;

    for(int i=0; i<n; i++)
    {
        s.push(i+1);
        pm.push_back('+');
        while(s.top()==input[pos])
        {
            pos++;
            s.pop();
            pm.push_back('-');
            if(s.empty())   break;
        }  
    }

    if(s.empty())
    {
        for(int i=0; i<pm.size(); i++)
        {
            cout << pm[i] << '\n';
        }
    }
    else    cout << "NO" << endl;


    return 0;
}
