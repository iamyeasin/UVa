#include<bits/stdc++.h>
#define MAX 100000

using namespace std;


static long long int p[MAX+1];
long long int prime[5000];

void seive()
{
    memset(p,0,sizeof(p));
    for(int i=4; i<= MAX; i+=2)
    {
        p[i] = 1; // evens are not prime.1 means not prime. 0 means prime
    }

    for(int i=3; i*i<MAX; i+=2)
    {
        if(!p[i])
        {
            for(int j=i*i; j<MAX; j+=i)
            {
                p[j] = 1;// Cutting the factors which is not prime.
            }
        }
    }

    prime[0]=2;
    int k=1;
    for(int i=3; i<MAX; i++)
    {
        if(!p[i])
        {
            prime[k]=i; //storing the primes.
            k++;
        }
    }
}

int main()
{
    //freopen("C:\\Users\\Yeasin\\Desktop\\input.txt","rt",stdin);
    //freopen("C:\\Users\\Yeasin\\Desktop\\output.txt","wt",stdout);


    seive();
    int n,counter,maxx;

    while(scanf("%d",&n) != EOF)
    {
        if(!n) break;
        for(int i=0; i<n; i++)
        {
            if(prime[i]>n)
            {
                break;
            }
            else if(prime[i] <= n)
            {
                maxx = i+1;
            }

        }
       // cout<<maxx<<endl;
        counter=0;
        if(n>=4 && !(n&1))
        {
            for(int i=0; i < maxx; i++)
            {
                for(int j=i; j <= maxx; j++)
                {
                    if(prime[i] + prime[j] == n )
                    {
                        //cout<<prime[i] <<" "<< prime[j]<<endl;
                        counter++;
                    }
                }
            }
        }
        cout<<counter<<endl;
    }


    return 0;
}
