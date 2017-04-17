#include<bits/stdc++.h>

using namespace std;

void wave(int x)
{
    for(int i=1; i<=x; i++)
    {
        for(int j=1; j<=i; j++)
        {
            printf("%d",i);
        }
        printf("\n");
    }

    for(int i=x-1; i>=1; i--)
    {
        for(int j=1; j<=i; j++)
        {
            printf("%d",i);
        }
        printf("\n");
    }

}


int main()
{
    int kase,n,m;
    scanf("%d",&kase);

    for(int xx =1; xx<=kase; xx++)
    {
        scanf("%d %d",&m,&n);
        if(xx>1)
        {
            printf("\n");
        }

        for(int i=1; i<=n; i++)
        {
            wave(m);
            if(i != n)
            {
                printf("\n");
            }
        }
    }


    return 0;
}
