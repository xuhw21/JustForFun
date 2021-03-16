#include<iostream>
#include<vector>

using namespace std;

vector<int> getNext(string a)
{
    int n = a.size();
    vector<int> next(n, 0);
    next[0] = -1;
    int k = -1, j = 0;
    while (j < n - 1) // should notice j should less than n - 1.
    {
        if (k == -1 || a[k] == a[j])
            next[++j] = ++k;
        else
            k = next[k];
    }
    return next;
}

int KMP(string src, string pattern)
{
    int n = src.size();
    int m = pattern.size();
    vector<int> next = getNext(pattern);

    int i = 0, j = 0;
    while (i < n && j < m)
    {
        if (j == -1 || src[i] == pattern[j])
        {
            ++i;
            ++j;
        }
        else
            j = next[j];
    }
    if (j == m)
        return i - j;
    else
        return -1;
}


int main(int argc, char** argv)
{
    int res = KMP("my name is henry", "ame is");
   return 0;
}
