#include<stdio.h>
#include<math.h>
#include<stdlib.h>

int main()
{
    long kase,T=0,res,j;
    scanf("%ld",&kase);

    while(kase--)
    {
        scanf("%ld",&res);//That was easy....Just read the description
        res *= 567;
        res /=9;
        res += 7492;
        res *= 235;
        res /= 47;
        res -= 498;
        res %= 100;
        res /= 10;

        printf("%d\n",abs(res));

    }

    return 0;
}
