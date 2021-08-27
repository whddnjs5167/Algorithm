#include<bits/stdc++.h>
#define FASTio ios_base :: sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#define endl '\n'

using namespace std;

int main()
{
    FASTio;

    int t,n,k,myteam,m;

    cin >> t;

    while(t--)
    {
        cin >> n >> k >> myteam >> m;

        vector<vector<int>> score(n+1,vector<int> (k+1,0));
        vector<int> cnt_sub(n+1,0);
        vector<int> last_sub(n+1,0);

        for(int i=0; i<m; i++)
        {
            int id,pn,s;
            cin >>  id >> pn >> s;

            if(score[id][pn]<s)
            {
                score[id][0]-=score[id][pn];
                score[id][pn]=s;
                score[id][0]+=s;
            }
            cnt_sub[id]++;
            last_sub[id]=i;
        }

        int cnt_higher=0;

        for(int i=1; i<n+1; i++)
        {
            if(score[myteam][0]<score[i][0]) cnt_higher++;
            else if(score[myteam][0]==score[i][0])
            {
                if(cnt_sub[myteam]>cnt_sub[i]) cnt_higher++;
                else if(cnt_sub[myteam]==cnt_sub[i])
                {
                    if(last_sub[myteam]>last_sub[i]) cnt_higher++;
                }
            }
        }

        cout << cnt_higher+1 << endl;

        score.clear();
        cnt_sub.clear();
        last_sub.clear();
    }

    return 0;
}
