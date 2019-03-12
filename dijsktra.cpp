#include<iostream>
#include<utility>
#include<queue>
#include<map>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        int m, n;
        cin >> m >> n;
        vector<map<int, int> > G(m+1);
        vector<int> d(m+1, INT_MAX);
        priority_queue< pair<int, int> > Q;
        for(int i = 1;i <= n; i++)
        {
            int u, v, w;
            cin >> u >> v >> w;
            if(G[u].count(v) == 0 or G[u][v] > w)
            {
                G[u][v] = w;
                G[v][u] = w;
            }
        }
        int source;
        cin >> source;
        Q.push(make_pair(0, source));
        d[source] = 0;
        while(!Q.empty())
        {
            pair<int, int> topmost = Q.top();
            Q.pop();
            for(map<int, int>::const_iterator i = G[topmost.second].begin(); i != G[topmost.second].end(); ++i)
            {
                if(d[topmost.second] + i->second < d[i->first])
                {
                    d[i->first] = d[topmost.second] + i->second;
                    Q.push(make_pair(d[i->first], i->first));
                }
            }
        }
        for(int i = 1; i <= m; i++)
        {
            if(i != source)
            {
                if(d[i] == INT_MAX)
                cout << -1 << " ";
                else
                cout << d[i] << " ";
            }
        }
        cout << endl;
    }
    return 0;
}