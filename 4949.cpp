#include<bits/stdc++.h>
#define FASTio ios_base :: sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#define endl '\n'

using namespace std;

int main()
{
    FASTio;

    string ss;
    stack<char> str;

    while(1)
    {
        char t=' ';
        while(t!='.')
        {
            scanf("%c", &t);
            ss.push_back(t);
        }
        getchar();
        
        if(ss[0]=='.')    return 0;

        for(int i=0; i<ss.size(); i++)
        {
            char temp=ss[i];
            if(temp=='(' || temp=='[')
                str.push(temp);
            else if(temp==')')
            {
                if(!str.empty())
                {
                    if(str.top()=='(')  str.pop();
                    else    break;
                }
                else    str.push(temp);
            }
            else if(temp==']')
            {
                if(!str.empty())
                {
                    if(str.top()=='[')  str.pop();
                    else    break;
                }
                else    str.push(temp);
            }

            if(temp=='.') break;
        }

        if(str.empty()) printf("yes\n");
        else    printf("no\n");

        while(!str.empty())
            str.pop();

        ss.clear();
    }

    return 0;
}
