/*
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char arr[80];
    int T = 0;

    while(scanf("%s",&arr) != EOF)
    {
        if(strcmp(arr,"#") == 0)
        {
            break;
        }
        else if(strcmp(arr,"HELLO") == 0)
        {
            printf("Case %d: ENGLISH\n", ++T);
        }
        else if(strcmp(arr,"HOLA") == 0)
        {
            printf("Case %d: SPANISH\n", ++T);
        }
        else if(strcmp(arr,"HALLO") == 0)
        {
            printf("Case %d: GERMAN\n", ++T);
        }
        else if(strcmp(arr,"BONJOUR") == 0)
        {
            printf("Case %d: FRENCH\n", ++T);
        }
        else if(strcmp(arr,"CIAO") == 0)
        {
            printf("Case %d: ITALIAN\n", ++T);
        }
        else if(strcmp(arr,"ZDRAVSTVUJTE") == 0)
        {
            printf("Case %d: RUSSIAN\n", ++T);
        }
        else
        {
            printf("Case %d: UNKNOWN\n", ++T);
        }

    }

    return 0;
}



*/#include<bits/stdc++.h>

using namespace std;

int main()
{
    char arr[2001],T=0;

    memset(arr,'\0',sizeof(arr));
    while(gets(arr) != NULL)
    {
        if(arr[0] == 35)
        {
            break;
        }

        if(arr[0] == 'H' && arr[1] == 'E' && arr[2] == 'L' && arr[3] == 'L' && arr[4] == 'O'&& arr[5] == '\0')
        {
            printf("Case %d: ENGLISH\n",++T);
        }
        else if(arr[0] == 'H' && arr[1] == 'O' && arr[2] == 'L' && arr[3] == 'A' && arr[4] == '\0')
        {
            printf("Case %d: SPANISH\n",++T);
        }
        else if(arr[0] == 'H' && arr[1] == 'A' && arr[2] == 'L' && arr[3] == 'L' && arr[4] == 'O'&& arr[5] == '\0')
        {
            printf("Case %d: GERMAN\n",++T);
        }
        else if(arr[0] == 'B' && arr[1] == 'O' && arr[2] == 'N' && arr[3] == 'J' && arr[4] == 'O' && arr[5] == 'U' && arr[6] == 'R' && arr[7] == '\0')
        {
            printf("Case %d: FRENCH\n",++T);
        }
        else if(arr[0] == 'C' && arr[1] == 'I' && arr[2] == 'A' && arr[3] == 'O'&& arr[4] == '\0')
        {
            printf("Case %d: ITALIAN\n",++T);
        }
                                                                                                                        //ZDRAVSTVUJTE
        else if(arr[0] == 'Z' && arr[1] == 'D' && arr[2] == 'R' && arr[3] == 'A' && arr[4] == 'V' && arr[5] == 'S' && arr[6] == 'T' && arr[7] == 'V' && arr[8] == 'U' && arr[9] == 'J' && arr[10] == 'T' && arr[11] == 'E' && arr[12] == '\0')
        {
            printf("Case %d: RUSSIAN\n",++T);
        }
        else
        {
            printf("Case %d: UNKNOWN\n",++T);
        }
         printf("\n");
    }
   // printf("\n");


    return 0;
}
