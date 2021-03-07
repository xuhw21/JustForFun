#include<iostream>
#include<string>
#include<vector>

using namespace std;

string bigNumMulti(const string& lhs, const string& rhs)
{
    int n = lhs.size(), m = rhs.size();
    string res;
    vector<int> vecRes(n+m, 0);

    for(int i=n-1; i>=0; i--)
    {
        for(int j=m-1; j>=0; j--)
        {
            int idx = n+m-i-j-2;
            vecRes[idx] += (lhs[i]-'0')*(rhs[j]-'0');
        }
    }

    for(int i=0; i<vecRes.size()-1; i++)
    {
        if(vecRes[i]>9)
        {
            vecRes[i+1]+=(vecRes[i]/10);
            vecRes[i]%=10;
        }
    }

    int idx = vecRes.size()-1;
    while(idx>=0 && vecRes[idx]==0)
    {
        idx--;
    }

    while(idx>=0)
    {
        res+=to_string(vecRes[idx]);
        idx--;
    }

    return res;
}

int main(int argc, char** argv)
{
    string res = bigNumMulti("56899", "845156");
    cout<<res<<endl;
    return 0;
}