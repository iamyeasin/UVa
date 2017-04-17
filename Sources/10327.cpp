/*
Used bubble sort for sorting. then just counted every swap
*/

#include<bits/stdc++.h>

using namespace std;

int num[1005];

int Sort(int n)
{
    int counter=0;
    for(int i=0; i<n-1; i++)
    {
        for(int j=0; j<n-i-1; j++)
        {
          if(num[j] > num[j+1])
          {
              int temp = num[j];
              num[j] = num[j+1];
              num[j+1] = temp;
               // cout<<num[i]<<" "<<num[j]<<endl;
              counter++;
          }
        }
    }

    return counter;
}

void in(int n)
{
    memset(num,0,sizeof(num));
    for(int i=0; i<n; i++)
    {
        scanf("%d",&num[i]);
    }
}

int main()
{
    int n;
    while(scanf("%d",&n) != EOF)
    {
        in(n);
        //cout<<Sort(n)<<endl;
        printf("Minimum exchange operations : %d\n",Sort(n));

    }


    return 0;
}
