#include<iostream>
#include<utility>
#include<vector>
#include<cstdio>
using namespace std;

int main()
{
    int t;
    scanf("%d ", &t);
    while(t--)
    {
        string a, b;
        getline(cin, a);
        getline(cin, b);
        vector< vector< pair<int, vector<char> > > > c;
        int l = a.size();
        int m = b.size();
        for(int i = 0; i <= l; i++)
        {
            vector< pair<int, vector<char> > > temp;
            for(int j = 0; j <= m; j++)
            {
                pair<int, vector<char> > t;
                t.first = 0;
                temp.push_back(t);
            }
            c.push_back(temp);
        }
        for(int i = 1; i <= l; i++)
        {
            for(int j = 1; j <= m; j++)
            {
                if(a[i-1] == b[j-1])
                {
                    c[i][j].first = c[i-1][j-1].first + 1;
                    c[i][j].second = c[i-1][j-1].second;
                    c[i][j].second.push_back(a[i-1]);
                }
                else
                {
                    c[i][j] = max(c[i-1][j], c[i][j-1]);
                }
            }
        }
        for(vector<char>::const_iterator p = c[l][m].second.begin(); p != c[l][m].second.end() ;++p)
        {
            cout << *p;
        }
        cout << endl;
        //cout << c[l][m].first << endl;
    }
}