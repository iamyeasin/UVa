#include <stdio.h>
#include <string.h>
#include <math.h>
#include <algorithm>

int main()
{
    int flag=0;
    char arr[10];
    while(scanf("%c",&arr[0]) != EOF)
    {
        if(arr[0] == 34 && flag == 0)
        {
            printf("``");
            flag = 1;
            continue;
        }

        else if(arr[0] == 34 && flag == 1)
        {
            printf("''");
            flag = 0;
            continue;
        }
        else
        {
            printf("%c",arr[0]);
        }
    }



    return 0;
}
