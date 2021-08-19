#include<bits/stdc++.h>
#define FASTio ios_base :: sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#define endl '\n'

using namespace std;

int chon;
bool find_flag = false;

void finder(vector<vector<bool>>& v, int pos, int find, int n, int cnt)
{
    if(pos==find)
    {
        chon = cnt;
        find_flag = true;
        return;
    }
    for(int i=1; i<n; i++)
    {
        if(v[pos][i])
        {
            v[i][pos] = false;
            finder(v,i,find,n,cnt+1);
            v[i][pos] = true;
        }
    }

    return;
}

int main()
{
    FASTio;

    int n,m,a,b;

    cin >> n;

    n++;

    cin >> a >> b;

    vector<vector<bool>> v(n,vector<bool> (n,false));

    cin >> m;

    for(int i=0; i<m; i++)
    {
        int x,y;
        cin >> x >> y;
        v[x][y]=true;
        v[y][x]=true;
    }

    finder(v,a,b,n,0);
    if(chon==0) cout << -1 << endl;
    else cout << chon << endl;

    return 0;
}
