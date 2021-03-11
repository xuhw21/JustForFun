#include<iostream>
#include<vector>

using namespace std;

int dfs(int idx, int stats, bool limit, vector<int>& digits, vector<vector<int>>&dp)
{
    if (idx == -1) return 1;
    if (!limit && dp[idx][stats] != -1) return dp[idx][stats];
    int up = limit ? digits[idx] : 9;
    int sum = 0;
    for (int i = 0; i <= up; i++)
    {
        if (stats && i == 9) continue;
        sum += dfs(idx - 1, i == 4, limit && i == digits[idx], digits, dp);
    }
    if (!limit) dp[idx][stats] = sum;
    return sum;
}

int bitsdp(int a)
{
    vector<int> digits;
    while (a > 0)
    {
        digits.push_back(a % 10);
        a /= 10;
    }
    vector<vector<int>> dp(digits.size(), vector<int>(2, -1));
    return dfs(digits.size() - 1, 0, true, digits, dp);
}

int main(int argc, char** argv)
{
    int input = 1000;
   int tmp = bitsdp(input);
   int res = input + 1 - tmp;
   return 0;
}
