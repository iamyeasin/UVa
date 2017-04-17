#include<stdio.h>

int main()
{
    int cola,remainder,div;
    while(scanf("%d",&cola) != EOF)
    {
        if(cola >= 2)
        {
            div = cola + cola/2; // I still have the empty bottle at last.
            printf("%d\n",div); // That I have to return him.
        }
        else if(cola != 0 && cola == 1)
        {
            printf("1\n");
        }


    }

    return 0;
}

