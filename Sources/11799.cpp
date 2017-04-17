#include<bits/stdc++.h>

using namespace std;

int main()
{
    int kase,x,big,test,T=0;
    scanf("%d",&kase);

    while(kase--)
    {
        big=0;
        scanf("%d",&x);
        for(int i=0; i<x; i++)
        {
            scanf("%d",&test);
            if(test > big)
            {
                big = test;
            }
        }
        printf("Case %d: %d\n",++T,big);

    }




    return 0;
}
