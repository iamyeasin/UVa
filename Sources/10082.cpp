#include <stdio.h>
#include <iostream>
#include <string.h>
#include <algorithm>

using namespace std;

int main()
{
    char arr[500],arr2[5];
    char code[50]= {81,87,69,82,84,89,85,73,79,80,91,93,92,65,
                    83,68,70,71,72,74,75,76,59,39,90,88,67,
                    86,66,78,77,44,46,47,96,49,50,51,52,53,54
                    ,55,56,57,48,45,61
                   };



    while(gets(arr) != '\0')
    {
        for(int i=0; i<strlen(arr); i++)
        {
            if(arr[i] != ' ')
            {
                for(int j=0; j<50; j++)
                {
                    if(code[j] == arr[i])
                    {
                        printf("%c",code[j-1]);
                    }
                }
            }
            else
            {
                printf("%c",arr[i]);
            }
        }
            puts("");
    }






    return 0;
}
