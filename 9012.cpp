#include <iostream>
#include <stack>
#include <string>

using namespace std;

int main()
{
    stack<char> st;

    int t;

    cin >> t;

    while(t--)
    {
        string str;
        bool flag = false;

        cin >> str;

        for(int i=0; i<str.size(); i++)
        {
            if(str[i]=='(')  st.push('(');
            else if(str[i]==')')
            {
                if(st.empty()) flag = true;
                else st.pop();
            }
        }

        if(!flag && st.empty())  cout << "YES" << endl;
        else cout << "NO" << endl;

        while(!st.empty())
            st.pop();
    }

    return 0;
}
