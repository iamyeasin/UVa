#include<bits/stdc++.h>

using namespace std;

int isprime(int n)
{
    if(n<2)
    {
        return 0;
    }
    if(n==2)
    {
        return 1;
    }

    if((n%2)==0)
    {
        return 0;
    }

    for(int i=3; i*i <= n; i += 2)
    {
        if(n%i == 0)
        {
            return 0;
        }
    }

    return 1;
}


int main()
{
    int x,i,j;
    while(scanf("%d",&x))
    {
        if(x == 0)
        {
            break;
        }
        else
        {
            for(int i=3; i <=x; i++)
            {
                if(isprime(i))
                {
                    int m = x-i;
                    if(isprime(m))
                    {
                        printf("%d = %d + %d\n",x,i,m);
                        break;
                    }
                }
            }
        }
    }

    return 0;
}
