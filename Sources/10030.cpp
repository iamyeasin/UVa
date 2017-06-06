#include<stdio.h>
#define sf scanf
#define pf printf

int main()
{

    int kase;
    sf("%d",&kase);

    while(kase--)
    {
        long long farmer,sum=0;
        sf("%lld",&farmer);

        for(int i=0; i<farmer; i++)
        {
            long long fy,na,ev;
            sf("%lld %lld %lld",&fy,&na,&ev);
            sum += (fy*ev);
        }

        pf("%lld\n",sum);
        sum=0;

    }


    return 0;
}
