#include<bits/stdc++.h>

using namespace std;

int main()
{
    int a,b,road,s,k,r,T=0;

    while(scanf("%d %d",&a,&b) == 2)
    {
        if(a == 0 || b == 0)
        {
            break;
        }
        else
        {

            road = a-b; // fist dekhlam integer dia koyta road hoy..

            s = ceil(road/(b*1.00)); // ehon khali check korlam je koyda road ase tar liga koyta character lage..jemon.. baki road jodi
                                    // 10 ta thake ar amar letter thake 3 ta taile ceil(10/3) = 4 ta.. mane hoilo.. je 4 ta letter hoilei ami seigulare nam dite parum.
            if(s > 26) // karon 26 tar beshi character hoile to unique nam dewa possible na.
            {
                printf("Case %d: impossible\n",++T);
            }
            else
            {
                printf("Case %d: %d\n",++T,s);
            }

        }

    }


    return 0;
}
