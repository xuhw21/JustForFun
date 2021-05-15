#include<iostream>
#include<vector>

using namespace std;

void dfs(vector<vector<long long>>& dp, int i, int idx, int state, int next, int m)
{
    if (idx == m)
    {
        dp[i + 1][next] += dp[i][state];
        return;
    }

    if (state & (1 << idx))
        dfs(dp, i, idx + 1, state, next, m);
    if ((state & (1 << idx)) == 0)
        dfs(dp, i, idx + 1, state, next | (1 << idx), m);
    if(idx<m-1 && (state &(1<<idx)) && (state &(1<<(idx+1))))
        dfs(dp, i, idx + 2, state, next|(1<<idx)|(1<<(idx + 1)), m);
    return;
}

int StateCompression(int n, int m)
{
    if (n * m % 2) return 0;

    vector<vector<long long>> dp(n + 1, vector<long long>((1 << m), 0));
    dp[0][(1 << m) - 1] = 1;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < (1 << m); j++)
        {
            if (dp[i][j])
                dfs(dp, i, 0, j, 0, m);
        }
    }
    return dp[n][(1 << m) - 1];
}

int main(int argc, char** argv)
{

    int res = StateCompression(4,11);
    return 0;
}

