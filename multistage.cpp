#define INT_MAX 2147483647
#include<iostream>
#include<vector>
#include<utility>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        int n, m;
        cin >> n >> m;
        vector< vector< pair<int, int> > > G;
        for(int i = 1; i <= n; i++)
        {
            vector< pair<int, int> > temp;
            pair<int, int> tem;
            tem.first = i;
            tem.second = 0;
            temp.push_back(tem);
            G.push_back(temp);
        }
        for(int i = 1; i <= m; i++)
        {
            int a, b, w;
            cin >> a >> b >> w;
            pair<int, int> temp;
            temp.first = a;
            temp.second = w;
            G[b-1].push_back(temp);
        }
        int p = G.size();
        for(int i = 1; i <= p-1; i++)
        {
            int minimum = INT_MAX;
            int q = G[i].size();
            for(int j = 1; j <= q - 1; j++)
            {
                if(G[G[i][j].first - 1][0].second + G[i][j].second < minimum)
                {
                    minimum = G[G[i][j].first - 1][0].second + G[i][j].second;
                }
            }
            if(minimum != INT_MAX)
                G[i][0].second = minimum;
        }
        cout << G[p-1][0].second << endl;
    }
}