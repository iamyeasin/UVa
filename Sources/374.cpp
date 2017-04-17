#include<bits/stdc++.h>

using namespace std;

long bigMod(long b, long p,long m)
{
    if(p == 0)
        return 1;
    else if(!(p&1))
    {
        return (bigMod(b,p/2,m)*bigMod(b,p/2,m))%m; //Square x = x*x
    }
    else
    {
        return ((b%m) * bigMod(b,p-1,m))%m;
    }
}


int main()
{
    long B,P,M;
    while(scanf("%ld %ld %ld",&B,&P,&M) == 3)
    {
        printf("%ld\n",bigMod(B,P,M));
    }

    return 0;
}
