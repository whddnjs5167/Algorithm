#include <iostream>
#include <string>
#include <vector>
#include <list>

using namespace std;

int point = 0;

int main()
{
    string a;
    list<char> str;
    list<char>::iterator it;
    int n;

    cin >> a;

    int size = a.size();

    while(size--)
        str.push_front(a[size]);

    cin >> n;

    it = str.end();
    
    while(n--)
    {
        char tmp;
        cin >> tmp;
        if(tmp == 'L')
        {
            if(it!=str.begin()) it--;
        }
        else if(tmp == 'D')
        {
            if(it!=str.end()) it++;
        }
        else if(tmp == 'B')
        {
            if(it!=str.begin())
            {
                it = str.erase(--it);
            }

        }
        else if(tmp == 'P')
        {
            char tmp2;
            cin >> tmp2;
            str.insert(it,tmp2);
        }
    }

    for(list<char>::iterator it2= str.begin(); it2 != str.end(); it2++)
    {
        cout << *(it2);
    }
    
    cout << endl;

    return 0;
}
