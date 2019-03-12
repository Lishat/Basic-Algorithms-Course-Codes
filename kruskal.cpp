#include <iostream>
#include <utility>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector< pair< int, pair<int, int> > > G;
    vector<int> parent;
    int n, t;
    cin >> n >> t;
    for(int i = 1; i <= n; i++)
    {
        parent.push_back(i);
    }
    for(int i = 1; i <= t; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        G.push_back(make_pair(c, make_pair(a, b)));
    }
    sort(G.begin(), G.end());
    int shortest = 0;
    for(int i = 0; i <= G.size() - 1; i++)
    {
        if(parent[G[i].second.first-1] != parent[G[i].second.second-1])
        {
            shortest += G[i].first;
            int ex = parent[G[i].second.second-1];
            for(int j = 0; j <= parent.size()-1; j++)
            {
                if(parent[G[j].second.second-1] == ex)
                {
                    parent[G[j].second.second-1] = parent[G[i].second.first-1];
                }
            }
        }
    }
    cout << shortest << endl;
    return 0;
}