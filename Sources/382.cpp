#include<bits/stdc++.h>

using namespace std;

int digit(int n) // COUNTING HOW MANY DIGITS ARE IN THE NUMBER
{
    int counter=0;
    while(n != 0)
    {
        n /= 10;
        counter++;
    }
    return counter;
}

void space(int n) //SPACING FOR OUTPUTS.
{
    int s = 5;

    for(int i=1; i <= s-n; i++)
    {
        printf(" ");
    }
}

int main()
{
    long long int x,y,kase,sum;
    int xx=0;
    while(scanf("%lld",&x))
    {
        if (xx == 0)
        {
            xx=1;
            printf("PERFECTION OUTPUT\n");
        }
        if(x == 0)
        {
            printf("END OF OUTPUT\n");
            break;
        }
        else
        {
            sum = 0;
            for(int i=1; i<x; i++)
            {
                if(x%i == 0)
                {
                    sum += i;
                }
            }
        }

        int d = digit(x);
        if(sum == x)
        {
            space(d); // PRINTING BEFORE SPACE
            printf("%lld  PERFECT\n",x); // THE DESIRED NUMBER
        }
        else if(sum < x)
        {
            space(d);// PRINTING BEFORE SPACE
            printf("%lld  DEFICIENT\n",x); // THE DESIRED NUMBER
        }
        else if(sum > x)
        {
            space(d);// PRINTING BEFORE SPACE
            printf("%lld  ABUNDANT\n",x); // THE DESIRED NUMBER
        }
    }


    return 0;
}
