#include<iostream>
#include<vector>
#include<map>
#include<queue>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        int m, n;
        cin >> m >> n;
        vector<int> visit;
        vector< vector<int> > G;
        for(int i = 1; i <= m; i++)
        {
            vector<int> temp;
            G.push_back(temp);
            visit.push_back(-1);
        }
        for(int i = 1;i <= n; i++)
        {
            int u, v;
            cin >> u >> v;
            G[u-1].push_back(v);
            G[v-1].push_back(u);
        }
        queue< pair<int, int> > q;
        int tem;
        cin >> tem;
        q.push(make_pair(tem, 0));
        while(!q.empty())
        {
            for(int i = 0; i <= G[q.front().first - 1].size() - 1; i++)
            {
                if(visit[G[q.front().first - 1][i]-1] == -1)
                {
                    q.push(make_pair(G[q.front().first - 1][i], (q.front().second + 1)));
                    visit[G[q.front().first - 1][i]-1] = (q.front().second+1)*6;
                }
            }
            q.pop();
        }
        for(int i = 0; i <= visit.size() - 1; i++)
        {
            if(i != tem - 1)
            cout << visit[i] << " ";
        }
        cout << endl;
    }
    return 0;
}