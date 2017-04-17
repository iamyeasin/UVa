#include <stdio.h>
#include <string.h>
#include <math.h>

int main()
{
    freopen("C:\\Users\\Yeasin\\Desktop\\input.txt","rt",stdin);
    freopen("C:\\Users\\Yeasin\\Desktop\\output.txt","wt",stdout);

    long long kase,x,y;
    scanf("%lld",&kase);

    while(kase--)
    {
        scanf("%lld %lld",&x,&y);
        int flag = 0;

        if((((x&1) && (y&1)) || (!(x&1) && !(y&1))) && (x >= y))
        {
            printf("%lld %lld\n",(x+y)/2,(x-y)/2);
        }
        else
        {
            printf("impossible\n");
        }
    }


    return 0;
}
