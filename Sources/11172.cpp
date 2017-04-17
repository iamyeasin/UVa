#include<stdio.h>

int main()
{
    long i,j,a,b,c;
    scanf("%ld",&a);

    for(i=0;i<a;i++)
    {
        scanf("%ld %ld",&b,&c);
        if(b>c)
        {
            printf(">\n");
        }
        else if(b==c)
        {
            printf("=\n");
        }
        else
        {
            printf("<\n");
        }

    }

    return 0;
}

