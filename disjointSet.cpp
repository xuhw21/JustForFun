#include<iostream>

#define MAXN 1005

static int fa[MAXN];
static int rank[MAXN];

void init(int n)
{
    for(int i = 1; i <= n; i++)
    {
        fa[i] = i;
    }
}

int find(int i)
{
    return fa[i] == i ? i : (fa[i] = find(fa[i]));
}

void merge(int i, int j)
{
    int x = find(i), y = find(j);
    if(rank[x] <= rank[y])
        fa[x] = y;
    else
        fa[y] = x;

    if(rank[x] == rank[y] && x!=y)
    {
        rank[y]++;
    }
}