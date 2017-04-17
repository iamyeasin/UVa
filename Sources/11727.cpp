#include<stdio.h>
#include<algorithm>

using namespace std;

int main()
{
   int kase,T=0,arr[3];
   scanf("%d",&kase);

   while(kase--)
   {
       scanf("%d %d %d",&arr[0],&arr[1],&arr[2]);
       sort(arr,arr+3);

       printf("Case %d: %d\n",++T,arr[1]);

   }

    return 0;
}
