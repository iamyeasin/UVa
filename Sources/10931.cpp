#include<bits/stdc++.h>

using namespace std;

char bits[1001];
char bit[1001];


void rev(int last)
{
    int i =0;
    for(i=0; i<last; i++)
    {
        bit[i] = bits[last-i-1];
    }
    bit[i] = '\0';
}


int b2p(long x)
{
    int counter=0;
    int i = 0;
    memset(bits,-1,1001);
    memset(bit,0,1001);
    while(x)
    {
        if(x&1)
        {
            counter++;
            bits[i] = 1 + '0';
            // x = x>>1;
        }
        else
        {
            bits[i] = 0 + '0';
        }
        x = x>>1;
        i++;
    }
    bits[i] = '\0';

    rev(i);

    return counter;
}


int main()
{
    long n;
    while(scanf("%d",&n))
    {
        if(!n) break;
        if(n == 1)  printf("The parity of 1 is 1 (mod 2).\n");
        else
        {
            int b = b2p(n);
            printf("The parity of %s is %d (mod 2).\n",bit,b);
        }

    }


    return 0;
}
