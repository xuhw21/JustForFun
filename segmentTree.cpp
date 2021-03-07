#include<iostream>

#define maxn 100005
int data[maxn], tree[maxn<<2], lazy[maxn<<2];

void pushUp(int k)
{
    tree[k] = tree[k<<1] + tree[(k<<1)|1];
}

void build(int l, int r, int k)
{
    if(l == r)
        tree[k] = data[l];
    else
    {
        int m = l + ((r-l)>>1);
        build(l, m, (k<<1));
        build(m+1, r, ((k<<1)|1));
        pushUp(k);
    }
}

int query(int L, int R, int l, int r, int k)
{
    if(L<=l && R>=r)
        return tree[k];
    else
    {
        int res = 0;
        int mid = l + ((r-l)>>1);
        if(mid >= L)
            res += query(L, R, l, mid, k<<1);
        if(mid <= R)
            res += query(L, R, mid+1, r, (k<<1)|1);
        return res;
    }
    return 0;
}

void update(int p, int v, int l, int r, int k)
{
    if(l==r)
    {
        data[p] += v;
        tree[k] += v;
    }
    else
    {
        int mid = l + ((r-l)>>1);
        if(p<=mid)
            update(p, v, l, mid, k<<1);
        else
        {
            update(p, v, mid+1, r, (k<<1)|1);
        }
        pushUp(k);
    }
}

void pushDown(int k)
{
    if(lazy[k])
    {
        lazy[k<<1] += lazy[k];
        lazy[k<<1|1] += lazy[k];
        tree[k<<1] += lazy[k];
        tree[k<<1|1] += lazy[k];
        lazy[k] = 0;
    }
}
void update(int L, int R, int v, int l, int r, int k)
{
    if(l>=L && r<=R)
    {
        lazy[k] += v;
        tree[k] += v;
    }
    else
    {
        pushDown(k);
        int mid = l + ((r-l)>>1);
        if(mid >= L)
            update(L, R, v, l, mid, k<<1);
        if(mid<R)
            update(L, R, v, mid+1, R, (k<<1)|1);
        pushUp(k);
    }
}

int query(int L, int R, int l, int r, int k)
{
    if(l >= L && r <= R)
        return tree[k];
    else
    {
        pushDown(k);
        int res = 0;
        int mid = l + ((r-l)>>1);
        if(mid >= l)
            res += query(L, R, l, mid, k);
        if(mid < R)
            res += query(L, R, mid+1, R, k);
        return res;
    }
    return 0;
}
