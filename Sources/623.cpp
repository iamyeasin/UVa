#include<cstdio>
#include<cmath>
#include<iostream>
#include<string.h>

using namespace std;

long arr[1005][2605];

int main()
{
    long x,y,i,j,k;

    scanf("%ld",&x);

    arr[0][0]=arr[1][0]=1;

    for(i=2; i<=1000; i++)
    {
        for(j=0; j<=2600; j++)

        {
            arr[i][j]  += i*arr[i-1][j];

            if(arr[i][j]>9)
            {
                arr[i][j+1] = arr[i][j+1]+(arr[i][j]/10);
                arr[i][j] = arr[i][j]%10;
            }
           // if(arr[i][j] !=0)
            //cout<<i<<" "<<j<<" "<<arr[i][j]<<endl;
        }
    }


    //for(int i=0; i<2600; i++)
        //cout<<arr[x][i];

    for(i=1000; i>=0; i--)
    {
        if(arr[x][i] != 0)
            break;
    }
    for( ; i>=0; i--)
        printf("%ld", arr[x][i]);

    puts("");


    return 0;
}
