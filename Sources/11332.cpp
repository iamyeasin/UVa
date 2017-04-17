#include<bits/stdc++.h>

using namespace std;

char f[20];

int Sum(long x)
{
    int sum =0;
    while(x != 0)
    {
        sum = sum + (x%10);
        x = x/10;
    }

    return sum;
}

int first()
{
    int sum =0;
    for(int i=0; i<strlen(f); i++)
    {
        sum += f[i]-'0';
    }

    return sum;
}


int main()
{
    while(1)
    {
        gets(f);
        if(f[0] == '0')
        {
            break;
        }

        long fast = first();
        int xx = Sum(fast);

        while(xx >= 10)
        {
            fast = xx;
            xx = Sum(fast);
        }

        printf("%d\n",xx);
    }

    return 0;
}
