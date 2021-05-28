#include<iostream>
#include<vector>
#include<queue>
using namespace std;
int countRestrictedPaths(int n, vector<vector<int>>& edges) {
    int mod = 1e9 + 7;
    typedef pair<int, int> pii;
    vector<vector<pair<int, int>>> adjL(n + 1, vector<pair<int, int>>());
    int m = edges.size();
    for (int i = 0; i < m; i++)
    {
        adjL[edges[i][0]].push_back(make_pair(edges[i][1], edges[i][2]));
        adjL[edges[i][1]].push_back(make_pair(edges[i][0], edges[i][2]));
    }

    priority_queue<pii, vector<pii>, greater<pii>> pq;
    pq.push({ 0,n });
    vector<int> minD(n + 1, INT_MAX);
    minD[n] = 0;
    while (!pq.empty())
    {
        int idx = pq.top().second, val = pq.top().first;
        pq.pop();
        vector<pair<int, int>> tmpv = adjL[idx];
        for (int j = 0; j < tmpv.size(); j++)
        {
            if (minD[tmpv[j].first] > minD[idx] + tmpv[j].second)
            {
                minD[tmpv[j].first] = minD[idx] + tmpv[j].second;
                pq.push({ minD[tmpv[j].first], tmpv[j].first });
            }
        }
    }
    return minD[n];
}
int main()
{
    return 0;
}
