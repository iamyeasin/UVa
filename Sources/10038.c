#include<stdio.h>

int main()
{
    int x,i,j,k;
    long flag=0;

    scanf("%d",&x);

    int in[x+5];

    for(i=0; i<x; i++)
    {
        scanf("%d",&in[i]);

        if(in[i]>x || in[i]<1)
            flag=-5;
    }

    int a,b;
    for(j=1; j<x-1; j++)
    {
        a=abs(in[j]-in[j-1]);
        b=abs(in[j]-in[j+1]);

        if(abs(a-b)!=1)
            flag=-5;
    }

    if(flag==0)
        printf("jolly");
    else
        printf("not jolly");



    return 0;
}
