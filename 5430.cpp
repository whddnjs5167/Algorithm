#include <iostream>
#include <string>
#include <list>

using namespace std;

list<char> ls;
string fun;

bool D(bool flag)
{
    if(ls.empty())  return true;

    if(!flag)    ls.pop_front();
    else    ls.pop_back();

    return false;
}

void input()
{
    char tmp='\0';
    while(tmp!=']')
    {
        cin >> tmp;
        ls.push_back(tmp);
    }
}

int main()
{
    int t;

    cin >> t;

    while(t--)
    {
        
        int n;
        bool R_flag=false, err_flag=false;

        cin >> fun;

        cin >> n;

        input();

        list<char>::iterator front = ls.begin(), end = --ls.end();

        for(int i = 0; i < fun.size(); i++)
        {
            if(fun[i]=='R') R_flag=!R_flag;
            else if(fun[i]=='D')
            {
                if(ls.size()==2)
                {
                    err_flag = true;
                    break;
                }

                if(!R_flag)
                {
                    if(*front=='[') front++;
                    while(*front!=',' && *front!=']')
                    {
                        front = ls.erase(front++);
                    }
                    if(*front==',')  front = ls.erase(front);
                }
                else
                {
                    if(*end==']')   end--;

                    while(*end!=',' && *end!='[')
                    {
                        ls.erase(end--);
                    }
                    if(*end==',')  end = ls.erase(end);

                }
            }
        }
        
        if(err_flag) cout << "error" << endl;
        else
        {
            if(!R_flag)
            {
                for(auto it=ls.begin(); it!=ls.end(); it++)
                    cout << *it;
            }
            else
            {

                cout << *ls.begin();
                int cnt = 0;
                for(auto it=--(--ls.end()); it!=ls.begin(); it--)
                {
                    auto tmp = it;
                    if(*tmp==',')
                    {
                        tmp++;
                        while(cnt--) cout << *tmp++;
                        cout << ',';
                    }
                    else if(tmp == ++ls.begin())
                    {
                        cnt++;
                        while(cnt--)    cout << *tmp++;
                    }
                    cnt++;
                }
                cout << *--ls.end();
            }
            cout << endl;
        }

        ls.clear();
        fun.clear();

    }

    return 0;
}
