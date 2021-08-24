#include<bits/stdc++.h>
#define FASTio ios_base :: sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#define endl '\n'

using namespace std;

int check(char c)
{
    if(c=='+' || c=='-')
        return 1;

    return 2;
}

int main()
{
    FASTio;

    string str;
    stack<char> sign;

    cin >> str;

    for(int i=0; i<str.size(); i++)
    {
        char now = str[i];
        if(now >='A' && now <='Z')
        {
            cout << now;
        }
        else if(now == '(')
        {
            sign.push(now);
        }
        else if(now == ')')
        {
            while(sign.top()!='(')
            {
                cout << sign.top();
                sign.pop();
            }
            sign.pop();
        }
        else
        {
            while(1)
            {
                if(sign.empty()) break;
                //지금 들어는 문자 이전 문자보다 작으면
                if(check(now)>check(sign.top())) break;
                else
                {                    
                    cout << sign.top();

                    sign.pop();
                }
            }
            sign.push(now);
        }
    }

    while(!sign.empty())
    {
        char tmp = sign.top();
        if(tmp!='(' && tmp!=')')    cout << tmp;
        sign.pop();
    }

    cout << endl;

    return 0;
}
