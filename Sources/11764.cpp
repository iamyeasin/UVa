#include<iostream>
#include<stdio.h>

using namespace std;

int main()
{
    int kase,T=0;
    int arr[50];
    scanf("%d",&kase);

    while(kase--)
    {
        int n,lo=0,hi=0;
        scanf("%d",&n);

        for(int i=0; i<n; i++)
        {
            scanf("%d",&arr[i]);
        }

        for(int i=1; i<n; i++)
        {
            if(arr[i] > arr[i-1])
            {
                hi++;
            }
            else if(arr[i] < arr[i-1])
            {
                lo++;
            }
        }

        printf("Case %d: %d %d\n",++T,hi,lo);

    }

    return 0;
}
