/*
Have to find the max cycle length from i number to j number;
Suppose i =1, j=10;
I have to find the max cycle length.such as for 2 will be 1,
for 3 will be 7, for 4 will be 2, for 5 will be 5,for 6 will be 8.
This way have to find the max cycle length.
*/

#include<stdio.h>


int main()
{
    int a,b,maxx;

    while(scanf("%d %d",&a,&b) == 2)
    {
        int ma2x=0;
        printf("%d %d",a,b);

        if(a>b)
        {
            int m = a;
            a = b;
            b = m;
        }

        for(int i=a; i<=b; i++)
        {
            maxx = 1;
            int k = i;
            while(k>1)
            {
                if(k&1)
                {
                    k = 3*k + 1;
                }
                else
                {
                    k = k/2;
                }

                maxx++;
            }

            if(maxx > ma2x)
            {
                ma2x = maxx;
            }

        }

        printf(" %d\n",ma2x);


    }



    return 0;
}
