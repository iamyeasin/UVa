#include<stdio.h>


int main()
{
    int i,j,k,l,m,temp,x;
    int arr[3];

    while(scanf("%d",&m)==1)
    {
        for(k=1; k<=m; k++)
        {
            for(j=0; j<3; j++)
            {
                scanf("%d",&arr[j]);
            }
            for(i=0; i<3; i++)
            {
                for(l=0; l<3-i-1; l++)
                {
                    if(arr[l]>arr[l+1])
                    {
                        temp=arr[l+1];
                        arr[l+1]=arr[l];
                        arr[l]=temp;
                    }
                }
            }
            printf("Case %d: %d\n",k,arr[1]);

        }
    }



    return 0;
}
