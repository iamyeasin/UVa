/*
HINT : ekta prime er list e total number gula gunsi.. counter dia..
ar description e koise center e list ta print korte..bepar hoilo gia..
jodi total prime list e 9 ta value thake taile mid list ber korte hoibo..
(9-c)/2 eivabe...
so eita hoitase starting point... end point hoibo.. start er loge c jog korlei
end point pawa jaibo...

pore start point theika end point porjonto loop calailei ... sob prime gula pawa jaibo.
*/

#include<bits/stdc++.h>

using namespace std;

static int primes[10003];
long long int p[1005];

void sieve()
{
    memset(primes,0,sizeof(primes));
    for(int i=4; i<10000; i+=2)
    {
        primes[i] = 1; //1 means not prime but 0 does
    }

    for(int i=3; i*i<10000; i+=2)
    {
        if(!primes[i])
        {
            for(int j=i*i; j<10000; j+=i)
            {
                primes[j] = 1;
            }
        }
    }

    p[0] = 1;
    p[1] = 2;
    int k = 2;

    for(int i=3; i <= 10000; i++)
    {
        if(primes[i] == 0)
        {
            p[k] = i;//Storing all the prime numbers
            k++;
        }
    }
}


int main()
{
    //freopen("C:\\Users\\Yeasin\\Desktop\\input.txt","rt",stdin);
    //freopen("C:\\Users\\Yeasin\\Desktop\\output.txt","wt",stdout);

    sieve();
    int maxx,N,c,cc,counter;

    while(scanf("%d %d",&N,&c) == 2)
    {
        int x=c;
        counter = 0;
        for(int i=0; i<=N; i++)
        {
            if(p[i]>N)
            {
                break;
            }
            else
            {
                counter++;
            }
        }

        //cout<<counter<<endl;
        if(counter&1)
        {
            c = 2*c - 1;
        }
        else
        {
            c = 2*c;
        }
        if(N==c || c>N)
        {
            c= counter;
        }

        int start = ((-c+counter)/2);
        int ennd  = start + c;
        if(start<0)
        {
            start = 0;
            ennd = counter;
        }

        printf("%d %d:",N,x);

        for(int i=start; i<ennd; i++)
        {
            printf(" %d",p[i]);
        }
        cout<<endl<<endl;
    }



    return 0;
}
