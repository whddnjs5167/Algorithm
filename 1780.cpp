#include<bits/stdc++.h>
#define FASTio ios_base :: sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#define endl '\n'

using namespace std;

int zero_cnt = 0;
int plus_cnt = 0;
int minus_cnt = 0;

int finder(int y, int x, int end_y, int end_x, vector<vector<int>>& v)
{
    int post=v[y][x];

    for(int i=y; i<end_y; i++)
    {
        for(int j=x; j<end_x; j++)
        {
            if(post!=v[i][j]) return -2;
            post=v[i][j];
        }
    }

    return post;
}

void rec(int y, int x,vector<vector<int>>& v, int n)
{
    int size = n;

    int num = finder(y,x,y+size,x+size,v);
    
    if(num == 1)    plus_cnt++;
    else if(num == 0)   zero_cnt++;
    else if(num == -1)  minus_cnt++;
    else
    {
        for(int i=y; i<y+size; i+=size/3)
        {
            for(int j=x; j<x+size; j+=size/3)
            {
                rec(i,j,v,size/3);
            }
        }
    }

    return ;
}

int main()
{
    FASTio;

    int n;

    cin >> n;

    vector<vector<int>> v(n,vector<int> (n,0));

    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++)
            cin >> v[i][j];


    rec(0,0,v,n);

    cout << minus_cnt << endl;
    cout << zero_cnt << endl;
    cout << plus_cnt << endl;

    return 0;
}
