#include<iostream>
#include<vector>

using namespace std;

int BellmanFord(int n, vector<vector<int>>& flights, int src, int dst)
{
    vector<int> dp(n, INT_MAX);
    dp[src] = 0;
    for (int i = 1; i <= n - 1; i++)
    {
        for (auto& it : flights)
        {
            int u = it[0], v = it[1], weight = it[2];
            if (dp[u] != INT_MAX && dp[v] > dp[u] + weight)
                dp[v] = dp[u] + weight;
        }
    }

    //determine whether this is a negative-weight cycle.
    bool isLoop = false;
    for (auto& it : flights)
    {
        int u = it[0], v = it[1], weight = it[2];
        if (dp[u] != INT_MAX && dp[v] > dp[u] + weight)
            isLoop = true;
    }

    return dp[dst];
}

int main()
{
    return 0;
}
