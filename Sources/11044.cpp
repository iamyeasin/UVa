#include<stdio.h>

int main()
{
    int m,n,i,j,x;
    scanf("%d",&x);


    for(i=0;i<x;i++)
    {
        scanf("%d %d",&n,&m);
        j=(n/3)*(m/3);

        printf("%d\n",j);

    }



    return 0;
}
